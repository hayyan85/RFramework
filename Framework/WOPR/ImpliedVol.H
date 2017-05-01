#ifndef LOCAL_IMPLIEDVOL_H
#define LOCAL_IMPLIEDVOL_H

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

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include "util.H"
#include "blackScholes.H"

/*
 * This class just wraps the black_scholes() function. We can store the state
 * of a particular set of values we wish to determine the implied volatilty
 * for and then plug in volatilities using the () operator.
 */
class black_scholes_functor
{
	public:
		black_scholes_functor( const char &cpFlag,
				       const double &s0,
				       const double &K,
				       const double &T,
				       const double &r )
			: _cpFlag( cpFlag ), _s0( s0 ), _K( K ), _T( T ), _r( r )
		{
		}

		double operator ()( double sigma )
		{
			return black_scholes( _cpFlag, _s0, _K, _T, _r, sigma ) ;
		}

		double operator ()( double sigma, const std::string &greek )
		{
			if ( greek.compare( "vega" ) )
			{
				return black_scholes_vega( _s0, _K, _T, _r, sigma ) ;
			}
			else
			{
				return 0.0 ;
			}
		}
	private:
		char   _cpFlag ;
		double _s0,
		       _K,
		       _T,
		       _r ;
} ;

/*
 * This class wraps the black_scholes_functor class. Since I am using a root
 * finding method to determine the implied volatility I need the x intercept
 * be the implied volatility. I accomplish this by subtracting the given
 * option price. I can then pass this functor into a root finding method.
 */
class black_scholes_implVol_finder_functor
{
	public:
		black_scholes_implVol_finder_functor( const black_scholes_functor &bsf, const double &optPrice )
			: _bsf( bsf ), _optPrice( optPrice )
		{
		}

		double operator ()( double sigma )
		{
			return _optPrice - _bsf( sigma ) ;
		}

		double operator ()( double sigma, const std::string &greek )
		{
			return _bsf( sigma, greek ) ;
		}

	private:
		black_scholes_functor _bsf ;
		double _optPrice ;
} ;

double bisectionNewtonImpliedVol(	const char CallPutFlag,
	const double s0,
	const double K,
	const double T,
	const double r,
	const double optPrice,
	const double lowGuess,
	const double highGuess )
{
	if(optPrice==0)
	{
		return 0.0;
	}

	black_scholes_functor bsf =		black_scholes_functor( CallPutFlag, s0, K, T, r ) ;
	black_scholes_implVol_finder_functor bsiff =black_scholes_implVol_finder_functor( bsf, optPrice ) ;
	double	midPoint	= 0.5 * ( lowGuess + highGuess ),
		midDiff		= bsiff( midPoint ),
		midVega		= bsiff( midPoint, "vega" ),
		dx		= ( highGuess - lowGuess ),
		dxPrev		= dx,
		tempLowGuess	= lowGuess,
		temHighGuess	= highGuess,
		temp ;

	for ( int i = 1; i < MAXITERATION; ++i )
	{
		if (  ( (( midPoint - temHighGuess ) * midVega - midDiff) * (( midPoint - tempLowGuess ) * midVega - midDiff) > 0 ) ||
			( fabs( 2 * midDiff ) > fabs( dxPrev * midVega) ) )
		{
			dxPrev		= dx ;
			dx		= 0.5 * ( temHighGuess - tempLowGuess ) ;
			midPoint	= tempLowGuess + dxPrev ;
		}
		else
		{
			dxPrev          = dx ;
			dx		= midDiff / midVega ;
			temp		= midPoint ;
			midPoint	= midPoint - dx ;
		}

		midDiff = bsiff( midPoint ) ;

		if ( fabs( midDiff ) < EPS )
		{
			break ;
		}

		midVega = bsiff( midPoint, "vega" ) ;

		if ( midDiff < 0.0 )
		{
			temHighGuess = midPoint ;
		}
		else
		{
			tempLowGuess = midPoint ;
		}
	}

	if(midPoint<1)
	{
		std::string b = "break";
	}
	return midPoint ;
}

#endif
