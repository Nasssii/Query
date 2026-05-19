/********************************************************************************
** Form generated from reading UI file 'finddata.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDATA_H
#define UI_FINDDATA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finddata
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *led_sql_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *ChB_date;
    QLabel *led_sql_4;
    QDateTimeEdit *dateEdit_Begin;
    QLabel *led_sql_2;
    QDateTimeEdit *dateEdit_End;
    QPushButton *Btn_Find;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Btn_PageUp;
    QSpinBox *CurPage;
    QLabel *label;
    QPushButton *Btn_PageDown;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *Btn_ExportAll;
    QLabel *label_14;
    QSpinBox *allPage;

    void setupUi(QWidget *Finddata)
    {
        if (Finddata->objectName().isEmpty())
            Finddata->setObjectName(QString::fromUtf8("Finddata"));
        Finddata->resize(1251, 672);
        gridLayout = new QGridLayout(Finddata);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Finddata);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 0));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        led_sql_3 = new QLabel(Finddata);
        led_sql_3->setObjectName(QString::fromUtf8("led_sql_3"));
        led_sql_3->setMinimumSize(QSize(0, 0));
        led_sql_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        led_sql_3->setFont(font1);
        led_sql_3->setFrameShape(QFrame::NoFrame);
        led_sql_3->setTextFormat(Qt::AutoText);
        led_sql_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(led_sql_3);

        comboBox = new QComboBox(Finddata);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        comboBox->setFont(font2);

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        ChB_date = new QCheckBox(Finddata);
        ChB_date->setObjectName(QString::fromUtf8("ChB_date"));

        horizontalLayout->addWidget(ChB_date);

        led_sql_4 = new QLabel(Finddata);
        led_sql_4->setObjectName(QString::fromUtf8("led_sql_4"));
        led_sql_4->setMinimumSize(QSize(41, 0));
        led_sql_4->setMaximumSize(QSize(41, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        led_sql_4->setFont(font3);
        led_sql_4->setFrameShape(QFrame::NoFrame);
        led_sql_4->setTextFormat(Qt::AutoText);
        led_sql_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(led_sql_4);

        dateEdit_Begin = new QDateTimeEdit(Finddata);
        dateEdit_Begin->setObjectName(QString::fromUtf8("dateEdit_Begin"));
        dateEdit_Begin->setFont(font2);
        dateEdit_Begin->setDate(QDate(2024, 8, 1));
        dateEdit_Begin->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_Begin);

        led_sql_2 = new QLabel(Finddata);
        led_sql_2->setObjectName(QString::fromUtf8("led_sql_2"));
        led_sql_2->setMinimumSize(QSize(31, 31));
        led_sql_2->setMaximumSize(QSize(31, 31));
        led_sql_2->setFont(font3);
        led_sql_2->setFrameShape(QFrame::NoFrame);
        led_sql_2->setTextFormat(Qt::AutoText);
        led_sql_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(led_sql_2);

        dateEdit_End = new QDateTimeEdit(Finddata);
        dateEdit_End->setObjectName(QString::fromUtf8("dateEdit_End"));
        dateEdit_End->setFont(font2);
        dateEdit_End->setDate(QDate(2025, 1, 8));
        dateEdit_End->setTime(QTime(23, 59, 59));
        dateEdit_End->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_End);

        Btn_Find = new QPushButton(Finddata);
        Btn_Find->setObjectName(QString::fromUtf8("Btn_Find"));
        Btn_Find->setMinimumSize(QSize(0, 31));
        Btn_Find->setMaximumSize(QSize(16777215, 31));
        Btn_Find->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Pictrue/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Find->setIcon(icon);
        Btn_Find->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(Btn_Find);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(Finddata);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        tableView->setFont(font4);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        Btn_PageUp = new QPushButton(Finddata);
        Btn_PageUp->setObjectName(QString::fromUtf8("Btn_PageUp"));
        Btn_PageUp->setMinimumSize(QSize(0, 31));
        Btn_PageUp->setMaximumSize(QSize(16777215, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(9);
        font5.setUnderline(false);
        Btn_PageUp->setFont(font5);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Pictrue/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageUp->setIcon(icon1);
        Btn_PageUp->setAutoDefault(false);
        Btn_PageUp->setFlat(false);

        horizontalLayout_8->addWidget(Btn_PageUp);

        CurPage = new QSpinBox(Finddata);
        CurPage->setObjectName(QString::fromUtf8("CurPage"));
        CurPage->setEnabled(false);
        CurPage->setMinimumSize(QSize(0, 31));
        CurPage->setMaximumSize(QSize(31, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setUnderline(false);
        font6.setWeight(50);
        CurPage->setFont(font6);
        CurPage->setFrame(true);
        CurPage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurPage->setReadOnly(true);
        CurPage->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CurPage->setAccelerated(false);
        CurPage->setMinimum(1);
        CurPage->setMaximum(1000);

        horizontalLayout_8->addWidget(CurPage);

        label = new QLabel(Finddata);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(31, 0));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label);

        Btn_PageDown = new QPushButton(Finddata);
        Btn_PageDown->setObjectName(QString::fromUtf8("Btn_PageDown"));
        Btn_PageDown->setMinimumSize(QSize(0, 31));
        Btn_PageDown->setMaximumSize(QSize(16777215, 31));
        Btn_PageDown->setFont(font5);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Pictrue/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageDown->setIcon(icon2);
        Btn_PageDown->setAutoDefault(false);
        Btn_PageDown->setFlat(false);

        horizontalLayout_8->addWidget(Btn_PageDown);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        pushButton = new QPushButton(Finddata);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Agency FB"));
        font7.setPointSize(12);
        pushButton->setFont(font7);

        horizontalLayout_8->addWidget(pushButton);

        Btn_ExportAll = new QPushButton(Finddata);
        Btn_ExportAll->setObjectName(QString::fromUtf8("Btn_ExportAll"));
        Btn_ExportAll->setFont(font7);

        horizontalLayout_8->addWidget(Btn_ExportAll);

        label_14 = new QLabel(Finddata);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 31));
        label_14->setFont(font2);

        horizontalLayout_8->addWidget(label_14);

        allPage = new QSpinBox(Finddata);
        allPage->setObjectName(QString::fromUtf8("allPage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(allPage->sizePolicy().hasHeightForWidth());
        allPage->setSizePolicy(sizePolicy);
        allPage->setMinimumSize(QSize(41, 31));
        allPage->setMaximumSize(QSize(16777215, 31));
        QFont font8;
        font8.setPointSize(12);
        allPage->setFont(font8);
        allPage->setReadOnly(false);
        allPage->setMinimum(10);
        allPage->setMaximum(100);
        allPage->setSingleStep(5);
        allPage->setValue(50);

        horizontalLayout_8->addWidget(allPage);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);


        retranslateUi(Finddata);

        Btn_PageUp->setDefault(false);
        Btn_PageDown->setDefault(false);


        QMetaObject::connectSlotsByName(Finddata);
    } // setupUi

    void retranslateUi(QWidget *Finddata)
    {
        Finddata->setWindowTitle(QCoreApplication::translate("Finddata", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Finddata", "PINSEN", nullptr));
        led_sql_3->setText(QCoreApplication::translate("Finddata", "\346\225\260\346\215\256\351\200\211\346\213\251:", nullptr));
        ChB_date->setText(QString());
        led_sql_4->setText(QCoreApplication::translate("Finddata", "\346\227\245\346\234\237:", nullptr));
        dateEdit_Begin->setDisplayFormat(QCoreApplication::translate("Finddata", "yyyy/MM/dd HH:mm:ss", nullptr));
        led_sql_2->setText(QCoreApplication::translate("Finddata", "\350\207\263", nullptr));
        dateEdit_End->setDisplayFormat(QCoreApplication::translate("Finddata", "yyyy/MM/dd HH:mm:ss", nullptr));
        Btn_Find->setText(QCoreApplication::translate("Finddata", "\346\237\245\350\257\242", nullptr));
        Btn_PageUp->setText(QCoreApplication::translate("Finddata", "\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("Finddata", "/", nullptr));
        Btn_PageDown->setText(QCoreApplication::translate("Finddata", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton->setText(QCoreApplication::translate("Finddata", "\345\257\274\345\207\272", nullptr));
        Btn_ExportAll->setText(QCoreApplication::translate("Finddata", "\345\257\274\345\207\272\345\205\250\351\203\250", nullptr));
        label_14->setText(QCoreApplication::translate("Finddata", "\346\234\200\345\244\247\346\230\276\347\244\272\350\241\214\346\225\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finddata: public Ui_Finddata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDATA_H
