#include "FeedConnector.h"

#include <QObject>
#include <iostream>
#include "boost/spirit/include/qi.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <QTcpSocket>
#include "QStringList"
#include "OptionIndicator.h"
#include "Wopr.h"
#include "UpdateFeeds.h"
#include <windows.h> 
#include <intrin.h>  
#include <ctype.h>
#include "TickStorage.h"
#include "OptionProperties.h"

//---------------------------------------------------------------------------------------------
//Log4cplus Files does not work with UNICODE Preprocessor
//---------------------------------------------------------------------------------------------
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------


using namespace boost::posix_time;
using namespace boost::gregorian;
namespace qi = boost::spirit::qi;


typedef WOPR WOPR_CLASS;

namespace Framework
{
	namespace WOPR
	{
		std::map<std::string,float> FeedConnector::StockUpdates;

		boost::mutex FeedConnector::mutex_stock_update;

		FeedConnector::FeedConnector(QObject* parent /* = 0 */)
		{
			connected = false;
			RiskFreeRate = atof(WOPR_CLASS::GetConfigValue("RiskFreeRate").c_str());
		}

		TickStorage FeedConnector::ReturnTickStorage()
		{
			return tick_bank;
		}

		//Converts the date format 8/17/2013 to ptime
		boost::posix_time::ptime FeedConnector::Date_PtimeConverter(const std::string& Dtime)
		{
			 QString QDtime(Dtime.c_str());
			 QStringList lstdate = QDtime.split("/");
			 QString Fdate = lstdate[2] + "-" + lstdate[0] + "-" + lstdate[1];
			 date d(from_simple_string(Fdate.toStdString()));
			 ptime t(d, hours(0) +  minutes(0)   +  seconds(0)   +   millisec(0) );
			 std::string out =  boost::posix_time::to_simple_string(t);
			 return t;
		}

		//This method requires the presence of milliseconds
		boost::posix_time::ptime FeedConnector::ReturnInTimeFormat_mseconds(const std::string& Dtime)
		{
			QString QDtime(Dtime.c_str());
			QStringList t_vector = QDtime.split(":");

			QStringList sec_mvector = t_vector[2].split(".");
			int sec = sec_mvector[0].toInt(); 
			int msec =sec_mvector[1].toInt();

			date d = second_clock::local_time().date(); //Add a day

			ptime t(d, hours(t_vector[0].toInt()) +  minutes( t_vector[1].toInt() )   +  seconds(sec)   +   millisec(msec) );
		
			return t;
		}


		std::string FeedConnector::CalculateTickTimeDifference(std::string& tickTime)
		{
			ptime localtime = boost::posix_time::microsec_clock::local_time();
			std::string localtme = boost::posix_time::to_simple_string(localtime);
			

			ptime tickTime_ = ReturnInTimeFormat_mseconds(tickTime);
			std::string feedtme = boost::posix_time::to_simple_string(tickTime_);
			

			boost::posix_time::time_duration difftime = localtime - tickTime_;

			std::stringstream ssDuration;
			
			ssDuration << difftime.total_milliseconds();

			std::string str = ssDuration.str();

			return str;
		}


		std::string FeedConnector::CalculateExpirationTimeLeft(const std::string& timeStamp , const std::string& expirDate)
		{
			std::string output;
			boost::posix_time::ptime dtime = Date_PtimeConverter(expirDate) + minutes(1050);
			
			output = boost::posix_time::to_simple_string(dtime);
			
			//boost::posix_time::time_duration difftime = ReturnInTimeFormat_mseconds(timeStamp) - dtime;
			boost::posix_time::time_duration difftime =  dtime - ReturnInTimeFormat_mseconds(timeStamp) ;
			
			float total_sec = difftime.total_seconds();
			float years = (float(1)/float(31536000)) * total_sec; 
			QString yr(QString::number(years,'g',6));
			return yr.toStdString();
		}


		void FeedConnector::UpdateStockClose(std::string symbol,float close)
		{
			{//Begin Lock
				boost::lock_guard<boost::mutex> lock(mutex_stock_update);
				//found or not still insert it
				StockUpdates[symbol] = close;
			}
		}


