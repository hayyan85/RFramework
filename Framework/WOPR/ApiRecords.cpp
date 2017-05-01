// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include "ApiRecords.h"
#include <string.h>	// for strlen
static void ReadString( int32_t type, realtick_api::RTDataReader& rd, std::string& val, bool& flag )
{
   if( type==TYPE_STRING )
   {
      const char* sz = nullptr;
      if( rd.ReadString(sz) )
      {
         val = sz;
         flag = true;
      }
   }
}

static void ReadPrice( int32_t type, realtick_api::RTDataReader& rd, realtick_api::RTPRICE& val, bool& flag )
{
   if( type==TYPE_PRICE )
   {
      realtick_api::RTPRICE x;
      if( rd.ReadPrice(x) )
      {
         val = x;
         flag = true;
      }
   }
}

static void ReadDouble( int32_t type, realtick_api::RTDataReader& rd, double& val, bool& flag )
{
   if( type==TYPE_DOUBLE )
   {
      double x = 0;
      if( rd.ReadDouble(x) )
      {
         val = x;
         flag = true;
      }
   }
}

static void ReadInt( int32_t type, realtick_api::RTDataReader& rd, int& val, bool& flag )
{
   if( type==TYPE_SHORT )
   {
      int16_t x = 0;
      if( rd.ReadShort(x) )
      {
         val = x;
         flag = true;
      }
   }
   else if( type==TYPE_LONG )
   {
      int32_t x = 0;
      if( rd.ReadLong(x) )
      {
         val = x;
         flag = true;
      }
   }
}

static void ReadDate( int32_t type, realtick_api::RTDataReader& rd, realtick_api::RTDATE& val, bool& flag )
{
   if( type==TYPE_DATE )
   {
      realtick_api::RTDATE x;
      if( rd.ReadDate(x) )
      {
         val = x;
         flag = true;
      }
   }
}

static void ReadTime( int32_t type, realtick_api::RTDataReader& rd, realtick_api::RTTIME& val, bool& flag )
{
   if( type==TYPE_TIME )
   {
      realtick_api::RTTIME x;
      if( rd.ReadTime(x) )
      {
         val = x;
         flag = true;
      }
   }
}

