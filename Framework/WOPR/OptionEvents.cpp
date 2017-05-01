#include <iostream>
#include <sstream> 
#include <conio.h>
#include <stdio.h>
#include <sstream>
#include <time.h>

#ifndef OPTION_EVENTS_HEADER
#include "OptionEvents.h"
#endif 

using namespace OptionFeed;

namespace Framework
{
	namespace WOPR
	{
		HRESULT RegisteredEvents::QueryInterface(REFIID riid, void** ppvObject)
		{
			if (ppvObject == NULL)
				return E_POINTER;

			if (riid == __uuidof(OptionFeed::ICallBackMethods) || riid == __uuidof(IUnknown))
			{
				*ppvObject = this;
			}
			else
			{
				*ppvObject = NULL;
				return E_NOINTERFACE;
			}

			static_cast<IUnknown*>(*ppvObject)->AddRef();

			return S_OK;
		}

		ULONG RegisteredEvents::AddRef()
		{
			return ::InterlockedIncrement(&m_ulRefCount);
		}

		ULONG RegisteredEvents::Release()
		{
			ULONG ulRefCount = ::InterlockedDecrement(&m_ulRefCount);

			if (ulRefCount == 0)
				delete this;

			return ulRefCount;
		}

		//Interface Events
		HRESULT RegisteredEvents::MarketData_ErrorHandler(BSTR msg)
		{
			std::cout << "Error Handler : " << msg;
			return S_OK;
		}

		HRESULT RegisteredEvents::MarketData_ConnectedHandler(BSTR msg)
		{
			std::cout << "Connected Handler : " << msg;
			return S_OK;
		}

		HRESULT RegisteredEvents::MarketData_DisConnectedHandler(BSTR msg)
		{
			std::cout << "Connected Handler : " << msg;
			return S_OK;
		}


		HRESULT RegisteredEvents::MarketData_Depth_BackHandler(OptionFeed::IScalpObjects_InstrInfo* instr,__int64 ts,BSTR partID,long mod,
			BSTR numBid , BSTR numask, LPSAFEARRAY bidExch,LPSAFEARRAY askExch,
			LPSAFEARRAY bidbk,LPSAFEARRAY askbk)
		{
			std::cout << "Back Handler : " ;
			return S_OK;
		}
	}//end namespace ScalpEvents
}//end namespace OptionQuoter


