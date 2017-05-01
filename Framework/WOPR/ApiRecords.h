// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#pragma once
#ifndef APIRECORDS_H
#define APIRECORDS_H

#include <fids.h>
#include <string>
#include <vector>
#include <RealTickApi.h>

class LivequoteRecord {

public:
   LivequoteRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_SYMBOL_ID
public:
   int SymbolId() const { return _SymbolId;}
   bool HasSymbolId() const { return _HasSymbolId;}
private:
   int _SymbolId;
   bool _HasSymbolId;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_TRD_UNITS
public:
   const std::string& TrdUnits() const { return _TrdUnits;}
   bool HasTrdUnits() const { return _HasTrdUnits;}
private:
   std::string _TrdUnits;
   bool _HasTrdUnits;

// T_EXCH_NAME
public:
   const std::string& ExchName() const { return _ExchName;}
   bool HasExchName() const { return _HasExchName;}
private:
   std::string _ExchName;
   bool _HasExchName;

// T_EXCHID
public:
   const std::string& Exchid() const { return _Exchid;}
   bool HasExchid() const { return _HasExchid;}
private:
   std::string _Exchid;
   bool _HasExchid;

// T_EXCHZONE
public:
   const std::string& Exchzone() const { return _Exchzone;}
   bool HasExchzone() const { return _HasExchzone;}
private:
   std::string _Exchzone;
   bool _HasExchzone;

// T_STARTTIME
public:
   const realtick_api::RTTIME& Starttime() const { return _Starttime;}
   bool HasStarttime() const { return _HasStarttime;}
private:
   realtick_api::RTTIME _Starttime;
   bool _HasStarttime;

// T_STOPTIME
public:
   const realtick_api::RTTIME& Stoptime() const { return _Stoptime;}
   bool HasStoptime() const { return _HasStoptime;}
private:
   realtick_api::RTTIME _Stoptime;
   bool _HasStoptime;

// T_EXCHDATE
public:
   const realtick_api::RTDATE& Exchdate() const { return _Exchdate;}
   bool HasExchdate() const { return _HasExchdate;}
private:
   realtick_api::RTDATE _Exchdate;
   bool _HasExchdate;

// T_EXCHTIM
public:
   const realtick_api::RTTIME& Exchtim() const { return _Exchtim;}
   bool HasExchtim() const { return _HasExchtim;}
private:
   realtick_api::RTTIME _Exchtim;
   bool _HasExchtim;

// T_SESSION
public:
   int Session() const { return _Session;}
   bool HasSession() const { return _HasSession;}
private:
   int _Session;
   bool _HasSession;

// T_CURRENT_SESSION
public:
   int CurrentSession() const { return _CurrentSession;}
   bool HasCurrentSession() const { return _HasCurrentSession;}
private:
   int _CurrentSession;
   bool _HasCurrentSession;

// T_STARTSESS2
public:
   const realtick_api::RTTIME& Startsess2() const { return _Startsess2;}
   bool HasStartsess2() const { return _HasStartsess2;}
private:
   realtick_api::RTTIME _Startsess2;
   bool _HasStartsess2;

// T_TABLE_ID
public:
   int TableId() const { return _TableId;}
   bool HasTableId() const { return _HasTableId;}
private:
   int _TableId;
   bool _HasTableId;

// T_TRDPRC_1
public:
   const realtick_api::RTPRICE& Trdprc1() const { return _Trdprc1;}
   bool HasTrdprc1() const { return _HasTrdprc1;}
private:
   realtick_api::RTPRICE _Trdprc1;
   bool _HasTrdprc1;

// T_TRDPRC_2
public:
   const realtick_api::RTPRICE& Trdprc2() const { return _Trdprc2;}
   bool HasTrdprc2() const { return _HasTrdprc2;}
private:
   realtick_api::RTPRICE _Trdprc2;
   bool _HasTrdprc2;

// T_TRDPRC_3
public:
   const realtick_api::RTPRICE& Trdprc3() const { return _Trdprc3;}
   bool HasTrdprc3() const { return _HasTrdprc3;}
private:
   realtick_api::RTPRICE _Trdprc3;
   bool _HasTrdprc3;

// T_TRDPRC_4
public:
   const realtick_api::RTPRICE& Trdprc4() const { return _Trdprc4;}
   bool HasTrdprc4() const { return _HasTrdprc4;}
private:
   realtick_api::RTPRICE _Trdprc4;
   bool _HasTrdprc4;

// T_TRDPRC_5
public:
   const realtick_api::RTPRICE& Trdprc5() const { return _Trdprc5;}
   bool HasTrdprc5() const { return _HasTrdprc5;}
private:
   realtick_api::RTPRICE _Trdprc5;
   bool _HasTrdprc5;

// T_NETCHNG_1
public:
   const realtick_api::RTPRICE& Netchng1() const { return _Netchng1;}
   bool HasNetchng1() const { return _HasNetchng1;}
private:
   realtick_api::RTPRICE _Netchng1;
   bool _HasNetchng1;

// T_HIGH_1
public:
   const realtick_api::RTPRICE& High1() const { return _High1;}
   bool HasHigh1() const { return _HasHigh1;}
private:
   realtick_api::RTPRICE _High1;
   bool _HasHigh1;

// T_LOW_1
public:
   const realtick_api::RTPRICE& Low1() const { return _Low1;}
   bool HasLow1() const { return _HasLow1;}
private:
   realtick_api::RTPRICE _Low1;
   bool _HasLow1;

// T_CURRENCY
public:
   const std::string& Currency() const { return _Currency;}
   bool HasCurrency() const { return _HasCurrency;}
private:
   std::string _Currency;
   bool _HasCurrency;

// T_TRD_DATE
public:
   const realtick_api::RTDATE& TrdDate() const { return _TrdDate;}
   bool HasTrdDate() const { return _HasTrdDate;}
private:
   realtick_api::RTDATE _TrdDate;
   bool _HasTrdDate;

// T_TRDTIM_1
public:
   const realtick_api::RTTIME& Trdtim1() const { return _Trdtim1;}
   bool HasTrdtim1() const { return _HasTrdtim1;}
private:
   realtick_api::RTTIME _Trdtim1;
   bool _HasTrdtim1;

// T_OPEN_PRC
public:
   const realtick_api::RTPRICE& OpenPrc() const { return _OpenPrc;}
   bool HasOpenPrc() const { return _HasOpenPrc;}
private:
   realtick_api::RTPRICE _OpenPrc;
   bool _HasOpenPrc;

// T_HST_CLOSE
public:
   const realtick_api::RTPRICE& HstClose() const { return _HstClose;}
   bool HasHstClose() const { return _HasHstClose;}
private:
   realtick_api::RTPRICE _HstClose;
   bool _HasHstClose;

// T_BID
public:
   const realtick_api::RTPRICE& Bid() const { return _Bid;}
   bool HasBid() const { return _HasBid;}
private:
   realtick_api::RTPRICE _Bid;
   bool _HasBid;

// T_ASK
public:
   const realtick_api::RTPRICE& Ask() const { return _Ask;}
   bool HasAsk() const { return _HasAsk;}
private:
   realtick_api::RTPRICE _Ask;
   bool _HasAsk;

// T_BIDSIZE
public:
   int Bidsize() const { return _Bidsize;}
   bool HasBidsize() const { return _HasBidsize;}
private:
   int _Bidsize;
   bool _HasBidsize;

// T_ASKSIZE
public:
   int Asksize() const { return _Asksize;}
   bool HasAsksize() const { return _HasAsksize;}
private:
   int _Asksize;
   bool _HasAsksize;

// T_ACVOL_1
public:
   int Acvol1() const { return _Acvol1;}
   bool HasAcvol1() const { return _HasAcvol1;}
private:
   int _Acvol1;
   bool _HasAcvol1;

// T_EARNINGS
public:
   const realtick_api::RTPRICE& Earnings() const { return _Earnings;}
   bool HasEarnings() const { return _HasEarnings;}
private:
   realtick_api::RTPRICE _Earnings;
   bool _HasEarnings;

// T_PERATIO
public:
   const realtick_api::RTPRICE& Peratio() const { return _Peratio;}
   bool HasPeratio() const { return _HasPeratio;}
private:
   realtick_api::RTPRICE _Peratio;
   bool _HasPeratio;

// T_DIVPAYDATE
public:
   const realtick_api::RTDATE& Divpaydate() const { return _Divpaydate;}
   bool HasDivpaydate() const { return _HasDivpaydate;}
private:
   realtick_api::RTDATE _Divpaydate;
   bool _HasDivpaydate;

// T_EXDIVDATE
public:
   const realtick_api::RTDATE& Exdivdate() const { return _Exdivdate;}
   bool HasExdivdate() const { return _HasExdivdate;}
private:
   realtick_api::RTDATE _Exdivdate;
   bool _HasExdivdate;

// T_TRDXID_1
public:
   const std::string& Trdxid1() const { return _Trdxid1;}
   bool HasTrdxid1() const { return _HasTrdxid1;}
private:
   std::string _Trdxid1;
   bool _HasTrdxid1;

// T_BIDEXID
public:
   const std::string& Bidexid() const { return _Bidexid;}
   bool HasBidexid() const { return _HasBidexid;}
private:
   std::string _Bidexid;
   bool _HasBidexid;

// T_ASKEXID
public:
   const std::string& Askexid() const { return _Askexid;}
   bool HasAskexid() const { return _HasAskexid;}
private:
   std::string _Askexid;
   bool _HasAskexid;

// T_LOT_SIZE
public:
   int LotSize() const { return _LotSize;}
   bool HasLotSize() const { return _HasLotSize;}
private:
   int _LotSize;
   bool _HasLotSize;

// T_SETTLE
public:
   const realtick_api::RTPRICE& Settle() const { return _Settle;}
   bool HasSettle() const { return _HasSettle;}
private:
   realtick_api::RTPRICE _Settle;
   bool _HasSettle;

// T_DIVIDEND
public:
   const realtick_api::RTPRICE& Dividend() const { return _Dividend;}
   bool HasDividend() const { return _HasDividend;}
private:
   realtick_api::RTPRICE _Dividend;
   bool _HasDividend;

// T_NUM_MOVES
public:
   int NumMoves() const { return _NumMoves;}
   bool HasNumMoves() const { return _HasNumMoves;}
private:
   int _NumMoves;
   bool _HasNumMoves;

// T_HSTCLSDATE
public:
   const realtick_api::RTDATE& Hstclsdate() const { return _Hstclsdate;}
   bool HasHstclsdate() const { return _HasHstclsdate;}
private:
   realtick_api::RTDATE _Hstclsdate;
   bool _HasHstclsdate;

// T_HIGH_52
public:
   const realtick_api::RTPRICE& High52() const { return _High52;}
   bool HasHigh52() const { return _HasHigh52;}
private:
   realtick_api::RTPRICE _High52;
   bool _HasHigh52;

// T_LOW_52
public:
   const realtick_api::RTPRICE& Low52() const { return _Low52;}
   bool HasLow52() const { return _HasLow52;}
private:
   realtick_api::RTPRICE _Low52;
   bool _HasLow52;

// T_ISSUE_DATE
public:
   const realtick_api::RTDATE& IssueDate() const { return _IssueDate;}
   bool HasIssueDate() const { return _HasIssueDate;}
private:
   realtick_api::RTDATE _IssueDate;
   bool _HasIssueDate;

// T_BID_TICK_1
public:
   const std::string& BidTick1() const { return _BidTick1;}
   bool HasBidTick1() const { return _HasBidTick1;}
private:
   std::string _BidTick1;
   bool _HasBidTick1;

// T_DAYS_MAT
public:
   int DaysMat() const { return _DaysMat;}
   bool HasDaysMat() const { return _HasDaysMat;}
private:
   int _DaysMat;
   bool _HasDaysMat;

// T_YLD_MATURITY
public:
   double YldMaturity() const { return _YldMaturity;}
   bool HasYldMaturity() const { return _HasYldMaturity;}
private:
   double _YldMaturity;
   bool _HasYldMaturity;

// T_TDY_OF_CLS
public:
   const realtick_api::RTPRICE& TdyOfCls() const { return _TdyOfCls;}
   bool HasTdyOfCls() const { return _HasTdyOfCls;}
private:
   realtick_api::RTPRICE _TdyOfCls;
   bool _HasTdyOfCls;

// T_BUYER_ID
public:
   int BuyerId() const { return _BuyerId;}
   bool HasBuyerId() const { return _HasBuyerId;}
private:
   int _BuyerId;
   bool _HasBuyerId;

// T_SELLER_ID
public:
   int SellerId() const { return _SellerId;}
   bool HasSellerId() const { return _HasSellerId;}
private:
   int _SellerId;
   bool _HasSellerId;

// T_TRDVOL_1
public:
   int Trdvol1() const { return _Trdvol1;}
   bool HasTrdvol1() const { return _HasTrdvol1;}
private:
   int _Trdvol1;
   bool _HasTrdvol1;

// T_BASISVALUE
public:
   double Basisvalue() const { return _Basisvalue;}
   bool HasBasisvalue() const { return _HasBasisvalue;}
private:
   double _Basisvalue;
   bool _HasBasisvalue;

// T_STATUS_1
public:
   int Status1() const { return _Status1;}
   bool HasStatus1() const { return _HasStatus1;}
private:
   int _Status1;
   bool _HasStatus1;

// T_LOT_SIZE_A
public:
   double LotSizeA() const { return _LotSizeA;}
   bool HasLotSizeA() const { return _HasLotSizeA;}
private:
   double _LotSizeA;
   bool _HasLotSizeA;

// T_SEG_TEXT
public:
   const std::string& SegText() const { return _SegText;}
   bool HasSegText() const { return _HasSegText;}
private:
   std::string _SegText;
   bool _HasSegText;

// T_BID_TIME
public:
   const realtick_api::RTTIME& BidTime() const { return _BidTime;}
   bool HasBidTime() const { return _HasBidTime;}
private:
   realtick_api::RTTIME _BidTime;
   bool _HasBidTime;

// T_ASK_TIME
public:
   const realtick_api::RTTIME& AskTime() const { return _AskTime;}
   bool HasAskTime() const { return _HasAskTime;}
private:
   realtick_api::RTTIME _AskTime;
   bool _HasAskTime;

// T_ACT_TP_1
public:
   const std::string& ActTp1() const { return _ActTp1;}
   bool HasActTp1() const { return _HasActTp1;}
private:
   std::string _ActTp1;
   bool _HasActTp1;

// T_OPEN_TIME
public:
   const realtick_api::RTTIME& OpenTime() const { return _OpenTime;}
   bool HasOpenTime() const { return _HasOpenTime;}
private:
   realtick_api::RTTIME _OpenTime;
   bool _HasOpenTime;

// T_HIGH_TIME
public:
   const realtick_api::RTTIME& HighTime() const { return _HighTime;}
   bool HasHighTime() const { return _HasHighTime;}
private:
   realtick_api::RTTIME _HighTime;
   bool _HasHighTime;

// T_SETTLEDATE
public:
   const realtick_api::RTDATE& Settledate() const { return _Settledate;}
   bool HasSettledate() const { return _HasSettledate;}
private:
   realtick_api::RTDATE _Settledate;
   bool _HasSettledate;

// T_LOW_TIME
public:
   const realtick_api::RTTIME& LowTime() const { return _LowTime;}
   bool HasLowTime() const { return _HasLowTime;}
private:
   realtick_api::RTTIME _LowTime;
   bool _HasLowTime;

// T_HIGH52_DATE
public:
   const realtick_api::RTDATE& High52Date() const { return _High52Date;}
   bool HasHigh52Date() const { return _HasHigh52Date;}
private:
   realtick_api::RTDATE _High52Date;
   bool _HasHigh52Date;

// T_LOW52_DATE
public:
   const realtick_api::RTDATE& Low52Date() const { return _Low52Date;}
   bool HasLow52Date() const { return _HasLow52Date;}
private:
   realtick_api::RTDATE _Low52Date;
   bool _HasLow52Date;

// T_IRGCOND
public:
   int Irgcond() const { return _Irgcond;}
   bool HasIrgcond() const { return _HasIrgcond;}
private:
   int _Irgcond;
   bool _HasIrgcond;

// T_PARITY99
public:
   const realtick_api::RTPRICE& Parity99() const { return _Parity99;}
   bool HasParity99() const { return _HasParity99;}
private:
   realtick_api::RTPRICE _Parity99;
   bool _HasParity99;

// T_HST_VOL
public:
   int HstVol() const { return _HstVol;}
   bool HasHstVol() const { return _HasHstVol;}
private:
   int _HstVol;
   bool _HasHstVol;

// T_SEQNUM
public:
   int Seqnum() const { return _Seqnum;}
   bool HasSeqnum() const { return _HasSeqnum;}
private:
   int _Seqnum;
   bool _HasSeqnum;

// T_RESTRICT
public:
   const std::string& Restrict() const { return _Restrict;}
   bool HasRestrict() const { return _HasRestrict;}
private:
   std::string _Restrict;
   bool _HasRestrict;

// T_STATUS
public:
   const std::string& Status() const { return _Status;}
   bool HasStatus() const { return _HasStatus;}
private:
   std::string _Status;
   bool _HasStatus;

// T_MG_STATE
public:
   const std::string& MgState() const { return _MgState;}
   bool HasMgState() const { return _HasMgState;}
private:
   std::string _MgState;
   bool _HasMgState;

// T_DELAY
public:
   int Delay() const { return _Delay;}
   bool HasDelay() const { return _HasDelay;}
private:
   int _Delay;
   bool _HasDelay;

// T_NOMINAL_CURRENCY
public:
   const std::string& NominalCurrency() const { return _NominalCurrency;}
   bool HasNominalCurrency() const { return _HasNominalCurrency;}
private:
   std::string _NominalCurrency;
   bool _HasNominalCurrency;

// T_ISSUERS_DOMICILE
public:
   const std::string& IssuersDomicile() const { return _IssuersDomicile;}
   bool HasIssuersDomicile() const { return _HasIssuersDomicile;}
private:
   std::string _IssuersDomicile;
   bool _HasIssuersDomicile;

// T_ISSUERS_SECTOR
public:
   int IssuersSector() const { return _IssuersSector;}
   bool HasIssuersSector() const { return _HasIssuersSector;}
private:
   int _IssuersSector;
   bool _HasIssuersSector;

// T_ISSUE_PRICE
public:
   const realtick_api::RTPRICE& IssuePrice() const { return _IssuePrice;}
   bool HasIssuePrice() const { return _HasIssuePrice;}
private:
   realtick_api::RTPRICE _IssuePrice;
   bool _HasIssuePrice;

// T_WARRANT_CONV_NUM
public:
   const realtick_api::RTPRICE& WarrantConvNum() const { return _WarrantConvNum;}
   bool HasWarrantConvNum() const { return _HasWarrantConvNum;}
private:
   realtick_api::RTPRICE _WarrantConvNum;
   bool _HasWarrantConvNum;

// T_WARRANT_CONV_DENOM
public:
   const realtick_api::RTPRICE& WarrantConvDenom() const { return _WarrantConvDenom;}
   bool HasWarrantConvDenom() const { return _HasWarrantConvDenom;}
private:
   realtick_api::RTPRICE _WarrantConvDenom;
   bool _HasWarrantConvDenom;

// T_DIVIDEND_1_DATE
public:
   const realtick_api::RTDATE& Dividend1Date() const { return _Dividend1Date;}
   bool HasDividend1Date() const { return _HasDividend1Date;}
private:
   realtick_api::RTDATE _Dividend1Date;
   bool _HasDividend1Date;

// T_NSIN_1
public:
   const std::string& Nsin1() const { return _Nsin1;}
   bool HasNsin1() const { return _HasNsin1;}
private:
   std::string _Nsin1;
   bool _HasNsin1;

// T_NSIN_2
public:
   const std::string& Nsin2() const { return _Nsin2;}
   bool HasNsin2() const { return _HasNsin2;}
private:
   std::string _Nsin2;
   bool _HasNsin2;

// T_NSIN_3
public:
   const std::string& Nsin3() const { return _Nsin3;}
   bool HasNsin3() const { return _HasNsin3;}
private:
   std::string _Nsin3;
   bool _HasNsin3;

// T_NSIN_4
public:
   const std::string& Nsin4() const { return _Nsin4;}
   bool HasNsin4() const { return _HasNsin4;}
private:
   std::string _Nsin4;
   bool _HasNsin4;

// T_NSIN_5
public:
   const std::string& Nsin5() const { return _Nsin5;}
   bool HasNsin5() const { return _HasNsin5;}
private:
   std::string _Nsin5;
   bool _HasNsin5;

// T_NSIN_6
public:
   const std::string& Nsin6() const { return _Nsin6;}
   bool HasNsin6() const { return _HasNsin6;}
private:
   std::string _Nsin6;
   bool _HasNsin6;

// T_THEO_OPEN
public:
   const realtick_api::RTPRICE& TheoOpen() const { return _TheoOpen;}
   bool HasTheoOpen() const { return _HasTheoOpen;}
private:
   realtick_api::RTPRICE _TheoOpen;
   bool _HasTheoOpen;

// T_IMBALANCE
public:
   int Imbalance() const { return _Imbalance;}
   bool HasImbalance() const { return _HasImbalance;}
private:
   int _Imbalance;
   bool _HasImbalance;

// T_CONTRACTS
public:
   int Contracts() const { return _Contracts;}
   bool HasContracts() const { return _HasContracts;}
private:
   int _Contracts;
   bool _HasContracts;

// T_COUNTERVALUE
public:
   const realtick_api::RTPRICE& Countervalue() const { return _Countervalue;}
   bool HasCountervalue() const { return _HasCountervalue;}
private:
   realtick_api::RTPRICE _Countervalue;
   bool _HasCountervalue;

// T_OPENING_VOL
public:
   int OpeningVol() const { return _OpeningVol;}
   bool HasOpeningVol() const { return _HasOpeningVol;}
private:
   int _OpeningVol;
   bool _HasOpeningVol;

// T_OPENING_CONTRACTS
public:
   int OpeningContracts() const { return _OpeningContracts;}
   bool HasOpeningContracts() const { return _HasOpeningContracts;}
private:
   int _OpeningContracts;
   bool _HasOpeningContracts;

// T_OPENING_NUMBER
public:
   int OpeningNumber() const { return _OpeningNumber;}
   bool HasOpeningNumber() const { return _HasOpeningNumber;}
private:
   int _OpeningNumber;
   bool _HasOpeningNumber;

// T_SUSP_TIME
public:
   const realtick_api::RTTIME& SuspTime() const { return _SuspTime;}
   bool HasSuspTime() const { return _HasSuspTime;}
private:
   realtick_api::RTTIME _SuspTime;
   bool _HasSuspTime;

// T_MINIMUM_SIZE
public:
   int MinimumSize() const { return _MinimumSize;}
   bool HasMinimumSize() const { return _HasMinimumSize;}
private:
   int _MinimumSize;
   bool _HasMinimumSize;

// T_TICK_SIZE
public:
   const realtick_api::RTPRICE& TickSize() const { return _TickSize;}
   bool HasTickSize() const { return _HasTickSize;}
private:
   realtick_api::RTPRICE _TickSize;
   bool _HasTickSize;

// T_SUBMARKET
public:
   const std::string& Submarket() const { return _Submarket;}
   bool HasSubmarket() const { return _HasSubmarket;}
private:
   std::string _Submarket;
   bool _HasSubmarket;

// T_OPT_VOL
public:
   int OptVol() const { return _OptVol;}
   bool HasOptVol() const { return _HasOptVol;}
private:
   int _OptVol;
   bool _HasOptVol;

// T_PUT_VOL
public:
   int PutVol() const { return _PutVol;}
   bool HasPutVol() const { return _HasPutVol;}
private:
   int _PutVol;
   bool _HasPutVol;

// T_CALL_VOL
public:
   int CallVol() const { return _CallVol;}
   bool HasCallVol() const { return _HasCallVol;}
private:
   int _CallVol;
   bool _HasCallVol;

// T_AUCTION_PRICE
public:
   const realtick_api::RTPRICE& AuctionPrice() const { return _AuctionPrice;}
   bool HasAuctionPrice() const { return _HasAuctionPrice;}
private:
   realtick_api::RTPRICE _AuctionPrice;
   bool _HasAuctionPrice;

// T_AUCTION_SIZE
public:
   int AuctionSize() const { return _AuctionSize;}
   bool HasAuctionSize() const { return _HasAuctionSize;}
private:
   int _AuctionSize;
   bool _HasAuctionSize;

// T_AUCTION_TIME
public:
   const realtick_api::RTTIME& AuctionTime() const { return _AuctionTime;}
   bool HasAuctionTime() const { return _HasAuctionTime;}
private:
   realtick_api::RTTIME _AuctionTime;
   bool _HasAuctionTime;

// T_NSIN_TRADING
public:
   const std::string& NsinTrading() const { return _NsinTrading;}
   bool HasNsinTrading() const { return _HasNsinTrading;}
private:
   std::string _NsinTrading;
   bool _HasNsinTrading;

// T_AUCTION_END
public:
   const realtick_api::RTTIME& AuctionEnd() const { return _AuctionEnd;}
   bool HasAuctionEnd() const { return _HasAuctionEnd;}
private:
   realtick_api::RTTIME _AuctionEnd;
   bool _HasAuctionEnd;

// T_BID_TICK_2
public:
   const std::string& BidTick2() const { return _BidTick2;}
   bool HasBidTick2() const { return _HasBidTick2;}
private:
   std::string _BidTick2;
   bool _HasBidTick2;

// T_NAS_CROSS_TYPE
public:
   const std::string& NasCrossType() const { return _NasCrossType;}
   bool HasNasCrossType() const { return _HasNasCrossType;}
private:
   std::string _NasCrossType;
   bool _HasNasCrossType;

// T_NAS_IMBALANCE
public:
   int NasImbalance() const { return _NasImbalance;}
   bool HasNasImbalance() const { return _HasNasImbalance;}
private:
   int _NasImbalance;
   bool _HasNasImbalance;

// T_NAS_PAIRED
public:
   int NasPaired() const { return _NasPaired;}
   bool HasNasPaired() const { return _HasNasPaired;}
private:
   int _NasPaired;
   bool _HasNasPaired;

// T_NAS_REFERENCE_PRICE
public:
   const realtick_api::RTPRICE& NasReferencePrice() const { return _NasReferencePrice;}
   bool HasNasReferencePrice() const { return _HasNasReferencePrice;}
private:
   realtick_api::RTPRICE _NasReferencePrice;
   bool _HasNasReferencePrice;

// T_NAS_FAR_IND_CLEARING
public:
   const realtick_api::RTPRICE& NasFarIndClearing() const { return _NasFarIndClearing;}
   bool HasNasFarIndClearing() const { return _HasNasFarIndClearing;}
private:
   realtick_api::RTPRICE _NasFarIndClearing;
   bool _HasNasFarIndClearing;

// T_NAS_NEAR_IND_CLEARING
public:
   const realtick_api::RTPRICE& NasNearIndClearing() const { return _NasNearIndClearing;}
   bool HasNasNearIndClearing() const { return _HasNasNearIndClearing;}
private:
   realtick_api::RTPRICE _NasNearIndClearing;
   bool _HasNasNearIndClearing;

// T_NYSE_IMBAL_TYPE
public:
   const std::string& NyseImbalType() const { return _NyseImbalType;}
   bool HasNyseImbalType() const { return _HasNyseImbalType;}
private:
   std::string _NyseImbalType;
   bool _HasNyseImbalType;

// T_NYSE_IMBALANCE
public:
   int NyseImbalance() const { return _NyseImbalance;}
   bool HasNyseImbalance() const { return _HasNyseImbalance;}
private:
   int _NyseImbalance;
   bool _HasNyseImbalance;

// T_OFFICIAL_PRICE
public:
   const realtick_api::RTPRICE& OfficialPrice() const { return _OfficialPrice;}
   bool HasOfficialPrice() const { return _HasOfficialPrice;}
private:
   realtick_api::RTPRICE _OfficialPrice;
   bool _HasOfficialPrice;

// T_ARCA_MATCH_PRICE
public:
   const realtick_api::RTPRICE& ArcaMatchPrice() const { return _ArcaMatchPrice;}
   bool HasArcaMatchPrice() const { return _HasArcaMatchPrice;}
private:
   realtick_api::RTPRICE _ArcaMatchPrice;
   bool _HasArcaMatchPrice;

// T_ARCA_IMBALANCE_VOLUME
public:
   int ArcaImbalanceVolume() const { return _ArcaImbalanceVolume;}
   bool HasArcaImbalanceVolume() const { return _HasArcaImbalanceVolume;}
private:
   int _ArcaImbalanceVolume;
   bool _HasArcaImbalanceVolume;

// T_ARCA_MATCH_VOLUME
public:
   int ArcaMatchVolume() const { return _ArcaMatchVolume;}
   bool HasArcaMatchVolume() const { return _HasArcaMatchVolume;}
private:
   int _ArcaMatchVolume;
   bool _HasArcaMatchVolume;

// T_ARCA_IMBALANCE_SIG
public:
   int ArcaImbalanceSig() const { return _ArcaImbalanceSig;}
   bool HasArcaImbalanceSig() const { return _HasArcaImbalanceSig;}
private:
   int _ArcaImbalanceSig;
   bool _HasArcaImbalanceSig;

// T_ARCA_AOT
public:
   const realtick_api::RTTIME& ArcaAot() const { return _ArcaAot;}
   bool HasArcaAot() const { return _HasArcaAot;}
private:
   realtick_api::RTTIME _ArcaAot;
   bool _HasArcaAot;

// T_SYMBOL_DESC
public:
   const std::string& SymbolDesc() const { return _SymbolDesc;}
   bool HasSymbolDesc() const { return _HasSymbolDesc;}
private:
   std::string _SymbolDesc;
   bool _HasSymbolDesc;

// T_COMPANY_NAME
public:
   const std::string& CompanyName() const { return _CompanyName;}
   bool HasCompanyName() const { return _HasCompanyName;}
private:
   std::string _CompanyName;
   bool _HasCompanyName;

// T_MINMOVE
public:
   int Minmove() const { return _Minmove;}
   bool HasMinmove() const { return _HasMinmove;}
private:
   int _Minmove;
   bool _HasMinmove;

// T_MAXMOVE
public:
   int Maxmove() const { return _Maxmove;}
   bool HasMaxmove() const { return _HasMaxmove;}
private:
   int _Maxmove;
   bool _HasMaxmove;

// T_CHANGE_LAST
public:
   const realtick_api::RTPRICE& ChangeLast() const { return _ChangeLast;}
   bool HasChangeLast() const { return _HasChangeLast;}
private:
   realtick_api::RTPRICE _ChangeLast;
   bool _HasChangeLast;

// T_COMMODITY_NAME
public:
   const std::string& CommodityName() const { return _CommodityName;}
   bool HasCommodityName() const { return _HasCommodityName;}
private:
   std::string _CommodityName;
   bool _HasCommodityName;

// T_MONEY_FLOW
public:
   int MoneyFlow() const { return _MoneyFlow;}
   bool HasMoneyFlow() const { return _HasMoneyFlow;}
private:
   int _MoneyFlow;
   bool _HasMoneyFlow;

// T_VWAP
public:
   double Vwap() const { return _Vwap;}
   bool HasVwap() const { return _HasVwap;}
private:
   double _Vwap;
   bool _HasVwap;

// T_SUM_PV
public:
   double SumPv() const { return _SumPv;}
   bool HasSumPv() const { return _HasSumPv;}
private:
   double _SumPv;
   bool _HasSumPv;

// T_VWAP_VOL
public:
   int VwapVol() const { return _VwapVol;}
   bool HasVwapVol() const { return _HasVwapVol;}
private:
   int _VwapVol;
   bool _HasVwapVol;

// T_SALE_CONDITION
public:
   int SaleCondition() const { return _SaleCondition;}
   bool HasSaleCondition() const { return _HasSaleCondition;}
private:
   int _SaleCondition;
   bool _HasSaleCondition;

// T_SALE_CONDITION_PRICE
public:
   const realtick_api::RTPRICE& SaleConditionPrice() const { return _SaleConditionPrice;}
   bool HasSaleConditionPrice() const { return _HasSaleConditionPrice;}
private:
   realtick_api::RTPRICE _SaleConditionPrice;
   bool _HasSaleConditionPrice;

// T_SALE_CONDITION_VOLUME
public:
   int SaleConditionVolume() const { return _SaleConditionVolume;}
   bool HasSaleConditionVolume() const { return _HasSaleConditionVolume;}
private:
   int _SaleConditionVolume;
   bool _HasSaleConditionVolume;

// T_SALE_CONDITION_TIME
public:
   const realtick_api::RTTIME& SaleConditionTime() const { return _SaleConditionTime;}
   bool HasSaleConditionTime() const { return _HasSaleConditionTime;}
private:
   realtick_api::RTTIME _SaleConditionTime;
   bool _HasSaleConditionTime;

// T_SALE_CONDITION_XID
public:
   const std::string& SaleConditionXid() const { return _SaleConditionXid;}
   bool HasSaleConditionXid() const { return _HasSaleConditionXid;}
private:
   std::string _SaleConditionXid;
   bool _HasSaleConditionXid;

// T_SALE_CONDITION_DATE
public:
   const realtick_api::RTDATE& SaleConditionDate() const { return _SaleConditionDate;}
   bool HasSaleConditionDate() const { return _HasSaleConditionDate;}
private:
   realtick_api::RTDATE _SaleConditionDate;
   bool _HasSaleConditionDate;

// T_BID_CONDITION
public:
   const std::string& BidCondition() const { return _BidCondition;}
   bool HasBidCondition() const { return _HasBidCondition;}
private:
   std::string _BidCondition;
   bool _HasBidCondition;

// T_ASK_CONDITION
public:
   const std::string& AskCondition() const { return _AskCondition;}
   bool HasAskCondition() const { return _HasAskCondition;}
private:
   std::string _AskCondition;
   bool _HasAskCondition;

// T_BID_DATE
public:
   const realtick_api::RTDATE& BidDate() const { return _BidDate;}
   bool HasBidDate() const { return _HasBidDate;}
private:
   realtick_api::RTDATE _BidDate;
   bool _HasBidDate;

// T_ASK_DATE
public:
   const realtick_api::RTDATE& AskDate() const { return _AskDate;}
   bool HasAskDate() const { return _HasAskDate;}
private:
   realtick_api::RTDATE _AskDate;
   bool _HasAskDate;

// T_INDICATIVE_PRICE
public:
   const realtick_api::RTPRICE& IndicativePrice() const { return _IndicativePrice;}
   bool HasIndicativePrice() const { return _HasIndicativePrice;}
private:
   realtick_api::RTPRICE _IndicativePrice;
   bool _HasIndicativePrice;

// T_SMALLCAP
public:
   const std::string& Smallcap() const { return _Smallcap;}
   bool HasSmallcap() const { return _HasSmallcap;}
private:
   std::string _Smallcap;
   bool _HasSmallcap;

// T_ISIN_NO
public:
   const std::string& IsinNo() const { return _IsinNo;}
   bool HasIsinNo() const { return _HasIsinNo;}
private:
   std::string _IsinNo;
   bool _HasIsinNo;

// T_SUSPENDED_INDICATOR
public:
   int SuspendedIndicator() const { return _SuspendedIndicator;}
   bool HasSuspendedIndicator() const { return _HasSuspendedIndicator;}
private:
   int _SuspendedIndicator;
   bool _HasSuspendedIndicator;

// T_SESS_CLOSE_DATE
public:
   const realtick_api::RTDATE& SessCloseDate() const { return _SessCloseDate;}
   bool HasSessCloseDate() const { return _HasSessCloseDate;}
private:
   realtick_api::RTDATE _SessCloseDate;
   bool _HasSessCloseDate;

// T_SEDOL
public:
   const std::string& Sedol() const { return _Sedol;}
   bool HasSedol() const { return _HasSedol;}
private:
   std::string _Sedol;
   bool _HasSedol;

// T_CAT
public:
   const std::string& Cat() const { return _Cat;}
   bool HasCat() const { return _HasCat;}
private:
   std::string _Cat;
   bool _HasCat;

// T_INTRADAY_HIGH_COUNT
public:
   int IntradayHighCount() const { return _IntradayHighCount;}
   bool HasIntradayHighCount() const { return _HasIntradayHighCount;}
private:
   int _IntradayHighCount;
   bool _HasIntradayHighCount;

// T_INTRADAY_LOW_COUNT
public:
   int IntradayLowCount() const { return _IntradayLowCount;}
   bool HasIntradayLowCount() const { return _HasIntradayLowCount;}
private:
   int _IntradayLowCount;
   bool _HasIntradayLowCount;

// T_LRP_BID
public:
   const realtick_api::RTPRICE& LrpBid() const { return _LrpBid;}
   bool HasLrpBid() const { return _HasLrpBid;}
private:
   realtick_api::RTPRICE _LrpBid;
   bool _HasLrpBid;

// T_LRP_ASK
public:
   const realtick_api::RTPRICE& LrpAsk() const { return _LrpAsk;}
   bool HasLrpAsk() const { return _HasLrpAsk;}
private:
   realtick_api::RTPRICE _LrpAsk;
   bool _HasLrpAsk;

// T_LRP_TIME
public:
   const realtick_api::RTTIME& LrpTime() const { return _LrpTime;}
   bool HasLrpTime() const { return _HasLrpTime;}
private:
   realtick_api::RTTIME _LrpTime;
   bool _HasLrpTime;

// T_LATENCY_1
public:
   int Latency1() const { return _Latency1;}
   bool HasLatency1() const { return _HasLatency1;}
private:
   int _Latency1;
   bool _HasLatency1;

// T_DIVIDEND_YIELD
public:
   const realtick_api::RTPRICE& DividendYield() const { return _DividendYield;}
   bool HasDividendYield() const { return _HasDividendYield;}
private:
   realtick_api::RTPRICE _DividendYield;
   bool _HasDividendYield;

// T_DIVIDEND_RATE
public:
   const realtick_api::RTPRICE& DividendRate() const { return _DividendRate;}
   bool HasDividendRate() const { return _HasDividendRate;}
private:
   realtick_api::RTPRICE _DividendRate;
   bool _HasDividendRate;

// T_CUSIP
public:
   const std::string& Cusip() const { return _Cusip;}
   bool HasCusip() const { return _HasCusip;}
private:
   std::string _Cusip;
   bool _HasCusip;

// T_FINANCIAL_COMMENT
public:
   const std::string& FinancialComment() const { return _FinancialComment;}
   bool HasFinancialComment() const { return _HasFinancialComment;}
private:
   std::string _FinancialComment;
   bool _HasFinancialComment;

// T_DIVIDEND_1
public:
   const realtick_api::RTDATE& Dividend1() const { return _Dividend1;}
   bool HasDividend1() const { return _HasDividend1;}
private:
   realtick_api::RTDATE _Dividend1;
   bool _HasDividend1;

// T_IS_ACTIVE
public:
   int IsActive() const { return _IsActive;}
   bool HasIsActive() const { return _HasIsActive;}
private:
   int _IsActive;
   bool _HasIsActive;

// T_UTC_OFFSET
public:
   int UtcOffset() const { return _UtcOffset;}
   bool HasUtcOffset() const { return _HasUtcOffset;}
private:
   int _UtcOffset;
   bool _HasUtcOffset;

// T_SECURITY_TYPE
public:
   const std::string& SecurityType() const { return _SecurityType;}
   bool HasSecurityType() const { return _HasSecurityType;}
private:
   std::string _SecurityType;
   bool _HasSecurityType;

// T_SYMBOL_ERROR
public:
   int SymbolError() const { return _SymbolError;}
   bool HasSymbolError() const { return _HasSymbolError;}
private:
   int _SymbolError;
   bool _HasSymbolError;

// T_STRIKE_PRC
public:
   const realtick_api::RTPRICE& StrikePrc() const { return _StrikePrc;}
   bool HasStrikePrc() const { return _HasStrikePrc;}
private:
   realtick_api::RTPRICE _StrikePrc;
   bool _HasStrikePrc;

// T_EXPIR_DATE
public:
   const realtick_api::RTDATE& ExpirDate() const { return _ExpirDate;}
   bool HasExpirDate() const { return _HasExpirDate;}
private:
   realtick_api::RTDATE _ExpirDate;
   bool _HasExpirDate;

// T_MATUR_DATE
public:
   const realtick_api::RTDATE& MaturDate() const { return _MaturDate;}
   bool HasMaturDate() const { return _HasMaturDate;}
private:
   realtick_api::RTDATE _MaturDate;
   bool _HasMaturDate;

// T_PUTCALLIND
public:
   const std::string& PutCallInd() const { return _PutCallInd;}
   bool HasPutCallInd() const { return _HasPutCallInd;}
private:
   std::string _PutCallInd;
   bool _HasPutCallInd;

// T_SETTLE_CASH
public:
   const realtick_api::RTPRICE& SettleCash() const { return _SettleCash;}
   bool HasSettleCash() const { return _HasSettleCash;}
private:
   realtick_api::RTPRICE _SettleCash;
   bool _HasSettleCash;

// T_SETTLE_SIZE_1
public:
   int SettleSize1() const { return _SettleSize1;}
   bool HasSettleSize1() const { return _HasSettleSize1;}
private:
   int _SettleSize1;
   bool _HasSettleSize1;

// T_TRADE_ROOT
public:
   const std::string& TradeRoot() const { return _TradeRoot;}
   bool HasTradeRoot() const { return _HasTradeRoot;}
private:
   std::string _TradeRoot;
   bool _HasTradeRoot;

// T_UNDERSYM
public:
   const std::string& UnderSym() const { return _UnderSym;}
   bool HasUnderSym() const { return _HasUnderSym;}
private:
   std::string _UnderSym;
   bool _HasUnderSym;

// T_OPTION_ROOT
public:
   const std::string& OptionRoot() const { return _OptionRoot;}
   bool HasOptionRoot() const { return _HasOptionRoot;}
private:
   std::string _OptionRoot;
   bool _HasOptionRoot;

// T_TICKSZTBL
public:
   const std::string& Ticksztbl() const { return _Ticksztbl;}
   bool HasTicksztbl() const { return _HasTicksztbl;}
private:
   std::string _Ticksztbl;
   bool _HasTicksztbl;

};


