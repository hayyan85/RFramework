/********************************************************************************
** Form generated from reading UI file 'OptionScanner.ui'
**
** Created: Wed Oct 23 11:14:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSCANNER_H
#define UI_OPTIONSCANNER_H

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

class Ui_OptionScanner
{
public:
    QAction *actionSave_Layout;
    QAction *actionLoad_Layout;
    QAction *actionTestLayout;
    QAction *actionAuto_Refresh;
    QAction *actionTestLayout_2;
    QAction *actionDisable_Auto_Refresh;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditSearch;
    QPushButton *cmdOptions;
    QPushButton *cmdConnect;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QLabel *label;
    QTableView *tableViewColumnsFilter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBoxIndicatorName;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBoxOperation;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEditPassValue;
    QFrame *frame_extravar;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditPassValue_ext1;
    QFrame *line;
    QLineEdit *lineEditPassValue_ext2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *cmdRemoveSelectedFilter;
    QPushButton *cmdAddFilter;
    QListWidget *listWidgetFilters;
    QTableView *tableSubscription;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuRefresh;

    void setupUi(QMainWindow *OptionScanner)
    {
        if (OptionScanner->objectName().isEmpty())
            OptionScanner->setObjectName(QString::fromUtf8("OptionScanner"));
        OptionScanner->resize(1013, 888);
        actionSave_Layout = new QAction(OptionScanner);
        actionSave_Layout->setObjectName(QString::fromUtf8("actionSave_Layout"));
        actionLoad_Layout = new QAction(OptionScanner);
        actionLoad_Layout->setObjectName(QString::fromUtf8("actionLoad_Layout"));
        actionTestLayout = new QAction(OptionScanner);
        actionTestLayout->setObjectName(QString::fromUtf8("actionTestLayout"));
        actionAuto_Refresh = new QAction(OptionScanner);
        actionAuto_Refresh->setObjectName(QString::fromUtf8("actionAuto_Refresh"));
        actionTestLayout_2 = new QAction(OptionScanner);
        actionTestLayout_2->setObjectName(QString::fromUtf8("actionTestLayout_2"));
        actionDisable_Auto_Refresh = new QAction(OptionScanner);
        actionDisable_Auto_Refresh->setObjectName(QString::fromUtf8("actionDisable_Auto_Refresh"));
        centralWidget = new QWidget(OptionScanner);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(8);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setKerning(true);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEditSearch = new QLineEdit(centralWidget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));
        sizePolicy.setHeightForWidth(lineEditSearch->sizePolicy().hasHeightForWidth());
        lineEditSearch->setSizePolicy(sizePolicy);
        lineEditSearch->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
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

        horizontalLayout_2->addWidget(lineEditSearch);

        cmdOptions = new QPushButton(centralWidget);
        cmdOptions->setObjectName(QString::fromUtf8("cmdOptions"));
        cmdOptions->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(cmdOptions);

        cmdConnect = new QPushButton(centralWidget);
        cmdConnect->setObjectName(QString::fromUtf8("cmdConnect"));
        cmdConnect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(cmdConnect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"/*border-top-left-radius: 10px;*/\n"
"/*border-top-right-radius: 10px;*/\n"
"/*border: 1px solid black;*/\n"
"	background-color: qconicalgradient(cx:1, cy:0, angle:310.4, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        splitter = new QSplitter(frame);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setStyleSheet(QString::fromUtf8(""));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-top: 1px solid black;\n"
"border-left: 1px solid black;\n"
"border-right: 1px solid black;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"/*padding-bottom: 10px; /*Increases the hieght of the label*/\n"
"font: bold 12px;"));
        splitter->addWidget(label);
        tableViewColumnsFilter = new QTableView(splitter);
        tableViewColumnsFilter->setObjectName(QString::fromUtf8("tableViewColumnsFilter"));
        sizePolicy.setHeightForWidth(tableViewColumnsFilter->sizePolicy().hasHeightForWidth());
        tableViewColumnsFilter->setSizePolicy(sizePolicy);
        tableViewColumnsFilter->setStyleSheet(QString::fromUtf8("border: none;\n"
"/*border-bottom-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;*/\n"
"border-top: 1px solid black;\n"
"border-left: 1px solid black;\n"
"border-right: 1px solid black;\n"
"border-bottom: 1px solid black;\n"
"background-color: qlineargradient(spread:pad, x1:1.002273, y1:0.068, x2:0.392318, y2:0.614, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(255, 255, 255, 255));\n"
"/*margin-bottom: 3ex; /* leave space at the top for the title */\n"
""));
        tableViewColumnsFilter->setFrameShape(QFrame::Box);
        tableViewColumnsFilter->setFrameShadow(QFrame::Plain);
        tableViewColumnsFilter->setAlternatingRowColors(true);
        tableViewColumnsFilter->setGridStyle(Qt::DashLine);
        splitter->addWidget(tableViewColumnsFilter);
        tableViewColumnsFilter->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-top: 1px solid black;\n"
