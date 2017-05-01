/********************************************************************************
** Form generated from reading UI file 'ExpGraph.ui'
**
** Created: Wed Oct 23 11:14:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPGRAPH_H
#define UI_EXPGRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_ExpGraph
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboDistinctSymbol;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *comboCallPut;
    QPushButton *cmdStart;
    QPushButton *cmdHideTable;
    QSpacerItem *horizontalSpacer;
    QFrame *frametableDisplay;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableOptions;
    QCustomPlot *LinePlot;

    void setupUi(QMainWindow *ExpGraph)
    {
        if (ExpGraph->objectName().isEmpty())
            ExpGraph->setObjectName(QString::fromUtf8("ExpGraph"));
        ExpGraph->resize(854, 922);
        centralWidget = new QWidget(ExpGraph);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        comboDistinctSymbol = new QComboBox(centralWidget);
        comboDistinctSymbol->setObjectName(QString::fromUtf8("comboDistinctSymbol"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboDistinctSymbol->sizePolicy().hasHeightForWidth());
        comboDistinctSymbol->setSizePolicy(sizePolicy1);
        comboDistinctSymbol->setMinimumSize(QSize(75, 0));
        comboDistinctSymbol->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 4em;\n"
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
" QComboBox::drop-down {\n"
"\n"
"  "
                        "   subcontrol-origin: padding;\n"
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

        verticalLayout->addWidget(comboDistinctSymbol);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_3);

        comboCallPut = new QComboBox(centralWidget);
        comboCallPut->setObjectName(QString::fromUtf8("comboCallPut"));
        sizePolicy1.setHeightForWidth(comboCallPut->sizePolicy().hasHeightForWidth());
        comboCallPut->setSizePolicy(sizePolicy1);
        comboCallPut->setMinimumSize(QSize(75, 0));
        comboCallPut->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 4em;\n"
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
" QComboBox::drop-down {\n"
"\n"
"  "
                        "   subcontrol-origin: padding;\n"
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

        verticalLayout_3->addWidget(comboCallPut);


        horizontalLayout->addLayout(verticalLayout_3);

        cmdStart = new QPushButton(centralWidget);
        cmdStart->setObjectName(QString::fromUtf8("cmdStart"));
        sizePolicy.setHeightForWidth(cmdStart->sizePolicy().hasHeightForWidth());
        cmdStart->setSizePolicy(sizePolicy);
        cmdStart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 1px solid #8f8f91;\n"
"         border-radius: 1px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 130px;\n"
"         min-height: 18px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
""));

        horizontalLayout->addWidget(cmdStart);

        cmdHideTable = new QPushButton(centralWidget);
        cmdHideTable->setObjectName(QString::fromUtf8("cmdHideTable"));
        sizePolicy.setHeightForWidth(cmdHideTable->sizePolicy().hasHeightForWidth());
        cmdHideTable->setSizePolicy(sizePolicy);
        cmdHideTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 1px solid #8f8f91;\n"
"         border-radius: 1px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 130px;\n"
"         min-height: 18px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
""));

        horizontalLayout->addWidget(cmdHideTable);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        frametableDisplay = new QFrame(centralWidget);
        frametableDisplay->setObjectName(QString::fromUtf8("frametableDisplay"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frametableDisplay->sizePolicy().hasHeightForWidth());
        frametableDisplay->setSizePolicy(sizePolicy2);
        frametableDisplay->setFrameShape(QFrame::StyledPanel);
        frametableDisplay->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frametableDisplay);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableOptions = new QTableView(frametableDisplay);
        tableOptions->setObjectName(QString::fromUtf8("tableOptions"));
        tableOptions->setFrameShape(QFrame::Box);
        tableOptions->setFrameShadow(QFrame::Plain);
        tableOptions->setSortingEnabled(true);

        horizontalLayout_2->addWidget(tableOptions);


        verticalLayout_2->addWidget(frametableDisplay);

        LinePlot = new QCustomPlot(centralWidget);
        LinePlot->setObjectName(QString::fromUtf8("LinePlot"));
        sizePolicy2.setHeightForWidth(LinePlot->sizePolicy().hasHeightForWidth());
        LinePlot->setSizePolicy(sizePolicy2);
        LinePlot->setAutoFillBackground(false);

        verticalLayout_2->addWidget(LinePlot);

        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 7);

        horizontalLayout_3->addLayout(verticalLayout_2);

        ExpGraph->setCentralWidget(centralWidget);

        retranslateUi(ExpGraph);

        QMetaObject::connectSlotsByName(ExpGraph);
    } // setupUi

    void retranslateUi(QMainWindow *ExpGraph)
    {
        ExpGraph->setWindowTitle(QApplication::translate("ExpGraph", "C/P symbol plots of corresponding expiration ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExpGraph", "Symbol", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ExpGraph", "Call/Put", 0, QApplication::UnicodeUTF8));
        cmdStart->setText(QApplication::translate("ExpGraph", "Start", 0, QApplication::UnicodeUTF8));
        cmdHideTable->setText(QApplication::translate("ExpGraph", "Hide Table", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpGraph: public Ui_ExpGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPGRAPH_H
