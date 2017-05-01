#include "Wopr.h"
#include <fstream>
#include "External.h"
#include <map>
#include <vector>
#include <intrin.h>
#include <boost/algorithm/string.hpp>
#include "TDisplay.h"

#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>  

#include "MySQL-WOPR.h"

#include "AddOptionSymbol.h"

#ifndef UPDATEFEEDS_H
#include "UpdateFeeds.h"
#endif


#pragma comment(lib,  "ws2_32.lib") 

bool WOPR::ConfigInitialized = false;

std::map<std::string,std::string>& WOPR::get_config_map()
{
	static std::map<std::string,std::string> map;
	return map;
}

WOPR::WOPR(QWidget *parent, Qt::WFlags flags)	: QMainWindow(parent, flags)

{
	ui.setupUi(this);
	QObject::connect(ui.actionStart_Feeds, SIGNAL(triggered()), this, SLOT(startUpdates()));
	QObject::connect(ui.actionAdd_Option, SIGNAL(triggered()), this, SLOT(AddNewOptionSymbol()));
	std::string title = "WOPR";
	this->setWindowTitle(title.c_str());
}

WOPR::~WOPR()
{}

void WOPR::QuitWOPR()
{
	qApp->exit();
}

void WOPR::InitializeConfigSettings()
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

std::string WOPR::GetConfigValue(std::string item_)
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
		__debugbreak();
		return "Item not found";
	}
}

void WOPR::startOptions()
{
	//Start options from the scalp feed
}

void WOPR::startUpdates()
{
	updtFeeds = new UpdateFeeds();
	updtFeeds->setFixedSize(updtFeeds->size());
	updtFeeds->setWindowFlags(Qt::Dialog);
	updtFeeds->show();
}

void WOPR::AddNewOptionSymbol()
{
	AddOptionSymbol *sload = new AddOptionSymbol(this);
	sload->setWindowModality(Qt::WindowModal); //Block only this form instance

	if(sload->exec()==1) //Block until the user selects from a form
	{
		//Add new symbol to the option list
		updtFeeds->AddNewSymbolRuntime(sload->get_symbol(),sload->get_under(),sload->get_callput());
		//Check if we need to add it to the DB
		if(sload->get_AddRecord())
		{
			//Add it to the db
			Framework::WOPR::DBaseConnection db;
			db.InitiateDBConnection();
			db.AddRuntimeOption(sload);
		}
	}
	else
	{
		//Do nothing ... Since the form was canceled
	}
	delete sload;
}