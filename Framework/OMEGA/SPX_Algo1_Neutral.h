#ifndef HEADER_SPX_AlGO1_NEUTRAL
#define HEADER_SPX_AlGO1_NEUTRAL


#include <cstdio>
#include <string>
#include "exprtk.hpp"
#include <iostream>
#include "Utility.h"
#include "math.h"

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
		IMPLEMENT_SET_METHOD( type , name );	\
		IMPLEMENT_GET_METHOD( type , name );


class SPX_ALGO1_NEUTRAL
{ 
    public:
	enum EnumAction {SendOrder,CancelOrder,NoAction};
	
	SPX_ALGO1_NEUTRAL()
	{
		send_order_condition = "(Q_Bid > highest_open_order_price)  and (tot_cxl < max_cxl or equal(tot_cxl,max_cxl)) and (current_pos < max_pos or current_pos = 0)";
		send_order_condition = "if("  + send_order_condition + ",output:=1 ,output:=-1)";
		
		cancel_order_condition = "Q_Bid < highest_open_order_price or equal(Q_Bid,highest_open_order_price)";
		cancel_order_condition = "if("  + cancel_order_condition + ",output:=1 ,output:=-1)";

		send_order_cond_A = "(( (Q_Bid  < ( Q_Ask  - .10)) or equal(Q_Bid,Q_Ask  - .10) ) and (Q_BidSize - OrdSize > OrdSize * 5)) or (	( equal(Q_Bid,Q_Ask  - .05) )and ( (Q_BidSize / Q_AskSize)  > 4)and (Q_BidSize - OrdSize > OrdSize * 5)	)";
		send_order_cond_A = "if("  + send_order_cond_A + ",output:=1 ,output:=-1)";

		send_order_cond_B = "(( (Q_Bid  < ( Q_Ask  - .15)) or equal(Q_Bid,Q_Ask  - .15) ) and (Q_BidSize - OrdSize > OrdSize * 5))	or  ((  equal(Q_Bid,Q_Ask  - .10) )	and ( ((Q_BidSize / Q_AskSize)  > 1) and (Q_BidSize - OrdSize > OrdSize * 5)))	";
		send_order_cond_B = "if("  + send_order_cond_B + ",output:=1 ,output:=-1)";

		send_order_cond_C = "(( (Q_Bid  < ( Q_Ask  - .20)) or equal(Q_Bid,Q_Ask  - .20) ) and (Q_BidSize - OrdSize > OrdSize * 3)) or (	( equal(Q_Bid,Q_Ask  - .15) ) and ( ((Q_BidSize / Q_AskSize)  > 1) and (Q_BidSize - OrdSize > OrdSize * 5))	)";
		send_order_cond_C = "if("  + send_order_cond_C + ",output:=1 ,output:=-1)";


		cancel_order_cond_A = "(( equal(Q_Bid,Q_Ask  - .10) )and	(Q_BidSize - OrdSize > OrdSize * 1))or (( equal(Q_Bid,Q_Ask  - .05) ) and ( (Q_BidSize / Q_AskSize)  < 4 or (Q_BidSize - OrdSize < OrdSize * 2.5)))";
		cancel_order_cond_A = "if("  + cancel_order_cond_A + ",output:=1 ,output:=-1)";

		cancel_order_cond_B = "(( equal(Q_Bid,Q_Ask  - .15) ) and	(Q_BidSize - OrdSize < OrdSize * 2)	)or (( equal(Q_Bid,Q_Ask  - .10) ) and	( ((Q_BidSize / Q_AskSize)  < 1) or (Q_BidSize - OrdSize < OrdSize * 3)))or	((Q_Bid > Q_Ask  - .10)  and	( ((Q_BidSize / Q_AskSize)  < 50) or (Q_BidSize - OrdSize < OrdSize * 2)))";
		cancel_order_cond_B = "if("  + cancel_order_cond_B + ",output:=1 ,output:=-1)";

		
	    cancel_order_cond_C = "(( equal(Q_Bid,Q_Ask  - .20) ) and (Q_BidSize - OrdSize < OrdSize * 3)) or(( equal(Q_Bid,Q_Ask  - .15) ) and ( ((Q_BidSize / Q_AskSize)  < 1) or (Q_BidSize - OrdSize < OrdSize * 3)))or((  equal(Q_Bid,Q_Ask  - .10) )and( ((Q_BidSize / Q_AskSize)  < 50) or (Q_BidSize - OrdSize < OrdSize * 5)))or((Q_Bid > Q_Ask  - .10))";
		cancel_order_cond_C = "if("  + cancel_order_cond_C + ",output:=1 ,output:=-1)";

		
	}
		
	void evaluate_expression()
	{
		output = 0;
		symbol_table.clear();
		symbol_table.add_variable("Q_Bid",Q_Bid);
		symbol_table.add_variable("highest_open_order_price",highest_open_order_price);
		symbol_table.add_variable("tot_cxl",tot_cxl);
		symbol_table.add_variable("max_cxl",max_cxl);
		symbol_table.add_variable("current_pos",current_pos);
		symbol_table.add_variable("max_pos",max_pos);
		symbol_table.add_variable("output",output);
		
		    expression.release();
			expression.register_symbol_table(symbol_table);
			parser.compile(send_order_condition,expression); 
			expression.value();
			
			if(output>0) 
			{
				process_send_order_conditions();
				return; //Since we cannot make the next statement an else if
			}
		 
			output = 0;OutputAction = NoAction;
			expression.release();
			expression.register_symbol_table(symbol_table);
			parser.compile(cancel_order_condition,expression); 
			expression.value();

			if(output>0) 
			{
			  process_cancel_order_conditions();
			  return;//Since we cannot make the next statement an else if
			}
		
	}//End method
	
private:

