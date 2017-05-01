/********************************************************************************
** Form generated from reading UI file 'OptionQuoter.ui'
**
** Created: Fri Nov 1 10:46:36 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONQUOTER_H
#define UI_OPTIONQUOTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionQuoter
{
public:
    QAction *action_Hide_Console;
    QAction *actionHide_Filters;
    QAction *actionHide_Option_Updates;
    QAction *actionSpx_Algo1_Neutral;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cmdShowSymbols;
    QPushButton *cmdStart;
    QPushButton *cmdPause;
    QPushButton *cmdAddExpression;
    QSpacerItem *horizontalSpacer;
    QTableView *tableViewOptions;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableViewExchanges;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *tableViewInputs;
    QTableView *tableViewOpenOrders;
    QFrame *frameFilters;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEditFilterExpression;
    QComboBox *comboColumnNames;
    QPushButton *cmdAddColumn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *cmdLoadExpression;
    QPushButton *cmdSaveExpression;
    QPushButton *cmdTestExpression;
    QTableView *TableExpressionTester;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEditFinalExpression;
    QListWidget *listWidgetConsole;
    QMenuBar *menuBar;
    QMenu *menuView;
    QMenu *menuInternal_Algorithms;

    void setupUi(QMainWindow *OptionQuoter)
    {
        if (OptionQuoter->objectName().isEmpty())
            OptionQuoter->setObjectName(QString::fromUtf8("OptionQuoter"));
        OptionQuoter->resize(586, 680);
        OptionQuoter->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"             background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                               stop:0 lightgray, stop:1 darkgray);\n"
"         }\n"
""));
        action_Hide_Console = new QAction(OptionQuoter);
        action_Hide_Console->setObjectName(QString::fromUtf8("action_Hide_Console"));
        action_Hide_Console->setCheckable(false);
        actionHide_Filters = new QAction(OptionQuoter);
        actionHide_Filters->setObjectName(QString::fromUtf8("actionHide_Filters"));
        actionHide_Option_Updates = new QAction(OptionQuoter);
        actionHide_Option_Updates->setObjectName(QString::fromUtf8("actionHide_Option_Updates"));
        actionSpx_Algo1_Neutral = new QAction(OptionQuoter);
        actionSpx_Algo1_Neutral->setObjectName(QString::fromUtf8("actionSpx_Algo1_Neutral"));
        centralWidget = new QWidget(OptionQuoter);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cmdShowSymbols = new QPushButton(layoutWidget);
        cmdShowSymbols->setObjectName(QString::fromUtf8("cmdShowSymbols"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmdShowSymbols->sizePolicy().hasHeightForWidth());
        cmdShowSymbols->setSizePolicy(sizePolicy);
        cmdShowSymbols->setMinimumSize(QSize(90, 21));
        cmdShowSymbols->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(cmdShowSymbols);

        cmdStart = new QPushButton(layoutWidget);
        cmdStart->setObjectName(QString::fromUtf8("cmdStart"));
        sizePolicy.setHeightForWidth(cmdStart->sizePolicy().hasHeightForWidth());
        cmdStart->setSizePolicy(sizePolicy);
        cmdStart->setMinimumSize(QSize(90, 21));
        cmdStart->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(cmdStart);

        cmdPause = new QPushButton(layoutWidget);
        cmdPause->setObjectName(QString::fromUtf8("cmdPause"));

        horizontalLayout->addWidget(cmdPause);

        cmdAddExpression = new QPushButton(layoutWidget);
        cmdAddExpression->setObjectName(QString::fromUtf8("cmdAddExpression"));
        sizePolicy.setHeightForWidth(cmdAddExpression->sizePolicy().hasHeightForWidth());
        cmdAddExpression->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cmdAddExpression);

        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        splitter->addWidget(layoutWidget);
        tableViewOptions = new QTableView(splitter);
        tableViewOptions->setObjectName(QString::fromUtf8("tableViewOptions"));
        tableViewOptions->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        tableViewOptions->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableViewOptions->setAlternatingRowColors(true);
        splitter->addWidget(tableViewOptions);
        tableViewOptions->verticalHeader()->setDefaultSectionSize(25);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));

        verticalLayout->addWidget(label);

        tableViewExchanges = new QTableView(layoutWidget1);
        tableViewExchanges->setObjectName(QString::fromUtf8("tableViewExchanges"));
        tableViewExchanges->setStyleSheet(QString::fromUtf8(""));
        tableViewExchanges->setFrameShape(QFrame::Box);
        tableViewExchanges->setFrameShadow(QFrame::Plain);
        tableViewExchanges->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableViewExchanges->setAlternatingRowColors(true);
        tableViewExchanges->horizontalHeader()->setDefaultSectionSize(55);
        tableViewExchanges->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout->addWidget(tableViewExchanges);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));

        verticalLayout_2->addWidget(label_2);

        tableViewInputs = new QTableView(layoutWidget1);
        tableViewInputs->setObjectName(QString::fromUtf8("tableViewInputs"));
        tableViewInputs->setFrameShape(QFrame::Box);
        tableViewInputs->setFrameShadow(QFrame::Plain);
        tableViewInputs->setAlternatingRowColors(true);
        tableViewInputs->horizontalHeader()->setDefaultSectionSize(70);
        tableViewInputs->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout_2->addWidget(tableViewInputs);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);
        splitter->addWidget(layoutWidget1);
        tableViewOpenOrders = new QTableView(splitter);
        tableViewOpenOrders->setObjectName(QString::fromUtf8("tableViewOpenOrders"));
        tableViewOpenOrders->setStyleSheet(QString::fromUtf8(""));
        tableViewOpenOrders->setFrameShape(QFrame::Box);
        tableViewOpenOrders->setFrameShadow(QFrame::Plain);
        tableViewOpenOrders->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableViewOpenOrders->setAlternatingRowColors(true);
        splitter->addWidget(tableViewOpenOrders);
        tableViewOpenOrders->horizontalHeader()->setDefaultSectionSize(85);
        tableViewOpenOrders->verticalHeader()->setDefaultSectionSize(18);
        frameFilters = new QFrame(splitter);
        frameFilters->setObjectName(QString::fromUtf8("frameFilters"));
        sizePolicy1.setHeightForWidth(frameFilters->sizePolicy().hasHeightForWidth());
        frameFilters->setSizePolicy(sizePolicy1);
        frameFilters->setFrameShape(QFrame::Box);
        frameFilters->setFrameShadow(QFrame::Plain);
        frameFilters->setLineWidth(1);
        frameFilters->setMidLineWidth(1);
        horizontalLayout_3 = new QHBoxLayout(frameFilters);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(frameFilters);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEditFilterExpression = new QLineEdit(frameFilters);
        lineEditFilterExpression->setObjectName(QString::fromUtf8("lineEditFilterExpression"));

        horizontalLayout_5->addWidget(lineEditFilterExpression);

        comboColumnNames = new QComboBox(frameFilters);
        comboColumnNames->setObjectName(QString::fromUtf8("comboColumnNames"));

        horizontalLayout_5->addWidget(comboColumnNames);

        cmdAddColumn = new QPushButton(frameFilters);
        cmdAddColumn->setObjectName(QString::fromUtf8("cmdAddColumn"));
        sizePolicy.setHeightForWidth(cmdAddColumn->sizePolicy().hasHeightForWidth());
        cmdAddColumn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(cmdAddColumn);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(frameFilters);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));

        horizontalLayout_4->addWidget(label_4);

        cmdLoadExpression = new QPushButton(frameFilters);
        cmdLoadExpression->setObjectName(QString::fromUtf8("cmdLoadExpression"));
        sizePolicy.setHeightForWidth(cmdLoadExpression->sizePolicy().hasHeightForWidth());
        cmdLoadExpression->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(cmdLoadExpression);

        cmdSaveExpression = new QPushButton(frameFilters);
        cmdSaveExpression->setObjectName(QString::fromUtf8("cmdSaveExpression"));
        sizePolicy.setHeightForWidth(cmdSaveExpression->sizePolicy().hasHeightForWidth());
        cmdSaveExpression->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(cmdSaveExpression);

        cmdTestExpression = new QPushButton(frameFilters);
        cmdTestExpression->setObjectName(QString::fromUtf8("cmdTestExpression"));
        sizePolicy.setHeightForWidth(cmdTestExpression->sizePolicy().hasHeightForWidth());
        cmdTestExpression->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(cmdTestExpression);


        verticalLayout_3->addLayout(horizontalLayout_4);

        TableExpressionTester = new QTableView(frameFilters);
        TableExpressionTester->setObjectName(QString::fromUtf8("TableExpressionTester"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TableExpressionTester->sizePolicy().hasHeightForWidth());
        TableExpressionTester->setSizePolicy(sizePolicy3);
        TableExpressionTester->setMinimumSize(QSize(0, 90));
        TableExpressionTester->setMaximumSize(QSize(16777215, 70));
        TableExpressionTester->setFrameShape(QFrame::Box);
        TableExpressionTester->setFrameShadow(QFrame::Plain);
        TableExpressionTester->setAlternatingRowColors(true);
        TableExpressionTester->setGridStyle(Qt::DashLine);
        TableExpressionTester->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout_3->addWidget(TableExpressionTester);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(frameFilters);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));

        horizontalLayout_6->addWidget(label_5);

        lineEditFinalExpression = new QLineEdit(frameFilters);
        lineEditFinalExpression->setObjectName(QString::fromUtf8("lineEditFinalExpression"));

        horizontalLayout_6->addWidget(lineEditFinalExpression);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_3->addLayout(verticalLayout_3);

        splitter->addWidget(frameFilters);
        listWidgetConsole = new QListWidget(splitter);
        listWidgetConsole->setObjectName(QString::fromUtf8("listWidgetConsole"));
        sizePolicy3.setHeightForWidth(listWidgetConsole->sizePolicy().hasHeightForWidth());
        listWidgetConsole->setSizePolicy(sizePolicy3);
        listWidgetConsole->setStyleSheet(QString::fromUtf8(""));
        listWidgetConsole->setFrameShape(QFrame::Box);
        listWidgetConsole->setFrameShadow(QFrame::Plain);
        listWidgetConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        splitter->addWidget(listWidgetConsole);

        horizontalLayout_7->addWidget(splitter);

        OptionQuoter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OptionQuoter);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 18));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuInternal_Algorithms = new QMenu(menuBar);
        menuInternal_Algorithms->setObjectName(QString::fromUtf8("menuInternal_Algorithms"));
        OptionQuoter->setMenuBar(menuBar);

        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuInternal_Algorithms->menuAction());
        menuView->addAction(actionHide_Filters);
        menuView->addAction(action_Hide_Console);
        menuView->addAction(actionHide_Option_Updates);
        menuInternal_Algorithms->addAction(actionSpx_Algo1_Neutral);

        retranslateUi(OptionQuoter);

        QMetaObject::connectSlotsByName(OptionQuoter);
    } // setupUi

    void retranslateUi(QMainWindow *OptionQuoter)
    {
        OptionQuoter->setWindowTitle(QApplication::translate("OptionQuoter", "OptionQuoter", 0, QApplication::UnicodeUTF8));
        action_Hide_Console->setText(QApplication::translate("OptionQuoter", "Hide Output", 0, QApplication::UnicodeUTF8));
        actionHide_Filters->setText(QApplication::translate("OptionQuoter", "Hide Filter", 0, QApplication::UnicodeUTF8));
        actionHide_Option_Updates->setText(QApplication::translate("OptionQuoter", "Hide Updates", 0, QApplication::UnicodeUTF8));
        actionSpx_Algo1_Neutral->setText(QApplication::translate("OptionQuoter", "Spx_Algo1_Neutral", 0, QApplication::UnicodeUTF8));
        cmdShowSymbols->setText(QApplication::translate("OptionQuoter", "Load Symbols", 0, QApplication::UnicodeUTF8));
        cmdStart->setText(QApplication::translate("OptionQuoter", "Start", 0, QApplication::UnicodeUTF8));
        cmdPause->setText(QApplication::translate("OptionQuoter", "Pause", 0, QApplication::UnicodeUTF8));
        cmdAddExpression->setText(QApplication::translate("OptionQuoter", "Add Expression", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionQuoter", "Exchanges", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionQuoter", "Inputs", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OptionQuoter", "Criteria", 0, QApplication::UnicodeUTF8));
        cmdAddColumn->setText(QApplication::translate("OptionQuoter", "Add Column", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionQuoter", "Expression Tester", 0, QApplication::UnicodeUTF8));
        cmdLoadExpression->setText(QApplication::translate("OptionQuoter", "Load Expression", 0, QApplication::UnicodeUTF8));
        cmdSaveExpression->setText(QApplication::translate("OptionQuoter", "Save Expression", 0, QApplication::UnicodeUTF8));
        cmdTestExpression->setText(QApplication::translate("OptionQuoter", "Test Expression", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OptionQuoter", "Selected Expression", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("OptionQuoter", "View", 0, QApplication::UnicodeUTF8));
        menuInternal_Algorithms->setTitle(QApplication::translate("OptionQuoter", "Internal Algorithms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionQuoter: public Ui_OptionQuoter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONQUOTER_H
