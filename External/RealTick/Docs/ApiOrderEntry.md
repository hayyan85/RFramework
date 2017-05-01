<small>
© 2012 RealTick LLC All rights reserved.

<em>Use of the RealTick API®, including, but not limited to, all code and
documentation, is subject to the RealTick API® terms and conditions which are
posted on www.realtick.com.  The code contained herein is deemed to be part of
the "Licensed Product" as referred to in the end user license agreements
between the user and RealTick.</em>
</small>

<hr />
#Order Entry with RealTick APIs

<hr />
## Introduction

This document describes the data messages sent and received while interacting with the RealTick EMS. This information is applicable to order entry with any of the RealTick APIs.

All messages are transmitted using the following TQL parameters:

 - Service: ACCOUNT\_GATEWAY
 - Topic: ORDER
 - Table: ORDERS

When *sending* an order entry command to RealTick, always use the following TQL item:
<pre>
   ORDERS;*;
</pre>

When *advising* for updates on order flow, use the same item:
<pre>
   ORDERS;*;
</pre>


When *requesting* the current order book, you may use the same item to request the day's entire book, or you may parameterize the request by account, order status, or both:
<pre>
	ORDERS;*;
	ORDERS;*;20001='BANK',20003='BRANCH',20008='CUST',20052='ACCT'
	ORDERS;*;20683={'LIVE','PENDING'}
	ORDERS;*;20001='BANK',20003='BRANCH',20008='CUST',20052='ACCT',20683={'LIVE','PENDING'}
</pre>

All order messages are transmitted as TAL4 blocks.  Separate documentation on the .NET and C++ APIs describe how to read and write these blocks.  The remainder of this document describes these blocks without reference to a specific API.  

We use the following notation to represent message flow:
<pre>
	-> (a message you send to RealTick)
		<- (a message RealTick sends to you)
</pre>

Within each message we use capitalized names like TYPE and GOOD\_UNTIL to refer to individual fields.  These names correspond to field names in the C# 'FieldInformation' class and to FIDS defined for C++ in the FIDS.H header file.

<hr />
## Understanding Basic Order Flow

Every message sent (POKED) to or received (as ADVISE or REQUEST data) from the ORDERS table contains the field TYPE, which indicates the kind of message.  Typical values for TYPE are:

<pre>
	UserSubmitOrder
	UserSubmitCancel
	ExchangeAcceptOrder
	etc.
</pre>

### - Submit, Accept, and Fill

When you submit an order, use the field CLIENT\_ORDER\_ID to supply a unique identifier of your own.  The server will respond with a copy of the same message, filling in additional fields such as the ORDER\_ID:

<pre>
	-> UserSubmitOrder (CLIENT_ORDER_ID="A")
			<- UserSubmitOrder (CLIENT_ORDER_ID="A", ORDER_ID="001", CURRENT_STATUS="PENDING")
</pre>

When your order is forwarded to the exchange, you will see an accept or reject message, and the state of your order will also be updated.  Every message that references your order will contain your order's ORDER\_ID in the field ORIGINAL
_ORDER\_ID.   

<pre>
		<- ExchangeAcceptOrder (ORIGINAL_ORDER_ID="001")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="LIVE")

or

		<- ClerkReject (ORIGINAL_ORDER_ID="001")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="DELETED")

</pre>

When your order fills, you will see a fill message, plus an update:

<pre>
		<- ExchangeTradeOrder (ORIGINAL_ORDER_ID="001")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="COMPLETED")
</pre>

### - Cancel and Kill

If you want to cancel your order, send a cancel message with the REFERS\_TO\_ID referencing your order:


<pre>
	-> UserSubmitCancel (REFERS_TO_ID="001")
		<- UserSubmitCancel (ORIGINAL_ORDER_ID="001")
</pre>


When your order is killed, whether spontaneously or in response to a cancel, you will get a kill message and an update:

<pre>
		<- ExchangeKillOrder (ORIGINAL_ORDER_ID="001")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="DELETED")
</pre>


### - Change

If you want to change (i.e. cancel/replace) your order, send a change message with the REFERS\_TO\_ID referencing your order:


