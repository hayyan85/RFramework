#ifndef Historical_Collection_Header
#define Historical_Collection_Header

#include <iostream>
//#include <boost/archive/text_oarchive.hpp> 
//#include <boost/archive/text_iarchive.hpp> 
#include <map>
#include "HistoricalFields.pb.h"

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


/*
THIS CLASS CONTAINS A COLLECTION OF HISTORICAL FIELDS
*/

namespace Framework
{
	namespace Common
	{
		/*
		class HistoricalCollection
		{
			
			private:
			typedef std::map<int,Serializable::HistoricalFields_ser> Ctype;
			IMPLEMENT_SET_GET_METHOD(Ctype,hfCollection);

			
			friend class boost::serialization::access; 
			template <typename Archive> 
			void serialize(Archive &ar, const unsigned int version) 
			{ 
				ar & hfCollection;
			} 
			

			public:
			void AddItem(int freq, Serializable::HistoricalFields_ser hf)
			{
				hfCollection[freq] = hf;
			}

			//Checks if the frequency is present
			bool IsFreqPresent(int freq)
			{
				Ctype::iterator it = hfCollection.find(freq);
				if(it!=hfCollection.end())
				{
					return true; //Frequency present
				}
				return false; //Frequency not present
			}

			//Return the Historical Object
			Serializable::HistoricalFields_ser Return_Historical_Object(int freq)
			{
				return hfCollection[freq];
			}
		};
		*/
	}//end namespace WOPR
}//end namespace Framework

#endif 