		//Thread safety check
		//Retrieves the closing of the stock if nothing is found returns 0
		float FeedConnector::RetrieveStockClose(std::string option_symbol_name)
		{
			std::string stk_symbol = GetSymbolOfOption(option_symbol_name); 
			if(StockUpdates.find(stk_symbol)!=StockUpdates.end())
			{
				return StockUpdates[stk_symbol];
			}
			else
			{
				return 0; 
			}
		}//end method


		float FeedConnector::ConvertStringToFloat(std::string& str)
		{
			float val;
			std::string::iterator begin ;  std::string::iterator end ;
			begin = str.begin(); end = str.end();

			//Convert string to float using boost::spirit
			boost::spirit::qi::parse(begin, end, boost::spirit::float_, val);
			return val;
		}


		float FeedConnector::trunc(float d)
		{
			return (d>0) ? floor(d) : ceil(d) ; 
		}

		//Yes they are equal
		bool FeedConnector::FloatCompareOptions(float a , float b)
		{
			if (trunc(100.0 * a) == trunc(100.0 * b))
			{
				return true;
			}
			return false;
		
		}

		//This method returns if bid and ask are the same as preserved
		bool FeedConnector::RunImpliedVolatilityMethod(const std::string symbol,float bid,float ask)
		{
			//Check if the symbol is present
			if(LastVolTracker.find(symbol)==LastVolTracker.end())
			{
				//Symbol not present - So now we add it and return true (since the implied volatility function obviously needs to run)
				LastVolatility lv;
				lv.set_bid(bid);
				lv.set_ask(ask);

				LastVolTracker[symbol] = lv;
				return true;
			}
			else
			{
                //Symbol is present - So check if bid and ask are the same
				//if(LastVolTracker[symbol].get_bid()==bid && LastVolTracker[symbol].get_ask()==ask)
				if(FloatCompareOptions(LastVolTracker[symbol].get_bid(),bid) && FloatCompareOptions(LastVolTracker[symbol].get_ask(),ask) )
				{
					//This does match - No need to run the function return false
					return false;
				}
				else
				{
					//Bid and ask are not the same
					LastVolTracker[symbol].set_bid(bid);
					LastVolTracker[symbol].set_ask(ask);
					
					//Still need to run the function
					return true;
				}
			}//end else;
		}//End method;


		void FeedConnector::UpdateLastVolTracker(const std::string symbol,float& bid_iv,float& ask_iv,float& mp_iv)
		{
			LastVolTracker[symbol].set_ask_iv(ask_iv);
			LastVolTracker[symbol].set_bid_iv(bid_iv);
			LastVolTracker[symbol].set_mp_iv(mp_iv);
		}


		//Retrieve the Fundamental Message
		std::string FeedConnector::RetrieveFundMessage(std::string symbol , FMessage msg)
		{
			//Check if the symbol is in there
			//Check if a message is in there
			if(FundamentalMsgTracker.find(symbol) == FundamentalMsgTracker.end() )
			{
				//Not Found
				return "-99";
			}

			std::string  res;
			if(msg == FMessage::DivAmount)
			{
				res = FundamentalMsgTracker[symbol][FMessage::DivAmount].c_str();
			}
			else if (msg == FMessage::DivDate)
			{
				res = FundamentalMsgTracker[symbol][FMessage::DivAmount].c_str();
			}
			else if(msg == FMessage::DivPercentage)
			{
				res = FundamentalMsgTracker[symbol][FMessage::DivAmount].c_str();
			}

			return res;
		}//End Method



		//This message is for storing content of a fundamental message
		void FeedConnector::ProcessFundMessage(std::string& tick_msg)
		{
			QString tq(tick_msg.c_str());
			QStringList tick_content = tq.split(",");
			std::string ex_div_date = tick_content[13].toStdString();
			std::string ex_div_amt = tick_content[10].toStdString();
			std::string ex_div_perc = tick_content[9].toStdString();
			std::string symbol = tick_content[1].toStdString();
			FundamentalMsgTracker[symbol][FMessage::DivAmount] = ex_div_amt;
			FundamentalMsgTracker[symbol][FMessage::DivDate] = ex_div_date;
			FundamentalMsgTracker[symbol][FMessage::DivPercentage] = ex_div_perc;
		}


