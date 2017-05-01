#include "VolatilityGraph.h"
#include "MySQL-Eclipse.h" 
#include "Network.h"
#include "Eclipse.h"

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "OptionTick.pb.h"
#include "boost/spirit/include/qi.hpp"
#include <boost\spirit\include\karma.hpp>
#include <sstream>
#include <iomanip>  
#include <iostream>
#include <QToolTip>

#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "boost/thread/mutex.hpp"
#include <windows.h>
#include "VolatilityProxy.h"

#define VolatilityGraph_RefreshRate 300 

VolatilityGraph::VolatilityGraph(QWidget *parent)	: QWidget(parent)
{
	ui.setupUi(this);
	db = new Framework::NEclipse::DBaseConnection();
	db->InitiateDBConnection();
	InitializeVolatilityGraph();
	Tableshowing = false;
	FormGUID = boost::uuids::to_string(boost::uuids::random_generator()());
	
	
	QObject::connect(ui.comboDistinctSymbol,SIGNAL(currentIndexChanged(QString)),this,SLOT(SymbolChanged(QString)));
	QObject::connect(ui.comboExpirationDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(DateChanged(QString)));
	QObject::connect(ui.cmdStart,SIGNAL(clicked()),this,SLOT(SubscribeToSymbols()));
    QObject::connect(ui.cmdHideTable,SIGNAL(clicked()),this,SLOT(ShowOptionTable()));
	
	
	connect(ui.LinePlot, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), this, SLOT(LinePlotableClicked(QCPAbstractPlottable*,QMouseEvent*)));
	connect(ui.VolumePlot, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), this, SLOT(VolumePlotableClicked(QCPAbstractPlottable*,QMouseEvent*)));
	connect(ui.TradesPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), this, SLOT(TradePlotableClicked(QCPAbstractPlottable*,QMouseEvent*)));
	connect(ui.OInterestPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), this, SLOT(OpenInterestPlotableClicked(QCPAbstractPlottable*,QMouseEvent*)));
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------SIGNAL ATTACHMENTS FOR MANAGING THE GRAPH Y-AXIS-------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	connect(ui.LinePlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(LinePlotRangeChanged(QCPRange)));
	connect(ui.VolumePlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(VolumePlotRangeChanged(QCPRange)));
	connect(ui.TradesPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(TradePlotRangeChanged(QCPRange)));
	connect(ui.OInterestPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(OpenInterestPlotRangeChanged(QCPRange)));
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	/*
	connect(ui.checkBoxVolatility,SIGNAL(stateChanged (int)) , this,SLOT(PlotVolatilityShowState(int)));
	connect(ui.checkBoxVolume,SIGNAL(stateChanged (int)) , this,SLOT(PlotVolumeShowState(int)));
	connect(ui.checkBoxTrades,SIGNAL(stateChanged (int)) , this,SLOT(PlotTradesShowState(int)));
	connect(ui.checkBoxOpenInterest,SIGNAL(stateChanged (int)) , this,SLOT(PlotOinterestShowState(int)));
	*/
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

	ui.frametableDisplay->hide();
	play = false;
}

VolatilityGraph::~VolatilityGraph()
{
	db->CloseDBConnection();
} 

std::string VolatilityGraph::getFormGUID()
{
	return FormGUID;
}

void VolatilityGraph::MakeCellBlink(int row)
{
	{
		boost::lock_guard<boost::mutex> lock(mutex_blinker);
		ModelOptionTable->setData(ModelOptionTable->index(row,0), Qt::gray, Qt::BackgroundRole); //For Blinker
	}
	Sleep(160);
	{
		boost::lock_guard<boost::mutex> lock(mutex_blinker);
		ModelOptionTable->setData(ModelOptionTable->index(row,0), Qt::white, Qt::BackgroundRole); //For Blinker
	}
}


void VolatilityGraph::FindExtremes(Serializable::OptionTick_ser& oc,double& min,double& max)
{
	double a = oc.ask_imp_volatility(); double b = oc.bid_imp_volatility(); double c = oc.mp_imp_volatility();
	if(a>=b && a>=c) {max =a;}
	else if (b>=a && b>=c) {max =b;}
	else if (c>=a && c>=b) {max =c;}

	if(a<=b && a<=c) {min = a;}
	else if(b<=a && b<=c) {min = b;}
	else if(c<=a && c<=b) {min = c;}
}

#pragma region Methods for QCustomPlot

void VolatilityGraph::LinePlotRangeChanged(const QCPRange &newRange)
{
	ui.LinePlot->yAxis->setRangeLower(0);
}

