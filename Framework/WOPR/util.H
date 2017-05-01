#ifndef LOCAL_UTIL_H
#define LOCAL_UTIL_H

/*
 *	Author:	Shafik Yaghmour
 *
 *	General routines and constants for Financial Engineering/Options Pricing/Numerical Methods.
 *
 *	You are free to use this code but you should give credit to the author(s).
 */

/*
 * This code and other related code can be found at:
 *
 *	http://shafik.net/~shafik/FinancialEngineering/Code/
 *
 */

#include <ctime>
#include <cmath>
//#include <unistd.h>
#include <process.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

const double		E  = 2.718281828459045235360287471352662498 ;
const long double	PI = 3.1415926535897932384626433832795028841968 ;
const double		EPS = std::numeric_limits<double>::epsilon() ;

void initRand()
{
	//srand( time( NULL ) + getpid() ) ;
	srand( time( NULL ) + _getpid() ) ;
}

/*
 * Generate a random number over [0, 1)
 */
double randomUniform_0_1( void )
{
	return double( rand() ) / double( RAND_MAX ) ;
}

/*
 * Box-Muller method for generating random normal deviates.
 *
 * Numerical Recipies, 2nd edition, pg 288-290
 */
double normalSample()
{
	static int iset = 0;
	static double set ;
	double fac,
	       rsq,
	       v1,
	       v2 ;

	if ( iset == 0 )
	{
		do
		{
			v1 = 2.0 * randomUniform_0_1() - 1.0 ;
			v2 = 2.0 * randomUniform_0_1() - 1.0 ;
			rsq = ( v1 * v1 ) + ( v2 * v2 ) ;
		} while( rsq >= 1.0 || rsq == 0.0 ) ;

		fac = sqrt( -2.0 * log( rsq ) / rsq ) ;
		set = v1 * fac ;
		iset = 1 ;

		return v2 * fac ;
	}
	else
	{
		iset = 0 ;
		return set ;
	}
}

template <class T>
void SWAP( T &x1, T &x2 )
{
	T tmp = x1 ;
	x1 = x2 ;
	x2 = tmp ;
}

template <class T>
T SIGN( const T &a, const T &b )
{
	T
		sign = ( b < 0 ) ? -1 : 1 ;

	return a * sign ;
}

template <class T>
T MIN( const T &a, const T &b )
{
	return ( a <= b ) ? a : b ;
}

/*
 * Extension of std::runtime_error to cover bad conversions.
 */
class BadConversion : public std::runtime_error
{
	public:
		BadConversion( const std::string &str ) :
			std::runtime_error(str)
		{}
} ;

/*
 * Generic routine to convert a string to a generic type T.
 *
 *	throws BadConversion() exception if conversation fails
 *
 * reference:
 *	http://www.cplusplus.com/reference/iostream/istream/operator%3E%3E.html
 */
template <typename T>
inline void convert( const std::string &str, T &x )
{
	std::istringstream i(str) ;

	if ( !(i >> x) )
	{
		throw BadConversion( str ) ;
	}
}

/*
 * This functions solves the equation (a^2 + b^2)^(1/2)
 *
 * Reference:
 *
 *	Numerical Recipies, 3nd edition,
 *		http://www.nr.com/webnotes?2
 */
double pythagorasSolveForC( const double a, const double b )
{
	double
		absA = fabs(a),
		absB = fabs(b),
		c ;

	c = ( absA > absB ?
		absA * sqrt( 1.0 + (absB/absA) * (absB/absA) ) :
		( absB == 0.0 ?
		  0.0 :
		  absB * sqrt( 1.0 + (absA/absB) * (absA/absB) ) ) ) ;

	return c ;
}
#endif