class RegionalRecord {

public:
   RegionalRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_TRD_UNITS
public:
   const std::string& TrdUnits() const { return _TrdUnits;}
   bool HasTrdUnits() const { return _HasTrdUnits;}
private:
   std::string _TrdUnits;
   bool _HasTrdUnits;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_EXCH_NAME
public:
   const std::string& ExchName() const { return _ExchName;}
   bool HasExchName() const { return _HasExchName;}
private:
   std::string _ExchName;
   bool _HasExchName;

// T_REGIONAL_BID
public:
   const realtick_api::RTPRICE& RegionalBid() const { return _RegionalBid;}
   bool HasRegionalBid() const { return _HasRegionalBid;}
private:
   realtick_api::RTPRICE _RegionalBid;
   bool _HasRegionalBid;

// T_REGIONAL_BID_TIME
public:
   const realtick_api::RTTIME& RegionalBidTime() const { return _RegionalBidTime;}
   bool HasRegionalBidTime() const { return _HasRegionalBidTime;}
private:
   realtick_api::RTTIME _RegionalBidTime;
   bool _HasRegionalBidTime;

// T_REGIONAL_BIDEXID
public:
   const std::string& RegionalBidexid() const { return _RegionalBidexid;}
   bool HasRegionalBidexid() const { return _HasRegionalBidexid;}
private:
   std::string _RegionalBidexid;
   bool _HasRegionalBidexid;

// T_REGIONAL_BIDSIZE
public:
   int RegionalBidsize() const { return _RegionalBidsize;}
   bool HasRegionalBidsize() const { return _HasRegionalBidsize;}
private:
   int _RegionalBidsize;
   bool _HasRegionalBidsize;

// T_REGIONAL_ASK
public:
   const realtick_api::RTPRICE& RegionalAsk() const { return _RegionalAsk;}
   bool HasRegionalAsk() const { return _HasRegionalAsk;}
private:
   realtick_api::RTPRICE _RegionalAsk;
   bool _HasRegionalAsk;

// T_REGIONAL_ASK_TIME
public:
   const realtick_api::RTTIME& RegionalAskTime() const { return _RegionalAskTime;}
   bool HasRegionalAskTime() const { return _HasRegionalAskTime;}
private:
   realtick_api::RTTIME _RegionalAskTime;
   bool _HasRegionalAskTime;

// T_REGIONAL_ASKEXID
public:
   const std::string& RegionalAskexid() const { return _RegionalAskexid;}
   bool HasRegionalAskexid() const { return _HasRegionalAskexid;}
private:
   std::string _RegionalAskexid;
   bool _HasRegionalAskexid;

// T_REGIONAL_ASKSIZE
public:
   int RegionalAsksize() const { return _RegionalAsksize;}
   bool HasRegionalAsksize() const { return _HasRegionalAsksize;}
private:
   int _RegionalAsksize;
   bool _HasRegionalAsksize;

// T_REGIONAL_TRDPRC_1
public:
   const realtick_api::RTPRICE& RegionalTrdprc1() const { return _RegionalTrdprc1;}
   bool HasRegionalTrdprc1() const { return _HasRegionalTrdprc1;}
private:
   realtick_api::RTPRICE _RegionalTrdprc1;
   bool _HasRegionalTrdprc1;

// T_REGIONAL_TRDTIM_1
public:
   const realtick_api::RTTIME& RegionalTrdtim1() const { return _RegionalTrdtim1;}
   bool HasRegionalTrdtim1() const { return _HasRegionalTrdtim1;}
private:
   realtick_api::RTTIME _RegionalTrdtim1;
   bool _HasRegionalTrdtim1;

// T_REGIONAL_TRDVOL_1
public:
   int RegionalTrdvol1() const { return _RegionalTrdvol1;}
   bool HasRegionalTrdvol1() const { return _HasRegionalTrdvol1;}
private:
   int _RegionalTrdvol1;
   bool _HasRegionalTrdvol1;

// T_REGIONAL_EXCHID
public:
   const std::string& RegionalExchid() const { return _RegionalExchid;}
   bool HasRegionalExchid() const { return _HasRegionalExchid;}
private:
   std::string _RegionalExchid;
   bool _HasRegionalExchid;

// T_REGIONAL_TRDXID_1
public:
   const std::string& RegionalTrdxid1() const { return _RegionalTrdxid1;}
   bool HasRegionalTrdxid1() const { return _HasRegionalTrdxid1;}
private:
   std::string _RegionalTrdxid1;
   bool _HasRegionalTrdxid1;

// T_REGIONAL_TRD_DATE
public:
   const realtick_api::RTDATE& RegionalTrdDate() const { return _RegionalTrdDate;}
   bool HasRegionalTrdDate() const { return _HasRegionalTrdDate;}
private:
   realtick_api::RTDATE _RegionalTrdDate;
   bool _HasRegionalTrdDate;

// T_REGIONAL_OPEN_PRC
public:
   const realtick_api::RTPRICE& RegionalOpenPrc() const { return _RegionalOpenPrc;}
   bool HasRegionalOpenPrc() const { return _HasRegionalOpenPrc;}
private:
   realtick_api::RTPRICE _RegionalOpenPrc;
   bool _HasRegionalOpenPrc;

// T_REGIONAL_HST_CLOSE
public:
   const realtick_api::RTPRICE& RegionalHstClose() const { return _RegionalHstClose;}
   bool HasRegionalHstClose() const { return _HasRegionalHstClose;}
private:
   realtick_api::RTPRICE _RegionalHstClose;
   bool _HasRegionalHstClose;

// T_REGIONAL_HIGH_1
public:
   const realtick_api::RTPRICE& RegionalHigh1() const { return _RegionalHigh1;}
   bool HasRegionalHigh1() const { return _HasRegionalHigh1;}
private:
   realtick_api::RTPRICE _RegionalHigh1;
   bool _HasRegionalHigh1;

// T_REGIONAL_LOW_1
public:
   const realtick_api::RTPRICE& RegionalLow1() const { return _RegionalLow1;}
   bool HasRegionalLow1() const { return _HasRegionalLow1;}
private:
   realtick_api::RTPRICE _RegionalLow1;
   bool _HasRegionalLow1;

// T_REGIONAL_ACVOL_1
public:
   int RegionalAcvol1() const { return _RegionalAcvol1;}
   bool HasRegionalAcvol1() const { return _HasRegionalAcvol1;}
private:
   int _RegionalAcvol1;
   bool _HasRegionalAcvol1;

// T_REGIONAL_STATUS
public:
   const std::string& RegionalStatus() const { return _RegionalStatus;}
   bool HasRegionalStatus() const { return _HasRegionalStatus;}
private:
   std::string _RegionalStatus;
   bool _HasRegionalStatus;

// T_REGIONAL_ASK_DATE
public:
   const realtick_api::RTDATE& RegionalAskDate() const { return _RegionalAskDate;}
   bool HasRegionalAskDate() const { return _HasRegionalAskDate;}
private:
   realtick_api::RTDATE _RegionalAskDate;
   bool _HasRegionalAskDate;

// T_REGIONAL_BID_DATE
public:
   const realtick_api::RTDATE& RegionalBidDate() const { return _RegionalBidDate;}
   bool HasRegionalBidDate() const { return _HasRegionalBidDate;}
private:
   realtick_api::RTDATE _RegionalBidDate;
   bool _HasRegionalBidDate;

// T_REGIONAL_NETCHNG_1
public:
   const realtick_api::RTPRICE& RegionalNetchng1() const { return _RegionalNetchng1;}
   bool HasRegionalNetchng1() const { return _HasRegionalNetchng1;}
private:
   realtick_api::RTPRICE _RegionalNetchng1;
   bool _HasRegionalNetchng1;

// T_REGIONAL_SALE_CONDITION
public:
   int RegionalSaleCondition() const { return _RegionalSaleCondition;}
   bool HasRegionalSaleCondition() const { return _HasRegionalSaleCondition;}
private:
   int _RegionalSaleCondition;
   bool _HasRegionalSaleCondition;

// T_REGIONAL_CHANGE_LAST
public:
   const realtick_api::RTPRICE& RegionalChangeLast() const { return _RegionalChangeLast;}
   bool HasRegionalChangeLast() const { return _HasRegionalChangeLast;}
private:
   realtick_api::RTPRICE _RegionalChangeLast;
   bool _HasRegionalChangeLast;

};


