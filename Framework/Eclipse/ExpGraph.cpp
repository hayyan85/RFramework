#include "ExpGraph.h"
#include "Eclipse.h"
#include "MySQL-Eclipse.h" 

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "OptionTick.pb.h"
#include "boost/spirit/include/qi.hpp"
#include <boost\spirit\include\karma.hpp>
#include <sstream>
#include <iomanip>  

#include "Network.h"
#include "OptionTick.pb.h"

#include "ExpDateProxy.h"


#define ExpGraph_RefreshRate 250 

ExpGraph::ExpGraph(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	db = new Framework::NEclipse::DBaseConnection();
	FormGUID = boost::uuids::to_string(boost::uuids::random_generator()());
	db->InitiateDBConnection();
	play = false;
	InitializeExpGraph();
	populateColors();
	colorindex = -1;
	isFirstPlot = false;
	isTableHidden = false;
	QObject::connect(ui.cmdStart,SIGNAL(clicked()),this,SLOT(SubscribeToSymbols()));
	QObject::connect(ui.cmdHideTable,SIGNAL(clicked()),this,SLOT(HideTable()));
	connect(ui.LinePlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(LinePlotRangeChanged(QCPRange)));
	QObject::connect(ui.comboDistinctSymbol,SIGNAL(currentIndexChanged(QString)),this,SLOT(SymbolChanged(QString)));
}

//Destructor
//Close the Db instance
ExpGraph::~ExpGraph()
{ 
	db->CloseDBConnection();
}

void ExpGraph::LinePlotRangeChanged(const QCPRange &newRange)
{
	ui.LinePlot->yAxis->setRangeLower(0);
}

void ExpGraph::SymbolChanged(QString str)
{
	ui.comboCallPut->clear();
	ui.comboCallPut->addItem("--");
	std::vector<std::string> temp = db->GetCallAndPutsSymbolsCriteria(str.toStdString());
	for(std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		ui.comboCallPut->addItem((*it).c_str());	
	}
}

void ExpGraph::HideTable()
{
	if(!isTableHidden) //Table is not hidden - Hide it
	{
		ui.frametableDisplay->setVisible(false);
		ui.cmdHideTable->setText("Show Table");
	}
	else               //Table is hidden show it
	{
		ui.frametableDisplay->setVisible(true);
		ui.cmdHideTable->setText("Hide Table");
	}
	isTableHidden = !isTableHidden;
}


#pragma  region ColorPicker
void ExpGraph::populateColors()
{
	
	CurveColors.push_back("aqua");	
	CurveColors.push_back("magenta");	
	CurveColors.push_back("limegreen");
	CurveColors.push_back("darkolivegreen");
	CurveColors.push_back("turquoise");
	CurveColors.push_back("palegreen");


	CurveColors.push_back("royalblue");
	CurveColors.push_back("yellow");
	CurveColors.push_back("springgreen");
	CurveColors.push_back("seagreen");
	CurveColors.push_back("salmon");
	CurveColors.push_back("magenta");
	CurveColors.push_back("gold");
	CurveColors.push_back("orangered");
	CurveColors.push_back("yellowgreen");
	CurveColors.push_back("lightpink");
	CurveColors.push_back("dodgerblue");
	CurveColors.push_back("forestgreen");
	CurveColors.push_back("olivedrab");

}
#pragma  endregion

#pragma region Initializations

std::string ExpGraph::getFormGUID()
{
	return FormGUID;
}

void ExpGraph::InitializeExpGraph()
{
	InitializeOptionsTable();
	populateDistinctSymbols();
	ui.comboCallPut->addItem("--");
	PlotTickPass = atoi(Eclipse::GetConfigValue("PlotTickPass").c_str());
}

void ExpGraph::InitializeOptionsTable()
{
	FilterModelOptionTable = new Framework::NEclipse::ExpDate_FilterProxyModel(this);
		
	ModelOptionTable = new QStandardItemModel();
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
	
	FilterModelOptionTable->setSourceModel(ModelOptionTable);
	ui.tableOptions->horizontalHeader()->setMovable(true); 
	ui.tableOptions->setSortingEnabled(true);

	ui.tableOptions->setModel(FilterModelOptionTable);

	//ui.tableOptions->horizontalHeader()->moveSection(0,7);

}


void ExpGraph::populateDistinctSymbols()
{
	std::vector<std::string> dsymbol = db->GetDistinctSymbols();

	ui.comboDistinctSymbol->addItem("--");	
	for(std::vector<std::string>::iterator it = dsymbol.begin(); it != dsymbol.end(); it++ )
	{
		ui.comboDistinctSymbol->addItem((*it).c_str());	
	}
	ui.comboDistinctSymbol->setCurrentIndex(0);
	ui.comboCallPut->setCurrentIndex(0);
}

//This method initializes the plot display and sets the x-axis
void ExpGraph::InitializePlotGraph(double x_min_diff,QCustomPlot* plot)
{
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
	QColor Fontcolor("yellow");
	ui.LinePlot->legend->setVisible(true);
	ui.LinePlot->legend->setFont(QFont("Helvetica",9));
	ui.LinePlot->legend->setTextColor(Fontcolor);
	QBrush brush;
	QColor color("azure");
	brush.setColor(color);
	
	ui.LinePlot->legend->setBrush(brush);
}

