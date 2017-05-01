// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include "MarketMakersBook.h"
#include <algorithm>
#include <iterator>


using namespace realtick_api;

#define QUOTE_TYPE_DROP 7
#define QUOTE_TYPE_UPDATE 2
#define QUOTE_TYPE_REFRESH 1


MarketMakersBook::MarketMakersBook()
{
}

MarketMakersBook::~MarketMakersBook()
{
}

void MarketMakersBook::Update( sp::shared_ptr<MarketMakersRecord>& rec )
{
	if( !rec->HasMktMkrId() || !rec->HasDispName() )
		return;

    bool bSetBid=false, bSetAsk=false, bClearBid=false, bClearAsk=false;

    if( rec->HasMktMkrBid() )
    {
        // The record may or may not contain the bid side.  If it does have the bid side,
        // then set or clear the bid, according to whether the values are nonzero.
        bSetBid = (rec->MktMkrBid().lVal != 0 && rec->MktMkrBidsize()!=0);
        bClearBid = !bSetBid;
    }

    if( rec->HasMktMkrAsk() )
    {
        // The record may or may not contain the ask side.  If it does have the ask side,
        // then set or clear the ask, according to whether the values are nonzero.
        bSetAsk = (rec->MktMkrAsk().lVal != 0 && rec->MktMkrAsksize() != 0);
        bClearAsk = !bSetAsk;
    }

    if (rec->HasQuoteUpdateType())
    {
        // if the quote is explicitely deleted, then ... delete it!
        if (rec->QuoteUpdateType() == QUOTE_TYPE_DROP)
        {
            bSetBid = bSetAsk = false;
            bClearBid = bClearAsk = true;
        }
    }

    if( bSetBid || bSetAsk || bClearBid || bClearAsk )
    {
		RTLock lock( _cs ); // don't allow Bids() or Asks() to copy from the map while we're updating it
        if (bSetBid)
        {
            _bids[rec->MktMkrId()] = rec;
        }
        if (bClearBid)
        {
			std::map<std::string, sp::shared_ptr<MarketMakersRecord> >::iterator it = _bids.find( rec->MktMkrId() );
			if( it != _bids.end() )
				_bids.erase(it);
        }
        if (bSetAsk)
        {
            _asks[rec->MktMkrId()] = rec;
        }
        if( bClearAsk )
        {
			std::map<std::string, sp::shared_ptr<MarketMakersRecord> >::iterator it = _asks.find( rec->MktMkrId() );
			if( it != _asks.end() )
				_asks.erase(it);
        }
    }

}


bool compare_bid(const sp::shared_ptr<MarketMakersRecord>& x, 
	const sp::shared_ptr<MarketMakersRecord>& y)
{
	double f, g;
	RTPriceHelper::PriceToDouble( x->MktMkrBid(), f );
	RTPriceHelper::PriceToDouble( y->MktMkrBid(), g );
	return f>g;
}

bool compare_ask(const sp::shared_ptr<MarketMakersRecord>& x, 
	const sp::shared_ptr<MarketMakersRecord>& y)
{
	double f, g;
	RTPriceHelper::PriceToDouble( x->MktMkrAsk(), f );
	RTPriceHelper::PriceToDouble( y->MktMkrAsk(), g );
	return f<g;
}


std::vector< sp::shared_ptr<MarketMakersRecord> > MarketMakersBook::Bids()
{
	std::vector< sp::shared_ptr<MarketMakersRecord> > lst;

	if( true ) // screate scope for lock
	{
		RTLock lock( _cs ); // prevent Update() from altering the map while we're copying
		lst.reserve(_bids.size());
		for( std::map<std::string, sp::shared_ptr<MarketMakersRecord> >::iterator it = _bids.begin(); it!=_bids.end(); ++it )
		{
			lst.push_back( it->second );
		}
	}

	std::sort( lst.begin(), lst.end(), compare_bid );
	return lst;
}


std::vector< sp::shared_ptr<MarketMakersRecord> > MarketMakersBook::Asks()
{
	std::vector< sp::shared_ptr<MarketMakersRecord> > lst;

	if( true ) // create scope for lock
	{
		RTLock lock( _cs ); // prevent Update() from altering the map while we're copying
		lst.reserve(_asks.size());
		for( std::map<std::string, sp::shared_ptr<MarketMakersRecord> >::iterator it = _asks.begin(); it!=_asks.end(); ++it )
		{
			lst.push_back( it->second );
		}
	}

	std::sort( lst.begin(), lst.end(), compare_ask );
	return lst;
}

