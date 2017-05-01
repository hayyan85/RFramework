#include "MySQL-OMEGA.h"
#include <iostream>
#include <intrin.h>  
#include <vector>
#include "External.h"
#include "omega.h"

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


namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;


typedef OMEGA OMEGA_CLASS ;

namespace Framework
{
	namespace NOmega
	{
	
		void DBaseConnection::InitiateDBConnection()
		{
			/* Create a connection */
			driver = get_driver_instance();	
			
			
			con = 	driver->connect(OMEGA_CLASS::GetConfigValue("SQLServerName"), OMEGA_CLASS::GetConfigValue("SQLUserName"), OMEGA_CLASS::GetConfigValue("SQLPassword"));

			/* Connect to the MySQL database */
			con->setSchema("WOPR");

			OptionLookUpTable = "WOPR.masterlist";
	        SymbolTopicMapTable = "WOPR.SymbolTopicMap";     
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

	
		//Retrieves distinct symbols from under
		std::vector<std::string> DBaseConnection::GetDistinctSymbols()
		{
			std::vector<std::string> temp;
			std::string SQL = "SELECT DISTINCT UNDER FROM " + OptionLookUpTable ;
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
			//if(symbol=="--") return;
			std::vector<std::string> temp;
			
			std::string SQL = "SELECT DISTINCT EXPDATE FROM " + OptionLookUpTable + " WHERE `under` = ? ";

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
			
			std::vector<std::string> temp;
			std::string SQL = "SELECT DISTINCT CALLPUT FROM " + OptionLookUpTable +" WHERE `under` = ?  and `expdate` = ?";

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
			std::vector<double> temp;
		
			std::string SQL = "SELECT Strike FROM " + OptionLookUpTable + " WHERE `under` = ?  and `expdate` = ? and `CallPut`= ?";
			
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
			std::sort (temp.begin(), temp.end(), VectorSort());
			return temp;
			
		}


		std::string DBaseConnection::GetFinalSymbol(std::string symbol,std::string date,std::string CallPut,double strike)
		{
			std::string SQL = "SELECT symbol FROM " + OptionLookUpTable +  " WHERE `under` = ?  and `expdate` = ? and `CallPut`= ? and `Strike`= ?" ;
			
			prep_stmt = con->prepareStatement(SQL);	
			prep_stmt->setString(1,symbol);
			prep_stmt->setString(2,date);
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

		std::map<std::string,std::string> DBaseConnection::GetCurrentSymbolMappedTopics()
		{
			std::map<std::string,std::string> temp;
			std::string SQL = "SELECT `Symbol`,`Topic` FROM " + SymbolTopicMapTable +";";

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


		std::map<std::string,std::string> DBaseConnection::GetIQSterlingSymbolMapping()
		{
			std::map<std::string,std::string> temp;
			std::string SQL = "SELECT  `Symbol` , `STISymbol` FROM `WOPRSymbolLists`.`OptionList`;";
			prep_stmt = con->prepareStatement(SQL);	
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string iq_symbol =  res->getString("Symbol");
				std::string sti_symbol =  res->getString("STISymbol");
				temp.insert(std::pair<std::string,std::string>(iq_symbol,sti_symbol));
			}
			return temp;
		}

		std::map<std::string,std::string> DBaseConnection::GetUnderlyingSymbolMapping()
		{
			std::map<std::string,std::string> temp;
			std::string SQL = "SELECT  `Symbol` , `Under` FROM `WOPRSymbolLists`.`OptionList`;";
			prep_stmt = con->prepareStatement(SQL);	
			res = prep_stmt->executeQuery();
			while(res->next()) //If object exists
			{
				std::string symbol =  res->getString("Symbol");
				std::string under =  res->getString("Under");
				temp.insert(std::pair<std::string,std::string>(symbol,under));
			}
			return temp;
		}
	}//End namespace
}//End namespace
