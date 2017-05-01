#ifndef Qpid_Network_Header
#define Qpid_Network_Header

#include <qdebug.h>
#include <QObject>
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>

#include <boost/thread/mutex.hpp>
#include "External.h"

#include "OptionTick.pb.h"
#include "StockTick.pb.h"
using namespace qpid::messaging;


namespace Framework
{
	namespace WOPR
	{
		class QpidConnector : public QObject
		{
		Q_OBJECT 
		private:
		Message message;
		qpid::messaging::Connection connection;
		qpid::messaging::Sender sender;
		std::string Convert_Int_To_String(int a);
		void RespondToRequests();

		public:  
		QpidConnector(QObject *parent = 0);		
		void Create_Dynamic_Queues(int con,std::string symbol,int FirstRequest=0);
		void Dispatach_Options(Serializable::OptionTick_ser& opt_tick,std::string symbol);
		void Dispatach_Stocks(Serializable::StockTick_ser& opt_tick,std::string symbol);
		void StartRequestResponser();
		void CloseConnection();

        signals:
		void QTDisplayOnOptionForm(Serializable::OptionTick_ser ot);
		void QTConsoleMessage(std::string msg);
		};

	}//end namespace Framework
}//end namespace WOPR
#endif 