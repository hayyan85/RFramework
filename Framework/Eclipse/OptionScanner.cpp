#include "OptionScanner.h"
#include "QStandardItem"
#include <sstream>
#include <iomanip>
#include <MySQL-Eclipse.h>
#include "QMessageBox"

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "Network.h"
#include "Eclipse.h"

#include "boost/spirit/include/qi.hpp"
#include <boost/algorithm/string.hpp>

#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "OptionScannerLayout.h"
#include "QTextCodec"
#include "QFileDialog"
#include <fstream>
#include <QString>
#include "QByteArray"
#include "QInputDialog"
#include "OptionScannerProxy.h"

namespace qi = boost::spirit::qi;

OptionScanner::OptionScanner(QWidget *parent): QMainWindow(parent)
{
	bConnect = false; //Not Connected
	ui.setupUi(this);
	this->options_visible = true;
	FilterModelOptionTable = new Framework::NEclipse::OptionScanner_FilterProxyModel(this);
	FormGUID = boost::uuids::to_string(boost::uuids::random_generator()());
	db.InitiateDBConnection();
	
	ui.frame_extravar->setVisible(false);

	InitiateOptionScanner();
	InitializeOptionModel();

	QObject::connect(ui.cmdConnect,SIGNAL(clicked()),this,SLOT(RetrieveAllOptions()));
	QObject::connect(Column_Model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(FilterColumn(QStandardItem*))); //Column to filter checked
	
	QObject::connect(ui.cmdOptions,SIGNAL(clicked()), this, SLOT(HideOptions() ));
	
	QObject::connect(ui.cmdRemoveSelectedFilter,SIGNAL(clicked()), this, SLOT(RemoveFilter()));
	QObject::connect(ui.cmdAddFilter,SIGNAL(clicked()), this, SLOT(AddNewFilter()));
	QObject::connect(ui.lineEditSearch,SIGNAL(returnPressed()), this, SLOT(HighlightSymbol() ));

	QObject::connect(ui.actionLoad_Layout,SIGNAL(triggered()), this, SLOT(LoadLayout()));
	QObject::connect(ui.actionSave_Layout,SIGNAL(triggered()), this, SLOT(saveLayout()));
	

	QObject::connect(ui.tableSubscription->horizontalHeader(),SIGNAL(sectionMoved(int,int,int)), this, SLOT(sectionMoved(int,int,int) ));
	QObject::connect(ui.tableSubscription->horizontalHeader(),SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), this, SLOT(OptionssortIndicatorChanged(int,Qt::SortOrder)));
	QObject::connect(ui.actionAuto_Refresh,SIGNAL(triggered()), this, SLOT(ConfigureAutoSort()));
	QObject::connect(ui.actionDisable_Auto_Refresh,SIGNAL(triggered()), this, SLOT(StopAutoSort()));

	QObject::connect(ui.comboBoxOperation,SIGNAL(currentIndexChanged(int)), this, SLOT(LogicalOperatorChanged(int)));
	//QObject::connect(ui.actionTestLayout_2,SIGNAL(triggered()), this, SLOT(TestLayout()));
}


OptionScanner::~OptionScanner()
{
	db.CloseDBConnection();
}

void OptionScanner::sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex)
{/*.....*/}

/*
void OptionScanner::NewColumnInserted(int colno)
{
	ui.tableSubscription->showColumn(colno);
	int visualindex_a = ui.tableSubscription->horizontalHeader()->visualIndex(colno);
	int total_visible = ui.tableSubscription->horizontalHeader()->count();
	ui.tableSubscription->horizontalHeader()->showSection(colno);
	int visualindex_b = ui.tableSubscription->horizontalHeader()->logicalIndex(colno);
	ui.tableSubscription->horizontalHeader()->swapSections(visualindex_a,0);
	std::string t = "Dssdds";
}
*/


void OptionScanner::LogicalOperatorChanged(int index)
{
	if(ui.comboBoxOperation->itemText(index)=="<>" || ui.comboBoxOperation->itemText(index)=="<=>" )
	{
		ui.lineEditPassValue_ext1->setText("");
		ui.lineEditPassValue_ext2->setText("");
		ui.frame_extravar->setVisible(true);
		ui.lineEditPassValue->setVisible(false);
	}
	else
	{
		ui.frame_extravar->setVisible(false);
		ui.lineEditPassValue->setVisible(true);
	}
}