class PositionRecord {

public:
   PositionRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_TBO_ACCOUNT_ID
public:
   int TboAccountId() const { return _TboAccountId;}
   bool HasTboAccountId() const { return _HasTboAccountId;}
private:
   int _TboAccountId;
   bool _HasTboAccountId;

// T_BANK
public:
   const std::string& Bank() const { return _Bank;}
   bool HasBank() const { return _HasBank;}
private:
   std::string _Bank;
   bool _HasBank;

// T_BRANCH
public:
   const std::string& Branch() const { return _Branch;}
   bool HasBranch() const { return _HasBranch;}
private:
   std::string _Branch;
   bool _HasBranch;

// T_CUSTOMER
public:
   const std::string& Customer() const { return _Customer;}
   bool HasCustomer() const { return _HasCustomer;}
private:
   std::string _Customer;
   bool _HasCustomer;

// T_DEPOSIT
public:
   const std::string& Deposit() const { return _Deposit;}
   bool HasDeposit() const { return _HasDeposit;}
private:
   std::string _Deposit;
   bool _HasDeposit;

// T_CURRENCY
public:
   const std::string& Currency() const { return _Currency;}
   bool HasCurrency() const { return _HasCurrency;}
private:
   std::string _Currency;
   bool _HasCurrency;

// T_ACCT_TYPE
public:
   int AcctType() const { return _AcctType;}
   bool HasAcctType() const { return _HasAcctType;}
private:
   int _AcctType;
   bool _HasAcctType;

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_UNDERSYM
public:
   const std::string& Undersym() const { return _Undersym;}
   bool HasUndersym() const { return _HasUndersym;}
private:
   std::string _Undersym;
   bool _HasUndersym;

// T_RANK
public:
   int Rank() const { return _Rank;}
   bool HasRank() const { return _HasRank;}
private:
   int _Rank;
   bool _HasRank;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_AVERAGE_LONG
public:
   double AverageLong() const { return _AverageLong;}
   bool HasAverageLong() const { return _HasAverageLong;}
private:
   double _AverageLong;
   bool _HasAverageLong;

// T_LONGPOS
public:
   double Longpos() const { return _Longpos;}
   bool HasLongpos() const { return _HasLongpos;}
private:
   double _Longpos;
   bool _HasLongpos;

// T_AVERAGE_LONG0
public:
   double AverageLong0() const { return _AverageLong0;}
   bool HasAverageLong0() const { return _HasAverageLong0;}
private:
   double _AverageLong0;
   bool _HasAverageLong0;

// T_HIST_LONG_PRC_0
public:
   double HistLongPrc0() const { return _HistLongPrc0;}
   bool HasHistLongPrc0() const { return _HasHistLongPrc0;}
private:
   double _HistLongPrc0;
   bool _HasHistLongPrc0;

// T_LONGPOS0
public:
   double Longpos0() const { return _Longpos0;}
   bool HasLongpos0() const { return _HasLongpos0;}
private:
   double _Longpos0;
   bool _HasLongpos0;

// T_ORIG_LONGPOS0
public:
   double OrigLongpos0() const { return _OrigLongpos0;}
   bool HasOrigLongpos0() const { return _HasOrigLongpos0;}
private:
   double _OrigLongpos0;
   bool _HasOrigLongpos0;

// T_AVERAGE_SHORT
public:
   double AverageShort() const { return _AverageShort;}
   bool HasAverageShort() const { return _HasAverageShort;}
private:
   double _AverageShort;
   bool _HasAverageShort;

// T_SHORTPOS
public:
   double Shortpos() const { return _Shortpos;}
   bool HasShortpos() const { return _HasShortpos;}
private:
   double _Shortpos;
   bool _HasShortpos;

// T_AVERAGE_SHORT0
public:
   double AverageShort0() const { return _AverageShort0;}
   bool HasAverageShort0() const { return _HasAverageShort0;}
private:
   double _AverageShort0;
   bool _HasAverageShort0;

// T_HIST_SHORT_PRC_0
public:
   double HistShortPrc0() const { return _HistShortPrc0;}
   bool HasHistShortPrc0() const { return _HasHistShortPrc0;}
private:
   double _HistShortPrc0;
   bool _HasHistShortPrc0;

// T_SHORTPOS0
public:
   double Shortpos0() const { return _Shortpos0;}
   bool HasShortpos0() const { return _HasShortpos0;}
private:
   double _Shortpos0;
   bool _HasShortpos0;

// T_ORIG_SHORTPOS0
public:
   double OrigShortpos0() const { return _OrigShortpos0;}
   bool HasOrigShortpos0() const { return _HasOrigShortpos0;}
private:
   double _OrigShortpos0;
   bool _HasOrigShortpos0;

// T_SCALPED_PROFIT
public:
   double ScalpedProfit() const { return _ScalpedProfit;}
   bool HasScalpedProfit() const { return _HasScalpedProfit;}
private:
   double _ScalpedProfit;
   bool _HasScalpedProfit;

// T_MMR
public:
   double Mmr() const { return _Mmr;}
   bool HasMmr() const { return _HasMmr;}
private:
   double _Mmr;
   bool _HasMmr;

// T_TABLE
public:
   const std::string& Table() const { return _Table;}
   bool HasTable() const { return _HasTable;}
private:
   std::string _Table;
   bool _HasTable;

// T_BOUGHT_QTY
public:
   double BoughtQty() const { return _BoughtQty;}
   bool HasBoughtQty() const { return _HasBoughtQty;}
private:
   double _BoughtQty;
   bool _HasBoughtQty;

// T_SOLD_QTY
public:
   double SoldQty() const { return _SoldQty;}
   bool HasSoldQty() const { return _HasSoldQty;}
private:
   double _SoldQty;
   bool _HasSoldQty;

// T_SOLD_SHORT_QTY
public:
   double SoldShortQty() const { return _SoldShortQty;}
   bool HasSoldShortQty() const { return _HasSoldShortQty;}
private:
   double _SoldShortQty;
   bool _HasSoldShortQty;

// T_BOUGHT_AVG_PRC
public:
   double BoughtAvgPrc() const { return _BoughtAvgPrc;}
   bool HasBoughtAvgPrc() const { return _HasBoughtAvgPrc;}
private:
   double _BoughtAvgPrc;
   bool _HasBoughtAvgPrc;

// T_SOLD_AVG_PRC
public:
   double SoldAvgPrc() const { return _SoldAvgPrc;}
   bool HasSoldAvgPrc() const { return _HasSoldAvgPrc;}
private:
   double _SoldAvgPrc;
   bool _HasSoldAvgPrc;

// T_SOLD_SHORT_AVG_PRC
public:
   double SoldShortAvgPrc() const { return _SoldShortAvgPrc;}
   bool HasSoldShortAvgPrc() const { return _HasSoldShortAvgPrc;}
private:
   double _SoldShortAvgPrc;
   bool _HasSoldShortAvgPrc;

// T_COMMISSION
public:
   double Commission() const { return _Commission;}
   bool HasCommission() const { return _HasCommission;}
private:
   double _Commission;
   bool _HasCommission;

// T_NET_FEES
public:
   double NetFees() const { return _NetFees;}
   bool HasNetFees() const { return _HasNetFees;}
private:
   double _NetFees;
   bool _HasNetFees;

// T_HIST_SCALPED_PROFIT
public:
   double HistScalpedProfit() const { return _HistScalpedProfit;}
   bool HasHistScalpedProfit() const { return _HasHistScalpedProfit;}
private:
   double _HistScalpedProfit;
   bool _HasHistScalpedProfit;

};


