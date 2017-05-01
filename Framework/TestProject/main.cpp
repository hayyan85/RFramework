#include <iostream>
#include <intrin.h>  
#include <boost/thread.hpp>
#include "SterlingOrderUpdate.h"

#include "tinyxml.h"
#ifdef TIXML_USE_STL
#include <iostream>
#include <sstream>
using namespace std;
#else
#include <stdio.h>
#endif

#if defined( WIN32 ) && defined( TUNE )
#include <crtdbg.h>
_CrtMemState startMemState;
_CrtMemState endMemState;
#endif




#import "C:\\Windows\SysWOW64\Sti\Sterling.tlb" no_namespace    /*this is the project name*/


class CSink : public _ISTIEventsEvents
{
private:
	ULONG m_ulRefCount;
	LPTYPEINFO m_ptinfoEnglish;  // English type information for application interface
	LPTYPEINFO m_ptinfoGerman;   // German type information for application interface
	
	//----------------- Implementation of IUnknown Methods:-------------------------------
	
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;

		if (riid == __uuidof(_ISTIEventsEvents) || riid == __uuidof(IUnknown) || riid == __uuidof(IDispatch) )
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
	
	virtual ULONG STDMETHODCALLTYPE AddRef()
	{
		return ::InterlockedIncrement(&m_ulRefCount);
	}

	virtual ULONG STDMETHODCALLTYPE Release()
	{
		ULONG ulRefCount = ::InterlockedDecrement(&m_ulRefCount);

		if (ulRefCount == 0)
			delete this;

		return ulRefCount;
		//return NULL;
	}
	
	//--------------------------------------------------------------------------------
     
     public:
	 //Class Constructor
	 CSink() : m_ulRefCount(0) {}
	 ~CSink() {}

	 
	 //IDispatch Methods implemetation-------------------------------------------------------
	 STDMETHODIMP GetTypeInfoCount(UINT *pctinfo)
	 {       
		 return E_NOTIMPL;
	 }


	 STDMETHODIMP GetTypeInfo( UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo )
	 {
		 return E_NOTIMPL;
	 }

	 STDMETHODIMP GetIDsOfNames(const IID &riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId )
	 {
		 return E_NOTIMPL;
	 }
	 

	 void FindTag(std::string tname)
	 {
		 //Update order
		 TiXmlDocument doc;
		 
		 doc.Parse(tname.c_str(), 0, TIXML_ENCODING_UTF8);
		 TiXmlElement* root = doc.FirstChildElement();
		 TiXmlNode* root_node = 0;
		 TiXmlNode* node = 0;
		 std::string a;
		 std::string b;
		 StiOrderUpdate* ou = new StiOrderUpdate();
		 
		 while( node = root->IterateChildren( node ) )
		 {
			a = node->Value();
			b = node->FirstChild()->Value();

			if(a=="bstrAccount")
			{	
				ou->set_bstrAccount(b);
			}
			else if (a=="nOrderStatus")
			{
				ou->set_nOrderStatus(atoi(b.c_str()));
			}
			else if (a=="bstrSymbol")
			{
				ou->set_bstrSymbol(b);
			}
		 }//end while

		 std::cout << "Finised populating object\n";
	 }

	 STDMETHODIMP Invoke( DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS * pdispparams, VARIANT * pvarResult, EXCEPINFO * pexcepinfo, UINT * puArgErr)
	 { 
		 /*
		 DispIdMember    Type
		 13              OrderUpdate
		 15              OrderConfirm
		 12              TradeUpdate
		 */
		 
		 if(dispidMember == 13)
		 {
			 BSTR ta = pdispparams->rgvarg->bstrVal;

			 // given BSTR bs
			 std::wstring ws(ta, SysStringLen(ta));
			 const std::string s( ws.begin(), ws.end() );
			 FindTag(s);
		 }
		 
		 
		
		
			
		
		 //return DispInvoke( this, m_ptinfoEnglish,dispidMember, wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr); 
		 std::cout << "Event occured Disp";
	     return NULL;
	 }
	 //--------------------------------------------------------------------------------------

	 
};

void SendOrder()
{
	char *acct = "DEMO888";
	//Register for events
	//-----------------Send an order-------------------------------------
	ISTIOrderPtr cust_ord(__uuidof(STIOrder));
	cust_ord->Account = _com_util::ConvertStringToBSTR(acct);
	cust_ord->Side = _com_util::ConvertStringToBSTR("B");
	cust_ord->Symbol = _com_util::ConvertStringToBSTR("IBM");
	cust_ord->Quantity = 500;
	cust_ord->PriceType = ptSTILmt;
	cust_ord->Tif = "D";
	cust_ord->Destination = "NYSE";
	cust_ord->ClOrderID = "12112IDHayyan";
	int a = cust_ord->SubmitOrder();
	if(a!=0)
	{
          __debugbreak();
	}
	
	//---------------------------------------------------------------------
}

void main()
{
   
	HRESULT hr = CoInitializeEx( NULL, COINIT_APARTMENTTHREADED );

	//Register Events
 	ISTIAppPtr app(__uuidof(STIApp));
    ISTIEventsPtr evnt(__uuidof(STIEvents));
		 
	_bstr_t nme = app->GetTraderName();
	app->SetModeXML(true);
	bool a = app->IsApiEnabled();
	evnt->SetOrderEventsAsStructs(true);
	
	IConnectionPointContainer *point_container = NULL;
	IConnectionPoint *conn_point = NULL;

	//See if this implements a sink type interface
	//retrieve from a pointer to an interface that the object implements
	hr = evnt->QueryInterface(IID_IConnectionPointContainer,(void**)&point_container);

	//Get Interface Pointer to the Events
	hr = point_container->FindConnectionPoint(__uuidof(_ISTIEventsEvents),&conn_point);

	DWORD cookie;
	CSink *snk = new CSink();

	//Pass custom Interface to the Events
	hr = conn_point->Advise(snk,&cookie);
	
	if(hr==S_OK)
	{
		SendOrder();
		std::cout << "Order sent \n";
	}
	else
	{
		__debugbreak();
	}
	
	
	std::cout << "Waiting for event\n";
    
	bool bRet;
	MSG msg;
	while( (bRet = GetMessage( &msg, NULL, 0, 0 )) > 0)
	{
		std::cout << "GetMessage";
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}