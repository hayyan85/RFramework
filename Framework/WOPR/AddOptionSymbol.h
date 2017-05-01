#ifndef ADDOPTIONSYMBOL_H
#define ADDOPTIONSYMBOL_H

#include <QDialog>
#include "ui_AddOptionSymbol.h"

#define IMPLEMENT_SET_METHOD( type , name )	\
private:	type name;	\
public:		void set_##name(  type value ) {  name = value; }

#define IMPLEMENT_GET_METHOD( type , name )	\
public:		 type get_##name() 	{ return name; }

#define IMPLEMENT_SET_GET_METHOD( type , name ) \
	IMPLEMENT_SET_METHOD( type , name );	\
	IMPLEMENT_GET_METHOD( type , name );


class AddOptionSymbol : public QDialog
{
	Q_OBJECT

public:
	AddOptionSymbol(QWidget *parent = 0);
	~AddOptionSymbol();

private:
	Ui::AddOptionSymbol ui;
	IMPLEMENT_SET_GET_METHOD(std::string,under);
	IMPLEMENT_SET_GET_METHOD(std::string,callput);
	IMPLEMENT_SET_GET_METHOD(float,strike);
	IMPLEMENT_SET_GET_METHOD(std::string,expdate);
	IMPLEMENT_SET_GET_METHOD(std::string,symbol);
	IMPLEMENT_SET_GET_METHOD(std::string,stisymbol);
	IMPLEMENT_SET_GET_METHOD(bool,AddRecord);
	void intialize();
public slots:

	void AddSymbol();
	void cancel();
};

#endif // ADDOPTIONSYMBOL_H
