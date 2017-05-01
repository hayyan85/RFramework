#include "OptionFeeds.h"
#include "OptionTick.pb.h"
#include "QStandardItemModel"
#include "Wopr.h"
#include "QTimer"
#include <windows.h>
#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "boost/thread/mutex.hpp"
#include "boost/algorithm/string.hpp"
#include "QMessageBox"

OptionFeeds* OptionFeeds::PtrOptionFeedsForm;

OptionFeeds::OptionFeeds(QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	PtrOptionFeedsForm = this;
	InitializeOptionsTable();
	connect(ui.cmdFindSymbol,SIGNAL(clicked()),this,SLOT(SearchSymbol()));
}

OptionFeeds::~OptionFeeds()
{

}

void OptionFeeds::ConsoleMessage(std::string msg)
{
	int no = 	ui.listConsoleMsg->count();
	if(no > 30)
	{
		ui.listConsoleMsg->clear();
	}
	ui.listConsoleMsg->addItem(msg.c_str());
	ui.listConsoleMsg->scrollToBottom();
	
}

std::string OptionFeeds::ConvertIntToString(int a)
{
	return QString::number(a).toStdString();
}

std::string OptionFeeds::Roundfloat(float a)
{
	//return QString::number(a,'f',DecimalDigits).toStdString();
	std::stringstream sout;
	std::string str;
	sout << std::fixed << std::setprecision(DecimalDigits) << a;
	sout >> str;   
	return str;
}


void OptionFeeds::SearchSymbol()
{
	std::string symb = ui.lineEditSymbolName->text().toStdString();
	boost::algorithm::to_upper(symb);
	if(symb!="")
	{
		QList<QStandardItem*> lst = ModelOptionTable->findItems(symb.c_str(),Qt::MatchExactly,0);
		if(lst.count()>0)
		{
			ui.tableViewOptions->selectRow(lst[0]->row());
			QModelIndex ind = ModelOptionTable->index(lst[0]->row(),0);
			ui.tableViewOptions->scrollTo(ind);
		}
		else
		{
			QMessageBox::information(this,"Not Found", "The item is not present in the table - Have you subscribed to it ?");
		}
	}
}

