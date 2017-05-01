#ifndef _REALTICK_API_H
#define _REALTICK_API_H

#ifdef _WIN32
#include <stdint.h>
namespace sp = std;
#else

#if !__GNUC_PREREQ(4,6)
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#define nullptr 0
#include <tr1/memory>
namespace sp = std::tr1;
#else
namespace sp = std;
#endif
#endif

namespace realtick_api
{

#ifdef _WIN32
	#pragma once
	#ifdef RTAPI_EXPORTS
		#define RTAPI_API __declspec(dllexport)
	#else
		#define RTAPI_API __declspec(dllimport)
	#endif
#else
	#define RTAPI_API 
#endif

// TODO: put TYPE_xxx values into an enum, or make const properties of some class?
// TODO: eliminate other Win32 types?

/*****************
    Definitions
 *****************/

#define TYPE_DOUBLE			1
#define TYPE_INT32			2
#define TYPE_LONG			TYPE_INT32
#define TYPE_INT16			3
#define TYPE_SHORT			TYPE_INT16
#define TYPE_INT			TYPE_INT16
#define TYPE_LPACK			5
#define TYPE_PRICE			TYPE_LPACK
#define TYPE_STRING			6
#define TYPE_DATE			7
#define TYPE_TIME			8
#define TYPE_BLOB			9

#define TYPE_VECTOR_DOUBLE	11
#define TYPE_VECTOR_LONG	12
#define TYPE_VECTOR_INT		13
#define TYPE_VECTOR_DPACK	14
#define TYPE_VECTOR_LPACK	15
#define TYPE_VECTOR_STRING	16
#define TYPE_VECTOR_DATE	17
#define TYPE_VECTOR_TIME	18
#define TYPE_VECTOR_BLOB	19

#define TYPE_DOUBLE_VECTOR	TYPE_VECTOR_DOUBLE
#define TYPE_LONG_VECTOR	TYPE_VECTOR_LONG
#define TYPE_INT32_VECTOR	TYPE_VECTOR_LONG
#define TYPE_SHORT_VECTOR	TYPE_VECTOR_INT
#define TYPE_INT16_VECTOR	TYPE_VECTOR_INT
#define TYPE_PRICE_VECTOR	TYPE_VECTOR_LPACK
#define TYPE_STRING_VECTOR	TYPE_VECTOR_STRING
#define TYPE_DATE_VECTOR	TYPE_VECTOR_DATE
#define TYPE_TIME_VECTOR	TYPE_VECTOR_TIME
#define TYPE_BLOB_VECTOR	TYPE_VECTOR_BLOB

#define TYPE_DATETIME			22
#define TYPE_INT64				24

#define TYPE_DATETIME_VECTOR	32
#define TYPE_INT64_VECTOR		34

#define TYPE_EMPTY			99  // FID with no data
#define TYPE_BLANK			TYPE_EMPTY
#define TYPE_ERROR			101	 // no data available for this field, with cause code



#pragma pack(1)

typedef struct _RT_TIME_
{
	uint16_t wMinutes;	// Minutes from midnight
	uint16_t wSeconds;	// Seconds into minute
}
RTTIME;


typedef struct _RT_DATE_
{
	uint8_t cDay;   // 1 - 31
	uint8_t cMonth; // 1 - 12
	uint16_t iYear; // 1992, 2003 etc
}
RTDATE;

typedef struct _RT_DATETIME_
{
	RTDATE	date;
	RTTIME	time;
}
RTDATETIME;

typedef struct _RTPRICE_
{
	uint16_t wBase;
	int32_t lVal;
}
RTPRICE;

#pragma pack()



/*****************
	RTClientAdaptor -- data access
 *****************/

class RTCA_Impl;

class RTAPI_API RTClientAdaptor
{
public:
	static void Startup();
	static void Shutdown();

public:
	RTClientAdaptor(const char* szUser, 
			  const char* szDomain, 
			  const char* szMachine, 
			  const char* szService, 
			  const char* szTopic);
	virtual ~RTClientAdaptor();

	bool Connect();
	bool Request(const char* szItem, const char* szFormat, bool bPagedRequest=false);
	bool Advise(const char* szItem, const char* szFormat);
	bool AdviseRequest(const char* szItem, const char* szFormat);
	bool Unadvise(const char* szItem, const char* szFormat);
	bool Poke(const char* szItem, const char* szFormat, const void* pData, long dwLen);
	bool Execute(const char* szItem);
	bool Terminate(uint32_t reason);

	virtual void OnInitAck(bool bStatus) {}
	virtual void OnExecAck(const char* szItem, bool bStatus) {}
	virtual void OnOtherAck(const char* szItem, bool bStatus) {}
	virtual void OnUpdate(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength) {}
	virtual void OnResponse(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength, bool bLastPage) {}
	virtual void OnTerminate(uint32_t reason) {}
private:
	friend class RTCA_Impl;
	RTCA_Impl *_pImpl;
};


/*****************
	RT4 -- self-describing binary data
 *****************/

class RTDataReader_Impl;
class RTDataWriter_Impl;

class RTAPI_API RTDataReader
{
public:
	RTDataReader( const void* );
	virtual ~RTDataReader();

