#include <iostream>
#include <intrin.h>  
#include "QueSilo.h"
#include "FeedConnector.h"
#include "TDisplay.h"
#include "UpdateFeeds.h"
#include "OptionTick.pb.h"
#include "StockTick.pb.h"
#include "FeedProcessor.h"

/*Log4cplus Files does not work with UNICODE Preprocessor*/
#include <log4cplus/fileappender.h> 
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>


namespace Framework
{
	namespace WOPR
	{
	    QueueSilo::QueueSilo(QObject *parent /* = 0 */)
		{
			boost::thread s(&QueueSilo::Start_Reading_Option_Feed_Silo,this); //Start the consumer
			boost::thread t(&QueueSilo::Start_Reading_Stock_Feed_Silo,this); //Start the consumer
		}
		


		//----------------------------------------------------------------------------------------------------------------------------------------------------
		//------------------------------THIS SECTION DEALS WITH STOCKS----------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------------------------------------
		void QueueSilo::Add_Feed_To_Stock_Silo(Serializable::StockTick_ser* lfeedTuple)
		{
			try
			{
				{//Begin Lock
					boost::lock_guard<boost::mutex> lock(mutex_Silo_Stock);
					Live_Feed_Silo_Stock.push_back(lfeedTuple);
				}
				condition_consumer_silo_Stocks.notify_one(); //Start Reading data from silo
			}
			catch (std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"FeedAdder" + err );
			}
		}//end method
		
		
		//This method attempts to read live feeds stored in the Live_Feed_Silo
		//It will be started as soon as instance of this class is created.
		void QueueSilo::Start_Reading_Stock_Feed_Silo()
		{
			int cont_size=0;
			Serializable::StockTick_ser* lfeedTuple;	
			LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Silo Consumer (STOCK) Thread started - OK");
			while(true)
			{
				{//Lock
					try
					{
						boost::unique_lock<boost::mutex> lock(mutex_Silo_Stock);
						while(Live_Feed_Silo_Stock.empty()) 
						{
							condition_consumer_silo_Stocks.wait(lock); 
						}//Block if empty - for spurious wakeup

						if(!Live_Feed_Silo_Stock.empty())
						{
							lfeedTuple = Live_Feed_Silo_Stock.front();
							cont_size  = Live_Feed_Silo_Stock.size();
							Live_Feed_Silo_Stock.pop_front();
						}
					}
					catch (std::exception& e)
					{
						__debugbreak();
						std::string err = e.what();
						LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,e.what());
					}

				}//Unlock				
				try
				{
					if(lfeedTuple->symbol()!="")
					{
						FeedProcessor().ProcessStockTick(lfeedTuple);
						delete lfeedTuple;
					}

				} catch (std::exception& e)
				{
					__debugbreak();
					std::string err = e.what();
					LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Consumer" + err);
				}
			}//end while

			LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Stock Silo Consumer Thread Exited - Critical Error : Messages wont be processed Now");
		}//end method
		
		//-----------------------------------------------------------------------------------------------------------------------------------------
		//----------------------------------------------------END STOCK SILO-----------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------------------------------------------------------






		//----------------------------------------------------------------------------------------------------------------------------------------------------
		//------------------------------THIS SECTION DEALS WITH OPTIONS---------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------------------------------------

		void QueueSilo::Add_Feed_To_Option_Silo(Serializable::OptionTick_ser* lfeedTuple)
		{
			try
			{
				{//Begin Lock
					boost::lock_guard<boost::mutex> lock(mutex_Silo_Option);
		 		    Live_Feed_Silo_Option.push_back(lfeedTuple);
					//QTPrintTotalQuantity(Live_Feed_Silo.size(),lfeedTuple->symbol());
				}
				condition_consumer_silo_Options.notify_one(); //Start Reading data from silo
				
			}
			catch (std::exception& e)
			{
				__debugbreak();
				std::string err =  e.what();
				LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"FeedAdder" + err );
			}
		}//end method
		

		
		//This method attempts to read live feeds stored in the Live_Feed_Silo
		//It will be started as soon as instance of this class is created.
		void QueueSilo::Start_Reading_Option_Feed_Silo()
		{
			int cont_size=0;
			Serializable::OptionTick_ser* lfeedTuple;	
			LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Silo Consumer Thread started - OK");
			while(true)
				{
					{//Lock
					    try
						{
							boost::unique_lock<boost::mutex> lock(mutex_Silo_Option);
							while(Live_Feed_Silo_Option.empty()) { condition_consumer_silo_Options.wait(lock); }//Block if empty - for spurious wakeup

							if(!Live_Feed_Silo_Option.empty())
							{
								lfeedTuple = Live_Feed_Silo_Option.front();
								cont_size  = Live_Feed_Silo_Option.size();
								Live_Feed_Silo_Option.pop_front();
							}
						}
						catch (std::exception& e)
						{
							__debugbreak();
							std::string err = e.what();
							LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,e.what());
						}
						
					}//Unlock				
					try
					{
							if(lfeedTuple->symbol()!="" && lfeedTuple->timestamp()!="")
							{
								FeedProcessor().ProcessOptionTick(lfeedTuple);
								delete lfeedTuple;
							}
							
					 } catch (std::exception& e)
					 {
					 	__debugbreak();
						std::string err = e.what();
						LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Consumer" + err);
					 }
				}//end while
			    
			LOG4CPLUS_INFO(UpdateFeeds::WOPR_Logger,"Option Silo Consumer Thread Exited - Critical Error : Messages wont be processed Now");
		}//end method
		
		//-----------------------------------------------------------------------------------------------------------------------------------------
		//----------------------------------------------------END OPTIONS SILO---------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------------------------------------------------------


	}//end namespace WOPR
}//end namespace Framework
