#ifndef ECLIPSE_H
#define ECLIPSE_H

#include <QtGui/QMainWindow>
#include "ui_Eclipse.h"
#include <map>
#include "External.h"
#include "MySQL-Eclipse.h"
#include "OptionTick.pb.h"

Q_DECLARE_METATYPE(std::string);
Q_DECLARE_METATYPE(Serializable::OptionTick_ser);
Q_DECLARE_METATYPE(Serializable::Option_collection_ser);

class Eclipse : public QMainWindow
{
	Q_OBJECT
public:
	static Eclipse* EclipsePtr;
	Eclipse(QWidget *parent = 0, Qt::WFlags flags = 0);
	static bool ConfigInitialized;
	static void InitializeConfigSettings();
	static std::map<std::string,std::string> SymbAndTopics;
	static std::map<std::string,std::string> SymbUnderline;
	~Eclipse();
private:
	static std::map<std::string,std::string>& get_config_map();
	void GetSymbolsTopics();
	Framework::NEclipse::DBaseConnection* dbconnect;
	Ui::EclipseClass ui;
public slots:
	static std::string GetConfigValue(std::string item_);
	void DisplayUpdateFeeds();
	void DisplayEquityScanner();
	void DisplayVolatilityGraph();
	void DisplayOptionScanner();
	void DisplayExpirationGraph();
	void ErrorDisplay(QString ErrorMsg);
};

#endif // ECLIPSE_H