//Sort Indicator - Used for sorting
//These variables are used by Sort Timer
void OptionScanner::OptionssortIndicatorChanged(int logicalIndex , Qt::SortOrder order)
{
	ColumnToSort = logicalIndex;
	ColumnSortorder = order;
}

//This method stops auto-sorting
void OptionScanner::StopAutoSort()
{
	SortTimer.stop();
}

//This method is triggered when sort timeout is triggered
void OptionScanner::UpdateSort()
{
	FilterModelOptionTable->sort(ColumnToSort,ColumnSortorder);
	FilterModelOptionTable->setSourceModel(ModelOptions);
}

void OptionScanner::ConfigureAutoSort()
{
	bool ok = false;
	int i = QInputDialog::getInteger(this, tr("Enter Refresh Period"),tr("Seconds"), 1, 0, 100, 1, &ok);
	if(ok)
	{
		SortTimer.stop();
		SortTimer.setInterval(i*6000);
		QObject::connect(&SortTimer, SIGNAL(timeout()), this, SLOT(UpdateSort()));
		SortTimer.start();
	}
}//End Method

void OptionScanner::HideOptions()
{
	if(options_visible)
	{
		ui.frame->hide();
		options_visible = false;
		ui.cmdOptions->setText("Show Options");
	}
	else
	{
		ui.frame->show();
		options_visible = true;
		ui.cmdOptions->setText("Hide Options");
	}
}

void OptionScanner::RemoveFilter()
{
	int a = ui.listWidgetFilters->selectedItems().count() ;
	if(a>0)
	{
		std::string indicator = ui.listWidgetFilters->currentItem()->text().toStdString();

		using namespace qi;
		std::vector<std::string> filter_vect;//0 contains the column name,1 contains the operator , 2 contains the filter value
		boost::spirit::qi::parse(indicator.begin(), indicator.end(), *~char_(" ") >> *(' ' >> *~char_(" ")) ,filter_vect);

		FilterModelOptionTable->RemoveFilterFromColumn(ColumnNameNos[filter_vect[0]],ModelOptions);

		FilterModelOptionTable->setSourceModel(ModelOptions);

		int row = ui.listWidgetFilters->row(ui.listWidgetFilters->currentItem());
		ui.listWidgetFilters->takeItem(row);
	}
	else
	{
		QMessageBox::information(this,"No filter to remove","Please select a filter to remove");
	}
}


/*
void OptionScanner::TestLayout()
{
	FilterModelOptionTable->sort(1,Qt::AscendingOrder);
	//FilterModelOptionTable->sort(2,Qt::DescendingOrder);
	FilterModelOptionTable->setSourceModel(ModelOptions);
}
*/

void OptionScanner::ShowDefaultSubsciptionColumns()
{
	std::vector<std::string> dflt;
	dflt.push_back("Underline");
	dflt.push_back("ExpDate");
	dflt.push_back("Strike");
	dflt.push_back("Bid");
	dflt.push_back("Ask");
	dflt.push_back("DailyTrades");
	dflt.push_back("DailyVolume");

	for(int i=0; i<Column_Model->rowCount(); ++i)
	{
	    if(std::find(dflt.begin(),dflt.end(),Column_Model->item(i,0)->text().toStdString()) == dflt.end())
		{
	       Column_Model->item(i,1)->setCheckState(Qt::CheckState::Checked);
		   FilterColumn(Column_Model->item(i,1));
		}
	}
}//End Method

