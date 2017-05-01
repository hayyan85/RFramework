#include "MySQL-Eclipse.h"
#include <iostream>
#include <intrin.h>  
#include <vector>


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

/* Boost Spirit */
#include <boost/algorithm/string.hpp>
#include "boost/spirit/include/qi.hpp"
#include <boost\spirit\include\karma.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include "Eclipse.h"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;


namespace Framework
{
	namespace NEclipse
	{
	
		void DBaseConnection::InitiateDBConnection()
		{
			/* Create a connection */
			driver = get_driver_instance();	
			
			
			//Retrieve details from the config file
			con = 	driver->connect(::Eclipse::GetConfigValue("SQLServerName"), ::Eclipse::GetConfigValue("SQLUserName"), ::Eclipse::GetConfigValue("SQLPassword"));

			/* Connect to the MySQL database */
			con->setSchema("WOPR");
		}
		
		void DBaseConnection::CloseDBConnection()
		{
			delete res;
			//delete stmt;
			delete prep_stmt;
			con->close();
			delete con;
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

		std::map<std::string,std::string> DBaseConnection::GetCurrentSymbolMappedTopics()
		{
			std::map<std::string,std::string> temp;
			std::string SQL = "SELECT	`SymbolTopicMap`.`Symbol`,	`SymbolTopicMap`.`Topic` FROM `WOPR`.`SymbolTopicMap`;";
			prep_stmt = con->prepareStatement(SQL);	
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string symbol =  res->getString("Symbol");
				std::string topic =  res->getString("Topic");
				temp.insert(std::pair<std::string,std::string>(symbol,topic));
			}
			return temp;
		}

		//-----------------------------------------

		//Retrieves distinct symbols from under
		std::vector<std::string> DBaseConnection::GetDistinctSymbols()
		{
			std::vector<std::string> temp;
			//std::string SQL = "SELECT DISTINCT UNDER FROM WOPRSymbolLists.OptionList;";
			std::string SQL = "SELECT DISTINCT UNDER FROM WOPR.masterlist;";
			prep_stmt = con->prepareStatement(SQL);	
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string symbol =  res->getString("under");
				temp.push_back(symbol);
			}
			return temp;
		}

