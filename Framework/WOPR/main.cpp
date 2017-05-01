#include "Wopr.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	WOPR w;
	w.setWindowFlags(w.windowFlags() | Qt::Dialog);
	w.setFixedSize(w.size());
	w.show();
	
	return a.exec();
}