void OptionScanner::saveLayout()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),"c:\\OExpression",tr("Entry Files (*.entry)"));

	OptionScannerLayout lout;

	//Save the columns that were checked
	lout.SaveColumnToHideVector(FilterModelOptionTable->GetHideCoulmnCollection());

	//-----------------------------------------------------------------------------------------
	//Save the Expression Filters that were checked
	//-----------------------------------------------------------------------------------------
	lout.SaveExpressionFilterMap(FilterModelOptionTable->GetFilterExpressionCollection());
	
	//------------------------------------------------------------------------------------------
	//Save the current column orders to a string which will be serialized to UTF-16
	//------------------------------------------------------------------------------------------
	OptionsColOrder= ui.tableSubscription->horizontalHeader()->saveState();
	QByteArray compressed = qCompress(OptionsColOrder, 1);
	QByteArray hexed = compressed.toHex();
	QString str(hexed); //Convert to string
	lout.SaveHeaderView(str.toStdString());

	//------------------------------------------------------------------------------------------
	//Serialize the object to a string and save
	//------------------------------------------------------------------------------------------
	std::stringstream ss;
	boost::archive::text_oarchive oa(ss); 
	oa << lout;
	std::string serialized_object = ss.str();

	if(filename!="")
	{
		//Save the columns and the expression
		std::ofstream EntrySavedFile (filename.toStdString());
		if (EntrySavedFile.is_open())
		{
			EntrySavedFile << serialized_object;
			EntrySavedFile.close();
		}
	}
	else
	{
		//User did not enter a file name and pressed cancel
		return;
	}

	QMessageBox::information(this,"Layout saved","Layout has been saved",QMessageBox::StandardButton::Ok);
}

void OptionScanner::LoadLayout()
{
	OptionScannerLayout qobj;
	QStringList filename = QFileDialog::getOpenFileNames(this, tr("Load File"),"c:\\",tr("Option Scanner Entry Files (*.entry)"));

	if(filename.size() > 0)
	{
		std::ifstream iFile(filename[0].toStdString());
		std::string line;
		std::string ActualString;
		while(getline(iFile, line)) 
		{
			if(line != "" )
			{
				ActualString = ActualString + line;
				
			} 
		}

		//De-serialize the string
		std::stringstream serstream(ActualString);
		boost::archive::text_iarchive ia(serstream);
		ia >> qobj;

		iFile.close();
	}
	else
	{
		return;
	}
	//Now load the properties up
	//Reload the columns to display that were saved.
	
	//First un-check the existing checked columns (if any)
	for(int i=0  ; i< Column_Model->rowCount(); i++)
	{
		Column_Model->item(i,1)->setCheckState(Qt::CheckState::Unchecked);
	}

	//Now add the checked columns
    std::vector<int> temp = qobj.RetrieveColumnToHideVector();
	for(int i=0 ; i<temp.size() ;i++)
	{
		QList<QStandardItem*> lst = Column_Model->findItems(ReturnColumnName(temp[i]).c_str(),Qt::MatchExactly,0);
		if(lst.size()>0)
		{
			Column_Model->item(lst[0]->row(),1)->setCheckState(Qt::CheckState::Checked);
		}
	}

	//Load the expression filter
	AddNewFilter(qobj.RetrieveExpressionFilterMap());

	//Load the column order 
	QString strba = QString(qobj.ReturnHeaderViewString().c_str());
	QByteArray readCompressed = QByteArray::fromHex(strba.toAscii());
	QByteArray readDecompressed = qUncompress(readCompressed);
	ui.tableSubscription->horizontalHeader()->restoreState(readDecompressed);
}


std::string OptionScanner::ReturnColumnName(int i)
{
 for(std::map<std::string,int>::iterator it = ColumnNameNos.begin() ; it!=ColumnNameNos.end();it++)
 {
	 if(it->second == i)
	 {
		 return it->first;
	 }
 }
}

//This method is only called when an attempt to restore the 
//Layout is made - This method handles the filter section
void OptionScanner::AddNewFilter(std::map<int,std::string>& FilterExpression)
{
    //Save the filter in to the Proxy Model	
	FilterModelOptionTable->SetFilterExpressionFromLayout(FilterExpression);
	
	//Also display it in the ListBox
	for(std::map<int,std::string>::iterator it = FilterExpression.begin(); it!=FilterExpression.end();++it)
	{
		ui.listWidgetFilters->addItem(QString(it->second.c_str()).replace("_"," "));
	}
	
	FilterModelOptionTable->setSourceModel(ModelOptions);
}