		//Get Relevant Expiration dates of a symbol
		std::vector<std::string> DBaseConnection::GetRelevantExpirationDates(std::string symbol)
		{
			std::vector<std::string> temp;
			//std::string SQL = "SELECT DISTINCT EXPDATE FROM WOPRSymbolLists.OptionList WHERE `under` = ? ";
			std::string SQL = "SELECT DISTINCT EXPDATE FROM WOPR.masterlist WHERE `under` = ? ";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("expdate");
				temp.push_back(reslt);
			}
			return temp;
		}

		std::vector<std::string> DBaseConnection::GetCallAndPuts(std::string symbol,std::string ExpDate)
		{
			//if(symbol=="--" || ExpDate=="--") return;
			std::vector<std::string> temp;
			//std::string SQL = "SELECT DISTINCT CALLPUT FROM WOPRSymbolLists.OptionList WHERE `under` = ?  and `expdate` = ?";
			std::string SQL = "SELECT DISTINCT CALLPUT FROM WOPR.masterlist WHERE `under` = ?  and `expdate` = ?";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setDateTime(2,ExpDate);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("callput");
				temp.push_back(reslt);
			}
			return temp;
		}

		std::vector<double> DBaseConnection::GetStrikePrice(std::string symbol,std::string date,std::string CallPut)
		{
			//if(symbol=="--" || date=="--" || CallPut=="--") return;
			std::vector<double> temp;
			//std::string SQL = "SELECT Strike FROM WOPRSymbolLists.OptionList WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?";
			std::string SQL = "SELECT Strike FROM WOPR.masterlist WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setDateTime(2,date);
			prep_stmt->setString(3,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				double reslt =  res->getDouble("Strike");
				temp.push_back(reslt);
			}
			return temp;
			std::sort (temp.begin(), temp.end(), VectorSort());
		}


		std::string DBaseConnection::GetFinalSymbol(std::string symbol,std::string date,std::string CallPut,double strike)
		{
			//std::string SQL = "SELECT Strike FROM WOPRSymbolLists.OptionList WHERE `under` = ?  and `expdate` = ? and `CallPut`= ? and `Strike`= ?" ;
			std::string SQL = "SELECT Strike FROM WOPR.masterlist WHERE `under` = ?  and `expdate` = ? and `CallPut`= ? and `Strike`= ?" ;
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setDateTime(2,date);
			prep_stmt->setString(3,CallPut);
			prep_stmt->setDouble(4,strike);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("symbol");
				return reslt;
			}
			return "Empty";
		}


		std::vector<std::string> DBaseConnection::GetFinalSymbol(std::string symbol,std::string date,std::string CallPut)
		{
			std::vector<std::string> temp;
			//std::string SQL = "SELECT symbol FROM WOPRSymbolLists.OptionList WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?" ;
			std::string SQL = "SELECT symbol FROM WOPR.masterlist WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?" ;
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setDateTime(2,date);
			prep_stmt->setString(3,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("symbol");
				temp.push_back(reslt);
			}
			return temp;
		}

		std::vector<double> DBaseConnection::GetStrikes(std::string symbol,std::string date,std::string CallPut)
		{
			std::vector<double> temp;
			//std::string SQL = "SELECT strike FROM WOPRSymbolLists.OptionList WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?" ;
			std::string SQL = "SELECT strike FROM WOPR.masterlist WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?" ;
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setDateTime(2,date);
			prep_stmt->setString(3,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				double reslt =  res->getDouble("strike");
				temp.push_back(reslt);
			}
			std::sort (temp.begin(), temp.end(), VectorSort());
			return temp;
		}

		std::vector<std::string> DBaseConnection::GetAllOptions()
		{
			try
			{
				std::vector<std::string> temp;
				std::string SQL = "SELECT Symbol FROM WOPR.masterlist WHERE `Instrument` = ?" ;
				prep_stmt = con->prepareStatement(SQL);	
				prep_stmt->setString(1,"OPTION");
				res = prep_stmt->executeQuery();
				while(res->next()) //If object exists
				{
					std::string  reslt =  res->getString("Symbol");
					temp.push_back(reslt);
				}
				return temp;
			}
			catch(std::exception &ex)
			{
				std::string e = ex.what();
			}
		}//End Method


		//Get the underline symbols
		std::map<std::string,std::string> DBaseConnection::GetUnderlineSymbols()
		{
			try
			{
				std::map<std::string,std::string> symbUnder;
				std::string SQL = "SELECT Symbol,Under FROM WOPR.masterlist WHERE `Instrument` = ?" ;
				prep_stmt = con->prepareStatement(SQL);	
				prep_stmt->setString(1,"OPTION");
				res = prep_stmt->executeQuery();
				while(res->next()) //If object exists
				{
					std::string  symbol =  res->getString("Symbol");
					std::string  underline =  res->getString("Under");
					symbUnder[symbol] = underline;
				}
				return symbUnder;
			}
			catch(std::exception &ex)
			{
				std::string e = ex.what();
			}
		}//End Method


		//Get symbols based on Call/Put
		std::vector<std::string> DBaseConnection::GetSymbolsOnCallPutCriteria(std::string symbol,std::string CallPut)
		{
			std::vector<std::string> temp;
			std::string SQL = "SELECT symbol FROM WOPR.masterlist WHERE `under` = ?  and `CallPut`= ?" ;
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setString(2,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("symbol");
				temp.push_back(reslt);
			}
			return temp;
		}

		std::vector<double> DBaseConnection::GetStrikesOnCallPutCriteria(std::string symbol,std::string CallPut)
		{
			std::vector<double> temp;
			std::string SQL = "SELECT strike FROM WOPR.masterlist WHERE `under` = ?  and `CallPut`= ?" ;
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setString(2,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				double reslt =  res->getDouble("strike");
				temp.push_back(reslt);
			}
			std::sort (temp.begin(), temp.end(), VectorSort());
			return temp;
		}

		std::vector<std::string> DBaseConnection::GetCallAndPutsSymbolsCriteria(std::string symbol)
		{
			std::vector<std::string> temp;
			std::string SQL = "SELECT DISTINCT CALLPUT FROM WOPR.masterlist WHERE `under` = ?";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("callput");
				temp.push_back(reslt);
			}
			return temp;
		}


		std::vector<std::string> DBaseConnection::GetRelevantExpirationDatesCriteria(std::string symbol , std::string CallPut)
		{
			std::vector<std::string> temp;
			std::string SQL = "SELECT DISTINCT EXPDATE FROM WOPR.masterlist WHERE `under` = ? and `CallPut`= ?";
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setString(2,CallPut);
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string reslt =  res->getString("expdate");
				temp.push_back(reslt);
			}
			return temp;
		}

	}//End namespace
}//End namespace