		void FeedConnector::ProcessStockTick(std::string& tick_msg)
		{
			//0    1        2                  3                   4              5                   6    7         8               9   10          11          12             13           14       15     16           17                18                        19          20           21      22                  
			//T  Symbol,Message Contents,Last Market Center,Most Recent Trade,Most Recent Trade Size,Bid,Bid Size,Bid Market Center,Ask,Ask Size,Bid TimeMS,Ask Market Center,Ask TimeMS,Total Volume,High,Low,Number of Trades Today,Most Recent Trade TimeMS,Open Interest,Expiration Date,Strike,TickID
			Serializable::StockTick_ser* opt_obj = new Serializable::StockTick_ser();
			QString tq(tick_msg.c_str());
			QStringList tick_content = tq.split(",");

			//Update the Stock Close Data Structure that preserves the last of every stock
			UpdateStockClose(tick_content[1].toStdString(),tick_content[4].toFloat());//close

			opt_obj->set_symbol(tick_content[1].toStdString());			
			
					
			opt_obj->set_bid(ConvertStringToFloat(tick_content[6].toStdString()));
			opt_obj->set_bidsize(tick_content[7].toFloat());

			opt_obj->set_ask(ConvertStringToFloat(tick_content[9].toStdString()));
			opt_obj->set_asksize(tick_content[10].toFloat());

			opt_obj->set_last(tick_content[4].toFloat());

			opt_obj->set_dailylow(tick_content[16].toFloat());
			opt_obj->set_dailyhigh(tick_content[15].toFloat());

			opt_obj->set_volume(tick_content[5].toInt());
			opt_obj->set_dvolume(tick_content[14].toInt());
			opt_obj->set_totaltrades(tick_content[17].toInt());

			opt_obj->set_exdivamount(atof(RetrieveFundMessage(opt_obj->symbol(),FMessage::DivAmount).c_str()));
			opt_obj->set_exdivdate(RetrieveFundMessage(opt_obj->symbol(),FMessage::DivAmount));
			opt_obj->set_exdivpercentage(  atof(RetrieveFundMessage(opt_obj->symbol(),FMessage::DivAmount).c_str()));

			silo->Add_Feed_To_Stock_Silo(opt_obj);
		}


