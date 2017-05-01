#include "OptionIndicator.h"
#include <ql/quantlib.hpp>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <boost/timer.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include "ImpliedVol.H"


using namespace std;
using namespace QuantLib;



namespace Framework
{
	namespace WOPR
	{
		
		Real OptionIndicator::impliedVolProblem ( const Real & spot , const Rate & strike , const Rate & rd ,const Rate & rf ,
												  const Volatility & vol ,	const Time & tau ,	const Integer & phi ,const Real & price )
		{
			return blackScholesPrice ( spot , strike , rd , rf , vol , tau , phi ) - price ;
		}


		Real OptionIndicator::blackScholesPrice( const Real & spot, const Real & strike , const Rate & rd , const Rate & rf , const Volatility & vol , const Time & tau , const Integer & phi )
		{
			boost :: math :: normal_distribution <> d (0.0 ,1.0);
			Real dp ,dm , fwd , stdDev , res , domDf , forDf ;
			domDf = std :: exp (- rd * tau ); forDf = std :: exp ( - rf * tau );
			fwd = spot * forDf / domDf ;
			stdDev = vol * std :: sqrt ( tau );
			dp =( std :: log ( fwd / strike )+0.5* stdDev * stdDev )/ stdDev ;
			dm =( std :: log ( fwd / strike ) -0.5* stdDev * stdDev )/ stdDev ;
			res = phi * domDf *( fwd * cdf (d , phi * dp )- strike * cdf (d , phi * dm ));
			return res ;
		}


		Real OptionIndicator::Implied_Volatility_Bisection(Real spot, Real strike,Rate rd, Rate rf, Rate tau, Integer phi, Real vol)
		{
			// calculate corresponding Black Scholes price
			Real price = blackScholesPrice ( spot , strike ,rd ,rf , vol , tau , phi );
			// setup a solver
			Bisection mySolv1 ; Brent mySolv2 ; Ridder mySolv3 ;
			Real accuracy =0.00001 , guess =0.25;
			Real min =0.0 , max =1.0;
			
			// setup a boost function
			boost :: function < Real ( Volatility )> myVolFunc ;
			
			// bind the boost function to all market parameters , keep vol as variant
			myVolFunc = boost::bind(&OptionIndicator::impliedVolProblem ,this, spot , strike ,rd ,rf ,_1 , tau , phi , price );
			// solve the problem
			Real res1 = mySolv1.solve ( myVolFunc , accuracy , guess , min , max );
			return res1;
			//return 2.22;
		}

		double OptionIndicator::bisectNewtonImpliedVol( const char CallPutFlag, const double s0, const double K, const double T, const double r, const double optPrice, const double lowGuess, const double highGuess )
		{
			return ::bisectionNewtonImpliedVol(CallPutFlag,s0,K,T,r,optPrice,lowGuess,highGuess);
		}
	}//end namespace WOPR
}//end namespace Framework