#ifndef OPTION_EVENTS_HEADER
#define OPTION_EVENTS_HEADER

#include <string>
#include <map>
#include <list>
#include <iostream>
#include "atlsafe.h"


#import "c:\\option\\OptionFeed.tlb" raw_interfaces_only

using namespace OptionFeed;

namespace Framework
{
	namespace WOPR
	{                         
		class RegisteredEvents : public OptionFeed::ICallBackMethods
		{
		private:
			ULONG m_ulRefCount;

		public:
			RegisteredEvents() : m_ulRefCount(0) {}
			~RegisteredEvents() {}

			// IUnknown:
			virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
			virtual ULONG STDMETHODCALLTYPE AddRef();
			virtual ULONG STDMETHODCALLTYPE Release();

			//ICallBackMethods:
			virtual HRESULT STDMETHODCALLTYPE MarketData_ErrorHandler(BSTR msg);
			virtual HRESULT STDMETHODCALLTYPE MarketData_ConnectedHandler(BSTR msg);
			virtual HRESULT STDMETHODCALLTYPE MarketData_DisConnectedHandler(BSTR msg);


			virtual HRESULT STDMETHODCALLTYPE MarketData_Depth_BackHandler(OptionFeed::IScalpObjects_InstrInfo* instr,__int64 ts,BSTR partID,long mod,
																		   BSTR numBid , BSTR numask, LPSAFEARRAY bidExch,LPSAFEARRAY askExch,
																		   LPSAFEARRAY bidbk,LPSAFEARRAY askbk);
		};

	}//end Namespace WOPR
}//end Framework
#endif