/********************************************************************************
** Form generated from reading UI file 'OptionFeeds.ui'
**
** Created: Wed Oct 23 10:02:42 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONFEEDS_H
#define UI_OPTIONFEEDS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionFeeds
{
public:
    QTableView *tableViewOptions;
    QPushButton *cmdFindSymbol;
    QLineEdit *lineEditSymbolName;
    QListWidget *listConsoleMsg;
    QLabel *label;

    void setupUi(QWidget *OptionFeeds)
    {
        if (OptionFeeds->objectName().isEmpty())
            OptionFeeds->setObjectName(QString::fromUtf8("OptionFeeds"));
        OptionFeeds->resize(904, 292);
        tableViewOptions = new QTableView(OptionFeeds);
        tableViewOptions->setObjectName(QString::fromUtf8("tableViewOptions"));
        tableViewOptions->setGeometry(QRect(20, 50, 851, 231));
        cmdFindSymbol = new QPushButton(OptionFeeds);
        cmdFindSymbol->setObjectName(QString::fromUtf8("cmdFindSymbol"));
        cmdFindSymbol->setGeometry(QRect(140, 20, 75, 23));
        lineEditSymbolName = new QLineEdit(OptionFeeds);
        lineEditSymbolName->setObjectName(QString::fromUtf8("lineEditSymbolName"));
        lineEditSymbolName->setGeometry(QRect(20, 20, 113, 20));
        listConsoleMsg = new QListWidget(OptionFeeds);
        listConsoleMsg->setObjectName(QString::fromUtf8("listConsoleMsg"));
        listConsoleMsg->setGeometry(QRect(20, 310, 851, 351));
        listConsoleMsg->setAlternatingRowColors(true);
        label = new QLabel(OptionFeeds);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 290, 91, 16));

        retranslateUi(OptionFeeds);

        QMetaObject::connectSlotsByName(OptionFeeds);
    } // setupUi

    void retranslateUi(QWidget *OptionFeeds)
    {
        OptionFeeds->setWindowTitle(QApplication::translate("OptionFeeds", "OptionFeeds", 0, QApplication::UnicodeUTF8));
        cmdFindSymbol->setText(QApplication::translate("OptionFeeds", "Find Symbol", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionFeeds", "Console Messages:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionFeeds: public Ui_OptionFeeds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONFEEDS_H
