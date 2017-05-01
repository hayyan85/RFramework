<small>
© 2012 RealTick LLC All rights reserved.

<em>Use of the RealTick API®, including, but not limited to, all code and
documentation, is subject to the RealTick API® terms and conditions which are
posted on www.realtick.com.  The code contained herein is deemed to be part of
the "Licensed Product" as referred to in the end user license agreements
between the user and RealTick.</em>
</small>

<hr />
# Programming with the RealTick API for C++ 

<hr />
## Introduction

This guide describes how to use the classes and methods in the RealTick API to send and receive QDS and EMS messages.  All of the classes and methods referenced here are defined in the file "RealTickApi.h" which is installed in the API's "Include" folder.

Before reading this documentation, it may be helpful to review the <b>RealTick Api Users Guide</b> which describes the QDS market data service and introduces the following key concepts:

- Service/Topic/Table
- Request/Advise
- Ack/Nack
- TQL
- FIDs
- TAL4 Data Format

If you are interested in order entry, the document called <b>ApiOrderEntry ("Order Entry with the RealTick APIs")</b> gives details about message structure and flow in the RealTick EMS.

Finally, the document <b>CompilingRealTickApiApplications ("Compiling RealTick Api Applications")</b> gives platform-specific instructions for linking and executing API applications on both Windows and Linux.

The examples in this document refer to example files like "LiveQuoteExample.cpp".  These example files are installed under the API's "SampleCode" folder.  They are all part of the single <b>QuickStart</b> application, which is provided in both precompiled and source code form for exploring the capabilities of the API.

<hr />
## Connecting

In order to connect to a particular Service/Topic, instantiate an instance of the class RTClientAdapter.  The desired Service and Topic names are passed to the constructor, and then you begin connection by calling Connect().

Normally you will create a class that inherits from RTClientAdapter.  Override the virtual methods of the class with code that processes the corresponding data and notifications.

If the connection is lost, the virtual OnTerminate() method will be called.

To close the connection when you are done, destruct the RTClientAdapter object.

For an example, please see the class LQ in the example file "LivequoteExample.cpp".

<pre>
	RTClientAdaptor rt( nullptr, nullptr, nullptr, "TA_SRV", "LIVEQUOTE");
	rt.Connect();
</pre>

For order entry, use the service "ACCOUNT_GATEWAY" and the topic "ORDERS":
<pre>
	RTClientAdaptor rtEms( nullptr, nullptr, nullptr, "ACCOUNT_GATEWAY", "ORDERS");
	rtEms.Connect();
</pre>


<hr />
## Request and Advise Data

To request or advise on a data item, use the Request() and Advise() methods of your RTClientAdaptor object.

Returned Ack/Nack messages will result in calls to the virtual OnOtherAck method.

Returned data will result in calls to the virtual OnResponse or OnUpdate methods.  OnResponse receives request data, while OnUpdate receives advise data.  Here are sample requests for IBM level-1 data and a current order book:

<pre>
	rt.Request( "LIVEQUOTE;*;1003='IBM'", "TAL4", false);
	rtEms.Request( "ORDERS;*;", "TAL4", false);
</pre>


<hr />
## Reading Data

Data is received in the virtual OnUpdate and OnResponse methods as a (void *).  To parse and process the data, use the RTDataReader class.  This class lets you iterate through the rows and colums of the returned data block.

For an example, please see the example file "TqlRequestExample.cpp" and the functions at the top fo the file "ApiRecords.cpp".

<pre>
	virtual void OnResponse(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength, bool bLastPage) 
	{
		cout << "OnResponse " << szItem << " " << dwLength << " bytes" << endl;
		RTDataReader rd( pData );
		for( int i=0; i&lt;rd.NumRecords(); i++, rd.NextRecord() )
		{
			for( int j=0; j&lt;rd.NumFields(); j++, rd.NextField() )
			{
				UINT id, type;
				if( rd.ReadField( id, type ) )
				{
					cout << "   Field ID " << id << ", Field Type " << type << endl;
					switch( type )
					{
					case TYPE_STRING:
						{
							const char* sz;
							if( rd.ReadString( sz ) )
								cout << "      String Value: " << sz << endl;
						}
						break;
					// etc for othe types
					}
				}
			}
		}
	}
</pre>


<hr />
## Timely Data Processing

The methods OnUpdate and OnResponse are called directly by the API worker threads that process the network queue.  Therefore it is vital that these methods complete quickly and return control the the API.  If these methods run slowly or deadlock, then incoming messages will be delayed or lost.

Applications that perform intensive calculations on incoming data or update a GUI will frequenly need to cache incoming data in worker queue or other data structure and allow an application thread to calculate in the background.


<hr />
## Using the Helper Classes

For common data tables like LIVEQUOTE and ORDERS, there are helper classes that map the data FIDs to named members.  These classes are defined in the files "ApiHelpers.h" and "ApiHelpers.cpp".  

Each class is constructed with an RTDataReader.  It reads the current row of data.

For an example, please see the example file "LivequoteExample.cpp".


<pre>
	virtual void OnResponse(const char* szItem, const char* szFormat, const void* pData, uint32_t dwLength, bool bLastPage) 
	{
		cout << "OnResponse " << szItem << " " << dwLength << " bytes" << endl;
		RTDataReader rd( pData );
		for( int i=0; i&lt;rd.NumRecords(); i++, rd.NextRecord() )
		{
			LivequoteRecord rec(rd);

			if( rec.HasDispName() )
			{			
				cout << "      Symbol: " << rec.DispName() << endl;
			}
		}
	}

</pre>



<hr />
## Sending and Receiving Order Data

When sending orders, changes, and cancels, POKE a message using the TQL item "ORDERS;*;"

<pre>
	rtEms.Poke( "ORDERS;*;", "TAL4", rt.GetData(), rt.GetDataLen() );
</pre>

In order to receive order updates, fills, kills, accepts, rejects, and other order events, use the same TQL item.  Use a REQUEST to retrieve your current order book, and an ADVISE to register for any subsequent updates:

<pre>
	rtEms.Request( "ORDERS;*;", "TAL4", false);
	rtEms.Advise( "ORDERS;*;", "TAL4");
</pre>

For examples of submitting, canceling, and changing orders, please see the QuickStart example files "SubmitThenFillExample", "SubmitThenCancelExample", and "SubmitThenChangeThenCancelExample".


