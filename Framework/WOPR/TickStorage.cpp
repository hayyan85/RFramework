#include <iostream>
#include "TickStorage.h"
#include <map>
#include "OptionTick.pb.h"
#include "UpdateFeeds.h"
#include "FeedConnector.h"

namespace Framework
{
	namespace WOPR
	{	
	    TickStorage::TickStorage()
		{
			//Constructor
		}

			
		void TickStorage::Update_Option(std::string option_symbol,Serializable::OptionTick_ser& opt)
		{
			if(latest_option_ticks.find(option_symbol) != latest_option_ticks.end())
			{
				//present
				latest_option_ticks[option_symbol]= opt;
			}
			else
			{
				//Not present - So we are adding it
				latest_option_ticks[option_symbol]= opt;
			}
		}
         	
	    Serializable::OptionTick_ser TickStorage::Retrieve_Option(std::string symbol)
		{

			if(latest_option_ticks.find(symbol) != latest_option_ticks.end())
			{
				//present
				return latest_option_ticks[symbol];
			}
			else
			{
				//Not present -
				//This scenario should never arise
				//This symbol should not even be present - Why is the client requesting it ?
				__debugbreak();
			}
		}

		//Tells whether the option symbol is present or not 
		bool TickStorage::IsOptionSymbolPresent(std::string option_symbol)
		{
			if(latest_option_ticks.find(option_symbol) != latest_option_ticks.end())
			{
				//present
				return true;
			}
			else
			{
				return false;
			}
		}


		std::string TickStorage::SearchTickStoresForOption(std::string option_symbol)
		{
			std::vector<Framework::WOPR::FeedConnector*> fc = UpdateFeeds::ptrUpdateFeedsForm->ReturnAllFeedConnectors();
			for(int i= 0 ; i<fc.size();i++)
			{
				if(fc[i]->ReturnTickStorage().IsOptionSymbolPresent(option_symbol))
				{
					Serializable::OptionTick_ser otick = fc[i]->ReturnTickStorage().Retrieve_Option(option_symbol);
					return otick.SerializeAsString();
				}
			}
		}


		std::string TickStorage::GetOptionClose(std::vector<std::string> option_symbols)
		{
			Serializable::Option_collection_ser ocs;
			for(int a=0;a<option_symbols.size();a++)
			{
				std::vector<Framework::WOPR::FeedConnector*> fc = UpdateFeeds::ptrUpdateFeedsForm->ReturnAllFeedConnectors();
				for(int i= 0 ; i<fc.size();i++)
				{
					if(fc[i]->ReturnTickStorage().IsOptionSymbolPresent(option_symbols[a]))
					{
						Serializable::OptionTick_ser* o = ocs.add_option_tick_collection();
						Serializable::OptionTick_ser otick = fc[i]->ReturnTickStorage().Retrieve_Option(option_symbols[a]);
						*o = otick;
					}
				}

			}
			return ocs.SerializeAsString();
		}//End Method
	}//end namespace
}//end Framework