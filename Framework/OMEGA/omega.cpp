#include "omega.h"
#include "OptionQuoter.h"
#include  "External.h"
#include "OptionTick.pb.h"
#include <fstream>
#include <intrin.h>
#include <boost/algorithm/string.hpp>
#include "Network.h"
#include "RTypes.pb.h"

#include "TimedMessage.h"


//---------QPID HEADERS----------------
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>
//--------------------------------------

bool OMEGA::ConfigInitialized = false;



std::map<std::string,std::string> OMEGA::SymbAndTopics;
std::map<std::string,std::string> OMEGA::IQSterlingEquivalent;
std::map<std::string,std::string> OMEGA::SymbAndUnderlying;
std::map<std::string, OptionQuoter*> OMEGA::OptionQuoterTracker;



OMEGA::OMEGA(QWidget *parent, Qt::WFlags flags)	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	Dbconnected = false;
	dbconnect = new Framework::NOmega::DBaseConnection();
	InitializeDatabase();
	TestQpidFeedConnection();
	TestQpidEventConnection();
	qRegisterMetaType<Serializable::OptionTick_ser>();
	qRegisterMetaType<Serializable::ROrderPosition>();
	qRegisterMetaType<Serializable::RUpdatePacket>();
	qRegisterMetaType<std::string>(); //Since we have signals that pass std::strings
	QObject::connect(ui.actionOption_Quoter,SIGNAL(triggered()),this,SLOT(StartOptionQuoter()));

	QObject::connect(ui.actionStop_All_Quoters,SIGNAL(triggered()),this,SLOT(StopAllQuoters()));
	QObject::connect(ui.actionStop_All_Quoters,SIGNAL(triggered()),this,SLOT(PauseAllQuoters()));

	GetSymbolsTopics();
}

OMEGA::~OMEGA()
{

}


void OMEGA::InitializeDatabase()
{
	try
	{
		dbconnect->InitiateDBConnection();
		Dbconnected = true;
		ui.label_SQLSTATUS->setText("Connected");
		ui.label_SQLSTATUS->setStyleSheet("QLabel {color : blue; }");
	}
	catch(std::exception* e)
	{
		ui.label_SQLSTATUS->setText("Not Connected");
		ui.label_SQLSTATUS->setStyleSheet("QLabel {color : red; }");
		Dbconnected = false;
	}
}


void OMEGA::TestQpidFeedConnection()
{
	try
	{
		//Test Update Feed QPID Connection
		qpid::messaging::Connection connection = Connection(GetConfigValue("QpidBrokerAddress"));
		connection.open();
		ui.labelQPIDSTATUS->setText("Connected");
		ui.labelQPIDSTATUS->setStyleSheet("QLabel {color : blue; }");
	}
	catch (std::exception& e)
	{
		ui.labelQPIDSTATUS->setText("Not Connected");
		ui.labelQPIDSTATUS->setStyleSheet("QLabel {color : red; }");
	}
}


void OMEGA::TestQpidEventConnection()
{
	try
	{
		//Test Update Feed QPID Connection
		qpid::messaging::Connection connection = Connection(GetConfigValue("QpidOrderEventAddress"));
		connection.open();
		ui.label_QpidEventStatus->setText("Connected");
		ui.label_QpidEventStatus->setStyleSheet("QLabel {color : blue; }");
	}
	catch (std::exception& e)
	{
		ui.label_QpidEventStatus->setText("Not Connected");
		ui.label_QpidEventStatus->setStyleSheet("QLabel {color : red; }");
	}
}

std::map<std::string,std::string>& OMEGA::get_config_map()
{
	static std::map<std::string,std::string> map;
	return map;
}

//Populates the config. into a map
void OMEGA::InitializeConfigSettings()
{
	if(ConfigInitialized)
	{return;}

	std::vector<std::string> results;
	std::ifstream File(FilePath);
	std::string line;
	if(File)
	{
		while(getline(File,line))
		{
			if(line!="")
			{
				boost::split(results, line, boost::is_any_of("=//"));
				std::string key_ = results[0];
				std::string value_ = results[1];
				boost::algorithm::trim(key_);
				boost::algorithm::trim(value_);
				get_config_map().insert(std::pair<std::string,std::string>(key_,value_));
			}
		}
		File.close();
		ConfigInitialized = true;
	}
}//End method


std::string OMEGA::GetConfigValue(std::string item_)
{
	InitializeConfigSettings();
	std::map<std::string,std::string>::iterator myiter = get_config_map().find(item_);
	if(myiter != get_config_map().end())
	{
		//item found
		return get_config_map()[item_];
	}
	else
	{
		return "Item not found";
	}
}


void OMEGA::GetSymbolsTopics()
{
	if(Dbconnected)
	{
		SymbAndTopics = dbconnect->GetCurrentSymbolMappedTopics();
		IQSterlingEquivalent = dbconnect->GetIQSterlingSymbolMapping();
		SymbAndUnderlying = dbconnect->GetUnderlyingSymbolMapping();
	}
}

void OMEGA::StartOptionQuoter()
{
	OptionQuoter* o = new OptionQuoter();
	o->show();
	o->setAttribute(Qt::WA_DeleteOnClose);
	OptionQuoterTracker[o->getFormGUID()] = o;
}


void OMEGA::RemoveOptionQuoterForm(std::string FormGUID)
{
	if( OptionQuoterTracker.find(FormGUID) != OptionQuoterTracker.end() )
	{
		//Found
		OptionQuoterTracker.erase(FormGUID);
	}
}

void OMEGA::StopAllQuoters()
{
	for(std::map<std::string,OptionQuoter*>::iterator it = OptionQuoterTracker.begin(); it!=OptionQuoterTracker.end();++it)
	{
		it->second->StopAutomation();
	}
}


void OMEGA::PauseAllQuoters()
{

	for(std::map<std::string,OptionQuoter*>::iterator it = OptionQuoterTracker.begin(); it!=OptionQuoterTracker.end();++it)
	{
		it->second->PauseAutomation();
	}
}