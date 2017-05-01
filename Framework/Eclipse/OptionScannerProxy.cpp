#include "OptionScannerProxy.h"
#include "boost/spirit/include/qi.hpp"
#include <boost/algorithm/string.hpp>
#include <map>
#include "QStandardItemModel"
namespace qi = boost::spirit::qi;

namespace Framework
{
	namespace NEclipse
	{
		//Constructor
		OptionScanner_FilterProxyModel::OptionScanner_FilterProxyModel(OptionScanner* os,QObject *parent /* = 0 */):QSortFilterProxyModel(parent)
		{
			oscanner = os;
		}///End constructor

		QDate OptionScanner_FilterProxyModel::ConvertToDate(const QString& dt) const
		{
			QStringList lst =  dt.split("/");//0 = Month ; 1= day ; 2= Year
			return QDate(lst[2].toInt(),lst[0].toInt(),lst[1].toInt());
		}

		bool OptionScanner_FilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
		{
			QVariant leftData = sourceModel()->data(left);
			QVariant rightData = sourceModel()->data(right);
			//0  = Symbol
			//18 = ExpTimeLeft
			//13 = Date
			if( left.column() == 0 || left.column() == 18) 
			{
				return leftData.toString() < rightData.toString();
			}
			if( left.column() == 13 ) 
			{
				return ConvertToDate(leftData.toString()) < ConvertToDate(rightData.toString());
			}
			else
			{
				return leftData.toDouble() < rightData.toDouble();
			}
		}

		//Should this column be displayed
		bool OptionScanner_FilterProxyModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
		{
			//If in the list it should not be displayed
			if(std::find(ColumnNoToFilter.begin(),ColumnNoToFilter.end(),source_column)!=ColumnNoToFilter.end())
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		//Do not display this column
		void OptionScanner_FilterProxyModel::FilterSpecificColumn(int col_no)
		{
			ColumnNoToFilter.push_back(col_no);
		}

		//Display this column
		void OptionScanner_FilterProxyModel::UndoFilterSpecificColumn(int col_no)
		{
			ColumnNoToFilter.erase(std::remove(ColumnNoToFilter.begin(),ColumnNoToFilter.end(),col_no));
			ColumnAdded = col_no;
		}


		//-------------------------------------------------------------------------------------------
		//------------These methods aid the layout(Load/Save) Mechanism------------------------------
		//-------------------------------------------------------------------------------------------
		void OptionScanner_FilterProxyModel::SetFilterExpressionFromLayout(std::map<int,std::string> layoutMap)
		{
			m_columnPatterns = layoutMap;
		}

		std::map<int,std::string>  OptionScanner_FilterProxyModel::GetFilterExpressionCollection()
		{
			return m_columnPatterns;
		}

		void OptionScanner_FilterProxyModel::SetColumnsToHideFromLayout(std::vector<int> layoutMap)
		{
			ColumnNoToFilter = layoutMap;
		}
		std::vector<int>  OptionScanner_FilterProxyModel::GetHideCoulmnCollection()
		{
			return ColumnNoToFilter;
		}
		//-------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------

		void OptionScanner_FilterProxyModel::AddFilterToColumn(int col_no,std::string filter_string,QStandardItemModel* frmPtrModel)
		{
			m_columnPatterns[col_no] = filter_string;
		}

		void OptionScanner_FilterProxyModel::RemoveFilterFromColumn(int col_no,QStandardItemModel* frmPtrModel)
		{
			m_columnPatterns.erase(col_no);
		}


		bool OptionScanner_FilterProxyModel::ShouldRowBeDisplayed(const std::string filter_string,const std::string rx_val) const
		{
			using namespace qi;
			std::vector<std::string> filter_vect;//0 contains the column name,1 contains the operator , 2 contains the filter value , 3 contains extra value 1 , 4 contains extra value 2
			boost::spirit::qi::parse(filter_string.begin(), filter_string.end(), *~char_("_") >> *('_' >> *~char_("_")) ,filter_vect);

			bool IsFloat;
			QString(rx_val.c_str()).toFloat(&IsFloat);
			float received_val = atof(rx_val.c_str());
			float filter_threshold = atof(filter_vect[2].c_str());
			float extra_a =  atof(filter_vect[2].c_str());
			float extra_b;

			if(filter_vect.size()>3)
			{
				extra_b =  atof(filter_vect[3].c_str());
			}


			if(filter_vect[1]==">=")
			{
				if(received_val>filter_threshold || received_val==filter_threshold )
					return true;  //This means display it
			}
			if(filter_vect[1]==">")
			{
				if(received_val>filter_threshold )
					return true;
			}
			if(filter_vect[1]=="<=")
			{
				if(received_val<filter_threshold || received_val==filter_threshold )
					return true;
			}
			if(filter_vect[1]=="<")
			{
				if(received_val<filter_threshold)
					return true;
			}
			if(filter_vect[1]=="=") //This might be a string so cater to string requirements also
			{
				//if(FloatCompareOptions(received_val,filter_threshold) || filter_vect[2]==rx_val)
				if(IsFloat && FloatCompareOptions(received_val,filter_threshold))
				{
					return true;
				}
				if(filter_vect[2]==rx_val && !IsFloat)	
				{
					return true;
				}
			}
			if(filter_vect[1]=="<>")
			{
				//5<>10
				if(received_val < extra_a || received_val > extra_b)
				{
					return true;
				}
			}
			if(filter_vect[1]=="<=>")
			{
				//5<=>10
				if( ( (received_val < extra_a) || (FloatCompareOptions(received_val,extra_a)) )  || ( (received_val > extra_b) || (FloatCompareOptions(received_val,extra_b)) ))
				{
					return true;
				}
			}
			return false;
		}

		bool OptionScanner_FilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
		{
			if(m_columnPatterns.empty())
				return true;

			bool ret = false;
			std::map<int,std::string>::const_iterator it;
			for(it = m_columnPatterns.begin(); it!=m_columnPatterns.end() ; ++it)
			{
				QModelIndex index = sourceModel()->index(sourceRow, it->first, sourceParent);
				std::string d = index.data().toString().toStdString() ;
				std::string e = it->second;//Close_>=_8
				ret = ShouldRowBeDisplayed(e,d);//ShouldRowBeFiltered(e,d);
				if(!ret)
				{
					return ret; //Will return a row as false while it checks all its conditions
				}
			}

			return ret;
		}//End method


		float OptionScanner_FilterProxyModel::trunc(float d) const
		{
			return (d>0) ? floor(d) : ceil(d) ; 
		}

		//Yes they are equal
		bool OptionScanner_FilterProxyModel::FloatCompareOptions(float a , float b) const
		{
			if (trunc(100.0 * a) == trunc(100.0 * b))
			{
				return true;
			}
			return false;

		}//End method

	}//End Namespace
}//End Namespace

