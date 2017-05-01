#ifndef Filter_Data_Header
#define Filter_Data_Header

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
	namespace NEclipse
	{
		class FilterData
		{
		    IMPLEMENT_SET_GET_METHOD(std::string,operation);
			IMPLEMENT_SET_GET_METHOD(std::string,dest_value);
		};
		
	}
}//end namespace Framework

#endif 