void OptionScanner::AddNewFilter()
{
	//Save the column order before doing anything
	std::string indicator = ui.comboBoxIndicatorName->currentText().toStdString();
	std::string operation = ui.comboBoxOperation->currentText().toStdString();
	std::string destination,displayedstring,delimstring;
	std::string exta,extb;
	
	if(operation != "<>" && operation != "<=>" )
	{
		destination = ui.lineEditPassValue->text().toStdString();
		displayedstring = indicator + " " + operation + " " + destination;
		delimstring = indicator + "_" + operation + "_" + destination;
		ui.lineEditPassValue_ext1->setText("");
		ui.lineEditPassValue_ext2->setText("");
	}
	else
	{
		exta = ui.lineEditPassValue_ext1->text().toStdString();
		extb = ui.lineEditPassValue_ext2->text().toStdString();
		displayedstring = indicator + " " + operation + " " + exta + " " + extb;
		delimstring = indicator + "_" + operation + "_" +  exta + "_" + extb;
	}

	ui.listWidgetFilters->addItem(displayedstring.c_str());

	//Add the displayed string and delimited string to the mapper
	FilterModelOptionTable->AddFilterToColumn(ColumnNameNos[indicator],delimstring,ModelOptions);

	FilterModelOptionTable->setSourceModel(ModelOptions);
}

void OptionScanner::FilterColumn(QStandardItem* p)
{
	//A request for displaying or hiding a column is made
	std::string col_name = Column_Model->item(p->row(),0)->text().toStdString();
	if( p->checkState()==Qt::Checked)
	{
		//Hide the column
		FilterModelOptionTable->FilterSpecificColumn(ColumnNameNos[col_name]);
		FilterModelOptionTable->setSourceModel(ModelOptions);
	}
	else
	{
		//Un-hide the column
		FilterModelOptionTable->UndoFilterSpecificColumn(ColumnNameNos[col_name]);
		FilterModelOptionTable->setSourceModel(ModelOptions);
	}//end Else
}

void OptionScanner::PopulateFilterOptions()
{
	std::map<std::string,int>::iterator it;
	//Populate the drop down Indicator name
	for(it=ColumnNameNos.begin();it!=ColumnNameNos.end();it++)
	{
		ui.comboBoxIndicatorName->addItem(it->first.c_str());
	}

	//Populate the binary options
	ui.comboBoxOperation->addItem(">=");
	ui.comboBoxOperation->addItem(">");
	ui.comboBoxOperation->addItem("<=");
	ui.comboBoxOperation->addItem("<");
	ui.comboBoxOperation->addItem("=");
	ui.comboBoxOperation->addItem("!=");
	ui.comboBoxOperation->addItem("<>");
	ui.comboBoxOperation->addItem("<=>");
}


void OptionScanner::PopulateColumnComboBox()
{
	Column_Model->clear();
    
	QStringList labels;

	labels.push_back("Column Name");
	labels.push_back("Hide");;
	
	Column_Model->setHorizontalHeaderLabels(labels);

	for(std::map<std::string,int>::iterator it = ColumnNameNos.begin();it!=ColumnNameNos.end();it++)
	{
		QStandardItem* col_name = new QStandardItem();
		col_name->setText(it->first.c_str());
		col_name->setEditable(false);

		QStandardItem* chk = new QStandardItem();
		chk->setCheckable(true);
		chk->setCheckState(Qt::Unchecked);
		chk->setEditable(false);

		QList<QStandardItem*> lst;
		lst.push_back(col_name);
		lst.push_back(chk);

		Column_Model->appendRow(lst);
	}
	ui.tableViewColumnsFilter->setModel(Column_Model);
}


void OptionScanner::RetrieveAllOptions()
{
	if(!bConnect) //Not Connected
	{
		SubscribeToOptionTopic("ParameterNoUse", "ParameterNoUse");
		ui.cmdConnect->setText("Disconnect");
	}
	else
	{
		//Open up another instance and close this one
		Eclipse::EclipsePtr->DisplayOptionScanner();
		this->close();
	}
	bConnect =!bConnect;
}


void OptionScanner::SubscribeToOptionTopic(std::string symbol, std::string topic)
{
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->ConnectToWOPRBroadcast();
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->SubscribeToOptionTopic(symbol,topic,this);
}

void OptionScanner::UnSubscribeFromTopic(std::string symbol)
{
	Framework::NEclipse::QpidSubscriber::GetQpidInstance()->UnSubscribeFromTopic(symbol,this);
}

std::string OptionScanner::getFormGUID()
{
	return FormGUID;
}

void OptionScanner::InitiateOptionScanner()
{
	SubscribedSymbols = db.GetAllOptions();
	//Sort the symbols so you do a binary search on the vector
	std::sort(SubscribedSymbols.begin(),SubscribedSymbols.end());
}