	void process_send_order_conditions()
	{
		double cnst  = 0.25;
		double cnst2 = 0.50;
		double cnst3 = 0.95;

		symbol_table.clear();
		expression.release();
		symbol_table.add_variable("Q_Bid",Q_Bid);
		symbol_table.add_variable("Q_Ask",Q_Ask);
		symbol_table.add_variable("Q_BidSize",Q_BidSize);
		symbol_table.add_variable("Q_Ask",Q_Ask);
		symbol_table.add_variable("Q_AskSize",Q_AskSize);
		symbol_table.add_variable("output",output);

		if(util.DoubleCompare(Q_Bid,cnst) || (Q_Bid < cnst))
		{
			//-----------------------------------------------------
			//Use expression send_order_cond_A
			//-----------------------------------------------------
			output = 0;OutputAction = NoAction;
			
			OrdSize = OrdSize;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);
			
			parser.compile(send_order_cond_A,expression);
			expression.value();
			if(output>0) 
			{
				OutputAction = SendOrder;
			}
		}
		else if ( Q_Bid > cnst && ((Q_Bid < cnst2) || (util.DoubleCompare(Q_Bid,cnst2))) )
		{
			//-----------------------------------------------------
			//Use expression send_order_cond_B
			//-----------------------------------------------------
			output = 0;OutputAction = NoAction;
			
			OrdSize = OrdSize / 3;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);

			parser.compile(send_order_cond_B,expression);
			expression.value();
			if(output>0)
			{ 
				OutputAction = SendOrder;
			}
		}
		else if ( Q_Bid > cnst2 && ( (Q_Bid < cnst3) || (util.DoubleCompare(Q_Bid,cnst3)) ) )
		{
			//-----------------------------------------------------
			//Use expression send_order_cond_C
			//-----------------------------------------------------
			output = 0;OutputAction = NoAction;

			OrdSize = OrdSize / 6;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);

			parser.compile(send_order_cond_C,expression);
			expression.value();
			if(output>0)
			{ 
				OutputAction = SendOrder;
			}
		}
	}//end method

	//Process Entry Condition B
	void process_cancel_order_conditions()
	{
		double cnst  = 0.25;
		double cnst2 = 0.50;
		double cnst3 = 0.95;
		symbol_table.clear();
		expression.release();
		symbol_table.add_variable("Q_Bid",Q_Bid);
		symbol_table.add_variable("Q_Ask",Q_Ask);
		symbol_table.add_variable("Q_BidSize",Q_BidSize);
		//symbol_table.add_variable("OrdSize",OrdSize);
		symbol_table.add_variable("Q_Ask",Q_Ask);
		symbol_table.add_variable("Q_AskSize",Q_AskSize);
		symbol_table.add_variable("output",output);
		//expression.register_symbol_table(symbol_table);

		if(util.DoubleCompare(Q_Bid,cnst) || (Q_Bid < cnst))
		{
			output = 0;OutputAction = NoAction;
		
			OrdSize = OrdSize;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);


			parser.compile(cancel_order_cond_A,expression); 
			expression.value();
			if(output>0) 
			{
				OutputAction = CancelOrder;
				
			}
		}
		else if(Q_Bid > cnst  && ( (Q_Bid < cnst2) || util.DoubleCompare(Q_Bid,cnst2)) )
		{
			
			output = 0;OutputAction = NoAction;
			
			OrdSize = OrdSize / 3;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);

			parser.compile(cancel_order_cond_B,expression);
			expression.value();
			if(output>0) 
			{
				OutputAction = CancelOrder;
			}
		}
		else if( Q_Bid > cnst2 && ( (Q_Bid <= cnst3) || util.DoubleCompare(Q_Bid,cnst3)) )
		{
			output = 0;OutputAction = NoAction;

			OrdSize = OrdSize / 6;
			OrdSize = ceil(OrdSize);
			symbol_table.add_variable("OrdSize",OrdSize);
			expression.register_symbol_table(symbol_table);

			parser.compile(cancel_order_cond_C,expression);
			expression.value();
			if(output>0) 
			{
				OutputAction = CancelOrder;				
			}
		}
	}//end method

	Framework::Utility::CommnUtility util;
	std::string send_order_condition;
	std::string cancel_order_condition;
	std::string send_order_cond_A; std::string cancel_order_cond_A;
	std::string send_order_cond_B; std::string cancel_order_cond_B;
	std::string send_order_cond_C; std::string cancel_order_cond_C;

	IMPLEMENT_SET_GET_METHOD(double,Q_Bid);
	IMPLEMENT_SET_GET_METHOD(double,Q_Ask);
	IMPLEMENT_SET_GET_METHOD(double,Q_BidSize);
	IMPLEMENT_SET_GET_METHOD(double,OrdSize);
	IMPLEMENT_SET_GET_METHOD(double,Q_AskSize);
	IMPLEMENT_SET_GET_METHOD(double,output);
	IMPLEMENT_SET_GET_METHOD(double,highest_open_order_price);
	IMPLEMENT_SET_GET_METHOD(double,tot_cxl);
	IMPLEMENT_SET_GET_METHOD(double,max_cxl);
	IMPLEMENT_SET_GET_METHOD(double,current_pos);
	IMPLEMENT_SET_GET_METHOD(double,max_pos);
	IMPLEMENT_SET_GET_METHOD(EnumAction,OutputAction);


	exprtk::symbol_table<double> symbol_table;
	exprtk::expression<double>   expression;
	exprtk::parser<double> parser;
};

#endif