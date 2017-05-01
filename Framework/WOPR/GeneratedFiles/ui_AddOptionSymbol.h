/********************************************************************************
** Form generated from reading UI file 'AddOptionSymbol.ui'
**
** Created: Wed Oct 23 10:02:42 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOPTIONSYMBOL_H
#define UI_ADDOPTIONSYMBOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddOptionSymbol
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxAddRecord;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditUnder;
    QComboBox *comboBoxCallPut;
    QLineEdit *lineEditStrike;
    QLineEdit *lineEditExpDate;
    QLineEdit *lineEditSymbol;
    QLineEdit *lineEditSTISymbol;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cmdAddSymbol;
    QPushButton *cmdCancel;

    void setupUi(QDialog *AddOptionSymbol)
    {
        if (AddOptionSymbol->objectName().isEmpty())
            AddOptionSymbol->setObjectName(QString::fromUtf8("AddOptionSymbol"));
        AddOptionSymbol->resize(276, 274);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddOptionSymbol->sizePolicy().hasHeightForWidth());
        AddOptionSymbol->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(AddOptionSymbol);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(AddOptionSymbol);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        checkBoxAddRecord = new QCheckBox(AddOptionSymbol);
        checkBoxAddRecord->setObjectName(QString::fromUtf8("checkBoxAddRecord"));

        horizontalLayout_3->addWidget(checkBoxAddRecord);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AddOptionSymbol);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AddOptionSymbol);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(AddOptionSymbol);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(AddOptionSymbol);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(AddOptionSymbol);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(AddOptionSymbol);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditUnder = new QLineEdit(AddOptionSymbol);
        lineEditUnder->setObjectName(QString::fromUtf8("lineEditUnder"));
        sizePolicy1.setHeightForWidth(lineEditUnder->sizePolicy().hasHeightForWidth());
        lineEditUnder->setSizePolicy(sizePolicy1);
        lineEditUnder->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 7em;\n"
" }\n"
"\n"
"\n"
" QLineEdit QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
"\n"
"QLineEdit {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }"));

        verticalLayout_2->addWidget(lineEditUnder);

        comboBoxCallPut = new QComboBox(AddOptionSymbol);
        comboBoxCallPut->setObjectName(QString::fromUtf8("comboBoxCallPut"));
        sizePolicy1.setHeightForWidth(comboBoxCallPut->sizePolicy().hasHeightForWidth());
        comboBoxCallPut->setSizePolicy(sizePolicy1);
        comboBoxCallPut->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 3em;\n"
"max-width:7em;\n"
"\n"
" }\n"
"\n"
" QComboBox:editable {\n"
"     background: white;\n"
" }\n"
"\n"
" QComboBox:!editable, QComboBox::drop-down:editable {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }\n"
"\n"
" /* QComboBox gets the \"on\" state when the popup is open */\n"
" QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                 stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
" }\n"
"\n"
" QComboBox:on { /* shift the text when the popup opens */\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
" }\n"
"\n"
" QComboBox:"
                        ":drop-down {\n"
"\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 1px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
" QComboBox::down-arrow \n"
"{\n"
"     image: url(images/downarrow.png);\n"
"    width: 15px;\n"
"    height: 15px;\n"
" }\n"
"\n"
" QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"     top: 1px;\n"
"     left: 1px;\n"
" }\n"
"\n"
" QComboBox QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
"\n"
"   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"}\n"
""));

        verticalLayout_2->addWidget(comboBoxCallPut);

        lineEditStrike = new QLineEdit(AddOptionSymbol);
        lineEditStrike->setObjectName(QString::fromUtf8("lineEditStrike"));
        sizePolicy1.setHeightForWidth(lineEditStrike->sizePolicy().hasHeightForWidth());
        lineEditStrike->setSizePolicy(sizePolicy1);
        lineEditStrike->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 7em;\n"
" }\n"
"\n"
"\n"
" QLineEdit QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
"\n"
"QLineEdit {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }"));

        verticalLayout_2->addWidget(lineEditStrike);

        lineEditExpDate = new QLineEdit(AddOptionSymbol);
        lineEditExpDate->setObjectName(QString::fromUtf8("lineEditExpDate"));
        sizePolicy1.setHeightForWidth(lineEditExpDate->sizePolicy().hasHeightForWidth());
        lineEditExpDate->setSizePolicy(sizePolicy1);
        lineEditExpDate->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 7em;\n"
" }\n"
"\n"
"\n"
" QLineEdit QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
"\n"
"QLineEdit {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }"));

        verticalLayout_2->addWidget(lineEditExpDate);

        lineEditSymbol = new QLineEdit(AddOptionSymbol);
        lineEditSymbol->setObjectName(QString::fromUtf8("lineEditSymbol"));
        sizePolicy1.setHeightForWidth(lineEditSymbol->sizePolicy().hasHeightForWidth());
        lineEditSymbol->setSizePolicy(sizePolicy1);
        lineEditSymbol->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 7em;\n"
" }\n"
"\n"
"\n"
" QLineEdit QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
"\n"
"QLineEdit {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }"));

        verticalLayout_2->addWidget(lineEditSymbol);

        lineEditSTISymbol = new QLineEdit(AddOptionSymbol);
        lineEditSTISymbol->setObjectName(QString::fromUtf8("lineEditSTISymbol"));
        sizePolicy1.setHeightForWidth(lineEditSTISymbol->sizePolicy().hasHeightForWidth());
        lineEditSTISymbol->setSizePolicy(sizePolicy1);
        lineEditSTISymbol->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 7em;\n"
" }\n"
"\n"
"\n"
" QLineEdit QAbstractItemView {\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
"\n"
"QLineEdit {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }"));

        verticalLayout_2->addWidget(lineEditSTISymbol);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cmdAddSymbol = new QPushButton(AddOptionSymbol);
        cmdAddSymbol->setObjectName(QString::fromUtf8("cmdAddSymbol"));
        sizePolicy1.setHeightForWidth(cmdAddSymbol->sizePolicy().hasHeightForWidth());
        cmdAddSymbol->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(cmdAddSymbol);

        cmdCancel = new QPushButton(AddOptionSymbol);
        cmdCancel->setObjectName(QString::fromUtf8("cmdCancel"));
        sizePolicy1.setHeightForWidth(cmdCancel->sizePolicy().hasHeightForWidth());
        cmdCancel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(cmdCancel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(AddOptionSymbol);

        QMetaObject::connectSlotsByName(AddOptionSymbol);
    } // setupUi

    void retranslateUi(QDialog *AddOptionSymbol)
    {
        AddOptionSymbol->setWindowTitle(QApplication::translate("AddOptionSymbol", "AddOptionSymbol", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddOptionSymbol", "Insert New Option Symbol", 0, QApplication::UnicodeUTF8));
        checkBoxAddRecord->setText(QApplication::translate("AddOptionSymbol", "AddRecord", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddOptionSymbol", "Under", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddOptionSymbol", "CallPut", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddOptionSymbol", "Strike", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddOptionSymbol", "ExpDate", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddOptionSymbol", "Symbol", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddOptionSymbol", "STI Symbol", 0, QApplication::UnicodeUTF8));
        cmdAddSymbol->setText(QApplication::translate("AddOptionSymbol", "Add Symbol", 0, QApplication::UnicodeUTF8));
        cmdCancel->setText(QApplication::translate("AddOptionSymbol", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddOptionSymbol: public Ui_AddOptionSymbol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOPTIONSYMBOL_H
