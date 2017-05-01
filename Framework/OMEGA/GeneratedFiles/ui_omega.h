/********************************************************************************
** Form generated from reading UI file 'omega.ui'
**
** Created: Fri Nov 1 10:46:32 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMEGA_H
#define UI_OMEGA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OMEGAClass
{
public:
    QAction *actionOption_Quoter;
    QAction *actionStop_All_Quoters;
    QAction *actionPause_All_Quoters;
    QWidget *centralWidget;
    QLabel *label;
    QFrame *line;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_SQLSTATUS;
    QLabel *labelQPIDSTATUS;
    QLabel *label_A_2;
    QLabel *label_QpidEventStatus;
    QMenuBar *menuBar;
    QMenu *menuLauch_Component;
    QMenu *menuExit_OMEGA;
    QMenu *menuAbout;
    QMenu *menuManage_Component;
    QMenu *menuOmega;

    void setupUi(QMainWindow *OMEGAClass)
    {
        if (OMEGAClass->objectName().isEmpty())
            OMEGAClass->setObjectName(QString::fromUtf8("OMEGAClass"));
        OMEGAClass->resize(381, 308);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OMEGAClass->sizePolicy().hasHeightForWidth());
        OMEGAClass->setSizePolicy(sizePolicy);
        actionOption_Quoter = new QAction(OMEGAClass);
        actionOption_Quoter->setObjectName(QString::fromUtf8("actionOption_Quoter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/OMEGA/Images/Optionquoter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption_Quoter->setIcon(icon);
        actionStop_All_Quoters = new QAction(OMEGAClass);
        actionStop_All_Quoters->setObjectName(QString::fromUtf8("actionStop_All_Quoters"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/OMEGA/Images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop_All_Quoters->setIcon(icon1);
        actionPause_All_Quoters = new QAction(OMEGAClass);
        actionPause_All_Quoters->setObjectName(QString::fromUtf8("actionPause_All_Quoters"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/OMEGA/Images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_All_Quoters->setIcon(icon2);
        centralWidget = new QWidget(OMEGAClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 361, 221));
        label->setFrameShape(QFrame::Box);
        label->setPixmap(QPixmap(QString::fromUtf8(":/OMEGA/Images/OmegaMain.png")));
        label->setScaledContents(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 240, 361, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_A = new QLabel(centralWidget);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setGeometry(QRect(10, 250, 61, 16));
        label_B = new QLabel(centralWidget);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setGeometry(QRect(10, 270, 61, 16));
        label_SQLSTATUS = new QLabel(centralWidget);
        label_SQLSTATUS->setObjectName(QString::fromUtf8("label_SQLSTATUS"));
        label_SQLSTATUS->setGeometry(QRect(70, 250, 81, 16));
        label_SQLSTATUS->setStyleSheet(QString::fromUtf8("color : red; "));
        label_SQLSTATUS->setTextFormat(Qt::PlainText);
        labelQPIDSTATUS = new QLabel(centralWidget);
        labelQPIDSTATUS->setObjectName(QString::fromUtf8("labelQPIDSTATUS"));
        labelQPIDSTATUS->setGeometry(QRect(70, 270, 81, 16));
        labelQPIDSTATUS->setStyleSheet(QString::fromUtf8("color : red; "));
        label_A_2 = new QLabel(centralWidget);
        label_A_2->setObjectName(QString::fromUtf8("label_A_2"));
        label_A_2->setGeometry(QRect(160, 270, 91, 16));
        label_QpidEventStatus = new QLabel(centralWidget);
        label_QpidEventStatus->setObjectName(QString::fromUtf8("label_QpidEventStatus"));
        label_QpidEventStatus->setGeometry(QRect(250, 270, 81, 16));
        label_QpidEventStatus->setStyleSheet(QString::fromUtf8("color : red; "));
        label_QpidEventStatus->setTextFormat(Qt::PlainText);
        OMEGAClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OMEGAClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 381, 18));
        menuBar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"             background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                               stop:0 lightgray, stop:1 darkgray);\n"
"         }\n"
""));
        menuLauch_Component = new QMenu(menuBar);
        menuLauch_Component->setObjectName(QString::fromUtf8("menuLauch_Component"));
        menuExit_OMEGA = new QMenu(menuBar);
        menuExit_OMEGA->setObjectName(QString::fromUtf8("menuExit_OMEGA"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuManage_Component = new QMenu(menuBar);
        menuManage_Component->setObjectName(QString::fromUtf8("menuManage_Component"));
        menuOmega = new QMenu(menuManage_Component);
        menuOmega->setObjectName(QString::fromUtf8("menuOmega"));
        OMEGAClass->setMenuBar(menuBar);

        menuBar->addAction(menuLauch_Component->menuAction());
        menuBar->addAction(menuManage_Component->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuExit_OMEGA->menuAction());
        menuLauch_Component->addAction(actionOption_Quoter);
        menuManage_Component->addAction(menuOmega->menuAction());
        menuOmega->addAction(actionStop_All_Quoters);
        menuOmega->addSeparator();
        menuOmega->addAction(actionPause_All_Quoters);

        retranslateUi(OMEGAClass);

        QMetaObject::connectSlotsByName(OMEGAClass);
    } // setupUi

    void retranslateUi(QMainWindow *OMEGAClass)
    {
        OMEGAClass->setWindowTitle(QApplication::translate("OMEGAClass", "OMEGA", 0, QApplication::UnicodeUTF8));
        actionOption_Quoter->setText(QApplication::translate("OMEGAClass", "Option Quoter", 0, QApplication::UnicodeUTF8));
        actionStop_All_Quoters->setText(QApplication::translate("OMEGAClass", "Stop All Quoters", 0, QApplication::UnicodeUTF8));
        actionStop_All_Quoters->setShortcut(QApplication::translate("OMEGAClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPause_All_Quoters->setText(QApplication::translate("OMEGAClass", "Pause All Quoters", 0, QApplication::UnicodeUTF8));
        actionPause_All_Quoters->setShortcut(QApplication::translate("OMEGAClass", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_A->setText(QApplication::translate("OMEGAClass", "Database:", 0, QApplication::UnicodeUTF8));
        label_B->setText(QApplication::translate("OMEGAClass", "Messaging:", 0, QApplication::UnicodeUTF8));
        label_SQLSTATUS->setText(QApplication::translate("OMEGAClass", "Not Connected", 0, QApplication::UnicodeUTF8));
        labelQPIDSTATUS->setText(QApplication::translate("OMEGAClass", "Not Connected", 0, QApplication::UnicodeUTF8));
        label_A_2->setText(QApplication::translate("OMEGAClass", "Event Messaging:", 0, QApplication::UnicodeUTF8));
        label_QpidEventStatus->setText(QApplication::translate("OMEGAClass", "Not Connected", 0, QApplication::UnicodeUTF8));
        menuLauch_Component->setTitle(QApplication::translate("OMEGAClass", "Lauch Component", 0, QApplication::UnicodeUTF8));
        menuExit_OMEGA->setTitle(QApplication::translate("OMEGAClass", "Exit OMEGA", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("OMEGAClass", "About", 0, QApplication::UnicodeUTF8));
        menuManage_Component->setTitle(QApplication::translate("OMEGAClass", "Manage Component", 0, QApplication::UnicodeUTF8));
        menuOmega->setTitle(QApplication::translate("OMEGAClass", "Omega", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OMEGAClass: public Ui_OMEGAClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMEGA_H
