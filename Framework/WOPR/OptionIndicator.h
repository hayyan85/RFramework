#ifndef Option_Indicator_Header
#define Option_Indicator_Header

#include <qdebug.h>
#include <QObject>
#include <iostream>
#include <string>
#include <map>
#include <ql/quantlib.hpp>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <boost/timer.hpp>
#include <boost/math/distributions.hpp>

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


using namespace std;
using namespace QuantLib;


namespace Framework
{
	namespace WOPR
	{
		class OptionIndicator : public QObject
		{
			Q_OBJECT 
		private:
			
			Real impliedVolProblem ( const Real & spot , const Rate & strike , const Rate & rd ,const Rate & rf ,
									 const Volatility & vol ,	const Time & tau ,	const Integer & phi ,const Real & price );


			Real blackScholesPrice ( const Real & spot, const Real & strike , const Rate & rd , const Rate & rf , const Volatility & vol ,
									 const Time & tau , const Integer & phi );

			Real Implied_Volatility_Bisection(Real spot, Real strike,Rate rd, Rate rf, Rate tau, Integer phi, Real vol);
		public:
			
			double bisectNewtonImpliedVol(	const char CallPutFlag, 	const double s0,	const double K,	const double T, 	const double r, const double optPrice,	const double lowGuess,	const double highGuess );
			
		};


		


	}//end namespace WOPR
}//end namespace Framework
#endif 