static void ReadIntVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<int>& val, bool& flag )
{
   if( type==TYPE_VECTOR_INT )
   {
      const int16_t* x;
      uint32_t n;
      if( rd.ReadShortVector(x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
            val.push_back( x[i] );
         flag = true;
      }
   }
   else if( type==TYPE_VECTOR_LONG )
   {
      const int32_t* x;
      uint32_t n;
      if( rd.ReadLongVector(x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
            val.push_back( x[i] );
         flag = true;
      }
   }
}

static void ReadDoubleVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<double>& val, bool& flag )
{
   if( type==TYPE_VECTOR_DOUBLE )
   {
      const double* x;
      uint32_t n;
      if( rd.ReadDoubleVector(x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
            val.push_back( x[i] );
         flag = true;
      }
   }
}

static void ReadPriceVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<realtick_api::RTPRICE>& val, bool& flag )
{
   if( type==TYPE_VECTOR_LPACK )
   {
      const int32_t* x;
      uint16_t base;
      uint32_t n;
      if( rd.ReadPriceVector(base, x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
         {
            realtick_api::RTPRICE prc;
            prc.wBase = base;
            prc.lVal = x[i];
            val.push_back( prc );
         }
         flag = true;
      }
   }
}

static void ReadDateVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<realtick_api::RTDATE>& val, bool& flag )
{
   if( type==TYPE_VECTOR_DATE )
   {
      const realtick_api::RTDATE* x;
      uint32_t n;
      if( rd.ReadDateVector(x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
            val.push_back( x[i] );
         flag = true;
      }
   }
}

static void ReadTimeVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<realtick_api::RTTIME>& val, bool& flag )
{
   if( type==TYPE_VECTOR_TIME )
   {
      const realtick_api::RTTIME* x;
      uint32_t n;
      if( rd.ReadTimeVector(x, n) )
      {
         for( uint32_t i=0; i<n; i++ )
            val.push_back( x[i] );
         flag = true;
      }
   }
}

static void ReadStringVec( int32_t type, realtick_api::RTDataReader& rd, std::vector<std::string>& val, bool& flag )
{
   if( type==TYPE_VECTOR_STRING )
   {
      const char* x;
      uint32_t n;
      uint32_t tot;
      if( rd.ReadStringVector(x, n, tot) )
      {
         int offset = 0;
         for( uint32_t i=0; i<n; i++ )
         {
            val.push_back( x+offset );
            offset += strlen(x+offset) + 1;
         }
         flag = true;
      }
   }
}


LivequoteRecord::LivequoteRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_SYMBOL_ID:
         ReadInt( type, rd, _SymbolId, _HasSymbolId );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_TRD_UNITS:
         ReadString( type, rd, _TrdUnits, _HasTrdUnits );
         break;
      case T_EXCH_NAME:
         ReadString( type, rd, _ExchName, _HasExchName );
         break;
      case T_EXCHID:
         ReadString( type, rd, _Exchid, _HasExchid );
         break;
      case T_EXCHZONE:
         ReadString( type, rd, _Exchzone, _HasExchzone );
         break;
      case T_STARTTIME:
         ReadTime( type, rd, _Starttime, _HasStarttime );
         break;
      case T_STOPTIME:
         ReadTime( type, rd, _Stoptime, _HasStoptime );
         break;
      case T_EXCHDATE:
         ReadDate( type, rd, _Exchdate, _HasExchdate );
         break;
      case T_EXCHTIM:
         ReadTime( type, rd, _Exchtim, _HasExchtim );
         break;
      case T_SESSION:
         ReadInt( type, rd, _Session, _HasSession );
         break;
      case T_CURRENT_SESSION:
         ReadInt( type, rd, _CurrentSession, _HasCurrentSession );
         break;
      case T_STARTSESS2:
         ReadTime( type, rd, _Startsess2, _HasStartsess2 );
         break;
      case T_TABLE_ID:
         ReadInt( type, rd, _TableId, _HasTableId );
         break;
      case T_TRDPRC_1:
         ReadPrice( type, rd, _Trdprc1, _HasTrdprc1 );
         break;
      case T_TRDPRC_2:
         ReadPrice( type, rd, _Trdprc2, _HasTrdprc2 );
         break;
      case T_TRDPRC_3:
         ReadPrice( type, rd, _Trdprc3, _HasTrdprc3 );
         break;
      case T_TRDPRC_4:
         ReadPrice( type, rd, _Trdprc4, _HasTrdprc4 );
         break;
      case T_TRDPRC_5:
         ReadPrice( type, rd, _Trdprc5, _HasTrdprc5 );
         break;
      case T_NETCHNG_1:
         ReadPrice( type, rd, _Netchng1, _HasNetchng1 );
         break;
      case T_HIGH_1:
         ReadPrice( type, rd, _High1, _HasHigh1 );
         break;
      case T_LOW_1:
         ReadPrice( type, rd, _Low1, _HasLow1 );
         break;
      case T_CURRENCY:
         ReadString( type, rd, _Currency, _HasCurrency );
         break;
      case T_TRD_DATE:
         ReadDate( type, rd, _TrdDate, _HasTrdDate );
         break;
      case T_TRDTIM_1:
         ReadTime( type, rd, _Trdtim1, _HasTrdtim1 );
         break;
      case T_OPEN_PRC:
         ReadPrice( type, rd, _OpenPrc, _HasOpenPrc );
         break;
      case T_HST_CLOSE:
         ReadPrice( type, rd, _HstClose, _HasHstClose );
         break;
      case T_BID:
         ReadPrice( type, rd, _Bid, _HasBid );
         break;
      case T_ASK:
         ReadPrice( type, rd, _Ask, _HasAsk );
         break;
      case T_BIDSIZE:
         ReadInt( type, rd, _Bidsize, _HasBidsize );
         break;
      case T_ASKSIZE:
         ReadInt( type, rd, _Asksize, _HasAsksize );
         break;
      case T_ACVOL_1:
         ReadInt( type, rd, _Acvol1, _HasAcvol1 );
         break;
      case T_EARNINGS:
         ReadPrice( type, rd, _Earnings, _HasEarnings );
         break;
      case T_PERATIO:
         ReadPrice( type, rd, _Peratio, _HasPeratio );
         break;
      case T_DIVPAYDATE:
         ReadDate( type, rd, _Divpaydate, _HasDivpaydate );
         break;
      case T_EXDIVDATE:
         ReadDate( type, rd, _Exdivdate, _HasExdivdate );
         break;
      case T_TRDXID_1:
         ReadString( type, rd, _Trdxid1, _HasTrdxid1 );
         break;
      case T_BIDEXID:
         ReadString( type, rd, _Bidexid, _HasBidexid );
         break;
      case T_ASKEXID:
         ReadString( type, rd, _Askexid, _HasAskexid );
         break;
      case T_LOT_SIZE:
         ReadInt( type, rd, _LotSize, _HasLotSize );
         break;
      case T_SETTLE:
         ReadPrice( type, rd, _Settle, _HasSettle );
         break;
      case T_DIVIDEND:
         ReadPrice( type, rd, _Dividend, _HasDividend );
         break;
      case T_NUM_MOVES:
         ReadInt( type, rd, _NumMoves, _HasNumMoves );
         break;
      case T_HSTCLSDATE:
         ReadDate( type, rd, _Hstclsdate, _HasHstclsdate );
         break;
      case T_HIGH_52:
         ReadPrice( type, rd, _High52, _HasHigh52 );
         break;
      case T_LOW_52:
         ReadPrice( type, rd, _Low52, _HasLow52 );
         break;
      case T_ISSUE_DATE:
         ReadDate( type, rd, _IssueDate, _HasIssueDate );
         break;
      case T_BID_TICK_1:
         ReadString( type, rd, _BidTick1, _HasBidTick1 );
         break;
      case T_DAYS_MAT:
         ReadInt( type, rd, _DaysMat, _HasDaysMat );
         break;
      case T_YLD_MATURITY:
         ReadDouble( type, rd, _YldMaturity, _HasYldMaturity );
         break;
      case T_TDY_OF_CLS:
         ReadPrice( type, rd, _TdyOfCls, _HasTdyOfCls );
         break;
      case T_BUYER_ID:
         ReadInt( type, rd, _BuyerId, _HasBuyerId );
         break;
      case T_SELLER_ID:
         ReadInt( type, rd, _SellerId, _HasSellerId );
         break;
      case T_TRDVOL_1:
         ReadInt( type, rd, _Trdvol1, _HasTrdvol1 );
         break;
      case T_BASISVALUE:
         ReadDouble( type, rd, _Basisvalue, _HasBasisvalue );
         break;
      case T_STATUS_1:
         ReadInt( type, rd, _Status1, _HasStatus1 );
         break;
      case T_LOT_SIZE_A:
         ReadDouble( type, rd, _LotSizeA, _HasLotSizeA );
         break;
      case T_SEG_TEXT:
         ReadString( type, rd, _SegText, _HasSegText );
         break;
      case T_BID_TIME:
         ReadTime( type, rd, _BidTime, _HasBidTime );
         break;
      case T_ASK_TIME:
         ReadTime( type, rd, _AskTime, _HasAskTime );
         break;
      case T_ACT_TP_1:
         ReadString( type, rd, _ActTp1, _HasActTp1 );
         break;
      case T_OPEN_TIME:
         ReadTime( type, rd, _OpenTime, _HasOpenTime );
         break;
      case T_HIGH_TIME:
         ReadTime( type, rd, _HighTime, _HasHighTime );
         break;
      case T_SETTLEDATE:
         ReadDate( type, rd, _Settledate, _HasSettledate );
         break;
      case T_LOW_TIME:
         ReadTime( type, rd, _LowTime, _HasLowTime );
         break;
      case T_HIGH52_DATE:
         ReadDate( type, rd, _High52Date, _HasHigh52Date );
         break;
      case T_LOW52_DATE:
         ReadDate( type, rd, _Low52Date, _HasLow52Date );
         break;
      case T_IRGCOND:
         ReadInt( type, rd, _Irgcond, _HasIrgcond );
         break;
      case T_PARITY99:
         ReadPrice( type, rd, _Parity99, _HasParity99 );
         break;
      case T_HST_VOL:
         ReadInt( type, rd, _HstVol, _HasHstVol );
         break;
      case T_SEQNUM:
         ReadInt( type, rd, _Seqnum, _HasSeqnum );
         break;
      case T_RESTRICT:
         ReadString( type, rd, _Restrict, _HasRestrict );
         break;
      case T_STATUS:
         ReadString( type, rd, _Status, _HasStatus );
         break;
      case T_MG_STATE:
         ReadString( type, rd, _MgState, _HasMgState );
         break;
      case T_DELAY:
         ReadInt( type, rd, _Delay, _HasDelay );
         break;
      case T_NOMINAL_CURRENCY:
         ReadString( type, rd, _NominalCurrency, _HasNominalCurrency );
         break;
      case T_ISSUERS_DOMICILE:
         ReadString( type, rd, _IssuersDomicile, _HasIssuersDomicile );
         break;
      case T_ISSUERS_SECTOR:
         ReadInt( type, rd, _IssuersSector, _HasIssuersSector );
         break;
      case T_ISSUE_PRICE:
         ReadPrice( type, rd, _IssuePrice, _HasIssuePrice );
         break;
      case T_WARRANT_CONV_NUM:
         ReadPrice( type, rd, _WarrantConvNum, _HasWarrantConvNum );
         break;
      case T_WARRANT_CONV_DENOM:
         ReadPrice( type, rd, _WarrantConvDenom, _HasWarrantConvDenom );
         break;
      case T_DIVIDEND_1_DATE:
         ReadDate( type, rd, _Dividend1Date, _HasDividend1Date );
         break;
      case T_NSIN_1:
         ReadString( type, rd, _Nsin1, _HasNsin1 );
         break;
      case T_NSIN_2:
         ReadString( type, rd, _Nsin2, _HasNsin2 );
         break;
      case T_NSIN_3:
         ReadString( type, rd, _Nsin3, _HasNsin3 );
         break;
      case T_NSIN_4:
         ReadString( type, rd, _Nsin4, _HasNsin4 );
         break;
      case T_NSIN_5:
         ReadString( type, rd, _Nsin5, _HasNsin5 );
         break;
      case T_NSIN_6:
         ReadString( type, rd, _Nsin6, _HasNsin6 );
         break;
      case T_THEO_OPEN:
         ReadPrice( type, rd, _TheoOpen, _HasTheoOpen );
         break;
      case T_IMBALANCE:
         ReadInt( type, rd, _Imbalance, _HasImbalance );
         break;
      case T_CONTRACTS:
         ReadInt( type, rd, _Contracts, _HasContracts );
         break;
      case T_COUNTERVALUE:
         ReadPrice( type, rd, _Countervalue, _HasCountervalue );
         break;
      case T_OPENING_VOL:
         ReadInt( type, rd, _OpeningVol, _HasOpeningVol );
         break;
      case T_OPENING_CONTRACTS:
         ReadInt( type, rd, _OpeningContracts, _HasOpeningContracts );
         break;
      case T_OPENING_NUMBER:
         ReadInt( type, rd, _OpeningNumber, _HasOpeningNumber );
         break;
      case T_SUSP_TIME:
         ReadTime( type, rd, _SuspTime, _HasSuspTime );
         break;
      case T_MINIMUM_SIZE:
         ReadInt( type, rd, _MinimumSize, _HasMinimumSize );
         break;
      case T_TICK_SIZE:
         ReadPrice( type, rd, _TickSize, _HasTickSize );
         break;
      case T_SUBMARKET:
         ReadString( type, rd, _Submarket, _HasSubmarket );
         break;
      case T_OPT_VOL:
         ReadInt( type, rd, _OptVol, _HasOptVol );
         break;
      case T_PUT_VOL:
         ReadInt( type, rd, _PutVol, _HasPutVol );
         break;
      case T_CALL_VOL:
         ReadInt( type, rd, _CallVol, _HasCallVol );
         break;
      case T_AUCTION_PRICE:
         ReadPrice( type, rd, _AuctionPrice, _HasAuctionPrice );
         break;
      case T_AUCTION_SIZE:
         ReadInt( type, rd, _AuctionSize, _HasAuctionSize );
         break;
      case T_AUCTION_TIME:
         ReadTime( type, rd, _AuctionTime, _HasAuctionTime );
         break;
      case T_NSIN_TRADING:
         ReadString( type, rd, _NsinTrading, _HasNsinTrading );
         break;
      case T_AUCTION_END:
         ReadTime( type, rd, _AuctionEnd, _HasAuctionEnd );
         break;
      case T_BID_TICK_2:
         ReadString( type, rd, _BidTick2, _HasBidTick2 );
         break;
      case T_NAS_CROSS_TYPE:
         ReadString( type, rd, _NasCrossType, _HasNasCrossType );
         break;
      case T_NAS_IMBALANCE:
         ReadInt( type, rd, _NasImbalance, _HasNasImbalance );
         break;
      case T_NAS_PAIRED:
         ReadInt( type, rd, _NasPaired, _HasNasPaired );
         break;
      case T_NAS_REFERENCE_PRICE:
         ReadPrice( type, rd, _NasReferencePrice, _HasNasReferencePrice );
         break;
      case T_NAS_FAR_IND_CLEARING:
         ReadPrice( type, rd, _NasFarIndClearing, _HasNasFarIndClearing );
         break;
      case T_NAS_NEAR_IND_CLEARING:
         ReadPrice( type, rd, _NasNearIndClearing, _HasNasNearIndClearing );
         break;
      case T_NYSE_IMBAL_TYPE:
         ReadString( type, rd, _NyseImbalType, _HasNyseImbalType );
         break;
      case T_NYSE_IMBALANCE:
         ReadInt( type, rd, _NyseImbalance, _HasNyseImbalance );
         break;
      case T_OFFICIAL_PRICE:
         ReadPrice( type, rd, _OfficialPrice, _HasOfficialPrice );
         break;
      case T_ARCA_MATCH_PRICE:
         ReadPrice( type, rd, _ArcaMatchPrice, _HasArcaMatchPrice );
         break;
      case T_ARCA_IMBALANCE_VOLUME:
         ReadInt( type, rd, _ArcaImbalanceVolume, _HasArcaImbalanceVolume );
         break;
      case T_ARCA_MATCH_VOLUME:
         ReadInt( type, rd, _ArcaMatchVolume, _HasArcaMatchVolume );
         break;
      case T_ARCA_IMBALANCE_SIG:
         ReadInt( type, rd, _ArcaImbalanceSig, _HasArcaImbalanceSig );
         break;
      case T_ARCA_AOT:
         ReadTime( type, rd, _ArcaAot, _HasArcaAot );
         break;
      case T_SYMBOL_DESC:
         ReadString( type, rd, _SymbolDesc, _HasSymbolDesc );
         break;
      case T_COMPANY_NAME:
         ReadString( type, rd, _CompanyName, _HasCompanyName );
         break;
      case T_MINMOVE:
         ReadInt( type, rd, _Minmove, _HasMinmove );
         break;
      case T_MAXMOVE:
         ReadInt( type, rd, _Maxmove, _HasMaxmove );
         break;
      case T_CHANGE_LAST:
         ReadPrice( type, rd, _ChangeLast, _HasChangeLast );
         break;
      case T_COMMODITY_NAME:
         ReadString( type, rd, _CommodityName, _HasCommodityName );
         break;
      case T_MONEY_FLOW:
         ReadInt( type, rd, _MoneyFlow, _HasMoneyFlow );
         break;
      case T_VWAP:
         ReadDouble( type, rd, _Vwap, _HasVwap );
         break;
      case T_SUM_PV:
         ReadDouble( type, rd, _SumPv, _HasSumPv );
         break;
      case T_VWAP_VOL:
         ReadInt( type, rd, _VwapVol, _HasVwapVol );
         break;
      case T_SALE_CONDITION:
         ReadInt( type, rd, _SaleCondition, _HasSaleCondition );
         break;
      case T_SALE_CONDITION_PRICE:
         ReadPrice( type, rd, _SaleConditionPrice, _HasSaleConditionPrice );
         break;
      case T_SALE_CONDITION_VOLUME:
         ReadInt( type, rd, _SaleConditionVolume, _HasSaleConditionVolume );
         break;
      case T_SALE_CONDITION_TIME:
         ReadTime( type, rd, _SaleConditionTime, _HasSaleConditionTime );
         break;
      case T_SALE_CONDITION_XID:
         ReadString( type, rd, _SaleConditionXid, _HasSaleConditionXid );
         break;
      case T_SALE_CONDITION_DATE:
         ReadDate( type, rd, _SaleConditionDate, _HasSaleConditionDate );
         break;
      case T_BID_CONDITION:
         ReadString( type, rd, _BidCondition, _HasBidCondition );
         break;
      case T_ASK_CONDITION:
         ReadString( type, rd, _AskCondition, _HasAskCondition );
         break;
      case T_BID_DATE:
         ReadDate( type, rd, _BidDate, _HasBidDate );
         break;
      case T_ASK_DATE:
         ReadDate( type, rd, _AskDate, _HasAskDate );
         break;
      case T_INDICATIVE_PRICE:
         ReadPrice( type, rd, _IndicativePrice, _HasIndicativePrice );
         break;
      case T_SMALLCAP:
         ReadString( type, rd, _Smallcap, _HasSmallcap );
         break;
      case T_ISIN_NO:
         ReadString( type, rd, _IsinNo, _HasIsinNo );
         break;
      case T_SUSPENDED_INDICATOR:
         ReadInt( type, rd, _SuspendedIndicator, _HasSuspendedIndicator );
         break;
      case T_SESS_CLOSE_DATE:
         ReadDate( type, rd, _SessCloseDate, _HasSessCloseDate );
         break;
      case T_SEDOL:
         ReadString( type, rd, _Sedol, _HasSedol );
         break;
      case T_CAT:
         ReadString( type, rd, _Cat, _HasCat );
         break;
      case T_INTRADAY_HIGH_COUNT:
         ReadInt( type, rd, _IntradayHighCount, _HasIntradayHighCount );
         break;
      case T_INTRADAY_LOW_COUNT:
         ReadInt( type, rd, _IntradayLowCount, _HasIntradayLowCount );
         break;
      case T_LRP_BID:
         ReadPrice( type, rd, _LrpBid, _HasLrpBid );
         break;
      case T_LRP_ASK:
         ReadPrice( type, rd, _LrpAsk, _HasLrpAsk );
         break;
      case T_LRP_TIME:
         ReadTime( type, rd, _LrpTime, _HasLrpTime );
         break;
      case T_LATENCY_1:
         ReadInt( type, rd, _Latency1, _HasLatency1 );
         break;
      case T_DIVIDEND_YIELD:
         ReadPrice( type, rd, _DividendYield, _HasDividendYield );
         break;
      case T_DIVIDEND_RATE:
         ReadPrice( type, rd, _DividendRate, _HasDividendRate );
         break;
      case T_CUSIP:
         ReadString( type, rd, _Cusip, _HasCusip );
         break;
      case T_FINANCIAL_COMMENT:
         ReadString( type, rd, _FinancialComment, _HasFinancialComment );
         break;
      case T_DIVIDEND_1:
         ReadDate( type, rd, _Dividend1, _HasDividend1 );
         break;
      case T_IS_ACTIVE:
         ReadInt( type, rd, _IsActive, _HasIsActive );
         break;
      case T_UTC_OFFSET:
         ReadInt( type, rd, _UtcOffset, _HasUtcOffset );
         break;
      case T_SECURITY_TYPE:
         ReadString( type, rd, _SecurityType, _HasSecurityType );
         break;
      case T_SYMBOL_ERROR:
         ReadInt( type, rd, _SymbolError, _HasSymbolError );
         break;
      case T_STRIKE_PRC:
         ReadPrice( type, rd, _StrikePrc, _HasStrikePrc );
         break;
      case T_EXPIR_DATE:
         ReadDate( type, rd, _ExpirDate, _HasExpirDate );
         break;
      case T_MATUR_DATE:
         ReadDate( type, rd, _MaturDate, _HasMaturDate );
         break;
      case T_PUTCALLIND:
         ReadString( type, rd, _PutCallInd, _HasPutCallInd );
         break;
      case T_SETTLE_CASH:
         ReadPrice( type, rd, _SettleCash, _HasSettleCash );
         break;
      case T_SETTLE_SIZE_1:
         ReadInt( type, rd, _SettleSize1, _HasSettleSize1 );
         break;
      case T_TRADE_ROOT:
         ReadString( type, rd, _TradeRoot, _HasTradeRoot );
         break;
      case T_UNDERSYM:
         ReadString( type, rd, _UnderSym, _HasUnderSym );
         break;
      case T_OPTION_ROOT:
         ReadString( type, rd, _OptionRoot, _HasOptionRoot );
         break;
      case T_TICKSZTBL:
         ReadString( type, rd, _Ticksztbl, _HasTicksztbl );
         break;
      }
   }
}