class CorpActRecord {

public:
   CorpActRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_CA_SPLIT_FACTOR
public:
   double CaSplitFactor() const { return _CaSplitFactor;}
   bool HasCaSplitFactor() const { return _HasCaSplitFactor;}
private:
   double _CaSplitFactor;
   bool _HasCaSplitFactor;

// T_CA_EFF_DATE
public:
   const realtick_api::RTDATE& CaEffDate() const { return _CaEffDate;}
   bool HasCaEffDate() const { return _HasCaEffDate;}
private:
   realtick_api::RTDATE _CaEffDate;
   bool _HasCaEffDate;

// T_CA_TYPE
public:
   int CaType() const { return _CaType;}
   bool HasCaType() const { return _HasCaType;}
private:
   int _CaType;
   bool _HasCaType;

// T_CA_IPO_SYMBOL
public:
   const std::string& CaIpoSymbol() const { return _CaIpoSymbol;}
   bool HasCaIpoSymbol() const { return _HasCaIpoSymbol;}
private:
   std::string _CaIpoSymbol;
   bool _HasCaIpoSymbol;

// T_CA_EXCH_NAME
public:
   const std::string& CaExchName() const { return _CaExchName;}
   bool HasCaExchName() const { return _HasCaExchName;}
private:
   std::string _CaExchName;
   bool _HasCaExchName;

};


class IntradayRecord {

public:
   IntradayRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_OPEN_PRC
public:
   const std::vector<realtick_api::RTPRICE>OpenPrc() const { return _OpenPrc;}
   bool HasOpenPrc() const { return _HasOpenPrc;}
private:
   std::vector<realtick_api::RTPRICE> _OpenPrc;
   bool _HasOpenPrc;

// T_HIGH_1
public:
   const std::vector<realtick_api::RTPRICE>High1() const { return _High1;}
   bool HasHigh1() const { return _HasHigh1;}
private:
   std::vector<realtick_api::RTPRICE> _High1;
   bool _HasHigh1;

// T_LOW_1
public:
   const std::vector<realtick_api::RTPRICE>Low1() const { return _Low1;}
   bool HasLow1() const { return _HasLow1;}
private:
   std::vector<realtick_api::RTPRICE> _Low1;
   bool _HasLow1;

// T_SETTLE
public:
   const std::vector<realtick_api::RTPRICE>Settle() const { return _Settle;}
   bool HasSettle() const { return _HasSettle;}
private:
   std::vector<realtick_api::RTPRICE> _Settle;
   bool _HasSettle;

// T_ACVOL_1
public:
   const std::vector<int>AcVol1() const { return _AcVol1;}
   bool HasAcVol1() const { return _HasAcVol1;}
private:
   std::vector<int> _AcVol1;
   bool _HasAcVol1;

// T_TRDTIM_1
public:
   const std::vector<realtick_api::RTTIME>TrdTim1() const { return _TrdTim1;}
   bool HasTrdTim1() const { return _HasTrdTim1;}
private:
   std::vector<realtick_api::RTTIME> _TrdTim1;
   bool _HasTrdTim1;

// T_TRD_DATE
public:
   const std::vector<realtick_api::RTDATE>TrdDate() const { return _TrdDate;}
   bool HasTrdDate() const { return _HasTrdDate;}
private:
   std::vector<realtick_api::RTDATE> _TrdDate;
   bool _HasTrdDate;

};


class QuoteChainRecord {

public:
   QuoteChainRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_EXCH_NAME
public:
   const std::string& ExchName() const { return _ExchName;}
   bool HasExchName() const { return _HasExchName;}
private:
   std::string _ExchName;
   bool _HasExchName;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_SYMBOL_DESC
public:
   const std::string& SymbolDesc() const { return _SymbolDesc;}
   bool HasSymbolDesc() const { return _HasSymbolDesc;}
private:
   std::string _SymbolDesc;
   bool _HasSymbolDesc;

// T_TRD_UNITS
public:
   const std::string& TrdUnits() const { return _TrdUnits;}
   bool HasTrdUnits() const { return _HasTrdUnits;}
private:
   std::string _TrdUnits;
   bool _HasTrdUnits;

// T_SESSION
public:
   int Session() const { return _Session;}
   bool HasSession() const { return _HasSession;}
private:
   int _Session;
   bool _HasSession;

// T_MINMOVE
public:
   int Minmove() const { return _Minmove;}
   bool HasMinmove() const { return _HasMinmove;}
private:
   int _Minmove;
   bool _HasMinmove;

// T_BASISVALUE
public:
   double Basisvalue() const { return _Basisvalue;}
   bool HasBasisvalue() const { return _HasBasisvalue;}
private:
   double _Basisvalue;
   bool _HasBasisvalue;

// T_COMMODITY_NAME
public:
   const std::string& CommodityName() const { return _CommodityName;}
   bool HasCommodityName() const { return _HasCommodityName;}
private:
   std::string _CommodityName;
   bool _HasCommodityName;

};


class XPermsAccountsRecord {

public:
   XPermsAccountsRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_BANK
public:
   const std::string& Bank() const { return _Bank;}
   bool HasBank() const { return _HasBank;}
private:
   std::string _Bank;
   bool _HasBank;

// T_BRANCH
public:
   const std::string& Branch() const { return _Branch;}
   bool HasBranch() const { return _HasBranch;}
private:
   std::string _Branch;
   bool _HasBranch;

// T_CUSTOMER
public:
   const std::string& Customer() const { return _Customer;}
   bool HasCustomer() const { return _HasCustomer;}
private:
   std::string _Customer;
   bool _HasCustomer;

// T_DEPOSIT
public:
   const std::string& Deposit() const { return _Deposit;}
   bool HasDeposit() const { return _HasDeposit;}
private:
   std::string _Deposit;
   bool _HasDeposit;

// T_ACCT_TYPE
public:
   int AcctType() const { return _AcctType;}
   bool HasAcctType() const { return _HasAcctType;}
private:
   int _AcctType;
   bool _HasAcctType;

// T_MARGIN_SOURCE
public:
   int MarginSource() const { return _MarginSource;}
   bool HasMarginSource() const { return _HasMarginSource;}
private:
   int _MarginSource;
   bool _HasMarginSource;

// T_MARGIN_RULESET_ID
public:
   int MarginRulesetId() const { return _MarginRulesetId;}
   bool HasMarginRulesetId() const { return _HasMarginRulesetId;}
private:
   int _MarginRulesetId;
   bool _HasMarginRulesetId;

// T_MARGIN_RULESET_NAME
public:
   const std::string& MarginRulesetName() const { return _MarginRulesetName;}
   bool HasMarginRulesetName() const { return _HasMarginRulesetName;}
private:
   std::string _MarginRulesetName;
   bool _HasMarginRulesetName;

// T_ACCT_DESC
public:
   const std::string& AcctDesc() const { return _AcctDesc;}
   bool HasAcctDesc() const { return _HasAcctDesc;}
private:
   std::string _AcctDesc;
   bool _HasAcctDesc;

};


