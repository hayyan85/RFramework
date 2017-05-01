#ifndef TDISPLAY_H
#define TDISPLAY_H

#include <QWidget>
#include "ui_TDisplay.h"
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp> 
#include "TableItems.h"
#include "QStandardItemModel"

//Q_DECLARE_METATYPE(Serializable::HistoricalCollection_ser);
//Q_DECLARE_METATYPE(Serializable::HistoricalFields_ser);

//using namespace Serializable;

class TDisplay : public QWidget
{
	Q_OBJECT

public:
	TDisplay(QWidget *parent = 0);
	static TDisplay* TableForm;
	~TDisplay();
private:
	Ui::TDisplay ui;
	QStandardItemModel* ModelOneMin;
	QStandardItemModel* ModelFiveMin;
	QStandardItemModel* ModelTenMin;
	QStandardItemModel* ModelThirtyMin;
	static int DecimalDigits;
	void InitializeTables();
	std::string Roundfloat(float a);
	//void ProcessSymbolDetails(Serializable::HistoricalFields_ser& hfield); 
	//void AddNewItemToModel(QStandardItemModel* model,Serializable::HistoricalFields_ser& hfield);
	//void UpdateExistingItemInModel(QStandardItemModel* model,Serializable::HistoricalFields_ser& hfield,int rowno);
	
	void AdjustTrendColour(QStandardItemModel* model,int row);
	void AdjustVcloseColour(QStandardItemModel* model,int row);
	
public slots:
	//void ManageTableUpdates(Serializable::HistoricalCollection_ser hcol);
	void UpdateSiloQuantity(int quantity,std::string symb);
	void UpdateFeedDelay(float delay_ms,std::string symb);
};

#endif // TDISPLAY_H
