#include "Network.h"
#include <intrin.h>
#include <iostream>
#include <sstream> 
#include <boost\spirit\include\karma.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <map>
#include <vector>
#include "OptionTick.pb.h"
#include <qpid/messaging/Address.h>
#include <vector>
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp> 
#include "OptionQuoter.h"
#include "omega.h"
#include <Windows.h>

using namespace qpid::messaging;

namespace Framework
{
	namespace NOmega
	{
	
		QpidSubscriber* QpidSubscriber::QpidSingleton=NULL;
		
		//Sender for sending orders to the Execution Engine
		qpid::messaging::Sender                                      QpidSubscriber::Option_Order_Sender;

		//Tracks the GUID with the Form for returning update packets
		std::map<std::string , OptionQuoter*>                        QpidSubscriber::UpdatePacketTracker;


		//Stores the address of the instance that receives events
		QpidSubscriber*                                             QpidSubscriber::EventReceiver;


		QpidSubscriber::~QpidSubscriber()
		{		}

		//Constructor
		QpidSubscriber::QpidSubscriber(QObject *parent /* = 0 */):QObject(parent)
		{
			ConnectedToWOPRBroadcast = false;
		}

		QpidSubscriber* QpidSubscriber::GetQpidInstance()
		{
			if(QpidSingleton==NULL)
			{
				QpidSingleton = new QpidSubscriber();
				QpidSingleton->Initiate_Option_Order_Dispatcher();  //Start the Option Order Dispatcher - Dispatches order to Exe.Engine
				QpidSingleton->StartRecordTracker();                //Starts Receiving order updates from the Execution Engine 
				return QpidSingleton;
			}
			return QpidSingleton;
		}

		void QpidSubscriber::SubscribeToTopic(std::string symbol , std::string topicName , OptionQuoter* ptr)
		{
			QpidSingleton->AddEquitySubscriber(ptr);
		}//End


		void QpidSubscriber::ConnectToWOPRBroadcast()
		{
			if(ConnectedToWOPRBroadcast)
			{
				return;
			}

			std::string conn_ip ;
			conn_ip = OMEGA::GetConfigValue("QpidBrokerAddress");
			connection = Connection(conn_ip);
			connection.open();
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
				}
			}//End while
			connection.close();    //Close the main connection
		}//End Method


		void QpidSubscriber::UnSubscribeFromTopic(std::string symbol,OptionQuoter* ptr)
		{
		
		}

		void QpidSubscriber::AddEquitySubscriber(OptionQuoter* option_quoter_ptr)
		{
			connect(this,SIGNAL(QTUpdateOptionTable(Serializable::OptionTick_ser)),option_quoter_ptr,SLOT(UpdateOptionModel(Serializable::OptionTick_ser)),Qt::AutoConnection);
			connect(this,SIGNAL(QTRemoveSymbol(std::string)),option_quoter_ptr,SLOT(RemoveSymbolFromModel(std::string)),Qt::AutoConnection);
			AddUpdatePacketSignal(option_quoter_ptr); //Make sure all forms receive events also
			//connect(this,SIGNAL(QTErrorMsg(std::string)),option_quoter_ptr,SLOT(DisplayErrorMessage(std::string)),Qt::AutoConnection);
		}

		void QpidSubscriber::RemoveSignal(OptionQuoter* option_quoter_ptr,std::string symbol)
		{
			disconnect(this, 0, option_quoter_ptr, 0);
		}

		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Sends a request to WOPR and waits for a response from it
		Serializable::Option_collection_ser QpidSubscriber::WOPRQuery_OptionUpdates(std::vector<std::string> option_collection)
		{
			std::string conn_ip ;
			conn_ip = OMEGA::GetConfigValue("QpidBrokerAddress");
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



		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------EVENT AND ORDER MANAGEMENT METHODS-------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		

		void QpidSubscriber::StartRecordTracker()
		{
			QpidSubscriber* qs = new QpidSubscriber();
			EventReceiver = qs;
			boost::thread t(boost::bind(&QpidSubscriber::RecordTracker,qs));
		}



		void QpidSubscriber::AddUpdatePacketSignal(OptionQuoter* option_quoter_ptr)
		{
			//connect(this,SIGNAL(QTUpdateEventPacket(Serializable::RUpdatePacket)),option_quoter_ptr,SLOT(UpdateOpenOrder(Serializable::RUpdatePacket)),Qt::AutoConnection);
			connect(EventReceiver,SIGNAL(QTUpdateEventPacket(Serializable::RUpdatePacket)),option_quoter_ptr,SLOT(UpdateOpenOrder(Serializable::RUpdatePacket)),Qt::AutoConnection);
		}

		//##################################################################
		//Queue : EVENT RECEIVER FROM EE - LISTENER                        #
		//This thread is responsible for updating the Orders in the table  #
		//This method receives the EVENTS from Execution Engine            #
		//##################################################################
	    void QpidSubscriber::RecordTracker()
		{
			
			try
			{
				std::string conn_ip ;
				conn_ip = OMEGA::GetConfigValue("QpidOrderEventAddress");
				Message msg;
				connection = Connection(conn_ip);
				connection.open();
				Session session  = connection.createSession();
				Receiver receiver = session.createReceiver("Update_packet ;{mode:browse}");
				receiver.setCapacity(800);
				Duration delay(30);
				int msgCounter = 0;
				while(true)
				{
					try
					{
						msg = receiver.fetch(Duration::FOREVER);
						std::string cont = msg.getContent();
						Serializable::RUpdatePacket ru;
						ru.ParseFromString(cont);
						QTUpdateEventPacket(ru);
						msgCounter++;
						if(msgCounter>600)
						{
							session.acknowledge();
							msgCounter = 0;
						}
					}
					catch (std::exception &ex)
					{
						std::string err = ex.what();
					}
				}//End while

				connection.close();    //Close the main connection
			}
			catch(std::exception &ex)
			{

			}
		}//end Method



		//#################################################################################
		//QUEUE : ORDER DISPATCHER                                                        #
		//This method initiates the sender that will send orders to the execution engine. #
		//#################################################################################
		void QpidSubscriber::Initiate_Option_Order_Dispatcher()
		{
			   try
			   {
				std::string queue_name = "Option_Orders_";		
				std::string sender_string = queue_name;				
				qpid::messaging::Connection connection(OMEGA::GetConfigValue("QpidOrderEventAddress"));
				connection.open();
				connection.setOption("tcp-nodelay", true);
				Session session  = connection.createSession();
				Option_Order_Sender = session.createSender(sender_string) ;
				Option_Order_Sender.setCapacity(800);
			   }
			   catch(std::exception& ex)
			   {
				   std::string e = ex.what();
			   }
			
		}

        //Send the Options order
		void QpidSubscriber::SendOptionOrder(Serializable::CustROrder_ser corder)
		{
			Message option_msg;
			option_msg.setContent(corder.SerializeAsString());
			Option_Order_Sender.send(option_msg);
		}

	}//end namespace NEclipse
}//end namespace Framework