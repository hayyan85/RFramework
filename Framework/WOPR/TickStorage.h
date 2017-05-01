#ifndef TICK_STORAGE_HEADER
#define TICK_STORAGE_HEADER

#include <iostream>
#include <map>
#include "OptionTick.pb.h"
#include "boost/thread/mutex.hpp"
#include <vector>

namespace Framework
{
	namespace WOPR
	{
		class TickStorage 
		{
		private:
			std::map<std::string,Serializable::OptionTick_ser> latest_option_ticks;
		public:
			TickStorage();
			void Update_Option(std::string option_symbol,Serializable::OptionTick_ser& opt);
			bool IsOptionSymbolPresent(std::string option_symbol);
			Serializable::OptionTick_ser Retrieve_Option(std::string symbol);
			std::string SearchTickStoresForOption(std::string option_symbol); //Returns serialized object
			std::string GetOptionClose(std::vector<std::string> option_symbols);
		};
	}//end namespace
}//end namespace Framework
#endif // TICKSTORAGE