void OptionFeeds::MakeCellBlink(int row)
{
	{
		boost::lock_guard<boost::mutex> lock(mutex_blinker);
		ModelOptionTable->setData(ModelOptionTable->index(row,0), Qt::gray, Qt::BackgroundRole); //For Blinker
	}
	Sleep(95);
	{
		boost::lock_guard<boost::mutex> lock(mutex_blinker);
	    ModelOptionTable->setData(ModelOptionTable->index(row,0), Qt::white, Qt::BackgroundRole); //For Blinker
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------Table Display-----------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------

void OptionFeeds::InitializeOptionsTable()
{  	
	ModelOptionTable = new QStandardItemModel();
	DecimalDigits = atoi(WOPR::GetConfigValue("DecimalDigits").c_str());
	QStringList labels;
	labels.push_back("Symbol");
	labels.push_back("Bid Volume");
	labels.push_back("Ask Volume");
	labels.push_back("Daily Volume");
	labels.push_back("Daily Trades");
	labels.push_back("Open Interest");
	labels.push_back("Strike");
	labels.push_back("Bid");
	labels.push_back("Ask");
	labels.push_back("Exp. Time Left");
	labels.push_back("Bid Imp. Volatility");
	labels.push_back("Ask Imp. Volatility");
	labels.push_back("MP Imp. Volatility");

	labels.push_back("BidTrade");
	labels.push_back("AskTrade");
	labels.push_back("NTrade");
	labels.push_back("Bid Volume");
	labels.push_back("Ask Volume");
	labels.push_back("N Volume");

	ModelOptionTable->setHorizontalHeaderLabels(labels); //Labels for the columns
	ui.tableViewOptions->setModel(ModelOptionTable);
}


void OptionFeeds::OptionFeeds_ManageTableUpdates(Serializable::OptionTick_ser otick)
{
	std::string symb = otick.symbol();

	QList<QStandardItem*> lst = ModelOptionTable->findItems(symb.c_str(),Qt::MatchExactly,0);
	if(lst.count()>0)
	{
		//Symbol exists in the model
		UpdateExistingItemInModel(otick,lst[0]->row());
		//boost::thread t(boost::bind(&OptionFeeds::MakeCellBlink,this,lst[0]->row())); //Start the blinker
	}
	else
	{
		AddNewItemToModel(otick);
	}
}//End Method



void OptionFeeds::AddNewItemToModel(Serializable::OptionTick_ser otick)
{

	QStandardItem* item_symbol           =  new QStandardItem(otick.symbol().c_str());                               //Symbol
	QStandardItem* item_bid_volume       =  new QStandardItem(ConvertIntToString(otick.bidsize()).c_str());          //BidVolume
	QStandardItem* item_ask_volume       =  new QStandardItem(ConvertIntToString(otick.asksize()).c_str());          //AskVolume
	QStandardItem* item_daily_volume     =  new QStandardItem(ConvertIntToString(otick.dailyvolume()).c_str());      //DailyVolume
	QStandardItem* item_daily_trades     =  new QStandardItem(ConvertIntToString(otick.dailytrades()).c_str());      //DailyTrades  
	QStandardItem* item_open_interest    =  new QStandardItem(ConvertIntToString(otick.openinterest()).c_str());     //OpenInterest
	QStandardItem* item_strike           =  new QStandardItem(Roundfloat(otick.strike()).c_str());				     //Strike
	QStandardItem* item_bid              =  new QStandardItem(Roundfloat(otick.bid()).c_str());					     //Bid
	QStandardItem* item_ask              =  new QStandardItem(Roundfloat(otick.ask()).c_str());					     //Ask
	QStandardItem* item_exp_time_left    =  new QStandardItem(Roundfloat(otick.exp_time_left()).c_str());		 	 //ExpTimeLeft
	QStandardItem* item_bid_impl_volat   =  new QStandardItem(Roundfloat(otick.bid_imp_volatility()).c_str());       //BidImpVolat
	QStandardItem* item_ask_imp_volat    =  new QStandardItem(Roundfloat(otick.ask_imp_volatility()).c_str());       //ASkImpVolat
	QStandardItem* item_mp_impl_volat    =  new QStandardItem(Roundfloat(otick.mp_imp_volatility()).c_str());        //MPImpVolat

	QStandardItem* item_bid_trade        =  new QStandardItem(ConvertIntToString(otick.bidtrade()).c_str());         //BitTrade
	QStandardItem* item_asktrade         =  new QStandardItem(ConvertIntToString(otick.asktrade()).c_str());         //AskTrade
	QStandardItem* item_ntrade			 =  new QStandardItem(ConvertIntToString(otick.ntrade()).c_str());           //NTrade
	QStandardItem* item_bidvol			 =  new QStandardItem(ConvertIntToString(otick.bidvol()).c_str());           //BidVol
	QStandardItem* item_askvol			 =  new QStandardItem(ConvertIntToString(otick.askvol()).c_str());           //AskVol
	QStandardItem* item_nvol			 =  new QStandardItem(ConvertIntToString(otick.nvol()).c_str());             //NVol


	QList<QStandardItem*> lst ;
	lst.push_back(item_symbol);
	lst.push_back(item_bid_volume);
	lst.push_back(item_ask_volume);
	lst.push_back(item_daily_volume);
	lst.push_back(item_daily_trades);
	lst.push_back(item_open_interest);
	lst.push_back(item_strike);
	lst.push_back(item_bid);
	lst.push_back(item_ask);
	lst.push_back(item_exp_time_left);
	lst.push_back(item_bid_impl_volat);
	lst.push_back(item_ask_imp_volat);
	lst.push_back(item_mp_impl_volat);

	lst.push_back(item_bid_trade);
	lst.push_back(item_asktrade);
	lst.push_back(item_ntrade);
	lst.push_back(item_bidvol);
	lst.push_back(item_askvol);
	lst.push_back(item_nvol);
	ModelOptionTable->appendRow(lst);
}

void OptionFeeds::UpdateExistingItemInModel(Serializable::OptionTick_ser& otick,int rowno)
{
	
	int i=1;
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.bidsize()).c_str());  i++ ;       //BidVolume
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.asksize()).c_str());  i++ ;       //AskVolume
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.dailyvolume()).c_str());  i++ ;   //DailyVolume
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.dailytrades()).c_str());  i++ ;   //DailyTrades  
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.openinterest()).c_str()); i++ ;   //OpenInterest
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.strike()).c_str()); i++ ;                  //Strike
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.bid()).c_str()); i++ ;                     //Bid
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.ask()).c_str()); i++ ;                     //Ask
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.exp_time_left()).c_str()); i++ ;           //ExpTimeLeft
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.bid_imp_volatility()).c_str());   i++ ;   //BidImpVolat
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.ask_imp_volatility()).c_str());   i++ ;   //ASkImpVolat
	ModelOptionTable->item(rowno,i)->setText(Roundfloat(otick.mp_imp_volatility()).c_str());    i++ ;   //MPImpVolat

	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.bidtrade()).c_str());  i++ ;      //BidTrade
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.asktrade()).c_str());  i++ ;      //AskTrade  
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.ntrade()).c_str());  i++ ;        //NTrade
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.bidvol()).c_str());  i++ ;        //BidVol
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.askvol()).c_str());  i++ ;        //AskVol
	ModelOptionTable->item(rowno,i)->setText(ConvertIntToString(otick.nvol()).c_str());  i++ ;          //NVol
}