void LivequoteRecord::Clear()
{
   _HasDispName=false;
   _HasSymbolId=false;
   _SymbolId=0;
   _HasStyp=false;
   _Styp=0;
   _HasTrdUnits=false;
   _HasExchName=false;
   _HasExchid=false;
   _HasExchzone=false;
   _HasStarttime=false;
   _Starttime.wMinutes=0;
   _Starttime.wSeconds=0;
   _HasStoptime=false;
   _Stoptime.wMinutes=0;
   _Stoptime.wSeconds=0;
   _HasExchdate=false;
   _Exchdate.iYear=1900;
   _Exchdate.cMonth=01;
   _Exchdate.cDay=01;
   _HasExchtim=false;
   _Exchtim.wMinutes=0;
   _Exchtim.wSeconds=0;
   _HasSession=false;
   _Session=0;
   _HasCurrentSession=false;
   _CurrentSession=0;
   _HasStartsess2=false;
   _Startsess2.wMinutes=0;
   _Startsess2.wSeconds=0;
   _HasTableId=false;
   _TableId=0;
   _HasTrdprc1=false;
   _Trdprc1.wBase=109;
   _Trdprc1.lVal=0;
   _HasTrdprc2=false;
   _Trdprc2.wBase=109;
   _Trdprc2.lVal=0;
   _HasTrdprc3=false;
   _Trdprc3.wBase=109;
   _Trdprc3.lVal=0;
   _HasTrdprc4=false;
   _Trdprc4.wBase=109;
   _Trdprc4.lVal=0;
   _HasTrdprc5=false;
   _Trdprc5.wBase=109;
   _Trdprc5.lVal=0;
   _HasNetchng1=false;
   _Netchng1.wBase=109;
   _Netchng1.lVal=0;
   _HasHigh1=false;
   _High1.wBase=109;
   _High1.lVal=0;
   _HasLow1=false;
   _Low1.wBase=109;
   _Low1.lVal=0;
   _HasCurrency=false;
   _HasTrdDate=false;
   _TrdDate.iYear=1900;
   _TrdDate.cMonth=01;
   _TrdDate.cDay=01;
   _HasTrdtim1=false;
   _Trdtim1.wMinutes=0;
   _Trdtim1.wSeconds=0;
   _HasOpenPrc=false;
   _OpenPrc.wBase=109;
   _OpenPrc.lVal=0;
   _HasHstClose=false;
   _HstClose.wBase=109;
   _HstClose.lVal=0;
   _HasBid=false;
   _Bid.wBase=109;
   _Bid.lVal=0;
   _HasAsk=false;
   _Ask.wBase=109;
   _Ask.lVal=0;
   _HasBidsize=false;
   _Bidsize=0;
   _HasAsksize=false;
   _Asksize=0;
   _HasAcvol1=false;
   _Acvol1=0;
   _HasEarnings=false;
   _Earnings.wBase=109;
   _Earnings.lVal=0;
   _HasPeratio=false;
   _Peratio.wBase=109;
   _Peratio.lVal=0;
   _HasDivpaydate=false;
   _Divpaydate.iYear=1900;
   _Divpaydate.cMonth=01;
   _Divpaydate.cDay=01;
   _HasExdivdate=false;
   _Exdivdate.iYear=1900;
   _Exdivdate.cMonth=01;
   _Exdivdate.cDay=01;
   _HasTrdxid1=false;
   _HasBidexid=false;
   _HasAskexid=false;
   _HasLotSize=false;
   _LotSize=0;
   _HasSettle=false;
   _Settle.wBase=109;
   _Settle.lVal=0;
   _HasDividend=false;
   _Dividend.wBase=109;
   _Dividend.lVal=0;
   _HasNumMoves=false;
   _NumMoves=0;
   _HasHstclsdate=false;
   _Hstclsdate.iYear=1900;
   _Hstclsdate.cMonth=01;
   _Hstclsdate.cDay=01;
   _HasHigh52=false;
   _High52.wBase=109;
   _High52.lVal=0;
   _HasLow52=false;
   _Low52.wBase=109;
   _Low52.lVal=0;
   _HasIssueDate=false;
   _IssueDate.iYear=1900;
   _IssueDate.cMonth=01;
   _IssueDate.cDay=01;
   _HasBidTick1=false;
   _HasDaysMat=false;
   _DaysMat=0;
   _HasYldMaturity=false;
   _YldMaturity=0;
   _HasTdyOfCls=false;
   _TdyOfCls.wBase=109;
   _TdyOfCls.lVal=0;
   _HasBuyerId=false;
   _BuyerId=0;
   _HasSellerId=false;
   _SellerId=0;
   _HasTrdvol1=false;
   _Trdvol1=0;
   _HasBasisvalue=false;
   _Basisvalue=0;
   _HasStatus1=false;
   _Status1=0;
   _HasLotSizeA=false;
   _LotSizeA=0;
   _HasSegText=false;
   _HasBidTime=false;
   _BidTime.wMinutes=0;
   _BidTime.wSeconds=0;
   _HasAskTime=false;
   _AskTime.wMinutes=0;
   _AskTime.wSeconds=0;
   _HasActTp1=false;
   _HasOpenTime=false;
   _OpenTime.wMinutes=0;
   _OpenTime.wSeconds=0;
   _HasHighTime=false;
   _HighTime.wMinutes=0;
   _HighTime.wSeconds=0;
   _HasSettledate=false;
   _Settledate.iYear=1900;
   _Settledate.cMonth=01;
   _Settledate.cDay=01;
   _HasLowTime=false;
   _LowTime.wMinutes=0;
   _LowTime.wSeconds=0;
   _HasHigh52Date=false;
   _High52Date.iYear=1900;
   _High52Date.cMonth=01;
   _High52Date.cDay=01;
   _HasLow52Date=false;
   _Low52Date.iYear=1900;
   _Low52Date.cMonth=01;
   _Low52Date.cDay=01;
   _HasIrgcond=false;
   _Irgcond=0;
   _HasParity99=false;
   _Parity99.wBase=109;
   _Parity99.lVal=0;
   _HasHstVol=false;
   _HstVol=0;
   _HasSeqnum=false;
   _Seqnum=0;
   _HasRestrict=false;
   _HasStatus=false;
   _HasMgState=false;
   _HasDelay=false;
   _Delay=0;
   _HasNominalCurrency=false;
   _HasIssuersDomicile=false;
   _HasIssuersSector=false;
   _IssuersSector=0;
   _HasIssuePrice=false;
   _IssuePrice.wBase=109;
   _IssuePrice.lVal=0;
   _HasWarrantConvNum=false;
   _WarrantConvNum.wBase=109;
   _WarrantConvNum.lVal=0;
   _HasWarrantConvDenom=false;
   _WarrantConvDenom.wBase=109;
   _WarrantConvDenom.lVal=0;
   _HasDividend1Date=false;
   _Dividend1Date.iYear=1900;
   _Dividend1Date.cMonth=01;
   _Dividend1Date.cDay=01;
   _HasNsin1=false;
   _HasNsin2=false;
   _HasNsin3=false;
   _HasNsin4=false;
   _HasNsin5=false;
   _HasNsin6=false;
   _HasTheoOpen=false;
   _TheoOpen.wBase=109;
   _TheoOpen.lVal=0;
   _HasImbalance=false;
   _Imbalance=0;
   _HasContracts=false;
   _Contracts=0;
   _HasCountervalue=false;
   _Countervalue.wBase=109;
   _Countervalue.lVal=0;
   _HasOpeningVol=false;
   _OpeningVol=0;
   _HasOpeningContracts=false;
   _OpeningContracts=0;
   _HasOpeningNumber=false;
   _OpeningNumber=0;
   _HasSuspTime=false;
   _SuspTime.wMinutes=0;
   _SuspTime.wSeconds=0;
   _HasMinimumSize=false;
   _MinimumSize=0;
   _HasTickSize=false;
   _TickSize.wBase=109;
   _TickSize.lVal=0;
   _HasSubmarket=false;
   _HasOptVol=false;
   _OptVol=0;
   _HasPutVol=false;
   _PutVol=0;
   _HasCallVol=false;
   _CallVol=0;
   _HasAuctionPrice=false;
   _AuctionPrice.wBase=109;
   _AuctionPrice.lVal=0;
   _HasAuctionSize=false;
   _AuctionSize=0;
   _HasAuctionTime=false;
   _AuctionTime.wMinutes=0;
   _AuctionTime.wSeconds=0;
   _HasNsinTrading=false;
   _HasAuctionEnd=false;
   _AuctionEnd.wMinutes=0;
   _AuctionEnd.wSeconds=0;
   _HasBidTick2=false;
   _HasNasCrossType=false;
   _HasNasImbalance=false;
   _NasImbalance=0;
   _HasNasPaired=false;
   _NasPaired=0;
   _HasNasReferencePrice=false;
   _NasReferencePrice.wBase=109;
   _NasReferencePrice.lVal=0;
   _HasNasFarIndClearing=false;
   _NasFarIndClearing.wBase=109;
   _NasFarIndClearing.lVal=0;
   _HasNasNearIndClearing=false;
   _NasNearIndClearing.wBase=109;
   _NasNearIndClearing.lVal=0;
   _HasNyseImbalType=false;
   _HasNyseImbalance=false;
   _NyseImbalance=0;
   _HasOfficialPrice=false;
   _OfficialPrice.wBase=109;
   _OfficialPrice.lVal=0;
   _HasArcaMatchPrice=false;
   _ArcaMatchPrice.wBase=109;
   _ArcaMatchPrice.lVal=0;
   _HasArcaImbalanceVolume=false;
   _ArcaImbalanceVolume=0;
   _HasArcaMatchVolume=false;
   _ArcaMatchVolume=0;
   _HasArcaImbalanceSig=false;
   _ArcaImbalanceSig=0;
   _HasArcaAot=false;
   _ArcaAot.wMinutes=0;
   _ArcaAot.wSeconds=0;
   _HasSymbolDesc=false;
   _HasCompanyName=false;
   _HasMinmove=false;
   _Minmove=0;
   _HasMaxmove=false;
   _Maxmove=0;
   _HasChangeLast=false;
   _ChangeLast.wBase=109;
   _ChangeLast.lVal=0;
   _HasCommodityName=false;
   _HasMoneyFlow=false;
   _MoneyFlow=0;
   _HasVwap=false;
   _Vwap=0;
   _HasSumPv=false;
   _SumPv=0;
   _HasVwapVol=false;
   _VwapVol=0;
   _HasSaleCondition=false;
   _SaleCondition=0;
   _HasSaleConditionPrice=false;
   _SaleConditionPrice.wBase=109;
   _SaleConditionPrice.lVal=0;
   _HasSaleConditionVolume=false;
   _SaleConditionVolume=0;
   _HasSaleConditionTime=false;
   _SaleConditionTime.wMinutes=0;
   _SaleConditionTime.wSeconds=0;
   _HasSaleConditionXid=false;
   _HasSaleConditionDate=false;
   _SaleConditionDate.iYear=1900;
   _SaleConditionDate.cMonth=01;
   _SaleConditionDate.cDay=01;
   _HasBidCondition=false;
   _HasAskCondition=false;
   _HasBidDate=false;
   _BidDate.iYear=1900;
   _BidDate.cMonth=01;
   _BidDate.cDay=01;
   _HasAskDate=false;
   _AskDate.iYear=1900;
   _AskDate.cMonth=01;
   _AskDate.cDay=01;
   _HasIndicativePrice=false;
   _IndicativePrice.wBase=109;
   _IndicativePrice.lVal=0;
   _HasSmallcap=false;
   _HasIsinNo=false;
   _HasSuspendedIndicator=false;
   _SuspendedIndicator=0;
   _HasSessCloseDate=false;
   _SessCloseDate.iYear=1900;
   _SessCloseDate.cMonth=01;
   _SessCloseDate.cDay=01;
   _HasSedol=false;
   _HasCat=false;
   _HasIntradayHighCount=false;
   _IntradayHighCount=0;
   _HasIntradayLowCount=false;
   _IntradayLowCount=0;
   _HasLrpBid=false;
   _LrpBid.wBase=109;
   _LrpBid.lVal=0;
   _HasLrpAsk=false;
   _LrpAsk.wBase=109;
   _LrpAsk.lVal=0;
   _HasLrpTime=false;
   _LrpTime.wMinutes=0;
   _LrpTime.wSeconds=0;
   _HasLatency1=false;
   _Latency1=0;
   _HasDividendYield=false;
   _DividendYield.wBase=109;
   _DividendYield.lVal=0;
   _HasDividendRate=false;
   _DividendRate.wBase=109;
   _DividendRate.lVal=0;
   _HasCusip=false;
   _HasFinancialComment=false;
   _HasDividend1=false;
   _Dividend1.iYear=1900;
   _Dividend1.cMonth=01;
   _Dividend1.cDay=01;
   _HasIsActive=false;
   _IsActive=0;
   _HasUtcOffset=false;
   _UtcOffset=0;
   _HasSecurityType=false;
   _HasSymbolError=false;
   _SymbolError=0;
   _HasStrikePrc=false;
   _StrikePrc.wBase=109;
   _StrikePrc.lVal=0;
   _HasExpirDate=false;
   _ExpirDate.iYear=1900;
   _ExpirDate.cMonth=01;
   _ExpirDate.cDay=01;
   _HasMaturDate=false;
   _MaturDate.iYear=1900;
   _MaturDate.cMonth=01;
   _MaturDate.cDay=01;
   _HasPutCallInd=false;
   _HasSettleCash=false;
   _SettleCash.wBase=109;
   _SettleCash.lVal=0;
   _HasSettleSize1=false;
   _SettleSize1=0;
   _HasTradeRoot=false;
   _HasUnderSym=false;
   _HasOptionRoot=false;
   _HasTicksztbl=false;
}


