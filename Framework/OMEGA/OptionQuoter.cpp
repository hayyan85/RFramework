#include "OptionQuoter.h"
#include "QStandardItemModel"
#include "OptionTick.pb.h"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include "Network.h"
#include "omega.h"
#include "Filter.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <intrin.h>
#include "QMessageBox"
#include "RTypes.pb.h"
#include "Utility.h"
#include "External.h"
#include <Windows.h>
#include "omega.h"
#include "QMenu"
#include "QFileDialog"
#include <fstream>
#include "SPX_Algo1_Neutral.h"
#include <QDateTime>

OptionQuoter::OptionQuoter(QWidget *parent, Qt::WFlags flags): QMainWindow(parent, flags)
{
	BHideFilter = false;
	BHideConsole = false;
	BHideUpdates = false;
	StartQuoter = false;

	ui.setupUi(this);
	symbol_load_inst = NULL;

	//---------------------------------------------------------------------------------
	ConstructToolTip();
	ui.cmdTestExpression->setVisible(false);
	ui.TableExpressionTester->setVisible(false);
	ModelOptionQuoter = new QStandardItemModel();
	ModelExchanges = new QStandardItemModel();
	ModelInputs = new QStandardItemModel();
	ModelOrderTracker = new QStandardItemModel();
	ModelExpressionTester = new QStandardItemModel();
	InitializeModel();
	//---------------------------------------------------------------------------------
	StartAutomationProcess = false;
	InternalAlgorithm = false;

	TimerEnableGUIDisplay = new QTimer();
	TimerEnableGUIDisplay->setInterval(1000);
	TimerEnableGUIDisplay->setSingleShot(true);

	FormGUID = boost::uuids::to_string(boost::uuids::random_generator()());
	Account = OMEGA::GetConfigValue("Account");
	this->Tif = OMEGA::GetConfigValue("Tif");
	QObject::connect(ui.cmdShowSymbols,SIGNAL(clicked()),this,SLOT(ShowSymbolList()));
		
	QObject::connect(ui.cmdStart,SIGNAL(clicked()),this,SLOT(ManageAutomation()));
	QObject::connect(ui.cmdPause,SIGNAL(clicked()),this,SLOT(PauseAutomation()));
		
	QObject::connect(ModelExchanges,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(ExchangeSelected(QStandardItem*)));
	QObject::connect(ModelOrderTracker,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(CancelOrderCheck(QStandardItem*)));
	QObject::connect(TimerEnableGUIDisplay, SIGNAL(timeout()), this, SLOT(TimerSlotEnableGUITimeOut()) );
	
	QObject::connect(ui.actionHide_Filters,SIGNAL(triggered()),this,SLOT(HideFilter()));
	QObject::connect(ui.action_Hide_Console,SIGNAL(triggered()),this,SLOT(HideConsole()));
	QObject::connect(ui.actionHide_Option_Updates,SIGNAL(triggered()),this,SLOT(HideUpdates()));


	QObject::connect(ui.cmdAddExpression,SIGNAL(clicked()),this,SLOT(AddExpressionFilter()));
	QObject::connect(ui.cmdAddColumn,SIGNAL(clicked()),this,SLOT(AddColumnToExpression()));
	QObject::connect(ui.cmdTestExpression,SIGNAL(clicked()),this,SLOT(TestExpression()));

	
	QObject::connect(ui.cmdSaveExpression,SIGNAL(clicked()),this,SLOT(SaveExpression()));
	QObject::connect(ui.cmdLoadExpression,SIGNAL(clicked()),this,SLOT(LoadExpression()));
	QObject::connect(ui.actionSpx_Algo1_Neutral,SIGNAL(triggered()),this,SLOT(Run_SPX_Algo1_NeutralAction()));
}

OptionQuoter::~OptionQuoter()
{
	::OMEGA::RemoveOptionQuoterForm(FormGUID);
}


void OptionQuoter::SaveExpression()
{

	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),"c:\\OExpression.entry");
    
	if(filename!="")
	{
		//Save the columns and the expression
		std::ofstream EntrySavedFile (filename.toStdString());
		if (EntrySavedFile.is_open())
		{
			for(int i=0 ; i<SelectedColumns.size() ; i++)
			{
				EntrySavedFile << SelectedColumns[i] << "\n";
			}

			EntrySavedFile << "FExpression: " << ui.lineEditFilterExpression->text().toStdString() <<  "\n";
			EntrySavedFile.close();
		}
	}
}


void OptionQuoter::LoadExpression()
{
	SelectedColumns.clear();
	ModelExpressionTester->clear();

	QStringList filename = QFileDialog::getOpenFileNames(this, tr("Load File"),"c:\\",tr("Omega Entry Files (*.entry)"));
	
	if(filename.size() > 0)
	{
		std::ifstream iFile(filename[0].toStdString());
		std::string line;


		while(getline(iFile, line)) 
		{
			if(line != "" )
			{
				 
				if(QString(line.c_str()).contains("FExpression:"))
				{
				    QString r_ = QString(line.c_str());
					r_.replace("FExpression:","");
					ui.lineEditFilterExpression->setText(r_);
				}
				else
				{
					AddColumnToExpression(line);
				}
			} 
		}
		iFile.close();
	}
}//End MEthod


void OptionQuoter::HideFilter()
{
	if(!BHideFilter)
	{
		ui.frameFilters->setVisible(false);
		ui.actionHide_Filters->setText("Show Filter");
	}
	else
	{
		ui.frameFilters->setVisible(true);
		ui.actionHide_Filters->setText("Hide Filter");
	}
	BHideFilter = !BHideFilter;
}


void OptionQuoter::HideConsole()
{
	if(!BHideConsole)
	{
		ui.listWidgetConsole->setVisible(false);
		ui.action_Hide_Console->setText("Show Output");
	}
	else
	{
		ui.listWidgetConsole->setVisible(true);
		ui.action_Hide_Console->setText("Hide Output");
	}
	BHideConsole =! BHideConsole;
}


void OptionQuoter::HideUpdates()
{
	if(!BHideUpdates)
	{
		ui.tableViewOptions->setVisible(false);
		ui.actionHide_Option_Updates->setText("Show Updates");
	}
	else
	{
		ui.tableViewOptions->setVisible(true);
		ui.actionHide_Option_Updates->setText("Hide Updates");
	}
	BHideUpdates =!BHideUpdates;
}//End Method


/*
//This method initializes the form setting
void OptionQuoter::InitializeFormSettings()
{
	ui.cmdStart->setEnabled(false);
	ui.cmdPause->setEnabled(false);
}
*/

void OptionQuoter::Run_SPX_Algo1_NeutralAction()
{
	InternalAlgorithm = true;
	InternalAlgorithmFunction = boost::bind(&OptionQuoter::Process_SPX_Algo1_Neutral,this);
	ui.lineEditFinalExpression->setText("Internal Algorithm : SPX ALOG1 NEUTRAL");
}


//Pause the Automation
void OptionQuoter::PauseAutomation()
{
	if(ui.cmdPause->text() == "Pause")
	{
		//Pause the automation
		AutomationPaused = true;
		PrintConsole(Other,"--------Automation Paused - Only Cancel Orders will be dispatched------");
		ui.cmdPause->setText("Resume");
	}
	else
	{
		//Pause the automation
		AutomationPaused = false;
		PrintConsole(Other,"--------Automation Resume - Both Cancel and New Orders will be dispatched------");
		ui.cmdPause->setText("Pause");
	}
}

void OptionQuoter::DisplayErrorMessage(std::string ErrorMsg)
{
	QMessageBox::information(this,"Error ", ErrorMsg.c_str());
}