void VolatilityGraph::VolumePlotRangeChanged(const QCPRange &newRange)
{
	ui.VolumePlot->yAxis->setRangeLower(0);
}

void VolatilityGraph::TradePlotRangeChanged(const QCPRange &newRange)
{
	ui.TradesPlot->yAxis->setRangeLower(0);
}

void VolatilityGraph::OpenInterestPlotRangeChanged(const QCPRange &newRange)
{
	ui.OInterestPlot->yAxis->setRangeLower(0);
}

void VolatilityGraph::PlotVolatilityShowState(int state)
{
	if(state == Qt::Unchecked){
		ui.LinePlot->setVisible(false);}
	
	if(state == Qt::Checked){
		ui.LinePlot->setVisible(true);
	    ui.LinePlot->replot();}
	
}

void VolatilityGraph::PlotVolumeShowState(int state)
{
	if(state == Qt::Unchecked){
		ui.VolumePlot->setVisible(false);}

	if(state == Qt::Checked){
		ui.VolumePlot->setVisible(true);
	    ui.VolumePlot->replot();}
}

void VolatilityGraph::PlotTradesShowState(int state)
{
	if(state == Qt::Unchecked){
		ui.TradesPlot->setVisible(false);}

	if(state == Qt::Checked){
		ui.TradesPlot->setVisible(true);
	    ui.TradesPlot->replot();}
}

void VolatilityGraph::PlotOinterestShowState(int state)
{
	if(state == Qt::Unchecked){
		ui.OInterestPlot->setVisible(false);}

	if(state == Qt::Checked){
		ui.OInterestPlot->setVisible(true);
	    ui.OInterestPlot->replot(); }
}

void VolatilityGraph::PlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b)
{
	/*double c,d;
	a->pixelsToCoords(b->posF(),c,d);
	QToolTip::showText(b->globalPos(),QString::number(c,'g',4) +"  " + QString::number(d,'g',4));*/
}

void VolatilityGraph::LinePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b)
{
	PlotableClicked(a,b);
}

void VolatilityGraph::TradePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b)
{
	PlotableClicked(a,b);
}

void VolatilityGraph::VolumePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b)
{
	PlotableClicked(a,b);
}

void VolatilityGraph::OpenInterestPlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b)
{
	PlotableClicked(a,b);
}

	
void VolatilityGraph::InitializeVolatilityGraph()
{
	//Initialize the form
	PlotTickPass = atoi(Eclipse::GetConfigValue("PlotTickPass").c_str());
	InitializeOptionsTable();
	populateDistinctSymbols();
	ui.comboExpirationDate->addItem("--");
	ui.comboCallPut->addItem("--");

	//Mark the check-boxes as checked - Since all the tables are bing displayed
	/* These checkboxes are no longer needed
	ui.checkBoxVolatility->setCheckState(Qt::CheckState::Checked);
	ui.checkBoxTrades->setCheckState(Qt::CheckState::Unchecked);
	ui.checkBoxVolume->setCheckState(Qt::CheckState::Unchecked);
	ui.checkBoxOpenInterest->setCheckState(Qt::CheckState::Unchecked);
	*/

	ui.checkBoxVolatility->setVisible(false);
	ui.checkBoxTrades->setVisible(false);
    ui.checkBoxVolume->setVisible(false);
	ui.checkBoxOpenInterest->setVisible(false);


	ui.LinePlot->setVisible(true);
	ui.VolumePlot->setVisible(false);
	ui.TradesPlot->setVisible(false);
	ui.OInterestPlot->setVisible(false);
}


//This method initializes the plot and sets the x-axis
void VolatilityGraph::InitializePlotGraph(double x_min_diff,QCustomPlot* plot)
{
	//plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

	plot->xAxis->setSubTickLength(3);
	plot->xAxis->setTickLength(10);
	plot->xAxis->setBasePen(QPen(Qt::white, 1));
	plot->yAxis->setBasePen(QPen(Qt::white, 1));
	plot->xAxis->setTickPen(QPen(Qt::white, 1));
	plot->yAxis->setTickPen(QPen(Qt::white, 1));
	plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
	plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
	plot->xAxis->setTickLabelColor(Qt::white);
	plot->yAxis->setTickLabelColor(Qt::white);
	plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine)); //Square 
	plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
	plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
	plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
	plot->xAxis->grid()->setSubGridVisible(true);
	plot->yAxis->grid()->setSubGridVisible(true);
	plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
	plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);

	QLinearGradient plotGradient;
	plotGradient.setStart(0, 0);
	plotGradient.setFinalStop(0, 350);
	plotGradient.setColorAt(0, QColor(80, 80, 80));
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	plot->setBackground(plotGradient);

	QLinearGradient axisRectGradient;
	axisRectGradient.setStart(0, 0);
	axisRectGradient.setFinalStop(0, 350);
	axisRectGradient.setColorAt(0, QColor(80, 80, 80));
	axisRectGradient.setColorAt(1, QColor(30, 30, 30));

	//plot->axisRect()->setRangeDragAxes(plot->xAxis,plot->yAxis);

	plot->axisRect()->setBackground(axisRectGradient);
	plot->xAxis->setLabel("Strike");

	plot->xAxis->setAutoTickStep(false);
	plot->xAxis->setAutoSubTicks(false);
	plot->xAxis->setTickStep(x_min_diff);
	plot->xAxis->setSubTickCount(x_min_diff);

	plot->xAxis->setRange(strikes_x.at(strikes_x.size()-1)-x_min_diff,strikes_x.at(0)+x_min_diff);

	//Customize the ticks and sub-ticks on the x and y axis
	ui.LinePlot->yAxis->setAutoTickStep(true);
	ui.LinePlot->yAxis->setAutoSubTicks(false);
}