	uint16_t NumRecords();
	uint16_t NumFields();
	bool NextRecord();
	bool NextField();
	bool ReadField( uint32_t& id, uint32_t& type );

	bool ReadShort( int16_t& val );
	bool ReadShortVector( const int16_t*& pVal, uint32_t& dwNumElements );
	bool ReadLong( int32_t& val );
	bool ReadLongVector( const int32_t*& pVal, uint32_t& dwNumElements );
	bool ReadInt64( int64_t& val );
	bool ReadInt64Vector( const int64_t*& pVal, uint32_t& dwNumElements );
	bool ReadDouble( double& val );
	bool ReadDoubleVector( const double*& pVal, uint32_t& dwNumElements );
	bool ReadString( const char*& val );
	bool ReadStringVector( const char*& pVal, uint32_t& dwNumElements, uint32_t& dwTotalLen );
	bool ReadPrice( RTPRICE& prc );
	bool ReadPriceVector( uint16_t& wBase, const int32_t*& pVal, uint32_t& dwNumElements );
	bool ReadDate( RTDATE& val );
	bool ReadDateVector( const RTDATE*& pVal, uint32_t& dwNumElements );
	bool ReadTime( RTTIME& val );
	bool ReadTimeVector( const RTTIME*& pVal, uint32_t& dwNumElements );
	bool ReadDateTime( const RTDATETIME*& pVal );
	bool ReadDateTimeVector( const RTDATETIME*& pVal, uint32_t& dwNumElements );
	bool ReadBlob( const void*& pVal, uint32_t& dwSize );
	bool ReadBlobVector( const void*& pVal, uint32_t& dwNumElements, uint32_t& dwTotalLen );
	bool ReadError( int16_t& val );

private:
	RTDataReader_Impl* _pImpl;
};


class RTAPI_API RTDataWriter
{
public:
	RTDataWriter();
	virtual ~RTDataWriter();

	void* GetData();
	long GetDataLen();

	bool NewRecord( );
	bool AddShort( uint16_t Id, int16_t val );
	bool AddShortVector( uint16_t Id, const int16_t* pVal, uint32_t dwNumElements );
	bool AddLong( uint16_t Id, int32_t val );
	bool AddLongVector( uint16_t Id, const int32_t* pVal, uint32_t dwNumElements );
	bool AddInt64( uint16_t Id, int64_t val );
	bool AddInt64Vector( uint16_t Id, const int64_t* pVal, uint32_t dwNumElements );
	bool AddDouble( uint16_t Id, double val );
	bool AddDoubleVector( uint16_t Id, const double* pVal, uint32_t dwNumElements );
	bool AddString( uint16_t Id, const char* val );
	bool AddStringVector( uint16_t Id, const char* pVal, uint32_t dwNumElements, uint32_t dwTotalLen );
	bool AddPrice( uint16_t Id, uint16_t wBase, int32_t val );
	bool AddPriceVector( uint16_t Id, uint16_t wBase, const int32_t* pVal, uint32_t dwNumElements );
	bool AddDate( uint16_t Id, RTDATE val );
	bool AddDateVector( uint16_t Id, const RTDATE* pVal, uint32_t dwNumElements );
	bool AddTime( uint16_t Id, RTTIME val );
	bool AddTimeVector( uint16_t Id, const RTTIME* pVal, uint32_t dwNumElements );
	bool AddDateTime( uint16_t Id, const RTDATETIME* pVal );
	bool AddDateTimeVector( uint16_t Id, const RTDATETIME* pVal, uint32_t dwNumElements );
	bool AddBlob( uint16_t Id, const void* pVal, uint32_t dwSize );
	bool AddBlobVector( uint16_t Id, const void* pVal, uint32_t dwNumElements, uint32_t dwTotalLen );
	bool AddError( uint16_t Id, int16_t val );
	bool AddBlank( uint16_t Id );

private:
	RTDataWriter_Impl* _pImpl;
};


/*****************
	Price Conversions
 *****************/

class RTAPI_API RTPriceHelper
{
public:
	static bool PriceToDouble( const RTPRICE& price, double& val );
	static bool DoubleToPrice( double val, uint16_t baseCode, RTPRICE& price );
};


/*****************
	Synchronization
 *****************/

class RTCriticalSection_Impl;
class RTLock_Impl;
class RTEvent_Impl;

class RTAPI_API RTCriticalSection
{
public:
	RTCriticalSection();
	virtual ~RTCriticalSection();
	friend class RTLock_Impl;
private:
	RTCriticalSection_Impl* _pImpl;
};

class RTAPI_API RTLock
{
public:
	RTLock(RTCriticalSection&);
	virtual ~RTLock();
private:
	RTLock_Impl* _pImpl;
};


class RTAPI_API RTEvent
{
public:
	RTEvent();
	virtual ~RTEvent();
	static bool Wait( uint32_t ms, RTEvent& evt );
	static bool Wait( uint32_t ms, int& whichOne, RTEvent& evt1, RTEvent& evt2 );
	void Set();
private:
	RTEvent_Impl* _pImpl;
};

uint32_t RTAPI_API RTSleep( uint32_t ms, bool alertable = false );

} // namespace realtick_api

#endif // _REALTICK_API_H


