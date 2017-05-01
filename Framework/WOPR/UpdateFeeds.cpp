#include "UpdateFeeds.h"
#include <string> 
#include <iostream> 
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <boost\spirit\include\karma.hpp>
#include <ta_libc.h>

#include "FeedConnector.h"
#include "Wopr.h"
#include "Network.h"
#include "boost/unordered_map.hpp"
#include "External.h"
#include "QMessageBox"
#include "OptionFeeds.h"
#include "OptionTick.pb.h"

//---------------------------------------------------------------------------------------------
//Log4cplus Files does not work with UNICODE Preprocessor
//---------------------------------------------------------------------------------------------
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

using namespace Framework::WOPR;

//This contains a mapping of a symbol to its relevant Network Implementation
boost::unordered_map<std::string,Framework::WOPR::QpidConnector*> UpdateFeeds::QpidMapper;

//Address of current form - For Signals and slots
UpdateFeeds* UpdateFeeds::ptrUpdateFeedsForm;


//-----------------------------------------------------------------------------------------------
//Stores whether a symbol is call or put                                                       //
//std::map<std::string,std::string> UpdateFeeds::OptionCallPut;                                //
                                                                                               //
//Stores option name corresponding to stock name                                               //
//std::map<std::string,std::string> UpdateFeeds::OptionStockMap;                               //
//-----------------------------------------------------------------------------------------------


//Logging Variables
log4cplus::SharedAppenderPtr UpdateFeeds::WOPR_Appender;
log4cplus::Logger UpdateFeeds::WOPR_Logger;
std::auto_ptr<log4cplus::Layout> UpdateFeeds::WOPRLayout;


UpdateFeeds::UpdateFeeds(QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	qRegisterMetaType<std::string>(); //Since we have signals that pass std::strings
	qRegisterMetaType<ConsoleType>(); //Since we have signals that pass std::strings
	qRegisterMetaType<Serializable::OptionTick_ser>(); //Since we have signals that pass Serializable::OptionTick_ser
	QObject::connect(ui.pushConnect, SIGNAL(clicked()), this, SLOT(Slot_InitiateConnection()));
	ptrUpdateFeedsForm = this;
	InitializeListSelectionTable();  //Initializes the DB Connection
	QObject::connect(model_lists,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(TableClicked(QStandardItem*)));
	max_socket_limit = atoi(WOPR::GetConfigValue("Max_Sockets_Limit").c_str());
	sockets_to_silo = atoi(WOPR::GetConfigValue("Sockets_to_Silo").c_str());
	SymbolsPerQueue = atoi(WOPR::GetConfigValue("SymbolsPerQueue").c_str());

}

void UpdateFeeds::ShowOptionsForm()
{
	OptionFeeds *u = new OptionFeeds(this);
	u->setFixedSize(u->size());
	u->setWindowFlags(Qt::Dialog);
	u->show();
}

std::vector<Framework::WOPR::FeedConnector*> UpdateFeeds::ReturnAllFeedConnectors()
{
	return Feed_Connector_List; 
}

//###################################################################################################################
//#########################################THESE METHODS HANDLE STATIC VARIABLES#####################################
//###################################################################################################################

std::string UpdateFeeds::GetSymbolCallPut(const std::string& symbol)
{
	boost::shared_lock< boost::shared_mutex > lock(shared_mutex_CallPutMap);
	return OptionCallPut[symbol];
}

void UpdateFeeds::AddSymbolCallPut(const std::string& symbol,const std::string& callput)
{
	boost::unique_lock< boost::shared_mutex > lock(shared_mutex_CallPutMap);
	OptionCallPut[symbol] = callput;
}

std::string UpdateFeeds::GetOptionStock(const std::string& option_symbol)
{
	boost::shared_lock< boost::shared_mutex > lock(shared_mutex_StockMap);
	if(OptionStockMap.find(option_symbol) != OptionStockMap.end())
	{  
		return OptionStockMap.at(option_symbol);
	}
	else
	{
		__debugbreak();
		return "NotPresent";
	}
}

void UpdateFeeds::AddOptionStock(const std::string& option,const std::string& stock)
{
	boost::unique_lock< boost::shared_mutex > lock(shared_mutex_StockMap);
	OptionStockMap[option] = stock;
}
//###################################################################################################################
void UpdateFeeds::TableClicked(QStandardItem* ind)
{
	std::string col_name = model_lists->item(ind->row(),0)->text().toStdString();
	if( ind->checkState()==Qt::Checked)
	{
		SelectedTables.push_back(col_name);
	}
	else
	{ 
		SelectedTables.erase(std::find(SelectedTables.begin(), SelectedTables.end(), col_name));
	}
}

