#include "SymbolLoad.h"
#include "MySQL-OMEGA.h"
#include "boost/lexical_cast.hpp"
#include "QMessageBox"

SymbolLoad::SymbolLoad(QWidget *parent)	: QDialog(parent)
{
	ui.setupUi(this);
	db = new Framework::NOmega::DBaseConnection();
	db->InitiateDBConnection();

	populateDistinctSymbols();
	
	QObject::connect(ui.cmdLoadSymbol,SIGNAL(clicked()),this,SLOT(ProcessSymbolDetails()));
	
	QObject::connect(ui.cmdDone,SIGNAL(clicked()),this,SLOT(RetrieveCorrespondingSymbol()));

	QObject::connect(ui.cmdCancel,SIGNAL(clicked()),this,SLOT(CancelForm()));

	QObject::connect(ui.ComboQExpDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(Q_DateChanged(QString)));
	QObject::connect(ui.ComboQCallPut,SIGNAL(currentIndexChanged(QString)),this,SLOT(Q_CallPutChanged(QString)));


	QObject::connect(ui.ComboAExpDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(A_DateChanged(QString)));
	QObject::connect(ui.ComboACallPut,SIGNAL(currentIndexChanged(QString)),this,SLOT(A_CallPutChanged(QString)));
	

	QObject::connect(ui.ComboBExpDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(B_DateChanged(QString)));
	QObject::connect(ui.ComboBCallPut,SIGNAL(currentIndexChanged(QString)),this,SLOT(B_CallPutChanged(QString)));

	QObject::connect(ui.ComboCExpDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(C_DateChanged(QString)));
	QObject::connect(ui.ComboCCallPut,SIGNAL(currentIndexChanged(QString)),this,SLOT(C_CallPutChanged(QString)));

	QObject::connect(ui.ComboDExpDate,SIGNAL(currentIndexChanged(QString)),this,SLOT(D_DateChanged(QString)));
	QObject::connect(ui.ComboDCallPut,SIGNAL(currentIndexChanged(QString)),this,SLOT(D_CallPutChanged(QString)));

	
}

SymbolLoad::~SymbolLoad()
{
	/*Destructor*/
}

void SymbolLoad::CancelForm()
{
	reject();
}

void SymbolLoad::RetrieveCorrespondingSymbol()
{
	//clear the map
	symbolTypeMap.clear();

	if(ui.checkBoxQ->checkState()==Qt::Checked)
	{
		symbolTypeMap["Q"]=db->GetFinalSymbol(ui.ComboDistinctSymbol->currentText().toStdString(),ui.ComboQExpDate->currentText().toStdString(),ui.ComboQCallPut->currentText().toStdString(),ui.ComboQStrike->currentText().toDouble());
		CallPut = ui.ComboQCallPut->currentText().toStdString();
		Maturity = QString(ui.ComboQExpDate->currentText()).replace("-","").toStdString().c_str();
		strike =  ui.ComboQStrike->currentText().toFloat();
		//symbolTypeMap["UnderLying"] = ui.ComboDistinctSymbol->currentText().toStdString();
		UnderLineSymbol = ui.ComboDistinctSymbol->currentText().toStdString();
		QuoteSymbol = symbolTypeMap["Q"];
	}

	if(ui.checkBoxA->checkState()==Qt::Checked)
	{
		symbolTypeMap["A"]=db->GetFinalSymbol(ui.ComboDistinctSymbol->currentText().toStdString(),ui.ComboAExpDate->currentText().toStdString(),ui.ComboACallPut->currentText().toStdString(),ui.ComboAStrike->currentText().toDouble());
	}
	if(ui.checkBoxB->checkState()==Qt::Checked)
	{
		symbolTypeMap["B"]=db->GetFinalSymbol(ui.ComboDistinctSymbol->currentText().toStdString(),ui.ComboBExpDate->currentText().toStdString(),ui.ComboBCallPut->currentText().toStdString(),ui.ComboBStrike->currentText().toDouble());
	}
	if(ui.checkBoxC->checkState()==Qt::Checked)
	{
		symbolTypeMap["C"]=db->GetFinalSymbol(ui.ComboDistinctSymbol->currentText().toStdString(),ui.ComboCExpDate->currentText().toStdString(),ui.ComboCCallPut->currentText().toStdString(),ui.ComboCStrike->currentText().toDouble());;
	}
	if(ui.checkBoxD->checkState()==Qt::Checked)
	{
		symbolTypeMap["D"]=db->GetFinalSymbol(ui.ComboDistinctSymbol->currentText().toStdString(),ui.ComboDExpDate->currentText().toStdString(),ui.ComboDCallPut->currentText().toStdString(),ui.ComboDStrike->currentText().toDouble());;
	}

	//Check if the conditions are met
	//At least two items need to be checked and one needs to be a Q(QUOTE)
	if(symbolTypeMap.size()>=2)
	{
		if(ui.checkBoxQ->checkState()==Qt::Checked)
		{
           accept(); //Return control back to the main 
		}
		else
		{
			QMessageBox::information(this,"Invalid Selection", "One of the selection needs to be a Quote");
		}
	}
	else
	{
		QMessageBox::information(this,"Invalid Selection", "Atleast two selections are required and one needs to be a Quote");
	}
}