		void FeedConnector::ProcessOptionTick(std::string& tick,std::string& MsgType)
		{
			//0    1        2                  3                   4              5                   6    7         8               9   10          11          12             13           14       15     16           17                18                        19          20           21      22                  
			//T  Symbol,Message Contents,Last Market Center,Most Recent Trade,Most Recent Trade Size,Bid,Bid Size,Bid Market Center,Ask,Ask Size,Bid TimeMS,Ask Market Center,Ask TimeMS,Total Volume,High,Low,Number of Trades Today,Most Recent Trade TimeMS,Open Interest,Expiration Date,Strike,TickID
			Serializable::OptionTick_ser* opt_obj = new Serializable::OptionTick_ser();

			QString tq(tick.c_str());
			QStringList tick_content = tq.split(",");
			
			
			opt_obj->set_symbol(tick_content[1].toStdString());
			
			bool is_traded =  tick_content[2].contains("C") ? true : false;
			opt_obj->set_istraded(is_traded);

			bool is_quote =  tick_content[2].contains("a")  ||  tick_content[1].contains("b") ? true : false;
			opt_obj->set_isquote(is_quote);

			opt_obj->set_istype("Option");


			opt_obj->set_tradeprice(tick_content[4].toFloat());

			opt_obj->set_tradevolume(tick_content[5].toInt());

			opt_obj->set_tradeexch("SomeExchange");

			opt_obj->set_bid(ConvertStringToFloat(tick_content[6].toStdString()));
			opt_obj->set_bidsize(tick_content[7].toFloat());
			opt_obj->set_bidexch(tick_content[8].toStdString());
			opt_obj->set_bidtime(tick_content[11].toStdString());
			
			opt_obj->set_ask(ConvertStringToFloat(tick_content[9].toStdString()));
			opt_obj->set_asksize(tick_content[10].toFloat());
			opt_obj->set_askexch(tick_content[12].toFloat());
			opt_obj->set_asktime(tick_content[13].toStdString());

			opt_obj->set_dailyvolume(tick_content[14].toInt());
			opt_obj->set_dailylow(tick_content[16].toFloat());
			opt_obj->set_dailyhigh(tick_content[15].toFloat());
			opt_obj->set_dailytrades(tick_content[17].toInt());

			opt_obj->set_timestamp(tick_content[18].toStdString());
			opt_obj->set_openinterest(tick_content[19].toInt());
			opt_obj->set_expdate(tick_content[20].toStdString());
			opt_obj->set_strike(tick_content[21].toFloat());
			opt_obj->set_tickid(tick_content[22].toInt());

			opt_obj->set_exp_time_left(QString(CalculateExpirationTimeLeft(opt_obj->timestamp(),opt_obj->expdate()).c_str()).toFloat()); //In years

			
			//std::string CallPut = UpdateFeeds::OptionCallPut.at(opt_obj->symbol());
			std::string CallPut = UpdateFeeds::ptrUpdateFeedsForm->GetSymbolCallPut(opt_obj->symbol());
			
			std::string lwer = QString(CallPut.c_str()).toLower().toStdString();
			char *p = const_cast<char*>(lwer.c_str());
			float stock_close = RetrieveStockClose(opt_obj->symbol());
			
			//if(MsgType == "Q" && tick_content[2].contains("C")) //We only want these messages for trade types and the "c" which means "LAST QUALIFIED TRADE"
			//{
			    if(MsgType=="Q")
				{
					std::string type = tick_content[2].toStdString();
					opt_obj->set_bidtrade(ops.RetrieveBidTrade(opt_obj->symbol(),opt_obj->bid(),opt_obj->tradeprice(),opt_obj->tradevolume(),type));
					opt_obj->set_asktrade(ops.RetrieveAskTrade(opt_obj->symbol(),opt_obj->ask(),opt_obj->tradeprice(),opt_obj->tradevolume(),type));
					opt_obj->set_ntrade(ops.RetrieveNTrade(opt_obj->symbol(),opt_obj->bid(),opt_obj->ask(),opt_obj->tradeprice(),opt_obj->tradevolume(),type));
					opt_obj->set_bidvol(ops.RetrieveBidVolume(opt_obj->symbol()));
					opt_obj->set_askvol(ops.RetrieveAskVolume(opt_obj->symbol()));
					opt_obj->set_nvol(ops.RetrieveNVolume(opt_obj->symbol()));
				}
			//}

			float bid_iv,ask_iv,temp,mp_iv;
			
			if(RunImpliedVolatilityMethod(opt_obj->symbol(),opt_obj->bid(),opt_obj->ask()))
			{
				//----------------------------THIS DOES NOT NEED TO BE CALLED EVERY TIME-----------------------------------------------------------------------------------
				bid_iv = oic.bisectNewtonImpliedVol(*p, stock_close,	 opt_obj->strike(),	 opt_obj->exp_time_left(), RiskFreeRate, opt_obj->bid(),.001, double(500)) ;
				bid_iv = bid_iv * float(100);
				ask_iv = oic.bisectNewtonImpliedVol(*p, stock_close,	 opt_obj->strike(),	 opt_obj->exp_time_left(), RiskFreeRate, opt_obj->ask(),.001, double(500)) ;
				ask_iv = ask_iv * float(100);
				temp = (opt_obj->bid() + opt_obj->ask())/((float)2.0);
				mp_iv =oic.bisectNewtonImpliedVol(*p, stock_close,	 opt_obj->strike(),	 opt_obj->exp_time_left(), RiskFreeRate, temp,.001, double(500) * float(100) );
				mp_iv = mp_iv * float(100);
				UpdateLastVolTracker(opt_obj->symbol(),bid_iv,ask_iv,mp_iv);
				opt_obj->set_bid_imp_volatility(bid_iv);
				opt_obj->set_ask_imp_volatility(ask_iv);
				opt_obj->set_mp_imp_volatility(mp_iv);
				//----------------------------------------------------------------------------------------------------------------------------------------------------------
			}
			else
			{
				//LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Implied Volatility Method Skipped");
				bid_iv = LastVolTracker[opt_obj->symbol()].get_bid_iv();
				ask_iv = LastVolTracker[opt_obj->symbol()].get_ask_iv();
				mp_iv = LastVolTracker[opt_obj->symbol()].get_mp_iv();
				opt_obj->set_bid_imp_volatility(bid_iv);
				opt_obj->set_ask_imp_volatility(ask_iv);
				opt_obj->set_mp_imp_volatility(mp_iv);
			}

			tick_bank.Update_Option(opt_obj->symbol(),*opt_obj);
			silo->Add_Feed_To_Option_Silo(opt_obj);
		}

	
		//This method categorizes the feed into a category
		void FeedConnector::CategorizeTick(std::string& tick)
		{
			//Extract the symbol
			QString QtickStr(tick.c_str());
			QStringList QtickLst = QtickStr.split(",");
			std::string symb = QtickLst[1].toStdString(); 

			//P IS THE INITIALIZING MESSAGE
			//Q IS THE UPDATE MESSAGE
			std::string stype = tick.substr(0,1);
			if (stype=="Q" || stype=="P" || stype=="F")
			{

				int len = symb.length();

				if(len >= 7 )  
				{
					if(stype!="F")
					//its an option - They cant process fundamental types
					//AS they throw index out of range errors
					ProcessOptionTick(tick,stype);
				}
				else
				{
					if(symb.find("@") != std::string::npos)
					{
						//its a future
						if(stype!="F")
						   ProcessStockTick(tick);      //This stores the latest close
					}
					else
					{
						//its a stock
						 if(stype=="F")
						 {
							 ProcessFundMessage(tick);   //Its a fundamental message - Store the details
						 }
						 else
						 {
							 ProcessStockTick(tick);     //This stores the latest close
						 }
					}
				}//end else
			}

		}//End method