//This method initializes the Line Plot Graph 
void VolatilityGraph::InitializeLinePlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff)
{
	ui.LinePlot->addGraph();
	ui.LinePlot->addGraph();
	ui.LinePlot->addGraph();

	AskImpliedPen.setColor(QColor(255, 3, 3));         //red 
	AskImpliedPen.setWidth(2);
	BidImpliedPen.setColor(QColor(0,255,0));           //green
	BidImpliedPen.setWidth(2);
	MPImpliedPen.setColor(QColor(0,0,255));            //Blue
	MPImpliedPen.setWidth(2);

	double lowYRange = ylow-y_min_diff;
	double YtickStep = (yhigh-ylow)/PlotTickPass;
	int YSubTickCount = 1;    //Min Value;
	
	lowYRange = lowYRange < 0 ? 0 : lowYRange ;
	ui.LinePlot->yAxis->setRange(lowYRange,yhigh+y_min_diff);

	InitializePlotGraph(x_min_diff,ui.LinePlot);

	YSubTickCount = y_min_diff > 1 ? y_min_diff:1;
	
	ui.LinePlot->yAxis->setTickStep(YtickStep);
	ui.LinePlot->yAxis->setSubTickCount(YSubTickCount);
	ui.LinePlot->yAxis->setSubTickLength(3);
	ui.LinePlot->yAxis->setTickLength(10);
	
	ui.LinePlot->graph(0)->setPen(AskImpliedPen);
	ui.LinePlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);
	ui.LinePlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	ui.LinePlot->graph(1)->setPen(BidImpliedPen);
	ui.LinePlot->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
	ui.LinePlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	ui.LinePlot->graph(2)->setPen(MPImpliedPen);
	ui.LinePlot->graph(2)->setLineStyle(QCPGraph::LineStyle::lsLine);
	ui.LinePlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	// set axes ranges, so we see all data:
	qSort(strikes_x);
	ask_implied_y.resize(strikes_x.size());
	bid_implied_y.resize(strikes_x.size());
	mp_implied_y.resize(strikes_x.size());

	ui.LinePlot->replot();
}



//Initialize the Volume Plot Graph
void VolatilityGraph::InitializeVolumePlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff)
{
	ui.VolumePlot->addGraph();

	VolumePlotPen.setColor(QColor(0,255,0));           //green
	VolumePlotPen.setWidth(2);

	double lowYRange = ylow-y_min_diff;
	double YtickStep = (yhigh-ylow)/PlotTickPass;
	int YSubTickCount = 1;    //Min Value;

	lowYRange = lowYRange < 0 ? 0 : lowYRange ;
	ui.VolumePlot->yAxis->setRange(lowYRange,yhigh+y_min_diff);

	InitializePlotGraph(x_min_diff,ui.VolumePlot);

	YSubTickCount = y_min_diff > 1 ? y_min_diff:1;

	ui.VolumePlot->yAxis->setTickStep(YtickStep);
	ui.VolumePlot->yAxis->setSubTickCount(YSubTickCount);
	ui.VolumePlot->yAxis->setSubTickLength(3);
	ui.VolumePlot->yAxis->setTickLength(10);

	ui.VolumePlot->graph(0)->setPen(VolumePlotPen);
	ui.VolumePlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsImpulse);
	ui.VolumePlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	// set axes ranges, so we see all data:
	qSort(strikes_x);
	volume_y.resize(strikes_x.size());
	ui.VolumePlot->replot();
}



