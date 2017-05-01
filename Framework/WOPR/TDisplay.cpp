#include "TDisplay.h"
#include "QWidget"
#include "Wopr.h"
#include "boost/unordered_map.hpp"
#include "boost/make_shared.hpp"
#include "boost/shared_ptr.hpp"
#include "External.h"
#include <sstream>
#include <boost\spirit\include\karma.hpp>
#include <QStandardItemModel>
#include <iostream>
#include <iomanip>    

int TDisplay::DecimalDigits;
TDisplay* TDisplay::TableForm;


using namespace Framework::WOPR;

TDisplay::TDisplay(QWidget *parent)	: QWidget(parent)
{
	ui.setupUi(this);
	TableForm = this;
	//qRegisterMetaType<Serializable::HistoricalCollection_ser>(); //Since we have signals that pass HistoricalCollection
	//qRegisterMetaType<Serializable::HistoricalFields_ser>();     //Since we have signals that pass HistoricalFields
	InitializeTables();
}

TDisplay::~TDisplay()
{
}

//Slot Method
void TDisplay::UpdateSiloQuantity(int quantity,std::string symb)
{
	char str[10];
	itoa(quantity,str,10);
	if(symb=="SPY")
	{
		ui.textEditQuantity->setText(str);
	}
}//end method

//Slot Method
void TDisplay::UpdateFeedDelay(float delay_ms,std::string symb)
{
	
	if(symb==ui.textSymbolMonitor->toPlainText().toStdString())
	{
		int a = ui.textTimeDifference->toPlainText().toInt();
		//if(delay_ms>a)
		//{
			ui.textTimeDifference->setText(Roundfloat(delay_ms).c_str());
		//}
	}//end if
}//end method



void TDisplay::InitializeTables()
{	
	for(int i =0 ; i<4 ; i++)
	{
		QStandardItemModel* modelPtr;
		if(i == 0) 	    
		{  
			ModelOneMin = new QStandardItemModel();
			modelPtr = ModelOneMin;
			ui.OneMinTableView->setModel(modelPtr);
		}
		if(i == 1) 	    
		{  
			ModelFiveMin = new QStandardItemModel();
			modelPtr = ModelFiveMin;
			ui.FiveMinTableView->setModel(modelPtr);
		}
		if(i == 2) 	    
		{  
			ModelTenMin = new QStandardItemModel();
			modelPtr = ModelTenMin;
			ui.TenMinTableView->setModel(modelPtr);
		}
		if(i == 3) 	    
		{  
			ModelThirtyMin = new QStandardItemModel();
			modelPtr = ModelThirtyMin;
			ui.ThirtyMinTableView->setModel(modelPtr);
		}

		QStringList labels;
		labels << QObject::tr("Symbol")       << QObject::tr("High")        << QObject::tr("Low")         << QObject::tr("Close")       << QObject::tr("Date")       << QObject::tr("LCG") << QObject::tr("SCG")<< QObject::tr("CGTrend")  
			<< QObject::tr("HighestHigh")  <<QObject::tr("lowestlow")    <<  QObject::tr("HighZone")   << QObject::tr("lowzone")     << QObject::tr("BarNumber")
			<< QObject::tr("Latr")  << QObject::tr("Satr") << QObject::tr("LRange") << QObject::tr("VClose") << QObject::tr("ValueStd") << QObject::tr("ValueIncrement") << QObject::tr("ba_spread") ;

		modelPtr->setHorizontalHeaderLabels(labels); //Labels for the columns
	}//end for
	DecimalDigits = atoi(WOPR::GetConfigValue("DecimalDigits").c_str());
}

//Update the table
/*
void TDisplay::ManageTableUpdates(Serializable::HistoricalCollection_ser hcol)
{
	int timeFrames_sec[4] = { 60, 300, 600, 1800 };
	//Iterate through all the TimeFrames(i.e 60,300,600,1800) 
    //#pragma omp parallel num_threads(4)
	//{
		//#pragma omp for
		for(int i =0 ; i< hcol.hfcollection_size()-1 ; i++)
		{
			Serializable::HistoricalFields_ser hfield = hcol.hfcollection(i);
			ProcessSymbolDetails(hfield);
		}//End for
	//}//end pragma
}//End Method
*/

std::string TDisplay::Roundfloat(float a)
{
	std::stringstream sout;
	std::string str;
	sout << std::fixed << std::setprecision(DecimalDigits) << a;
	sout >> str;   
	return str;
}