void SymbolLoad::populateDistinctSymbols()
{
	std::vector<std::string> dsymbol = db->GetDistinctSymbols();
	for(std::vector<std::string>::iterator it = dsymbol.begin(); it != dsymbol.end(); it++ )
	{
		ui.ComboDistinctSymbol->addItem((*it).c_str());	
	}
	ui.ComboQExpDate->setCurrentIndex(0);
	ui.ComboQCallPut->setCurrentIndex(0);
	ui.ComboQStrike->setCurrentIndex(0);
}

void SymbolLoad::DateChangedProcess(QComboBox * callput,QComboBox* strike,std::string itm)
{
	callput->clear();
	std::string symb = ui.ComboDistinctSymbol->currentText().toStdString();
	std::vector<std::string> temp = db->GetCallAndPuts(symb,itm);
	callput->addItem("--");	
	for(std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		callput->addItem((*it).c_str());	
	}
	callput->setCurrentIndex(0);
	strike->setCurrentIndex(0);
}

void SymbolLoad::CallPutChangedProcess(QComboBox * strike,QComboBox* date,std::string itm)
{
	strike->clear();
	std::string symb = ui.ComboDistinctSymbol->currentText().toStdString();
	std::string sdate = date->currentText().toStdString();
	std::string callput = itm;
	std::vector<double> rslt = db->GetStrikePrice(symb,sdate,callput);

	strike->addItem("--");
	for(std::vector<double>::iterator it = rslt.begin(); it != rslt.end(); it++ )
	{
		strike->addItem(boost::lexical_cast<std::string>(*it).c_str());	
	}
}

void SymbolLoad::Q_DateChanged(QString itm)
{
	/*
	ui.ComboQCallPut->clear();
	std::string symb = ui.ComboDistinctSymbol->currentText().toStdString();
	std::vector<std::string> temp = db->GetCallAndPuts(symb,itm.toStdString());
	ui.ComboQCallPut->addItem("--");	
	for(std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		ui.ComboQCallPut->addItem((*it).c_str());	
	}
	ui.ComboQCallPut->setCurrentIndex(0);
	ui.ComboQStrike->setCurrentIndex(0);*/
	DateChangedProcess(ui.ComboQCallPut,ui.ComboQStrike,itm.toStdString());
}


void SymbolLoad::A_DateChanged(QString itm)
{
	DateChangedProcess(ui.ComboACallPut,ui.ComboAStrike,itm.toStdString());
}

void SymbolLoad::B_DateChanged(QString itm)
{
	DateChangedProcess(ui.ComboBCallPut,ui.ComboBStrike,itm.toStdString());
}

void SymbolLoad::C_DateChanged(QString itm)
{
	DateChangedProcess(ui.ComboCCallPut,ui.ComboCStrike,itm.toStdString());
}

void SymbolLoad::D_DateChanged(QString itm)
{
	DateChangedProcess(ui.ComboDCallPut,ui.ComboDStrike,itm.toStdString());
}

void SymbolLoad::A_CallPutChanged(QString itm)
{
	CallPutChangedProcess(ui.ComboAStrike,ui.ComboAExpDate,itm.toStdString());
}

void SymbolLoad::B_CallPutChanged(QString itm)
{
	CallPutChangedProcess(ui.ComboBStrike,ui.ComboBExpDate,itm.toStdString());
}

void SymbolLoad::C_CallPutChanged(QString itm)
{
	CallPutChangedProcess(ui.ComboCStrike,ui.ComboCExpDate,itm.toStdString());
}

void SymbolLoad::D_CallPutChanged(QString itm)
{
	CallPutChangedProcess(ui.ComboDStrike,ui.ComboDExpDate,itm.toStdString());
}


void SymbolLoad::Q_CallPutChanged(QString itm)
{
    /*
    ui.ComboQStrike->clear();
	std::string symb = ui.ComboDistinctSymbol->currentText().toStdString();
    std::string date = ui.ComboQExpDate->currentText().toStdString();
	std::string callput = itm.toStdString();
	std::vector<double> rslt = db->GetStrikePrice(symb,date,callput);
	ui.ComboQStrike->addItem("--");
	for(std::vector<double>::iterator it = rslt.begin(); it != rslt.end(); it++ )
	{
		ui.ComboQStrike->addItem(boost::lexical_cast<std::string>(*it).c_str());	
	}
	*/
	CallPutChangedProcess(ui.ComboQStrike,ui.ComboQExpDate,itm.toStdString());
}

void SymbolLoad::ProcessSymbolDetails()
{
	ui.ComboQExpDate->clear();
	ui.ComboAExpDate->clear();
	ui.ComboBExpDate->clear();
	ui.ComboCExpDate->clear();
	ui.ComboDExpDate->clear();
	std::string symb = ui.ComboDistinctSymbol->currentText().toStdString();
	std::vector<std::string> expdates = db->GetRelevantExpirationDates(symb);
	ui.ComboQExpDate->addItem("--");
	ui.ComboAExpDate->addItem("--");
	ui.ComboBExpDate->addItem("--");
	ui.ComboCExpDate->addItem("--");
	ui.ComboDExpDate->addItem("--");
	for(std::vector<std::string>::iterator it = expdates.begin(); it != expdates.end(); it++ )
	{
		ui.ComboQExpDate->addItem((*it).c_str());
		ui.ComboAExpDate->addItem((*it).c_str());
		ui.ComboBExpDate->addItem((*it).c_str());
		ui.ComboCExpDate->addItem((*it).c_str());
		ui.ComboDExpDate->addItem((*it).c_str());
	}

}