void OptionScanner::InitializeOptionModel()
{
	int i=0;

	ModelOptions =new QStandardItemModel();
	Column_Model = new QStandardItemModel();

	//-------------------------------------------------------
	//Add the column names in a map so they can be used later
	//-------------------------------------------------------
	ColumnNameNos["Symbol"]=i; i++;      //0
	ColumnNameNos["TradePrice"]=i; i++;  //1
	ColumnNameNos["TradeVolume"]=i; i++; //2
	ColumnNameNos["Bid"]=i; i++;         //3
	ColumnNameNos["BidSize"]=i; i++;     //4
	ColumnNameNos["Ask"]=i; i++;         //5   
	ColumnNameNos["Ask Size"]=i; i++;    //6
	ColumnNameNos["DailyVolume"]=i; i++;  //7
	ColumnNameNos["DailyHigh"]=i; i++;    //8
	ColumnNameNos["DailyLow"]=i; i++;     //9
	ColumnNameNos["DailyTrades"]=i; i++;  //10
	ColumnNameNos["TimeStamp"]=i; i++;    //11
	ColumnNameNos["OpenInterest"]=i; i++; //12
	ColumnNameNos["ExpDate"]=i; i++;      //13
	ColumnNameNos["Strike"]=i; i++;       //14 
	ColumnNameNos["Bid_Imp_volatility"]=i; i++; //15
	ColumnNameNos["Ask_Imp_volatility"]=i; i++;  //16
	ColumnNameNos["MP_Imp_volatility"]=i; i++;   //17
	ColumnNameNos["Exp_Time_Left"]=i; i++;    //18
	ColumnNameNos["Underline"]=i; i++;    //19
	ColumnNameNos["BidTrade"]=i; i++;      //20
	ColumnNameNos["AskTrade"]=i; i++;      //21
	ColumnNameNos["NTrade"]=i; i++;        //22
	ColumnNameNos["Bid Volume"]=i; i++;    //23
	ColumnNameNos["Ask Volume"]=i; i++;    //24
	ColumnNameNos["N Volume"]=i; i++;      //25

	ColumnNameNos["PutCall"]=i; i++;      //26

	QStringList labels;

	labels.push_back("Symbol");
	labels.push_back("TradePrice");
	labels.push_back("TradeVolume");
	labels.push_back("Bid");
	labels.push_back("BidSize");
	labels.push_back("Ask");
	labels.push_back("Ask Size");
	labels.push_back("DailyVolume");
	labels.push_back("DailyHigh");
	labels.push_back("DailyLow");
	labels.push_back("DailyTrades");
	labels.push_back("TimeStamp");
	labels.push_back("OpenInterest");
	labels.push_back("ExpDate");
	labels.push_back("Strike");
	labels.push_back("Bid_Imp_volatility");
	labels.push_back("Ask_Imp_volatility");
	labels.push_back("MP_Imp_volatility");
	labels.push_back("Exp_Time_Left");
	labels.push_back("Underline");
	labels.push_back("BidTrade");
	labels.push_back("AskTrade");
	labels.push_back("NTrade");
	labels.push_back("BidVolume");
	labels.push_back("AskVolume");
	labels.push_back("NVolume");

	labels.push_back("PutCall");

	ModelOptions->setHorizontalHeaderLabels(labels); //Labels for the columns
	ui.tableSubscription->horizontalHeader()->setMovable(true); 
	FilterModelOptionTable->setSourceModel(ModelOptions);
	ui.tableSubscription->setModel(FilterModelOptionTable);
	ui.tableSubscription->setSortingEnabled(true); //Allow user to resort the columns

	PopulateColumnComboBox();
	PopulateFilterOptions();

	ShowDefaultSubsciptionColumns();

}//End Method

void OptionScanner::ManageTableUpdates(Serializable::OptionTick_ser otick)
{  
	//Check if this form even needs this update
	//-----------------------------------------------------------------------------------------------
	if(!std::binary_search(SubscribedSymbols.begin(),SubscribedSymbols.end(),otick.symbol())) return;
	//-----------------------------------------------------------------------------------------------

	QList<QStandardItem*> lst = ModelOptions->findItems(otick.symbol().c_str(),Qt::MatchExactly,0);
	if(lst.count()>0)
	{
		//Item Found - Update it
		UpdateExistingOption(otick,lst[0]->row());
		
	}
	else
	{
		AddNewOption(otick);
		//boost::thread t (boost::bind(&OptionScanner::AddNewOption,this,otick) );   //start in a distinct thread
	}
}


