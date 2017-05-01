#ifndef VOLATILITYGRAPH_H
#define VOLATILITYGRAPH_H

#include <QWidget>
#include "ui_VolatilityGraph.h"
#include "MySQL-Eclipse.h"
#include "OptionTick.pb.h"
#include "QStandardItemModel"
#include "boost/thread/mutex.hpp"
#include "qcustomplot.h"
#include "qsortfilterproxymodel.h"
#include "VolatilityProxy.h"
#include "QTimer"

class VolatilityGraph : public QWidget
{
	Q_OBJECT

public:
	VolatilityGraph(QWidget *parent = 0);
	~VolatilityGraph();
	std::string getFormGUID(); 

private:
	QTimer* UpdateLinePlot;
	Framework::NEclipse::VolatilityGraph_FilterProxyModel* filterproxyModel;
	std::vector<std::string> SubscribedSymbols;
	int PlotTickPass;
	int DecimalDigits;
	Ui::VolatilityGraph ui;
	std::string FormGUID;

	QPen AskImpliedPen;
	QPen BidImpliedPen;
	QPen MPImpliedPen;	 
	QPen VolumePlotPen; 
	QPen TradesPlotPen;
    
	boost::mutex mutex_blinker;

	QVector<double> strikes_x; 
	QVector<double> ask_implied_y;
	QVector<double> bid_implied_y;
	QVector<double> mp_implied_y;
	QVector<double> volume_y;
	QVector<double> trades_y;
	QVector<double> open_interest_y;

	bool Tableshowing;

	bool play;
	void InitializeVolatilityGraph(); 
	
	//------------------------------------------------------------------------------
	void InitializePlotGraph(double x_min_diff,QCustomPlot* plot);
	void InitializeLinePlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff);
	void InitializeVolumePlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff);
    void InitializeTradesPlotGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff);
	void InitializeOpenInterestGraph(double ylow,double yhigh,double x_min_diff,double y_min_diff);
	//-----------------------------------------------------------------------------

	void InitializeOptionsTable();
	void populateDistinctSymbols();
	void SubscribeToOptionTopic(std::string symbol , std::string topic);
	void UnSubscribeFromTopic(std::string topic);
	Framework::NEclipse::DBaseConnection *db;
	QStandardItemModel* ModelOptionTable;  
	void AddNewItemToModel(const Serializable::OptionTick_ser& otick);
	void UpdateExistingItemInModel(const Serializable::OptionTick_ser& otick,int rowno);
	std::string Roundfloat(float a);
	std::string ConvertIntToString(int a);
	
	

	//---------------------------------------------------------------------------
	enum PlotType {VolatilityType,VolumeType,TradeType,OpenInterestType};
	void UpdateImpliedVolatilityCurve(Serializable::OptionTick_ser& otick);
	void UpdateAskImpliedVolatilityCurve(double Aivolat,double strike);
	void UpdateBidImpliedVolatilityCurve(double Bivolat, double strike);
	void UpdateMPVolatilityCurve(double mpvolat, double strike);
	void UpdateVolumeCurve(double vol, double strike);
	void UpdateTradesCurve(double trades, double strike);
	void UpdateOpenInterestCurve(double open_interest,double strike);
	void manage_yaxis_range(double lowest,double highest, QCustomPlot* plt,PlotType pt);
	//--------------------------------------------------------------------------

	//------------------------Helper Methods for plotting-------------------------
	void PopulatePlotsInitializingData(Serializable::Option_collection_ser& otick);
	void GenerateExtremesForYAxis(Serializable::Option_collection_ser& oc,double& min,double& max,double& rdifference,PlotType pt);
	void CalculateMinDifference(std::vector<double>& vrange ,double& rdifference);
	void FindExtremes(Serializable::OptionTick_ser& oc,double& min,double& max);
    //-----------------------------------------------------------------------------

	void MakeCellBlink(int row);

signals:
	void QTUpdateVolatilityThread(Serializable::OptionTick_ser otick);

public slots:

	void SymbolChanged(QString symb);
	void DateChanged(QString date);
	void SubscribeToSymbols();
	void ManageTableUpdates(Serializable::OptionTick_ser otick);
	void RemoveSymbolFromTable(std::string symbol);
	void ShowOptionTable();
	void PlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b);
	void LinePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b);
	void VolumePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b);
	void TradePlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b);
	void OpenInterestPlotableClicked(QCPAbstractPlottable* a , QMouseEvent* b);
	void LinePlotRangeChanged (const QCPRange &newRange);
	void VolumePlotRangeChanged (const QCPRange &newRange);
	void TradePlotRangeChanged (const QCPRange &newRange);
	void OpenInterestPlotRangeChanged (const QCPRange &newRange);

	void TimeOut();
	//-----------------------------------------------------------------------------
	//Show or hide the widget
	void PlotVolatilityShowState(int state);
	void PlotTradesShowState(int state);
	void PlotVolumeShowState(int state);
	void PlotOinterestShowState(int state);
	//-----------------------------------------------------------------------------
	
};

#endif // VOLATILITYGRAPH_H
