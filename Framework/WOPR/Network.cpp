#include "Network.h"
#include "Wopr.h"
#include <intrin.h>
#include <iostream>
#include <sstream> 
#include <boost\spirit\include\karma.hpp>
#include <boost/serialization/map.hpp>
#include <boost/lexical_cast.hpp>
#include "UpdateFeeds.h"
#include "External.h"
#include <QObject>
#include "TDisplay.h"
#include "MySQL-WOPR.h"
#include "OptionFeeds.h"
#include "StockTick.pb.h"
#include "TickStorage.h"

//----------------------------------------------------------
/*Log4cplus Files does not work with UNICODE Preprocessor*/
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include "QString"
//---------------------------------------------------------

using namespace qpid::messaging;
typedef WOPR WOPR_CLASS ;

namespace Framework
{
	namespace WOPR
	{
		//Constructor
		QpidConnector::QpidConnector(QObject *parent /* = 0 */):QObject(parent)
		{
			//Connection to the Table
			connect(this,SIGNAL(QTDisplayOnOptionForm(Serializable::OptionTick_ser)),OptionFeeds::PtrOptionFeedsForm,SLOT(OptionFeeds_ManageTableUpdates(Serializable::OptionTick_ser)),Qt::QueuedConnection);
			connect(this,SIGNAL(QTConsoleMessage(std::string)),OptionFeeds::PtrOptionFeedsForm,SLOT(ConsoleMessage(std::string)),Qt::QueuedConnection);
		}


		//This method creates dynamic queues
		void QpidConnector::Create_Dynamic_Queues(int con,std::string symbol,int FirstRequest)
		{
			try
			{	
				if(FirstRequest==1)
				{
					//Clear the already populated Symbol-Topic Mapper tables;
					UpdateFeeds::ptrUpdateFeedsForm->dbconnect->ClearTopicSymbolMap();
				}

				//std::string queue_name = "Symbol_Topic_" + boost::lexical_cast<std::string>(con);
				//std::string queue_name = std::string("amq.topic/")  + "Symbol_Topic_" + boost::lexical_cast<std::string>(con);
				std::string queue_name = symbol;

				//For a topic Queue
				//std::string sender_string = queue_name +";{create:always, delete:always, node:{type:topic}}";
				std::string sender_string =  queue_name +";{create:always,node:{type:topic}}";
				
				int reconnect_limit = atoi(WOPR_CLASS::GetConfigValue("reconnect_limit").c_str());
				int reconnect_interval_min = atoi(WOPR_CLASS::GetConfigValue("reconnect_interval_min").c_str());
				
				int sender_capacity = atoi(WOPR_CLASS::GetConfigValue("QPID_Sender_Capacity").c_str());
				connection = qpid::messaging::Connection(WOPR_CLASS::GetConfigValue("QpidIP"));

				connection.open();
				connection.setOption("tcp-nodelay", true);
				connection.setOption("reconnect", true);
				connection.setOption("reconnect_limit",reconnect_limit);
				connection.setOption("reconnect_interval_min",reconnect_interval_min);

				Session session  = connection.createSession();
				sender = session.createSender(sender_string) ;
				sender.setCapacity(sender_capacity);
								
				//Store the name of the Dynamic queue you just created
				UpdateFeeds::ptrUpdateFeedsForm->QpidDynamicQueues.push_back(queue_name);
			}
			catch (std::exception &e)
			{	
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"CreateDynamicQueues : " + err );		
			}
		}//End Method

		
		std::string QpidConnector::Convert_Int_To_String(int a)
		{
			std::string _str;
			std::back_insert_iterator<std::string> sink(_str);
			boost::spirit::karma::generate(sink,a);
			return _str;
		}
		
		
		//This method dispatches Options
		void QpidConnector::Dispatach_Options(Serializable::OptionTick_ser& opt_tick,std::string symbol)
		{		
		  	    try
				{	
					QTDisplayOnOptionForm(opt_tick);
					//message.setSubject(symbol);
					message.setContent(opt_tick.SerializeAsString());
					sender.send(message);
				}
				catch (std::exception &e)
				{	
					__debugbreak();
					std::string err =  e.what();
					LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"DispatchOption : " + err );		
				}
		}


		//This method dispatches stocks
		void QpidConnector::Dispatach_Stocks(Serializable::StockTick_ser& opt_tick,std::string symbol)
		{
			try
			{	
				//message.setSubject(symbol);
				message.setContent(opt_tick.SerializeAsString());
				sender.send(message);
			}
			catch (std::exception &e)
			{	
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"DispatchStock : " + err );		
			}
		}

		void QpidConnector::StartRequestResponser()
		{
			boost::thread t(boost::bind(&QpidConnector::RespondToRequests,this));
		}

		//This method responds to requests from Clients
		void QpidConnector::RespondToRequests()
		{
			Message Request_message;
			std::string MessageSubject;
			std::string Qpid_con_ip = WOPR_CLASS::GetConfigValue("QpidIP");
			qpid::messaging::Connection connection_(Qpid_con_ip);
			connection_.open();
			Session session  = connection_.createSession();
			Receiver receiver = session.createReceiver("WOPR-ServiceProvider; {create: always}");
			while(true)
			{
				try
				{
					Request_message = receiver.fetch(qpid::messaging::Duration::FOREVER);
					const Address& address = Request_message.getReplyTo(); 
					Sender sender = session.createSender(address); 
					
					MessageSubject = Request_message.getSubject(); 
					
					if(MessageSubject == "Latest_Option_Request")
					{
						Message Response_message;
						qpid::types::Variant::Map prop = Request_message.getProperties();
						
						qpid::types::Variant::Map::iterator it;
						std::vector<std::string> symbcoll;
						for(it=prop.begin();it!=prop.end();it++ )
						{
							std::string symbol = it->first;
							symbcoll.push_back(symbol);
						}

						std::string rslt = TickStorage().GetOptionClose(symbcoll);
						Response_message.setContent(rslt);
						sender.send(Response_message);
						session.acknowledge();
					}
					else
					{
						//A Request came in without any details;
						DebugBreak();
					}
				}
				catch (std::exception &ex)
				{
					std::string err = ex.what();
				}
			}//End while
		}//End Method



    //Close the Connection
    void QpidConnector::CloseConnection()
	{
		connection.close();
	}
        

	}//end namespace WOPR
}//end namespace Framework