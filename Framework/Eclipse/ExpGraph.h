#ifndef EXPGRAPH_H
#define EXPGRAPH_H

#include <QMainWindow>
#include "ui_ExpGraph.h"
#include "MySQL-Eclipse.h"
#include "OptionTick.pb.h"
#include "QStandardItemModel"
#include "qcustomplot.h"
#include "ExpDateProxy.h"
#include "QTimer"

class ExpGraph : public QMainWindow
{
	Q_OBJECT

public:
	ExpGraph(QWidget *parent = 0);
	~ExpGraph();
	std::string getFormGUID(); 

private:
	QTimer* UpdateLinePlot;
	int colorindex;
	QVector<QString> CurveColors;
	Ui::ExpGraph ui;
	std::string FormGUID;
	bool isFirstPlot;
	bool isTableHidden;
	int PlotTickPass;
	void populateColors();
	std::vector<std::string> SubscribedSymbols;
	std::map<std::string,QVector<double>> IndividualXStrikes; //Date - Strikes
	std::map<std::string,QCPGraph*>  SymbolsPlotted;
	std::map<std::string,QVector<double>> SymbolsImpliedVolatility;

	enum PlotType {VolatilityType};
	bool play;
	Framework::NEclipse::DBaseConnection *db;
	
	Framework::NEclipse::ExpDate_FilterProxyModel* FilterModelOptionTable;

	QStandardItemModel* ModelOptionTable;  
	QVector<double> strikes_x; 
	void InitializeExpGraph();
	void InitializeOptionsTable();
	void populateDistinctSymbols();
	void CalculateMinDifference(std::vector<double>& vrange ,double& rdifference);
	
	void PopulatePlotsInitializingData(Serializable::Option_collection_ser& otick);
	void AddNewItemToModel(const Serializable::OptionTick_ser& otick);
	void UpdateExistingItemInModel(const Serializable::OptionTick_ser& otick,int rowno);
	std::string ConvertIntToString(int a);
	std::string Roundfloat(float a);

	void SubscribeToOptionTopic(std::string symbol , std::string topic);
	//void UnSubscribeFromTopic(std::string symbol);
	void InitializeLinePlotGraph(double x_min_diff);
	void RealignYaxis(const double& val);

	
	void InitializePlotGraph(double x_min_diff,QCustomPlot* plot);
	void ManagePlots(const Serializable::OptionTick_ser& otick);
	void AddNewSymbolPlot(const Serializable::OptionTick_ser* otick);
	void UpdateSymbolPlot(const Serializable::OptionTick_ser* otick);
	
	std::string  AlterDateFormat(const std::string& date);

public slots:
	void SubscribeToSymbols();
	void ManageTableUpdates(Serializable::OptionTick_ser otick);
	void HideTable();
	void LinePlotRangeChanged(const QCPRange &newRange);
	void SymbolChanged(QString str);
	void TimeOut();
};

#endif // EXPGRAPH_H