std::string OptionScanner::ConvertIntToString(int a)
{
	return QString::number(a).toStdString();
}

std::string OptionScanner::Roundfloat(float a)
{
	std::stringstream sout;
	std::string str;
	sout << std::fixed << std::setprecision(2) << a;
	sout >> str;   
	return str;
}

void OptionScanner::AddNewOption(Serializable::OptionTick_ser& otick)
{
	if(otick.symbol()=="") return;
	QStandardItem* item_symbol           =  new QStandardItem(otick.symbol().c_str());                               //Symbol
	QStandardItem* item_tradeprice       =  new QStandardItem(Roundfloat(otick.tradeprice()).c_str());               //TradePrice              
	QStandardItem* item_tradevolume      =  new QStandardItem(ConvertIntToString(otick.tradeprice()).c_str());       //TradeVolume                      
	QStandardItem* item_bid              =  new QStandardItem(Roundfloat(otick.bid()).c_str());					     //Bid
	QStandardItem* item_ask              =  new QStandardItem(Roundfloat(otick.ask()).c_str());					     //Ask
	QStandardItem* item_bid_size         =  new QStandardItem(ConvertIntToString(otick.bidsize()).c_str());          //BidSize
	QStandardItem* item_ask_size         =  new QStandardItem(ConvertIntToString(otick.asksize()).c_str());          //AskVolume
	QStandardItem* item_daily_volume     =  new QStandardItem(ConvertIntToString(otick.dailyvolume()).c_str());      //DailyVolume
	QStandardItem* item_daily_high       =  new QStandardItem(Roundfloat(otick.dailyhigh()).c_str());				 //DailyHigh
	QStandardItem* item_daily_low        =  new QStandardItem(Roundfloat(otick.dailylow()).c_str());				 //DailyLow
	QStandardItem* item_daily_trades     =  new QStandardItem(ConvertIntToString(otick.dailytrades()).c_str());      //DailyTrades  
	QStandardItem* item_time_stamp       =  new QStandardItem(otick.timestamp().c_str());							 //TimeStamp  
	QStandardItem* item_open_interest    =  new QStandardItem(ConvertIntToString(otick.openinterest()).c_str());     //OpenInterest
	QStandardItem* item_exp_date         =  new QStandardItem(otick.expdate().c_str());								 //ExpDate
	QStandardItem* item_strike           =  new QStandardItem(Roundfloat(otick.strike()).c_str());				     //Strike
	QStandardItem* item_bid_impl_volat   =  new QStandardItem(Roundfloat(otick.bid_imp_volatility()).c_str());       //BidImpVolat
	QStandardItem* item_ask_imp_volat    =  new QStandardItem(Roundfloat(otick.ask_imp_volatility()).c_str());       //ASkImpVolat
	QStandardItem* item_mp_impl_volat    =  new QStandardItem(Roundfloat(otick.mp_imp_volatility()).c_str());        //MPImpVolat
	QStandardItem* item_exp_time_left    =  new QStandardItem(Roundfloat(otick.exp_time_left()).c_str());		 	 //ExpTimeLeft
	QStandardItem* item_underline        =  new QStandardItem(::Eclipse::SymbUnderline[otick.symbol()].c_str());	 //Underline
	QStandardItem* item_bid_trade        =  new QStandardItem(ConvertIntToString(otick.bidtrade()).c_str());         //BitTrade
	QStandardItem* item_asktrade         =  new QStandardItem(ConvertIntToString(otick.asktrade()).c_str());         //AskTrade
	QStandardItem* item_ntrade			 =  new QStandardItem(ConvertIntToString(otick.ntrade()).c_str());           //NTrade
	QStandardItem* item_bidvol			 =  new QStandardItem(ConvertIntToString(otick.bidvol()).c_str());           //BidVol
	QStandardItem* item_askvol			 =  new QStandardItem(ConvertIntToString(otick.askvol()).c_str());           //AskVol
	QStandardItem* item_nvol			 =  new QStandardItem(ConvertIntToString(otick.nvol()).c_str());             //NVol
	QStandardItem* item_putCall			 =  new QStandardItem("--");								                 //PutCall


	QList<QStandardItem*> lst ;
	lst.push_back(item_symbol);
	lst.push_back(item_tradeprice);
	lst.push_back(item_tradevolume);
	lst.push_back(item_bid);
	lst.push_back(item_ask);
	lst.push_back(item_bid_size);
	lst.push_back(item_ask_size);
	lst.push_back(item_daily_volume);
	lst.push_back(item_daily_high);
	lst.push_back(item_daily_low);
	lst.push_back(item_daily_trades);
	lst.push_back(item_time_stamp);
	lst.push_back(item_open_interest);
	lst.push_back(item_exp_date);
	lst.push_back(item_strike);
	lst.push_back(item_bid_impl_volat);
	lst.push_back(item_ask_imp_volat);
	lst.push_back(item_mp_impl_volat);
	lst.push_back(item_exp_time_left);
	lst.push_back(item_underline);
	lst.push_back(item_bid_trade);
	lst.push_back(item_asktrade);
	lst.push_back(item_ntrade);
	lst.push_back(item_bidvol);
	lst.push_back(item_askvol);
	lst.push_back(item_nvol);

	lst.push_back(item_putCall);
	ModelOptions->appendRow(lst);
}

