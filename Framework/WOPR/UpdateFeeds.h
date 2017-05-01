#ifndef UPDATEFEEDS_H
#define UPDATEFEEDS_H

#include <QWidget>
#include "ui_UpdateFeeds.h"
#include "Network.h"
#include "FeedConnector.h"
#include <boost/unordered_map.hpp>
#include "External.h"
#include "QStandardItemModel"

/*Log4cplus Files does not work with UNICODE Preprocessor*/
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>
#include "MySQL-WOPR.h"

//For shared reading and exclusinve writing
#include <boost/thread/locks.hpp>
#include <string>


 Q_DECLARE_METATYPE(std::string);
 Q_DECLARE_METATYPE(ConsoleType);
 Q_DECLARE_METATYPE(Serializable::OptionTick_ser);

class UpdateFeeds : public QWidget
{
	Q_OBJECT

public:
	UpdateFeeds(QWidget *parent = 0);
	~UpdateFeeds();
	
	static UpdateFeeds* ptrUpdateFeedsForm;
	
	static log4cplus::Logger WOPR_Logger;
	
	//This contains a symbol mapped with a QpidSender Type
	static boost::unordered_map<std::string,Framework::WOPR::QpidConnector*> QpidMapper;


	//Contains a check box next to all tables that could be automated
	QStandardItemModel* model_lists;

	//This contains list of all the symbols that need to be automated
	std::vector<std::string> AutomationSymbol;

	//This contains all the queues dynamically  created
	std::vector<std::string> QpidDynamicQueues;	

	//DBConnection Instance
	Framework::WOPR::DBaseConnection* dbconnect;

	//This method returns all the feed connectors
	std::vector<Framework::WOPR::FeedConnector*> ReturnAllFeedConnectors();

	std::string GetSymbolCallPut(const std::string& symbol);
	void AddSymbolCallPut(const std::string& symbol,const std::string& callput);
	std::string GetOptionStock(const std::string& option_symbol);
	void AddOptionStock(const std::string& option,const std::string& stock);

private:

	//----------------------------------------------------------------
	boost::shared_mutex shared_mutex_CallPutMap;                    //
	boost::shared_mutex shared_mutex_StockMap;                      //
																    //
	//Contains OptionName and CallPut                               //
	std::map<std::string,std::string> OptionCallPut;                //
	                                                                // 
	//Contains OptionName and its StockSymbol                       //
	std::map<std::string,std::string> OptionStockMap;               //
	//----------------------------------------------------------------

	Ui::UpdateFeeds ui;
	int max_socket_limit;
	int sockets_to_silo;
	int SymbolsPerQueue;
	std::string Convert_Int_To_String(int a);
	void InitializeWOPR();
	void RequestLiveQuotes();
	void SelectAutomSymbols();
	void InitializeLoggingLibrary();
	void InitializeSiloSocketIntegration();
	void InitializeListSelectionTable();
	static log4cplus::SharedAppenderPtr WOPR_Appender;
	static std::auto_ptr<log4cplus::Layout> WOPRLayout;
	void SetupNetworkConnectivity();
	void SetupNetworkConnectivity(std::string symbol);
	std::vector<std::string> AvailableTables;
	std::vector<std::string> SelectedTables;
	std::vector<Framework::WOPR::FeedConnector*> Feed_Connector_List;
	void RetrieveOptionStockNames();
	void ShowOptionsForm();
	void AttachStockSymbols(std::vector<std::string>& Collection);
	std::string GetSymbolOfOption(std::string OptionName);

public:
	void AddNewSymbolRuntime(std::string symbol,std::string stock,std::string callput);

public slots:
	void Slot_InitiateConnection();
	void TableClicked(QStandardItem* ind);
};



class MoveStocksToTop
{
public:
	bool operator()(const std::string& first, const std::string& second) 
	{
		return first.size() < second.size();
	}
};

#endif // UPDATEFEEDS_H
