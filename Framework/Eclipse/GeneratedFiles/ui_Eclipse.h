/********************************************************************************
** Form generated from reading UI file 'Eclipse.ui'
**
** Created: Wed Oct 23 11:14:23 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECLIPSE_H
#define UI_ECLIPSE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EclipseClass
{
public:
    QAction *actionEquity_Scanner;
    QAction *actionVolatility_Graph;
    QAction *actionOption_Scanner;
    QAction *actionExpiration_Graph;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuLaunch_Component;
    QMenu *menuExit_ECLIPSE;
    QMenu *menuAbout;

    void setupUi(QMainWindow *EclipseClass)
    {
        if (EclipseClass->objectName().isEmpty())
            EclipseClass->setObjectName(QString::fromUtf8("EclipseClass"));
        EclipseClass->resize(385, 255);
        actionEquity_Scanner = new QAction(EclipseClass);
        actionEquity_Scanner->setObjectName(QString::fromUtf8("actionEquity_Scanner"));
        actionEquity_Scanner->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Eclipse/Images/stock_scanner.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEquity_Scanner->setIcon(icon);
        actionEquity_Scanner->setText(QString::fromUtf8("Equity Scanner"));
        actionEquity_Scanner->setIconText(QString::fromUtf8("Equity Scanner"));
        actionEquity_Scanner->setIconVisibleInMenu(true);
        actionVolatility_Graph = new QAction(EclipseClass);
        actionVolatility_Graph->setObjectName(QString::fromUtf8("actionVolatility_Graph"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Eclipse/Images/line_chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVolatility_Graph->setIcon(icon1);
        actionOption_Scanner = new QAction(EclipseClass);
        actionOption_Scanner->setObjectName(QString::fromUtf8("actionOption_Scanner"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Eclipse/Images/option_scan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption_Scanner->setIcon(icon2);
        actionExpiration_Graph = new QAction(EclipseClass);
        actionExpiration_Graph->setObjectName(QString::fromUtf8("actionExpiration_Graph"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Eclipse/Images/expired.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExpiration_Graph->setIcon(icon3);
        centralWidget = new QWidget(EclipseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Eclipse/Images/MainEclipse.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        EclipseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EclipseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 385, 18));
        menuLaunch_Component = new QMenu(menuBar);
        menuLaunch_Component->setObjectName(QString::fromUtf8("menuLaunch_Component"));
        menuExit_ECLIPSE = new QMenu(menuBar);
        menuExit_ECLIPSE->setObjectName(QString::fromUtf8("menuExit_ECLIPSE"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        EclipseClass->setMenuBar(menuBar);

        menuBar->addAction(menuLaunch_Component->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuExit_ECLIPSE->menuAction());
        menuLaunch_Component->addAction(actionEquity_Scanner);
        menuLaunch_Component->addSeparator();
        menuLaunch_Component->addAction(actionVolatility_Graph);
        menuLaunch_Component->addSeparator();
        menuLaunch_Component->addAction(actionOption_Scanner);
        menuLaunch_Component->addSeparator();
        menuLaunch_Component->addAction(actionExpiration_Graph);

        retranslateUi(EclipseClass);

        QMetaObject::connectSlotsByName(EclipseClass);
    } // setupUi

    void retranslateUi(QMainWindow *EclipseClass)
    {
        EclipseClass->setWindowTitle(QApplication::translate("EclipseClass", "Eclipse", 0, QApplication::UnicodeUTF8));
        actionEquity_Scanner->setShortcut(QApplication::translate("EclipseClass", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionVolatility_Graph->setText(QApplication::translate("EclipseClass", "Volatility Graph", 0, QApplication::UnicodeUTF8));
        actionVolatility_Graph->setShortcut(QApplication::translate("EclipseClass", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionOption_Scanner->setText(QApplication::translate("EclipseClass", "Option Scanner", 0, QApplication::UnicodeUTF8));
        actionOption_Scanner->setShortcut(QApplication::translate("EclipseClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExpiration_Graph->setText(QApplication::translate("EclipseClass", "Expiration Graph", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuLaunch_Component->setTitle(QApplication::translate("EclipseClass", "Launch Component", 0, QApplication::UnicodeUTF8));
        menuExit_ECLIPSE->setTitle(QApplication::translate("EclipseClass", "Exit Eclipse", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("EclipseClass", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EclipseClass: public Ui_EclipseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECLIPSE_H
