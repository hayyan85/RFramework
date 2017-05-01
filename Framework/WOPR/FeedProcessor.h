#ifndef Feed_Processor_Header
#define Feed_Processor_Header

#include "QObject"
#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <boost/thread/mutex.hpp>
#include "OptionTick.pb.h"
#include "StockTick.pb.h"

namespace Framework
{
	namespace WOPR
	{
		class FeedProcessor:public QObject
		{
		   Q_OBJECT 
		public:
		   void ProcessOptionTick(Serializable::OptionTick_ser* otick);
		   void ProcessStockTick(Serializable::StockTick_ser* otick);
		};

	}//end namespace WOPR
}//end namespace Framework
#endif 