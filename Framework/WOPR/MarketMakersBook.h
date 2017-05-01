// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include "ApiRecords.h"
#include <map>
#include <memory>
#include <vector>

// This helper class demonstrates how to process level-2 bid and ask updates from the
// data feed, updating or deleting quotes as appropriate.  At any time the Bids() and
// Asks() methods can be called to retrieve a current, sorted snapshot of the market.
class MarketMakersBook
{
public:
	MarketMakersBook();
	~MarketMakersBook();
	void Update( sp::shared_ptr<MarketMakersRecord>& rec );
	std::vector< sp::shared_ptr<MarketMakersRecord> > Bids();
	std::vector< sp::shared_ptr<MarketMakersRecord> > Asks();

private:
	std::map<std::string, sp::shared_ptr<MarketMakersRecord> > _bids, _asks;
	realtick_api::RTCriticalSection _cs;
};

