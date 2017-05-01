#ifndef OPTIONSCANNER_H
#define OPTIONSCANNER_H

#include <QMainWindow>
#include "ui_OptionScanner.h"
#include "OptionTick.pb.h"
#include "QStandardItemModel" 
#include "MySQL-Eclipse.h"
//#include "OptionScannerProxy.h"
#include "QHeaderView"
#include "QByteArray"
#include "QTimer"

namespace Framework
{
	namespace NEclipse
	{
		class OptionScanner_FilterProxyModel;
	}
}

class OptionScanner : public QMainWindow
{
	Q_OBJECT

public:
	OptionScanner(QWidget *parent = 0);
	std::string getFormGUID();
	~OptionScanner();
	Framework::NEclipse::OptionScanner_FilterProxyModel* FilterModelOptionTable;

private:
	QTimer SortTimer;
	int ColumnToSort;
	Qt::SortOrder ColumnSortorder;

	bool bConnect;
	QByteArray OptionsColOrder; 
	std::string FormGUID;
	bool options_visible;
	QStandardItemModel* Column_Model;
	std::map<std::string,int> ColumnNameNos;
	Framework::NEclipse::DBaseConnection db;
	std::vector<std::string> SubscribedSymbols;
	Ui::OptionScanner ui;
	QStandardItemModel* ModelOptions;
	void AddNewOption(Serializable::OptionTick_ser& otick);
	void UpdateExistingOption(Serializable::OptionTick_ser& otick, int rowno);
	std::string ConvertIntToString(int a);
	std::string Roundfloat(float a);
	void InitializeOptionModel();	
	void InitiateOptionScanner();
	void SubscribeToOptionTopic(std::string symbol , std::string topic);
	void UnSubscribeFromTopic(std::string symbol);
	void PopulateFilterOptions();
	void PopulateColumnComboBox();
	void ShowDefaultSubsciptionColumns();
	std::string ReturnColumnName(int i);
	//std::string headerstring; //Delete later
	
public slots:

	void ManageTableUpdates(Serializable::OptionTick_ser otick);
	void RetrieveAllOptions();
	void FilterColumn(QStandardItem* p);
	void RemoveFilter();
	void AddNewFilter();
	void AddNewFilter(std::map<int,std::string>& FilterExpression);
	void HighlightSymbol();
	void HideOptions();
	void sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex);
	void saveLayout();
	void LoadLayout();
	//void TestLayout(); //Delete Later

	void OptionssortIndicatorChanged (int logicalIndex	, Qt::SortOrder order);
	void ConfigureAutoSort();
	void StopAutoSort();
	void UpdateSort();
	void LogicalOperatorChanged(int index);
	//void NewColumnInserted(int colno);
};

#endif // OPTIONSCANNER_H