//Initialize the trades plot
void VolatilityGraph::InitializeTradesPlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff)
{
	ui.TradesPlot->addGraph();

	TradesPlotPen.setColor(QColor(0,255,0));           //green
	TradesPlotPen.setWidth(2);

	double lowYRange = ylow-y_min_diff;
	double YtickStep = (yhigh-ylow)/PlotTickPass;
	int YSubTickCount = 1;    //Min Value;

	lowYRange = lowYRange < 0 ? 0 : lowYRange ;
	ui.TradesPlot->yAxis->setRange(lowYRange,yhigh+y_min_diff);

	InitializePlotGraph(x_min_diff,ui.TradesPlot);

	YSubTickCount = y_min_diff > 1 ? y_min_diff:1;

	ui.TradesPlot->yAxis->setTickStep(YtickStep);
	ui.TradesPlot->yAxis->setSubTickCount(YSubTickCount);
	ui.TradesPlot->yAxis->setSubTickLength(3);
	ui.TradesPlot->yAxis->setTickLength(10);

	ui.TradesPlot->graph(0)->setPen(TradesPlotPen);
	ui.TradesPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsImpulse);
	ui.TradesPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	// set axes ranges, so we see all data:
	qSort(strikes_x);
	trades_y.resize(strikes_x.size());
	ui.TradesPlot->replot();
}


void VolatilityGraph::InitializeOpenInterestGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff)
{
	ui.OInterestPlot->addGraph();

	TradesPlotPen.setColor(QColor(0,255,0));           //green
	TradesPlotPen.setWidth(2);

	double lowYRange = ylow-y_min_diff;
	double YtickStep = (yhigh-ylow)/PlotTickPass;
	int YSubTickCount = 1;    //Min Value;

	lowYRange = lowYRange < 0 ? 0 : lowYRange ;
	ui.OInterestPlot->yAxis->setRange(lowYRange,yhigh+y_min_diff);

	InitializePlotGraph(x_min_diff,ui.OInterestPlot);

	YSubTickCount = y_min_diff > 1 ? y_min_diff:1;

	ui.OInterestPlot->yAxis->setTickStep(YtickStep);
	ui.OInterestPlot->yAxis->setSubTickCount(YSubTickCount);
	ui.OInterestPlot->yAxis->setSubTickLength(3);
	ui.OInterestPlot->yAxis->setTickLength(10);

	ui.OInterestPlot->graph(0)->setPen(TradesPlotPen);
	ui.OInterestPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsImpulse);
	ui.OInterestPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	// set axes ranges, so we see all data:
	qSort(strikes_x);
	open_interest_y.resize(strikes_x.size());
	ui.OInterestPlot->replot();
}



//This method simply realigns the y-axis
void VolatilityGraph::manage_yaxis_range(double lowest,double highest, QCustomPlot* plt,PlotType pt)
{
	//Changed from 5 to 15
	double HighestFivePer = (15.0/100.0)*highest; 
	double lowestFivePer = (15.0/100.0)*lowest;

	double upper_range = plt->yAxis->range().upper;
	double lower_range = plt->yAxis->range().lower;

	if(pt==PlotType::VolatilityType)
	{
		//if(highest > upper_range)
		if(highest > upper_range+HighestFivePer)
		{
			//set new upper range
			plt->yAxis->setRange(lower_range, highest + HighestFivePer);
		}
		//else if(lowest < lower_range)
		else if(lowest < lower_range-lowestFivePer)
		{
			//set new lower range
			double l = lowest - lowestFivePer;
			if(l<0.0) l=0;
			plt->yAxis->setRange(l, upper_range);
		}
	}
	else
	{
		//Check if current range is greater than older range
		//if(highest > upper_range)
		if(highest > upper_range+ HighestFivePer)
		{
			plt->yAxis->setRange(lower_range, highest + HighestFivePer);
		}
		//Check if current range is lower than the lowest range
		//else if (highest < lower_range)
		else if(lowest < lower_range-lowestFivePer)
		{
			//set new lower range
			double l = lowest - lowestFivePer;
			if(l<0.0) l=0;
			plt->yAxis->setRange(l, upper_range);
		}
	}
}//end method


void VolatilityGraph::TimeOut()
{
	ui.LinePlot->replot(); 
}

void VolatilityGraph::UpdateImpliedVolatilityCurve(Serializable::OptionTick_ser& otick)
{
		double l,h;
		FindExtremes(otick,l,h);
		manage_yaxis_range(l,h,ui.LinePlot,PlotType::VolatilityType);
	    UpdateAskImpliedVolatilityCurve(otick.ask_imp_volatility(),otick.strike());
		UpdateBidImpliedVolatilityCurve(otick.bid_imp_volatility(),otick.strike());
		UpdateMPVolatilityCurve(otick.mp_imp_volatility(),otick.strike());
		//ui.LinePlot->replot(); //Replotting done by the timer
}