RegionalRecord::RegionalRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_TRD_UNITS:
         ReadString( type, rd, _TrdUnits, _HasTrdUnits );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_EXCH_NAME:
         ReadString( type, rd, _ExchName, _HasExchName );
         break;
      case T_REGIONAL_BID:
         ReadPrice( type, rd, _RegionalBid, _HasRegionalBid );
         break;
      case T_REGIONAL_BID_TIME:
         ReadTime( type, rd, _RegionalBidTime, _HasRegionalBidTime );
         break;
      case T_REGIONAL_BIDEXID:
         ReadString( type, rd, _RegionalBidexid, _HasRegionalBidexid );
         break;
      case T_REGIONAL_BIDSIZE:
         ReadInt( type, rd, _RegionalBidsize, _HasRegionalBidsize );
         break;
      case T_REGIONAL_ASK:
         ReadPrice( type, rd, _RegionalAsk, _HasRegionalAsk );
         break;
      case T_REGIONAL_ASK_TIME:
         ReadTime( type, rd, _RegionalAskTime, _HasRegionalAskTime );
         break;
      case T_REGIONAL_ASKEXID:
         ReadString( type, rd, _RegionalAskexid, _HasRegionalAskexid );
         break;
      case T_REGIONAL_ASKSIZE:
         ReadInt( type, rd, _RegionalAsksize, _HasRegionalAsksize );
         break;
      case T_REGIONAL_TRDPRC_1:
         ReadPrice( type, rd, _RegionalTrdprc1, _HasRegionalTrdprc1 );
         break;
      case T_REGIONAL_TRDTIM_1:
         ReadTime( type, rd, _RegionalTrdtim1, _HasRegionalTrdtim1 );
         break;
      case T_REGIONAL_TRDVOL_1:
         ReadInt( type, rd, _RegionalTrdvol1, _HasRegionalTrdvol1 );
         break;
      case T_REGIONAL_EXCHID:
         ReadString( type, rd, _RegionalExchid, _HasRegionalExchid );
         break;
      case T_REGIONAL_TRDXID_1:
         ReadString( type, rd, _RegionalTrdxid1, _HasRegionalTrdxid1 );
         break;
      case T_REGIONAL_TRD_DATE:
         ReadDate( type, rd, _RegionalTrdDate, _HasRegionalTrdDate );
         break;
      case T_REGIONAL_OPEN_PRC:
         ReadPrice( type, rd, _RegionalOpenPrc, _HasRegionalOpenPrc );
         break;
      case T_REGIONAL_HST_CLOSE:
         ReadPrice( type, rd, _RegionalHstClose, _HasRegionalHstClose );
         break;
      case T_REGIONAL_HIGH_1:
         ReadPrice( type, rd, _RegionalHigh1, _HasRegionalHigh1 );
         break;
      case T_REGIONAL_LOW_1:
         ReadPrice( type, rd, _RegionalLow1, _HasRegionalLow1 );
         break;
      case T_REGIONAL_ACVOL_1:
         ReadInt( type, rd, _RegionalAcvol1, _HasRegionalAcvol1 );
         break;
      case T_REGIONAL_STATUS:
         ReadString( type, rd, _RegionalStatus, _HasRegionalStatus );
         break;
      case T_REGIONAL_ASK_DATE:
         ReadDate( type, rd, _RegionalAskDate, _HasRegionalAskDate );
         break;
      case T_REGIONAL_BID_DATE:
         ReadDate( type, rd, _RegionalBidDate, _HasRegionalBidDate );
         break;
      case T_REGIONAL_NETCHNG_1:
         ReadPrice( type, rd, _RegionalNetchng1, _HasRegionalNetchng1 );
         break;
      case T_REGIONAL_SALE_CONDITION:
         ReadInt( type, rd, _RegionalSaleCondition, _HasRegionalSaleCondition );
         break;
      case T_REGIONAL_CHANGE_LAST:
         ReadPrice( type, rd, _RegionalChangeLast, _HasRegionalChangeLast );
         break;
      }
   }
}

void RegionalRecord::Clear()
{
   _HasDispName=false;
   _HasTrdUnits=false;
   _HasStyp=false;
   _Styp=0;
   _HasExchName=false;
   _HasRegionalBid=false;
   _RegionalBid.wBase=109;
   _RegionalBid.lVal=0;
   _HasRegionalBidTime=false;
   _RegionalBidTime.wMinutes=0;
   _RegionalBidTime.wSeconds=0;
   _HasRegionalBidexid=false;
   _HasRegionalBidsize=false;
   _RegionalBidsize=0;
   _HasRegionalAsk=false;
   _RegionalAsk.wBase=109;
   _RegionalAsk.lVal=0;
   _HasRegionalAskTime=false;
   _RegionalAskTime.wMinutes=0;
   _RegionalAskTime.wSeconds=0;
   _HasRegionalAskexid=false;
   _HasRegionalAsksize=false;
   _RegionalAsksize=0;
   _HasRegionalTrdprc1=false;
   _RegionalTrdprc1.wBase=109;
   _RegionalTrdprc1.lVal=0;
   _HasRegionalTrdtim1=false;
   _RegionalTrdtim1.wMinutes=0;
   _RegionalTrdtim1.wSeconds=0;
   _HasRegionalTrdvol1=false;
   _RegionalTrdvol1=0;
   _HasRegionalExchid=false;
   _HasRegionalTrdxid1=false;
   _HasRegionalTrdDate=false;
   _RegionalTrdDate.iYear=1900;
   _RegionalTrdDate.cMonth=01;
   _RegionalTrdDate.cDay=01;
   _HasRegionalOpenPrc=false;
   _RegionalOpenPrc.wBase=109;
   _RegionalOpenPrc.lVal=0;
   _HasRegionalHstClose=false;
   _RegionalHstClose.wBase=109;
   _RegionalHstClose.lVal=0;
   _HasRegionalHigh1=false;
   _RegionalHigh1.wBase=109;
   _RegionalHigh1.lVal=0;
   _HasRegionalLow1=false;
   _RegionalLow1.wBase=109;
   _RegionalLow1.lVal=0;
   _HasRegionalAcvol1=false;
   _RegionalAcvol1=0;
   _HasRegionalStatus=false;
   _HasRegionalAskDate=false;
   _RegionalAskDate.iYear=1900;
   _RegionalAskDate.cMonth=01;
   _RegionalAskDate.cDay=01;
   _HasRegionalBidDate=false;
   _RegionalBidDate.iYear=1900;
   _RegionalBidDate.cMonth=01;
   _RegionalBidDate.cDay=01;
   _HasRegionalNetchng1=false;
   _RegionalNetchng1.wBase=109;
   _RegionalNetchng1.lVal=0;
   _HasRegionalSaleCondition=false;
   _RegionalSaleCondition=0;
   _HasRegionalChangeLast=false;
   _RegionalChangeLast.wBase=109;
   _RegionalChangeLast.lVal=0;
}


PositionRecord::PositionRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_TBO_ACCOUNT_ID:
         ReadInt( type, rd, _TboAccountId, _HasTboAccountId );
         break;
      case T_BANK:
         ReadString( type, rd, _Bank, _HasBank );
         break;
      case T_BRANCH:
         ReadString( type, rd, _Branch, _HasBranch );
         break;
      case T_CUSTOMER:
         ReadString( type, rd, _Customer, _HasCustomer );
         break;
      case T_DEPOSIT:
         ReadString( type, rd, _Deposit, _HasDeposit );
         break;
      case T_CURRENCY:
         ReadString( type, rd, _Currency, _HasCurrency );
         break;
      case T_ACCT_TYPE:
         ReadInt( type, rd, _AcctType, _HasAcctType );
         break;
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_UNDERSYM:
         ReadString( type, rd, _Undersym, _HasUndersym );
         break;
      case T_RANK:
         ReadInt( type, rd, _Rank, _HasRank );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_AVERAGE_LONG:
         ReadDouble( type, rd, _AverageLong, _HasAverageLong );
         break;
      case T_LONGPOS:
         ReadDouble( type, rd, _Longpos, _HasLongpos );
         break;
      case T_AVERAGE_LONG0:
         ReadDouble( type, rd, _AverageLong0, _HasAverageLong0 );
         break;
      case T_HIST_LONG_PRC_0:
         ReadDouble( type, rd, _HistLongPrc0, _HasHistLongPrc0 );
         break;
      case T_LONGPOS0:
         ReadDouble( type, rd, _Longpos0, _HasLongpos0 );
         break;
      case T_ORIG_LONGPOS0:
         ReadDouble( type, rd, _OrigLongpos0, _HasOrigLongpos0 );
         break;
      case T_AVERAGE_SHORT:
         ReadDouble( type, rd, _AverageShort, _HasAverageShort );
         break;
      case T_SHORTPOS:
         ReadDouble( type, rd, _Shortpos, _HasShortpos );
         break;
      case T_AVERAGE_SHORT0:
         ReadDouble( type, rd, _AverageShort0, _HasAverageShort0 );
         break;
      case T_HIST_SHORT_PRC_0:
         ReadDouble( type, rd, _HistShortPrc0, _HasHistShortPrc0 );
         break;
      case T_SHORTPOS0:
         ReadDouble( type, rd, _Shortpos0, _HasShortpos0 );
         break;
      case T_ORIG_SHORTPOS0:
         ReadDouble( type, rd, _OrigShortpos0, _HasOrigShortpos0 );
         break;
      case T_SCALPED_PROFIT:
         ReadDouble( type, rd, _ScalpedProfit, _HasScalpedProfit );
         break;
      case T_MMR:
         ReadDouble( type, rd, _Mmr, _HasMmr );
         break;
      case T_TABLE:
         ReadString( type, rd, _Table, _HasTable );
         break;
      case T_BOUGHT_QTY:
         ReadDouble( type, rd, _BoughtQty, _HasBoughtQty );
         break;
      case T_SOLD_QTY:
         ReadDouble( type, rd, _SoldQty, _HasSoldQty );
         break;
      case T_SOLD_SHORT_QTY:
         ReadDouble( type, rd, _SoldShortQty, _HasSoldShortQty );
         break;
      case T_BOUGHT_AVG_PRC:
         ReadDouble( type, rd, _BoughtAvgPrc, _HasBoughtAvgPrc );
         break;
      case T_SOLD_AVG_PRC:
         ReadDouble( type, rd, _SoldAvgPrc, _HasSoldAvgPrc );
         break;
      case T_SOLD_SHORT_AVG_PRC:
         ReadDouble( type, rd, _SoldShortAvgPrc, _HasSoldShortAvgPrc );
         break;
      case T_COMMISSION:
         ReadDouble( type, rd, _Commission, _HasCommission );
         break;
      case T_NET_FEES:
         ReadDouble( type, rd, _NetFees, _HasNetFees );
         break;
      case T_HIST_SCALPED_PROFIT:
         ReadDouble( type, rd, _HistScalpedProfit, _HasHistScalpedProfit );
         break;
      }
   }
}

void PositionRecord::Clear()
{
   _HasTboAccountId=false;
   _TboAccountId=0;
   _HasBank=false;
   _HasBranch=false;
   _HasCustomer=false;
   _HasDeposit=false;
   _HasCurrency=false;
   _HasAcctType=false;
   _AcctType=0;
   _HasDispName=false;
   _HasUndersym=false;
   _HasRank=false;
   _Rank=0;
   _HasStyp=false;
   _Styp=0;
   _HasAverageLong=false;
   _AverageLong=0;
   _HasLongpos=false;
   _Longpos=0;
   _HasAverageLong0=false;
   _AverageLong0=0;
   _HasHistLongPrc0=false;
   _HistLongPrc0=0;
   _HasLongpos0=false;
   _Longpos0=0;
   _HasOrigLongpos0=false;
   _OrigLongpos0=0;
   _HasAverageShort=false;
   _AverageShort=0;
   _HasShortpos=false;
   _Shortpos=0;
   _HasAverageShort0=false;
   _AverageShort0=0;
   _HasHistShortPrc0=false;
   _HistShortPrc0=0;
   _HasShortpos0=false;
   _Shortpos0=0;
   _HasOrigShortpos0=false;
   _OrigShortpos0=0;
   _HasScalpedProfit=false;
   _ScalpedProfit=0;
   _HasMmr=false;
   _Mmr=0;
   _HasTable=false;
   _HasBoughtQty=false;
   _BoughtQty=0;
   _HasSoldQty=false;
   _SoldQty=0;
   _HasSoldShortQty=false;
   _SoldShortQty=0;
   _HasBoughtAvgPrc=false;
   _BoughtAvgPrc=0;
   _HasSoldAvgPrc=false;
   _SoldAvgPrc=0;
   _HasSoldShortAvgPrc=false;
   _SoldShortAvgPrc=0;
   _HasCommission=false;
   _Commission=0;
   _HasNetFees=false;
   _NetFees=0;
   _HasHistScalpedProfit=false;
   _HistScalpedProfit=0;
}


CorpActRecord::CorpActRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_CA_SPLIT_FACTOR:
         ReadDouble( type, rd, _CaSplitFactor, _HasCaSplitFactor );
         break;
      case T_CA_EFF_DATE:
         ReadDate( type, rd, _CaEffDate, _HasCaEffDate );
         break;
      case T_CA_TYPE:
         ReadInt( type, rd, _CaType, _HasCaType );
         break;
      case T_CA_IPO_SYMBOL:
         ReadString( type, rd, _CaIpoSymbol, _HasCaIpoSymbol );
         break;
      case T_CA_EXCH_NAME:
         ReadString( type, rd, _CaExchName, _HasCaExchName );
         break;
      }
   }
}

void CorpActRecord::Clear()
{
   _HasDispName=false;
   _HasCaSplitFactor=false;
   _CaSplitFactor=0;
   _HasCaEffDate=false;
   _CaEffDate.iYear=1900;
   _CaEffDate.cMonth=01;
   _CaEffDate.cDay=01;
   _HasCaType=false;
   _CaType=0;
   _HasCaIpoSymbol=false;
   _HasCaExchName=false;
}


IntradayRecord::IntradayRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_OPEN_PRC:
         ReadPriceVec( type, rd, _OpenPrc, _HasOpenPrc );
         break;
      case T_HIGH_1:
         ReadPriceVec( type, rd, _High1, _HasHigh1 );
         break;
      case T_LOW_1:
         ReadPriceVec( type, rd, _Low1, _HasLow1 );
         break;
      case T_SETTLE:
         ReadPriceVec( type, rd, _Settle, _HasSettle );
         break;
      case T_ACVOL_1:
         ReadIntVec( type, rd, _AcVol1, _HasAcVol1 );
         break;
      case T_TRDTIM_1:
         ReadTimeVec( type, rd, _TrdTim1, _HasTrdTim1 );
         break;
      case T_TRD_DATE:
         ReadDateVec( type, rd, _TrdDate, _HasTrdDate );
         break;
      }
   }
}