/*
void TDisplay::ProcessSymbolDetails(Serializable::HistoricalFields_ser& hfield)
{
	QStandardItemModel* modelPtr;

	if     (hfield.frequency() == 60) 	         {	modelPtr = ModelOneMin;    }
	else if(hfield.frequency() == 300)           {	modelPtr = ModelFiveMin;   }
	else if(hfield.frequency() == 600)           { 	modelPtr = ModelTenMin;    }
	else if(hfield.frequency() == 1800)          { 	modelPtr = ModelThirtyMin; }

	//Check if the symbol exists in the model
	QList<QStandardItem*> lst = modelPtr->findItems(hfield.symbol().c_str(),Qt::MatchExactly,0);
	if(lst.count()>0)
	{
		//Symbol exists in the model
		UpdateExistingItemInModel(modelPtr,hfield,lst[0]->row());
	}
	else
	{
		AddNewItemToModel(modelPtr,hfield);
	}

}
*/
/*
void TDisplay::AddNewItemToModel(QStandardItemModel* model,Serializable::HistoricalFields_ser& hfield)
{
	std::string CGTrend_str;
	std::back_insert_iterator<std::string> sink_CGtrend(CGTrend_str);
	boost::spirit::karma::generate(sink_CGtrend,hfield.cgtrend());

	QStandardItem* item_symbol = new QStandardItem(hfield.symbol().c_str());
	QStandardItem* item_high   = new QStandardItem(Roundfloat(hfield.bar_high()).c_str());
	QStandardItem* item_low    = new QStandardItem(Roundfloat(hfield.bar_low()).c_str());
	QStandardItem* item_close  = new QStandardItem(Roundfloat(hfield.close()).c_str());
	QStandardItem* item_date   = new QStandardItem(hfield.ftime().c_str());
	QStandardItem* item_lcg   = new QStandardItem(Roundfloat(hfield.lcg()).c_str());
	QStandardItem* item_scg   = new QStandardItem(Roundfloat(hfield.scg()).c_str());
	QStandardItem* item_CGtrend   = new QStandardItem(CGTrend_str.c_str());

	QStandardItem* item_HighestHigh   = new QStandardItem(Roundfloat(hfield.bid()).c_str());
	QStandardItem* item_lowestlow     = new QStandardItem(Roundfloat(hfield.ask()).c_str());
	QStandardItem* item_highzone      = new QStandardItem(Roundfloat(hfield.highzone()).c_str());
	QStandardItem* item_lowzone       = new QStandardItem(Roundfloat(hfield.lowzone()).c_str());
	QStandardItem* item_r2value      = new QStandardItem(Roundfloat(hfield.barnumber()).c_str());

	//--------
	QStandardItem* item_Latr    = new QStandardItem(Roundfloat(hfield.latr()).c_str());
	QStandardItem* item_Satr    = new QStandardItem(Roundfloat(hfield.satr()).c_str());
	QStandardItem* item_LRange  = new QStandardItem(Roundfloat(hfield.lrange()).c_str()); 
	QStandardItem* item_VClose  = new QStandardItem(Roundfloat(hfield.vclose()).c_str());
	QStandardItem* item_ValueStd = new QStandardItem(Roundfloat(hfield.valuestd()).c_str());
	QStandardItem* item_ValueIncrement = new QStandardItem(Roundfloat(hfield.valueincrement()).c_str());
	QStandardItem* item_ba_spread= new QStandardItem(Roundfloat(hfield.ba_spread()).c_str());

	QList<QStandardItem*> lst ;

	lst.push_back(item_symbol);
	lst.push_back(item_high);
	lst.push_back(item_low);
	lst.push_back(item_close);
	lst.push_back(item_date);
	lst.push_back(item_lcg);
	lst.push_back(item_scg);
	lst.push_back(item_CGtrend);

	lst.push_back(item_HighestHigh);
	lst.push_back(item_lowestlow);
	lst.push_back(item_highzone);
	lst.push_back(item_lowzone);
	lst.push_back(item_r2value);

	lst.push_back(item_Latr);
	lst.push_back(item_Satr);
	lst.push_back(item_LRange);
	lst.push_back(item_VClose);
	lst.push_back(item_ValueStd);
	lst.push_back(item_ValueIncrement);
	lst.push_back(item_ba_spread);

	model->appendRow(lst);
}
*/
void TDisplay::AdjustTrendColour(QStandardItemModel* model,int row)
{

}

void TDisplay::AdjustVcloseColour(QStandardItemModel* model,int row)
{
}

/*
void TDisplay::UpdateExistingItemInModel(QStandardItemModel* model,Serializable::HistoricalFields_ser& hfield,int rowno)
{
	int i=1;
	std::string CGTrend_str;
	std::back_insert_iterator<std::string> sink_CGtrend(CGTrend_str);
	boost::spirit::karma::generate(sink_CGtrend,hfield.cgtrend());

	model->item(rowno,i)->setText(Roundfloat(hfield.bar_high()).c_str()); i++; //High
	model->item(rowno,i)->setText(Roundfloat(hfield.bar_low()).c_str()); i++;  //Low
	model->item(rowno,i)->setText(Roundfloat(hfield.close()).c_str()); i++;    //Close

	model->item(rowno,i)->setText(hfield.ftime().c_str()); i++;                 //Date
	model->item(rowno,i)->setText(Roundfloat(hfield.lcg()).c_str()); i++;      //LCG
	model->item(rowno,i)->setText(Roundfloat(hfield.scg()).c_str()); i++;      //SCG
	model->item(rowno,i)->setText(CGTrend_str.c_str()); i++;                    //CGTrend
	 

	model->item(rowno,i)->setText(Roundfloat(hfield.bid()).c_str()); i++;         //HighestHigh
	model->item(rowno,i)->setText(Roundfloat(hfield.ask()).c_str()); i++;         //LowestLow
	model->item(rowno,i)->setText(Roundfloat(hfield.highzone()).c_str()); i++;    //Highzone
	model->item(rowno,i)->setText(Roundfloat(hfield.lowzone()).c_str()); i++;     //Lowzone
	model->item(rowno,i)->setText(Roundfloat(hfield.barnumber()).c_str()); i++;   //BarNumber

	model->item(rowno,i)->setText(Roundfloat(hfield.latr()).c_str()); i++;       //Latr
	model->item(rowno,i)->setText(Roundfloat(hfield.satr()).c_str()); i++;       //Satr
	model->item(rowno,i)->setText(Roundfloat(hfield.lrange()).c_str()); i++;     //LRange
	model->item(rowno,i)->setText(Roundfloat(hfield.vclose()).c_str()); i++;     //Vclose
	model->item(rowno,i)->setText(Roundfloat(hfield.valuestd()).c_str()); i++;   //ValueStd
	model->item(rowno,i)->setText(Roundfloat(hfield.valueincrement()).c_str()); i++; //ValueIncrement
	model->item(rowno,i)->setText(Roundfloat(hfield.ba_spread()).c_str()); i++;      //baspread
	
}
*/