//Update Ask implied volatility curve
void VolatilityGraph::UpdateAskImpliedVolatilityCurve(double Aivolat,double strike)
{
	
	//Find out the slot where the ask implied volatility should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		ask_implied_y[pos]=Aivolat;        
		ui.LinePlot->graph(0)->setData(strikes_x, ask_implied_y);
	}
}//end method


void VolatilityGraph::UpdateBidImpliedVolatilityCurve(double Bivolat, double strike)
{
	//Find out the slot where the ask implied volatility should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		bid_implied_y[pos]=Bivolat;        
		ui.LinePlot->graph(1)->setData(strikes_x, bid_implied_y);
	}
}

//Update the Mp volatility curve
void VolatilityGraph::UpdateMPVolatilityCurve(double mpvolat, double strike)
{
	
	//Find out the slot where the ask implied volatility should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		mp_implied_y[pos]=mpvolat;        
		ui.LinePlot->graph(2)->setData(strikes_x, mp_implied_y);
	}
}


//Updates the volume curve
void VolatilityGraph::UpdateVolumeCurve(double vol, double strike)
{
	manage_yaxis_range(0,vol,ui.VolumePlot,PlotType::VolumeType);
	//Find out the slot where the volume should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		volume_y[pos]=vol;        
		((QCustomPlot*) ui.VolumePlot)->graph(0)->setData(strikes_x, volume_y);
		//((QCustomPlot*) ui.VolumePlot)->replot(); //Replot at the end
	}
}


void VolatilityGraph::UpdateTradesCurve(double trades, double strike)
{
	manage_yaxis_range(0,trades,ui.VolumePlot,PlotType::TradeType);
	//Find out the slot where the volume should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		trades_y[pos]=trades;        
		((QCustomPlot*) ui.TradesPlot)->graph(0)->setData(strikes_x, trades_y);
		//((QCustomPlot*) ui.TradesPlot)->replot(); //Replot at the end
	}
}//End method


void VolatilityGraph::UpdateOpenInterestCurve(double open_interest,double strike)
{
	manage_yaxis_range(0,open_interest,ui.OInterestPlot,PlotType::OpenInterestType);
	//Find out the slot where the volume should be inserted
	int pos = strikes_x.indexOf(strike);
	if(pos!=-1)
	{
		open_interest_y[pos]=open_interest;        
		((QCustomPlot*) ui.OInterestPlot)->graph(0)->setData(strikes_x, open_interest_y);
		//((QCustomPlot*) ui.OInterestPlot)->replot(); //Replot at the end
	}
}

#pragma endregion 


void VolatilityGraph::ShowOptionTable()
{
	if(!Tableshowing)
	{
		//Show the table
		ui.frametableDisplay->show();
		ui.cmdHideTable->setText("Hide Table");
		
	}
	else
	{
		//Hide the table
		ui.frametableDisplay->hide();
		ui.cmdHideTable->setText("Show Table");
	}
	
	Tableshowing = !Tableshowing;
}


void VolatilityGraph::RemoveSymbolFromTable(std::string symbol)
{
	bool t; 
	QList<QStandardItem*> lst = ModelOptionTable->findItems(symbol.c_str(),Qt::MatchExactly,0);
	if(lst.count()>0)
	{
		t = ModelOptionTable->removeRow(lst[0]->row());
	}	
}


void VolatilityGraph::populateDistinctSymbols()
{
	std::vector<std::string> dsymbol = db->GetDistinctSymbols();
	ui.comboDistinctSymbol->addItem("--");	
	for(std::vector<std::string>::iterator it = dsymbol.begin(); it != dsymbol.end(); it++ )
	{
		ui.comboDistinctSymbol->addItem((*it).c_str());	
	}
	ui.comboDistinctSymbol->setCurrentIndex(0);
	ui.comboExpirationDate->setCurrentIndex(0);
	ui.comboCallPut->setCurrentIndex(0);
}


void VolatilityGraph::SymbolChanged(QString symb)
{
	//std::string symb = ui.comboDistinctSymbol->currentText().toStdString();
	std::vector<std::string> temp = db->GetRelevantExpirationDates(symb.toStdString());
	for(std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		ui.comboExpirationDate->addItem((*it).c_str());	
	}
	ui.comboExpirationDate->setCurrentIndex(0);
	ui.comboCallPut->setCurrentIndex(0);
}

