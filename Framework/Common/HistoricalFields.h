#ifndef Historical_Fields_Header
#define Historical_Fields_Header

#include <iostream>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 

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
	namespace Common
	{
		/*
		class HistoricalFields
		{
		    IMPLEMENT_SET_GET_METHOD(std::string,symbol);
			IMPLEMENT_SET_GET_METHOD(int,frequency);
			IMPLEMENT_SET_GET_METHOD(double,bar_high);
			IMPLEMENT_SET_GET_METHOD(double,bar_low);
			IMPLEMENT_SET_GET_METHOD(double,close);
			IMPLEMENT_SET_GET_METHOD(std::string,ftime);
			IMPLEMENT_SET_GET_METHOD(int,index_no);
			IMPLEMENT_SET_GET_METHOD(double,LCG);
			IMPLEMENT_SET_GET_METHOD(double,SCG);
			IMPLEMENT_SET_GET_METHOD(int,CGTrend)
			IMPLEMENT_SET_GET_METHOD(double,dailyHigh);
			IMPLEMENT_SET_GET_METHOD(double,dailyLow);
			IMPLEMENT_SET_GET_METHOD(double,HighZone);
			IMPLEMENT_SET_GET_METHOD(double,LowZone);
			IMPLEMENT_SET_GET_METHOD(int,hulltrend);
			IMPLEMENT_SET_GET_METHOD(double,Latr);
			IMPLEMENT_SET_GET_METHOD(double,Satr);
			IMPLEMENT_SET_GET_METHOD(double,slinSlope);
			IMPLEMENT_SET_GET_METHOD(double,llinSlope);
			IMPLEMENT_SET_GET_METHOD(double,r2Cyc5);
			IMPLEMENT_SET_GET_METHOD(double,r2Cyc6);
			IMPLEMENT_SET_GET_METHOD(double,r2Cyc7);
			IMPLEMENT_SET_GET_METHOD(double,avgCyc);
			IMPLEMENT_SET_GET_METHOD(double,bid);
			IMPLEMENT_SET_GET_METHOD(double,ask);
			IMPLEMENT_SET_GET_METHOD(double,ba_spread);
			IMPLEMENT_SET_GET_METHOD(double,last);
			IMPLEMENT_SET_GET_METHOD(double,today_change);
			IMPLEMENT_SET_GET_METHOD(double,percent_change);
			IMPLEMENT_SET_GET_METHOD(double,trade_volume);

			//This field gets incremented
			IMPLEMENT_SET_GET_METHOD(long,barNumber);

			//--
			IMPLEMENT_SET_GET_METHOD(double,LRange);
			IMPLEMENT_SET_GET_METHOD(double,VClose);
			IMPLEMENT_SET_GET_METHOD(double,ValueStd);
			IMPLEMENT_SET_GET_METHOD(double,ValueIncrement);

			HistoricalFields()
			{
				this->symbol = "";
				this->frequency = 0;
				this->bar_high = 0;
				this->bar_low = 0;
				this->close = 0;
				this->ftime ="";
				this->index_no =0;
				this->LCG =0;
				this->SCG =0;
				this->CGTrend=0;
				this->dailyHigh =0;
				this->dailyLow =0;
				this->HighZone = 0;
				this->LowZone =0;
				this->hulltrend=0;
				this->Latr =0;
				this->Satr = 0;
				this->slinSlope =0;
				this->llinSlope = 0;
				this->r2Cyc5 = 0;
				this->r2Cyc6 = 0;
				this->r2Cyc7 = 0;
				this->avgCyc = 0;
				this->bid = 0;
				this->ask = 0;
				this->ba_spread =0;
				this->last = 0;
				this->today_change = 0;
				this->percent_change=0;
				this->trade_volume = 0;
				this->barNumber = 0;

				this->LRange=0;
				this->VClose=0;
				this->ValueStd=0;
				this->ValueIncrement = 0;
			}//End constructor

			private: 
			friend class boost::serialization::access; 
			template <typename Archive> 
			void serialize(Archive &ar, const unsigned int version) 
			{ 
				ar & symbol; 
				ar & frequency;
				ar & bar_high;
				ar & bar_low;
				ar & close;
				ar & ftime;
				ar & index_no;
				ar & LCG;
				ar & SCG;
				ar & CGTrend;
				ar & dailyHigh;
				ar & dailyLow;
				ar & HighZone;
				ar & LowZone;
				ar & hulltrend;
				ar & Latr;
				ar & Satr;
				ar & slinSlope;
				ar & llinSlope;
				ar & r2Cyc5;
				ar & r2Cyc6;
				ar & r2Cyc7;
				ar & avgCyc;
				ar & bid;
				ar & ask;
				ar & ba_spread;
				ar & last;
				ar & today_change;
				ar & percent_change;
				ar & trade_volume;
				ar & barNumber;

				ar & LRange;
				ar & VClose;
				ar & ValueStd;
				ar & ValueIncrement;
			} 



		};
		*/
	}//end namespace WOPR
}//end namespace Framework

#endif 