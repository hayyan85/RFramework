#ifndef Feed_Connector_RTick_Header
#define Feed_Connector_RTick_Header

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
#include <RealTickApi.h>

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


using namespace realtick_api;

namespace Framework
{
	namespace WOPR
	{
		class FeedConnector_RTick : public realtick_api::RTClientAdaptor,public QObject
		{
			Q_OBJECT 

			IMPLEMENT_SET_GET_METHOD(Framework::WOPR::QueueSilo*,silo);
			IMPLEMENT_SET_GET_METHOD(int,socket_id);
		
		private:
			RTEvent EvtConnect;
			RTEvent EvtDone;	
			static const int MaxToDisplay = 20;
			int NumDisplayed;
			int NumIgnored;

			void CategorizeTick(LivequoteRecord& tick);
			void ProcessOptionTick(const void* pData );
			void ProcessStockTick(const void* pData );

		public:
			FeedConnector_RTick(QObject* parent = 0);
			void RegisterSymbol(std::string symbol);
			void Startup();
			//---RealTickImplementations---------------
			virtual void OnInitAck(bool bStatus);
			virtual void OnExecAck(const char* szItem, bool bStatus);
			virtual void OnOtherAck(const char* szItem, bool bStatus); 
			virtual void OnUpdate(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength); 
			
			
		};
	}//end namespace WOPR
}//end namespace Framework
#endif 