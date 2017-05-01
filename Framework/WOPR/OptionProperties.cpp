#include "OptionProperties.h"
#include <iostream>
#include <map>
#include <intrin.h>  
#include <ctype.h>
#include <string>
#include "QString"

namespace Framework
{
	namespace WOPR
	{

		float OptionProperties::trunc(const float& d)
		{
			return (d>0) ? floor(d) : ceil(d) ; 
		}

		//True means they are equal
		bool OptionProperties::FloatCompareOptions(const float& a , const float& b)
		{
			if (trunc(100.0 * a) == trunc(100.0 * b))
			{
				return true;
			}
			return false;
		}


		//#############################################################################################################################################
		//#############################################################################################################################################
		int OptionProperties::RetrieveBidVolume(const std::string& symbol)
		{
			return BidVolumeTracker[symbol]; //If Not there then put it and return 0 ; 
		}

		void OptionProperties::UpdateBidVolume(const std::string& symbol, const int& volume)
		{
			
			std::map<std::string,int>& Refcontainer = BidVolumeTracker;
			
			
			//Check if the symbol exists
			if(Refcontainer.find(symbol) != Refcontainer.end())
			{
				Refcontainer[symbol]  +=  volume;
			}
			else
			{
				Refcontainer[symbol] = 0 + volume;
			}
		}//End Method

		
		int OptionProperties::RetrieveBidTrade(const std::string& symbol,const float& bid , const float& last, const int& volume,std::string& UpdateType)
		{
			std::map<std::string,int>& Refcontainer = BidTradeTracker;

			if(!QString(UpdateType.c_str()).contains("C")) //Last qualified trade
			{
				return Refcontainer[symbol]; //If Not there then put it and return 0 ; 
			}
			
			if(FloatCompareOptions(bid,last))
			{
				if(volume==0)
				{
					std::string t = "dsds";
				}
				
				UpdateBidVolume(symbol,volume);

				//Yes they are same - Check if tracker already has one
				if(Refcontainer.find(symbol) != Refcontainer.end())
				{
					//Tracker has one update it and return the result back;
					Refcontainer[symbol]+=1;
					return Refcontainer[symbol];
				}
				else
				{
					//The tracker had no record of this symbol - First Time !! Good for the symbol
					Refcontainer[symbol] = 1;
					return 1;
				}
				
			}
			else
			{
				//Refcontainer[symbol] = 0;
				//UpdateBidVolume(symbol,0);
				return Refcontainer[symbol]; //As they might not be equal but it might have previous values
			}
		}//End Method
		//#############################################################################################################################################
		//#############################################################################################################################################

		

		int OptionProperties::RetrieveAskVolume(const std::string& symbol)
		{
			return AskVolumeTracker[symbol];
		}

		void OptionProperties::UpdateAskVolume(const std::string& symbol, const int& volume)
		{
			std::map<std::string,int>& Refcontainer = AskVolumeTracker;

			//Check if the symbol exists
			if(Refcontainer.find(symbol) != Refcontainer.end())
			{
				Refcontainer[symbol]  +=  volume;
			}
			else
			{
				Refcontainer[symbol] = 0 + volume;
			}
		}

		int OptionProperties::RetrieveAskTrade(const std::string& symbol,const float& ask , const float& last, const int& volume,std::string& UpdateType)
		{
			std::map<std::string,int>& Refcontainer = AskTradeTracker;

			if(!QString(UpdateType.c_str()).contains("C")) //Last qualified trade
			{
				return Refcontainer[symbol]; //If Not there then put it and return 0 ; 
			}

			if(FloatCompareOptions(ask,last))
			{
				UpdateAskVolume(symbol,volume);
				//Yes they are same - Check if tracker already has one
				if(Refcontainer.find(symbol) != Refcontainer.end())
				{
					//Tracker has one update it and return the result back;
					Refcontainer[symbol]+=1;
					return Refcontainer[symbol];
				}
				else
				{
					//The tracker had no record of this symbol - First Time !! Good for the symbol
					Refcontainer[symbol] = 1;
					return 1;
				}
			}
			else
			{
				//Refcontainer[symbol] = 0;
				//UpdateAskVolume(symbol,0);
				//return 0;
				return Refcontainer[symbol];
			}
		}

		//#############################################################################################################################################
		//#############################################################################################################################################

		int OptionProperties::RetrieveNVolume(const std::string& symbol)
		{
			return NVolumeTracker[symbol];
		}

		void OptionProperties::UpdateNVolume(const std::string& symbol, const int& volume)
		{
			std::map<std::string,int>& Refcontainer = NVolumeTracker;

			//Check if the symbol exists
			if(Refcontainer.find(symbol) != Refcontainer.end())
			{
				Refcontainer[symbol]  +=  volume;
			}
			else
			{
				Refcontainer[symbol] = 0 + volume;
			}
		}

		int OptionProperties::RetrieveNTrade(const std::string& symbol,const float& bid , const float& ask,const float& last, const int& volume,std::string& UpdateType)
		{
			std::map<std::string,int>& Refcontainer = NTradeTracker;

			if(!QString(UpdateType.c_str()).contains("C")) //Last qualified trade
			{
				return Refcontainer[symbol]; //If Not there then put it and return 0 ; 
			}

			if(!FloatCompareOptions(bid,last) && !FloatCompareOptions(ask,last))
			{
				UpdateNVolume(symbol,volume);
				//Yes they are same - Check if tracker already has one
				if(Refcontainer.find(symbol) != Refcontainer.end())
				{
					//The tracker had no record of this symbol - First Time !! Good for the symbol
					Refcontainer[symbol] = 1;
					return 1;
				}
				else
				{
					//The tracker had no record of this symbol - First Time !! Good for the symbol
					Refcontainer[symbol] = 1;
					return 1;
				}
				
			}
			else
			{
				//Refcontainer[symbol] = 0;
				//UpdateNVolume(symbol,0);
				//return 0;
				return Refcontainer[symbol];
			}
		}
	}//End namespace
}//End namespace