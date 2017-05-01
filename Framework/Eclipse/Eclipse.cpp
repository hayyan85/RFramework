#include "Eclipse.h"
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "VolatilityGraph.h"
#include "External.h"
#include "OptionTick.pb.h"
#include "MySQL-Eclipse.h"
#include "OptionTick.pb.h"
#include "OptionScanner.h"
#include "ExpGraph.h"

#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>  

#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "boost/thread/mutex.hpp"

#include "QMessageBox"

namespace fs = boost::filesystem;

bool Eclipse::ConfigInitialized = false;

std::map<std::string,std::string> Eclipse::SymbAndTopics;
std::map<std::string,std::string> Eclipse::SymbUnderline;
Eclipse* Eclipse::EclipsePtr;

std::map<std::string,std::string>& Eclipse::get_config_map()
{
	static std::map<std::string,std::string> map;
	return map;
}

//Populates the config. into a map
void Eclipse::InitializeConfigSettings()
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

std::string Eclipse::GetConfigValue(std::string item_)
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

Eclipse::Eclipse(QWidget *parent, Qt::WFlags flags)	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	qRegisterMetaType<std::string>(); //Since we have signals that pass std::strings
	qRegisterMetaType<Serializable::OptionTick_ser>();
	qRegisterMetaType<Serializable::Option_collection_ser>();
	EclipsePtr = this;
	std::string title = "Eclipse" ;
	this->setWindowTitle(title.c_str());

	QObject::connect(ui.actionVolatility_Graph, SIGNAL(triggered()), this, SLOT(DisplayVolatilityGraph()));
	QObject::connect(ui.actionOption_Scanner, SIGNAL(triggered()), this, SLOT(DisplayOptionScanner()));
	QObject::connect(ui.actionExpiration_Graph, SIGNAL(triggered()), this, SLOT(DisplayExpirationGraph()));

	dbconnect = new Framework::NEclipse::DBaseConnection();
	dbconnect->InitiateDBConnection();

	InitializeConfigSettings();	
	
	GetSymbolsTopics();
}

Eclipse::~Eclipse()
{

}

void Eclipse::ErrorDisplay(QString ErrorMsg)
{
	QMessageBox::information(this,"Error : ",ErrorMsg);
}

void Eclipse::GetSymbolsTopics()
{
	 SymbAndTopics = dbconnect->GetCurrentSymbolMappedTopics();
	 SymbUnderline = dbconnect->GetUnderlineSymbols();
}

void Eclipse::DisplayEquityScanner()
{
	//EquityScanner *u = new EquityScanner(this);
	//u->setWindowFlags(u->windowFlags() | Qt::Dialog);
	//u->setFixedSize(u->size());
	//u->show();
	
}

void Eclipse::DisplayUpdateFeeds() 
{
	//TestUpdates *u = new TestUpdates(this);
	//u->setWindowFlags(u->windowFlags() | Qt::Dialog);
	//u->setFixedSize(u->size());
	//u->show();
}


void Eclipse::DisplayVolatilityGraph()
{
	VolatilityGraph *u = new VolatilityGraph();
	//u->setWindowFlags(u->windowFlags() | Qt::Dialog);
	//u->setFixedSize(u->size());
	u->setAttribute(Qt::WA_DeleteOnClose);
	u->show();
}

void Eclipse::DisplayOptionScanner()
{
	OptionScanner* u = new OptionScanner();
	u->setAttribute(Qt::WA_DeleteOnClose);
	u->show();
}

void Eclipse::DisplayExpirationGraph()
{
	ExpGraph* u = new ExpGraph();
	u->setAttribute(Qt::WA_DeleteOnClose);
	u->show();
}