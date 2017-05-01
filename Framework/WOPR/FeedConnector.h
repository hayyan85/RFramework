#ifndef Feed_Connector_Header
#define Feed_Connector_Header

#include <qdebug.h>
#include <QObject>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <QTcpSocket>
#include "QueSilo.h"
#include <map>
#include "OptionIndicator.h"
#include <winsock.h>
#include "TickStorage.h"
#include "LastVolatility.h"
#include "OptionProperties.h"

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
			IMPLEMENT_SET_METHOD( type , name );	\
			IMPLEMENT_GET_METHOD( type , name );

namespace Framework
{
	namespace WOPR
	{
		

		class FeedConnector : public QObject
		{
			Q_OBJECT 
			
			IMPLEMENT_SET_GET_METHOD(Framework::WOPR::QueueSilo*,silo);
			IMPLEMENT_SET_GET_METHOD(int,socket_id);

		public:
			FeedConnector(QObject* parent = 0);
			void Connect();
			int RegisterSymbol(std::string symbol);
		    void StartReceivingQuotes();
			TickStorage ReturnTickStorage();
			int GetSymbolCategory(std::string symbol);

		private:
			enum FMessage{DivPercentage,DivAmount,DivDate};
			std::map<std::string,Framework::WOPR::LastVolatility> LastVolTracker;
			std::map<std::string,std::map<FMessage,std::string>> FundamentalMsgTracker;  
			

			OptionIndicator oic;
			OptionProperties ops;

			boost::mutex mutex_socket;
			SOCKET clntSocket;
			WSADATA wsadata;
			SOCKADDR_IN target;
			TickStorage tick_bank;

			float RiskFreeRate;
		    std::string CallPut;
			bool connected;

			static boost::mutex mutex_stock_update;
			static std::map<std::string,float> StockUpdates;
			static void   UpdateStockClose(std::string symbol,float close);
			static float RetrieveStockClose(std::string option_symbol_name);
			static std::string GetSymbolOfOption(std::string OptionName);

			std::string RetrieveFundMessage(std::string symbol , FMessage msg);

			boost::posix_time::ptime ReturnInTimeFormat_mseconds(const std::string& Dtime);
			std::string CalculateTickTimeDifference(std::string& tickTime);
			std::string CalculateExpirationTimeLeft(const std::string& timeStamp , const std::string& expirDate);
			boost::posix_time::ptime Date_PtimeConverter(const std::string& Dtime);
			float ConvertStringToFloat(std::string& str);
			
			bool RunImpliedVolatilityMethod(const std::string symbol,float bid,float ask);
			void UpdateLastVolTracker(const std::string symbol,float& bid_iv,float& ask_iv,float& mp_iv);
			
			void CategorizeTick(std::string& tick);
			void ProcessOptionTick(std::string& tick,std::string& MsgType);
			void ProcessStockTick(std::string& tick_msg);
			void ProcessFundMessage(std::string& tick_msg);
		    void SocketSender(std::string dta);
		    void ReceiveTicks();	
			float trunc(float d);
			bool FloatCompareOptions(float a , float b);
		};
	}//end namespace WOPR
}//end namespace Framework
#endif 