<pre>
	-> UserSubmitChange (REFERS_TO_ID="001")
		<- UserSubmitChange (ORDER_ID="001-2", ORIGINAL_ORDER_ID="001", CURRENT_STATUS=PENDING)
</pre>


Your change will either succeed or fail:

<pre>
		<- UserSubmitChange( ORDER_ID="001-2", CURRENT_STATUS="COMPLETED")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="LIVE")

or perhaps:

		<- UserSubmitChange( ORDER_ID="001-2", CURRENT_STATUS="DELETED", REASON="Too late to cancel")
		<- UserSubmitOrder (ORDER_ID="001", CURRENT_STATUS="COMPLETED")

</pre>

<hr />
## Required Order Fields

The following code, from "SubmitThenFillExample" shows the minimum required set of fields to send a market order:

<pre>
		// generate a unique order tag to identify this order
		std::ostringstream tag;
		tag << "example-" << time(0) << "-" << rand();
		OrderTag = tag.str();

		// supply the minimum required set of fields for a market order
		RTDataWriter rt;
		rt.NewRecord();
		rt.AddString(T_BANK, Bank.c_str());
		rt.AddString(T_BRANCH, Branch.c_str());
		rt.AddString(T_CUSTOMER, Customer.c_str());
		rt.AddString(T_DEPOSIT, Deposit.c_str());
		rt.AddString(T_BUYORSELL, "BUY");
		rt.AddString(T_GOOD_UNTIL, "DAY");
		rt.AddString(T_EXIT_VEHICLE, Route.c_str());

		rt.AddString(T_DISP_NAME, Symbol.c_str());
		rt.AddLong(T_STYP, 1);
		rt.AddString(T_EXCHANGE, "NAS");

		rt.AddString(T_PRICE_TYPE, "Market");
		rt.AddString(T_VOLUME_TYPE, "AsEntered");
		rt.AddLong(T_VOLUME, 100);
		rt.AddString(T_CLIENT_ORDER_ID, OrderTag.c_str());
		rt.AddString(T_TYPE, "UserSubmitOrder");

		// send the order
		Poke( "ORDERS;*;", "TAL4", rt.GetData(), rt.GetDataLen() );
</pre>

These fields are:

<pre>
	BANK, BRANCH, CUSTOMER, DEPOSIT				account information
	DISP_NAME, STYP, EXCHANGE					symbol information
	PRICE_TYPE									"Limit" or "Market"
	PRICE										price (required for limit orders)
	VOLUME_TYPE									"AsEntered"
	VOLUME										order volume
	CLIENT_ORDER_ID									your ID -- must be unique
	TYPE										"UserSubmitOrder"
	BUYORSELL									"Buy", "Sell", or "SellShort"
	GOOD_UNTIL									"DAY" or "YYMMDDHHMMSS"
	EXIT_VEHICLE								route name

</pre>


<hr />
## Order Field Values

This section describes the legal values for various order fields

### - BUYORSELL Values

<pre>
	Buy
	Sell
	SellShort
</pre>

### - PRICE_TYPE Values

<pre>
	AsEntered			Limit order
	Limit				Same as AsEntered
	Market				Market Order
	Stop				Stop order, requires STOP_PRICE
	StopLimit			Stop Limit Order, requires STOP_PRICE and PRICE
	TrailingStop
	TrailingStopLimit
</pre>

### - VOLUME_TYPE Values

<pre>
	AsEntered			Regular order
	AON					All or Nothing
</pre>

### - STYP Values

<pre>
                        /*  1 = Stock              */
                        /*  2 = Stock Option       */
                        /*  3 = Future             */
                        /*  4 = Future Option      */
                        /*  5 = Spot               */
                        /*  6 = Warrant            */
                        /*  7 = Corp. Bond         */
                        /*  8 = Mutual Fund        */
                        /*  9 = Gov't Bond         */
                        /* 10 = Index              */
                        /* 11 = Muni Bond          */
                        /* 12 = News               */
                        /* 13 = Unused             */
                        /* 14 = Statistics         */
                        /* 15 = Money Mkt Fund     */
                        /* 16 = Unspecified Bond   */
                        /* 17 = Unspecified Fund   */
                        /* 18 = Miscellaneous      */
                        /* 19 = SingleStock Future */
                        /* 20 = Forex              */
                        /* 21 = Synthetic          */
                        /* 22 = Chain */