void IntradayRecord::Clear()
{
   _HasOpenPrc=false;
   _OpenPrc.clear();
   _HasHigh1=false;
   _High1.clear();
   _HasLow1=false;
   _Low1.clear();
   _HasSettle=false;
   _Settle.clear();
   _HasAcVol1=false;
   _AcVol1.clear();
   _HasTrdTim1=false;
   _TrdTim1.clear();
   _HasTrdDate=false;
   _TrdDate.clear();
}


QuoteChainRecord::QuoteChainRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_EXCH_NAME:
         ReadString( type, rd, _ExchName, _HasExchName );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_SYMBOL_DESC:
         ReadString( type, rd, _SymbolDesc, _HasSymbolDesc );
         break;
      case T_TRD_UNITS:
         ReadString( type, rd, _TrdUnits, _HasTrdUnits );
         break;
      case T_SESSION:
         ReadInt( type, rd, _Session, _HasSession );
         break;
      case T_MINMOVE:
         ReadInt( type, rd, _Minmove, _HasMinmove );
         break;
      case T_BASISVALUE:
         ReadDouble( type, rd, _Basisvalue, _HasBasisvalue );
         break;
      case T_COMMODITY_NAME:
         ReadString( type, rd, _CommodityName, _HasCommodityName );
         break;
      }
   }
}

void QuoteChainRecord::Clear()
{
   _HasDispName=false;
   _HasExchName=false;
   _HasStyp=false;
   _Styp=0;
   _HasSymbolDesc=false;
   _HasTrdUnits=false;
   _HasSession=false;
   _Session=0;
   _HasMinmove=false;
   _Minmove=0;
   _HasBasisvalue=false;
   _Basisvalue=0;
   _HasCommodityName=false;
}


XPermsAccountsRecord::XPermsAccountsRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_BANK:
         ReadString( type, rd, _Bank, _HasBank );
         break;
      case T_BRANCH:
         ReadString( type, rd, _Branch, _HasBranch );
         break;
      case T_CUSTOMER:
         ReadString( type, rd, _Customer, _HasCustomer );
         break;
      case T_DEPOSIT:
         ReadString( type, rd, _Deposit, _HasDeposit );
         break;
      case T_ACCT_TYPE:
         ReadInt( type, rd, _AcctType, _HasAcctType );
         break;
      case T_MARGIN_SOURCE:
         ReadInt( type, rd, _MarginSource, _HasMarginSource );
         break;
      case T_MARGIN_RULESET_ID:
         ReadInt( type, rd, _MarginRulesetId, _HasMarginRulesetId );
         break;
      case T_MARGIN_RULESET_NAME:
         ReadString( type, rd, _MarginRulesetName, _HasMarginRulesetName );
         break;
      case T_ACCT_DESC:
         ReadString( type, rd, _AcctDesc, _HasAcctDesc );
         break;
      }
   }
}

void XPermsAccountsRecord::Clear()
{
   _HasBank=false;
   _HasBranch=false;
   _HasCustomer=false;
   _HasDeposit=false;
   _HasAcctType=false;
   _AcctType=0;
   _HasMarginSource=false;
   _MarginSource=0;
   _HasMarginRulesetId=false;
   _MarginRulesetId=0;
   _HasMarginRulesetName=false;
   _HasAcctDesc=false;
}


MarketMakersRecord::MarketMakersRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_MKT_MKR_ID:
         ReadString( type, rd, _MktMkrId, _HasMktMkrId );
         break;
      case T_MKT_SOURCE:
         ReadString( type, rd, _MktSource, _HasMktSource );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_MKT_MKR_STATUS:
         ReadString( type, rd, _MktMkrStatus, _HasMktMkrStatus );
         break;
      case T_TABLE_ID:
         ReadInt( type, rd, _TableId, _HasTableId );
         break;
      case T_EXCH_NAME:
         ReadString( type, rd, _ExchName, _HasExchName );
         break;
      case T_SYMBOL_ID:
         ReadInt( type, rd, _SymbolId, _HasSymbolId );
         break;
      case T_QUOTE_UPDATE_TYPE:
         ReadInt( type, rd, _QuoteUpdateType, _HasQuoteUpdateType );
         break;
      case T_MKT_MKR_ASK:
         ReadPrice( type, rd, _MktMkrAsk, _HasMktMkrAsk );
         break;
      case T_MKT_MKR_ASKSIZE:
         ReadInt( type, rd, _MktMkrAsksize, _HasMktMkrAsksize );
         break;
      case T_MKT_MKR_ASK_TIME:
         ReadTime( type, rd, _MktMkrAskTime, _HasMktMkrAskTime );
         break;
      case T_MKT_MKR_DISPLAY:
         ReadString( type, rd, _MktMkrDisplay, _HasMktMkrDisplay );
         break;
      case T_MKT_MKR_CHANGE_LAST_ASK:
         ReadPrice( type, rd, _MktMkrChangeLastAsk, _HasMktMkrChangeLastAsk );
         break;
      case T_MKT_MKR_BID:
         ReadPrice( type, rd, _MktMkrBid, _HasMktMkrBid );
         break;
      case T_MKT_MKR_BIDSIZE:
         ReadInt( type, rd, _MktMkrBidsize, _HasMktMkrBidsize );
         break;
      case T_MKT_MKR_BID_TIME:
         ReadTime( type, rd, _MktMkrBidTime, _HasMktMkrBidTime );
         break;
      case T_SYMBOL_ERROR:
         ReadInt( type, rd, _SymbolError, _HasSymbolError );
         break;
      case T_MKT_MKR_DATE:
         ReadDate( type, rd, _MktMkrDate, _HasMktMkrDate );
         break;
      }
   }
}

void MarketMakersRecord::Clear()
{
   _HasDispName=false;
   _HasMktMkrId=false;
   _HasMktSource=false;
   _HasStyp=false;
   _Styp=0;
   _HasMktMkrStatus=false;
   _HasTableId=false;
   _TableId=0;
   _HasExchName=false;
   _HasSymbolId=false;
   _SymbolId=0;
   _HasQuoteUpdateType=false;
   _QuoteUpdateType=0;
   _HasMktMkrAsk=false;
   _MktMkrAsk.wBase=109;
   _MktMkrAsk.lVal=0;
   _HasMktMkrAsksize=false;
   _MktMkrAsksize=0;
   _HasMktMkrAskTime=false;
   _MktMkrAskTime.wMinutes=0;
   _MktMkrAskTime.wSeconds=0;
   _HasMktMkrDisplay=false;
   _HasMktMkrChangeLastAsk=false;
   _MktMkrChangeLastAsk.wBase=109;
   _MktMkrChangeLastAsk.lVal=0;
   _HasMktMkrBid=false;
   _MktMkrBid.wBase=109;
   _MktMkrBid.lVal=0;
   _HasMktMkrBidsize=false;
   _MktMkrBidsize=0;
   _HasMktMkrBidTime=false;
   _MktMkrBidTime.wMinutes=0;
   _MktMkrBidTime.wSeconds=0;
   _HasSymbolError=false;
   _SymbolError=0;
   _HasMktMkrDate=false;
   _MktMkrDate.iYear=1900;
   _MktMkrDate.cMonth=01;
   _MktMkrDate.cDay=01;
}


NewsRecord::NewsRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_NEWS_HEADLINE:
         ReadString( type, rd, _NewsHeadline, _HasNewsHeadline );
         break;
      case T_NEWS_DATE:
         ReadDate( type, rd, _NewsDate, _HasNewsDate );
         break;
      case T_NEWS_SOURCE:
         ReadString( type, rd, _NewsSource, _HasNewsSource );
         break;
      case T_NEWS_PAGE:
         ReadString( type, rd, _NewsPage, _HasNewsPage );
         break;
      case T_NEWS_TIME:
         ReadTime( type, rd, _NewsTime, _HasNewsTime );
         break;
      case T_NEWS_COUNT:
         ReadInt( type, rd, _NewsCount, _HasNewsCount );
         break;
      case T_NEWS_STORY:
         ReadString( type, rd, _NewsStory, _HasNewsStory );
         break;
      }
   }
}

void NewsRecord::Clear()
{
   _HasNewsHeadline=false;
   _HasNewsDate=false;
   _NewsDate.iYear=1900;
   _NewsDate.cMonth=01;
   _NewsDate.cDay=01;
   _HasNewsSource=false;
   _HasNewsPage=false;
   _HasNewsTime=false;
   _NewsTime.wMinutes=0;
   _NewsTime.wSeconds=0;
   _HasNewsCount=false;
   _NewsCount=0;
   _HasNewsStory=false;
}


DailyRecord::DailyRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_TRD_DATE:
         ReadDateVec( type, rd, _TrdDate, _HasTrdDate );
         break;
      case T_OPEN_PRC:
         ReadPriceVec( type, rd, _OpenPrc, _HasOpenPrc );
         break;
      case T_HIGH_1:
         ReadPriceVec( type, rd, _High1, _HasHigh1 );
         break;
      case T_LOW_1:
         ReadPriceVec( type, rd, _Low1, _HasLow1 );
         break;
      case T_SETTLE:
         ReadPriceVec( type, rd, _Settle, _HasSettle );
         break;
      }
   }
}

void DailyRecord::Clear()
{
   _HasDispName=false;
   _HasTrdDate=false;
   _TrdDate.clear();
   _HasOpenPrc=false;
   _OpenPrc.clear();
   _HasHigh1=false;
   _High1.clear();
   _HasLow1=false;
   _Low1.clear();
   _HasSettle=false;
   _Settle.clear();
}


TicksRecord::TicksRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_TRDPRC_1:
         ReadPriceVec( type, rd, _TrdPrc1, _HasTrdPrc1 );
         break;
      case T_TRD_DATE:
         ReadDateVec( type, rd, _TrdDate, _HasTrdDate );
         break;
      case T_TICK_TYPE:
         ReadIntVec( type, rd, _TickType, _HasTickType );
         break;
      case T_TRDXID_1:
         ReadStringVec( type, rd, _TrdXid1, _HasTrdXid1 );
         break;
      case T_TRDVOL_1:
         ReadIntVec( type, rd, _TrdVol1, _HasTrdVol1 );
         break;
      case T_TRDTIM_1:
         ReadTimeVec( type, rd, _TrdTim1, _HasTrdTim1 );
         break;
      case T_DISP_NAME:
         ReadStringVec( type, rd, _DispName, _HasDispName );
         break;
      }
   }
}

void TicksRecord::Clear()
{
   _HasTrdPrc1=false;
   _TrdPrc1.clear();
   _HasTrdDate=false;
   _TrdDate.clear();
   _HasTickType=false;
   _TickType.clear();
   _HasTrdXid1=false;
   _TrdXid1.clear();
   _HasTrdVol1=false;
   _TrdVol1.clear();
   _HasTrdTim1=false;
   _TrdTim1.clear();
   _HasDispName=false;
   _DispName.clear();
}