void ExpGraph::InitializeLinePlotGraph(double x_min_diff)
{
	InitializePlotGraph(x_min_diff,ui.LinePlot);
	ui.LinePlot->yAxis->setSubTickLength(5);
	ui.LinePlot->yAxis->setTickLength(10);
}
#pragma  endregion

#pragma  region Start Symbol Subscription

void ExpGraph::TimeOut()
{
	ui.LinePlot->replot(); 
}


//This method realign the date that will be stored as 
//a key in the map. This expiration date format is the
//same format received from IQFeed
std::string ExpGraph::AlterDateFormat(const std::string& date)
{
	QStringList lst = QString(date.c_str()).split("-");
	std::string dt = lst[1].toStdString() + "/" + lst[2].toStdString() + "/" + lst[0].toStdString();
	return dt;
}

void ExpGraph::SubscribeToSymbols()
{
	std::string symb = ui.comboDistinctSymbol->currentText().toStdString();
	std::string calput = ui.comboCallPut->currentText().toStdString();
	
	
	//These are the symbols that you would subscribe to
	SubscribedSymbols = db->GetSymbolsOnCallPutCriteria(symb,calput); //Might return multiple symbols
	std::sort(SubscribedSymbols.begin(),SubscribedSymbols.end());     //Sort for binary_search later
	
	if(play == false)
	{
		if(symb == "--" || calput == "--")
		{
			return;
		}

		//Extract All the expiration dates of a symbol that have C/P 
		std::vector<std::string> ExpDates = db->GetRelevantExpirationDatesCriteria(symb,calput); //Might return multiple Exp dates

		//Extract individual strikes of individual expiration dates
		for(int j=0 ; j<ExpDates.size(); j++)
		{
			QVector<double> Strk = QVector<double>::fromStdVector(db->GetStrikes(symb,ExpDates[j],calput));

			if(Strk.size()>0)
			{
				IndividualXStrikes[AlterDateFormat(ExpDates[j])] = Strk; 
			}
		}

		strikes_x = QVector<double>::fromStdVector(db->GetStrikesOnCallPutCriteria(symb,calput));
		std::sort(strikes_x.begin(), strikes_x.end(), std::greater<double>()); 

		//#############################################################################################################
		//#############################################################################################################
		//REMOVE DUPLICATE ITEMS FROM THE VECTOR
		QVector<double>::iterator it;
		it = std::unique (strikes_x.begin(), strikes_x.end());  
		strikes_x.resize( std::distance(strikes_x.begin(),it) ); 
		//#############################################################################################################
		//#############################################################################################################

		//Retrieve a list of the previous options and then use it to generate the y-scale axis;
		Serializable::Option_collection_ser oc = Framework::NEclipse::QpidSubscriber::GetQpidInstance()->WOPRQuery_OptionUpdates(SubscribedSymbols); //Do

		//Obtain the extremes for the y-axis
		double x_rdifference;

		CalculateMinDifference(strikes_x.toStdVector(),x_rdifference);                                     //Get min distance between two points on x-axis     

		//-----------------------------------------------------------------------------------------------------------------------------
		InitializeLinePlotGraph(x_rdifference); //Handles and sets up the plot for the x-axis (strikes)
		//-----------------------------------------------------------------------------------------------------------------------------

		PopulatePlotsInitializingData(oc); //Insert the first initializing data

		//Start timer for updating the value
		//Start the timer - This timer updates the GUI thread
		UpdateLinePlot = new QTimer(this);
		UpdateLinePlot->setInterval(ExpGraph_RefreshRate);
		UpdateLinePlot->start();
		connect(UpdateLinePlot, SIGNAL(timeout()), this, SLOT(TimeOut()));

		SubscribeToOptionTopic("ParameterNoUse", "ParameterNoUse");
		ui.cmdStart->setText("Stop");
	}
	else
	{

		Eclipse::EclipsePtr->DisplayExpirationGraph();
		this->close();
	}
	
	play =! play;
	
}//End Method


void ExpGraph::SubscribeToOptionTopic(std::string symbol , std::string topic)
{
	//Framework::NEclipse::QpidSubscriber::GetQpidInstance()->SubscribeToOptionTopic(symbol,topic,this);
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->ConnectToWOPRBroadcast();
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->SubscribeToOptionTopic(symbol,topic,this);
}

/*
void ExpGraph::UnSubscribeFromTopic(std::string symbol)
{
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->UnSubscribeFromTopic(symbol,this);
}
*/

void ExpGraph::PopulatePlotsInitializingData(Serializable::Option_collection_ser& otick)
{
	for(int i=0;i< otick.option_tick_collection_size();i++)
	{
		//ManagePlots(otick.option_tick_collection(i));
		ManageTableUpdates(otick.option_tick_collection(i));
	}
}

#pragma  endregion


#pragma  region String Utilities
std::string ExpGraph::ConvertIntToString(int a)
{
	std::string _str;
	std::back_insert_iterator<std::string> sink(_str);
	boost::spirit::karma::generate(sink,a);
	return _str;
}

