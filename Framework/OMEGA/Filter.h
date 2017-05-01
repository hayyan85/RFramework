#ifndef FILTER_HEADER
#define FILTER_HEADER

#include <iostream>
#include "OptionTick.pb.h"
#include "QStandardItemModel"
#include "Utility.h"


//Expression
//SymbolA-BidAskA > SymbolB-BidAskB + value
//   IBM008                IBM001221   
//Bid/AskIncoming > BidAskLookup + val

class FilterCriteria
{
public:
	enum BidAsk {Bid,Ask,BidSize,AskSize};
	std::string guid;
	std::string filterString;
	bool ConditionSatisfied(Serializable::OptionTick_ser& opt,QStandardItemModel* lookupmodel);
	void setFilterCriteria(std::string ISymbol ,std::string LSymbol,std::string l_operator,float val,std::string b_operator,BidAsk in_ , BidAsk look_);
	void setInvertedFilterCriteria(std::string ISymbol ,std::string LSymbol,std::string l_operator,float val,std::string b_operator,BidAsk in_ , BidAsk look_);

private:
	std::string IncomingSymbol;
	std::string LookUpSymbol;
	BidAsk BAIncoming;      //EnumType
	BidAsk BALookup;        //EnumType

	Framework::Utility::CommnUtility cutility;

	float BAFloatIncoming;  //could be either Bid/Ask/BidSize/AskSize Value
	float BAFloatLookup;    //could be either Bid/Ask/BidSize/AskSize Value

	std::string logical_operator;

	float value;

	std::string binary_operator;

	float RetrieveLookUpSymbolValue(BidAsk& ba,std::string& symbol,QStandardItemModel* lookupmodel );

	bool processBinaryOperator(float& income , float& lookup );

	bool processLogicalOperator(float& income , float& lookup );

	void RetrieveIncomingSymbolValue(float& BAFloatIncoming,Serializable::OptionTick_ser& opt);

	std::string Invert_Binary_Operator_Sign(std::string sign);

	std::string Invert_Comparison_Sign(std::string sign);
};

#endif