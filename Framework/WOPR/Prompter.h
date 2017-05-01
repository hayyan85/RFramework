// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include <string>
#include <map>

class Prompter
{
public:
	static std::string Prompt( const char* text, const char* def, bool upperCase=false );

private:
	static std::map<std::string, std::string> _map;
};
