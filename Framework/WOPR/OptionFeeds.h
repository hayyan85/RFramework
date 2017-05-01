#ifndef OPTIONFEEDS_H
#define OPTIONFEEDS_H

#include <QWidget>
#include "ui_OptionFeeds.h"
#include "OptionTick.pb.h"
#include "QStandardItemModel"
#include "QTimer"
#include "boost/thread/mutex.hpp"

class OptionFeeds : public QWidget
{
	Q_OBJECT

public:
	OptionFeeds(QWidget *parent = 0);
	~OptionFeeds();
	static OptionFeeds* PtrOptionFeedsForm;

private:
	Ui::OptionFeeds ui;
	QStandardItemModel* ModelOptionTable;    //Model of Option table
	int DecimalDigits;
	void InitializeOptionsTable();
	void AddNewItemToModel(Serializable::OptionTick_ser otick);
	void UpdateExistingItemInModel(Serializable::OptionTick_ser& otick,int rowno);
	std::string ConvertIntToString(int a);
	std::string Roundfloat(float a);
	void MakeCellBlink(int row);
	boost::mutex mutex_blinker;
public slots:
	void OptionFeeds_ManageTableUpdates(Serializable::OptionTick_ser otick);
	void ConsoleMessage(std::string msg);
	void SearchSymbol();
};

#endif // OPTIONFEEDS_H
