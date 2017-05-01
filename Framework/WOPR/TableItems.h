#ifndef Table_Items_Header
#define Table_Items_Header

#include <iostream>
#include <QWidget>
#include <QtGui/QMainWindow>
#include <QTableWidgetItem>

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );

namespace Framework
{
	namespace WOPR
	{
		class Table_Items_Holder
		{
			IMPLEMENT_SET_GET_METHOD(int,row_no);
			IMPLEMENT_SET_GET_METHOD(int,frequency);
			IMPLEMENT_SET_GET_METHOD(std::string,symbol);

			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,bar_high);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,bar_low);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,close);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,date);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,lcg);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,scg);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,CGTrend);

			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,highesthigh);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,lowestlow);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,highzone);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,lowzone);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,R2Value);

			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,Latr);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,Satr);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,LRange);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,VClose);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,ValueStd);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,ValueIncrement);
			IMPLEMENT_SET_GET_METHOD(QTableWidgetItem*,ba_spread);

		};

	}//end namespace FeedDispatcher
}//end namespace FeedMgr

#endif 