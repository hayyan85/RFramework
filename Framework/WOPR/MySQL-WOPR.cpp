#include "MySQL-WOPR.h"
#include <iostream>
#include <intrin.h>  
#include <vector>
#include "Wopr.h"

/*Boost Serialization*/
#include <sstream>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 

//Boost UUID Generator
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>    
#include <boost\spirit\include\karma.hpp>

/* MySQL Connector/C++ specific headers */
#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include "UpdateFeeds.h"


/* Boost Spirit */
#include <boost/algorithm/string.hpp>
#include "boost/spirit/include/qi.hpp"
#include <boost\spirit\include\karma.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>

/*Log4cplus Files does not work with UNICODE Preprocessor*/
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include "External.h"

#include "AddOptionSymbol.h"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;


typedef WOPR WOPR_CLASS ;

namespace Framework
{
	namespace WOPR
	{
	
		void DBaseConnection::InitiateDBConnection()
		{
			try
			{
				/* Create a connection */
				driver = get_driver_instance();	

				//con = 	driver->connect("hoyne", "hrafiq", "5Nss6cVu0Qi3AHn6rG");
				con = 	driver->connect(WOPR_CLASS::GetConfigValue("SQLServerName"), WOPR_CLASS::GetConfigValue("SQLUserName"), WOPR_CLASS::GetConfigValue("SQLPassword"));

				/* Connect to the MySQL database */
				con->setSchema("WOPR");	

				//----------------------------------------------------------------------------------------------------
				//----------------------------------------TABLE SELECTION---------------------------------------------
				//----------------------------------------------------------------------------------------------------
				SymbolTopicMapTable = "WOPR.SymbolTopicMap"; //This where the mapping of symbol to topics are dumped
				//----------------------------------------------------------------------------------------------------
                //----------------------------------------------------------------------------------------------------
			}
			catch (std::exception &e)
			{	
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"SQLConnection : " + err );		
			}
		}
		
		DBaseConnection::~DBaseConnection()
		{
		/*	delete stmt;
			delete res;
			delete con;
			delete prep_stmt;*/
		}

		int DBaseConnection::ConvertStringToInt(std::string str)
		{
			int val;
			std::string::iterator begin ;  std::string::iterator end ;
			begin = str.begin(); end = str.end();

			//Convert string to float using boost::spirit
			boost::spirit::qi::parse(begin, end, boost::spirit::int_, val);
			return val;
		}



		//Retrieves the names of symbols from each table that has been marked fro automation
		std::vector<std::string> DBaseConnection::ReturnSymbolList(std::string tablename)
		{
			std::vector<std::string> SymbolList;
			std::string SQL = "SELECT `" +tablename+ "`.`Symbol` FROM `WOPRSymbolLists`.`"+ tablename+"`;";
			stmt = con->createStatement();
			res = stmt->executeQuery(SQL);
			while(res->next()) //If object exists
			{
				std::string symbol =  res->getString("Symbol");		
				SymbolList.push_back(symbol);
			}
			return SymbolList;
		}//end method


		//Retrieves all the tables that could be automated
		std::vector<std::string> DBaseConnection::RetrieveAvailableLists()
		{
			std::vector<std::string> tableList;
			std::string SQL = "show tables in WOPRSymbolLists";
			stmt = con->createStatement();
			res = stmt->executeQuery(SQL);
			while(res->next()) //If object exists
			{
				std::string symbol =  res->getString(1);		
				tableList.push_back(symbol);
			}
			return tableList;
		}//End Method


