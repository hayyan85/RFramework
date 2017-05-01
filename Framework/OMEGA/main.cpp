#include "omega.h"
#include <QtGui/QApplication>

#include <cmath>
#include "QString"
#include <sstream>
#include "boost/lexical_cast.hpp"

int main(int argc, char *argv[])
{
	
	/*std::string t = "2.34";
	double m = 2.34;
	double j = float(234)/float(100);
    double a=  boost::lexical_cast<double>(t);
	std::cin.get();*/
	
	
	QApplication a(argc, argv);
	OMEGA w;
	w.setWindowFlags(w.windowFlags() | Qt::Dialog);
	w.setFixedSize(w.size());
	w.show();
	return a.exec();
	

}
