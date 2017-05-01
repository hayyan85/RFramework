#include "AddOptionSymbol.h"

AddOptionSymbol::AddOptionSymbol(QWidget *parent): QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.cmdAddSymbol,SIGNAL(clicked()),this,SLOT(AddSymbol()));
	intialize();
}

AddOptionSymbol::~AddOptionSymbol()
{

}

void AddOptionSymbol::AddSymbol()
{
	set_under(ui.lineEditUnder->text().toStdString());
	set_symbol(ui.lineEditSymbol->text().toStdString());
	set_strike(ui.lineEditStrike->text().toFloat());
	set_callput(ui.comboBoxCallPut->currentText().toStdString());
	set_expdate(ui.lineEditExpDate->text().toStdString());
	set_stisymbol(ui.lineEditSTISymbol->text().toStdString());
	if(ui.checkBoxAddRecord->isChecked())
	{
		set_AddRecord(true);
	}
	else
	{
		set_AddRecord(false);
	}
	accept();
}

void AddOptionSymbol::intialize()
{
	ui.checkBoxAddRecord->setChecked(true);
	ui.comboBoxCallPut->addItem("C");
	ui.comboBoxCallPut->addItem("P");
	ui.lineEditExpDate->setText("YYYY-MM-DD");
}

void AddOptionSymbol::cancel()
{
	reject();
}