std::string ExpGraph::Roundfloat(float a)
{
	std::stringstream sout;
	std::string str;
	sout << std::fixed << std::setprecision(2) << a;
	sout >> str;   
	return str;
}
#pragma  endregion


//This method compares minimum difference between two consecutive nos (7,6,5,4)
void ExpGraph::CalculateMinDifference(std::vector<double>& vrange ,double& rdifference)
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


//This method manages the plots
//Checks if its a new symbol or old one to update
void ExpGraph::ManagePlots(const Serializable::OptionTick_ser& otick)
{
  if(SymbolsPlotted.find(otick.expdate())!=SymbolsPlotted.end())
  {
	  //Symbol present simply update the plot
	  UpdateSymbolPlot(&otick);
  }
  else
  {
     //Symbol NOT present - Create a new plot
	  AddNewSymbolPlot(&otick);
  }
}

void ExpGraph::AddNewSymbolPlot(const Serializable::OptionTick_ser* otick)
{
	colorindex++;
	QColor c;
	c.setNamedColor(CurveColors[colorindex]);
	QPen NewPen;
	NewPen.setColor(c);
	NewPen.setWidth(2);
	QCPGraph* grp = ui.LinePlot->addGraph();
	grp->setName(otick->expdate().c_str());
	grp->setPen(NewPen);
	grp->setLineStyle(QCPGraph::LineStyle::lsLine);
	grp->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));

	
	//---------------------------------------------------------------------------------------------
	if(!isFirstPlot) //This is the first symbol that came in
	{ 
		ui.LinePlot->yAxis->setRange(otick->mp_imp_volatility(),otick->mp_imp_volatility()+50);
		isFirstPlot = true ; 
	}
	else
	{
		RealignYaxis(otick->mp_imp_volatility());
	}
	//---------------------------------------------------------------------------------------------

	QVector<double> vec;
	
	
	vec.resize(IndividualXStrikes[otick->expdate()].size()); //Resize to the actual strikes for the expiration

	SymbolsPlotted[otick->expdate()] = grp;
	SymbolsImpliedVolatility[otick->expdate()] = vec;
	

	int pos = IndividualXStrikes[otick->expdate()].indexOf(otick->strike());
	if(pos!=-1)
	{
		//SymbolsImpliedVolatility[otick->expdate()][pos]= otick->mp_imp_volatility();
		SymbolsImpliedVolatility.at(otick->expdate())[pos]= otick->mp_imp_volatility();
		SymbolsPlotted.at(otick->expdate())->setData(IndividualXStrikes.at(otick->expdate()),SymbolsImpliedVolatility.at(otick->expdate()));
	}
		
	//ui.LinePlot->replot();
}

void ExpGraph::UpdateSymbolPlot(const Serializable::OptionTick_ser* otick)
{
    //int pos = strikes_x.indexOf(otick->strike());
	int pos = IndividualXStrikes[otick->expdate()].indexOf(otick->strike());
	if(pos!=-1)
	{
		RealignYaxis(otick->mp_imp_volatility());
		SymbolsImpliedVolatility.at(otick->expdate())[pos]= otick->mp_imp_volatility();
		//SymbolsPlotted[otick->expdate()]->setData(strikes_x,SymbolsImpliedVolatility[otick->expdate()]);
		SymbolsPlotted.at(otick->expdate())->setData(IndividualXStrikes.at(otick->expdate()),SymbolsImpliedVolatility.at(otick->expdate()));
	}
	//ui.LinePlot->replot();
}

void ExpGraph::RealignYaxis(const double& val)
{

	double upper_range = ui.LinePlot->yAxis->range().upper;
	double lower_range = ui.LinePlot->yAxis->range().lower;

	//Check if incoming value is greater than the upper limit
	if(val > upper_range)
	{
		ui.LinePlot->yAxis->setRange(lower_range-50,val+50);
	}
	//Check if incoming value is less than the lower limit
	else if(val < lower_range)
	{
		ui.LinePlot->yAxis->setRange(val,upper_range);
	}

	

}


#pragma  region ManageTableUpdates
void ExpGraph::ManageTableUpdates(Serializable::OptionTick_ser otick)
{
	//Check if this form even needs this update
	//-----------------------------------------------------------------------------------------------
	if(!std::binary_search(SubscribedSymbols.begin(),SubscribedSymbols.end(),otick.symbol())) return;
	//-----------------------------------------------------------------------------------------------

	ManagePlots(otick);
	
	std::string symb = otick.symbol();
	QList<QStandardItem*> lst = ModelOptionTable->findItems(symb.c_str(),Qt::MatchExactly,0);

	if(lst.count()>0)
	{
		UpdateExistingItemInModel(otick,lst[0]->row());
	}
	else
	{
		AddNewItemToModel(otick);
	}
}//End Method


void ExpGraph::AddNewItemToModel(const Serializable::OptionTick_ser& otick)
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

void ExpGraph::UpdateExistingItemInModel(const Serializable::OptionTick_ser& otick,int rowno)
{

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
#pragma  endregion 