void OptionQuoter::EnableDisableDisplay(bool type)
{
		ui.cmdShowSymbols->setEnabled(type);
		//ui.cmdStart->setEnabled(type);
		ui.tableViewExchanges->setEnabled(type);
		ui.tableViewInputs->setEnabled(type);
		ui.cmdLoadExpression->setEnabled(type);
		ui.cmdSaveExpression->setEnabled(type);
		
}

void OptionQuoter::ManageAutomation()
{
	if(!StartQuoter)
	{
		StartAutomation();
		ui.cmdStart->setText("Stop");
	}
	else
	{
		StopAutomation();
		ui.cmdStart->setText("Start");
	}

	StartQuoter =!StartQuoter;
}

void OptionQuoter::StartAutomation()
{
	if(ExchangesSelected.size()>0 && (expression_string!="" || InternalAlgorithm==true))
	{
		StartAutomationProcess = true;
		PrintConsole(Other,"Automation started ..");
	    EnableDisableDisplay(false);
		AutomationPaused = false;
		ui.cmdPause->setText("Pause");
	}
	else
	{
		QMessageBox::information(this,"Missing Requirements", "Please insert a filter or an internal algorithm and select an exchange");
	}
}

void OptionQuoter::StopAutomation()
{
	PrintConsole(MType::Other,"Attempting to STOP Automation..");

	StartAutomationProcess = false;

	//This clears the form up
	//PrintConsole(MType::Other,"Clearing all internal filter..");

	//Clear all Filters
	//ClearAllFilters();

	//Cancel All Pending Orders
	CancelAllPendingOrders();

	//We do not want to unsubscribe from all symbols
	//UnSubscribe From  all Symbols;
	//PrintConsole(MType::Other,"Unsubscribing from All Subscribed Symbols..");	
	//UnSubscribeFromAllSymbols();	
	TimerEnableGUIDisplay->start();
}


void OptionQuoter::ExchangeDataChanged( const QModelIndex & topLeft, const QModelIndex & bottomRight )
{/**/}

void OptionQuoter::ExchangeSelected(QStandardItem* itm)
{
	std::string col_name = ModelExchanges->item(itm->row(),0)->text().toStdString();

	if(ModelExchanges->item(itm->row(),1)->checkState()==Qt::Checked)
	{
		if(std::find(ExchangesSelected.begin(),ExchangesSelected.end(),col_name)==ExchangesSelected.end())
		{
			ExchangesSelected.push_back(col_name);
		}
	}
	else
	{
		ExchangesSelected.erase(std::find(ExchangesSelected.begin(), ExchangesSelected.end(), col_name));
	}
}



std::string OptionQuoter::getFormGUID()
{
	return FormGUID;
}

void OptionQuoter::SubscribeToTopic(std::string symbol , std::string topic)
{
	Framework::NOmega::QpidSubscriber::GetQpidInstance()->ConnectToWOPRBroadcast();
	Framework::NOmega::QpidSubscriber::GetQpidInstance()->SubscribeToTopic(symbol,topic,this);
}

void OptionQuoter::UnSubscribeFromTopic(std::string symbol)
{
	Framework::NOmega::QpidSubscriber::GetQpidInstance()->UnSubscribeFromTopic(symbol,this);
	
}

void OptionQuoter::InitializeModel()
{
	QStringList labels;
	labels.push_back("Type");
	labels.push_back("Symbol");
	labels.push_back("BidSize");
	labels.push_back("Bid");
	labels.push_back("Last");
	labels.push_back("Ask");
	labels.push_back("Ask Size");
	ModelOptionQuoter->setHorizontalHeaderLabels(labels); //Labels for the columns
	ui.tableViewOptions->setModel(ModelOptionQuoter);
}


//---------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------TABLE ORDER TRACKER MANAGER------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------



void OptionQuoter::InitializeOrderTrackerModel()
{
	QStringList labels;
	labels.push_back("OrderID");				//0
	labels.push_back("Side");                   //1   
	labels.push_back("Quantity");               //2
	labels.push_back("Price");                  //3
	labels.push_back("Destination");            //4
	labels.push_back("Sterling Code");          //5
	labels.push_back("SearchString");           //6 
	labels.push_back("Cancel Order");           //7
	ModelOrderTracker->setHorizontalHeaderLabels(labels); //Labels for the columns
	ui.tableViewOpenOrders->setModel(ModelOrderTracker);
}


//True means YES its an open order !!
bool OptionQuoter::CheckIfOpenOrder(Serializable::CustROrder_ser& opt)
{
	std::string srch = opt.side() + "-" + QString::number(opt.lmtprice(),'f',2).toStdString() + "-" + opt.bstrdestination();

	QList<QStandardItem*> lst = ModelOrderTracker->findItems(srch.c_str(),Qt::MatchFixedString,OrderTrackerColEnum::SearchString);
	
	if(lst.count()>0)
	{
		//Exists - extract the latest order code;
		int res = lst.count();
		for(int i=0 ; i < lst.count();i++)
		{
			int code = ModelOrderTracker->item(lst[i]->row(),OrderTrackerColEnum::Sterling_Code)->text().toDouble();

			if(code == -99 || code == -98 || code==1 || code==10 || code==13 || code== 14 || code== 0 )
			{
				return true;// YES!! Open Order // Do not send a new one out
			}

			else
			{
				std::string s = "Something different";
			}
		}//end for
		return false; //Not an open order - Ok to send another one..
	}//End if
	return false;
}//End method


void OptionQuoter::AdddNewOpenOrder(Serializable::CustROrder_ser& opt)
{

	QList<QStandardItem*> lst;
	/*
	labels.push_back("OrderID");				//0
	labels.push_back("Side");                   //1   
	labels.push_back("Quantity");               //2
	labels.push_back("Price");                  //3
	labels.push_back("Destination");            //4
	labels.push_back("Sterling Code");          //5
	labels.push_back("SearchString");           //6 
	*/

	std::string srch = opt.side() + "-" + QString::number(opt.lmtprice(),'f',2).toStdString() + "-" + opt.bstrdestination();
	
	QStandardItem* item_orderid   = new QStandardItem(opt.bstrclorderid().c_str());
	QStandardItem* item_side      = new QStandardItem(opt.side().c_str());
	QStandardItem* item_qunatity  = new QStandardItem( QString::number(opt.nquantity(),'f',2));
	QStandardItem* item_price     = new QStandardItem( QString::number(opt.lmtprice(),'f',2));;
	QStandardItem* item_dest      = new QStandardItem(opt.bstrdestination().c_str());
	QStandardItem* item_scode     = new QStandardItem( QString::number(opt.norderstatus())); //Sterling Code
	QStandardItem* item_hash      = new QStandardItem(srch.c_str());
	QStandardItem* item_cancel   =  new QStandardItem("Cancel Order");
	item_cancel->setCheckable(true);
	item_cancel->setCheckState(Qt::CheckState::Unchecked);
	

	lst.push_back(item_orderid);
	lst.push_back(item_side);
	lst.push_back(item_qunatity);
	lst.push_back(item_price);
	lst.push_back(item_dest);
	lst.push_back(item_scode);
	lst.push_back(item_hash);
	lst.push_back(item_cancel);

	int r = ModelOrderTracker->rowCount();
	ModelOrderTracker->appendRow(lst);	
}


void OptionQuoter::UpdateCancelExchange(Serializable::CustROrder_ser& rord)
{
  QList<QStandardItem*> lst = ModelExchanges->findItems(rord.bstrdestination().c_str(),Qt::MatchExactly,0);
  //Get Existing cancels
  int cancel_count = ModelExchanges->item(lst[0]->row(),3)->text().toInt();
  cancel_count++;
  ModelExchanges->item(lst[0]->row(),3)->setText(QString::number(cancel_count));
}


