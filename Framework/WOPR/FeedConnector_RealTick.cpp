#include "FeedConnector_RealTick.h"

#include <QObject>
#include <iostream>
#include "boost/spirit/include/qi.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <QTcpSocket>
#include "QStringList"
#include "OptionIndicator.h"
#include "Wopr.h"
#include "UpdateFeeds.h"
#include <windows.h> 
#include <intrin.h>  
#include <ctype.h>
#include "TickStorage.h"
#include "OptionProperties.h"

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

#include <RealTickApi.h>
#include "ApiRecords.h"
#include "Prompter.h"
#include <sstream>
#include "ExampleHelpers.h"



using namespace realtick_api;
using namespace boost::posix_time;
using namespace boost::gregorian;
namespace qi = boost::spirit::qi;


typedef WOPR WOPR_CLASS;

namespace Framework
{
	namespace WOPR
	{
		FeedConnector_RTick::FeedConnector_RTick(QObject* parent /* = 0 */):RTClientAdaptor(  nullptr, nullptr, nullptr, "TA_SRV", "LIVEQUOTE" ),QObject(parent)
		{

		}


		void FeedConnector_RTick::Startup()
		{
			RTClientAdaptor::Startup();
		}

		void FeedConnector_RTick::RegisterSymbol(std::string symbol)
		{
			
			std::ostringstream bld;
			std::string tql;
			bld << "LIVEQUOTE;1003;1003='" << symbol << "'";
			tql = bld.str();
			RTClientAdaptor::Connect();
			if( !RTEvent::Wait(5000, EvtConnect) )
			{
				cout << "NO CONNECTION" << endl;
				return;
			}

			RTClientAdaptor::Advise( tql.c_str(), "TAL4");
			RTClientAdaptor::Request( tql.c_str(), "TAL4", false);

			if( !RTEvent::Wait(500000, EvtDone) )
			{

			}
		}//End Method
	 


		#pragma region OverRiddenMethods
		void FeedConnector_RTick::OnInitAck(bool bStatus) 
		{
			if( bStatus )
				EvtConnect.Set();
		}

		void FeedConnector_RTick::OnExecAck(const char* szItem, bool bStatus)
		{

		}

		void FeedConnector_RTick::OnOtherAck(const char* szItem, bool bStatus)
		{

		}
	
		void FeedConnector_RTick::OnUpdate(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength)
		{

		}

		void FeedConnector_RTick::ProcessOptionTick(const void* pData )
		{
			RTDataReader rd( pData );
			LivequoteRecord rec(rd);
		}

		void FeedConnector_RTick::ProcessStockTick(const void* pData )
		{
			RTDataReader rd( pData );
			LivequoteRecord rec(rd);
		}
		#pragma endregion 



		//Categorize the tick
		void FeedConnector_RTick::CategorizeTick(LivequoteRecord& tick)
		{

		}

		
	}//end namespace
}//End namepsace