"border-left: 1px solid black;\n"
"border-right: 1px solid black;\n"
"border-top: 1px solid black;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"font: bold 12px;"));

        horizontalLayout_10->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        comboBoxIndicatorName = new QComboBox(layoutWidget);
        comboBoxIndicatorName->setObjectName(QString::fromUtf8("comboBoxIndicatorName"));
        sizePolicy.setHeightForWidth(comboBoxIndicatorName->sizePolicy().hasHeightForWidth());
        comboBoxIndicatorName->setSizePolicy(sizePolicy);
        comboBoxIndicatorName->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
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

        horizontalLayout_10->addWidget(comboBoxIndicatorName);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-top: 1px solid black;\n"
"border-left: 1px solid black;\n"
"border-right: 1px solid black;\n"
"border-top: 1px solid black;\n"
"border-top: 1px solid black;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"font: bold 12px;"));

        horizontalLayout_11->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        comboBoxOperation = new QComboBox(layoutWidget1);
        comboBoxOperation->setObjectName(QString::fromUtf8("comboBoxOperation"));
        sizePolicy.setHeightForWidth(comboBoxOperation->sizePolicy().hasHeightForWidth());
        comboBoxOperation->setSizePolicy(sizePolicy);
        comboBoxOperation->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
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

        horizontalLayout_11->addWidget(comboBoxOperation);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-top: 1px solid black;\n"