void UpdateFeeds::InitializeListSelectionTable()
{
	model_lists = new QStandardItemModel();
	ui.table_lists->setModel(model_lists);
	dbconnect = new Framework::WOPR::DBaseConnection();
	dbconnect->InitiateDBConnection();

	
	QStringList labels;
	labels.push_back("Table Name");
	labels.push_back("Status");
	model_lists->setHorizontalHeaderLabels(labels); //Labels for the columns
	
	
	AvailableTables = dbconnect->RetrieveAvailableLists();
	
	for(int i=0 ; i<AvailableTables.size();i++)
	{
		QList<QStandardItem*> lst ;
		QStandardItem* item_tbname = new QStandardItem(AvailableTables[i].c_str());
		QStandardItem* item_checked=new QStandardItem();
		item_checked->setCheckable(true);
		item_checked->setCheckState(Qt::CheckState::Unchecked);
		lst.push_back(item_tbname);
		lst.push_back(item_checked);
		model_lists->appendRow(lst);
	}
}//End Method


void UpdateFeeds::RetrieveOptionStockNames()
{
	OptionStockMap = dbconnect->RetrieveOptionStockNames(SelectedTables);
}



void UpdateFeeds::InitializeLoggingLibrary()
{	
	WOPR_Appender = new log4cplus::FileAppender(LoggingFile);
	WOPR_Appender->setName("ExecutionAppender");
	WOPRLayout = std::auto_ptr<log4cplus::Layout>(new log4cplus::TTCCLayout());;
	WOPR_Appender->setLayout( WOPRLayout );
	WOPR_Logger = log4cplus::Logger::getInstance("EngLogger");
	WOPR_Logger.addAppender(WOPR_Appender);
	WOPR_Logger.setLogLevel ( log4cplus::INFO_LOG_LEVEL );
	//LOG4CPLUS_INFO(EngineLogger, "logEvent");      
}


UpdateFeeds::~UpdateFeeds()
{
	//Close the QPID Connection so that the topics are closed
	for(boost::unordered_map<std::string,Framework::WOPR::QpidConnector*>::iterator it = QpidMapper.begin(); it!=QpidMapper.end();++it)
	{
		it->second->CloseConnection();
	}
}


std::string UpdateFeeds::Convert_Int_To_String(int a)
{
	std::string _str;
	std::back_insert_iterator<std::string> sink(_str);
	boost::spirit::karma::generate(sink,a);
	return _str;
}

void UpdateFeeds::SetupNetworkConnectivity()
{
	
	std::vector<std::string> symbols_being_broadcasted;
	QpidConnector *qc = new QpidConnector();
	qc->Create_Dynamic_Queues(0,"WOPR_BROADCAST",1); //Clears symbol topic map table and creates one topic
	QpidMapper.insert(std::pair<std::string,QpidConnector*>("WOPR_BROADCAST",qc));
	
	/*
	for(int i=1 ; i<AutomationSymbol.size();i++)
	{
		symbols_being_broadcasted.push_back(AutomationSymbol[i]);
		//dbconnect->InsertTopicSymbolMap(AutomationSymbol[i],"--");
	}//End for
	*/
	
	//Insert these into the database - This is a time consuming process
	dbconnect->InsertTopicSymbolCollection(AutomationSymbol);

	//Start the Request-Responser - No need to store this in the vector
	//This method currently caters to the requests of Volatility Graphs
	QpidConnector *service_resp = new QpidConnector();
	service_resp->StartRequestResponser();
	
}


//This method is used for creating topics for symbols at runtime
void UpdateFeeds::SetupNetworkConnectivity(std::string symbol)
{
	QpidConnector *qc = new QpidConnector();
	qc->Create_Dynamic_Queues(-1,symbol);
	QpidMapper.insert(std::pair<std::string,QpidConnector*>(symbol,qc));
}

//Register the symbol for Live Updates
void UpdateFeeds::RequestLiveQuotes()
{
	int j= 0;
	for(int i = 0 ; i<AutomationSymbol.size() ; i++)
	{
		Feed_Connector_List[j]->Connect();
		
		//returns 0 for stock, //return 1 for option //return 2 for future
		//int type = Feed_Connector_List[j]->RegisterSymbol(AutomationSymbol[i]);
		int type = Feed_Connector_List[j]->GetSymbolCategory(AutomationSymbol[i]);

		if(type==1)
		{
			//if its an option then retrieve its call/put type for later reference
			OptionCallPut[AutomationSymbol[i]]=dbconnect->RetrieveOptionCallPut(AutomationSymbol[i],SelectedTables);
			
			//Now register the symbol
			Feed_Connector_List[j]->RegisterSymbol(AutomationSymbol[i]);
		}
		else
		{
			//Now register the symbol
			dbconnect->InserttStockType_MasterList(AutomationSymbol[i]);
			Feed_Connector_List[j]->RegisterSymbol(AutomationSymbol[i]);
		}
		
		if(j==max_socket_limit-1)
		{
			j=0;
		}
		else
		{
			j=j+1;
		}
	}//End for
}

