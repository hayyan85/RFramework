#ifndef MySQL_WOPR_Header
#define MySQL_WOPR_Header

#include <iostream>
#include <string>
#include <vector>
#include <boost/optional.hpp>

/* MySQL Connector/C++ specific headers */
#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include <map>

namespace Framework
{
	namespace NOmega
	{
		class DBaseConnection
		{
			private:
				sql::Driver *driver;
				sql::Statement *stmt;
				sql::ResultSet *res;
				sql::Connection *con;
				sql::PreparedStatement *prep_stmt;
				std::string SymbolTopicMapTable;
				std::string OptionLookUpTable;
		
		public:				
				
				void InitiateDBConnection();
				int ConvertStringToInt(std::string str);

				std::map<std::string,std::string> GetUnderlyingSymbolMapping();
				std::map<std::string,std::string> GetCurrentSymbolMappedTopics();
				std::map<std::string,std::string> GetIQSterlingSymbolMapping();

				std::vector<std::string> GetDistinctSymbols();
				std::vector<std::string> GetRelevantExpirationDates(std::string symbol);
				std::vector<std::string> GetCallAndPuts(std::string symbol,std::string ExpDate);
				std::vector<double> GetStrikePrice(std::string symbol,std::string date,std::string CallPut);
				std::string GetFinalSymbol(std::string symbol,std::string date,std::string CallPut,double strike);
				
				~DBaseConnection();

		};

		class VectorSort 
		{
		public:
			bool operator() (int i,int j) { return (i<j);}
		};

	}//end namespace ExecutionEngine
}//end namespace Framework
#endif 