#ifndef Qpid_Network_Header
#define Qpid_Network_Header

#include "OptionTick.pb.h"

//---------QPID HEADERS----------------
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>
//--------------------------------------

#include <boost/thread/mutex.hpp>
#include <QObject>
#include "OptionQuoter.h"
#include <map>
#include <vector>
#include "RTypes.pb.h"

using namespace qpid::messaging;

namespace Framework
{
	namespace NOmega 
	{
		class QpidSubscriber : public QObject
		{
			Q_OBJECT

		private:
			
			static QpidSubscriber* QpidSingleton;
			Connection connection;
			bool ConnectedToWOPRBroadcast;
			//-------------------------------------------------------------------------------------------------------
			static qpid::messaging::Sender										   Option_Order_Sender; //Sender for sending Option order to Exec. Engine  
		    static std::map<std::string , OptionQuoter*>                           UpdatePacketTracker; //FormGUID - In order to send updates to relevant form 
			static QpidSubscriber*												   EventReceiver;       //Ptr that receives the event     
			//--------------------------------------------------------------------------------------------------------
			void ReceiveFromWOPRBroadCast(qpid::messaging::Receiver receiver);
			QpidSubscriber(QObject *parent = 0 );                                                                               //Private Constructor : To make it a singleton

		public:
			~QpidSubscriber();
			enum OrderType{Option,stock};
			void StartRecordTracker();
			Serializable::Option_collection_ser WOPRQuery_OptionUpdates(std::vector<std::string> option_collection);            //Sends a request to WOPR requesting data
			void AddEquitySubscriber(OptionQuoter* option_quoter_ptr); 
			
			void RemoveSignal(OptionQuoter* option_quoter_ptr,std::string symbol);		  				                        //Removes the signal-slot connection
			void RecordTracker();
			void Initiate_Option_Order_Dispatcher();
			void AddUpdatePacketSignal(OptionQuoter* option_quoter_ptr);
			void ConnectToWOPRBroadcast();
			//-----------------------------------------------------------------------------------------------------
			static QpidSubscriber*  GetQpidInstance();
			static void SubscribeToTopic(std::string symbol , std::string topicName, OptionQuoter* ptr);
			static void UnSubscribeFromTopic(std::string symbol,OptionQuoter* ptr);
			static void SendOptionOrder(Serializable::CustROrder_ser corder);
			//-----------------------------------------------------------------------------------------------------

		signals:
			void QTUpdateOptionTable(Serializable::OptionTick_ser ot);
			void QTErrorDump(std::string err);
			void QTRemoveSymbol(std::string symbol);
			void QTUpdateEventPacket(Serializable::RUpdatePacket updPacket);
			void QTTest(int a);
			void QTErrorMsg(std::string Error_Msg);
		};

	}//end namespace NEclipse
}//end namespace Framework
#endif 