class MarketMakersRecord {

public:
   MarketMakersRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_MKT_MKR_ID
public:
   const std::string& MktMkrId() const { return _MktMkrId;}
   bool HasMktMkrId() const { return _HasMktMkrId;}
private:
   std::string _MktMkrId;
   bool _HasMktMkrId;

// T_MKT_SOURCE
public:
   const std::string& MktSource() const { return _MktSource;}
   bool HasMktSource() const { return _HasMktSource;}
private:
   std::string _MktSource;
   bool _HasMktSource;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_MKT_MKR_STATUS
public:
   const std::string& MktMkrStatus() const { return _MktMkrStatus;}
   bool HasMktMkrStatus() const { return _HasMktMkrStatus;}
private:
   std::string _MktMkrStatus;
   bool _HasMktMkrStatus;

// T_TABLE_ID
public:
   int TableId() const { return _TableId;}
   bool HasTableId() const { return _HasTableId;}
private:
   int _TableId;
   bool _HasTableId;

// T_EXCH_NAME
public:
   const std::string& ExchName() const { return _ExchName;}
   bool HasExchName() const { return _HasExchName;}
private:
   std::string _ExchName;
   bool _HasExchName;

// T_SYMBOL_ID
public:
   int SymbolId() const { return _SymbolId;}
   bool HasSymbolId() const { return _HasSymbolId;}
private:
   int _SymbolId;
   bool _HasSymbolId;

// T_QUOTE_UPDATE_TYPE
public:
   int QuoteUpdateType() const { return _QuoteUpdateType;}
   bool HasQuoteUpdateType() const { return _HasQuoteUpdateType;}
private:
   int _QuoteUpdateType;
   bool _HasQuoteUpdateType;

// T_MKT_MKR_ASK
public:
   const realtick_api::RTPRICE& MktMkrAsk() const { return _MktMkrAsk;}
   bool HasMktMkrAsk() const { return _HasMktMkrAsk;}
private:
   realtick_api::RTPRICE _MktMkrAsk;
   bool _HasMktMkrAsk;

// T_MKT_MKR_ASKSIZE
public:
   int MktMkrAsksize() const { return _MktMkrAsksize;}
   bool HasMktMkrAsksize() const { return _HasMktMkrAsksize;}
private:
   int _MktMkrAsksize;
   bool _HasMktMkrAsksize;

// T_MKT_MKR_ASK_TIME
public:
   const realtick_api::RTTIME& MktMkrAskTime() const { return _MktMkrAskTime;}
   bool HasMktMkrAskTime() const { return _HasMktMkrAskTime;}
private:
   realtick_api::RTTIME _MktMkrAskTime;
   bool _HasMktMkrAskTime;

// T_MKT_MKR_DISPLAY
public:
   const std::string& MktMkrDisplay() const { return _MktMkrDisplay;}
   bool HasMktMkrDisplay() const { return _HasMktMkrDisplay;}
private:
   std::string _MktMkrDisplay;
   bool _HasMktMkrDisplay;

// T_MKT_MKR_CHANGE_LAST_ASK
public:
   const realtick_api::RTPRICE& MktMkrChangeLastAsk() const { return _MktMkrChangeLastAsk;}
   bool HasMktMkrChangeLastAsk() const { return _HasMktMkrChangeLastAsk;}
private:
   realtick_api::RTPRICE _MktMkrChangeLastAsk;
   bool _HasMktMkrChangeLastAsk;

// T_MKT_MKR_BID
public:
   const realtick_api::RTPRICE& MktMkrBid() const { return _MktMkrBid;}
   bool HasMktMkrBid() const { return _HasMktMkrBid;}
private:
   realtick_api::RTPRICE _MktMkrBid;
   bool _HasMktMkrBid;

// T_MKT_MKR_BIDSIZE
public:
   int MktMkrBidsize() const { return _MktMkrBidsize;}
   bool HasMktMkrBidsize() const { return _HasMktMkrBidsize;}
private:
   int _MktMkrBidsize;
   bool _HasMktMkrBidsize;

// T_MKT_MKR_BID_TIME
public:
   const realtick_api::RTTIME& MktMkrBidTime() const { return _MktMkrBidTime;}
   bool HasMktMkrBidTime() const { return _HasMktMkrBidTime;}
private:
   realtick_api::RTTIME _MktMkrBidTime;
   bool _HasMktMkrBidTime;

// T_SYMBOL_ERROR
public:
   int SymbolError() const { return _SymbolError;}
   bool HasSymbolError() const { return _HasSymbolError;}
private:
   int _SymbolError;
   bool _HasSymbolError;

// T_MKT_MKR_DATE
public:
   const realtick_api::RTDATE& MktMkrDate() const { return _MktMkrDate;}
   bool HasMktMkrDate() const { return _HasMktMkrDate;}
private:
   realtick_api::RTDATE _MktMkrDate;
   bool _HasMktMkrDate;

};


class NewsRecord {

public:
   NewsRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_NEWS_HEADLINE
public:
   const std::string& NewsHeadline() const { return _NewsHeadline;}
   bool HasNewsHeadline() const { return _HasNewsHeadline;}
private:
   std::string _NewsHeadline;
   bool _HasNewsHeadline;

// T_NEWS_DATE
public:
   const realtick_api::RTDATE& NewsDate() const { return _NewsDate;}
   bool HasNewsDate() const { return _HasNewsDate;}
private:
   realtick_api::RTDATE _NewsDate;
   bool _HasNewsDate;

// T_NEWS_SOURCE
public:
   const std::string& NewsSource() const { return _NewsSource;}
   bool HasNewsSource() const { return _HasNewsSource;}
private:
   std::string _NewsSource;
   bool _HasNewsSource;

// T_NEWS_PAGE
public:
   const std::string& NewsPage() const { return _NewsPage;}
   bool HasNewsPage() const { return _HasNewsPage;}
private:
   std::string _NewsPage;
   bool _HasNewsPage;

// T_NEWS_TIME
public:
   const realtick_api::RTTIME& NewsTime() const { return _NewsTime;}
   bool HasNewsTime() const { return _HasNewsTime;}
private:
   realtick_api::RTTIME _NewsTime;
   bool _HasNewsTime;

// T_NEWS_COUNT
public:
   int NewsCount() const { return _NewsCount;}
   bool HasNewsCount() const { return _HasNewsCount;}
private:
   int _NewsCount;
   bool _HasNewsCount;

// T_NEWS_STORY
public:
   const std::string& NewsStory() const { return _NewsStory;}
   bool HasNewsStory() const { return _HasNewsStory;}
private:
   std::string _NewsStory;
   bool _HasNewsStory;

};


class DailyRecord {

public:
   DailyRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_TRD_DATE
public:
   const std::vector<realtick_api::RTDATE>TrdDate() const { return _TrdDate;}
   bool HasTrdDate() const { return _HasTrdDate;}
private:
   std::vector<realtick_api::RTDATE> _TrdDate;
   bool _HasTrdDate;

// T_OPEN_PRC
public:
   const std::vector<realtick_api::RTPRICE>OpenPrc() const { return _OpenPrc;}
   bool HasOpenPrc() const { return _HasOpenPrc;}
private:
   std::vector<realtick_api::RTPRICE> _OpenPrc;
   bool _HasOpenPrc;

// T_HIGH_1
public:
   const std::vector<realtick_api::RTPRICE>High1() const { return _High1;}
   bool HasHigh1() const { return _HasHigh1;}
private:
   std::vector<realtick_api::RTPRICE> _High1;
   bool _HasHigh1;

// T_LOW_1
public:
   const std::vector<realtick_api::RTPRICE>Low1() const { return _Low1;}
   bool HasLow1() const { return _HasLow1;}
private:
   std::vector<realtick_api::RTPRICE> _Low1;
   bool _HasLow1;

// T_SETTLE
public:
   const std::vector<realtick_api::RTPRICE>Settle() const { return _Settle;}
   bool HasSettle() const { return _HasSettle;}
private:
   std::vector<realtick_api::RTPRICE> _Settle;
   bool _HasSettle;

};


class TicksRecord {

public:
   TicksRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_TRDPRC_1
public:
   const std::vector<realtick_api::RTPRICE>TrdPrc1() const { return _TrdPrc1;}
   bool HasTrdPrc1() const { return _HasTrdPrc1;}
private:
   std::vector<realtick_api::RTPRICE> _TrdPrc1;
   bool _HasTrdPrc1;

// T_TRD_DATE
public:
   const std::vector<realtick_api::RTDATE>TrdDate() const { return _TrdDate;}
   bool HasTrdDate() const { return _HasTrdDate;}
private:
   std::vector<realtick_api::RTDATE> _TrdDate;
   bool _HasTrdDate;

// T_TICK_TYPE
public:
   const std::vector<int>TickType() const { return _TickType;}
   bool HasTickType() const { return _HasTickType;}
private:
   std::vector<int> _TickType;
   bool _HasTickType;

// T_TRDXID_1
public:
   const std::vector<std::string>TrdXid1() const { return _TrdXid1;}
   bool HasTrdXid1() const { return _HasTrdXid1;}
private:
   std::vector<std::string> _TrdXid1;
   bool _HasTrdXid1;

// T_TRDVOL_1
public:
   const std::vector<int>TrdVol1() const { return _TrdVol1;}
   bool HasTrdVol1() const { return _HasTrdVol1;}
private:
   std::vector<int> _TrdVol1;
   bool _HasTrdVol1;

// T_TRDTIM_1
public:
   const std::vector<realtick_api::RTTIME>TrdTim1() const { return _TrdTim1;}
   bool HasTrdTim1() const { return _HasTrdTim1;}
private:
   std::vector<realtick_api::RTTIME> _TrdTim1;
   bool _HasTrdTim1;

// T_DISP_NAME
public:
   const std::vector<std::string>DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::vector<std::string> _DispName;
   bool _HasDispName;

};


