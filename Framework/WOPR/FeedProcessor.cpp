#ifndef Feed_Processor_Header
#include "FeedProcessor.h"
#endif

#include "OptionTick.pb.h"
#include <boost/thread/mutex.hpp>
#include <iostream>
#include <intrin.h>  
#include "FeedConnector.h"
#include "Network.h"
#include "UpdateFeeds.h"

#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "QStringList"

/*Log4cplus Files does not work with UNICODE Preprocessor*/
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>

using namespace boost::posix_time;
using namespace boost::gregorian;

namespace Framework
{
	namespace WOPR
	{
		
		void FeedProcessor::ProcessOptionTick(Serializable::OptionTick_ser* otick)
		{
			//UpdateFeeds::QpidMapper[otick->symbol()]->Dispatach_Options(*otick,otick->symbol());
			UpdateFeeds::QpidMapper["WOPR_BROADCAST"]->Dispatach_Options(*otick,otick->symbol());
		}

		void FeedProcessor::ProcessStockTick(Serializable::StockTick_ser* otick)
		{
			//UpdateFeeds::QpidMapper[otick->symbol()]->Dispatach_Stocks(*otick,otick->symbol());
			UpdateFeeds::QpidMapper["WOPR_BROADCAST"]->Dispatach_Stocks(*otick,otick->symbol());
		}
	}//end namespace WOPR
}//end namespace Framework
