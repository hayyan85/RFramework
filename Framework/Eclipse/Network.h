#ifndef Qpid_Network_Header
#define Qpid_Network_Header

#include "OptionTick.pb.h"
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/mutex.hpp>
#include <QObject>
#include "External.h"
#include "VolatilityGraph.h"
#include <map>
#include <vector>

using namespace qpid::messaging;

namespace Framework
{
	namespace NEclipse 
	{
		class QpidSubscriber : public QObject
		{
		Q_OBJECT
		
		private:
	    static QpidSubscriber* QpidSingleton;
		bool ConnectedToWOPRBroadcast;
		Connection connection;
	
		void ReceiveFromWOPRBroadCast(qpid::messaging::Receiver receiver);

		public:
		~QpidSubscriber();
		QpidSubscriber(QObject *parent = 0); 
		Serializable::Option_collection_ser WOPRQuery_OptionUpdates(std::vector<std::string> option_collection);        //Sends a request to WOPR requesting data
		void AddOptionSubscriber(QObject* form_ptr);                 //Subscribes to the feed 
		void RemoveSignal(QObject* form_ptr,std::string symbol);	 //Removes the signal-slot connection
		void ConnectToWOPRBroadcast();                               //Subscribes to the feed
				
		static QpidSubscriber*  GetQpidInstance();
		static void SubscribeToOptionTopic(std::string symbol , std::string topicName, QObject* ptr);

	
		static void UnSubscribeFromTopic(std::string symbol,QObject* ptr);

		signals:
		void QTUpdateOptionTable(Serializable::OptionTick_ser ot);
		void QTErrorDump(QString err);
		void QTRemoveSymbol(std::string symbol);
		};

	}//end namespace NEclipse
}//end namespace Framework
#endif 