"border-left: 1px solid black;\n"
"border-right: 1px solid black;\n"
"border-top: 1px solid black;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"font: bold 12px;"));

        horizontalLayout_12->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(57, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        lineEditPassValue = new QLineEdit(layoutWidget2);
        lineEditPassValue->setObjectName(QString::fromUtf8("lineEditPassValue"));
        sizePolicy.setHeightForWidth(lineEditPassValue->sizePolicy().hasHeightForWidth());
        lineEditPassValue->setSizePolicy(sizePolicy);
        lineEditPassValue->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
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

        horizontalLayout_12->addWidget(lineEditPassValue);

        frame_extravar = new QFrame(layoutWidget2);
        frame_extravar->setObjectName(QString::fromUtf8("frame_extravar"));
        sizePolicy.setHeightForWidth(frame_extravar->sizePolicy().hasHeightForWidth());
        frame_extravar->setSizePolicy(sizePolicy);
        frame_extravar->setFrameShape(QFrame::NoFrame);
        frame_extravar->setFrameShadow(QFrame::Plain);
        horizontalLayout_4 = new QHBoxLayout(frame_extravar);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEditPassValue_ext1 = new QLineEdit(frame_extravar);
        lineEditPassValue_ext1->setObjectName(QString::fromUtf8("lineEditPassValue_ext1"));
        sizePolicy.setHeightForWidth(lineEditPassValue_ext1->sizePolicy().hasHeightForWidth());
        lineEditPassValue_ext1->setSizePolicy(sizePolicy);
        lineEditPassValue_ext1->setMinimumSize(QSize(36, 0));
        lineEditPassValue_ext1->setMaximumSize(QSize(62, 16777215));
        lineEditPassValue_ext1->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 3em;\n"
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

        horizontalLayout_4->addWidget(lineEditPassValue_ext1);

        line = new QFrame(frame_extravar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        lineEditPassValue_ext2 = new QLineEdit(frame_extravar);
        lineEditPassValue_ext2->setObjectName(QString::fromUtf8("lineEditPassValue_ext2"));
        sizePolicy.setHeightForWidth(lineEditPassValue_ext2->sizePolicy().hasHeightForWidth());
        lineEditPassValue_ext2->setSizePolicy(sizePolicy);
        lineEditPassValue_ext2->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 1em;\n"
" max-width: 3em;\n"
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

        horizontalLayout_4->addWidget(lineEditPassValue_ext2);


        horizontalLayout_12->addWidget(frame_extravar);

        splitter->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        cmdRemoveSelectedFilter = new QPushButton(layoutWidget3);
        cmdRemoveSelectedFilter->setObjectName(QString::fromUtf8("cmdRemoveSelectedFilter"));
        sizePolicy.setHeightForWidth(cmdRemoveSelectedFilter->sizePolicy().hasHeightForWidth());
        cmdRemoveSelectedFilter->setSizePolicy(sizePolicy);
        cmdRemoveSelectedFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_13->addWidget(cmdRemoveSelectedFilter);

        cmdAddFilter = new QPushButton(layoutWidget3);
        cmdAddFilter->setObjectName(QString::fromUtf8("cmdAddFilter"));
        sizePolicy.setHeightForWidth(cmdAddFilter->sizePolicy().hasHeightForWidth());
        cmdAddFilter->setSizePolicy(sizePolicy);
        cmdAddFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_13->addWidget(cmdAddFilter);

        splitter->addWidget(layoutWidget3);
        listWidgetFilters = new QListWidget(splitter);
        listWidgetFilters->setObjectName(QString::fromUtf8("listWidgetFilters"));
        sizePolicy.setHeightForWidth(listWidgetFilters->sizePolicy().hasHeightForWidth());
        listWidgetFilters->setSizePolicy(sizePolicy);
        listWidgetFilters->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.102273, y1:0.068, x2:0.392318, y2:0.614, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(255, 255, 255, 255));"));
        listWidgetFilters->setFrameShape(QFrame::Box);
        listWidgetFilters->setFrameShadow(QFrame::Plain);
        listWidgetFilters->setAlternatingRowColors(true);
        splitter->addWidget(listWidgetFilters);

        horizontalLayout_3->addWidget(splitter);


        horizontalLayout->addWidget(frame);

        tableSubscription = new QTableView(centralWidget);
        tableSubscription->setObjectName(QString::fromUtf8("tableSubscription"));
        tableSubscription->setFrameShape(QFrame::Box);
        tableSubscription->setFrameShadow(QFrame::Plain);
        tableSubscription->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableSubscription->setAutoScroll(false);
        tableSubscription->setAlternatingRowColors(true);
        tableSubscription->setWordWrap(false);
        tableSubscription->verticalHeader()->setVisible(false);
        tableSubscription->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout->addWidget(tableSubscription);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout);

        OptionScanner->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OptionScanner);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 18));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuRefresh = new QMenu(menuBar);
        menuRefresh->setObjectName(QString::fromUtf8("menuRefresh"));
        OptionScanner->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuRefresh->menuAction());
        menuOptions->addAction(actionSave_Layout);
        menuOptions->addSeparator();
        menuOptions->addAction(actionLoad_Layout);
        menuRefresh->addAction(actionAuto_Refresh);
        menuRefresh->addAction(actionDisable_Auto_Refresh);

        retranslateUi(OptionScanner);

        QMetaObject::connectSlotsByName(OptionScanner);
    } // setupUi

    void retranslateUi(QMainWindow *OptionScanner)
    {
        OptionScanner->setWindowTitle(QApplication::translate("OptionScanner", "OptionScanner", 0, QApplication::UnicodeUTF8));
        actionSave_Layout->setText(QApplication::translate("OptionScanner", "Save Layout", 0, QApplication::UnicodeUTF8));
        actionLoad_Layout->setText(QApplication::translate("OptionScanner", "Load Layout", 0, QApplication::UnicodeUTF8));
        actionTestLayout->setText(QApplication::translate("OptionScanner", "TestLayout", 0, QApplication::UnicodeUTF8));
        actionAuto_Refresh->setText(QApplication::translate("OptionScanner", "Enable Auto Refresh", 0, QApplication::UnicodeUTF8));
        actionTestLayout_2->setText(QApplication::translate("OptionScanner", "TestLayout", 0, QApplication::UnicodeUTF8));
        actionDisable_Auto_Refresh->setText(QApplication::translate("OptionScanner", "Disable Auto Refresh", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionScanner", "Search Symbol", 0, QApplication::UnicodeUTF8));
        cmdOptions->setText(QApplication::translate("OptionScanner", "Hide Options", 0, QApplication::UnicodeUTF8));
        cmdConnect->setText(QApplication::translate("OptionScanner", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionScanner", "Select column(s) to hide", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionScanner", "Select Indicator", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OptionScanner", "Binary Operaton", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OptionScanner", "Pass Value", 0, QApplication::UnicodeUTF8));
        cmdRemoveSelectedFilter->setText(QApplication::translate("OptionScanner", "Remove Filter", 0, QApplication::UnicodeUTF8));
        cmdAddFilter->setText(QApplication::translate("OptionScanner", "Add Filter", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("OptionScanner", "Options", 0, QApplication::UnicodeUTF8));
        menuRefresh->setTitle(QApplication::translate("OptionScanner", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionScanner: public Ui_OptionScanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSCANNER_H
