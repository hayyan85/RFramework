// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include <string>
#include <RealTickApi.h>

class ExampleHelpers
{
public:
	static std::string fmtPrice( const realtick_api::RTPRICE& rtprc );
	static std::string fmtTime( const realtick_api::RTTIME& t );
	static std::string fmtDate( const realtick_api::RTDATE& t );

	static std::string goodFromString( int secondsFromNow );
	static std::string whereClauseString( int secondsFromNow );
};