void VolatilityGraph::DateChanged(QString date)
{
	std::vector<std::string> temp = db->GetCallAndPuts( ui.comboDistinctSymbol->currentText().toStdString(),date.toStdString());
	for(std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		ui.comboCallPut->addItem((*it).c_str());	
	}
	ui.comboCallPut->setCurrentIndex(0);
}

//This method compares minimum difference between two consecutive nos (7,6,5,4)
void VolatilityGraph::CalculateMinDifference(std::vector<double>& vrange ,double& rdifference)
{
	//Now calculate the min difference between two nos
	double min = 0;
	bool firsttry = true;
	for(int i=0; i<vrange.size() ; i++)
	{
		if(i+1<vrange.size()) //If the last np is not negative
		{
			double temp= 0;
			if(firsttry == true)
			{
				temp = (vrange[i]) - vrange[i+1] ;
				min = temp;
				firsttry = false;
			}
			else
			{
				temp = (vrange[i]) - vrange[i+1];
				if(temp<min)
				{
					if(temp!=double(0))
					{
						min = temp;
					}
					
				}
			}//endif
		}//endif
	}//end for

	rdifference = min;
}//End Method


//This method determines the extremes for the Y-Axis
void VolatilityGraph::GenerateExtremesForYAxis(Serializable::Option_collection_ser& oc,double& min,double& max,double& rdifference,PlotType pt)
{
	std::vector<double> NoArranger;
	int a = oc.option_tick_collection_size();
	if(a!=0)
	{
		for(int i=0;i< oc.option_tick_collection_size();i++)
		{
			double val;
			if(pt==VolatilityType)
			{
				val= oc.option_tick_collection(i).ask_imp_volatility();
				NoArranger.push_back(val);
				val = oc.option_tick_collection(i).bid_imp_volatility();
				NoArranger.push_back(val);
				val = oc.option_tick_collection(i).mp_imp_volatility();
				NoArranger.push_back(val);
			}
			else if(pt==VolumeType)
			{
				val= oc.option_tick_collection(i).dailyvolume();
				NoArranger.push_back(val);
			}
			else if(pt==TradeType)
			{
				val= oc.option_tick_collection(i).dailytrades();
				NoArranger.push_back(val);
			}
			else if(pt==OpenInterestType)
			{
				val= oc.option_tick_collection(i).openinterest();
				NoArranger.push_back(val);
			}

		}
		std::sort(NoArranger.begin(), NoArranger.end(), std::greater<double>()); //Highest at top(index 0)
		min = NoArranger[NoArranger.size()-1];
		max = NoArranger[0];
		CalculateMinDifference(NoArranger,rdifference);
	}
	else
	{
		//Why did you get an empty object ?
		//Were there items in the WOPR Table ?
		DebugBreak();
	}
}//end Method



void VolatilityGraph::PopulatePlotsInitializingData(Serializable::Option_collection_ser& otick)
{
	for(int i=0;i< otick.option_tick_collection_size();i++)
	{
		ManageTableUpdates(otick.option_tick_collection(i));
	}
}