//EVENTS received hit at this slot
//The item is already suppose to be in the table at this point
void OptionQuoter::UpdateOpenOrder(Serializable::RUpdatePacket pkt)
{
	Serializable::CustROrder_ser opt = pkt.custord();
	Serializable::ExtraRFields ext ;
	ext.ParseFromString(Framework::Utility::CommnUtility().base64_decode(opt.bstruser()));
	

	if(ext.formid()!=FormGUID)
	{

		//PrintConsole(Other, "Event Ignored: Current FormID = " + FormGUID + "Event From GUID: " + ext.formid() + " ");
		return;
	}


	//Check if this was a Trade Update Event
	if(pkt.has_tupdate())
	{
		TradeUpdate(pkt.tupdate());
		return;
	}
	

	//No this was an order update Event
	QList<QStandardItem*> lst = ModelOrderTracker->findItems(opt.bstrclorderid().c_str(),Qt::MatchExactly,OrderTrackerColEnum::OrderID);
	
	if(lst.count()>0)
	{
		int row = lst[0]->row();

		//Update the table
		ModelOrderTracker->item(row,OrderTrackerColEnum::Sterling_Code)->setText(QString::number(opt.norderstatus(),'f',3).toStdString().c_str());  	//Sterling Code
		ModelOrderTracker->item(row,OrderTrackerColEnum::Quantity)->setText(QString::number(opt.nlvsquantity()).toStdString().c_str());  	            //Quantity
		
		//Assign colors on update
		if(opt.norderstatus()==10) //If partial fill
		{
			ModelOrderTracker->item(row,OrderTrackerColEnum::Quantity)->setBackground(Qt::yellow);
		}

		//Assign colors on update
		if(opt.norderstatus()==5) //If Full Fill Remove from the table
		{
			ModelOrderTracker->removeRow(lst[0]->row());
			std::string temp = "Order Filled : " + opt.bstrclorderid() + " - Removed from table - Time: " +  QTime::currentTime().toString("h:m:s ap").toStdString();
			PrintConsole(MType::OrderType,temp);
		}

		//Assign colors on update
		if(opt.norderstatus()==8) //If Cancelled Remove from the table
		{
			ModelOrderTracker->removeRow(lst[0]->row());
			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			//Provide cancel details
			std::string Details;
			Details = "QBid : " + QString::number(CancelDetailRecorder[opt.bstrclorderid().c_str()]->get_qbid(),'f',3).toStdString() +
					  " QAsk : " + QString::number(CancelDetailRecorder[opt.bstrclorderid().c_str()]->get_qask(),'f',3).toStdString() +
					  " Spread : " + QString::number(CancelDetailRecorder[opt.bstrclorderid().c_str()]->get_Spread(),'f',3).toStdString() +
					  " OrderSize : " + QString::number(CancelDetailRecorder[opt.bstrclorderid().c_str()]->get_OrdSize(),'f',3).toStdString() +
					  " AskSize : " + QString::number(CancelDetailRecorder[opt.bstrclorderid().c_str()]->get_AskSize(),'f',3).toStdString();

			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			std::string temp = "Order Cancelled : " + opt.bstrclorderid() + " - Removed from table " +  QTime::currentTime().toString("h:m:s ap").toStdString();
			UpdateCancelExchange(opt);
			PrintConsole(MType::CancelType,temp);
			PrintConsole(MType::CancelType,"Details of Canceled Order : " + Details);
		}
		
	}//end if
}//End method


