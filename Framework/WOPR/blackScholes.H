#ifndef BLACHSCHOLES_H
#define BLACHSCHOLES_H

/*
 * Copyright (c) 2008, Shafik Yaghmour
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Shafik Yaghmour nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Shafik Yaghmour ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Shafik Yaghmour BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This code and other related code can be found at:
 *
 *	http://shafik.net/~shafik/FinancialEngineering/Code/
 *
 */

#include "util.H"
/*
 * Constants
 */
const double MAXITERATION = 500 ;

/*
 * This function will the pdf for a standard normal variable.
 */
double gaussianPDF( double x )
{
	return exp( ((-x) * (-x)) * 0.5 ) / sqrt( 2 * PI ) ;
}

/*
 * This function computes the cumulative normal distribution.
 */
double CND( double x1 )
{
	/*
	 * pg. 297, Hull 6th ed.
	 */
	double gamma	= 0.2316419 ;

	double a1	= 0.319381530 ;
	double a2	= -0.356563782 ;
	double a3	= 1.781477937 ;
	double a4	= -1.821255978 ;
	double a5	= 1.330274429 ;

	double x = fabs(x1) ;

	double k	= 1.0 / ( 1.0 + gamma * x ) ;
	double Nprime   = (1.0 / sqrt( 2.0 * PI ) ) *
				exp( -x * x / 2 ) ;

	//printf( "%f\n", k ) ;
//	printf( "%f\n", (1.0 / sqrt( 2.0 * PI ) ) ) ;
//	printf( "%f\n",  -x * x / 2 );
//	printf( "%f\n", exp( -x * x / 2 ) );
//	printf( "%f\n", Nprime ) ;

	double ret ;

	if ( x1 < 0 )
	{
	ret = 1.0 -( 1.0 -
		( Nprime *
		  ( ( a1 * k ) +
		    ( a2 * pow( k, 2.0) )  +
		    ( a3 * pow( k, 3.0 ) ) +
		    ( a4 * pow( k, 4.0 ) ) +
		    ( a5 * pow( k, 5.0 ) ) ) ) ) ;
	}
	else
	{
	ret = ( 1.0 -
		( Nprime *
		  ( ( a1 * k ) +
		    ( a2 * pow( k, 2.0) )  +
		    ( a3 * pow( k, 3.0 ) ) +
		    ( a4 * pow( k, 4.0 ) ) +
		    ( a5 * pow( k, 5.0 ) ) ) ) ) ;
	}

//	printf( "%f\n", ret ) ;
	//std::cout << "CND: " << ret << std::endl ;

	return ret ;
}

/*
 * This function calculates the black scholes equation.
 */
double black_scholes( char CallPutFlag, double s0, double K, double T, double r, double sigma )
{
	/*
	 * pg. 295, Hull 6th ed.
	 */
	double d1 = ( log( s0 / K ) + ( ( r + ( sigma * sigma ) ) / 2 )* T ) / ( sigma * sqrt( T ) ) ;
	double d2 = d1 - ( sigma * sqrt( T ) ) ;

	//std::cout << "d1: " << d1 << " d2: " << d2 << std::endl ;

	if ( CallPutFlag == 'c' )
	{
		return s0 * CND( d1 ) - K * pow( E, -( r * T ) ) * CND( d2 ) ;
	}
	else
	{
		return  K * pow( E, -( r * T ) ) * CND( -d2 ) - ( s0 * CND( -d1 ) ) ;
	}
}

/*
 * This function calculates the delta for a black scholes option.
 */
double black_scholes_delta( char CallPutFlag, double s0, double K, double T, double r, double sigma )
{
	double d	= ( log( s0 / K ) + ( ( r + pow( sigma, 2 ) ) / 2 )* T ) / ( sigma * sqrt( T ) ) ;
	double delta ;

	if ( CallPutFlag == 'c' )
	{
		delta = CND( d ) ;
	}
	else
	{
		delta = CND( d ) - 1 ;
	}

	return delta ;
}

/*
 * This function decided whther the user should delta hedge and if so how
 * many shares are needed to hedge.
 *
 * This is pure naive delta hedging with no checks and no rounding.
 */
bool blackScholesDeltaStrategy0( char CallPutFlag,
				double s0,
				double K,
				double T,
				double r,
				double sigma,
				double OptionShort,
				double numberOfOptions,
				double numberOfSharesPerOption,
				double currentHedgePosition,
				double &changeInHedge )
{
	double
		delta   =  black_scholes_delta( 'c', s0, K, T, r, sigma ),
		sign	= OptionShort ? 1.0 : -1.0 ;

	// Should be 0 but just in case.
	if ( changeInHedge != 0.0 )
	{
		changeInHedge = 0 ;
	}

	changeInHedge = (sign * delta * numberOfSharesPerOption * numberOfOptions) - currentHedgePosition ;

	return true ;
}

/*
 * This function decided whther the user should delta hedge and if so how
 * many shares are needed to hedge.
 *
 * The strategy is a simple one, if delta falls below a threshold then it no
 * longer makes sense to hedge. The function will also round the number of
 * shares to hedge down.
 */
bool blackScholesDeltaStrategy1( char CallPutFlag,
				double s0,
				double K,
				double T,
				double r,
				double sigma,
				double OptionShort,
				double numberOfOptions,
				double numberOfSharesPerOption,
				double currentHedgePosition,
				double &changeInHedge )
{
	const double THRESHOLD = 0.01 ;
	double
		delta   =  black_scholes_delta( 'c', s0, K, T, r, sigma ),
		sign	= OptionShort ? 1.0 : -1.0 ;

	// Should be 0 but just in case.
	if ( changeInHedge != 0.0 )
	{
		changeInHedge = 0 ;
	}

	if ( delta < THRESHOLD )
	{
		return false ;
	}

	changeInHedge = (sign * delta * numberOfSharesPerOption * numberOfOptions) - currentHedgePosition ;

	/*
	 * If negative we round up otherwie round down.
	 */
	if ( changeInHedge < 0.0 )
	{
		changeInHedge = ceil( changeInHedge ) ;
	}
	else
	{
		changeInHedge = floor( changeInHedge ) ;
	}

	/*
	 * Seems redundant but it is not since we want to flag the fact that we
	 * should not hedge.
	 */
	if ( fabs(changeInHedge) < 1.0 )
	{
		changeInHedge = 0.0 ;
		return false ;
	}

	return true ;
}

/*
 * This function calculates the gamma for a black scholes option.
 */
double black_scholes_gamma( double s0, double K, double T, double r, double sigma )
{
	double d = ( log( s0 / K ) + ( ( r + pow( sigma, 2 ) ) / 2 )* T ) / ( sigma * sqrt( T ) ) ;

	return ( gaussianPDF( d ) / ( s0 * sigma * sqrt(T) ) );
}


/*
 * This function calculates the vega for a black scholes option.
 */
double black_scholes_vega( double s0, double K, double T, double r, double sigma )
{
	double d = ( log( s0 / K ) + ( ( r + pow( sigma, 2 ) ) / 2 )* T ) / ( sigma * sqrt( T ) ) ;

	return s0 * gaussianPDF( d ) * sqrt( T ) ;
}

#endif