//This method runs only once when the button is clicked
void VolatilityGraph::SubscribeToSymbols()
{
	std::string symb = ui.comboDistinctSymbol->currentText().toStdString();
	std::string date = ui.comboExpirationDate->currentText().toStdString();
	std::string calput = ui.comboCallPut->currentText().toStdString();
	

	if(symb == "--" || date == "--" || calput == "--")
	{
		return;
	}

	SubscribedSymbols = db->GetFinalSymbol(symb,date,calput); //Might return multiple symbols
	std::sort(SubscribedSymbols.begin(),SubscribedSymbols.end());                      //Sort for binay_search later

	if(!play)
	{
			strikes_x = QVector<double>::fromStdVector(db->GetStrikes(symb,date,calput));
			std::sort(strikes_x.begin(), strikes_x.end(), std::greater<double>()); 
	
			//Retrieve a list of the previous options and then use it to generate the y-scale axis;
			Serializable::Option_collection_ser oc = Framework::NEclipse::QpidSubscriber::GetQpidInstance()->WOPRQuery_OptionUpdates(SubscribedSymbols);

			//Obtain the extremes for the y-axis
			double lower_bound , upper_bound , y_rdifference,x_rdifference;


			CalculateMinDifference(strikes_x.toStdVector(),x_rdifference);                                     //Get min distance between two points on x-axis     
			//-----------------------------------------------------------------------------------------------------------------------------
			GenerateExtremesForYAxis(oc,lower_bound,upper_bound,y_rdifference,PlotType::VolatilityType); //Will get the upper and lower bound and also the min distance between two points on y axis
			InitializeLinePlotGraph(lower_bound,upper_bound,x_rdifference,y_rdifference);
			//------------------------------------------------------------------------------------------------------------------------------
	
			/* These plots are no longer being used
			//--------------------------------------------------------------------------------------------------
			GenerateExtremesForYAxis(oc,lower_bound,upper_bound,y_rdifference,PlotType::VolumeType);     //Will get the upper and lower bound and also the min distance between two points on y axis
			InitializeVolumePlotGraph(lower_bound,upper_bound,x_rdifference,y_rdifference);
			//--------------------------------------------------------------------------------------------------

			//--------------------------------------------------------------------------------------------------
			GenerateExtremesForYAxis(oc,lower_bound,upper_bound,y_rdifference,PlotType::TradeType);     //Will get the upper and lower bound and also the min distance between two points on y axis
			InitializeTradesPlotGraph(lower_bound,upper_bound,x_rdifference,y_rdifference);
			//--------------------------------------------------------------------------------------------------

			//--------------------------------------------------------------------------------------------------
			GenerateExtremesForYAxis(oc,lower_bound,upper_bound,y_rdifference,PlotType::OpenInterestType);     //Will get the upper and lower bound and also the min distance between two points on y axis
			InitializeOpenInterestGraph(lower_bound,upper_bound,x_rdifference,y_rdifference);
			//--------------------------------------------------------------------------------------------------	
			*/

			PopulatePlotsInitializingData(oc); //Insert the first initializing data
			SubscribeToOptionTopic("ParameterNoUse", "ParameterNoUse");
			ui.cmdStart->setText("Stop");

			//Start the timer - This timer updates the GUI thread
			UpdateLinePlot = new QTimer(this);
			UpdateLinePlot->setInterval(VolatilityGraph_RefreshRate);
			UpdateLinePlot->start();
			connect(UpdateLinePlot, SIGNAL(timeout()), this, SLOT(TimeOut()));
	}
	else
	{
		/*
		for(int i=0;i<temp.size();i++)
		{	
			UnSubscribeFromTopic(temp[i]);
		}
		*/
		//ui.LinePlot->clearGraphs();
		//ui.cmdStart->setText("Start");
		Eclipse::EclipsePtr->DisplayVolatilityGraph();
		this->close();
	}

	play = !play;
}//End method


void VolatilityGraph::SubscribeToOptionTopic(std::string symbol , std::string topic)
{
	//Framework::NEclipse::QpidSubscriber::GetQpidInstance()->SubscribeToOptionTopic(symbol,topic,this);
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->ConnectToWOPRBroadcast();
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->SubscribeToOptionTopic(symbol,topic,this);
}

void VolatilityGraph::UnSubscribeFromTopic(std::string symbol)
{
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->UnSubscribeFromTopic(symbol,this);
}

std::string VolatilityGraph::Roundfloat(float a)
{
	std::stringstream sout;
	std::string str;
	sout << std::fixed << std::setprecision(DecimalDigits) << a;
	sout >> str;   
	return str;
}