//This method is responsible for creating the sockets
//And then attaching sockets to a silo
void UpdateFeeds::InitializeSiloSocketIntegration()
{
	
	//One Silo attaches to multiple sockets
	int SiloTracker = 0;
	QueueSilo* qsilo = new QueueSilo();
	
	int SockCounter = 1;
	int SiloCounter = 1;
	if(max_socket_limit > AutomationSymbol.size())
	{
		max_socket_limit = AutomationSymbol.size();
	}

	for(int i=0 ; i<max_socket_limit ; i++)
	{		
		Framework::WOPR::FeedConnector* fc= new Framework::WOPR::FeedConnector(); //Create new socket
		fc->set_socket_id(i);
		if(SiloTracker == sockets_to_silo)
		{
			qsilo = new QueueSilo();
			fc->set_silo(qsilo);
			Feed_Connector_List.push_back(fc);
			SiloTracker=1;
			SiloCounter++;
		}
		else
		{
			fc->set_silo(qsilo);
			Feed_Connector_List.push_back(fc);
			SiloTracker++;
		}
		SockCounter = i+1;
	}

	ui.listConsole->addItem("Total Sockets Created : " + QString::number(SockCounter));
	ui.listConsole->addItem("Total Silos Created : " + QString::number(SiloCounter));

}//End method




void UpdateFeeds::InitializeWOPR()
{
	
	//Clear the MasterList..
	//All Other components look at that list for information
	dbconnect->Clear_MasterList();


	//Map the option names to the relevant stock name;
	RetrieveOptionStockNames();     

	//Attach Relevant stocks of the option symbols
	//Uses result of RetrieveOptionStockNames
	AttachStockSymbols(AutomationSymbol); 

	//Initialize the logging library
	InitializeLoggingLibrary();

	//Distributes silos amongst the sockets
	InitializeSiloSocketIntegration();
	
	//Create topics for symbols to be broadcasted.
	SetupNetworkConnectivity();

	//Request Live Quotes
	//This should be at the end of Initialization since Quote Updates will start
	//coming in instantly..
	RequestLiveQuotes();
}//End method


//Add new symbols when the wopr is running
void UpdateFeeds::AddNewSymbolRuntime(std::string symbol,std::string stock,std::string callput)
{
    //Add the relevant stock to the symbol
	//so that it can be retrieved later on
	AddOptionStock(symbol,stock);

	//Contains OptionName and CallPut 
	AddSymbolCallPut(symbol,callput);
	
	//Create a topic for this symbol
	SetupNetworkConnectivity(symbol);

	//----------------------------------------------------
	//Retrieve the symbol and its stock from IQFeed
	//----------------------------------------------------
	Feed_Connector_List[Feed_Connector_List.size()-1]->RegisterSymbol(stock);
	Feed_Connector_List[Feed_Connector_List.size()-1]->RegisterSymbol(symbol);
	

}

std::string UpdateFeeds::GetSymbolOfOption(std::string OptionName)
{
	if(UpdateFeeds::OptionStockMap.find(OptionName) != UpdateFeeds::OptionStockMap.end())
	{
		return UpdateFeeds::OptionStockMap.at(OptionName);
	}
	else
	{
		__debugbreak();
		return "NotPresent";
	}
}

//This method attaches stock symbols for relevant option symbols
void UpdateFeeds::AttachStockSymbols(std::vector<std::string>& Collection)
{
	std::vector<std::string> More_Symbols;

	for(int i = 0 ;i<Collection.size();i++)
	{
		std::string symbol = Collection[i];
		int len = symbol.length();

		if(len >= 7 )
		{
			//Its an option
			//We should also request the stock	
			//Now request the stock
			std::string stockname = GetSymbolOfOption(symbol);
			if(std::find(More_Symbols.begin(),More_Symbols.end(),stockname) == More_Symbols.end())
			{
				More_Symbols.push_back(stockname);
			}
		}
	}//End For


	Collection.insert(Collection.end(),More_Symbols.begin(),More_Symbols.end());
	std::sort(Collection.begin(), Collection.end(), MoveStocksToTop());
}//End Method



//This method adds the symbols selected from all the DB tables
void UpdateFeeds::SelectAutomSymbols()
{
  for(int i=0 ; i<SelectedTables.size() ; i++)
  {
	   std::vector<std::string> temp;
	   temp = dbconnect->ReturnSymbolList(SelectedTables[i]);   
	   AutomationSymbol.insert(AutomationSymbol.end(),temp.begin(),temp.end());
  }
}//end method



void UpdateFeeds::Slot_InitiateConnection()
{
	if(SelectedTables.size()>0)
	{
		InitializeLoggingLibrary();
		LOG4CPLUS_INFO(WOPR_Logger, "WOPR Started");      
		TA_RetCode retCode;
		retCode = TA_Initialize();
		if( retCode == TA_SUCCESS )
		{
			SelectAutomSymbols();
			boost::thread live_feed_thread(boost::bind(&UpdateFeeds::InitializeWOPR,this));     //Start in a different thread
			ShowOptionsForm();
		}
	}
	else
	{
		QMessageBox::information(this,"No Database Lists Selected", "Please select the lists of symbols to automate");

	}
}//End method