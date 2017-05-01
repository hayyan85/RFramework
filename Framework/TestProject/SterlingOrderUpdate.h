#ifndef Sterling_Order_Update_Header
#define Sterling_Order_Update_Header

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );

//Keywords
//CAP:           Custom Attached Parameter
//Orderupdate:   XML structure from sterling order update event
//STIOrder:      Sterling STI Order Type

class StiOrderUpdate 
{
    IMPLEMENT_SET_GET_METHOD(std::string,bstrAccount);    //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string,bstrDestination);//orderupdate
	IMPLEMENT_SET_GET_METHOD(int,nOrderStatus);		      //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string,bstrSymbol);     //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string,bstrClOrderId);  //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string,bstrAction);     //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string,Side);           //orderupdate
	IMPLEMENT_SET_GET_METHOD(int,nQuantity);              //orderupdate
	IMPLEMENT_SET_GET_METHOD(int,nLvsQuantity);           //orderupdate
	IMPLEMENT_SET_GET_METHOD(std::string ,bstrLogMessage);//orderupdate
	IMPLEMENT_SET_GET_METHOD(int,LmtPrice);               //STIOrder 
	IMPLEMENT_SET_GET_METHOD(std::string,bstrUser);       //STIOrder

	IMPLEMENT_SET_GET_METHOD(int,TotalExecutedQty);  //CAP
	IMPLEMENT_SET_GET_METHOD(int,ExecutedQty);       //CAP
	IMPLEMENT_SET_GET_METHOD(std::string,symbol);    //CAP
	IMPLEMENT_SET_GET_METHOD(int,frequency);         //CAP
	IMPLEMENT_SET_GET_METHOD(int,level);             //CAP

	StiOrderUpdate()
	{
		TotalExecutedQty = 0;
		ExecutedQty = 0;
	}
};

#endif // EXECENGINE_H