</pre>

### - GOOD_UNTIL Values

<pre>
	DAY					day order
	DAYPLUS				extended day order
	GTC					good until cancel order
	IOC					immediate or cancel order
	YYYYMMDD			good until specific date
	+HH:MM:SS			good for specified time interval
</pre>


<hr />
## Understanding Staged Orders

To create a ticket, submit an order with the special TYPE value "UserSubmitStagedOrder":

<pre>
	-> UserSubmitStagedOrder (CLIENT_ORDER_ID="TKT_A")
			<- UserSubmitStagedOrder (CLIENT_ORDER_ID="TKT_A", ORDER_ID="001", CURRENT_STATUS="LIVE")
</pre>

To submit a child order against the ticket, submit a regular order with the TICKET\_ID field populated:

<pre>
	-> UserSubmitOrder (CLIENT_ORDER_ID="CHILD_B", TICKET_ID="001")
			<- UserSubmitOrder (CLIENT_ORDER_ID="CHILD_B", ORDER_ID="002", CURRENT_STATUS="PENDING")
</pre>

When the child order fills, you will see fills on both the ticket and the child:

<pre>
			<- ExchangeTradeOrder (ORDER_ID="002", VOLUME=100)
			<- ExchangeTradeOrder (ORDER_ID="001", VOLUME=100)
</pre>

You can submit cancel and change messages against both the ticket and the child following the instructions above.

<hr />
## Understanding Compound Orders

Compound orders are composed of multiple legs that execute in concert.  Examples would be list orders, spreads, and pairs.

Routes that support compound orders have very specific requirements for field values, and submitting these orders will generally require you to work with Transition Support or Api Support to determine the details for your application.

In general, a compound order is composed of a "UserSubmitCompoundOrder" message, together with one or more regular "UserSubmitOrder" messages.  These messages are sent to RealTick in a *single* TAL4 block with multiple rows:

<pre>
	->  [
			UserSubmitCompoundOrder (CLIENT_ORDER_ID="A", DISP_NAME="SPREAD", LINKED_ORDER_RELATIONSHIP=9, LINKED_ORDER_CANCELLATION=2)
			UserSubmitOrder (CLIENT_ORDER_ID="B", DISP_NAME="IBM", BUYORSELL="Buy", LINKED_ORDER_RELATIONSHIP=9, LINKED_ORDER_CANCELLATION=2)
			UserSubmitOrder (CLIENT_ORDER_ID="C", DISP_NAME="INTC", BUYORSELL="Sell", LINKED_ORDER_RELATIONSHIP=9, LINKED_ORDER_CANCELLATION=2)
        ]
</pre>

It is also possible to submit a staged compound order, in which case the legs contain "UserSubmitStagedOrder" messages intead of "UserSubmitOrder":
<pre>
	->  [
			UserSubmitCompoundOrder (CLIENT_ORDER_ID="A", DISP_NAME="SPREAD", LINKED_ORDER_RELATIONSHIP=13, LINKED_ORDER_CANCELLATION=2)
			UserSubmitStagedOrder (CLIENT_ORDER_ID="B", DISP_NAME="IBM", BUYORSELL="Buy", LINKED_ORDER_RELATIONSHIP=9, LINKED_ORDER_CANCELLATION=2)
			UserSubmitStagedOrder (CLIENT_ORDER_ID="C", DISP_NAME="INTC", BUYORSELL="Sell", LINKED_ORDER_RELATIONSHIP=9, LINKED_ORDER_CANCELLATION=2)
        ]
</pre>


Within each row of the block, the fields LINKED\_ORDER\_RELATIONSHIP and LINKED\_ORDER\_CANCELLATION hold values appropriate to the route.  Some commonly used values are:

<pre>
	LINKED_ORDER_RELATIONSHIP:
									0	OCO
									1	OSO
									2	SPREAD
									4	BASKET
									9	PAIR
									12	LIST
									13	TICKET LIST				
									14	TICKET SPREAD
									15	BRACKET
									17	DARKWHEEL

	LINKED_ORDER_CANCELLATION:
									1							ATOMIC
									2							ALL_OR_NONE
									3							AUTONOMOUS_STATE

