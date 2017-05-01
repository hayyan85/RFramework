#ifndef SYMBOLLOAD_H
#define SYMBOLLOAD_H

//#include <QWidget>
#include "QDialog"
#include "ui_SymbolLoad.h"
#include "MySQL-OMEGA.h"
#include <map>

class SymbolLoad : public QDialog
{
	Q_OBJECT

public:
	SymbolLoad(QWidget *parent = 0);
	~SymbolLoad();
	std::map<std::string,std::string> symbolTypeMap;
	//----------these are for the QTypes--------
	std::string CallPut;
	std::string Maturity;
	float strike;
	std::string QuoteSymbol;
	std::string UnderLineSymbol;
	//-----------------------------------------

private:
	Framework::NOmega::DBaseConnection* db;
	Ui::SymbolLoad ui;
	
	void populateDistinctSymbols();
	void DateChangedProcess(QComboBox * callput,QComboBox* strike,std::string itm);
	void CallPutChangedProcess(QComboBox * strike,QComboBox* date,std::string itm);

public slots:
	void ProcessSymbolDetails();

	void Q_DateChanged(QString itm);
	void Q_CallPutChanged(QString itm);

	void A_DateChanged(QString itm);
	void A_CallPutChanged(QString itm);

	void B_DateChanged(QString itm);
	void B_CallPutChanged(QString itm);

	void C_DateChanged(QString itm);
	void C_CallPutChanged(QString itm);

	void D_DateChanged(QString itm);
	void D_CallPutChanged(QString itm);

	void RetrieveCorrespondingSymbol();
	void CancelForm();

};

#endif // SYMBOLLOAD_H
