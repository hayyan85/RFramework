#ifndef OMEGA_H
#define OMEGA_H

#include <QtGui/QMainWindow>
#include "ui_omega.h"
#include "MySQL-OMEGA.h"
#include "OptionTick.pb.h"
#include "RTypes.pb.h"
#include "OptionQuoter.h"

Q_DECLARE_METATYPE(std::string);
Q_DECLARE_METATYPE(Serializable::RUpdatePacket);
Q_DECLARE_METATYPE(Serializable::OptionTick_ser);
Q_DECLARE_METATYPE(Serializable::ROrderPosition);

class OMEGA : public QMainWindow
{
	Q_OBJECT

public:
	OMEGA(QWidget *parent = 0, Qt::WFlags flags = 0);
	~OMEGA();

	bool Dbconnected;
	static std::map<std::string,std::string>  IQSterlingEquivalent;  //IQSymbol-Sterling Symbol
	static std::map<std::string,std::string>  SymbAndTopics;         //Symbol-TopicName
	static std::map<std::string,std::string>  SymbAndUnderlying;     //Symbol-TopicName
	static std::map<std::string, OptionQuoter*> OptionQuoterTracker; //GUID-OPTION QUOTER

	static std::map<std::string,std::string>& get_config_map();
	static std::string GetConfigValue(std::string item_);
	static void RemoveOptionQuoterForm(std::string FormGUID);

private:
	Ui::OMEGAClass ui;
	static bool ConfigInitialized;
	static void InitializeConfigSettings();
	std::vector<std::string> SubscribedSymbols;
	Framework::NOmega::DBaseConnection* dbconnect;
	void GetSymbolsTopics();
	void InitializeDatabase();
	void TestQpidFeedConnection();
	void TestQpidEventConnection();

public slots:
   void StartOptionQuoter();
   void StopAllQuoters();
   void PauseAllQuoters();
};

#endif // OMEGA_H
