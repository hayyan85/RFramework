#ifndef LastVolatility_Header
#define LastVolatility_Header

#include <iostream>

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


namespace Framework
{
	namespace WOPR
	{
		class LastVolatility
		{
			IMPLEMENT_SET_GET_METHOD(float,bid);
			IMPLEMENT_SET_GET_METHOD(float,ask);
			IMPLEMENT_SET_GET_METHOD(float,bid_iv);
			IMPLEMENT_SET_GET_METHOD(float,ask_iv);
			IMPLEMENT_SET_GET_METHOD(float,mp_iv);
			
		};

	}//end namespace WOPR
}//end namespace Framework
#endif 