class OrderRecord {

public:
   OrderRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_ORDER_ID
public:
   const std::string& OrderId() const { return _OrderId;}
   bool HasOrderId() const { return _HasOrderId;}
private:
   std::string _OrderId;
   bool _HasOrderId;

// T_CLIENT_ORDER_ID
public:
   const std::string& ClientOrderId() const { return _ClientOrderId;}
   bool HasClientOrderId() const { return _HasClientOrderId;}
private:
   std::string _ClientOrderId;
   bool _HasClientOrderId;

// T_TICKET_ID
public:
   const std::string& TicketId() const { return _TicketId;}
   bool HasTicketId() const { return _HasTicketId;}
private:
   std::string _TicketId;
   bool _HasTicketId;

// T_NEWS_DATE
public:
   const realtick_api::RTDATE& NewsDate() const { return _NewsDate;}
   bool HasNewsDate() const { return _HasNewsDate;}
private:
   realtick_api::RTDATE _NewsDate;
   bool _HasNewsDate;

// T_NEWS_TIME
public:
   const realtick_api::RTTIME& NewsTime() const { return _NewsTime;}
   bool HasNewsTime() const { return _HasNewsTime;}
private:
   realtick_api::RTTIME _NewsTime;
   bool _HasNewsTime;

// T_TYPE
public:
   const std::string& Type() const { return _Type;}
   bool HasType() const { return _HasType;}
private:
   std::string _Type;
   bool _HasType;

// T_TRADER_ID
public:
   const std::string& TraderId() const { return _TraderId;}
   bool HasTraderId() const { return _HasTraderId;}
private:
   std::string _TraderId;
   bool _HasTraderId;

// T_ORIGINAL_TRADER_ID
public:
   const std::string& OriginalTraderId() const { return _OriginalTraderId;}
   bool HasOriginalTraderId() const { return _HasOriginalTraderId;}
private:
   std::string _OriginalTraderId;
   bool _HasOriginalTraderId;

// T_CURRENT_STATUS
public:
   const std::string& CurrentStatus() const { return _CurrentStatus;}
   bool HasCurrentStatus() const { return _HasCurrentStatus;}
private:
   std::string _CurrentStatus;
   bool _HasCurrentStatus;

// T_ORIGINAL_ORDER_ID
public:
   const std::string& OriginalOrderId() const { return _OriginalOrderId;}
   bool HasOriginalOrderId() const { return _HasOriginalOrderId;}
private:
   std::string _OriginalOrderId;
   bool _HasOriginalOrderId;

// T_TBO_ACCOUNT_ID
public:
   int TboAccountId() const { return _TboAccountId;}
   bool HasTboAccountId() const { return _HasTboAccountId;}
private:
   int _TboAccountId;
   bool _HasTboAccountId;

// T_BOOK_ID
public:
   int BookId() const { return _BookId;}
   bool HasBookId() const { return _HasBookId;}
private:
   int _BookId;
   bool _HasBookId;

// T_DATE_INDEX
public:
   int DateIndex() const { return _DateIndex;}
   bool HasDateIndex() const { return _HasDateIndex;}
private:
   int _DateIndex;
   bool _HasDateIndex;

// T_GW_BOOK_SEQ_NO
public:
   int GwBookSeqNo() const { return _GwBookSeqNo;}
   bool HasGwBookSeqNo() const { return _HasGwBookSeqNo;}
private:
   int _GwBookSeqNo;
   bool _HasGwBookSeqNo;

// T_RANK
public:
   int Rank() const { return _Rank;}
   bool HasRank() const { return _HasRank;}
private:
   int _Rank;
   bool _HasRank;

// T_BANK
public:
   const std::string& Bank() const { return _Bank;}
   bool HasBank() const { return _HasBank;}
private:
   std::string _Bank;
   bool _HasBank;

// T_BRANCH
public:
   const std::string& Branch() const { return _Branch;}
   bool HasBranch() const { return _HasBranch;}
private:
   std::string _Branch;
   bool _HasBranch;

// T_CUSTOMER
public:
   const std::string& Customer() const { return _Customer;}
   bool HasCustomer() const { return _HasCustomer;}
private:
   std::string _Customer;
   bool _HasCustomer;

// T_DEPOSIT
public:
   const std::string& Deposit() const { return _Deposit;}
   bool HasDeposit() const { return _HasDeposit;}
private:
   std::string _Deposit;
   bool _HasDeposit;

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_CURRENCY
public:
   const std::string& Currency() const { return _Currency;}
   bool HasCurrency() const { return _HasCurrency;}
private:
   std::string _Currency;
   bool _HasCurrency;

// T_ACCT_TYPE
public:
   int AcctType() const { return _AcctType;}
   bool HasAcctType() const { return _HasAcctType;}
private:
   int _AcctType;
   bool _HasAcctType;

// T_REMOTE_ID
public:
   const std::string& RemoteId() const { return _RemoteId;}
   bool HasRemoteId() const { return _HasRemoteId;}
private:
   std::string _RemoteId;
   bool _HasRemoteId;

// T_NEW_REMOTE_ID
public:
   const std::string& NewRemoteId() const { return _NewRemoteId;}
   bool HasNewRemoteId() const { return _HasNewRemoteId;}
private:
   std::string _NewRemoteId;
   bool _HasNewRemoteId;

// T_REFERS_TO_ID
public:
   const std::string& RefersToId() const { return _RefersToId;}
   bool HasRefersToId() const { return _HasRefersToId;}
private:
   std::string _RefersToId;
   bool _HasRefersToId;

// T_CLAIMED_BY_CLERK
public:
   const std::string& ClaimedByClerk() const { return _ClaimedByClerk;}
   bool HasClaimedByClerk() const { return _HasClaimedByClerk;}
private:
   std::string _ClaimedByClerk;
   bool _HasClaimedByClerk;

// T_VOLUME
public:
   int Volume() const { return _Volume;}
   bool HasVolume() const { return _HasVolume;}
private:
   int _Volume;
   bool _HasVolume;

// T_BUYORSELL
public:
   const std::string& Buyorsell() const { return _Buyorsell;}
   bool HasBuyorsell() const { return _HasBuyorsell;}
private:
   std::string _Buyorsell;
   bool _HasBuyorsell;

// T_GOOD_UNTIL
public:
   const std::string& GoodUntil() const { return _GoodUntil;}
   bool HasGoodUntil() const { return _HasGoodUntil;}
private:
   std::string _GoodUntil;
   bool _HasGoodUntil;

// T_VOLUME_TYPE
public:
   const std::string& VolumeType() const { return _VolumeType;}
   bool HasVolumeType() const { return _HasVolumeType;}
private:
   std::string _VolumeType;
   bool _HasVolumeType;

// T_PRICE_TYPE
public:
   const std::string& PriceType() const { return _PriceType;}
   bool HasPriceType() const { return _HasPriceType;}
private:
   std::string _PriceType;
   bool _HasPriceType;

// T_PRICE
public:
   const realtick_api::RTPRICE& Price() const { return _Price;}
   bool HasPrice() const { return _HasPrice;}
private:
   realtick_api::RTPRICE _Price;
   bool _HasPrice;

// T_EXIT_VEHICLE
public:
   const std::string& ExitVehicle() const { return _ExitVehicle;}
   bool HasExitVehicle() const { return _HasExitVehicle;}
private:
   std::string _ExitVehicle;
   bool _HasExitVehicle;

// T_TIME_STAMP
public:
   const std::string& TimeStamp() const { return _TimeStamp;}
   bool HasTimeStamp() const { return _HasTimeStamp;}
private:
   std::string _TimeStamp;
   bool _HasTimeStamp;

// T_STOP_PRICE
public:
   const realtick_api::RTPRICE& StopPrice() const { return _StopPrice;}
   bool HasStopPrice() const { return _HasStopPrice;}
private:
   realtick_api::RTPRICE _StopPrice;
   bool _HasStopPrice;

// T_EXCHANGE
public:
   const std::string& Exchange() const { return _Exchange;}
   bool HasExchange() const { return _HasExchange;}
private:
   std::string _Exchange;
   bool _HasExchange;

// T_TRD_TIME
public:
   const realtick_api::RTTIME& TrdTime() const { return _TrdTime;}
   bool HasTrdTime() const { return _HasTrdTime;}
private:
   realtick_api::RTTIME _TrdTime;
   bool _HasTrdTime;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_BASISVALUE
public:
   double Basisvalue() const { return _Basisvalue;}
   bool HasBasisvalue() const { return _HasBasisvalue;}
private:
   double _Basisvalue;
   bool _HasBasisvalue;

// T_ORDER_TAG
public:
   const std::string& OrderTag() const { return _OrderTag;}
   bool HasOrderTag() const { return _HasOrderTag;}
private:
   std::string _OrderTag;
   bool _HasOrderTag;

// T_ORIGINAL_VOLUME
public:
   int OriginalVolume() const { return _OriginalVolume;}
   bool HasOriginalVolume() const { return _HasOriginalVolume;}
private:
   int _OriginalVolume;
   bool _HasOriginalVolume;

// T_STRIKE_PRC
public:
   const realtick_api::RTPRICE& StrikePrc() const { return _StrikePrc;}
   bool HasStrikePrc() const { return _HasStrikePrc;}
private:
   realtick_api::RTPRICE _StrikePrc;
   bool _HasStrikePrc;

// T_FIX_TRADER_ID
public:
   const std::string& FixTraderId() const { return _FixTraderId;}
   bool HasFixTraderId() const { return _HasFixTraderId;}
private:
   std::string _FixTraderId;
   bool _HasFixTraderId;

// T_TRADER_CAPACITY
public:
   const std::string& TraderCapacity() const { return _TraderCapacity;}
   bool HasTraderCapacity() const { return _HasTraderCapacity;}
private:
   std::string _TraderCapacity;
   bool _HasTraderCapacity;

// T_ORIGINAL_PRICE
public:
   const realtick_api::RTPRICE& OriginalPrice() const { return _OriginalPrice;}
   bool HasOriginalPrice() const { return _HasOriginalPrice;}
private:
   realtick_api::RTPRICE _OriginalPrice;
   bool _HasOriginalPrice;

// T_TABLE
public:
   const std::string& Table() const { return _Table;}
   bool HasTable() const { return _HasTable;}
private:
   std::string _Table;
   bool _HasTable;

// T_LATENCY_3
public:
   double Latency3() const { return _Latency3;}
   bool HasLatency3() const { return _HasLatency3;}
private:
   double _Latency3;
   bool _HasLatency3;

// T_LATENCY_6
public:
   double Latency6() const { return _Latency6;}
   bool HasLatency6() const { return _HasLatency6;}
private:
   double _Latency6;
   bool _HasLatency6;

// T_UTC_OFFSET
public:
   int UtcOffset() const { return _UtcOffset;}
   bool HasUtcOffset() const { return _HasUtcOffset;}
private:
   int _UtcOffset;
   bool _HasUtcOffset;

// T_OMS_CLIENT_TYPE
public:
   int OmsClientType() const { return _OmsClientType;}
   bool HasOmsClientType() const { return _HasOmsClientType;}
private:
   int _OmsClientType;
   bool _HasOmsClientType;

// T_REASON
public:
   const std::string& Reason() const { return _Reason;}
   bool HasReason() const { return _HasReason;}
private:
   std::string _Reason;
   bool _HasReason;

// T_GOOD_FROM
public:
   const std::string& GoodFrom() const { return _GoodFrom;}
   bool HasGoodFrom() const { return _HasGoodFrom;}
private:
   std::string _GoodFrom;
   bool _HasGoodFrom;

// T_VOLUME_TRADED
public:
   int VolumeTraded() const { return _VolumeTraded;}
   bool HasVolumeTraded() const { return _HasVolumeTraded;}
private:
   int _VolumeTraded;
   bool _HasVolumeTraded;

// T_ORDER_RESIDUAL
public:
   int VolumeRemaining() const { return _VolumeRemaining;}
   bool HasVolumeRemaining() const { return _HasVolumeRemaining;}
private:
   int _VolumeRemaining;
   bool _HasVolumeRemaining;

// T_AVG_PRICE
public:
   double AvgPrice() const { return _AvgPrice;}
   bool HasAvgPrice() const { return _HasAvgPrice;}
private:
   double _AvgPrice;
   bool _HasAvgPrice;

// T_OPPOSITE_PARTY
public:
   const std::string& OppositeParty() const { return _OppositeParty;}
   bool HasOppositeParty() const { return _HasOppositeParty;}
private:
   std::string _OppositeParty;
   bool _HasOppositeParty;

// T_USER_MESSAGE
public:
   const std::string& UserMessage() const { return _UserMessage;}
   bool HasUserMessage() const { return _HasUserMessage;}
private:
   std::string _UserMessage;
   bool _HasUserMessage;

// T_EXPIR_DATE
public:
   const realtick_api::RTDATE& ExpirDate() const { return _ExpirDate;}
   bool HasExpirDate() const { return _HasExpirDate;}
private:
   realtick_api::RTDATE _ExpirDate;
   bool _HasExpirDate;

// T_PUTCALLIND
public:
   const std::string& Putcallind() const { return _Putcallind;}
   bool HasPutcallind() const { return _HasPutcallind;}
private:
   std::string _Putcallind;
   bool _HasPutcallind;

// T_UNDERSYM
public:
   const std::string& Undersym() const { return _Undersym;}
   bool HasUndersym() const { return _HasUndersym;}
private:
   std::string _Undersym;
   bool _HasUndersym;

// T_SHORT_LOCATE_ID
public:
   const std::string& ShortLocateId() const { return _ShortLocateId;}
   bool HasShortLocateId() const { return _HasShortLocateId;}
private:
   std::string _ShortLocateId;
   bool _HasShortLocateId;

// T_MINMOVE
public:
   int Minmove() const { return _Minmove;}
   bool HasMinmove() const { return _HasMinmove;}
private:
   int _Minmove;
   bool _HasMinmove;

// T_BID
public:
   const realtick_api::RTPRICE& Bid() const { return _Bid;}
   bool HasBid() const { return _HasBid;}
private:
   realtick_api::RTPRICE _Bid;
   bool _HasBid;

// T_ASK
public:
   const realtick_api::RTPRICE& Ask() const { return _Ask;}
   bool HasAsk() const { return _HasAsk;}
private:
   realtick_api::RTPRICE _Ask;
   bool _HasAsk;

// T_COMMISSION
public:
   double Commission() const { return _Commission;}
   bool HasCommission() const { return _HasCommission;}
private:
   double _Commission;
   bool _HasCommission;

// T_COMMISSION_CODE
public:
   const std::string& CommissionCode() const { return _CommissionCode;}
   bool HasCommissionCode() const { return _HasCommissionCode;}
private:
   std::string _CommissionCode;
   bool _HasCommissionCode;

// T_COMMISSION_RATE
public:
   double CommissionRate() const { return _CommissionRate;}
   bool HasCommissionRate() const { return _HasCommissionRate;}
private:
   double _CommissionRate;
   bool _HasCommissionRate;

// T_COMMISSION_RATE_TYPE
public:
   int CommissionRateType() const { return _CommissionRateType;}
   bool HasCommissionRateType() const { return _HasCommissionRateType;}
private:
   int _CommissionRateType;
   bool _HasCommissionRateType;

// T_LINKED_ORDER_ID
public:
   const std::string& LinkedOrderId() const { return _LinkedOrderId;}
   bool HasLinkedOrderId() const { return _HasLinkedOrderId;}
private:
   std::string _LinkedOrderId;
   bool _HasLinkedOrderId;

// T_LINKED_ORDER_RELATIONSHIP
public:
   int LinkedOrderRelationship() const { return _LinkedOrderRelationship;}
   bool HasLinkedOrderRelationship() const { return _HasLinkedOrderRelationship;}
private:
   int _LinkedOrderRelationship;
   bool _HasLinkedOrderRelationship;

// T_LINKED_ORDER_CANCELLATION
public:
   int LinkedOrderCancellation() const { return _LinkedOrderCancellation;}
   bool HasLinkedOrderCancellation() const { return _HasLinkedOrderCancellation;}
private:
   int _LinkedOrderCancellation;
   bool _HasLinkedOrderCancellation;

// T_SPREAD_LEG_COUNT
public:
   int SpreadLegCount() const { return _SpreadLegCount;}
   bool HasSpreadLegCount() const { return _HasSpreadLegCount;}
private:
   int _SpreadLegCount;
   bool _HasSpreadLegCount;

// T_SPREAD_NUM_LEGS
public:
   int SpreadNumLegs() const { return _SpreadNumLegs;}
   bool HasSpreadNumLegs() const { return _HasSpreadNumLegs;}
private:
   int _SpreadNumLegs;
   bool _HasSpreadNumLegs;

// T_SPREAD_LEG_NUMBER
public:
   int SpreadLegNumber() const { return _SpreadLegNumber;}
   bool HasSpreadLegNumber() const { return _HasSpreadLegNumber;}
private:
   int _SpreadLegNumber;
   bool _HasSpreadLegNumber;

// T_SPREAD_LEG_PRICE_TYPE
public:
   int SpreadLegPriceType() const { return _SpreadLegPriceType;}
   bool HasSpreadLegPriceType() const { return _HasSpreadLegPriceType;}
private:
   int _SpreadLegPriceType;
   bool _HasSpreadLegPriceType;

// T_SPREAD_LEG_LEAN_PRIORITY
public:
   int SpreadLegLeanPriority() const { return _SpreadLegLeanPriority;}
   bool HasSpreadLegLeanPriority() const { return _HasSpreadLegLeanPriority;}
private:
   int _SpreadLegLeanPriority;
   bool _HasSpreadLegLeanPriority;

// T_PAIR_SPREAD
public:
   double PairSpread() const { return _PairSpread;}
   bool HasPairSpread() const { return _HasPairSpread;}
private:
   double _PairSpread;
   bool _HasPairSpread;

// T_PAIR_SPREAD_TYPE
public:
   int PairSpreadType() const { return _PairSpreadType;}
   bool HasPairSpreadType() const { return _HasPairSpreadType;}
private:
   int _PairSpreadType;
   bool _HasPairSpreadType;

// T_PAIR_RATIO
public:
   double PairRatio() const { return _PairRatio;}
   bool HasPairRatio() const { return _HasPairRatio;}
private:
   double _PairRatio;
   bool _HasPairRatio;

// T_PAIR_CASH
public:
   double PairCash() const { return _PairCash;}
   bool HasPairCash() const { return _HasPairCash;}
private:
   double _PairCash;
   bool _HasPairCash;

// T_PAIR_IMBALANCE_LIMIT
public:
   double PairImbalanceLimit() const { return _PairImbalanceLimit;}
   bool HasPairImbalanceLimit() const { return _HasPairImbalanceLimit;}
private:
   double _PairImbalanceLimit;
   bool _HasPairImbalanceLimit;

// T_PAIR_IMBALANCE_LIMIT_TYPE
public:
   int PairImbalanceLimitType() const { return _PairImbalanceLimitType;}
   bool HasPairImbalanceLimitType() const { return _HasPairImbalanceLimitType;}
private:
   int _PairImbalanceLimitType;
   bool _HasPairImbalanceLimitType;

// T_PAIR_LEG_1_BENCHMARK
public:
   double PairLeg1Benchmark() const { return _PairLeg1Benchmark;}
   bool HasPairLeg1Benchmark() const { return _HasPairLeg1Benchmark;}
private:
   double _PairLeg1Benchmark;
   bool _HasPairLeg1Benchmark;

// T_PAIR_LEG_2_BENCHMARK
public:
   double PairLeg2Benchmark() const { return _PairLeg2Benchmark;}
   bool HasPairLeg2Benchmark() const { return _HasPairLeg2Benchmark;}
private:
   double _PairLeg2Benchmark;
   bool _HasPairLeg2Benchmark;

// T_PAIR_TARGET
public:
   double PairTarget() const { return _PairTarget;}
   bool HasPairTarget() const { return _HasPairTarget;}
private:
   double _PairTarget;
   bool _HasPairTarget;

// T_PAIR_LEG_1_BENCHMARK_TYPE
public:
   int PairLeg1BenchmarkType() const { return _PairLeg1BenchmarkType;}
   bool HasPairLeg1BenchmarkType() const { return _HasPairLeg1BenchmarkType;}
private:
   int _PairLeg1BenchmarkType;
   bool _HasPairLeg1BenchmarkType;

// T_PAIR_LEG_2_BENCHMARK_TYPE
public:
   int PairLeg2BenchmarkType() const { return _PairLeg2BenchmarkType;}
   bool HasPairLeg2BenchmarkType() const { return _HasPairLeg2BenchmarkType;}
private:
   int _PairLeg2BenchmarkType;
   bool _HasPairLeg2BenchmarkType;

// T_SPREAD_CLIP
public:
   double SpreadClip() const { return _SpreadClip;}
   bool HasSpreadClip() const { return _HasSpreadClip;}
private:
   double _SpreadClip;
   bool _HasSpreadClip;

// T_SPREAD_CLIP_TYPE
public:
   int SpreadClipType() const { return _SpreadClipType;}
   bool HasSpreadClipType() const { return _HasSpreadClipType;}
private:
   int _SpreadClipType;
   bool _HasSpreadClipType;

// T_ECN_FEE
public:
   double EcnFee() const { return _EcnFee;}
   bool HasEcnFee() const { return _HasEcnFee;}
private:
   double _EcnFee;
   bool _HasEcnFee;

// T_SHARES_ALLOCATED
public:
   int SharesAllocated() const { return _SharesAllocated;}
   bool HasSharesAllocated() const { return _HasSharesAllocated;}
private:
   int _SharesAllocated;
   bool _HasSharesAllocated;

// T_ALLOCATED_VALUE
public:
   double AllocatedValue() const { return _AllocatedValue;}
   bool HasAllocatedValue() const { return _HasAllocatedValue;}
private:
   double _AllocatedValue;
   bool _HasAllocatedValue;

};


