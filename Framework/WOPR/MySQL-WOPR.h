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

class AddOptionSymbol;

namespace Framework
{
	namespace WOPR
	{
		class DBaseConnection
		{
			private:
				sql::Driver *driver;
				sql::Statement *stmt;
				sql::ResultSet *res;
				sql::Connection *con;
				sql::PreparedStatement *prep_stmt;
				std::string OptionLookUpTable;
				std::string SymbolTopicMapTable;
				void InserttOptionType_MasterList(std::string TableName , std::string symbol);
			public:				
				void Clear_MasterList();
				void InitiateDBConnection();
				void InserttStockType_MasterList(std::string symbol);
				int ConvertStringToInt(std::string str);
				std::vector<std::string> ReturnSymbolList(std::string tablename); 
				std::vector<std::string> RetrieveAvailableLists(); 
				void InsertTopicSymbolMap(std::string symb,std::string topic);
				void InsertTopicSymbolCollection(std::vector<std::string>& collection);
				void ClearTopicSymbolMap();
				std::string RetrieveOptionCallPut(std::string option_symbol,std::vector<std::string>& TablesSelected);
				std::map<std::string,std::string> RetrieveOptionStockNames(std::vector<std::string>& TablesSelected);
				void AddRuntimeOption(AddOptionSymbol* opt);
				~DBaseConnection();

		};

	}//end namespace ExecutionEngine
}//end namespace Framework
#endif 