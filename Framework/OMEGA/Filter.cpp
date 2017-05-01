#include "Filter.h"
#include "iostream"
#include <string.h>
#include "OptionTick.pb.h"
#include "External.h"
#include "Utility.h"

void FilterCriteria::setFilterCriteria(std::string ISymbol ,std::string LSymbol,std::string l_operator,float val,std::string b_operator,BidAsk in_ , BidAsk look_)
{
	this->IncomingSymbol = ISymbol;
	this->LookUpSymbol = LSymbol;
	this->logical_operator = l_operator;
	this->binary_operator= b_operator;
	this->value = val;
	this->BAIncoming = in_;
	this->BALookup = look_;
}


void FilterCriteria::setInvertedFilterCriteria(std::string ISymbol ,std::string LSymbol,std::string l_operator,float val,std::string b_operator,BidAsk in_ , BidAsk look_)
{
	this->IncomingSymbol = LSymbol;
	this->LookUpSymbol = ISymbol;
	this->logical_operator = Invert_Comparison_Sign(l_operator);
	this->binary_operator= Invert_Binary_Operator_Sign(b_operator);
	this->value = val;
	this->BAIncoming = look_;
	this->BALookup = in_;
}


std::string FilterCriteria::Invert_Comparison_Sign(std::string sign)
{
	if(sign==">")
	{return "<";}

	else if(sign==">=")
	{return "<=";}

	if(sign=="<")
	{return ">";}

	else if(sign=="<=")
	{return ">=";}
}


std::string FilterCriteria::Invert_Binary_Operator_Sign(std::string sign)
{
	if(sign=="+")
	{
		return "-" ;
	}
	else if(sign =="-")
	{
		return "+" ;
	}
	else if(sign =="*")
	{
		return "/";
	}
	else if(sign =="/")
	{
		return "*";
	}
}


//Check which logical operator is being used
bool FilterCriteria::processBinaryOperator(float& income , float& lookup )
{
	if(binary_operator=="+")
	{
		lookup = lookup + value;
	}
	else if(binary_operator=="-")
	{
		lookup = lookup - value;
	}
	else if(binary_operator=="*")
	{
		lookup = lookup * value;
	}
	else if(binary_operator=="/")
	{
		lookup = lookup / value;
	}

	return processLogicalOperator(income,lookup) ;
}//end method


//Logical operator check
bool FilterCriteria::processLogicalOperator(float& income , float& lookup )
{
	if(logical_operator==">")
	{
		if(income > lookup) return true;
	}

	else if(logical_operator=="<")
	{
		if(income < lookup) return true;
	}

	else if(logical_operator==">=")
	{
		if(income >= lookup || cutility.FloatCompare(income,lookup)) 
		{
				return true;
		}
	}

	else if(logical_operator=="<=")
	{
		if(income <= lookup || cutility.FloatCompare(income,lookup)) 
		{
				return true;
		}
	}

	else if(logical_operator=="=")
	{
		if(cutility.FloatCompare(income,lookup)) 
		{
				return true;
		}
	}
	
	return false;
}

//Retrieve the bid/ask value of the lookup[ symbol
float FilterCriteria::RetrieveLookUpSymbolValue(BidAsk& ba,std::string& symbol,QStandardItemModel* lookupmodel )
{
	//-----------------------------------------------------------------------------------------------------------
	/* REFERERENCE CHART ----------------------------------------------------------------------------------------
	-------------------------------------------------------------------------------------------------------------
	labels.push_back("Type");        0
	labels.push_back("Symbol");      1
	labels.push_back("BidSize");     2
	labels.push_back("Bid");         3
	labels.push_back("Last");        4
	labels.push_back("Ask");         5 
	labels.push_back("Ask Size");    6
	//-----------------------------------------------------------------------------------------------------------*/

	QList<QStandardItem*> lst = lookupmodel->findItems(symbol.c_str(),Qt::MatchExactly,1);
	if(lst.size() > 0)
	{
		int row = lst[0]->row();

        //Make sure a value has come in
		if(lookupmodel->item(row,3)->text()=="--")
			return -99;

		//Check if its a bid or an ask
		if(ba==BidAsk::Bid)
		{
			//its a bid
			return lookupmodel->item(row,3)->text().toFloat() + RoundNo;
		}
		else if (ba==BidAsk::Ask)
		{
			//its an ask
			return lookupmodel->item(row,5)->text().toFloat() + RoundNo;
		}

		else if (ba==BidAsk::BidSize)
		{
			//its an ask
			return lookupmodel->item(row,2)->text().toFloat() + RoundNo;
		}
		else if (ba==BidAsk::AskSize)
		{
			//its an ask
			return lookupmodel->item(row,6)->text().toFloat() + RoundNo;
		}
	}
}//End Method


void FilterCriteria::RetrieveIncomingSymbolValue(float& BAFloatIncoming,Serializable::OptionTick_ser& opt)
{
	if(BAIncoming==FilterCriteria::Ask)
	{
		BAFloatIncoming = opt.ask();
	}
	else if(BAIncoming==FilterCriteria::Bid)
	{
		BAFloatIncoming = opt.bid();
	}
	else if(BAIncoming==FilterCriteria::BidSize)
	{
		BAFloatIncoming = opt.bidsize();
	}
	else if(BAIncoming==FilterCriteria::AskSize)
	{
		BAFloatIncoming = opt.asksize();
	}
}//End method

//Returns if the filter conditional expression  is satisfied. 
bool FilterCriteria::ConditionSatisfied(Serializable::OptionTick_ser& opt,QStandardItemModel* lookupmodel)
{
	//Check if the incoming symbol is same
	if(IncomingSymbol==opt.symbol())
	{
		//Fill up the details of incoming symbol
		RetrieveIncomingSymbolValue(BAFloatIncoming,opt);


		//Fill up details of look up symbol
		BAFloatLookup = RetrieveLookUpSymbolValue(BALookup,LookUpSymbol,lookupmodel);


		if(BAFloatLookup == -99)
        return false;

		return processBinaryOperator(BAFloatIncoming,BAFloatLookup);
	}
	return false;
}