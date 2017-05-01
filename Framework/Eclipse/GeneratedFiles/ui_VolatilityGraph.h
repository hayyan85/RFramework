/********************************************************************************
** Form generated from reading UI file 'VolatilityGraph.ui'
**
** Created: Wed Oct 23 11:14:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLATILITYGRAPH_H
#define UI_VOLATILITYGRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_VolatilityGraph
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboDistinctSymbol;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboExpirationDate;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *comboCallPut;
    QPushButton *cmdStart;
    QPushButton *cmdHideTable;
    QCheckBox *checkBoxVolatility;
    QCheckBox *checkBoxVolume;
    QCheckBox *checkBoxTrades;
    QCheckBox *checkBoxOpenInterest;
    QSpacerItem *horizontalSpacer;
    QFrame *frametableDisplay;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableOptions;
    QCustomPlot *LinePlot;
    QCustomPlot *VolumePlot;
    QCustomPlot *TradesPlot;
    QCustomPlot *OInterestPlot;

    void setupUi(QWidget *VolatilityGraph)
    {
        if (VolatilityGraph->objectName().isEmpty())
            VolatilityGraph->setObjectName(QString::fromUtf8("VolatilityGraph"));
        VolatilityGraph->resize(975, 879);
        horizontalLayout_3 = new QHBoxLayout(VolatilityGraph);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(VolatilityGraph);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        comboDistinctSymbol = new QComboBox(VolatilityGraph);
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

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(VolatilityGraph);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);

        comboExpirationDate = new QComboBox(VolatilityGraph);
        comboExpirationDate->setObjectName(QString::fromUtf8("comboExpirationDate"));
        sizePolicy1.setHeightForWidth(comboExpirationDate->sizePolicy().hasHeightForWidth());
        comboExpirationDate->setSizePolicy(sizePolicy1);
        comboExpirationDate->setMinimumSize(QSize(75, 0));
        comboExpirationDate->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
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

        verticalLayout_2->addWidget(comboExpirationDate);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(VolatilityGraph);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_3);

        comboCallPut = new QComboBox(VolatilityGraph);
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

        cmdStart = new QPushButton(VolatilityGraph);
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

        cmdHideTable = new QPushButton(VolatilityGraph);
        cmdHideTable->setObjectName(QString::fromUtf8("cmdHideTable"));
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

        checkBoxVolatility = new QCheckBox(VolatilityGraph);
        checkBoxVolatility->setObjectName(QString::fromUtf8("checkBoxVolatility"));
        sizePolicy.setHeightForWidth(checkBoxVolatility->sizePolicy().hasHeightForWidth());
        checkBoxVolatility->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBoxVolatility);

        checkBoxVolume = new QCheckBox(VolatilityGraph);
        checkBoxVolume->setObjectName(QString::fromUtf8("checkBoxVolume"));
        sizePolicy.setHeightForWidth(checkBoxVolume->sizePolicy().hasHeightForWidth());
        checkBoxVolume->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBoxVolume);

        checkBoxTrades = new QCheckBox(VolatilityGraph);
        checkBoxTrades->setObjectName(QString::fromUtf8("checkBoxTrades"));
        sizePolicy.setHeightForWidth(checkBoxTrades->sizePolicy().hasHeightForWidth());
        checkBoxTrades->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBoxTrades);

        checkBoxOpenInterest = new QCheckBox(VolatilityGraph);
        checkBoxOpenInterest->setObjectName(QString::fromUtf8("checkBoxOpenInterest"));
        sizePolicy.setHeightForWidth(checkBoxOpenInterest->sizePolicy().hasHeightForWidth());
        checkBoxOpenInterest->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBoxOpenInterest);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);

        frametableDisplay = new QFrame(VolatilityGraph);
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


        verticalLayout_4->addWidget(frametableDisplay);

        LinePlot = new QCustomPlot(VolatilityGraph);
        LinePlot->setObjectName(QString::fromUtf8("LinePlot"));
        sizePolicy2.setHeightForWidth(LinePlot->sizePolicy().hasHeightForWidth());
        LinePlot->setSizePolicy(sizePolicy2);
        LinePlot->setAutoFillBackground(false);

        verticalLayout_4->addWidget(LinePlot);

        VolumePlot = new QCustomPlot(VolatilityGraph);
        VolumePlot->setObjectName(QString::fromUtf8("VolumePlot"));
        sizePolicy2.setHeightForWidth(VolumePlot->sizePolicy().hasHeightForWidth());
        VolumePlot->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(VolumePlot);

        TradesPlot = new QCustomPlot(VolatilityGraph);
        TradesPlot->setObjectName(QString::fromUtf8("TradesPlot"));
        sizePolicy2.setHeightForWidth(TradesPlot->sizePolicy().hasHeightForWidth());
        TradesPlot->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(TradesPlot);

        OInterestPlot = new QCustomPlot(VolatilityGraph);
        OInterestPlot->setObjectName(QString::fromUtf8("OInterestPlot"));
        sizePolicy2.setHeightForWidth(OInterestPlot->sizePolicy().hasHeightForWidth());
        OInterestPlot->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(OInterestPlot);

        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 3);
        verticalLayout_4->setStretch(3, 1);
        verticalLayout_4->setStretch(4, 1);
        verticalLayout_4->setStretch(5, 1);

        horizontalLayout_3->addLayout(verticalLayout_4);


        retranslateUi(VolatilityGraph);

        QMetaObject::connectSlotsByName(VolatilityGraph);
    } // setupUi

    void retranslateUi(QWidget *VolatilityGraph)
    {
        VolatilityGraph->setWindowTitle(QApplication::translate("VolatilityGraph", "VolatilityGraph", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VolatilityGraph", "Symbol", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VolatilityGraph", "Expiration", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VolatilityGraph", "Call/Put", 0, QApplication::UnicodeUTF8));
        cmdStart->setText(QApplication::translate("VolatilityGraph", "Start", 0, QApplication::UnicodeUTF8));
        cmdHideTable->setText(QApplication::translate("VolatilityGraph", "ShowTable", 0, QApplication::UnicodeUTF8));
        checkBoxVolatility->setText(QApplication::translate("VolatilityGraph", "Volatility Plot", 0, QApplication::UnicodeUTF8));
        checkBoxVolume->setText(QApplication::translate("VolatilityGraph", "Volume Plot", 0, QApplication::UnicodeUTF8));
        checkBoxTrades->setText(QApplication::translate("VolatilityGraph", "Trades Plot", 0, QApplication::UnicodeUTF8));
        checkBoxOpenInterest->setText(QApplication::translate("VolatilityGraph", "Open Interest Plot", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VolatilityGraph: public Ui_VolatilityGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLATILITYGRAPH_H
