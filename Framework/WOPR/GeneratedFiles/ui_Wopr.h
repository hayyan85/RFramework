/********************************************************************************
** Form generated from reading UI file 'Wopr.ui'
**
** Created: Wed Oct 23 10:02:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WOPR_H
#define UI_WOPR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WOPRClass
{
public:
    QAction *actionStart_Feeds;
    QAction *actionAdd_New_Option;
    QAction *actionAdd_Option;
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuManage;

    void setupUi(QMainWindow *WOPRClass)
    {
        if (WOPRClass->objectName().isEmpty())
            WOPRClass->setObjectName(QString::fromUtf8("WOPRClass"));
        WOPRClass->resize(348, 237);
        actionStart_Feeds = new QAction(WOPRClass);
        actionStart_Feeds->setObjectName(QString::fromUtf8("actionStart_Feeds"));
        actionAdd_New_Option = new QAction(WOPRClass);
        actionAdd_New_Option->setObjectName(QString::fromUtf8("actionAdd_New_Option"));
        actionAdd_Option = new QAction(WOPRClass);
        actionAdd_Option->setObjectName(QString::fromUtf8("actionAdd_Option"));
        centralWidget = new QWidget(WOPRClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 331, 201));
        label->setFrameShape(QFrame::Box);
        label->setPixmap(QPixmap(QString::fromUtf8(":/WOPR/WOPR.png")));
        label->setScaledContents(true);
        WOPRClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WOPRClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 348, 18));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuManage = new QMenu(menuBar);
        menuManage->setObjectName(QString::fromUtf8("menuManage"));
        WOPRClass->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuManage->menuAction());
        menuOptions->addAction(actionStart_Feeds);
        menuManage->addAction(actionAdd_Option);

        retranslateUi(WOPRClass);

        QMetaObject::connectSlotsByName(WOPRClass);
    } // setupUi

    void retranslateUi(QMainWindow *WOPRClass)
    {
        WOPRClass->setWindowTitle(QApplication::translate("WOPRClass", "WOPR", 0, QApplication::UnicodeUTF8));
        actionStart_Feeds->setText(QApplication::translate("WOPRClass", "Start WOPR", 0, QApplication::UnicodeUTF8));
        actionAdd_New_Option->setText(QApplication::translate("WOPRClass", "Add New Option", 0, QApplication::UnicodeUTF8));
        actionAdd_Option->setText(QApplication::translate("WOPRClass", "Add Option Symbol", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuOptions->setTitle(QApplication::translate("WOPRClass", "Options", 0, QApplication::UnicodeUTF8));
        menuManage->setTitle(QApplication::translate("WOPRClass", "Manage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WOPRClass: public Ui_WOPRClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WOPR_H
