#ifndef WOPR_H
#define WOPR_H

#include <QtGui/QMainWindow>
#include "ui_Wopr.h"
#include <QtCore>
#include <map>
#include <vector>

class UpdateFeeds; //Forward dec.

class WOPR : public QMainWindow
{
	Q_OBJECT
public:
	~WOPR();
	WOPR(QWidget *parent = 0, Qt::WFlags flags = 0);
	static std::string GetConfigValue(std::string item_);
	static std::map<std::string,std::string>& get_config_map();
private:
	Ui::WOPRClass ui;
	UpdateFeeds* updtFeeds;
	static bool ConfigInitialized;
	static void InitializeConfigSettings();
	public slots:
		void  startOptions();
		void  startUpdates();
		void  AddNewOptionSymbol();
		void QuitWOPR();
};

#endif // WOPR_H
