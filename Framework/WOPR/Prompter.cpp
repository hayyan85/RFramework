// © 2012 RealTick LLC All rights reserved.
// 
// Use of the RealTick API®, including, but not limited to, all code and
// documentation, is subject to the RealTick API® terms and conditions which are
// posted on www.realtick.com.  The code contained herein is deemed to be part of
// the "Licensed Product" as referred to in the end user license agreements
// between the user and RealTick.
// 
#include "Prompter.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

map<string, string> Prompter::_map;

string Prompter::Prompt( const char* text, const char* def, bool upperCase )
{
	if( _map.find(text) == _map.end() )
		_map[text] = def;

	cout << text << " [" << _map[text] << "] ? ";

	char tmp[1024];
	cin.getline(tmp, sizeof(tmp));
	if( upperCase )
	{
		for( char* p = tmp; *p; ++p )
			*p = toupper(*p);
	}

	string st(tmp);
	if (st.empty())
		st = _map[text];
	_map[text] = st;
	return st;
}



