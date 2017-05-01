#include "Network.h"
#include "Eclipse.h"
#include <intrin.h>
#include <iostream>
#include <sstream> 
#include <boost\spirit\include\karma.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include "External.h"
#include "Eclipse.h"

#include <map>
#include <vector>
#include <qpid/messaging/Address.h>
#include <vector>
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp> 

#include "VolatilityGraph.h"
#include "OptionTick.pb.h"
#include "OptionScanner.h"
#include "ExpGraph.h"

using namespace qpid::messaging;

namespace Framework
{
	namespace NEclipse
	{
		QpidSubscriber* QpidSubscriber::QpidSingleton=NULL;

		
		QpidSubscriber::~QpidSubscriber()
		{		}

		//Constructor
		QpidSubscriber::QpidSubscriber(QObject *parent /* = 0 */):QObject(parent)
		{
			ConnectedToWOPRBroadcast = false;
			//Attach a signal-slot for QPID Error Messages
			connect(this,SIGNAL(QTErrorDump(QString)),Eclipse::EclipsePtr,SLOT(ErrorDisplay(QString)),Qt::AutoConnection);
		}

		QpidSubscriber* QpidSubscriber::GetQpidInstance()
		{
			if(QpidSingleton==NULL)
			{
				QpidSingleton = new QpidSubscriber();
				return QpidSingleton;
			}
			return QpidSingleton;
		}

		void QpidSubscriber::SubscribeToOptionTopic(std::string symbol , std::string topicName , QObject* ptr)
		{
			QpidSingleton->AddOptionSubscriber(ptr);
		}

		void QpidSubscriber::ConnectToWOPRBroadcast()
		{
			if(ConnectedToWOPRBroadcast)
			{
				return;
			}

			std::string conn_ip ;
			conn_ip = Eclipse::GetConfigValue("QpidBrokerAddress");
			connection = Connection(conn_ip);
			connection.open();
			
			//##########################################################################################
            //###############################CONNECTION OPTIONS#########################################
			//##########################################################################################
			int reconnect_limit = atoi(Eclipse::GetConfigValue("reconnect_limit").c_str());
			int reconnect_interval_min = atoi(Eclipse::GetConfigValue("reconnect_interval_min").c_str());
			connection.setOption("reconnect", true);
			connection.setOption("reconnect_limit",reconnect_limit);
			connection.setOption("reconnect_interval_min",reconnect_interval_min);
			//##########################################################################################

			Session session  = connection.createSession();
			Receiver receiver = session.createReceiver("WOPR_BROADCAST");
			receiver.setCapacity(1500);
			boost::thread t(boost::bind(&QpidSubscriber::ReceiveFromWOPRBroadCast,this,receiver));
			ConnectedToWOPRBroadcast = true;
		}


		//Send to all the subscribed forms
		//Now the forms are responsible for filtering the data
		void QpidSubscriber::ReceiveFromWOPRBroadCast(qpid::messaging::Receiver receiver)
		{
				Message msg;
			    Serializable::OptionTick_ser ot;
				while(true)
				{
					try
					{
						msg = receiver.fetch(Duration::FOREVER);
						std::string cont = msg.getContent();
						//De-serialize the message and send it via signal
						ot.ParseFromString(cont);
						QTUpdateOptionTable(ot);
					}
					catch (std::exception &ex)
					{
						std::string err = ex.what();
						QTErrorDump(err.c_str());
					}
				}//End while
				connection.close();    //Close the main connection
		}//End Method


		//void QpidSubscriber::UnSubscribeFromTopic(std::string symbol,VolatilityGraph* ptr)
		void QpidSubscriber::UnSubscribeFromTopic(std::string symbol,QObject* ptr)
		{
		}

		//void QpidSubscriber::AddOptionSubscriber(VolatilityGraph* equity_ptr)
		void QpidSubscriber::AddOptionSubscriber(QObject* form_ptr)
		{
			connect(this,SIGNAL(QTUpdateOptionTable(Serializable::OptionTick_ser)),form_ptr,SLOT(ManageTableUpdates(Serializable::OptionTick_ser)),Qt::QueuedConnection);
			connect(this,SIGNAL(QTRemoveSymbol(std::string)),form_ptr,SLOT(RemoveSymbolFromTable(std::string)),Qt::AutoConnection);
		}

		//void QpidSubscriber::RemoveSignal(VolatilityGraph* equity_ptr,std::string symbol)
		void QpidSubscriber::RemoveSignal(QObject* form_ptr,std::string symbol)
		{
			QTRemoveSymbol(symbol); //Remove the symbol from the main table (Not necessary here)
			QObject::disconnect(form_ptr,SLOT(RemoveSymbolFromTable(std::string)));
		}
		
		
		
		//Sends a request to WOPR and waits for a response from it
		Serializable::Option_collection_ser QpidSubscriber::WOPRQuery_OptionUpdates(std::vector<std::string> option_collection)
		{
			std::string conn_ip ;
			conn_ip = Eclipse::GetConfigValue("QpidBrokerAddress");
			Connection con_(conn_ip);
			con_.open();
			Session sess_  = con_.createSession();
			Sender sender_ = sess_.createSender("WOPR-ServiceProvider");

			std::string QueueName_ = "#response-queue" + boost::uuids::to_string(boost::uuids::random_generator()()) + "; {create:always, delete:always}";
			qpid::messaging::Address responseQueue(QueueName_);
			Receiver receiver = sess_.createReceiver(responseQueue);
			Message request_;
			request_.setReplyTo(responseQueue);
			request_.setSubject("Latest_Option_Request");

			for(int i = 0; i<option_collection.size();i++)
			{
				request_.setProperty(option_collection[i],"");
			}

			sender_.send(request_);                
			Message response = receiver.fetch();
			std::string ser_obj = response.getContent();
			Serializable::Option_collection_ser oc;
			oc.ParseFromString(ser_obj);
			return oc;
		}//End Method

	}//end namespace NEclipse
}//end namespace Framework