OrderRecord::OrderRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_ORDER_ID:
         ReadString( type, rd, _OrderId, _HasOrderId );
         break;
      case T_CLIENT_ORDER_ID:
         ReadString( type, rd, _ClientOrderId, _HasClientOrderId );
         break;
      case T_TICKET_ID:
         ReadString( type, rd, _TicketId, _HasTicketId );
         break;
      case T_NEWS_DATE:
         ReadDate( type, rd, _NewsDate, _HasNewsDate );
         break;
      case T_NEWS_TIME:
         ReadTime( type, rd, _NewsTime, _HasNewsTime );
         break;
      case T_TYPE:
         ReadString( type, rd, _Type, _HasType );
         break;
      case T_TRADER_ID:
         ReadString( type, rd, _TraderId, _HasTraderId );
         break;
      case T_ORIGINAL_TRADER_ID:
         ReadString( type, rd, _OriginalTraderId, _HasOriginalTraderId );
         break;
      case T_CURRENT_STATUS:
         ReadString( type, rd, _CurrentStatus, _HasCurrentStatus );
         break;
      case T_ORIGINAL_ORDER_ID:
         ReadString( type, rd, _OriginalOrderId, _HasOriginalOrderId );
         break;
      case T_TBO_ACCOUNT_ID:
         ReadInt( type, rd, _TboAccountId, _HasTboAccountId );
         break;
      case T_BOOK_ID:
         ReadInt( type, rd, _BookId, _HasBookId );
         break;
      case T_DATE_INDEX:
         ReadInt( type, rd, _DateIndex, _HasDateIndex );
         break;
      case T_GW_BOOK_SEQ_NO:
         ReadInt( type, rd, _GwBookSeqNo, _HasGwBookSeqNo );
         break;
      case T_RANK:
         ReadInt( type, rd, _Rank, _HasRank );
         break;
      case T_BANK:
         ReadString( type, rd, _Bank, _HasBank );
         break;
      case T_BRANCH:
         ReadString( type, rd, _Branch, _HasBranch );
         break;
      case T_CUSTOMER:
         ReadString( type, rd, _Customer, _HasCustomer );
         break;
      case T_DEPOSIT:
         ReadString( type, rd, _Deposit, _HasDeposit );
         break;
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_CURRENCY:
         ReadString( type, rd, _Currency, _HasCurrency );
         break;
      case T_ACCT_TYPE:
         ReadInt( type, rd, _AcctType, _HasAcctType );
         break;
      case T_REMOTE_ID:
         ReadString( type, rd, _RemoteId, _HasRemoteId );
         break;
      case T_NEW_REMOTE_ID:
         ReadString( type, rd, _NewRemoteId, _HasNewRemoteId );
         break;
      case T_REFERS_TO_ID:
         ReadString( type, rd, _RefersToId, _HasRefersToId );
         break;
      case T_CLAIMED_BY_CLERK:
         ReadString( type, rd, _ClaimedByClerk, _HasClaimedByClerk );
         break;
      case T_VOLUME:
         ReadInt( type, rd, _Volume, _HasVolume );
         break;
      case T_BUYORSELL:
         ReadString( type, rd, _Buyorsell, _HasBuyorsell );
         break;
      case T_GOOD_UNTIL:
         ReadString( type, rd, _GoodUntil, _HasGoodUntil );
         break;
      case T_VOLUME_TYPE:
         ReadString( type, rd, _VolumeType, _HasVolumeType );
         break;
      case T_PRICE_TYPE:
         ReadString( type, rd, _PriceType, _HasPriceType );
         break;
      case T_PRICE:
         ReadPrice( type, rd, _Price, _HasPrice );
         break;
      case T_EXIT_VEHICLE:
         ReadString( type, rd, _ExitVehicle, _HasExitVehicle );
         break;
      case T_TIME_STAMP:
         ReadString( type, rd, _TimeStamp, _HasTimeStamp );
         break;
      case T_STOP_PRICE:
         ReadPrice( type, rd, _StopPrice, _HasStopPrice );
         break;
      case T_EXCHANGE:
         ReadString( type, rd, _Exchange, _HasExchange );
         break;
      case T_TRD_TIME:
         ReadTime( type, rd, _TrdTime, _HasTrdTime );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_BASISVALUE:
         ReadDouble( type, rd, _Basisvalue, _HasBasisvalue );
         break;
      case T_ORDER_TAG:
         ReadString( type, rd, _OrderTag, _HasOrderTag );
         break;
      case T_ORIGINAL_VOLUME:
         ReadInt( type, rd, _OriginalVolume, _HasOriginalVolume );
         break;
      case T_STRIKE_PRC:
         ReadPrice( type, rd, _StrikePrc, _HasStrikePrc );
         break;
      case T_FIX_TRADER_ID:
         ReadString( type, rd, _FixTraderId, _HasFixTraderId );
         break;
      case T_TRADER_CAPACITY:
         ReadString( type, rd, _TraderCapacity, _HasTraderCapacity );
         break;
      case T_ORIGINAL_PRICE:
         ReadPrice( type, rd, _OriginalPrice, _HasOriginalPrice );
         break;
      case T_TABLE:
         ReadString( type, rd, _Table, _HasTable );
         break;
      case T_LATENCY_3:
         ReadDouble( type, rd, _Latency3, _HasLatency3 );
         break;
      case T_LATENCY_6:
         ReadDouble( type, rd, _Latency6, _HasLatency6 );
         break;
      case T_UTC_OFFSET:
         ReadInt( type, rd, _UtcOffset, _HasUtcOffset );
         break;
      case T_OMS_CLIENT_TYPE:
         ReadInt( type, rd, _OmsClientType, _HasOmsClientType );
         break;
      case T_REASON:
         ReadString( type, rd, _Reason, _HasReason );
         break;
      case T_GOOD_FROM:
         ReadString( type, rd, _GoodFrom, _HasGoodFrom );
         break;
      case T_VOLUME_TRADED:
         ReadInt( type, rd, _VolumeTraded, _HasVolumeTraded );
         break;
      case T_ORDER_RESIDUAL:
         ReadInt( type, rd, _VolumeRemaining, _HasVolumeRemaining );
         break;
      case T_AVG_PRICE:
         ReadDouble( type, rd, _AvgPrice, _HasAvgPrice );
         break;
      case T_OPPOSITE_PARTY:
         ReadString( type, rd, _OppositeParty, _HasOppositeParty );
         break;
      case T_USER_MESSAGE:
         ReadString( type, rd, _UserMessage, _HasUserMessage );
         break;
      case T_EXPIR_DATE:
         ReadDate( type, rd, _ExpirDate, _HasExpirDate );
         break;
      case T_PUTCALLIND:
         ReadString( type, rd, _Putcallind, _HasPutcallind );
         break;
      case T_UNDERSYM:
         ReadString( type, rd, _Undersym, _HasUndersym );
         break;
      case T_SHORT_LOCATE_ID:
         ReadString( type, rd, _ShortLocateId, _HasShortLocateId );
         break;
      case T_MINMOVE:
         ReadInt( type, rd, _Minmove, _HasMinmove );
         break;
      case T_BID:
         ReadPrice( type, rd, _Bid, _HasBid );
         break;
      case T_ASK:
         ReadPrice( type, rd, _Ask, _HasAsk );
         break;
      case T_COMMISSION:
         ReadDouble( type, rd, _Commission, _HasCommission );
         break;
      case T_COMMISSION_CODE:
         ReadString( type, rd, _CommissionCode, _HasCommissionCode );
         break;
      case T_COMMISSION_RATE:
         ReadDouble( type, rd, _CommissionRate, _HasCommissionRate );
         break;
      case T_COMMISSION_RATE_TYPE:
         ReadInt( type, rd, _CommissionRateType, _HasCommissionRateType );
         break;
      case T_LINKED_ORDER_ID:
         ReadString( type, rd, _LinkedOrderId, _HasLinkedOrderId );
         break;
      case T_LINKED_ORDER_RELATIONSHIP:
         ReadInt( type, rd, _LinkedOrderRelationship, _HasLinkedOrderRelationship );
         break;
      case T_LINKED_ORDER_CANCELLATION:
         ReadInt( type, rd, _LinkedOrderCancellation, _HasLinkedOrderCancellation );
         break;
      case T_SPREAD_LEG_COUNT:
         ReadInt( type, rd, _SpreadLegCount, _HasSpreadLegCount );
         break;
      case T_SPREAD_NUM_LEGS:
         ReadInt( type, rd, _SpreadNumLegs, _HasSpreadNumLegs );
         break;
      case T_SPREAD_LEG_NUMBER:
         ReadInt( type, rd, _SpreadLegNumber, _HasSpreadLegNumber );
         break;
      case T_SPREAD_LEG_PRICE_TYPE:
         ReadInt( type, rd, _SpreadLegPriceType, _HasSpreadLegPriceType );
         break;
      case T_SPREAD_LEG_LEAN_PRIORITY:
         ReadInt( type, rd, _SpreadLegLeanPriority, _HasSpreadLegLeanPriority );
         break;
      case T_PAIR_SPREAD:
         ReadDouble( type, rd, _PairSpread, _HasPairSpread );
         break;
      case T_PAIR_SPREAD_TYPE:
         ReadInt( type, rd, _PairSpreadType, _HasPairSpreadType );
         break;
      case T_PAIR_RATIO:
         ReadDouble( type, rd, _PairRatio, _HasPairRatio );
         break;
      case T_PAIR_CASH:
         ReadDouble( type, rd, _PairCash, _HasPairCash );
         break;
      case T_PAIR_IMBALANCE_LIMIT:
         ReadDouble( type, rd, _PairImbalanceLimit, _HasPairImbalanceLimit );
         break;
      case T_PAIR_IMBALANCE_LIMIT_TYPE:
         ReadInt( type, rd, _PairImbalanceLimitType, _HasPairImbalanceLimitType );
         break;
      case T_PAIR_LEG_1_BENCHMARK:
         ReadDouble( type, rd, _PairLeg1Benchmark, _HasPairLeg1Benchmark );
         break;
      case T_PAIR_LEG_2_BENCHMARK:
         ReadDouble( type, rd, _PairLeg2Benchmark, _HasPairLeg2Benchmark );
         break;
      case T_PAIR_TARGET:
         ReadDouble( type, rd, _PairTarget, _HasPairTarget );
         break;
      case T_PAIR_LEG_1_BENCHMARK_TYPE:
         ReadInt( type, rd, _PairLeg1BenchmarkType, _HasPairLeg1BenchmarkType );
         break;
      case T_PAIR_LEG_2_BENCHMARK_TYPE:
         ReadInt( type, rd, _PairLeg2BenchmarkType, _HasPairLeg2BenchmarkType );
         break;
      case T_SPREAD_CLIP:
         ReadDouble( type, rd, _SpreadClip, _HasSpreadClip );
         break;
      case T_SPREAD_CLIP_TYPE:
         ReadInt( type, rd, _SpreadClipType, _HasSpreadClipType );
         break;
      case T_ECN_FEE:
         ReadDouble( type, rd, _EcnFee, _HasEcnFee );
         break;
      case T_SHARES_ALLOCATED:
         ReadInt( type, rd, _SharesAllocated, _HasSharesAllocated );
         break;
      case T_ALLOCATED_VALUE:
         ReadDouble( type, rd, _AllocatedValue, _HasAllocatedValue );
         break;
      }
   }
}

void OrderRecord::Clear()
{
   _HasOrderId=false;
   _HasClientOrderId=false;
   _HasTicketId=false;
   _HasNewsDate=false;
   _NewsDate.iYear=1900;
   _NewsDate.cMonth=01;
   _NewsDate.cDay=01;
   _HasNewsTime=false;
   _NewsTime.wMinutes=0;
   _NewsTime.wSeconds=0;
   _HasType=false;
   _HasTraderId=false;
   _HasOriginalTraderId=false;
   _HasCurrentStatus=false;
   _HasOriginalOrderId=false;
   _HasTboAccountId=false;
   _TboAccountId=0;
   _HasBookId=false;
   _BookId=0;
   _HasDateIndex=false;
   _DateIndex=0;
   _HasGwBookSeqNo=false;
   _GwBookSeqNo=0;
   _HasRank=false;
   _Rank=0;
   _HasBank=false;
   _HasBranch=false;
   _HasCustomer=false;
   _HasDeposit=false;
   _HasDispName=false;
   _HasCurrency=false;
   _HasAcctType=false;
   _AcctType=0;
   _HasRemoteId=false;
   _HasNewRemoteId=false;
   _HasRefersToId=false;
   _HasClaimedByClerk=false;
   _HasVolume=false;
   _Volume=0;
   _HasBuyorsell=false;
   _HasGoodUntil=false;
   _HasVolumeType=false;
   _HasPriceType=false;
   _HasPrice=false;
   _Price.wBase=109;
   _Price.lVal=0;
   _HasExitVehicle=false;
   _HasTimeStamp=false;
   _HasStopPrice=false;
   _StopPrice.wBase=109;
   _StopPrice.lVal=0;
   _HasExchange=false;
   _HasTrdTime=false;
   _TrdTime.wMinutes=0;
   _TrdTime.wSeconds=0;
   _HasStyp=false;
   _Styp=0;
   _HasBasisvalue=false;
   _Basisvalue=0;
   _HasOrderTag=false;
   _HasOriginalVolume=false;
   _OriginalVolume=0;
   _HasStrikePrc=false;
   _StrikePrc.wBase=109;
   _StrikePrc.lVal=0;
   _HasFixTraderId=false;
   _HasTraderCapacity=false;
   _HasOriginalPrice=false;
   _OriginalPrice.wBase=109;
   _OriginalPrice.lVal=0;
   _HasTable=false;
   _HasLatency3=false;
   _Latency3=0;
   _HasLatency6=false;
   _Latency6=0;
   _HasUtcOffset=false;
   _UtcOffset=0;
   _HasOmsClientType=false;
   _OmsClientType=0;
   _HasReason=false;
   _HasGoodFrom=false;
   _HasVolumeTraded=false;
   _VolumeTraded=0;
   _HasVolumeRemaining=false;
   _VolumeRemaining=0;
   _HasAvgPrice=false;
   _AvgPrice=0;
   _HasOppositeParty=false;
   _HasUserMessage=false;
   _HasExpirDate=false;
   _ExpirDate.iYear=1900;
   _ExpirDate.cMonth=01;
   _ExpirDate.cDay=01;
   _HasPutcallind=false;
   _HasUndersym=false;
   _HasShortLocateId=false;
   _HasMinmove=false;
   _Minmove=0;
   _HasBid=false;
   _Bid.wBase=109;
   _Bid.lVal=0;
   _HasAsk=false;
   _Ask.wBase=109;
   _Ask.lVal=0;
   _HasCommission=false;
   _Commission=0;
   _HasCommissionCode=false;
   _HasCommissionRate=false;
   _CommissionRate=0;
   _HasCommissionRateType=false;
   _CommissionRateType=0;
   _HasLinkedOrderId=false;
   _HasLinkedOrderRelationship=false;
   _LinkedOrderRelationship=0;
   _HasLinkedOrderCancellation=false;
   _LinkedOrderCancellation=0;
   _HasSpreadLegCount=false;
   _SpreadLegCount=0;
   _HasSpreadNumLegs=false;
   _SpreadNumLegs=0;
   _HasSpreadLegNumber=false;
   _SpreadLegNumber=0;
   _HasSpreadLegPriceType=false;
   _SpreadLegPriceType=0;
   _HasSpreadLegLeanPriority=false;
   _SpreadLegLeanPriority=0;
   _HasPairSpread=false;
   _PairSpread=0;
   _HasPairSpreadType=false;
   _PairSpreadType=0;
   _HasPairRatio=false;
   _PairRatio=0;
   _HasPairCash=false;
   _PairCash=0;
   _HasPairImbalanceLimit=false;
   _PairImbalanceLimit=0;
   _HasPairImbalanceLimitType=false;
   _PairImbalanceLimitType=0;
   _HasPairLeg1Benchmark=false;
   _PairLeg1Benchmark=0;
   _HasPairLeg2Benchmark=false;
   _PairLeg2Benchmark=0;
   _HasPairTarget=false;
   _PairTarget=0;
   _HasPairLeg1BenchmarkType=false;
   _PairLeg1BenchmarkType=0;
   _HasPairLeg2BenchmarkType=false;
   _PairLeg2BenchmarkType=0;
   _HasSpreadClip=false;
   _SpreadClip=0;
   _HasSpreadClipType=false;
   _SpreadClipType=0;
   _HasEcnFee=false;
   _EcnFee=0;
   _HasSharesAllocated=false;
   _SharesAllocated=0;
   _HasAllocatedValue=false;
   _AllocatedValue=0;
}