void OptionScanner::UpdateExistingOption(Serializable::OptionTick_ser& otick, int rowno)
{
	
	int i=1;
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.tradeprice()).c_str());  i++ ;            //TradePrice
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.tradevolume()).c_str());  i++ ;   //TradeVolume
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.bid()).c_str()); i++ ;                    //Bid
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.bidsize()).c_str()); i++ ;        //BidSize
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.ask()).c_str()); i++ ;                    //Ask
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.asksize()).c_str());  i++ ;       //AskSize
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.dailyvolume()).c_str());  i++ ;   //DailyVolume
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.dailyhigh()).c_str());  i++ ;             //DailyHigh
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.dailylow()).c_str());  i++ ;				//DailyLow
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.dailytrades()).c_str());  i++ ;   //DailyTrades
	ModelOptions->item(rowno,i)->setText(otick.timestamp().c_str());  i++ ;							//TimeStamp
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.openinterest()).c_str()); i++ ;   //OpenInterest
	ModelOptions->item(rowno,i)->setText(otick.expdate().c_str()); i++ ;							//ExpDate
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.strike()).c_str()); i++ ;                 //Strike
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.bid_imp_volatility()).c_str());   i++ ;   //BidImpVolat
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.ask_imp_volatility()).c_str());   i++ ;   //ASkImpVolat
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.mp_imp_volatility()).c_str());    i++ ;   //MPImpVolat
	ModelOptions->item(rowno,i)->setText(Roundfloat(otick.exp_time_left()).c_str()); i++ ;          //ExpTimeLeft
	ModelOptions->item(rowno,i)->setText(::Eclipse::SymbUnderline[otick.symbol()].c_str()); i++ ;   //Underline

	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.bidtrade()).c_str());  i++ ;      //BidTrade
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.asktrade()).c_str());  i++ ;      //AskTrade  
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.ntrade()).c_str());  i++ ;        //NTrade
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.bidvol()).c_str());  i++ ;        //BidVol
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.askvol()).c_str());  i++ ;        //AskVol
	ModelOptions->item(rowno,i)->setText(ConvertIntToString(otick.nvol()).c_str());  i++ ;          //NVol
	ModelOptions->item(rowno,i)->setText("--");  i++ ;          //PutCall
}

void OptionScanner::HighlightSymbol()
{
	std::string symb = ui.lineEditSearch->text().toStdString();
	boost::algorithm::to_upper(symb);
	if(symb!="")
	{
		QList<QStandardItem*> lst = ModelOptions->findItems(symb.c_str(),Qt::MatchExactly,0);
		if(lst.count()>0)
		{
			ui.tableSubscription->selectRow(lst[0]->row());
			QModelIndex ind = ModelOptions->index(lst[0]->row(),0);
			ui.tableSubscription->scrollTo(ind);
		}
		else
		{
			QMessageBox::information(this,"Not Found", "The item is not present in the table - Have you subscribed to it ?");
		}
	}

}