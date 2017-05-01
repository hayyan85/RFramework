#ifndef OPTIONQUOTER_H
#define OPTIONQUOTER_H

#include <QDialog>
#include "ui_OptionQuoter.h"
#include "MySQL-OMEGA.h"
#include "SymbolLoad.h"
#include "QStandardItemModel"
#include "OptionTick.pb.h"
#include "Filter.h"
#include <map>
#include <vector>
#include "RTypes.pb.h"
#include <boost/thread/mutex.hpp>
#include <QTimer>
#include <QtGui/QMainWindow>
#include "exprtk.hpp"
#include "SPX_Algo1_Neutral.h"
#include "boost/function.hpp"


#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


class CancelOrderDetails;

class OptionQuoter : public QMainWindow
{
	Q_OBJECT

public:
	OptionQuoter(QWidget *parent = 0, Qt::WFlags flags = 0);
	
	~OptionQuoter();
	std::string getFormGUID();
	void StopAutomation();

private:
	
	bool BHideFilter;
	bool BHideConsole;
	bool BHideUpdates;
	bool StartQuoter;
	bool InternalAlgorithm;
	std::vector<std::string> SubscribedSymbols;

	//------------------------------------------------
	boost::function<void()> InternalAlgorithmFunction;
	SPX_ALGO1_NEUTRAL spx_algo1_neut;
	std::map<std::string,CancelOrderDetails*> CancelDetailRecorder;
	//------------------------------------------------
	


	//----------------------------------------------------------------------------------------------------------------
	//--------------------------------------------EXPRESSION STRING OPTIONS-----------------------------------------------
	//----------------------------------------------------------------------------------------------------------------
	std::string ToolTip_filter;
	exprtk::symbol_table<double> symbol_table;
	exprtk::expression<double> expression;
	exprtk::parser<double> parser;
	double expression_result;
	std::string expression_string;
	int no_of_columns;
	std::map<std::string,QStandardItem*> column_cell_mapper; //contains mapping of selection to cell
	std::vector<std::string> SelectedColumns;
	void AddColumnToExpression(std::string colname);
	//----------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------


	enum MType {OrderType,CancelType,Other};
	enum OrderTrackerColEnum {OrderID,Side,Quantity,Price,Destination,Sterling_Code,SearchString,Cancel_Order_Column};
	enum InputRows { Max_Pos ,Current_Pos, Max_Bid , Max_Offer , Min_Offer };

	QTimer* TimerEnableGUIDisplay;  //Checks if no open orders in order tracker then enables GUI 
	std::vector<std::string> ExchangesSelected;
	volatile bool StartAutomationProcess;
	volatile bool AutomationPaused;

	Ui::OptionQuoter ui;
	SymbolLoad* symbol_load_inst;
	Framework::NOmega::DBaseConnection* dbconnect;
	
	
	QStandardItemModel* ModelOptionQuoter;
	QStandardItemModel* ModelExchanges;
	QStandardItemModel* ModelInputs;
	QStandardItemModel* ModelOrderTracker;
	QStandardItemModel* ModelExpressionTester;;


	

	void InitializeModel();
	std::string FormGUID;
	std::string Account;
	std::string Tif;
	void GetExchangeDetails(std::string& exchange_name,int &OrderSize, int& MaxCancel , int& TotalCancel);
	void AddOptionToTable(const std::string& type , const std::string& symbolName );
	void SubscribeToTopic(std::string symbol , std::string topic);
	void UnSubscribeFromTopic(std::string symbol);
	void ManageSubscriptions();
	void DisplayExchanges();
	void DisplayInputs();
	void DisplayLayout();
	void populateFilters();
	
	void TestConditionalFilters();

	bool TestInputFilter(Serializable::OptionTick_ser& opt);
	bool FilterInputValues();
	void UnSubscribeFromAllSymbols();
	
	int  FindIndexOfList(std::string& t);
	void RemoveFilter(int i);
	void PopulateOptionsTable();
	bool SendOptionOrder(float& Qbid,float& Qask);
	void SendCustomOptionOrder(const float& Qbid,const std::string Exch,const int& ordsize);
	void InitializeOrderTrackerModel();
	void PrintConsole(MType mt,std::string str);
	//----------------------------------------------------------
	void AdddNewOpenOrder(Serializable::CustROrder_ser& opt);
	bool CheckIfOpenOrder(Serializable::CustROrder_ser& opt);
	//----------------------------------------------------------
	void TradeUpdate(const Serializable::TradeUpdate& tupd);
	void SendCancelOrder();
	void ForceCancelOrder(std::string& order_id);
	bool SearchFilter(std::string& filter_text );

	void ConstructToolTip();
	void EnableDisableDisplay(bool type);

	void CancelAllPendingOrders();
	void UpdateCancelExchange(Serializable::CustROrder_ser& rord);

	//void InitializeFormSettings();
	void PositionedFilterAddition(std::string t);

	void StartAutomation();

	void Process_SPX_Algo1_Neutral();
	double Extract_Highest_Open_order_Price();

	public slots:
		void ShowSymbolList();
		void UpdateOptionModel(Serializable::OptionTick_ser otick);
		void RemoveSymbolFromModel(std::string symbol);
		void ExchangeDataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight ) ;
		void ExchangeSelected(QStandardItem* itm);
		void UpdateOpenOrder(Serializable::RUpdatePacket pkt);
		void CancelOrderCheck(QStandardItem* itm);
		void TimerSlotEnableGUITimeOut();
		void DisplayErrorMessage(std::string ErrorMsg);
		void PauseAutomation();
		void HideFilter();
		void HideConsole();
		void HideUpdates();
		//-----------------------------------
		void AddExpressionFilter();
		void AddColumnToExpression();
		void TestExpression();
		void FilterContextMenu(const QPoint& pos);
		//-----------------------------------
		void SaveExpression();
		void LoadExpression();
		void ManageAutomation();
		void Run_SPX_Algo1_NeutralAction();
};

class CancelOrderDetails
{
	IMPLEMENT_SET_GET_METHOD(float,qbid);
	IMPLEMENT_SET_GET_METHOD(float,qask);
	IMPLEMENT_SET_GET_METHOD(float,OrdSize);
	IMPLEMENT_SET_GET_METHOD(float,AskSize);
	IMPLEMENT_SET_GET_METHOD(float,Spread);
};
#endif // OPTIONQUOTER_H