		//QT Signals that there is data available
		void FeedConnector::ReceiveTicks()
		{
			int optVal;
			int optLen = sizeof(int);

			std::string new_tick_string="";    	
			std::string old_tick_string="";
			std::string EndWord =    "\n";	 
			std::string EndWordopt = "\r";
			bool EndMsg = false;
			int iResult ;

			//Make sure the socket is valid by asserting it - This will save future surprises
			if (getsockopt(clntSocket, SOL_SOCKET, 	SO_ACCEPTCONN, (char*)&optVal, 	&optLen) == SOCKET_ERROR)
			{
				std::cout << "Socket ID is: " << socket_id;
				__debugbreak();
			}

			do 
			{
				char tick_stream[60];//This is important 60 is the right size
				iResult =  recv(clntSocket,tick_stream,sizeof(tick_stream),0);
				if(iResult<0)
				{
					int a = WSAGetLastError();
					__debugbreak();
				}

				EndMsg = false;
				std::string tick_to_string = std::string(tick_stream,iResult); //T,20130820 00:45:44 //19
				
				//Check to see if its a time stamp only
				//Check if it has a termination
				if(tick_to_string.find(EndWord) != std::string::npos || tick_to_string.find(EndWordopt) != std::string::npos)
				{
					//Check if it has a T
					if(tick_to_string.substr(0,2)=="T,")
					{
					  int l = tick_to_string.length();
					  {
						  if(l==20)
						  {
							  continue; //Ignore next statements get more data from socket
						  }
					  }
					}
				}
				
				tick_to_string = old_tick_string + tick_to_string;

				//Check if this contains ENDMSG
				if(tick_to_string.find(EndWord) != std::string::npos || tick_to_string.find(EndWordopt) != std::string::npos)
				{
					EndMsg = true;
				}

				if(EndMsg)
				{
					//yes end of message - Now remove the EndWord
					int a = tick_to_string.find(EndWord);
					new_tick_string = tick_to_string.substr(0,a); 
					//Maybe the new message contains more info after the EndWord - save it
					old_tick_string = tick_to_string.substr(a + EndWord.length(),tick_to_string.length());
					CategorizeTick(new_tick_string);
				}
				else
				{
					old_tick_string = tick_to_string;
				}
			} while( iResult > 0 );    
		}