std::string VolatilityGraph::ConvertIntToString(int a)
{
	std::string _str;
	std::back_insert_iterator<std::string> sink(_str);
	boost::spirit::karma::generate(sink,a);
	return _str;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------Table Display-----------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------

void VolatilityGraph::InitializeOptionsTable()
{
	ModelOptionTable = new QStandardItemModel();
	filterproxyModel = new Framework::NEclipse::VolatilityGraph_FilterProxyModel(this);
	DecimalDigits = atoi(Eclipse::GetConfigValue("DecimalDigits").c_str());
	QStringList labels;

	labels.push_back("Symbol");
	labels.push_back("Exp Date");
	labels.push_back("Strike");
	labels.push_back("Bid Implied");
	labels.push_back("Bid");
	labels.push_back("Ask");
	labels.push_back("Ask Implied");
	labels.push_back("Daily Volume");
	labels.push_back("Daily Trades");
	labels.push_back("Open Interest");

	ModelOptionTable->setHorizontalHeaderLabels(labels); //Labels for the columns
	
	filterproxyModel->setSourceModel(ModelOptionTable);
	
	ui.tableOptions->setModel(filterproxyModel);

	ui.tableOptions->setSortingEnabled(true);
	ui.tableOptions->horizontalHeader()->setMovable(true); 
	//ui.tableOptions->setModel(ModelOptionTable);
}


void VolatilityGraph::ManageTableUpdates(Serializable::OptionTick_ser otick)
{
	//Check if this form even needs this update
	//-----------------------------------------------------------------------------------------------
	if(!std::binary_search(SubscribedSymbols.begin(),SubscribedSymbols.end(),otick.symbol())) return;
	//-----------------------------------------------------------------------------------------------

	UpdateImpliedVolatilityCurve(otick);
	 
	  //UpdateVolumeCurve(otick.dailyvolume(),otick.strike());
	 //UpdateTradesCurve(otick.dailytrades(),otick.strike());
	 //UpdateOpenInterestCurve(otick.openinterest(),otick.strike());
	
	/* //No Need to display these plots anymore
	 if(ui.checkBoxVolatility->checkState()==Qt::Checked)   {
		                                                      ui.LinePlot->replot();    }
	 
	 if(ui.checkBoxVolume->checkState()==Qt::Checked)       {
		                                                      ui.VolumePlot->replot();  }
	 if(ui.checkBoxTrades->checkState()==Qt::Checked)       {
		                                                      ui.TradesPlot->replot();  }
	 if(ui.checkBoxOpenInterest->checkState()==Qt::Checked) {
	                                                     ui.OInterestPlot->replot();} */
	 	 
	std::string symb = otick.symbol();

	QList<QStandardItem*> lst = ModelOptionTable->findItems(symb.c_str(),Qt::MatchExactly,0);
	
	if(lst.count()>0)
	{
		//Symbol exists in the model
		//boost::thread t(boost::bind(&VolatilityGraph::MakeCellBlink,this,lst[0]->row())); //Start the blinker
		UpdateExistingItemInModel(otick,lst[0]->row());
		
	}
	else
	{
		AddNewItemToModel(otick);
	}
	
}//End Method



void VolatilityGraph::AddNewItemToModel(const Serializable::OptionTick_ser& otick)
{
	QStandardItem* item_symbol           =  new QStandardItem(otick.symbol().c_str());									   //Symbol
	QStandardItem* item_Exp_Date		 =  new QStandardItem(otick.expdate().c_str());									   //ExpDate
	QStandardItem* item_strike			 =  new QStandardItem(Roundfloat(otick.strike()).c_str());			               //Strike  
	QStandardItem* item_bid_imp		     =  new QStandardItem(Roundfloat(otick.bid_imp_volatility()).c_str());             //BidImplied
	QStandardItem* item_bid  		     =  new QStandardItem(Roundfloat(otick.bid()).c_str());						       //Bid
	QStandardItem* item_ask				 =  new QStandardItem(Roundfloat(otick.ask()).c_str());							   //Ask
	QStandardItem* item_ask_imp_volat    =  new QStandardItem(Roundfloat(otick.ask_imp_volatility()).c_str());			   //ASkImpVolat
	QStandardItem* item_daily_volume     =  new QStandardItem(ConvertIntToString(otick.dailyvolume()).c_str());			   //DailyVolume
	QStandardItem* item_daily_trades	 =  new QStandardItem(ConvertIntToString(otick.dailytrades()).c_str());			   //DailyTrades
	QStandardItem* item_open_interest    =  new QStandardItem(Roundfloat(otick.openinterest()).c_str());				   //OpenInterest


	QList<QStandardItem*> lst ;
	lst.push_back(item_symbol);
	lst.push_back(item_Exp_Date);
	lst.push_back(item_strike);
	lst.push_back(item_bid_imp);
	lst.push_back(item_bid);
	lst.push_back(item_ask);
	lst.push_back(item_ask_imp_volat);
	lst.push_back(item_daily_volume);
	lst.push_back(item_daily_trades);
	lst.push_back(item_open_interest);
	ModelOptionTable->appendRow(lst);
}

void VolatilityGraph::UpdateExistingItemInModel(const Serializable::OptionTick_ser& otick,int rowno)
{
	/*
	labels.push_back("Exp Date");
	labels.push_back("Strike");
	labels.push_back("Bid Implied");
	labels.push_back("Bid");
	labels.push_back("Ask");
	labels.push_back("Ask Implied");
	labels.push_back("Daily Volume");
	labels.push_back("Daily Trades");
	labels.push_back("Open Interest");
	*/

	int i=1;
	ModelOptionTable->item(rowno,i)->setText(otick.expdate().c_str());  i++ ;								  //ExpDate
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.strike()).c_str());  i++ ;					  //Strike  
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.bid_imp_volatility()).c_str()); i++ ;           //BidImplied
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.bid()).c_str()); i++ ;						  //Bid
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.ask()).c_str());   i++ ;						  //Ask
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.ask_imp_volatility()).c_str());   i++ ;         //ASkImpVolat
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.dailyvolume()).c_str());    i++ ;		  //DailyVolume
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.dailytrades()).c_str());    i++ ;		  //DailyTrades
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.openinterest()).c_str());    i++ ;			  //OpenInterest
}