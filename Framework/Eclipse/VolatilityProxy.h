#ifndef VOLATILITY_SCANNER_PROXYMODEL_HEADER
#define VOLATILITY_SCANNER_PROXYMODEL_HEADER

#include <QSortFilterProxyModel>
#include <vector>
#include "QStandardItemModel"
#include "QHeaderView"
#include "QDate"

class VolatilityGraph;

namespace Framework
{
	namespace NEclipse
	{
		class VolatilityGraph_FilterProxyModel : public QSortFilterProxyModel
		{
			Q_OBJECT
		public:
			explicit VolatilityGraph_FilterProxyModel(VolatilityGraph* os,QObject *parent = 0);
			
			void AddFilterToColumn(int col_no,std::string filter_string,QStandardItemModel* frmPtrModel);
			void RemoveFilterFromColumn(int col_no,QStandardItemModel* frmPtrModel);

			void SetFilterExpressionFromLayout(std::map<int,std::string> layoutMap);
			std::map<int,std::string> GetFilterExpressionCollection();


			void SetColumnsToHideFromLayout(std::vector<int> layoutMap);
			std::vector<int> GetHideCoulmnCollection();

			void FilterSpecificColumn(int col_no);
			void UndoFilterSpecificColumn(int col_no);

		protected:
			bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
			bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
			bool lessThan(const QModelIndex &left, const QModelIndex &right) const;

		private:
			VolatilityGraph* volatplot;
			
			mutable int ColumnAdded;
			std::map<int,std::string>m_columnPatterns;
			std::vector<int> ColumnNoToFilter;
			bool ShouldRowBeDisplayed(const std::string filter_string,const std::string rx_val) const;
	        QDate ConvertToDate(const QString& dt) const;
			float trunc(float d) const;
			bool FloatCompareOptions(float a , float b) const;
	   signals:
			void NewColumnAdded(int col) const;

		};
	}
}

#endif // OPTION_SCANNER_PROXYMODEL_HEADER