		//Connect to IQ Feed
		void FeedConnector::Connect()
		{

			if(connected)  { return; } //Just to make sure you dont connect more than once on an instance

			connected = true;

			

			int error = WSAStartup(0x0202, &wsadata);


			target.sin_family = AF_INET; // address family Internet
			target.sin_port = htons (5009); 
			target.sin_addr.s_addr = inet_addr ("127.0.0.1"); 

			clntSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
			

			if (::connect(clntSocket, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR)
			{
				//Could not connect
				__debugbreak();

			}
			else
			{
				std::string Version_Set = "S,SET PROTOCOL,5.0\r\n";

				//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				//IQ Feed                                                       80               70               71                 72                 11   13        64             12    14       82         65                  81         7        9     10      56                73                            19         34                23     60 
				std::string subscription = "S,SELECT UPDATE FIELDS,Symbol,Message Contents,Last Market Center,Most Recent Trade,Most Recent Trade Size, Bid,Bid Size,Bid Market Center,Ask,Ask Size,Bid TimeMS,Ask Market Center,Ask TimeMS,Total Volume,High,Low,Number of Trades Today,Most Recent Trade TimeMS,Open Interest,Expiration Date,Strike,TickID\r\n";
				//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				
				
				int ver_len = Version_Set.length();
				int sub_len = subscription.length();


				SocketSender(Version_Set);
				
				SocketSender(subscription);
				
				int iResult ;
				char buf[800];
				do 
				{
					
					iResult =  recv(clntSocket,buf,sizeof(buf),0);
					if(iResult<0)
					{
						int a = WSAGetLastError();
						__debugbreak();
					}
					std::string dta(buf);
					if (dta.substr(0,2)=="T,")
					{
						break;
					}
				} while( iResult > 0 );

				StartReceivingQuotes();
			}//end else
		}//End Method


		void FeedConnector::SocketSender(std::string dta)
		{
			int str_len = dta.length();
			int transmitted = 0 ;
			while(str_len != transmitted)
			{
				int temp;
				{//Begin Lock
					boost::lock_guard<boost::mutex> lock(mutex_socket);
				    temp = send(clntSocket,dta.c_str(),dta.length(),0);
				}
				transmitted = transmitted + temp;
			}
			Sleep(100);
		}


		std::string FeedConnector::GetSymbolOfOption(std::string OptionName)
		{
			return UpdateFeeds::ptrUpdateFeedsForm->GetOptionStock(OptionName);
			/*
			if(UpdateFeeds::OptionStockMap.find(OptionName) != UpdateFeeds::OptionStockMap.end())
			{
				return UpdateFeeds::OptionStockMap.at(OptionName);
			}
			else
			{
				__debugbreak();
				return "NotPresent";
			}*/
		}


		int FeedConnector::GetSymbolCategory(std::string symbol)
		{
			int len = symbol.length();

			if(len >= 7 )
			{
				//its an option
				return 1;
			}
			else
			{
				//It could be a future or stock
				if(symbol.find("@") != std::string::npos)
				{
					//its a future
					return 2;
				}
				else
				{
					//its a stock
					return 0;
				}
			}
		}//End Method

		//This method is responsible for subscribing to symbols from IQ Feed
		//returns 0 for stock, //return 1 for option //return 2 for future
		int FeedConnector::RegisterSymbol(std::string symbol)
		{
			std::string tx = std::string("w")+symbol+std::string("\n");

		    SocketSender(tx);

			/*
			int len = symbol.length();


			if(len >= 7 )
			{
				//its an option
				//We should also request the stock	
				//Now request the stock
				//std::string stockname = GetSymbolOfOption(symbol);
				//std::string stockreq = std::string("w")+stockname+std::string("\n");
				//SocketSender(stockreq);   //No need for this - As it is handled when building the automation symbol list
				return 1;
			}
			else
			{
				//It could be a future or stock
				if(symbol.find("@") != std::string::npos)
				{
					//its a future
					return 2;
				}
				else
				{
					//its a stock
					return 0;
				}

			}*/
			return 0;
		}//end method


		void FeedConnector::StartReceivingQuotes()
		{
			boost::thread t(&FeedConnector::ReceiveTicks,this);
		}

	}//end namespace WOPR

}//end namespace Framework
