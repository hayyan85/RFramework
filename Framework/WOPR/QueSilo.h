#ifndef QueSilo_Header
#define QueSilo_Header

#include <qdebug.h>
#include <QObject>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <iostream>
#include <string>
#include <deque>
#include "OptionTick.pb.h"
#include "StockTick.pb.h"

namespace Framework
{
	namespace WOPR
	{
		class QueueSilo: public QObject
		{
		Q_OBJECT 
		private:

        //========================OPTIONS================================
	    boost::condition_variable condition_consumer_silo_Options;
		boost::mutex mutex_Silo_Option;
		std::deque<Serializable::OptionTick_ser*> Live_Feed_Silo_Option;
		//==============================================================

		//========================STOCKS================================
		boost::condition_variable condition_consumer_silo_Stocks;
		boost::mutex mutex_Silo_Stock;
		std::deque<Serializable::StockTick_ser*> Live_Feed_Silo_Stock;
		//==============================================================

		public:
		QueueSilo(QObject *parent = 0);		

		//========================OPTIONS================================
		void Add_Feed_To_Option_Silo(Serializable::OptionTick_ser* lfeedTuple);
		void Start_Reading_Option_Feed_Silo();
		//==============================================================

		//========================STOCKS================================
		void Add_Feed_To_Stock_Silo(Serializable::StockTick_ser* lfeedTuple);
		void Start_Reading_Stock_Feed_Silo();
		//==============================================================

		};

	}//end namespace WOPR
}//end namespace Framework
#endif 