class OptionServerRecord {

public:
   OptionServerRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_PUTCALLIND
public:
   const std::string& PutCallId() const { return _PutCallId;}
   bool HasPutCallId() const { return _HasPutCallId;}
private:
   std::string _PutCallId;
   bool _HasPutCallId;

// T_STRIKE_PRC
public:
   const realtick_api::RTPRICE& StrikePrice() const { return _StrikePrice;}
   bool HasStrikePrice() const { return _HasStrikePrice;}
private:
   realtick_api::RTPRICE _StrikePrice;
   bool _HasStrikePrice;

// T_TIME_TO_EXPIRATION
public:
   double TimeToExpire() const { return _TimeToExpire;}
   bool HasTimeToExpire() const { return _HasTimeToExpire;}
private:
   double _TimeToExpire;
   bool _HasTimeToExpire;

// T_RATE
public:
   double Rate() const { return _Rate;}
   bool HasRate() const { return _HasRate;}
private:
   double _Rate;
   bool _HasRate;

// T_DIV_DATE_1
public:
   const realtick_api::RTDATE& DividendDate1() const { return _DividendDate1;}
   bool HasDividendDate1() const { return _HasDividendDate1;}
private:
   realtick_api::RTDATE _DividendDate1;
   bool _HasDividendDate1;

// T_DIV_AMOUNT_1
public:
   double DividendAmout1() const { return _DividendAmout1;}
   bool HasDividendAmout1() const { return _HasDividendAmout1;}
private:
   double _DividendAmout1;
   bool _HasDividendAmout1;

// T_DIV_DATE_2
public:
   const realtick_api::RTDATE& DividendDate2() const { return _DividendDate2;}
   bool HasDividendDate2() const { return _HasDividendDate2;}
private:
   realtick_api::RTDATE _DividendDate2;
   bool _HasDividendDate2;

// T_DIV_AMOUNT_2
public:
   double DividendAmout2() const { return _DividendAmout2;}
   bool HasDividendAmout2() const { return _HasDividendAmout2;}
private:
   double _DividendAmout2;
   bool _HasDividendAmout2;

// T_DIV_DATE_3
public:
   const realtick_api::RTDATE& DividendDate3() const { return _DividendDate3;}
   bool HasDividendDate3() const { return _HasDividendDate3;}
private:
   realtick_api::RTDATE _DividendDate3;
   bool _HasDividendDate3;

// T_DIV_AMOUNT_3
public:
   double DividendAmout3() const { return _DividendAmout3;}
   bool HasDividendAmout3() const { return _HasDividendAmout3;}
private:
   double _DividendAmout3;
   bool _HasDividendAmout3;

// T_DIV_DATE_4
public:
   const realtick_api::RTDATE& DividendDate4() const { return _DividendDate4;}
   bool HasDividendDate4() const { return _HasDividendDate4;}
private:
   realtick_api::RTDATE _DividendDate4;
   bool _HasDividendDate4;

// T_DIV_AMOUNT_4
public:
   double DividendAmout4() const { return _DividendAmout4;}
   bool HasDividendAmout4() const { return _HasDividendAmout4;}
private:
   double _DividendAmout4;
   bool _HasDividendAmout4;

// T_DIV_DATE_5
public:
   const realtick_api::RTDATE& DividendDate5() const { return _DividendDate5;}
   bool HasDividendDate5() const { return _HasDividendDate5;}
private:
   realtick_api::RTDATE _DividendDate5;
   bool _HasDividendDate5;

// T_DIV_AMOUNT_5
public:
   double DividendAmout5() const { return _DividendAmout5;}
   bool HasDividendAmout5() const { return _HasDividendAmout5;}
private:
   double _DividendAmout5;
   bool _HasDividendAmout5;

// T_DIV_DATE_6
public:
   const realtick_api::RTDATE& DividendDate6() const { return _DividendDate6;}
   bool HasDividendDate6() const { return _HasDividendDate6;}
private:
   realtick_api::RTDATE _DividendDate6;
   bool _HasDividendDate6;

// T_DIV_AMOUNT_6
public:
   double DividendAmout6() const { return _DividendAmout6;}
   bool HasDividendAmout6() const { return _HasDividendAmout6;}
private:
   double _DividendAmout6;
   bool _HasDividendAmout6;

// T_ORIGINAL_PRICE
public:
   const realtick_api::RTPRICE& OriginalPrice() const { return _OriginalPrice;}
   bool HasOriginalPrice() const { return _HasOriginalPrice;}
private:
   realtick_api::RTPRICE _OriginalPrice;
   bool _HasOriginalPrice;

// T_UNDERLIER_PRICE
public:
   const realtick_api::RTPRICE& UnderlierPrice() const { return _UnderlierPrice;}
   bool HasUnderlierPrice() const { return _HasUnderlierPrice;}
private:
   realtick_api::RTPRICE _UnderlierPrice;
   bool _HasUnderlierPrice;

// T_OPT_CALC_MODEL
public:
   int Model() const { return _Model;}
   bool HasModel() const { return _HasModel;}
private:
   int _Model;
   bool _HasModel;

// T_IMPLIED
public:
   double ImpliedVol() const { return _ImpliedVol;}
   bool HasImpliedVol() const { return _HasImpliedVol;}
private:
   double _ImpliedVol;
   bool _HasImpliedVol;

// T_THEO
public:
   double Premium() const { return _Premium;}
   bool HasPremium() const { return _HasPremium;}
private:
   double _Premium;
   bool _HasPremium;

// T_DELTA
public:
   double Delta() const { return _Delta;}
   bool HasDelta() const { return _HasDelta;}
private:
   double _Delta;
   bool _HasDelta;

// T_VEGA
public:
   double Vega() const { return _Vega;}
   bool HasVega() const { return _HasVega;}
private:
   double _Vega;
   bool _HasVega;

// T_GAMMA
public:
   double Gamma() const { return _Gamma;}
   bool HasGamma() const { return _HasGamma;}
private:
   double _Gamma;
   bool _HasGamma;

// T_THETA
public:
   double Theta() const { return _Theta;}
   bool HasTheta() const { return _HasTheta;}
private:
   double _Theta;
   bool _HasTheta;

// T_UNDERSYM
public:
   const std::string& UnderSym() const { return _UnderSym;}
   bool HasUnderSym() const { return _HasUnderSym;}
private:
   std::string _UnderSym;
   bool _HasUnderSym;

// T_OPTION_ROOT
public:
   const std::string& OptionRoot() const { return _OptionRoot;}
   bool HasOptionRoot() const { return _HasOptionRoot;}
private:
   std::string _OptionRoot;
   bool _HasOptionRoot;

};


class DepositRecord {

public:
   DepositRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_TBO_ACCOUNT_ID
public:
   int TboAccountId() const { return _TboAccountId;}
   bool HasTboAccountId() const { return _HasTboAccountId;}
private:
   int _TboAccountId;
   bool _HasTboAccountId;

// T_BANK
public:
   const std::string& Bank() const { return _Bank;}
   bool HasBank() const { return _HasBank;}
private:
   std::string _Bank;
   bool _HasBank;

// T_BRANCH
public:
   const std::string& Branch() const { return _Branch;}
   bool HasBranch() const { return _HasBranch;}
private:
   std::string _Branch;
   bool _HasBranch;

// T_CUSTOMER
public:
   const std::string& Customer() const { return _Customer;}
   bool HasCustomer() const { return _HasCustomer;}
private:
   std::string _Customer;
   bool _HasCustomer;

// T_DEPOSIT
public:
   const std::string& Deposit() const { return _Deposit;}
   bool HasDeposit() const { return _HasDeposit;}
private:
   std::string _Deposit;
   bool _HasDeposit;

// T_CURRENCY
public:
   const std::string& Currency() const { return _Currency;}
   bool HasCurrency() const { return _HasCurrency;}
private:
   std::string _Currency;
   bool _HasCurrency;

// T_RANK
public:
   int Rank() const { return _Rank;}
   bool HasRank() const { return _HasRank;}
private:
   int _Rank;
   bool _HasRank;

// T_MARKETVALUE_0
public:
   double Marketvalue0() const { return _Marketvalue0;}
   bool HasMarketvalue0() const { return _HasMarketvalue0;}
private:
   double _Marketvalue0;
   bool _HasMarketvalue0;

// T_CASH_BALANCE
public:
   double CashBalance() const { return _CashBalance;}
   bool HasCashBalance() const { return _HasCashBalance;}
private:
   double _CashBalance;
   bool _HasCashBalance;

// T_EQUITY_BALANCE
public:
   double EquityBalance() const { return _EquityBalance;}
   bool HasEquityBalance() const { return _HasEquityBalance;}
private:
   double _EquityBalance;
   bool _HasEquityBalance;

// T_EXTRA_CBP
public:
   double ExtraCbp() const { return _ExtraCbp;}
   bool HasExtraCbp() const { return _HasExtraCbp;}
private:
   double _ExtraCbp;
   bool _HasExtraCbp;

// T_MIN_BALANCE
public:
   double MinBalance() const { return _MinBalance;}
   bool HasMinBalance() const { return _HasMinBalance;}
private:
   double _MinBalance;
   bool _HasMinBalance;

// T_MAX_ORDER_SIZE
public:
   double MaxOrderSize() const { return _MaxOrderSize;}
   bool HasMaxOrderSize() const { return _HasMaxOrderSize;}
private:
   double _MaxOrderSize;
   bool _HasMaxOrderSize;

// T_EXCESS_EQ_0
public:
   double ExcessEq0() const { return _ExcessEq0;}
   bool HasExcessEq0() const { return _HasExcessEq0;}
private:
   double _ExcessEq0;
   bool _HasExcessEq0;

// T_EXCESS_EQ
public:
   double ExcessEq() const { return _ExcessEq;}
   bool HasExcessEq() const { return _HasExcessEq;}
private:
   double _ExcessEq;
   bool _HasExcessEq;

// T_MMR_0
public:
   double Mmr0() const { return _Mmr0;}
   bool HasMmr0() const { return _HasMmr0;}
private:
   double _Mmr0;
   bool _HasMmr0;

// T_MMR
public:
   double Mmr() const { return _Mmr;}
   bool HasMmr() const { return _HasMmr;}
private:
   double _Mmr;
   bool _HasMmr;

// T_SCALPED_PROFIT
public:
   double ScalpedProfit() const { return _ScalpedProfit;}
   bool HasScalpedProfit() const { return _HasScalpedProfit;}
private:
   double _ScalpedProfit;
   bool _HasScalpedProfit;

// T_CASH_BALANCE_ADJ
public:
   double CashBalanceAdj() const { return _CashBalanceAdj;}
   bool HasCashBalanceAdj() const { return _HasCashBalanceAdj;}
private:
   double _CashBalanceAdj;
   bool _HasCashBalanceAdj;

// T_MMR_0_ADJ
public:
   double Mmr0Adj() const { return _Mmr0Adj;}
   bool HasMmr0Adj() const { return _HasMmr0Adj;}
private:
   double _Mmr0Adj;
   bool _HasMmr0Adj;

// T_SMA_0
public:
   double Sma0() const { return _Sma0;}
   bool HasSma0() const { return _HasSma0;}
private:
   double _Sma0;
   bool _HasSma0;

// T_SMA_0_ADJ
public:
   double Sma0Adj() const { return _Sma0Adj;}
   bool HasSma0Adj() const { return _HasSma0Adj;}
private:
   double _Sma0Adj;
   bool _HasSma0Adj;

// T_HOUSE_EXCESS_0
public:
   double HouseExcess0() const { return _HouseExcess0;}
   bool HasHouseExcess0() const { return _HasHouseExcess0;}
private:
   double _HouseExcess0;
   bool _HasHouseExcess0;

// T_ORQ_0
public:
   double Orq0() const { return _Orq0;}
   bool HasOrq0() const { return _HasOrq0;}
private:
   double _Orq0;
   bool _HasOrq0;

// T_CALC_TIME
public:
   const std::string& CalcTime() const { return _CalcTime;}
   bool HasCalcTime() const { return _HasCalcTime;}
private:
   std::string _CalcTime;
   bool _HasCalcTime;

// T_DAYS_BACK
public:
   int DaysBack() const { return _DaysBack;}
   bool HasDaysBack() const { return _HasDaysBack;}
private:
   int _DaysBack;
   bool _HasDaysBack;

// T_COST
public:
   double Cost() const { return _Cost;}
   bool HasCost() const { return _HasCost;}
private:
   double _Cost;
   bool _HasCost;

// T_MMR_0_NON_DAYTRADE_ADJ
public:
   double Mmr0NonDaytradeAdj() const { return _Mmr0NonDaytradeAdj;}
   bool HasMmr0NonDaytradeAdj() const { return _HasMmr0NonDaytradeAdj;}
private:
   double _Mmr0NonDaytradeAdj;
   bool _HasMmr0NonDaytradeAdj;

// T_SRV_PENDING_MARGIN
public:
   double SrvPendingMargin() const { return _SrvPendingMargin;}
   bool HasSrvPendingMargin() const { return _HasSrvPendingMargin;}
private:
   double _SrvPendingMargin;
   bool _HasSrvPendingMargin;

// T_COMMISSION
public:
   double Commission() const { return _Commission;}
   bool HasCommission() const { return _HasCommission;}
private:
   double _Commission;
   bool _HasCommission;

// T_NET_FEES
public:
   double NetFees() const { return _NetFees;}
   bool HasNetFees() const { return _HasNetFees;}
private:
   double _NetFees;
   bool _HasNetFees;

// T_HIST_SCALPED_PROFIT
public:
   double HistScalpedProfit() const { return _HistScalpedProfit;}
   bool HasHistScalpedProfit() const { return _HasHistScalpedProfit;}
private:
   double _HistScalpedProfit;
   bool _HasHistScalpedProfit;

// T_TABLE
public:
   const std::string& Table() const { return _Table;}
   bool HasTable() const { return _HasTable;}
private:
   std::string _Table;
   bool _HasTable;

// T_PENDING_MARGIN
public:
   double PendingMargin() const { return _PendingMargin;}
   bool HasPendingMargin() const { return _HasPendingMargin;}
private:
   double _PendingMargin;
   bool _HasPendingMargin;

// T_CBP_REMAINING
public:
   double CbpRemaining() const { return _CbpRemaining;}
   bool HasCbpRemaining() const { return _HasCbpRemaining;}
private:
   double _CbpRemaining;
   bool _HasCbpRemaining;

};