//This method simply updates the trade
void OptionQuoter::TradeUpdate(const Serializable::TradeUpdate& tupd)
{
	int new_pos;
	int pos = ModelInputs->item(InputRows::Current_Pos,1)->text().toInt();
	if(tupd.side()=="S")
	{
		
		new_pos =  pos - tupd.volume();
		ModelInputs->item(InputRows::Current_Pos,1)->setText(QString::number(new_pos));
	}
	else
	{
		new_pos =  pos + tupd.volume();
		ModelInputs->item(InputRows::Current_Pos,1)->setText(QString::number(new_pos));
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------END SECTION---------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------



void OptionQuoter::PrintConsole(MType mt,std::string str)
{
	str +=  " Time : " +  QTime::currentTime().toString("h:m:s ap").toStdString();
	ui.listWidgetConsole->addItem(str.c_str());
	ui.listWidgetConsole->scrollToBottom();
	

	if(mt==MType::OrderType)
	{
		ui.listWidgetConsole->item(ui.listWidgetConsole->count()-1)->setForeground(Qt::white);
		ui.listWidgetConsole->item(ui.listWidgetConsole->count()-1)->setBackgroundColor(Qt::blue);
	}

	if(mt==MType::CancelType)
	{
		ui.listWidgetConsole->item(ui.listWidgetConsole->count()-1)->setForeground(Qt::black);
		ui.listWidgetConsole->item(ui.listWidgetConsole->count()-1)->setBackgroundColor(Qt::red);
	}

	if(mt==MType::Other)
	{
		ui.listWidgetConsole->item(ui.listWidgetConsole->count()-1)->setForeground(Qt::darkCyan);
	}
}



//Display the Inputs
void OptionQuoter::DisplayInputs()
{
	ModelInputs->clear();
	QList<std::string> description ;
	QStringList headerlst ;

	headerlst << "Criteria" << "Input" ; 

	description << "Max Pos" << "Current Pos" << "Max Bid" << "Max Offer" << "Min Offer";

	ModelInputs->setHorizontalHeaderLabels(headerlst); //Labels for the columns
	for(int i=0;i<5;i++)
	{
		QList<QStandardItem*> lst ;
		QStandardItem* item_desc   = new QStandardItem(description[i].c_str());
		QStandardItem* item_input  = new QStandardItem("0");
		lst.push_back(item_desc);
		lst.push_back(item_input);
		ModelInputs->appendRow(lst);
	}
	ui.tableViewInputs->setModel(ModelInputs);
}



//Display the exchanges
void OptionQuoter::DisplayExchanges()
{
	ModelExchanges->clear(); 

	QList<std::string> exchlst ;
	QStringList headerlst ;
	
	headerlst << "Exchange" << "Run" << "Max Cxls" << "Tot Cxls" << "OrdSize";

	exchlst << "BATS" << "PHLX" << "PSEX" 
		    << "NASD" << "BOX"  << "ISE"
			<< "C2"   << "CBOE" << "AMEX" 
			<< "MIAX" << "GEMINI" ;
	
	ModelExchanges->setHorizontalHeaderLabels(headerlst); //Labels for the columns
	for(int i=0;i<11;i++)
	{
		QList<QStandardItem*> lst ;
		QStandardItem* item_exchange = new QStandardItem(exchlst[i].c_str());
		QStandardItem* item_checked  = new QStandardItem();
		item_checked->setCheckable(true);
		item_checked->setCheckState(Qt::CheckState::Unchecked);
		QStandardItem* item_max_cxls  = new QStandardItem("10");
		QStandardItem* item_tot_cxls  = new QStandardItem("0");
		QStandardItem* item_order_size  = new QStandardItem("0");
		lst.push_back(item_exchange);
		lst.push_back(item_checked);
		lst.push_back(item_max_cxls);
		lst.push_back(item_tot_cxls);
		lst.push_back(item_order_size);
		ModelExchanges->appendRow(lst);
	}

	ui.tableViewExchanges->setModel(ModelExchanges);
}

//Remove Symbol From Model
void OptionQuoter::RemoveSymbolFromModel(std::string symbol)
{
	bool t; 
	QList<QStandardItem*> lst = ModelOptionQuoter->findItems(symbol.c_str(),Qt::MatchExactly,1);
	if(lst.count()>0)
	{
		t = ModelOptionQuoter->removeRow(lst[0]->row());
	}	
}


//Return the orders from the exchanges - this is changed by the user keyboard input
void OptionQuoter::GetExchangeDetails(std::string& exchange_name,int &OrderSize, int& MaxCancel , int& TotalCancel)
{
		QList<QStandardItem*> lst  = ModelExchanges->findItems(exchange_name.c_str(),Qt::MatchExactly,0);
		if(lst.size() > 0)
		{
		int row = lst[0]->row();
		OrderSize =  ModelExchanges->item(row,4)->text().toFloat();
		MaxCancel = ModelExchanges->item(row,2)->text().toFloat();
		TotalCancel = ModelExchanges->item(row,3)->text().toFloat();
		}
}


bool OptionQuoter::SendOptionOrder(float& Qbid,float& Qask)
{
	Serializable::CustROrder_ser corder;
	//Extract the name of QType Symbol
	std::string option_symbol = symbol_load_inst->symbolTypeMap["Q"];
	std::string underlying_symbol = OMEGA::SymbAndUnderlying[option_symbol];
	std::string sterling_equivalent_symbol = OMEGA::IQSterlingEquivalent[option_symbol];
	
	//------------------QUICK HACK FOR FIXING THE UNDERLYING SYMBOL OF ONLY SPX--------------------
	QString under(underlying_symbol.c_str());
	if(under.contains("SPX"))
	{
		underlying_symbol = "$SPX";
	}
	//---------------------------------------------------------------------------------------------

	//Iterate through all the exchanges
	for(int i=0;i<ExchangesSelected.size();i++)
	{
		
		int quantity;
		int MaxCancel;
		int TotalCancel;
		std::string ExchangeName = ExchangesSelected[i];
		GetExchangeDetails(ExchangeName,quantity,MaxCancel,TotalCancel);
		if(TotalCancel < MaxCancel )
		{
			    Serializable::ExtraRFields efields;
			    
				corder.set_lmtprice(Qbid);
				corder.set_nquantity(quantity);
				corder.set_tif(Tif);
				corder.set_bstraccount(Account);
				corder.set_bstrdestination(ExchangeName);
				corder.set_bstrclorderid(boost::uuids::to_string(boost::uuids::random_generator()()));
				corder.set_pricetype(Serializable::CustROrder_ser::EPriceType::CustROrder_ser_EPriceType_Lmt); //Fixed
				corder.set_side("B");
				corder.set_bstrsymbol(sterling_equivalent_symbol);
				corder.set_underlying(underlying_symbol);
			
				//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				//---------------------------SMALL HACK FOR TESTING SINCE SYMBOL NAMES IS CHANGED ON THE EXECUTION ENGINE LETS CANGE IT HERE TOO----------------------------------------------
				//scorder.set_bstrsymbol("BAC 130830C13500");
				//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


				corder.set_norderstatus(-99);

				//-------------------------------------------------------------------------------
				//---------------ADDITIONAL OPTION FIELD REQUIREMENTS----------------------------
				corder.set_cust_ordercategory("O");    //Fixed Open for now
				corder.set_instrument("O");
				corder.set_maturity(symbol_load_inst->Maturity);
				corder.set_putcall(symbol_load_inst->CallPut);
				corder.set_strikeprice(symbol_load_inst->strike);
				//-------------------------------------------------------------------------------
				//-------------------------------------------------------------------------------

				//-------------------------------------------------------------------------------
                //---------------SETUP EXTRA FIELDS THAT ARE RETURNED WITH UPDATE ORDER----------
				efields.set_formid(FormGUID);
				efields.set_ordertype("N");  //Can be a new (N) or (C) cancel
				std::string ser_string = efields.SerializeAsString();
				ser_string = Framework::Utility::CommnUtility().base64_encode(reinterpret_cast<const unsigned char*>(ser_string.c_str()), ser_string.length());
				corder.set_bstruser(ser_string);
				//-------------------------------------------------------------------------------
				
				if(corder.nquantity()==0)
				{
					return false;
				}

				//Send the order Immediately after checking
				//Check if Such an order is already open - Send if false
				if(!CheckIfOpenOrder(corder) && !AutomationPaused) //Make Sure the Automation is not Paused (By default when Automation starts its not paused)
				{
					//Add to the table
					PrintConsole(MType::OrderType,"New Order Dispatched");
					//ui.listWidgetConsole->addItem("New Order Dispatched."); ui.listWidgetConsole->scrollToBottom();
					
					AdddNewOpenOrder(corder);

					//Send to NetWork Immediately
					Framework::NOmega::QpidSubscriber::GetQpidInstance()->SendOptionOrder(corder);
				}
		}
		else
		{
			PrintConsole(MType::Other, "Cannot Send a new order - Maximum Cancel Allowed Exceeded.");
			return false;
		}
	}
	return true;
}//End Method

void OptionQuoter::SendCustomOptionOrder(const float& Qbid,const std::string Exch,const int& ordsize)
{
	Serializable::CustROrder_ser corder;

	//Extract the name of QType Symbol
	std::string option_symbol = symbol_load_inst->symbolTypeMap["Q"];
	std::string underlying_symbol = OMEGA::SymbAndUnderlying[option_symbol];
	std::string sterling_equivalent_symbol = OMEGA::IQSterlingEquivalent[option_symbol];

	//------------------QUICK HACK FOR FIXING THE UNDERLYING SYMBOL OF ONLY SPX--------------------
	QString under(underlying_symbol.c_str());
	if(under.contains("SPX"))
	{
		underlying_symbol = "$SPX";
	}
	//---------------------------------------------------------------------------------------------

		int quantity;
		int MaxCancel;
		int TotalCancel;
		std::string ExchangeName = Exch;
		
		//Get the max cancel and total cancel
		GetExchangeDetails(ExchangeName,quantity,MaxCancel,TotalCancel);
		if(TotalCancel < MaxCancel )
		{
			Serializable::ExtraRFields efields;

			corder.set_lmtprice(Qbid);
			corder.set_nquantity(ordsize);
			corder.set_tif(Tif);
			corder.set_bstraccount(Account);
			corder.set_bstrdestination(ExchangeName);
			corder.set_bstrclorderid(boost::uuids::to_string(boost::uuids::random_generator()()));
			corder.set_pricetype(Serializable::CustROrder_ser::EPriceType::CustROrder_ser_EPriceType_Lmt); //Fixed
			corder.set_side("B");
			corder.set_bstrsymbol(sterling_equivalent_symbol);
			corder.set_underlying(underlying_symbol);
			corder.set_norderstatus(-99);

			//-------------------------------------------------------------------------------
			//---------------ADDITIONAL OPTION FIELD REQUIREMENTS----------------------------
			corder.set_cust_ordercategory("O");    //Fixed Open for now
			corder.set_instrument("O");
			corder.set_maturity(symbol_load_inst->Maturity);
			corder.set_putcall(symbol_load_inst->CallPut);
			corder.set_strikeprice(symbol_load_inst->strike);
			//-------------------------------------------------------------------------------
			//-------------------------------------------------------------------------------

			//-------------------------------------------------------------------------------
			//---------------SETUP EXTRA FIELDS THAT ARE RETURNED WITH UPDATE ORDER----------
			efields.set_formid(FormGUID);
			efields.set_ordertype("N");  //Can be a new (N) or (C) cancel
			std::string ser_string = efields.SerializeAsString();
			ser_string = Framework::Utility::CommnUtility().base64_encode(reinterpret_cast<const unsigned char*>(ser_string.c_str()), ser_string.length());
			corder.set_bstruser(ser_string);
			//-------------------------------------------------------------------------------

			if(corder.nquantity()==0)
			{
				return ;
			}

			//Send the order Immediately after checking
			//Check if Such an order is already open - Send if false
			if(!CheckIfOpenOrder(corder) && !AutomationPaused) //Make Sure the Automation is not Paused (By default when Automation starts its not paused)
			{
				//Add to the table
				PrintConsole(MType::OrderType,"New Order Dispatched");
				//ui.listWidgetConsole->addItem("New Order Dispatched."); ui.listWidgetConsole->scrollToBottom();

				AdddNewOpenOrder(corder);

				//Send to NetWork Immediately
				Framework::NOmega::QpidSubscriber::GetQpidInstance()->SendOptionOrder(corder);
			}
		}
		else
		{
			PrintConsole(MType::Other, "Cannot Send a new order - Maximum Cancel Allowed Exceeded.");
			return;
		}
}//End method


void OptionQuoter::SendCancelOrder()
{
		/*
	labels.push_back("OrderID");				//0
	labels.push_back("Side");                   //1   
	labels.push_back("Quantity");               //2
	labels.push_back("Price");                  //3
	labels.push_back("Destination");            //4
	labels.push_back("Category");               //5 
	labels.push_back("Sterling Code");          //6
	labels.push_back("SearchString");           //7 
	*/

	float Qbid;
	Serializable::CustROrder_ser corder;
	Serializable::ExtraRFields efields;
	efields.set_formid(FormGUID);
	efields.set_ordertype("C");  //Can be a new (N) or (C) cancel

	std::string option_symbol = symbol_load_inst->symbolTypeMap["Q"];
	QList<QStandardItem*> lst  = ModelOptionQuoter->findItems(option_symbol.c_str(),Qt::MatchExactly,1);
	if(lst.size() > 0)
	{
		int row = lst[0]->row();
		Qbid = ModelOptionQuoter->item(row,3)->text().toFloat() ;
	}

	for(int i=0 ; i<ModelOrderTracker->rowCount();i++)
	{
		float lmtprice = ModelOrderTracker->item(i,OrderTrackerColEnum::Price)->text().toFloat();
		
		//std::string str_code = ModelOrderTracker->item(i,6)->text().toStdString();
		int code = ModelOrderTracker->item(i,OrderTrackerColEnum::Sterling_Code)->text().toFloat();

		//                 PendingCancel   OrderJustDispatched  CustomPendingCancel                           
		if(lmtprice>=Qbid && code!=1 && code!=-99 && code!=-98)
		{	
			std::string OrderId = ModelOrderTracker->item(i,OrderTrackerColEnum::OrderID)->text().toStdString();

			PrintConsole(OrderType,"-------START : Preparing to Cancel Order--------------------");
			PrintConsole(OrderType,"Order To cancel has ID : " + OrderId + " with Code : " + QString::number(code).toStdString());

			corder.set_cust_cancelorderid(OrderId);
			
			//Use the old client id - Just Add - XX
			std::string cancel_id = "XX-" + OrderId;
			corder.set_bstrclorderid(cancel_id);
						
			corder.set_bstruser(efields.SerializeAsString());//Contains the type of order
			corder.set_bstraccount(Account);
			
			
			//Change the id of the order also since an acknowledgment will be sent of this new id not an old one
			ModelOrderTracker->item(i,OrderTrackerColEnum::OrderID)->setText(corder.bstrclorderid().c_str());

			//Change the code of the order stating that a cancel has been dispatched for this order
			ModelOrderTracker->item(i,OrderTrackerColEnum::Sterling_Code)->setText("-98"); //This means its a pending cancel

			
			//Add to the table
			PrintConsole(MType::OrderType,"New Order (Cancel Type) Dispatched");


			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			//Record details of this cancel order that is being  dispatched - Remove this later
			int row = lst[0]->row();
			CancelOrderDetails * cod = new CancelOrderDetails();
			cod->set_qbid(ModelOptionQuoter->item(row,3)->text().toFloat());
			cod->set_qask(ModelOptionQuoter->item(row,5)->text().toFloat());
			cod->set_Spread(cod->get_qask()-cod->get_qbid());
			cod->set_OrdSize(ModelOrderTracker->item(i,OrderTrackerColEnum::Quantity)->text().toDouble());
			cod->set_AskSize(ModelOptionQuoter->item(row,6)->text().toFloat());
			CancelDetailRecorder[cancel_id]= cod;
			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


			//Send to NetWork Immediately
			Framework::NOmega::QpidSubscriber::GetQpidInstance()->SendOptionOrder(corder);

			PrintConsole(OrderType,"-------END : Preparing to Cancel Order--------------------");
		}
	}//end for
}//End Method


void OptionQuoter::CancelOrderCheck(QStandardItem* itm)
{
	if( itm->column()==OrderTrackerColEnum::Cancel_Order_Column)
	{
		if(ModelOrderTracker->item(itm->row(),OrderTrackerColEnum::Cancel_Order_Column)->checkState()==Qt::CheckState::Checked)
		{
			ForceCancelOrder(ModelOrderTracker->item(itm->row(),OrderTrackerColEnum::OrderID)->text().toStdString());
		}
	}
}


void OptionQuoter::ForceCancelOrder(std::string& order_id)
{
	Serializable::CustROrder_ser corder;
	Serializable::ExtraRFields efields;
	efields.set_formid(FormGUID);
	efields.set_ordertype("C");  //Can be a new (N) or (C) cancel
	corder.set_cust_cancelorderid(order_id);
	//corder.set_bstrclorderid(boost::uuids::to_string(boost::uuids::random_generator()()));
	corder.set_bstrclorderid("XX-"+ order_id);
	corder.set_bstruser(efields.SerializeAsString());//Contains the type of order
	corder.set_bstraccount(Account);

	//Find the relevant row with that order ID
	QList<QStandardItem*> lst  = ModelOrderTracker->findItems(order_id.c_str(),Qt::MatchExactly,OrderTrackerColEnum::OrderID);
	if(lst.count() > 0)
	{
		//Change the code to pending cancel
		ModelOrderTracker->item(lst[0]->row(),OrderTrackerColEnum::Sterling_Code)->setText("-99");

		//Change the id of the order also since an acknowledgment will be sent of this new id not an old one
		ModelOrderTracker->item(lst[0]->row(),OrderTrackerColEnum::OrderID)->setText(corder.bstrclorderid().c_str());
	}

	//Send to NetWork Immediately
	Framework::NOmega::QpidSubscriber::GetQpidInstance()->SendOptionOrder(corder);
}

bool OptionQuoter::FilterInputValues()
{
	float Qbid= 0;
	float Qask= 0;
	float max_bid=0;
	float max_ask=0;
	float min_ask;
	std::string option_symbol = symbol_load_inst->symbolTypeMap["Q"];
	QList<QStandardItem*> lst  = ModelOptionQuoter->findItems(option_symbol.c_str(),Qt::MatchExactly,1);
	
	if(lst.size() > 0)
	{
		int row = lst[0]->row();
		Qbid = ModelOptionQuoter->item(row,3)->text().toFloat() ;
		Qask = ModelOptionQuoter->item(row,4)->text().toFloat() ;
	}

	max_bid = ModelInputs->item(InputRows::Max_Bid,1)->text().toFloat() ;
	max_ask = ModelInputs->item(InputRows::Max_Offer,1)->text().toFloat() ;
	min_ask = ModelInputs->item(InputRows::Min_Offer,1)->text().toFloat() ;

	//if((Qbid<max_bid && Qask>min_ask) && (Qask > min_ask) && Qask < max_ask )
	if(Qbid < max_bid || Framework::Utility::CommnUtility().FloatCompare(max_bid,Qbid))
	{
		return SendOptionOrder(Qbid,Qask);
	}
	else
	{
		return false;
	}
}//End Method


void OptionQuoter::TestConditionalFilters()
{
	//Reset the old expression attachment
	symbol_table.clear();
	expression.release();
	expression_result = 0;
	
	std::vector<double*> cont;

	symbol_table.add_variable("expression_result",expression_result);
	for(int i=0; i < SelectedColumns.size();i++)
	{
		QList<QStandardItem*> lst = ModelExpressionTester->findItems(SelectedColumns[i].c_str(),Qt::MatchFixedString,0);

		if(lst.count()>0)
		{
			bool conversion  = false;
			double *a = new double(  column_cell_mapper[SelectedColumns[i]]->text().toDouble(&conversion));
			if(!conversion) return;
			cont.push_back(a);
			symbol_table.add_variable(SelectedColumns[i],*a);
		}		
	}
	
	//Attach new values
	expression.register_symbol_table(symbol_table);
	parser.compile(expression_string,expression);
	expression.value();

	if(expression_result > 0)
	{
		ui.lineEditFinalExpression->setStyleSheet("QLineEdit{background: green;}");
		FilterInputValues(); //Send an order out 
	}
	else if (expression_result < 0)
	{
		ui.lineEditFinalExpression->setStyleSheet("QLineEdit{background: red;}");
		SendCancelOrder();  //Send Cancel order out
	}
	else if (expression_result == 0)
	{
	
	}

	for(int i=0 ; i<cont.size() ; i++)
	{
		delete cont[i];
	}
}//End Method


double OptionQuoter::Extract_Highest_Open_order_Price()
{
	    double highest_price = 0;
		for(int i=0 ; i<ModelOrderTracker->rowCount();i++)
		{
			double price = ModelOrderTracker->item(i,OrderTrackerColEnum::Price)->text().toDouble();
			highest_price =  price > highest_price ? price : highest_price;
		}
		return highest_price;
}


void OptionQuoter::Process_SPX_Algo1_Neutral()
{
	//Iterate through the exchanges
	for(int i=0; i<ExchangesSelected.size(); i++)
	{
		QList<QStandardItem*> lst = ModelExchanges->findItems(ExchangesSelected[i].c_str(),Qt::MatchExactly,0);
		if(lst.size()>0)
		{
			int rowno = lst[0]->row();
			double tot_cancel = ModelExchanges->item(rowno,3)->text().toDouble();
			double max_cancel = ModelExchanges->item(rowno,2)->text().toDouble();
			spx_algo1_neut.set_Q_Bid( column_cell_mapper["Q_Bid"]->text().toDouble());
			spx_algo1_neut.set_Q_Ask( column_cell_mapper["Q_Ask"]->text().toDouble());
			spx_algo1_neut.set_Q_BidSize( column_cell_mapper["Q_BidSize"]->text().toDouble());
			spx_algo1_neut.set_Q_AskSize( column_cell_mapper["Q_AskSize"]->text().toDouble());
			spx_algo1_neut.set_max_cxl(max_cancel);
			spx_algo1_neut.set_tot_cxl(tot_cancel);
			double max_pos     = ModelInputs->item(0,1)->text().toDouble();
			double current_pos = ModelInputs->item(1,1)->text().toDouble();
			int order_size = ModelExchanges->item(rowno,4)->text().toInt();
			spx_algo1_neut.set_current_pos(current_pos);
			spx_algo1_neut.set_max_pos(max_pos);
			spx_algo1_neut.set_OrdSize(order_size);
			spx_algo1_neut.set_highest_open_order_price(Extract_Highest_Open_order_Price());
			spx_algo1_neut.evaluate_expression();
			if(spx_algo1_neut.get_OutputAction()==SPX_ALGO1_NEUTRAL::EnumAction::SendOrder)
			{
				SendCustomOptionOrder((float)spx_algo1_neut.get_Q_Bid(),ExchangesSelected[i],spx_algo1_neut.get_OrdSize());
			}
			else if (spx_algo1_neut.get_OutputAction()==SPX_ALGO1_NEUTRAL::EnumAction::CancelOrder)
			{
				SendCancelOrder();
			}
			else
			{
				//Do Nothing
			}
		}//end if
	}//End for

}//End method

//Update the options table - This is where the feeds come in
void OptionQuoter::UpdateOptionModel(Serializable::OptionTick_ser otick)
{
	//Check if this form even needs this update
	//-----------------------------------------------------------------------------------------------
	if(!std::binary_search(SubscribedSymbols.begin(),SubscribedSymbols.end(),otick.symbol())) return;
	//-----------------------------------------------------------------------------------------------

	QList<QStandardItem*> lst = ModelOptionQuoter->findItems(otick.symbol().c_str(),Qt::MatchExactly,1);
	if(lst.size()>0)
	{
		int rowno = lst[0]->row();
		int i=2;
		ModelOptionQuoter->item(rowno,i)->setText(QString::number(otick.bidsize()).toStdString().c_str());   i++;           //BidSize 
		ModelOptionQuoter->item(rowno,i)->setText(QString::number(otick.bid()).toStdString().c_str());   i++;			    //Bid 
		ModelOptionQuoter->item(rowno,i)->setText(QString::number(otick.tradeprice(),'f',3).toStdString().c_str());   i++;  //Last
		ModelOptionQuoter->item(rowno,i)->setText(QString::number(otick.ask(),'f',3).toStdString().c_str());   i++;			//Ask
		ModelOptionQuoter->item(rowno,i)->setText(QString::number(otick.asksize(),'f',3).toStdString().c_str());   i++;		//AskSize
	}//end if

	if(StartAutomationProcess)
	{
		if(InternalAlgorithm==true)
		{
			//Run the internal algorithm function (whichever is selected)
			InternalAlgorithmFunction(); 
		}
		else
		{
			TestConditionalFilters();
		}
	}
}//end method


void OptionQuoter::AddOptionToTable(const std::string& type , const std::string& symbolName )
{
	QStandardItem* item_type             =  new QStandardItem(type.c_str());             //0
	QStandardItem* item_symbol           =  new QStandardItem(symbolName.c_str());       //1  
	QStandardItem* item_BidSize		     =  new QStandardItem("--");                     //2
	QStandardItem* item_Bid              =  new QStandardItem("--");                     //3
	QStandardItem* item_Last             =  new QStandardItem("--");                     //4 
	QStandardItem* item_Ask              =  new QStandardItem("--");                     //5 
	QStandardItem* item_AskSize          =  new QStandardItem("--");                     //6

	QList<QStandardItem*> lst ;
	lst.push_back(item_type);
	lst.push_back(item_symbol);
	lst.push_back(item_BidSize);
	lst.push_back(item_Bid);
	lst.push_back(item_Last);
	lst.push_back(item_Ask);
	lst.push_back(item_AskSize);
	ModelOptionQuoter->appendRow(lst);
}


//Subscribe to symbols
void OptionQuoter::ManageSubscriptions()
{
	SubscribedSymbols.clear();
	for(std::map<std::string,std::string>::iterator it =symbol_load_inst->symbolTypeMap.begin(); it != symbol_load_inst->symbolTypeMap.end();it++)
	{
		std::string symbol = it->second;
        std::string topic = OMEGA::SymbAndTopics[symbol];
		//SubscribeToTopic(symbol,topic);
		SubscribedSymbols.push_back(symbol);
	}
	//Sort the symbols now for binary search later
	std::sort(SubscribedSymbols.begin(),SubscribedSymbols.end());
	SubscribeToTopic("ParameterNoUse", "ParameterNoUse");
}

//Fills in the remaining tables on the form
void OptionQuoter::DisplayLayout()
{
	    DisplayExchanges(); //Display the exchanges table
		DisplayInputs();    //Display the inputs   table
		populateFilters();
		InitializeOrderTrackerModel(); //Display the order Tracker Model
}


void OptionQuoter::PositionedFilterAddition(std::string t)
{
	ui.lineEditFilterExpression->insert(std::string(" " + t + " ").c_str());
}

void OptionQuoter::FilterContextMenu(const QPoint& pos)
{
	QPoint globalPos = ui.lineEditFilterExpression->mapToGlobal(pos);
	// for QAbstractScrollArea and derived classes you would use:
	// QPoint globalPos = myWidget->viewport()->mapToGlobal(pos); 

	QMenu mnumain;
	mnumain.setTitle("Insert Item");

	QMenu mnuBooleanOperators;
	mnuBooleanOperators.setTitle("Boolean Operators");
	mnuBooleanOperators.addAction("and");
	mnuBooleanOperators.addAction("or");

	QMenu mnuEqualities;
	mnuEqualities.setTitle("Equality Operators");
	mnuEqualities.addAction("=");
	mnuEqualities.addAction("equal");
	mnuEqualities.addAction("!=");
	mnuEqualities.addAction("<");
	mnuEqualities.addAction(">");
	mnuEqualities.addAction("<=");
	mnuEqualities.addAction(">=");


	QMenu mnuArithmatic;
	mnuArithmatic.setTitle("Arithmatic Operators");
	mnuArithmatic.addAction("+");
	mnuArithmatic.addAction("-");
	mnuArithmatic.addAction("*");
	mnuArithmatic.addAction("/");
	mnuArithmatic.addAction("%");
	mnuArithmatic.addAction("^");


	QMenu mnuFunctions;
	mnuFunctions.setTitle("Functions");
	mnuFunctions.addAction("abs");
	mnuFunctions.addAction("avg");
	mnuFunctions.addAction("ceil");
	mnuFunctions.addAction("clamp");
	mnuFunctions.addAction("erf");
	mnuFunctions.addAction("erfc");
	mnuFunctions.addAction("expm1");
	mnuFunctions.addAction("floor");
	mnuFunctions.addAction("frac");
	mnuFunctions.addAction("inrange");
	mnuFunctions.addAction("log");
	mnuFunctions.addAction("log10");
	mnuFunctions.addAction("log1p");
	mnuFunctions.addAction("log2");
	mnuFunctions.addAction("max");
	mnuFunctions.addAction("min");
	mnuFunctions.addAction("sum");
	mnuFunctions.addAction("trunc");
	mnuFunctions.addAction("roundn");

	// ...
	mnumain.addMenu(&mnuBooleanOperators);
	mnumain.addMenu(&mnuEqualities);
	mnumain.addMenu(&mnuFunctions);
	mnumain.addMenu(&mnuArithmatic);

	QAction* selectedItem = mnumain.exec(globalPos);
	std::string t = "sdds";
	if(selectedItem)
	{
           std::string selection = selectedItem->text().toStdString();
		   {PositionedFilterAddition(selection);}
	}
	//else
	//{
		// nothing was chosen
	//}

}


void OptionQuoter::ConstructToolTip()
{

	ui.lineEditFilterExpression->setStyleSheet("QToolTip{ min-width: " + QString::number(400) + "px; width: " + QString::number(400) + "px;}");
	ToolTip_filter = "<font color='blue'> <b> Arithmatic Operators </b> </font> <br>"  
		"<font color='red'> <b> + </b> </font> Addition between x and y. (eg: x + y) <br>"  
		"<font color='red'> <b> - </b> </font> Addition between x and y. (eg: x + y) <br>"  
		"<font color='red'> <b> * </b> </font> Multiplication between x and y. (eg: x * y) <br>"
		"<font color='red'> <b> / </b> </font> Division between x and y (eg: x / y) <br>"
		"<font color='red'> <b> % </b> </font> Modulus of x with respect to y. (eg: x % y)  <br>"
		"<font color='red'> <b> ^ </b> </font> x to the power of y. (eg: x ^ y) <br>"
		"<font color='blue'> <b> Boolean Operators </b> </font> <br>"  
		"<font color='red'> <b> and </b> </font> Logical AND, True only if x and y are both true. (eg: x and y) <br>"  
		"<font color='red'> <b> or </b> </font>  Logical OR, True if either x or y is true. (eg: x or y) <br>"  
		"<font color='blue'> <b> Equality Operators </b> </font> <br>"  
		"<font color='red'> <b> = </b> </font>  True only if x is strictly equal to y. (eg: x = y)  <br>"  
		"<font color='red'> <b> != </b> </font> True only if x does not equal y. (eg: x != y) <br>"  
		"<font color='red'> <b> &lt; </b> </font> True only if x is less than y. (eg: x &lt; y) <br>"  
		"<font color='red'> <b> &gt; </b> </font> True only if x is greater than y. (eg: x &gt; y)  <br>"  
		"<font color='red'> <b> &lt;= </b> </font> True only if x is less than or equal to y. (eg: x &lt;= y) <br>"  
		"<font color='red'> <b> &gt;= </b> </font> True only if x greater than or equal to y. (eg: x &gt;= y) <br>"  
		"";
}

//Insert the names of column names here for the combo boxe here
void OptionQuoter::populateFilters()
{
	/*
	labels.push_back("Type");        0
	labels.push_back("Symbol");      1
	labels.push_back("BidSize");     2
	labels.push_back("Bid");         3
	labels.push_back("Last");        4 
	labels.push_back("Ask");         5
	labels.push_back("Ask Size");  6 */

	ModelExpressionTester->clear();

	//---------------------------------------
	ui.lineEditFinalExpression->setText("");
	expression_string = "";
	//--------------------------------------

	//Populate the headers of the Expression Tester Table
	QStringList labels;
	labels.push_back("Variable");
	labels.push_back("Value");
	ModelExpressionTester->setHorizontalHeaderLabels(labels); //Labels for the columns
	ui.TableExpressionTester->setModel(ModelExpressionTester);


	//Populate the Column Combo Box
	std::string caption;
	int col;
	int type = 0;
	for(int row = 0 ; row<ModelOptionQuoter->rowCount();row++)
	{                       
		//Type-BidSize
		col = 2; //BidSize
		caption = ModelOptionQuoter->item(row,type)->text().toStdString() + "_BidSize";
		ui.comboColumnNames->addItem(caption.c_str());
		column_cell_mapper[caption]=ModelOptionQuoter->item(row,col);

		//Type-Bid
		col = 3; //Bid
		caption = ModelOptionQuoter->item(row,type)->text().toStdString() + "_Bid";
		ui.comboColumnNames->addItem(caption.c_str());
		column_cell_mapper[caption]=ModelOptionQuoter->item(row,col);

		//Type-Ask
		col = 5; //Ask
		caption = ModelOptionQuoter->item(row,type)->text().toStdString() + "_Ask";
		ui.comboColumnNames->addItem(caption.c_str());
		column_cell_mapper[caption]=ModelOptionQuoter->item(row,col);

		//Type-Ask
		col = 6; //Ask
		caption = ModelOptionQuoter->item(row,type)->text().toStdString() + "_AskSize";
		ui.comboColumnNames->addItem(caption.c_str());
		column_cell_mapper[caption]=ModelOptionQuoter->item(row,col);
	}

	ui.lineEditFilterExpression->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.lineEditFilterExpression, SIGNAL(customContextMenuRequested(const QPoint&)),	this, SLOT(FilterContextMenu(const QPoint&)));
							  
	ui.lineEditFilterExpression->setToolTip(ToolTip_filter.c_str());
	
}//End Method

void OptionQuoter::AddColumnToExpression(std::string colname)
{
	//Add this column to the Expression Tester
	QStandardItem* item_variable         =  new QStandardItem(colname.c_str());  //0
	QStandardItem* item_value            =  new QStandardItem("0");             //1  


	if(std::find(SelectedColumns.begin(),SelectedColumns.end(),colname)==SelectedColumns.end())
	{
		//Add to selected columns and tester modeltable
		SelectedColumns.push_back(colname);
		QList<QStandardItem*> lst ;
		lst.push_back(item_variable);
		lst.push_back(item_value);
		ModelExpressionTester->appendRow(lst);
	}
}//end Method

void OptionQuoter::AddColumnToExpression()
{
	std::string col = ui.comboColumnNames->currentText().toStdString();
	
	//ui.lineEditFilterExpression->setText(ui.lineEditFilterExpression->text() + col.c_str());
	ui.lineEditFilterExpression->insert(std::string(" " + col + " ").c_str());

	//Add this column to the Expression Tester
	QStandardItem* item_variable         =  new QStandardItem(col.c_str());  //0
	QStandardItem* item_value            =  new QStandardItem("0");             //1  
	

	if(std::find(SelectedColumns.begin(),SelectedColumns.end(),col)==SelectedColumns.end())
	{
		SelectedColumns.push_back(col);
		QList<QStandardItem*> lst ;
		lst.push_back(item_variable);
		lst.push_back(item_value);
		ModelExpressionTester->appendRow(lst);
	}
}//end Method

void OptionQuoter::TestExpression()
{

	symbol_table.clear();
	expression.release();
	

	expression_result = 0;
	std::string fs = "if(" + ui.lineEditFilterExpression->text().toStdString() + ",expression_result:=1 ,expression_result:=-1)";
	expression_string = fs;

	for(int i=0; i < SelectedColumns.size();i++)
	{
		QList<QStandardItem*> lst = ModelExpressionTester->findItems(SelectedColumns[i].c_str(),Qt::MatchFixedString,0);

		if(lst.count()>0)
		{
			double *a = new double(ModelExpressionTester->item(lst[0]->row(),1)->text().toDouble());
			symbol_table.add_variable(SelectedColumns[i],*a);
		}		
	}

	symbol_table.add_variable("expression_result",expression_result);
	expression.register_symbol_table(symbol_table);
	parser.compile(expression_string,expression);
	expression.value();	

	if(expression_result > 0)
	{
		QMessageBox::information(this,"Expression Tester","Result : True");
	}
    else if(expression_result < 0)
	{
		QMessageBox::information(this,"Expression Tester","Result : False");
	}
	
}//End Method

//Add the expression Filter
void OptionQuoter::AddExpressionFilter()
{
	//symbol_table.clear();
	//expression.release();

	//expression_result = 0;
	std::string fs = "if(" + ui.lineEditFilterExpression->text().toStdString() + ",expression_result:=1 ,expression_result:=-1)";
	expression_string = fs;
	ui.lineEditFinalExpression->setText(ui.lineEditFilterExpression->text());
	
	
	/*
	symbol_table.add_variable("expression_result",expression_result);

	for(int i=0; i < SelectedColumns.size();i++)
	{
		QList<QStandardItem*> lst = ModelExpressionTester->findItems(SelectedColumns[i].c_str(),Qt::MatchFixedString,0);

		if(lst.count()>0)
		{
			float *a = new float(ModelExpressionTester->item(lst[0]->row(),1)->text().toFloat());
			symbol_table.add_variable(SelectedColumns[i],*a);
		}		
	}
	*/
	
	//expression.register_symbol_table(symbol_table);
	//parser.compile(expression_string,expression);

}//End Method


void OptionQuoter::UnSubscribeFromAllSymbols()
{
	std::vector<std::string> RemovedSymobls;
	for(int i=0 ; i<ModelOptionQuoter->rowCount();i++)
	{
		std::string symbol = ModelOptionQuoter->item(i,1)->text().toStdString();
		RemovedSymobls.push_back(symbol);
		UnSubscribeFromTopic(symbol); //Form wont receive anymore updates however we still need to remove them from the table
	}

    //This removes the symbol from the table 
	for(int i=0 ; i<RemovedSymobls.size();i++)
	{
		RemoveSymbolFromModel(RemovedSymobls[i]);
	}
}



void OptionQuoter::PopulateOptionsTable()
{
	AddOptionToTable("Q",symbol_load_inst->symbolTypeMap["Q"]);
	
	for(std::map<std::string,std::string>::iterator it =symbol_load_inst->symbolTypeMap.begin(); it != symbol_load_inst->symbolTypeMap.end();it++)
	{
		if(it->first!="Q")
		{
			AddOptionToTable(it->first,it->second);
		}
		
	}
}//End Method


void OptionQuoter::ShowSymbolList()
{
	if(symbol_load_inst==NULL)
	{
		SymbolLoad *sload = new SymbolLoad(this);
		symbol_load_inst = sload;
		sload->setWindowModality(Qt::WindowModal); //Block only this form instance
		
		if(sload->exec()==1) //Block until the user selects from a form
		{
		    PopulateOptionsTable();   //Populate options table
			DisplayLayout();          //Display everything else
			ManageSubscriptions();    //Connect to topics on QPID
			
			std::string title = symbol_load_inst->UnderLineSymbol + "-" + symbol_load_inst->QuoteSymbol;
			this->setWindowTitle(title.c_str());
			ui.cmdStart->setEnabled(true);
			ui.cmdPause->setEnabled(true);
		}
		else
		{
			//Do nothing ... Since the form was canceled
		}
	}
	else
	{
		if(symbol_load_inst->exec()==1) //Block until the user selects from a form
		{
			//UnSubscribe From  all Symbols;
			UnSubscribeFromAllSymbols();	//This clears the form up
			
			PopulateOptionsTable();        //Displays symbols selected from the Symbol Form
			ManageSubscriptions();         //Connect to topics on QPID

			DisplayLayout();               //Display everything else 

			std::string title = symbol_load_inst->UnderLineSymbol + "-" + symbol_load_inst->QuoteSymbol;
			this->setWindowTitle(title.c_str());
		}
		else
		{
			//Do nothing ... Since the form was canceled
		}
	}
}//END METHOD


void OptionQuoter::CancelAllPendingOrders()
{
	//This clears the form up
	PrintConsole(MType::Other,"canceling Open Orders (if any)");
	for(int i=0 ; i < ModelOrderTracker->rowCount();i++)
	{
			PrintConsole(MType::Other,"Canceling Order ID : " + ModelOrderTracker->item(i,OrderTrackerColEnum::OrderID)->text().toStdString() );	
			ForceCancelOrder(ModelOrderTracker->item(i,OrderTrackerColEnum::OrderID)->text().toStdString());
	}
}//End Method


void OptionQuoter::TimerSlotEnableGUITimeOut()
{
	if(ModelOrderTracker->rowCount() == 0)
	{
		EnableDisableDisplay(true);
		TimerEnableGUIDisplay->stop();
	}
}

