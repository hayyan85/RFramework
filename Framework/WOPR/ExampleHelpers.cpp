// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include "ExampleHelpers.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <time.h>

using namespace std;
using namespace realtick_api;

#ifndef _WIN32
#ifndef _snprintf_s
#define _snprintf_s snprintf
#endif
#endif



std::string ExampleHelpers::fmtPrice( const RTPRICE& rtprc )
{
	double prc;
	RTPriceHelper::PriceToDouble(rtprc, prc);

	std::ostringstream str;
	str << fixed << setprecision(2) << prc;
	return str.str();
}

std::string ExampleHelpers::fmtTime( const RTTIME& t )
{
	std::ostringstream str;
	str << setfill('0') << setw(2) << t.wMinutes/60 << ":" << setiosflags(ios::right)
						<< setfill('0') << setw(2) << t.wMinutes%60 << ":" << setw(2) << t.wSeconds;
	return str.str();
}

std::string ExampleHelpers::fmtDate( const RTDATE& t )
{
	std::ostringstream str;
	str << setfill('0') << setw(4) << t.iYear << "-" << setiosflags(ios::right)
						<< setfill('0') << setw(2) << (int)t.cMonth << "-" << setw(2) << (int)t.cDay;
	return str.str();
}

std::string ExampleHelpers::goodFromString( int secondsFromNow )
{
	time_t start_time = time(0) + 300;
	struct tm *ptm;
#ifdef _WIN32
	struct tm tm;
	localtime_s( &tm, &start_time );
	ptm = &tm;
#else
	ptm = localtime( &start_time );
#endif
	char tmp[245];
	_snprintf_s( tmp, sizeof(tmp), "%04d-%02d-%02d %02d:%02d:%02d",
		ptm->tm_year + 1900, ptm->tm_mon+1, ptm->tm_mday,
		ptm->tm_hour, ptm->tm_min, ptm->tm_sec );

	return tmp;
}

std::string ExampleHelpers::whereClauseString( int secondsFromNow )
{
	time_t now = time(0) + secondsFromNow;
	struct tm *ptm;
#ifdef _WIN32
	struct tm tm;
	localtime_s( &tm, &now );
	ptm = &tm;
#else
	ptm = localtime( &now );
#endif

	char tmp[16];
	_snprintf_s( tmp, sizeof(tmp), "%04d/%02d/%02d",
		ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday );

	return tmp;
}


