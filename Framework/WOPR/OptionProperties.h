#ifndef OptionProperties_Header
#define OptionProperties_Header

#include <iostream>
#include <map>

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


namespace Framework
{
	namespace WOPR
	{
		class OptionProperties
		{
			private:
			std::map<std::string,int> BidTradeTracker;
			std::map<std::string,int> BidVolumeTracker;

			std::map<std::string,int> AskTradeTracker;
			std::map<std::string,int> AskVolumeTracker;

			std::map<std::string,int> NTradeTracker;
			std::map<std::string,int> NVolumeTracker;
			

			float trunc(const float& d);
			bool FloatCompareOptions(const float& a , const float& b);
			
			void UpdateBidVolume(const std::string& symbol, const int& volume);
			void UpdateAskVolume(const std::string& symbol, const int& volume);
			void UpdateNVolume(const std::string& symbol, const int& volume);

			public:
				int RetrieveBidTrade(const std::string& symbol,const float& bid , const float& last, const int& volume,std::string& UpdateType);
				int RetrieveBidVolume(const std::string& symbol);

				
				int RetrieveAskTrade(const std::string& symbol,const float& ask , const float& last, const int& volume,std::string& UpdateType);
				int RetrieveAskVolume(const std::string& symbol);

				int RetrieveNTrade(const std::string& symbol,const float& bid , const float& ask,const float& last, const int& volume,std::string& UpdateType);
				int RetrieveNVolume(const std::string& symbol);
		};
	}//end namespace WOPR
}//end namespace Framework
#endif 