#include "Eclipse.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Eclipse w;
	w.setWindowFlags(w.windowFlags() | Qt::Dialog);
	w.setFixedSize(w.size());
	w.show();
	return a.exec();
}