</pre>


When the server responds, it will update each part of the order individually, not in a solid block.  As usual, each part will have a unique ORDER\_ID, and it will copy the CLIENT\_ORDER\_ID supplied in the initial entry.  Each leg will also populate the field LINKED\_ORDER\_ID to indicate the ID of the parent UserSubmitCompoundOrder messsage:

<pre>
			<- UserSubmitCompoundOrder	(ORDER_ID="001", CLIENT_ORDER_ID="A")
			<- UserSubmitOrder	(ORDER_ID="002", CLIENT_ORDER_ID="B", LINKED_ORDER_ID="001")
			<- UserSubmitOrder	(ORDER_ID="003", CLIENT_ORDER_ID="C", LINKED_ORDER_ID="001")
</pre>

Fill and kills arrive as usual:

<pre>
			<- ExchangeKillOrder (ORDER_ID="003-a", ORIGINAL_ORDER_ID="003")
</pre>

When cancelling or changing a compound order, you must again submit all the parts of the order together, supplying the same required fields as in the original entry:

<pre>
		-> [
				UserSubmitChange( REFERS_TO_ID="001", ... )
				UserSubmitChange( REFERS_TO_ID="002", ... )
				UserSubmitChange( REFERS_TO_ID="003", ... )
		   ]
</pre>



<hr />
## Order Recipies

This section describes the fields that need to be set for various order types.

### - Fill or Kill Order

<pre>
	VOLUME_TYPE = AON
	GOOD_UNTIL = IOC
</pre>

### - Limit Order

<pre>
	PRICE = (limit price)
	PRICE_TYPE = AsEntered
</pre>

### - List Order

A list order is a compound order with LINKED\_ORDER\_RELATIONSHIP set to 12.  A staged list order is a compound order with LINKED\_ORDER\_RELATIONSHIP set to 13 and TYPE set to "UserSubmitStagedOrder" in the legs.

<pre>
	LINKED_ORDER_RELATIONSHIP = 12 (or 13, for staged lists)
	LINKED_ORDER_CANCELLATION = 1 (or consult support for your application)
</pre>


### - Market Order

<pre>
	PRICE = (not sent)
	PRICE_TYPE = Market
</pre>

### - Reserve Order (Hidden Order)

<pre>
	VOLUME_TYPE = Reserve
	RESERVE_SHOWSIZE = (show size)
</pre>

### - Staged Order (Ticket)

<pre>
	TYPE = UserSubmitStagedOrder	
</pre>


### - Staged Order (Child Order)

<pre>
	TYPE = UserSubmitOrder	
	TICKET_ID = (ORDER_ID from the parent UserSubmitStagedOrder)
</pre>


### - Stop Order

<pre>
	PRICE_TYPE = Stop
	STOP_PRICE = (stop price)
	PRICE = (not sent)
</pre>

### - Stop Limit Order

<pre>
	PRICE_TYPE = Stop Limit
	STOP_PRICE = (stop price)
	PRICE = (limit price)
</pre>

### - Synthetic Reserve Order (RealTick managed Hidden Order, Iceberg Order)

<pre>
	VOLUME_TYPE = SyntheticReserve
	RESERVE_SHOWSIZE = (show size)
</pre>


### - Trailing Stop Order

<pre>
	PRICE_TYPE = TrailingStop
	STOP_PRICE = (delta)
	PRICE = (not sent)
</pre>

### - Trailing Stop Limit Order

<pre>
	PRICE_TYPE = TrailingStopLimit
	STOP_PRICE = (delta)
	PRICE = (limit)
</pre>


### - Broker Algo Order

Each destination requires different fields for algo orders.  Please contact Transition Support or Api Support for assistance setting fields for your particular algo order.

### - RealTick Spread or Pair

Fields required for RealTick Strategy Server orders (using the routes RTPAIRS and RTSPREADS) are described in the RealTick Strategy Server documentation, which can be requested from Transition Support or Api Support.