class SymbolGuideRecord {

public:
   SymbolGuideRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_EXCH_NAME
public:
   const std::string& ExchName() const { return _ExchName;}
   bool HasExchName() const { return _HasExchName;}
private:
   std::string _ExchName;
   bool _HasExchName;

// T_STYP
public:
   int Styp() const { return _Styp;}
   bool HasStyp() const { return _HasStyp;}
private:
   int _Styp;
   bool _HasStyp;

// T_SYMBOL_DESC
public:
   const std::string& SymbolDesc() const { return _SymbolDesc;}
   bool HasSymbolDesc() const { return _HasSymbolDesc;}
private:
   std::string _SymbolDesc;
   bool _HasSymbolDesc;

// T_ISIN_NO
public:
   const std::string& IsinNo() const { return _IsinNo;}
   bool HasIsinNo() const { return _HasIsinNo;}
private:
   std::string _IsinNo;
   bool _HasIsinNo;

// T_COUNTRY
public:
   const std::string& Country() const { return _Country;}
   bool HasCountry() const { return _HasCountry;}
private:
   std::string _Country;
   bool _HasCountry;

// T_COMMODITY_NAME
public:
   const std::string& CommodityName() const { return _CommodityName;}
   bool HasCommodityName() const { return _HasCommodityName;}
private:
   std::string _CommodityName;
   bool _HasCommodityName;

// T_BLOOMBERG_CODE
public:
   const std::string& BloombergCode() const { return _BloombergCode;}
   bool HasBloombergCode() const { return _HasBloombergCode;}
private:
   std::string _BloombergCode;
   bool _HasBloombergCode;

// T_BLOOMBERG_CODE_FULL
public:
   const std::string& BloombergCodeFull() const { return _BloombergCodeFull;}
   bool HasBloombergCodeFull() const { return _HasBloombergCodeFull;}
private:
   std::string _BloombergCodeFull;
   bool _HasBloombergCodeFull;

// T_RIC_CODE
public:
   const std::string& RicCode() const { return _RicCode;}
   bool HasRicCode() const { return _HasRicCode;}
private:
   std::string _RicCode;
   bool _HasRicCode;

// T_SEDOL
public:
   const std::string& Sedol() const { return _Sedol;}
   bool HasSedol() const { return _HasSedol;}
private:
   std::string _Sedol;
   bool _HasSedol;

// T_GICS_SECTOR
public:
   const std::string& GicsSector() const { return _GicsSector;}
   bool HasGicsSector() const { return _HasGicsSector;}
private:
   std::string _GicsSector;
   bool _HasGicsSector;

// T_GICS_INDUSTRY
public:
   const std::string& GicsIndustry() const { return _GicsIndustry;}
   bool HasGicsIndustry() const { return _HasGicsIndustry;}
private:
   std::string _GicsIndustry;
   bool _HasGicsIndustry;

// T_GICS_SUBINDUSTRY
public:
   const std::string& GicsSubindustry() const { return _GicsSubindustry;}
   bool HasGicsSubindustry() const { return _HasGicsSubindustry;}
private:
   std::string _GicsSubindustry;
   bool _HasGicsSubindustry;

// T_CUSIP
public:
   const std::string& Cusip() const { return _Cusip;}
   bool HasCusip() const { return _HasCusip;}
private:
   std::string _Cusip;
   bool _HasCusip;

};


class SecurityRecord {

public:
   SecurityRecord( realtick_api::RTDataReader& rd ); 
   void Clear();

// T_DISP_NAME
public:
   const std::string& DispName() const { return _DispName;}
   bool HasDispName() const { return _HasDispName;}
private:
   std::string _DispName;
   bool _HasDispName;

// T_EARNINGS
public:
   const realtick_api::RTPRICE& Earnings() const { return _Earnings;}
   bool HasEarnings() const { return _HasEarnings;}
private:
   realtick_api::RTPRICE _Earnings;
   bool _HasEarnings;

// T_PERATIO
public:
   const realtick_api::RTPRICE& Peratio() const { return _Peratio;}
   bool HasPeratio() const { return _HasPeratio;}
private:
   realtick_api::RTPRICE _Peratio;
   bool _HasPeratio;

// T_DIVPAYDATE
public:
   const realtick_api::RTDATE& Divpaydate() const { return _Divpaydate;}
   bool HasDivpaydate() const { return _HasDivpaydate;}
private:
   realtick_api::RTDATE _Divpaydate;
   bool _HasDivpaydate;

// T_EXDIVDATE
public:
   const realtick_api::RTDATE& Exdivdate() const { return _Exdivdate;}
   bool HasExdivdate() const { return _HasExdivdate;}
private:
   realtick_api::RTDATE _Exdivdate;
   bool _HasExdivdate;

// T_DIVIDEND
public:
   const realtick_api::RTPRICE& Dividend() const { return _Dividend;}
   bool HasDividend() const { return _HasDividend;}
private:
   realtick_api::RTPRICE _Dividend;
   bool _HasDividend;

// T_HIGH_52
public:
   const realtick_api::RTPRICE& High52() const { return _High52;}
   bool HasHigh52() const { return _HasHigh52;}
private:
   realtick_api::RTPRICE _High52;
   bool _HasHigh52;

// T_LOW_52
public:
   const realtick_api::RTPRICE& Low52() const { return _Low52;}
   bool HasLow52() const { return _HasLow52;}
private:
   realtick_api::RTPRICE _Low52;
   bool _HasLow52;

// T_RIC_CODE
public:
   const std::string& RicCode() const { return _RicCode;}
   bool HasRicCode() const { return _HasRicCode;}
private:
   std::string _RicCode;
   bool _HasRicCode;

// T_BLOOMBERG_CODE
public:
   const std::string& BloombergCode() const { return _BloombergCode;}
   bool HasBloombergCode() const { return _HasBloombergCode;}
private:
   std::string _BloombergCode;
   bool _HasBloombergCode;

// T_HIGH52_DATE
public:
   const realtick_api::RTDATE& High52Date() const { return _High52Date;}
   bool HasHigh52Date() const { return _HasHigh52Date;}
private:
   realtick_api::RTDATE _High52Date;
   bool _HasHigh52Date;

// T_LOW52_DATE
public:
   const realtick_api::RTDATE& Low52Date() const { return _Low52Date;}
   bool HasLow52Date() const { return _HasLow52Date;}
private:
   realtick_api::RTDATE _Low52Date;
   bool _HasLow52Date;

// T_ISSUERS_SECTOR_STR
public:
   const std::string& IssuersSectorStr() const { return _IssuersSectorStr;}
   bool HasIssuersSectorStr() const { return _HasIssuersSectorStr;}
private:
   std::string _IssuersSectorStr;
   bool _HasIssuersSectorStr;

// T_MG_SICM
public:
   const realtick_api::RTPRICE& MgSicm() const { return _MgSicm;}
   bool HasMgSicm() const { return _HasMgSicm;}
private:
   realtick_api::RTPRICE _MgSicm;
   bool _HasMgSicm;

// T_MKT_CAP
public:
   const realtick_api::RTPRICE& MktCap() const { return _MktCap;}
   bool HasMktCap() const { return _HasMktCap;}
private:
   realtick_api::RTPRICE _MktCap;
   bool _HasMktCap;

// T_COMPANY_NAME
public:
   const std::string& CompanyName() const { return _CompanyName;}
   bool HasCompanyName() const { return _HasCompanyName;}
private:
   std::string _CompanyName;
   bool _HasCompanyName;

// T_PRIMARY_EXCHANGE
public:
   const std::string& PrimaryExchange() const { return _PrimaryExchange;}
   bool HasPrimaryExchange() const { return _HasPrimaryExchange;}
private:
   std::string _PrimaryExchange;
   bool _HasPrimaryExchange;

// T_DIVIDEND_FREQ_N
public:
   int DividendFreqN() const { return _DividendFreqN;}
   bool HasDividendFreqN() const { return _HasDividendFreqN;}
private:
   int _DividendFreqN;
   bool _HasDividendFreqN;

// T_SECURITY_CATEGORY
public:
   int SecurityCategory() const { return _SecurityCategory;}
   bool HasSecurityCategory() const { return _HasSecurityCategory;}
private:
   int _SecurityCategory;
   bool _HasSecurityCategory;

// T_ISIN_NO
public:
   const std::string& IsinNo() const { return _IsinNo;}
   bool HasIsinNo() const { return _HasIsinNo;}
private:
   std::string _IsinNo;
   bool _HasIsinNo;

// T_SEDOL
public:
   const std::string& Sedol() const { return _Sedol;}
   bool HasSedol() const { return _HasSedol;}
private:
   std::string _Sedol;
   bool _HasSedol;

// T_DIVIDEND_YIELD
public:
   const realtick_api::RTPRICE& DividendYield() const { return _DividendYield;}
   bool HasDividendYield() const { return _HasDividendYield;}
private:
   realtick_api::RTPRICE _DividendYield;
   bool _HasDividendYield;

// T_DIVIDEND_RATE
public:
   const realtick_api::RTPRICE& DividendRate() const { return _DividendRate;}
   bool HasDividendRate() const { return _HasDividendRate;}
private:
   realtick_api::RTPRICE _DividendRate;
   bool _HasDividendRate;

// T_CUSIP
public:
   const std::string& Cusip() const { return _Cusip;}
   bool HasCusip() const { return _HasCusip;}
private:
   std::string _Cusip;
   bool _HasCusip;

// T_BETA
public:
   const realtick_api::RTPRICE& Beta() const { return _Beta;}
   bool HasBeta() const { return _HasBeta;}
private:
   realtick_api::RTPRICE _Beta;
   bool _HasBeta;

// T_SPLIT_FACTOR_1
public:
   double SplitFactor1() const { return _SplitFactor1;}
   bool HasSplitFactor1() const { return _HasSplitFactor1;}
private:
   double _SplitFactor1;
   bool _HasSplitFactor1;

// T_SPLIT_DATE_1
public:
   const realtick_api::RTDATE& SplitDate1() const { return _SplitDate1;}
   bool HasSplitDate1() const { return _HasSplitDate1;}
private:
   realtick_api::RTDATE _SplitDate1;
   bool _HasSplitDate1;

// T_SHARES_OUT
public:
   int SharesOut() const { return _SharesOut;}
   bool HasSharesOut() const { return _HasSharesOut;}
private:
   int _SharesOut;
   bool _HasSharesOut;

// T_GICS_SECTOR
public:
   const std::string& GicsSector() const { return _GicsSector;}
   bool HasGicsSector() const { return _HasGicsSector;}
private:
   std::string _GicsSector;
   bool _HasGicsSector;

// T_GICS_INDUSTRY
public:
   const std::string& GicsIndustry() const { return _GicsIndustry;}
   bool HasGicsIndustry() const { return _HasGicsIndustry;}
private:
   std::string _GicsIndustry;
   bool _HasGicsIndustry;

// T_GICS_SUBINDUSTRY
public:
   const std::string& GicsSubindustry() const { return _GicsSubindustry;}
   bool HasGicsSubindustry() const { return _HasGicsSubindustry;}
private:
   std::string _GicsSubindustry;
   bool _HasGicsSubindustry;

// T_COUNTRY
public:
   const std::string& Country() const { return _Country;}
   bool HasCountry() const { return _HasCountry;}
private:
   std::string _Country;
   bool _HasCountry;

// T_PROC_DATE
public:
   const realtick_api::RTDATE& ProcDate() const { return _ProcDate;}
   bool HasProcDate() const { return _HasProcDate;}
private:
   realtick_api::RTDATE _ProcDate;
   bool _HasProcDate;

// T_CLOSE50DAVG_1D
public:
   double Close50davg1d() const { return _Close50davg1d;}
   bool HasClose50davg1d() const { return _HasClose50davg1d;}
private:
   double _Close50davg1d;
   bool _HasClose50davg1d;

// T_CLOSE200DAVG_1D
public:
   double Close200davg1d() const { return _Close200davg1d;}
   bool HasClose200davg1d() const { return _HasClose200davg1d;}
private:
   double _Close200davg1d;
   bool _HasClose200davg1d;

// T_RSI14D_1D
public:
   double Rsi14d1d() const { return _Rsi14d1d;}
   bool HasRsi14d1d() const { return _HasRsi14d1d;}
private:
   double _Rsi14d1d;
   bool _HasRsi14d1d;

// T_VOLUME20DAVG_1D
public:
   double Volume20davg1d() const { return _Volume20davg1d;}
   bool HasVolume20davg1d() const { return _HasVolume20davg1d;}
private:
   double _Volume20davg1d;
   bool _HasVolume20davg1d;

// T_VOLUME50DAVG_1D
public:
   double Volume50davg1d() const { return _Volume50davg1d;}
   bool HasVolume50davg1d() const { return _HasVolume50davg1d;}
private:
   double _Volume50davg1d;
   bool _HasVolume50davg1d;

// T_VOLUME200DAVG_1D
public:
   double Volume200davg1d() const { return _Volume200davg1d;}
   bool HasVolume200davg1d() const { return _HasVolume200davg1d;}
private:
   double _Volume200davg1d;
   bool _HasVolume200davg1d;

// T_VOLUME5DAVG_1D
public:
   double Volume5davg1d() const { return _Volume5davg1d;}
   bool HasVolume5davg1d() const { return _HasVolume5davg1d;}
private:
   double _Volume5davg1d;
   bool _HasVolume5davg1d;

// T_VOLUME10DAVG_1D
public:
   double Volume10davg1d() const { return _Volume10davg1d;}
   bool HasVolume10davg1d() const { return _HasVolume10davg1d;}
private:
   double _Volume10davg1d;
   bool _HasVolume10davg1d;

// T_CLOSE5DAVG_1D
public:
   double Close5davg1d() const { return _Close5davg1d;}
   bool HasClose5davg1d() const { return _HasClose5davg1d;}
private:
   double _Close5davg1d;
   bool _HasClose5davg1d;

// T_CLOSE10DAVG_1D
public:
   double Close10davg1d() const { return _Close10davg1d;}
   bool HasClose10davg1d() const { return _HasClose10davg1d;}
private:
   double _Close10davg1d;
   bool _HasClose10davg1d;

// T_CLOSE20DAVG_1D
public:
   double Close20davg1d() const { return _Close20davg1d;}
   bool HasClose20davg1d() const { return _HasClose20davg1d;}
private:
   double _Close20davg1d;
   bool _HasClose20davg1d;

// T_RSI9D_1D
public:
   double Rsi9d1d() const { return _Rsi9d1d;}
   bool HasRsi9d1d() const { return _HasRsi9d1d;}
private:
   double _Rsi9d1d;
   bool _HasRsi9d1d;

// T_RSI25D_1D
public:
   double Rsi25d1d() const { return _Rsi25d1d;}
   bool HasRsi25d1d() const { return _HasRsi25d1d;}
private:
   double _Rsi25d1d;
   bool _HasRsi25d1d;

// T_BOLLINGER_UPPER21D_1D
public:
   double BollingerUpper21d1d() const { return _BollingerUpper21d1d;}
   bool HasBollingerUpper21d1d() const { return _HasBollingerUpper21d1d;}
private:
   double _BollingerUpper21d1d;
   bool _HasBollingerUpper21d1d;

// T_BOLLINGER_LOWER21D_1D
public:
   double BollingerLower21d1d() const { return _BollingerLower21d1d;}
   bool HasBollingerLower21d1d() const { return _HasBollingerLower21d1d;}
private:
   double _BollingerLower21d1d;
   bool _HasBollingerLower21d1d;

// T_ADX14D_1D
public:
   double Adx14d1d() const { return _Adx14d1d;}
   bool HasAdx14d1d() const { return _HasAdx14d1d;}
private:
   double _Adx14d1d;
   bool _HasAdx14d1d;

// T_PLUSDI14D_1D
public:
   double Plusdi14d1d() const { return _Plusdi14d1d;}
   bool HasPlusdi14d1d() const { return _HasPlusdi14d1d;}
private:
   double _Plusdi14d1d;
   bool _HasPlusdi14d1d;

// T_MINUSDI14D_1D
public:
   double Minusdi14d1d() const { return _Minusdi14d1d;}
   bool HasMinusdi14d1d() const { return _HasMinusdi14d1d;}
private:
   double _Minusdi14d1d;
   bool _HasMinusdi14d1d;

// T_HIGH15DMAX_1D
public:
   double High15dmax1d() const { return _High15dmax1d;}
   bool HasHigh15dmax1d() const { return _HasHigh15dmax1d;}
private:
   double _High15dmax1d;
   bool _HasHigh15dmax1d;

// T_LOW15DMIN_1D
public:
   double Low15dmin1d() const { return _Low15dmin1d;}
   bool HasLow15dmin1d() const { return _HasLow15dmin1d;}
private:
   double _Low15dmin1d;
   bool _HasLow15dmin1d;

// T_HLVOLATILITY10D_1D
public:
   double Hlvolatility10d1d() const { return _Hlvolatility10d1d;}
   bool HasHlvolatility10d1d() const { return _HasHlvolatility10d1d;}
private:
   double _Hlvolatility10d1d;
   bool _HasHlvolatility10d1d;

};

#endif // APIRECORDS_H