OptionServerRecord::OptionServerRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_PUTCALLIND:
         ReadString( type, rd, _PutCallId, _HasPutCallId );
         break;
      case T_STRIKE_PRC:
         ReadPrice( type, rd, _StrikePrice, _HasStrikePrice );
         break;
      case T_TIME_TO_EXPIRATION:
         ReadDouble( type, rd, _TimeToExpire, _HasTimeToExpire );
         break;
      case T_RATE:
         ReadDouble( type, rd, _Rate, _HasRate );
         break;
      case T_DIV_DATE_1:
         ReadDate( type, rd, _DividendDate1, _HasDividendDate1 );
         break;
      case T_DIV_AMOUNT_1:
         ReadDouble( type, rd, _DividendAmout1, _HasDividendAmout1 );
         break;
      case T_DIV_DATE_2:
         ReadDate( type, rd, _DividendDate2, _HasDividendDate2 );
         break;
      case T_DIV_AMOUNT_2:
         ReadDouble( type, rd, _DividendAmout2, _HasDividendAmout2 );
         break;
      case T_DIV_DATE_3:
         ReadDate( type, rd, _DividendDate3, _HasDividendDate3 );
         break;
      case T_DIV_AMOUNT_3:
         ReadDouble( type, rd, _DividendAmout3, _HasDividendAmout3 );
         break;
      case T_DIV_DATE_4:
         ReadDate( type, rd, _DividendDate4, _HasDividendDate4 );
         break;
      case T_DIV_AMOUNT_4:
         ReadDouble( type, rd, _DividendAmout4, _HasDividendAmout4 );
         break;
      case T_DIV_DATE_5:
         ReadDate( type, rd, _DividendDate5, _HasDividendDate5 );
         break;
      case T_DIV_AMOUNT_5:
         ReadDouble( type, rd, _DividendAmout5, _HasDividendAmout5 );
         break;
      case T_DIV_DATE_6:
         ReadDate( type, rd, _DividendDate6, _HasDividendDate6 );
         break;
      case T_DIV_AMOUNT_6:
         ReadDouble( type, rd, _DividendAmout6, _HasDividendAmout6 );
         break;
      case T_ORIGINAL_PRICE:
         ReadPrice( type, rd, _OriginalPrice, _HasOriginalPrice );
         break;
      case T_UNDERLIER_PRICE:
         ReadPrice( type, rd, _UnderlierPrice, _HasUnderlierPrice );
         break;
      case T_OPT_CALC_MODEL:
         ReadInt( type, rd, _Model, _HasModel );
         break;
      case T_IMPLIED:
         ReadDouble( type, rd, _ImpliedVol, _HasImpliedVol );
         break;
      case T_THEO:
         ReadDouble( type, rd, _Premium, _HasPremium );
         break;
      case T_DELTA:
         ReadDouble( type, rd, _Delta, _HasDelta );
         break;
      case T_VEGA:
         ReadDouble( type, rd, _Vega, _HasVega );
         break;
      case T_GAMMA:
         ReadDouble( type, rd, _Gamma, _HasGamma );
         break;
      case T_THETA:
         ReadDouble( type, rd, _Theta, _HasTheta );
         break;
      case T_UNDERSYM:
         ReadString( type, rd, _UnderSym, _HasUnderSym );
         break;
      case T_OPTION_ROOT:
         ReadString( type, rd, _OptionRoot, _HasOptionRoot );
         break;
      }
   }
}

void OptionServerRecord::Clear()
{
   _HasDispName=false;
   _HasPutCallId=false;
   _HasStrikePrice=false;
   _StrikePrice.wBase=109;
   _StrikePrice.lVal=0;
   _HasTimeToExpire=false;
   _TimeToExpire=0;
   _HasRate=false;
   _Rate=0;
   _HasDividendDate1=false;
   _DividendDate1.iYear=1900;
   _DividendDate1.cMonth=01;
   _DividendDate1.cDay=01;
   _HasDividendAmout1=false;
   _DividendAmout1=0;
   _HasDividendDate2=false;
   _DividendDate2.iYear=1900;
   _DividendDate2.cMonth=01;
   _DividendDate2.cDay=01;
   _HasDividendAmout2=false;
   _DividendAmout2=0;
   _HasDividendDate3=false;
   _DividendDate3.iYear=1900;
   _DividendDate3.cMonth=01;
   _DividendDate3.cDay=01;
   _HasDividendAmout3=false;
   _DividendAmout3=0;
   _HasDividendDate4=false;
   _DividendDate4.iYear=1900;
   _DividendDate4.cMonth=01;
   _DividendDate4.cDay=01;
   _HasDividendAmout4=false;
   _DividendAmout4=0;
   _HasDividendDate5=false;
   _DividendDate5.iYear=1900;
   _DividendDate5.cMonth=01;
   _DividendDate5.cDay=01;
   _HasDividendAmout5=false;
   _DividendAmout5=0;
   _HasDividendDate6=false;
   _DividendDate6.iYear=1900;
   _DividendDate6.cMonth=01;
   _DividendDate6.cDay=01;
   _HasDividendAmout6=false;
   _DividendAmout6=0;
   _HasOriginalPrice=false;
   _OriginalPrice.wBase=109;
   _OriginalPrice.lVal=0;
   _HasUnderlierPrice=false;
   _UnderlierPrice.wBase=109;
   _UnderlierPrice.lVal=0;
   _HasModel=false;
   _Model=0;
   _HasImpliedVol=false;
   _ImpliedVol=0;
   _HasPremium=false;
   _Premium=0;
   _HasDelta=false;
   _Delta=0;
   _HasVega=false;
   _Vega=0;
   _HasGamma=false;
   _Gamma=0;
   _HasTheta=false;
   _Theta=0;
   _HasUnderSym=false;
   _HasOptionRoot=false;
}


DepositRecord::DepositRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_TBO_ACCOUNT_ID:
         ReadInt( type, rd, _TboAccountId, _HasTboAccountId );
         break;
      case T_BANK:
         ReadString( type, rd, _Bank, _HasBank );
         break;
      case T_BRANCH:
         ReadString( type, rd, _Branch, _HasBranch );
         break;
      case T_CUSTOMER:
         ReadString( type, rd, _Customer, _HasCustomer );
         break;
      case T_DEPOSIT:
         ReadString( type, rd, _Deposit, _HasDeposit );
         break;
      case T_CURRENCY:
         ReadString( type, rd, _Currency, _HasCurrency );
         break;
      case T_RANK:
         ReadInt( type, rd, _Rank, _HasRank );
         break;
      case T_MARKETVALUE_0:
         ReadDouble( type, rd, _Marketvalue0, _HasMarketvalue0 );
         break;
      case T_CASH_BALANCE:
         ReadDouble( type, rd, _CashBalance, _HasCashBalance );
         break;
      case T_EQUITY_BALANCE:
         ReadDouble( type, rd, _EquityBalance, _HasEquityBalance );
         break;
      case T_EXTRA_CBP:
         ReadDouble( type, rd, _ExtraCbp, _HasExtraCbp );
         break;
      case T_MIN_BALANCE:
         ReadDouble( type, rd, _MinBalance, _HasMinBalance );
         break;
      case T_MAX_ORDER_SIZE:
         ReadDouble( type, rd, _MaxOrderSize, _HasMaxOrderSize );
         break;
      case T_EXCESS_EQ_0:
         ReadDouble( type, rd, _ExcessEq0, _HasExcessEq0 );
         break;
      case T_EXCESS_EQ:
         ReadDouble( type, rd, _ExcessEq, _HasExcessEq );
         break;
      case T_MMR_0:
         ReadDouble( type, rd, _Mmr0, _HasMmr0 );
         break;
      case T_MMR:
         ReadDouble( type, rd, _Mmr, _HasMmr );
         break;
      case T_SCALPED_PROFIT:
         ReadDouble( type, rd, _ScalpedProfit, _HasScalpedProfit );
         break;
      case T_CASH_BALANCE_ADJ:
         ReadDouble( type, rd, _CashBalanceAdj, _HasCashBalanceAdj );
         break;
      case T_MMR_0_ADJ:
         ReadDouble( type, rd, _Mmr0Adj, _HasMmr0Adj );
         break;
      case T_SMA_0:
         ReadDouble( type, rd, _Sma0, _HasSma0 );
         break;
      case T_SMA_0_ADJ:
         ReadDouble( type, rd, _Sma0Adj, _HasSma0Adj );
         break;
      case T_HOUSE_EXCESS_0:
         ReadDouble( type, rd, _HouseExcess0, _HasHouseExcess0 );
         break;
      case T_ORQ_0:
         ReadDouble( type, rd, _Orq0, _HasOrq0 );
         break;
      case T_CALC_TIME:
         ReadString( type, rd, _CalcTime, _HasCalcTime );
         break;
      case T_DAYS_BACK:
         ReadInt( type, rd, _DaysBack, _HasDaysBack );
         break;
      case T_COST:
         ReadDouble( type, rd, _Cost, _HasCost );
         break;
      case T_MMR_0_NON_DAYTRADE_ADJ:
         ReadDouble( type, rd, _Mmr0NonDaytradeAdj, _HasMmr0NonDaytradeAdj );
         break;
      case T_SRV_PENDING_MARGIN:
         ReadDouble( type, rd, _SrvPendingMargin, _HasSrvPendingMargin );
         break;
      case T_COMMISSION:
         ReadDouble( type, rd, _Commission, _HasCommission );
         break;
      case T_NET_FEES:
         ReadDouble( type, rd, _NetFees, _HasNetFees );
         break;
      case T_HIST_SCALPED_PROFIT:
         ReadDouble( type, rd, _HistScalpedProfit, _HasHistScalpedProfit );
         break;
      case T_TABLE:
         ReadString( type, rd, _Table, _HasTable );
         break;
      case T_PENDING_MARGIN:
         ReadDouble( type, rd, _PendingMargin, _HasPendingMargin );
         break;
      case T_CBP_REMAINING:
         ReadDouble( type, rd, _CbpRemaining, _HasCbpRemaining );
         break;
      }
   }
}

void DepositRecord::Clear()
{
   _HasTboAccountId=false;
   _TboAccountId=0;
   _HasBank=false;
   _HasBranch=false;
   _HasCustomer=false;
   _HasDeposit=false;
   _HasCurrency=false;
   _HasRank=false;
   _Rank=0;
   _HasMarketvalue0=false;
   _Marketvalue0=0;
   _HasCashBalance=false;
   _CashBalance=0;
   _HasEquityBalance=false;
   _EquityBalance=0;
   _HasExtraCbp=false;
   _ExtraCbp=0;
   _HasMinBalance=false;
   _MinBalance=0;
   _HasMaxOrderSize=false;
   _MaxOrderSize=0;
   _HasExcessEq0=false;
   _ExcessEq0=0;
   _HasExcessEq=false;
   _ExcessEq=0;
   _HasMmr0=false;
   _Mmr0=0;
   _HasMmr=false;
   _Mmr=0;
   _HasScalpedProfit=false;
   _ScalpedProfit=0;
   _HasCashBalanceAdj=false;
   _CashBalanceAdj=0;
   _HasMmr0Adj=false;
   _Mmr0Adj=0;
   _HasSma0=false;
   _Sma0=0;
   _HasSma0Adj=false;
   _Sma0Adj=0;
   _HasHouseExcess0=false;
   _HouseExcess0=0;
   _HasOrq0=false;
   _Orq0=0;
   _HasCalcTime=false;
   _HasDaysBack=false;
   _DaysBack=0;
   _HasCost=false;
   _Cost=0;
   _HasMmr0NonDaytradeAdj=false;
   _Mmr0NonDaytradeAdj=0;
   _HasSrvPendingMargin=false;
   _SrvPendingMargin=0;
   _HasCommission=false;
   _Commission=0;
   _HasNetFees=false;
   _NetFees=0;
   _HasHistScalpedProfit=false;
   _HistScalpedProfit=0;
   _HasTable=false;
   _HasPendingMargin=false;
   _PendingMargin=0;
   _HasCbpRemaining=false;
   _CbpRemaining=0;
}


