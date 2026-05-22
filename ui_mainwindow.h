/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actions_SQL;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *USER;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *lineEdit_ComCode;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QLineEdit *lineEdit_OnlineCode;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QLineEdit *lineEdit_SerialN;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *ChB_date;
    QLabel *led_sql_4;
    QDateTimeEdit *dateEdit_Begin;
    QLabel *led_sql_2;
    QDateTimeEdit *dateEdit_End;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_Name;
    QLabel *label_7;
    QLineEdit *lineEdit_Condition;
    QLabel *label_8;
    QComboBox *comboBox_Result;
    QLabel *label_9;
    QComboBox *comboBox_Status;
    QPushButton *Btn_Find;
    QPushButton *pushButton;
    QFrame *frame_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QTableView *tableView_Work;
    QSpacerItem *horizontalSpacer_9;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QTableView *tableView_SJ1;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QTableView *tableView_JL;
    QWidget *tab_5;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QTableView *tableView_FS2;
    QTableView *tableView_FS1;
    QWidget *tab_6;
    QGridLayout *gridLayout_9;
    QTableView *tableView_DJ1;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Btn_PageUp;
    QSpinBox *CurPage;
    QLabel *label_4;
    QSpinBox *CurPage_2;
    QPushButton *Btn_PageDown;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_14;
    QSpinBox *allPage;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1251, 1242);
        MainWindow->setStyleSheet(QString::fromUtf8("/* -------------------------- \345\205\250\345\261\200\345\237\272\347\241\200\346\240\267\345\274\217 -------------------------- */\n"
"QWidget {\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 13px;\n"
"    color: #2c3e50;\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"/* -------------------------- \346\240\207\351\242\230\346\240\217 -------------------------- */\n"
"QFrame#frame_title {\n"
"    background-color: #d1e3f8;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QLabel#label_title {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #2d3748;\n"
"}\n"
"\n"
"/* -------------------------- \346\240\207\347\255\276\346\226\207\345\255\227 -------------------------- */\n"
"QLabel {\n"
"    color: #34495e;\n"
"}\n"
"\n"
"/* -------------------------- \350\276\223\345\205\245\346\241\206 / \346\227\245\346\234\237\346\241\206 / \346\227\266\351\227\264\346\241\206 -------------------------- */\n"
"QLineEdit,\n"
"QDateEdit,\n"
"QTimeEdit,\n"
"QSpinBox {\n"
"    background-color: #ff"
                        "ffff;\n"
"    border: 1px solid #cbd5e1;\n"
"    border-radius: 4px;\n"
"    padding: 4px 8px;\n"
"    min-height: 22px;\n"
"}\n"
"\n"
"QLineEdit:focus,\n"
"QDateEdit:focus,\n"
"QTimeEdit:focus {\n"
"    border: 1px solid #3b82f6;\n"
"    background-color: #eff6ff;\n"
"}\n"
"\n"
"/* -------------------------- \344\270\213\346\213\211\346\241\206 -------------------------- */\n"
"QComboBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cbd5e1;\n"
"    border-radius: 4px;\n"
"    padding: 4px 8px;\n"
"    min-height: 22px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow_down);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cbd5e1;\n"
"    selection-background-color: #3b82f6;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"/* -------------------------- \345\244\215\351\200\211\346\241\206 -----------------------"
                        "--- */\n"
"QCheckBox {\n"
"    spacing: 6px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border: 1px solid #cbd5e1;\n"
"    border-radius: 3px;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #3b82f6;\n"
"    border-color: #3b82f6;\n"
"    image: url(:/icons/check);\n"
"}\n"
"\n"
"/* -------------------------- \346\214\211\351\222\256\357\274\210\344\270\273\346\214\211\351\222\256\357\274\211 -------------------------- */\n"
"QPushButton {\n"
"    background-color: #3b82f6;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 6px 14px;\n"
"    min-height: 26px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2563eb;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1d4ed8;\n"
"}\n"
"\n"
"/* -------------------------- \347\201\260\350\211\262\346\214\211\351\222\256\357\274\210\350\276\205\345\212\251\346\214\211\351"
                        "\222\256\357\274\211 -------------------------- */\n"
"QPushButton#btn_gray {\n"
"    background-color: #64748b;\n"
"}\n"
"\n"
"QPushButton#btn_gray:hover {\n"
"    background-color: #475569;\n"
"}\n"
"\n"
"/* -------------------------- TabWidget \346\240\207\347\255\276\351\241\265 -------------------------- */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #e2e8f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 6px;\n"
"    top: -1px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #e2e8f0;\n"
"    padding: 8px 16px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #ffffff;\n"
"    color: #2563eb;\n"
"    font-weight: bold;\n"
"    border-bottom: 2px solid #2563eb;\n"
"}\n"
"\n"
"/* -------------------------- \350\241\250\346\240\274 -------------------------- */\n"
"QTableView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    gridline-color:"
                        " #f1f5f9;\n"
"    alternate-background-color: #f8fafc;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #dbeafe;\n"
"    color: #1e3a8a;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    border: 1px solid #e2e8f0;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    color: #334155;\n"
"}\n"
"\n"
"/* --------------------------  \346\273\232\345\212\250\346\235\241 -------------------------- */\n"
"QScrollBar:vertical {\n"
"    width: 12px;\n"
"    background-color: #f8fafc;\n"
"    margin: 6px 2px 6px 2px;  /* \345\205\263\351\224\256\357\274\232\344\270\212\344\270\213\345\267\246\345\217\263\347\225\231\347\231\275\357\274\214\344\270\215\350\264\264\350\276\271\347\225\214 */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #94a3b8;\n"
"    border-radius: 4px;\n"
"    min-height: 30px;        /* \351\230\262\346\255\242\346\273\221\345\235\227\345\244"
                        "\252\346\211\201 */\n"
"    margin: 0px 3px 0px 3px; /* \345\267\246\345\217\263\345\206\205\350\276\271\350\267\235\357\274\214\344\270\215\350\264\264\350\276\271 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color: #64748b;\n"
"}\n"
"\n"
"/* \346\260\264\345\271\263\346\273\232\345\212\250\346\235\241\357\274\210\345\217\257\351\200\211\357\274\214\350\207\252\345\212\250\347\273\237\344\270\200\357\274\211 */\n"
"QScrollBar:horizontal {\n"
"    height: 12px;\n"
"    background-color: #f8fafc;\n"
"    margin: 2px 6px 2px 6px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #94a3b8;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    margin: 3px 0px 3px 0px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"    border: none;\n"
"}"));
        actions_SQL = new QAction(MainWindow);
        actions_SQL->setObjectName(QString::fromUtf8("actions_SQL"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 102));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 5, 8, 1, 1);

        USER = new QToolButton(frame);
        USER->setObjectName(QString::fromUtf8("USER"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/user.svg"), QSize(), QIcon::Normal, QIcon::Off);
        USER->setIcon(icon);
        USER->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        USER->setAutoRaise(false);

        gridLayout_4->addWidget(USER, 5, 11, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 91));
        label_10->setMaximumSize(QSize(260, 270));
        label_10->setStyleSheet(QString::fromUtf8("padding:0px;\n"
"width:30px;\n"
"hight:30px;"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/PINSEN.png")));

        gridLayout_4->addWidget(label_10, 5, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 5, 10, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 5, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 5, 7, 1, 1);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_4->addWidget(widget, 5, 5, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 30pt \"Arial\";\n"
""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 5, 4, 1, 1);


        verticalLayout->addWidget(frame);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 144));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        label_2->setFont(font1);

        horizontalLayout_9->addWidget(label_2);

        lineEdit_ComCode = new QLineEdit(groupBox);
        lineEdit_ComCode->setObjectName(QString::fromUtf8("lineEdit_ComCode"));
        lineEdit_ComCode->setFont(font1);

        horizontalLayout_9->addWidget(lineEdit_ComCode);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));

        horizontalLayout_9->addLayout(horizontalLayout_10);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_9->addWidget(label_3);

        lineEdit_OnlineCode = new QLineEdit(groupBox);
        lineEdit_OnlineCode->setObjectName(QString::fromUtf8("lineEdit_OnlineCode"));
        lineEdit_OnlineCode->setFont(font1);

        horizontalLayout_9->addWidget(lineEdit_OnlineCode);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));

        horizontalLayout_9->addLayout(horizontalLayout_11);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_9->addWidget(label_5);

        lineEdit_SerialN = new QLineEdit(groupBox);
        lineEdit_SerialN->setObjectName(QString::fromUtf8("lineEdit_SerialN"));
        lineEdit_SerialN->setFont(font1);

        horizontalLayout_9->addWidget(lineEdit_SerialN);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));

        horizontalLayout->addLayout(horizontalLayout_12);

        ChB_date = new QCheckBox(groupBox);
        ChB_date->setObjectName(QString::fromUtf8("ChB_date"));

        horizontalLayout->addWidget(ChB_date);

        led_sql_4 = new QLabel(groupBox);
        led_sql_4->setObjectName(QString::fromUtf8("led_sql_4"));
        led_sql_4->setMinimumSize(QSize(41, 0));
        led_sql_4->setMaximumSize(QSize(41, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        font2.setWeight(50);
        led_sql_4->setFont(font2);
        led_sql_4->setStyleSheet(QString::fromUtf8("padding:=10px;"));
        led_sql_4->setFrameShape(QFrame::NoFrame);
        led_sql_4->setTextFormat(Qt::AutoText);
        led_sql_4->setAlignment(Qt::AlignCenter);
        led_sql_4->setMargin(-5);

        horizontalLayout->addWidget(led_sql_4);

        dateEdit_Begin = new QDateTimeEdit(groupBox);
        dateEdit_Begin->setObjectName(QString::fromUtf8("dateEdit_Begin"));
        dateEdit_Begin->setFont(font1);
        dateEdit_Begin->setDate(QDate(2024, 8, 1));
        dateEdit_Begin->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_Begin);

        led_sql_2 = new QLabel(groupBox);
        led_sql_2->setObjectName(QString::fromUtf8("led_sql_2"));
        led_sql_2->setMinimumSize(QSize(31, 31));
        led_sql_2->setMaximumSize(QSize(31, 31));
        led_sql_2->setFont(font2);
        led_sql_2->setFrameShape(QFrame::NoFrame);
        led_sql_2->setTextFormat(Qt::AutoText);
        led_sql_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(led_sql_2);

        dateEdit_End = new QDateTimeEdit(groupBox);
        dateEdit_End->setObjectName(QString::fromUtf8("dateEdit_End"));
        dateEdit_End->setFont(font1);
        dateEdit_End->setDate(QDate(2025, 1, 8));
        dateEdit_End->setTime(QTime(23, 59, 59));
        dateEdit_End->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_End);


        horizontalLayout_9->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_3->addWidget(label_6);

        lineEdit_Name = new QLineEdit(groupBox);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setMinimumSize(QSize(0, 32));
        lineEdit_Name->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_Name->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_Name);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_3->addWidget(label_7);

        lineEdit_Condition = new QLineEdit(groupBox);
        lineEdit_Condition->setObjectName(QString::fromUtf8("lineEdit_Condition"));
        lineEdit_Condition->setFont(font1);
        lineEdit_Condition->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(lineEdit_Condition);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_3->addWidget(label_8);

        comboBox_Result = new QComboBox(groupBox);
        comboBox_Result->addItem(QString());
        comboBox_Result->addItem(QString());
        comboBox_Result->addItem(QString());
        comboBox_Result->setObjectName(QString::fromUtf8("comboBox_Result"));
        comboBox_Result->setFont(font1);

        horizontalLayout_3->addWidget(comboBox_Result);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_3->addWidget(label_9);

        comboBox_Status = new QComboBox(groupBox);
        comboBox_Status->addItem(QString());
        comboBox_Status->addItem(QString());
        comboBox_Status->addItem(QString());
        comboBox_Status->setObjectName(QString::fromUtf8("comboBox_Status"));
        comboBox_Status->setFont(font1);

        horizontalLayout_3->addWidget(comboBox_Status);

        Btn_Find = new QPushButton(groupBox);
        Btn_Find->setObjectName(QString::fromUtf8("Btn_Find"));
        Btn_Find->setStyleSheet(QString::fromUtf8("board :100px;"));

        horizontalLayout_3->addWidget(Btn_Find);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setBold(true);
        font3.setWeight(75);
        pushButton->setFont(font3);

        horizontalLayout_3->addWidget(pushButton);

        frame_6 = new QFrame(groupBox);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setStyleSheet(QString::fromUtf8(""));
        frame_6->setFrameShape(QFrame::VLine);
        frame_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(frame_6);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout_2, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 840));
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableView_Work = new QTableView(tab);
        tableView_Work->setObjectName(QString::fromUtf8("tableView_Work"));

        gridLayout_5->addWidget(tableView_Work, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tableView_SJ1 = new QTableView(tab_3);
        tableView_SJ1->setObjectName(QString::fromUtf8("tableView_SJ1"));

        horizontalLayout_5->addWidget(tableView_SJ1);


        gridLayout_6->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        gridLayout_7->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        tableView_JL = new QTableView(tab_4);
        tableView_JL->setObjectName(QString::fromUtf8("tableView_JL"));

        gridLayout_7->addWidget(tableView_JL, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_8 = new QGridLayout(tab_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout_8->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        tableView_FS2 = new QTableView(tab_5);
        tableView_FS2->setObjectName(QString::fromUtf8("tableView_FS2"));

        gridLayout_8->addWidget(tableView_FS2, 1, 0, 1, 1);

        tableView_FS1 = new QTableView(tab_5);
        tableView_FS1->setObjectName(QString::fromUtf8("tableView_FS1"));

        gridLayout_8->addWidget(tableView_FS1, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_9 = new QGridLayout(tab_6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tableView_DJ1 = new QTableView(tab_6);
        tableView_DJ1->setObjectName(QString::fromUtf8("tableView_DJ1"));

        gridLayout_9->addWidget(tableView_DJ1, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));

        verticalLayout->addLayout(horizontalLayout_24);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        Btn_PageUp = new QPushButton(centralwidget);
        Btn_PageUp->setObjectName(QString::fromUtf8("Btn_PageUp"));
        Btn_PageUp->setMinimumSize(QSize(0, 38));
        Btn_PageUp->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font4.setBold(true);
        font4.setUnderline(false);
        font4.setWeight(75);
        Btn_PageUp->setFont(font4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Pictrue/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageUp->setIcon(icon1);
        Btn_PageUp->setAutoDefault(false);
        Btn_PageUp->setFlat(false);

        horizontalLayout_8->addWidget(Btn_PageUp);

        CurPage = new QSpinBox(centralwidget);
        CurPage->setObjectName(QString::fromUtf8("CurPage"));
        CurPage->setEnabled(false);
        CurPage->setMinimumSize(QSize(0, 32));
        CurPage->setMaximumSize(QSize(51, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font5.setBold(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        CurPage->setFont(font5);
        CurPage->setFrame(true);
        CurPage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurPage->setReadOnly(true);
        CurPage->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CurPage->setAccelerated(false);
        CurPage->setMinimum(1);
        CurPage->setMaximum(1000);

        horizontalLayout_8->addWidget(CurPage);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(16, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_4);

        CurPage_2 = new QSpinBox(centralwidget);
        CurPage_2->setObjectName(QString::fromUtf8("CurPage_2"));
        CurPage_2->setEnabled(false);
        CurPage_2->setMinimumSize(QSize(0, 32));
        CurPage_2->setMaximumSize(QSize(51, 16777215));
        CurPage_2->setFont(font5);
        CurPage_2->setFrame(true);
        CurPage_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurPage_2->setReadOnly(true);
        CurPage_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CurPage_2->setAccelerated(false);
        CurPage_2->setMinimum(1);
        CurPage_2->setMaximum(1000);

        horizontalLayout_8->addWidget(CurPage_2);

        Btn_PageDown = new QPushButton(centralwidget);
        Btn_PageDown->setObjectName(QString::fromUtf8("Btn_PageDown"));
        Btn_PageDown->setMinimumSize(QSize(0, 38));
        Btn_PageDown->setMaximumSize(QSize(16777215, 16777215));
        Btn_PageDown->setFont(font4);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Pictrue/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageDown->setIcon(icon2);
        Btn_PageDown->setAutoDefault(false);
        Btn_PageDown->setFlat(false);

        horizontalLayout_8->addWidget(Btn_PageDown);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 31));
        label_14->setFont(font1);

        horizontalLayout_8->addWidget(label_14);

        allPage = new QSpinBox(centralwidget);
        allPage->setObjectName(QString::fromUtf8("allPage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(allPage->sizePolicy().hasHeightForWidth());
        allPage->setSizePolicy(sizePolicy);
        allPage->setMinimumSize(QSize(41, 32));
        allPage->setMaximumSize(QSize(16777215, 31));
        allPage->setFont(font1);
        allPage->setReadOnly(false);
        allPage->setMinimum(10);
        allPage->setMaximum(10000);
        allPage->setSingleStep(5);
        allPage->setValue(25);

        horizontalLayout_8->addWidget(allPage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1251, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actions_SQL);
        menu->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);
        Btn_PageUp->setDefault(false);
        Btn_PageDown->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actions_SQL->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", nullptr));
        USER->setText(QString());
        label_10->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\237\245\350\257\242\350\275\257\344\273\266V1.0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\233\266\351\203\250\344\273\266\346\235\241\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\272\277\346\235\241\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\260\264\345\217\267\357\274\232", nullptr));
        ChB_date->setText(QString());
        led_sql_4->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237:", nullptr));
        dateEdit_Begin->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd HH:mm:ss", nullptr));
        led_sql_2->setText(QCoreApplication::translate("MainWindow", "\350\207\263", nullptr));
        dateEdit_End->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd HH:mm:ss", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\">\345\220\215 \347\247\260\357\274\232</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\">\346\235\241 \344\273\266\357\274\232</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", nullptr));
        comboBox_Result->setItemText(0, QString());
        comboBox_Result->setItemText(1, QCoreApplication::translate("MainWindow", "OK", nullptr));
        comboBox_Result->setItemText(2, QCoreApplication::translate("MainWindow", "NG", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        comboBox_Status->setItemText(0, QString());
        comboBox_Status->setItemText(1, QCoreApplication::translate("MainWindow", "\346\255\243\345\270\270", nullptr));
        comboBox_Status->setItemText(2, QCoreApplication::translate("MainWindow", "\350\277\224\344\277\256", nullptr));

        Btn_Find->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\345\257\274\345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\270\273\347\272\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\350\276\205\347\272\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\346\243\200\346\274\217\346\243\200\346\265\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\351\243\216\351\200\237\346\243\200\346\265\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\346\200\247\350\203\275\346\243\200\346\265\213", nullptr));
        Btn_PageUp->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Btn_PageDown->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\346\257\217\351\241\265\346\230\276\347\244\272\350\241\214\346\225\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
