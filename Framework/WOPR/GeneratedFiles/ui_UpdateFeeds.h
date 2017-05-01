/********************************************************************************
** Form generated from reading UI file 'UpdateFeeds.ui'
**
** Created: Wed Oct 23 10:02:42 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEFEEDS_H
#define UI_UPDATEFEEDS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateFeeds
{
public:
    QLabel *labelHistTot;
    QLabel *label_8;
    QLabel *label_7;
    QPushButton *pushConnect;
    QFrame *line_2;
    QFrame *line;
    QLabel *labelHistCompleted;
    QListWidget *listConsole;
    QFrame *line_3;
    QTableView *table_lists;
    QLabel *label_9;

    void setupUi(QWidget *UpdateFeeds)
    {
        if (UpdateFeeds->objectName().isEmpty())
            UpdateFeeds->setObjectName(QString::fromUtf8("UpdateFeeds"));
        UpdateFeeds->resize(660, 439);
        labelHistTot = new QLabel(UpdateFeeds);
        labelHistTot->setObjectName(QString::fromUtf8("labelHistTot"));
        labelHistTot->setGeometry(QRect(160, 50, 91, 16));
        label_8 = new QLabel(UpdateFeeds);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 70, 131, 16));
        label_7 = new QLabel(UpdateFeeds);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 131, 16));
        pushConnect = new QPushButton(UpdateFeeds);
        pushConnect->setObjectName(QString::fromUtf8("pushConnect"));
        pushConnect->setGeometry(QRect(10, 10, 111, 23));
        line_2 = new QFrame(UpdateFeeds);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 90, 641, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(UpdateFeeds);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 30, 641, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelHistCompleted = new QLabel(UpdateFeeds);
        labelHistCompleted->setObjectName(QString::fromUtf8("labelHistCompleted"));
        labelHistCompleted->setGeometry(QRect(160, 70, 91, 16));
        listConsole = new QListWidget(UpdateFeeds);
        listConsole->setObjectName(QString::fromUtf8("listConsole"));
        listConsole->setGeometry(QRect(10, 110, 641, 151));
        listConsole->setFrameShape(QFrame::Box);
        listConsole->setFrameShadow(QFrame::Plain);
        listConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listConsole->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listConsole->setAlternatingRowColors(true);
        line_3 = new QFrame(UpdateFeeds);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 270, 641, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        table_lists = new QTableView(UpdateFeeds);
        table_lists->setObjectName(QString::fromUtf8("table_lists"));
        table_lists->setGeometry(QRect(10, 310, 641, 111));
        table_lists->setFrameShape(QFrame::Box);
        table_lists->setFrameShadow(QFrame::Plain);
        table_lists->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        table_lists->setAlternatingRowColors(true);
        table_lists->setGridStyle(Qt::DashDotLine);
        table_lists->setSortingEnabled(false);
        table_lists->setWordWrap(false);
        table_lists->horizontalHeader()->setVisible(true);
        table_lists->horizontalHeader()->setDefaultSectionSize(75);
        table_lists->verticalHeader()->setVisible(false);
        table_lists->verticalHeader()->setDefaultSectionSize(20);
        label_9 = new QLabel(UpdateFeeds);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 290, 131, 16));

        retranslateUi(UpdateFeeds);

        QMetaObject::connectSlotsByName(UpdateFeeds);
    } // setupUi

    void retranslateUi(QWidget *UpdateFeeds)
    {
        UpdateFeeds->setWindowTitle(QApplication::translate("UpdateFeeds", "WOPR : UpdateFeeds", 0, QApplication::UnicodeUTF8));
        labelHistTot->setText(QApplication::translate("UpdateFeeds", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UpdateFeeds", "Completed Hist Commands:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UpdateFeeds", "Total History Commands    :", 0, QApplication::UnicodeUTF8));
        pushConnect->setText(QApplication::translate("UpdateFeeds", "Connect To IQLink", 0, QApplication::UnicodeUTF8));
        labelHistCompleted->setText(QApplication::translate("UpdateFeeds", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("UpdateFeeds", "Select the lists to automate :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UpdateFeeds: public Ui_UpdateFeeds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEFEEDS_H