		void DBaseConnection::InsertTopicSymbolMap(std::string symb,std::string topic)
		{
			try
			{
				std::string SQL = "INSERT INTO " + SymbolTopicMapTable  +"(`Symbol`,`Topic`)VALUES(?,?);";
				prep_stmt = con->prepareStatement(SQL);
				prep_stmt->setString(1,symb);
				prep_stmt->setString(2,topic);
				prep_stmt->execute();	
			}
			catch(std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"InsertTopicSymbolMap : " + err );		
			}
		}


		void DBaseConnection::InsertTopicSymbolCollection(std::vector<std::string>& collection)
		{
			//std::string SQL = "INSERT INTO " + SymbolTopicMapTable  +"(`Symbol`,`Topic`)VALUES(?,?);";
			std::string SQL = "INSERT INTO " + SymbolTopicMapTable  +"(`Symbol`,`Topic`)VALUES";
			for(int i=0;i<collection.size();i++)
			{
				if(i==0)
				{
					SQL = SQL + "(\"" + collection[i]+"\",\"--\")";
				}
				else
				{
					SQL = SQL + ",(\"" + collection[i]+"\",\"--\")";
				}
			}

			//Now insert it in the database
			stmt = con->createStatement();
			try
			{
				SQL = SQL + ";";
				stmt->execute(SQL);
			}
			catch(std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"ClearTopicSymbolMap : " + err );		
			}
		}

		void DBaseConnection::ClearTopicSymbolMap()
		{
			try
			{
				std::string SQL = "TRUNCATE TABLE " + SymbolTopicMapTable + ";" ;
				stmt = con->createStatement();
				stmt->execute(SQL);
			}
			catch(std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"ClearTopicSymbolMap : " + err );		
			}
		}


		void DBaseConnection::Clear_MasterList()
		{
			try
			{
				std::string SQL = "TRUNCATE TABLE WOPR.masterlist ";
				stmt = con->createStatement();
				stmt->execute(SQL);
			}
			catch(std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Clear Symbol Master List : " + err );		
			}
		}

		void DBaseConnection::InserttOptionType_MasterList(std::string TableName , std::string symbol)
		{
			
			std::string SQL = "SELECT * FROM WOPRSymbolLists." + TableName + " WHERE `SYMBOL` = ? ";
			
			std::string under_,callput_,ExpDate_,Symbol_,StiSymbol_,Pkey_,Instrument_;
			double strike_;

			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			res = prep_stmt->executeQuery();

		    while(res->next()) //If object exists
			{
				under_ =  res->getString("Under");
				callput_ = res->getString("CallPut");
				strike_ = res->getDouble("Strike");
				ExpDate_ = res->getString("ExpDate");
				Symbol_ = res->getString("Symbol");
				StiSymbol_ = res->getString("STIsymbol");
				Pkey_ = boost::uuids::to_string(boost::uuids::random_generator()());
				Instrument_ = "OPTION" ;
			}

			try
			{
				std::string InsertSQL = "INSERT INTO `WOPR`.`masterlist` (`Under`,`CallPut`,`Strike`,`ExpDate`,`Symbol`,`STIsymbol`,`PKey`,	`Instrument`) VALUES (?,?,?,?,?,?,?,?)";
				prep_stmt = con->prepareStatement(InsertSQL);	
				prep_stmt->setString(1,under_);
				prep_stmt->setString(2,callput_);
				prep_stmt->setDouble(3,strike_);
				prep_stmt->setString(4,ExpDate_);
				prep_stmt->setString(5,Symbol_);
				prep_stmt->setString(6,StiSymbol_);
				prep_stmt->setString(7,Pkey_);
				prep_stmt->setString(8,Instrument_);
				prep_stmt->execute();
			}
			catch(std::exception& e)
			{
				std::string str = e.what();
			}
			
		}//End Method


		void DBaseConnection::InserttStockType_MasterList(std::string symbol)
		{
			std::string under_,callput_,ExpDate_,Symbol_,StiSymbol_,Pkey_,Instrument_ ="-";

			//Check if the symbol is already in there ?
			//-----------------------------------------------------------------------------
			std::string SQL = "SELECT Symbol FROM WOPR.masterlist WHERE `SYMBOL` = ? ";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				return ; //Its already in there we do not need duplicate entries
			}
			//-----------------------------------------------------------------------------
			
			double strike_=0;
			Instrument_ = "STOCK";
			Symbol_ = symbol;
			Pkey_ = boost::uuids::to_string(boost::uuids::random_generator()());
			try
			{
				std::string InsertSQL = "INSERT INTO WOPR.masterlist (`Under`,`CallPut`,`Strike`,`ExpDate`,`Symbol`,`STIsymbol`,`PKey`,	`Instrument`) VALUES (?,?,?,?,?,?,?,?)";
				prep_stmt = con->prepareStatement(InsertSQL);	
				prep_stmt->setString(1,under_);
				prep_stmt->setString(2,callput_);
				prep_stmt->setDouble(3,strike_);
				prep_stmt->setString(4,ExpDate_);
				prep_stmt->setString(5,Symbol_);
				prep_stmt->setString(6,StiSymbol_);
				prep_stmt->setString(7,Pkey_);
				prep_stmt->setString(8,Instrument_);
				prep_stmt->execute();
			}
			catch(std::exception& e)
			{
				std::string str = e.what();
			}
		}//End Method


		std::string DBaseConnection::RetrieveOptionCallPut(std::string option_symbol , std::vector<std::string>& TablesSelected)
		{
			for(int i = 0 ; i<TablesSelected.size() ; i++)
			{
				std::string SQL = "SELECT CALLPUT FROM WOPRSymbolLists." + TablesSelected[i] + " WHERE `SYMBOL` = ? ";

				prep_stmt = con->prepareStatement(SQL);	
				prep_stmt->setString(1,option_symbol);
				res = prep_stmt->executeQuery();
				while(res->next()) //If object exists
				{
					std::string reslt =  res->getString("CALLPUT");
					InserttOptionType_MasterList(TablesSelected[i],option_symbol);
					return reslt;
				}
			}
		}//End MEthod;


		//This method returns the  option stock names
		std::map<std::string,std::string> DBaseConnection::RetrieveOptionStockNames(std::vector<std::string>& TablesSelected)
		{
			std::map<std::string,std::string> temp;
			std::vector<std::string> stock_symbols;
			for(int i = 0 ; i<TablesSelected.size() ; i++)
			{
				std::string SQL = "SELECT UNDER,SYMBOL FROM WOPRSymbolLists." + TablesSelected[i] ;
				prep_stmt = con->prepareStatement(SQL);	
				res = prep_stmt->executeQuery();
				while(res->next()) //If object exists
				{
					std::string under =  res->getString("under");
					std::string symbol =  res->getString("symbol");
					temp.insert(std::pair<std::string,std::string>(symbol,under));
					
					if(std::find(stock_symbols.begin(),stock_symbols.end(),under) != stock_symbols.end())
					{
						stock_symbols.push_back(under);
					}
				}
			}

			for(int i=0 ; i<stock_symbols.size() ; i++)
			{
				InserttStockType_MasterList(stock_symbols[i]);
			}
			return temp;
		}//end method


		void DBaseConnection::AddRuntimeOption(AddOptionSymbol* opt)
		{
			std::string SQL = "INSERT INTO `WOPRSymbolLists`.`OptionList` (`Under`, `CallPut`, `Strike`,`ExpDate`,`Symbol`,	`STIsymbol`)	VALUES"
				"(?,?,?,?,?,?);";

			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,opt->get_under());
			prep_stmt->setString(2,opt->get_callput());
			prep_stmt->setDouble(3,opt->get_strike());
			prep_stmt->setString(4,opt->get_expdate());
			prep_stmt->setString(5,opt->get_symbol());
			prep_stmt->setString(6,opt->get_stisymbol());
			res = prep_stmt->executeQuery();
		}

	}//End namespace
}//End namespace
