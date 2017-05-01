#ifndef STRIKEGRAPH_H
#define STRIKEGRAPH_H

#include <QMainWindow>
#include "ui_StrikeGraph.h"

class StrikeGraph : public QMainWindow
{
	Q_OBJECT

public:
	StrikeGraph(QWidget *parent = 0);
	~StrikeGraph();

private:
	Ui::StrikeGraph ui;
};

#endif // STRIKEGRAPH_H
