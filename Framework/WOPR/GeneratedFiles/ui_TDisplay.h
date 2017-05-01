/********************************************************************************
** Form generated from reading UI file 'TDisplay.ui'
**
** Created: Wed Oct 23 10:02:42 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDISPLAY_H
#define UI_TDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TDisplay
{
public:
    QLabel *label;
    QLabel *label_2;
    QFrame *line_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_10;
    QListWidget *listConsole;
    QLabel *label_5;
    QTextEdit *textEditQuantity;
    QLabel *label_6;
    QTextEdit *textTimeDifference;
    QLabel *label_7;
    QTextEdit *textSymbolMonitor;
    QTableView *OneMinTableView;
    QTableView *FiveMinTableView;
    QTableView *TenMinTableView;
    QTableView *ThirtyMinTableView;

    void setupUi(QWidget *TDisplay)
    {
        if (TDisplay->objectName().isEmpty())
            TDisplay->setObjectName(QString::fromUtf8("TDisplay"));
        TDisplay->resize(914, 689);
        label = new QLabel(TDisplay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 111, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(TDisplay);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 180, 111, 16));
        label_2->setFont(font);
        line_3 = new QFrame(TDisplay);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 540, 971, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(TDisplay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 300, 111, 16));
        label_3->setFont(font);
        label_4 = new QLabel(TDisplay);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 420, 111, 16));
        label_4->setFont(font);
        label_10 = new QLabel(TDisplay);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 560, 91, 16));
        label_10->setFont(font);
        listConsole = new QListWidget(TDisplay);
        listConsole->setObjectName(QString::fromUtf8("listConsole"));
        listConsole->setGeometry(QRect(10, 580, 881, 101));
        listConsole->setFrameShape(QFrame::Box);
        listConsole->setFrameShadow(QFrame::Plain);
        listConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listConsole->setAutoScroll(true);
        listConsole->setAutoScrollMargin(21);
        listConsole->setAlternatingRowColors(true);
        listConsole->setSelectionMode(QAbstractItemView::NoSelection);
        listConsole->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        label_5 = new QLabel(TDisplay);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(780, 20, 101, 16));
        label_5->setFont(font);
        textEditQuantity = new QTextEdit(TDisplay);
        textEditQuantity->setObjectName(QString::fromUtf8("textEditQuantity"));
        textEditQuantity->setEnabled(false);
        textEditQuantity->setGeometry(QRect(780, 40, 104, 31));
        label_6 = new QLabel(TDisplay);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(650, 20, 121, 16));
        label_6->setFont(font);
        textTimeDifference = new QTextEdit(TDisplay);
        textTimeDifference->setObjectName(QString::fromUtf8("textTimeDifference"));
        textTimeDifference->setEnabled(false);
        textTimeDifference->setGeometry(QRect(650, 40, 111, 31));
        textTimeDifference->setReadOnly(false);
        label_7 = new QLabel(TDisplay);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 20, 111, 20));
        label_7->setFont(font);
        textSymbolMonitor = new QTextEdit(TDisplay);
        textSymbolMonitor->setObjectName(QString::fromUtf8("textSymbolMonitor"));
        textSymbolMonitor->setGeometry(QRect(520, 40, 111, 31));
        OneMinTableView = new QTableView(TDisplay);
        OneMinTableView->setObjectName(QString::fromUtf8("OneMinTableView"));
        OneMinTableView->setGeometry(QRect(10, 80, 881, 91));
        OneMinTableView->setFrameShape(QFrame::Box);
        OneMinTableView->setFrameShadow(QFrame::Plain);
        OneMinTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        OneMinTableView->setAutoScroll(false);
        OneMinTableView->setAlternatingRowColors(true);
        OneMinTableView->setWordWrap(false);
        OneMinTableView->verticalHeader()->setDefaultSectionSize(25);
        FiveMinTableView = new QTableView(TDisplay);
        FiveMinTableView->setObjectName(QString::fromUtf8("FiveMinTableView"));
        FiveMinTableView->setGeometry(QRect(10, 200, 881, 91));
        FiveMinTableView->setFrameShape(QFrame::Box);
        FiveMinTableView->setFrameShadow(QFrame::Plain);
        FiveMinTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        FiveMinTableView->setAutoScroll(false);
        FiveMinTableView->setAlternatingRowColors(true);
        FiveMinTableView->setWordWrap(false);
        FiveMinTableView->verticalHeader()->setDefaultSectionSize(25);
        TenMinTableView = new QTableView(TDisplay);
        TenMinTableView->setObjectName(QString::fromUtf8("TenMinTableView"));
        TenMinTableView->setGeometry(QRect(10, 320, 881, 91));
        TenMinTableView->setFrameShape(QFrame::Box);
        TenMinTableView->setFrameShadow(QFrame::Plain);
        TenMinTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        TenMinTableView->setAutoScroll(false);
        TenMinTableView->setAlternatingRowColors(true);
        TenMinTableView->setWordWrap(false);
        TenMinTableView->verticalHeader()->setDefaultSectionSize(25);
        ThirtyMinTableView = new QTableView(TDisplay);
        ThirtyMinTableView->setObjectName(QString::fromUtf8("ThirtyMinTableView"));
        ThirtyMinTableView->setGeometry(QRect(10, 440, 881, 91));
        ThirtyMinTableView->setFrameShape(QFrame::Box);
        ThirtyMinTableView->setFrameShadow(QFrame::Plain);
        ThirtyMinTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ThirtyMinTableView->setAutoScroll(false);
        ThirtyMinTableView->setAlternatingRowColors(true);
        ThirtyMinTableView->setWordWrap(false);
        ThirtyMinTableView->verticalHeader()->setDefaultSectionSize(25);

        retranslateUi(TDisplay);

        QMetaObject::connectSlotsByName(TDisplay);
    } // setupUi

    void retranslateUi(QWidget *TDisplay)
    {
        TDisplay->setWindowTitle(QApplication::translate("TDisplay", "TDisplay", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TDisplay", "Frequency : 1 Min", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TDisplay", "Frequency : 5 Min", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TDisplay", "Frequency : 10 Min", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TDisplay", "Frequency : 30 Min", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TDisplay", "Output Console", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TDisplay", "Total Que Items", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TDisplay", "Max. Time Difference", 0, QApplication::UnicodeUTF8));
        textTimeDifference->setHtml(QApplication::translate("TDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TDisplay", "Symbol To Monitor", 0, QApplication::UnicodeUTF8));
        textSymbolMonitor->setHtml(QApplication::translate("TDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">SPY</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TDisplay: public Ui_TDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDISPLAY_H