SymbolGuideRecord::SymbolGuideRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_EXCH_NAME:
         ReadString( type, rd, _ExchName, _HasExchName );
         break;
      case T_STYP:
         ReadInt( type, rd, _Styp, _HasStyp );
         break;
      case T_SYMBOL_DESC:
         ReadString( type, rd, _SymbolDesc, _HasSymbolDesc );
         break;
      case T_ISIN_NO:
         ReadString( type, rd, _IsinNo, _HasIsinNo );
         break;
      case T_COUNTRY:
         ReadString( type, rd, _Country, _HasCountry );
         break;
      case T_COMMODITY_NAME:
         ReadString( type, rd, _CommodityName, _HasCommodityName );
         break;
      case T_BLOOMBERG_CODE:
         ReadString( type, rd, _BloombergCode, _HasBloombergCode );
         break;
      case T_BLOOMBERG_CODE_FULL:
         ReadString( type, rd, _BloombergCodeFull, _HasBloombergCodeFull );
         break;
      case T_RIC_CODE:
         ReadString( type, rd, _RicCode, _HasRicCode );
         break;
      case T_SEDOL:
         ReadString( type, rd, _Sedol, _HasSedol );
         break;
      case T_GICS_SECTOR:
         ReadString( type, rd, _GicsSector, _HasGicsSector );
         break;
      case T_GICS_INDUSTRY:
         ReadString( type, rd, _GicsIndustry, _HasGicsIndustry );
         break;
      case T_GICS_SUBINDUSTRY:
         ReadString( type, rd, _GicsSubindustry, _HasGicsSubindustry );
         break;
      case T_CUSIP:
         ReadString( type, rd, _Cusip, _HasCusip );
         break;
      }
   }
}

void SymbolGuideRecord::Clear()
{
   _HasDispName=false;
   _HasExchName=false;
   _HasStyp=false;
   _Styp=0;
   _HasSymbolDesc=false;
   _HasIsinNo=false;
   _HasCountry=false;
   _HasCommodityName=false;
   _HasBloombergCode=false;
   _HasBloombergCodeFull=false;
   _HasRicCode=false;
   _HasSedol=false;
   _HasGicsSector=false;
   _HasGicsIndustry=false;
   _HasGicsSubindustry=false;
   _HasCusip=false;
}


SecurityRecord::SecurityRecord( realtick_api::RTDataReader& rd )
{
   Clear();
   for( int i=0; i<rd.NumFields(); i++, rd.NextField() )
   { 
      uint32_t id, type;
      if( !rd.ReadField( id, type ) )
         return;

      switch( id )
      {
      case T_DISP_NAME:
         ReadString( type, rd, _DispName, _HasDispName );
         break;
      case T_EARNINGS:
         ReadPrice( type, rd, _Earnings, _HasEarnings );
         break;
      case T_PERATIO:
         ReadPrice( type, rd, _Peratio, _HasPeratio );
         break;
      case T_DIVPAYDATE:
         ReadDate( type, rd, _Divpaydate, _HasDivpaydate );
         break;
      case T_EXDIVDATE:
         ReadDate( type, rd, _Exdivdate, _HasExdivdate );
         break;
      case T_DIVIDEND:
         ReadPrice( type, rd, _Dividend, _HasDividend );
         break;
      case T_HIGH_52:
         ReadPrice( type, rd, _High52, _HasHigh52 );
         break;
      case T_LOW_52:
         ReadPrice( type, rd, _Low52, _HasLow52 );
         break;
      case T_RIC_CODE:
         ReadString( type, rd, _RicCode, _HasRicCode );
         break;
      case T_BLOOMBERG_CODE:
         ReadString( type, rd, _BloombergCode, _HasBloombergCode );
         break;
      case T_HIGH52_DATE:
         ReadDate( type, rd, _High52Date, _HasHigh52Date );
         break;
      case T_LOW52_DATE:
         ReadDate( type, rd, _Low52Date, _HasLow52Date );
         break;
      case T_ISSUERS_SECTOR_STR:
         ReadString( type, rd, _IssuersSectorStr, _HasIssuersSectorStr );
         break;
      case T_MG_SICM:
         ReadPrice( type, rd, _MgSicm, _HasMgSicm );
         break;
      case T_MKT_CAP:
         ReadPrice( type, rd, _MktCap, _HasMktCap );
         break;
      case T_COMPANY_NAME:
         ReadString( type, rd, _CompanyName, _HasCompanyName );
         break;
      case T_PRIMARY_EXCHANGE:
         ReadString( type, rd, _PrimaryExchange, _HasPrimaryExchange );
         break;
      case T_DIVIDEND_FREQ_N:
         ReadInt( type, rd, _DividendFreqN, _HasDividendFreqN );
         break;
      case T_SECURITY_CATEGORY:
         ReadInt( type, rd, _SecurityCategory, _HasSecurityCategory );
         break;
      case T_ISIN_NO:
         ReadString( type, rd, _IsinNo, _HasIsinNo );
         break;
      case T_SEDOL:
         ReadString( type, rd, _Sedol, _HasSedol );
         break;
      case T_DIVIDEND_YIELD:
         ReadPrice( type, rd, _DividendYield, _HasDividendYield );
         break;
      case T_DIVIDEND_RATE:
         ReadPrice( type, rd, _DividendRate, _HasDividendRate );
         break;
      case T_CUSIP:
         ReadString( type, rd, _Cusip, _HasCusip );
         break;
      case T_BETA:
         ReadPrice( type, rd, _Beta, _HasBeta );
         break;
      case T_SPLIT_FACTOR_1:
         ReadDouble( type, rd, _SplitFactor1, _HasSplitFactor1 );
         break;
      case T_SPLIT_DATE_1:
         ReadDate( type, rd, _SplitDate1, _HasSplitDate1 );
         break;
      case T_SHARES_OUT:
         ReadInt( type, rd, _SharesOut, _HasSharesOut );
         break;
      case T_GICS_SECTOR:
         ReadString( type, rd, _GicsSector, _HasGicsSector );
         break;
      case T_GICS_INDUSTRY:
         ReadString( type, rd, _GicsIndustry, _HasGicsIndustry );
         break;
      case T_GICS_SUBINDUSTRY:
         ReadString( type, rd, _GicsSubindustry, _HasGicsSubindustry );
         break;
      case T_COUNTRY:
         ReadString( type, rd, _Country, _HasCountry );
         break;
      case T_PROC_DATE:
         ReadDate( type, rd, _ProcDate, _HasProcDate );
         break;
      case T_CLOSE50DAVG_1D:
         ReadDouble( type, rd, _Close50davg1d, _HasClose50davg1d );
         break;
      case T_CLOSE200DAVG_1D:
         ReadDouble( type, rd, _Close200davg1d, _HasClose200davg1d );
         break;
      case T_RSI14D_1D:
         ReadDouble( type, rd, _Rsi14d1d, _HasRsi14d1d );
         break;
      case T_VOLUME20DAVG_1D:
         ReadDouble( type, rd, _Volume20davg1d, _HasVolume20davg1d );
         break;
      case T_VOLUME50DAVG_1D:
         ReadDouble( type, rd, _Volume50davg1d, _HasVolume50davg1d );
         break;
      case T_VOLUME200DAVG_1D:
         ReadDouble( type, rd, _Volume200davg1d, _HasVolume200davg1d );
         break;
      case T_VOLUME5DAVG_1D:
         ReadDouble( type, rd, _Volume5davg1d, _HasVolume5davg1d );
         break;
      case T_VOLUME10DAVG_1D:
         ReadDouble( type, rd, _Volume10davg1d, _HasVolume10davg1d );
         break;
      case T_CLOSE5DAVG_1D:
         ReadDouble( type, rd, _Close5davg1d, _HasClose5davg1d );
         break;
      case T_CLOSE10DAVG_1D:
         ReadDouble( type, rd, _Close10davg1d, _HasClose10davg1d );
         break;
      case T_CLOSE20DAVG_1D:
         ReadDouble( type, rd, _Close20davg1d, _HasClose20davg1d );
         break;
      case T_RSI9D_1D:
         ReadDouble( type, rd, _Rsi9d1d, _HasRsi9d1d );
         break;
      case T_RSI25D_1D:
         ReadDouble( type, rd, _Rsi25d1d, _HasRsi25d1d );
         break;
      case T_BOLLINGER_UPPER21D_1D:
         ReadDouble( type, rd, _BollingerUpper21d1d, _HasBollingerUpper21d1d );
         break;
      case T_BOLLINGER_LOWER21D_1D:
         ReadDouble( type, rd, _BollingerLower21d1d, _HasBollingerLower21d1d );
         break;
      case T_ADX14D_1D:
         ReadDouble( type, rd, _Adx14d1d, _HasAdx14d1d );
         break;
      case T_PLUSDI14D_1D:
         ReadDouble( type, rd, _Plusdi14d1d, _HasPlusdi14d1d );
         break;
      case T_MINUSDI14D_1D:
         ReadDouble( type, rd, _Minusdi14d1d, _HasMinusdi14d1d );
         break;
      case T_HIGH15DMAX_1D:
         ReadDouble( type, rd, _High15dmax1d, _HasHigh15dmax1d );
         break;
      case T_LOW15DMIN_1D:
         ReadDouble( type, rd, _Low15dmin1d, _HasLow15dmin1d );
         break;
      case T_HLVOLATILITY10D_1D:
         ReadDouble( type, rd, _Hlvolatility10d1d, _HasHlvolatility10d1d );
         break;
      }
   }
}

void SecurityRecord::Clear()
{
   _HasDispName=false;
   _HasEarnings=false;
   _Earnings.wBase=109;
   _Earnings.lVal=0;
   _HasPeratio=false;
   _Peratio.wBase=109;
   _Peratio.lVal=0;
   _HasDivpaydate=false;
   _Divpaydate.iYear=1900;
   _Divpaydate.cMonth=01;
   _Divpaydate.cDay=01;
   _HasExdivdate=false;
   _Exdivdate.iYear=1900;
   _Exdivdate.cMonth=01;
   _Exdivdate.cDay=01;
   _HasDividend=false;
   _Dividend.wBase=109;
   _Dividend.lVal=0;
   _HasHigh52=false;
   _High52.wBase=109;
   _High52.lVal=0;
   _HasLow52=false;
   _Low52.wBase=109;
   _Low52.lVal=0;
   _HasRicCode=false;
   _HasBloombergCode=false;
   _HasHigh52Date=false;
   _High52Date.iYear=1900;
   _High52Date.cMonth=01;
   _High52Date.cDay=01;
   _HasLow52Date=false;
   _Low52Date.iYear=1900;
   _Low52Date.cMonth=01;
   _Low52Date.cDay=01;
   _HasIssuersSectorStr=false;
   _HasMgSicm=false;
   _MgSicm.wBase=109;
   _MgSicm.lVal=0;
   _HasMktCap=false;
   _MktCap.wBase=109;
   _MktCap.lVal=0;
   _HasCompanyName=false;
   _HasPrimaryExchange=false;
   _HasDividendFreqN=false;
   _DividendFreqN=0;
   _HasSecurityCategory=false;
   _SecurityCategory=0;
   _HasIsinNo=false;
   _HasSedol=false;
   _HasDividendYield=false;
   _DividendYield.wBase=109;
   _DividendYield.lVal=0;
   _HasDividendRate=false;
   _DividendRate.wBase=109;
   _DividendRate.lVal=0;
   _HasCusip=false;
   _HasBeta=false;
   _Beta.wBase=109;
   _Beta.lVal=0;
   _HasSplitFactor1=false;
   _SplitFactor1=0;
   _HasSplitDate1=false;
   _SplitDate1.iYear=1900;
   _SplitDate1.cMonth=01;
   _SplitDate1.cDay=01;
   _HasSharesOut=false;
   _SharesOut=0;
   _HasGicsSector=false;
   _HasGicsIndustry=false;
   _HasGicsSubindustry=false;
   _HasCountry=false;
   _HasProcDate=false;
   _ProcDate.iYear=1900;
   _ProcDate.cMonth=01;
   _ProcDate.cDay=01;
   _HasClose50davg1d=false;
   _Close50davg1d=0;
   _HasClose200davg1d=false;
   _Close200davg1d=0;
   _HasRsi14d1d=false;
   _Rsi14d1d=0;
   _HasVolume20davg1d=false;
   _Volume20davg1d=0;
   _HasVolume50davg1d=false;
   _Volume50davg1d=0;
   _HasVolume200davg1d=false;
   _Volume200davg1d=0;
   _HasVolume5davg1d=false;
   _Volume5davg1d=0;
   _HasVolume10davg1d=false;
   _Volume10davg1d=0;
   _HasClose5davg1d=false;
   _Close5davg1d=0;
   _HasClose10davg1d=false;
   _Close10davg1d=0;
   _HasClose20davg1d=false;
   _Close20davg1d=0;
   _HasRsi9d1d=false;
   _Rsi9d1d=0;
   _HasRsi25d1d=false;
   _Rsi25d1d=0;
   _HasBollingerUpper21d1d=false;
   _BollingerUpper21d1d=0;
   _HasBollingerLower21d1d=false;
   _BollingerLower21d1d=0;
   _HasAdx14d1d=false;
   _Adx14d1d=0;
   _HasPlusdi14d1d=false;
   _Plusdi14d1d=0;
   _HasMinusdi14d1d=false;
   _Minusdi14d1d=0;
   _HasHigh15dmax1d=false;
   _High15dmax1d=0;
   _HasLow15dmin1d=false;
   _Low15dmin1d=0;
   _HasHlvolatility10d1d=false;
   _Hlvolatility10d1d=0;
}

