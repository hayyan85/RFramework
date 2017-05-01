#ifndef OPTIONSCANNER_LAYOUT_H
#define OPTIONSCANNER_LAYOUT_H

#include <iostream>
#include <string>
#include <vector>

/*Boost Serialization*/
#include <sstream>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include "QByteArray"

class OptionScannerLayout
{
public:
	//Save the filters
	void SaveExpressionFilterMap(std::map<int,std::string> Fmp)
	{
		FilterString = Fmp;
	}
	std::map<int,std::string> RetrieveExpressionFilterMap()
	{
		return FilterString;
	}

	//Save the columns to hide
	void SaveColumnToHideVector(std::vector<int> Fmp)
	{
		ColumnsToHide = Fmp;
	}

	std::vector<int> RetrieveColumnToHideVector()
	{
		return ColumnsToHide;
	}

	void SaveHeaderView(std::string headerview_string)
	{
		HeaderView = headerview_string;
	}

	std::string ReturnHeaderViewString()
	{
		return HeaderView;
	}

private: 
	std::map<int,std::string> FilterString;
	std::vector<int> ColumnsToHide;
	std::string HeaderView;
	
	friend class boost::serialization::access; 
	template <typename Archive> 
	void serialize(Archive &ar, const unsigned int version) 
	{ 
		ar & FilterString;
		ar & ColumnsToHide;
		ar & HeaderView;
	} 
};
#endif