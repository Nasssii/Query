/********************************************************************************
** Form generated from reading UI file 'SQLSettingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLSETTINGDIALOG_H
#define UI_SQLSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQLSettingDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTableWidget *tableWidgetSelSet;
    QLabel *labelSelSet;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_5;
    QLabel *LInkNamelabel;
    QLabel *SQLPASSWORDlabel;
    QLineEdit *SQLPASSWORD;
    QLineEdit *SQLUser;
    QLabel *portlabel;
    QLineEdit *linkSQL;
    QLabel *SQLUserNamelabel;
    QLineEdit *LInkName;
    QLineEdit *host;
    QLabel *linkSQLlabel;
    QLineEdit *port;
    QLabel *hostlabel;
    QLabel *labelSQLLink;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_4;
    QTableWidget *SQLTableSetitng;
    QLabel *labelSetTable;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SQLSettingDialog)
    {
        if (SQLSettingDialog->objectName().isEmpty())
            SQLSettingDialog->setObjectName(QString::fromUtf8("SQLSettingDialog"));
        SQLSettingDialog->resize(1444, 791);
        SQLSettingDialog->setMinimumSize(QSize(0, 151));
        SQLSettingDialog->setStyleSheet(QString::fromUtf8("/* ================================\n"
"   QLabel \351\200\217\346\230\216\345\272\225\344\274\230\345\214\226\n"
"   \346\224\276\345\234\250 QSS \346\226\207\344\273\266\346\234\200\345\220\216\n"
"   ================================ */\n"
"\n"
"/* \346\211\200\346\234\211 QLabel \351\273\230\350\256\244\351\200\217\346\230\216 */\n"
"QLabel {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \345\267\246\344\276\247\345\255\227\346\256\265\346\240\207\347\255\276\357\274\232host / PORT / \346\225\260\346\215\256\345\272\223\345\220\215 / \347\224\250\346\210\267\345\220\215 / \345\257\206\347\240\201 */\n"
"QLabel#hostlabel,\n"
"QLabel#portlabel,\n"
"QLabel#linkSQLlabel,\n"
"QLabel#SQLUserNamelabel,\n"
"QLabel#SQLPASSWORDlabel,\n"
"QLabel#LInkNamelabel {\n"
"    background-color: transparent;\n"
"    color: #526274;\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"/* \344\270\211\344\270\252\345\210\206\345\214\272\346"
                        "\240\207\351\242\230\357\274\232\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245 / \350\256\276\347\275\256\350\241\250 / \346\237\245\350\257\242\351\205\215\347\275\256 */\n"
"QLabel#labelSQLLink,\n"
"QLabel#labelSetTable,\n"
"QLabel#labelSelSet {\n"
"    background-color: transparent;\n"
"    color: #2563EB;\n"
"    font-size: 15px;\n"
"    font-weight: 700;\n"
"    border: none;\n"
"    padding: 0px 0px 8px 0px;\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\345\244\247\346\240\207\351\242\230 SQL\350\256\276\347\275\256 */\n"
"QLabel#label {\n"
"    background-color: transparent;\n"
"    color: #0F172A;\n"
"    font-size: 24px;\n"
"    font-weight: 700;\n"
"    border: none;\n"
"    padding: 12px 8px 8px 14px;\n"
"}"));
        verticalLayoutWidget = new QWidget(SQLSettingDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 10, 861, 544));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 46));
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Algerian"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidgetSelSet = new QTableWidget(verticalLayoutWidget);
        if (tableWidgetSelSet->columnCount() < 3)
            tableWidgetSelSet->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetSelSet->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetSelSet->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetSelSet->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidgetSelSet->rowCount() < 3)
            tableWidgetSelSet->setRowCount(3);
        tableWidgetSelSet->setObjectName(QString::fromUtf8("tableWidgetSelSet"));
        tableWidgetSelSet->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetSelSet->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetSelSet->setRowCount(3);
        tableWidgetSelSet->setColumnCount(3);
        tableWidgetSelSet->horizontalHeader()->setVisible(true);
        tableWidgetSelSet->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidgetSelSet, 10, 2, 1, 1);

        labelSelSet = new QLabel(verticalLayoutWidget);
        labelSelSet->setObjectName(QString::fromUtf8("labelSelSet"));
        labelSelSet->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(labelSelSet, 9, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 2, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        LInkNamelabel = new QLabel(verticalLayoutWidget);
        LInkNamelabel->setObjectName(QString::fromUtf8("LInkNamelabel"));
        LInkNamelabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(LInkNamelabel, 2, 0, 1, 1);

        SQLPASSWORDlabel = new QLabel(verticalLayoutWidget);
        SQLPASSWORDlabel->setObjectName(QString::fromUtf8("SQLPASSWORDlabel"));
        SQLPASSWORDlabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(SQLPASSWORDlabel, 8, 0, 1, 1);

        SQLPASSWORD = new QLineEdit(verticalLayoutWidget);
        SQLPASSWORD->setObjectName(QString::fromUtf8("SQLPASSWORD"));

        gridLayout_5->addWidget(SQLPASSWORD, 8, 1, 1, 1);

        SQLUser = new QLineEdit(verticalLayoutWidget);
        SQLUser->setObjectName(QString::fromUtf8("SQLUser"));

        gridLayout_5->addWidget(SQLUser, 7, 1, 1, 1);

        portlabel = new QLabel(verticalLayoutWidget);
        portlabel->setObjectName(QString::fromUtf8("portlabel"));
        portlabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(portlabel, 5, 0, 1, 1);

        linkSQL = new QLineEdit(verticalLayoutWidget);
        linkSQL->setObjectName(QString::fromUtf8("linkSQL"));

        gridLayout_5->addWidget(linkSQL, 6, 1, 1, 1);

        SQLUserNamelabel = new QLabel(verticalLayoutWidget);
        SQLUserNamelabel->setObjectName(QString::fromUtf8("SQLUserNamelabel"));
        SQLUserNamelabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(SQLUserNamelabel, 7, 0, 1, 1);

        LInkName = new QLineEdit(verticalLayoutWidget);
        LInkName->setObjectName(QString::fromUtf8("LInkName"));

        gridLayout_5->addWidget(LInkName, 2, 1, 1, 1);

        host = new QLineEdit(verticalLayoutWidget);
        host->setObjectName(QString::fromUtf8("host"));

        gridLayout_5->addWidget(host, 4, 1, 1, 1);

        linkSQLlabel = new QLabel(verticalLayoutWidget);
        linkSQLlabel->setObjectName(QString::fromUtf8("linkSQLlabel"));
        linkSQLlabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(linkSQLlabel, 6, 0, 1, 1);

        port = new QLineEdit(verticalLayoutWidget);
        port->setObjectName(QString::fromUtf8("port"));

        gridLayout_5->addWidget(port, 5, 1, 1, 1);

        hostlabel = new QLabel(verticalLayoutWidget);
        hostlabel->setObjectName(QString::fromUtf8("hostlabel"));
        hostlabel->setMaximumSize(QSize(80, 20));

        gridLayout_5->addWidget(hostlabel, 4, 0, 1, 1);

        labelSQLLink = new QLabel(verticalLayoutWidget);
        labelSQLLink->setObjectName(QString::fromUtf8("labelSQLLink"));
        labelSQLLink->setMinimumSize(QSize(0, 30));

        gridLayout_5->addWidget(labelSQLLink, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_5, 5, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 2, 2, 1, 1);

        SQLTableSetitng = new QTableWidget(verticalLayoutWidget);
        if (SQLTableSetitng->columnCount() < 2)
            SQLTableSetitng->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        SQLTableSetitng->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        SQLTableSetitng->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        SQLTableSetitng->setObjectName(QString::fromUtf8("SQLTableSetitng"));
        SQLTableSetitng->setSelectionMode(QAbstractItemView::SingleSelection);
        SQLTableSetitng->setSelectionBehavior(QAbstractItemView::SelectRows);
        SQLTableSetitng->setColumnCount(2);
        SQLTableSetitng->horizontalHeader()->setVisible(false);
        SQLTableSetitng->verticalHeader()->setVisible(false);
        SQLTableSetitng->verticalHeader()->setHighlightSections(true);

        gridLayout_3->addWidget(SQLTableSetitng, 2, 0, 1, 1);

        labelSetTable = new QLabel(verticalLayoutWidget);
        labelSetTable->setObjectName(QString::fromUtf8("labelSetTable"));
        labelSetTable->setMinimumSize(QSize(0, 30));
        labelSetTable->setMaximumSize(QSize(16777215, 30));

        gridLayout_3->addWidget(labelSetTable, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SQLSettingDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 570, 96, 34));
        pushButton_2 = new QPushButton(SQLSettingDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 570, 98, 36));

        retranslateUi(SQLSettingDialog);

        QMetaObject::connectSlotsByName(SQLSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SQLSettingDialog)
    {
        SQLSettingDialog->setWindowTitle(QCoreApplication::translate("SQLSettingDialog", "SQL\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("SQLSettingDialog", "SQL\350\256\276\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetSelSet->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SQLSettingDialog", "\346\230\276\347\244\272\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetSelSet->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SQLSettingDialog", "\346\225\260\346\215\256\345\272\223\345\210\227\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSelSet->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SQLSettingDialog", "\345\205\263\350\201\224\346\237\245\350\257\242\350\241\250", nullptr));
        labelSelSet->setText(QCoreApplication::translate("SQLSettingDialog", "\346\237\245\350\257\242\346\235\241\344\273\266\351\205\215\347\275\256", nullptr));
        LInkNamelabel->setText(QCoreApplication::translate("SQLSettingDialog", "\350\277\236\346\216\245\345\220\215", nullptr));
        SQLPASSWORDlabel->setText(QCoreApplication::translate("SQLSettingDialog", "\345\257\206\347\240\201", nullptr));
        portlabel->setText(QCoreApplication::translate("SQLSettingDialog", "PORT", nullptr));
        SQLUserNamelabel->setText(QCoreApplication::translate("SQLSettingDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        linkSQLlabel->setText(QCoreApplication::translate("SQLSettingDialog", "\346\225\260\346\215\256\345\272\223\345\220\215", nullptr));
        hostlabel->setText(QCoreApplication::translate("SQLSettingDialog", "host", nullptr));
        labelSQLLink->setText(QCoreApplication::translate("SQLSettingDialog", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = SQLTableSetitng->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SQLSettingDialog", "\345\211\215\347\253\257\350\241\250\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = SQLTableSetitng->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SQLSettingDialog", "\346\225\260\346\215\256\345\272\223\350\241\250\345\220\215", nullptr));
        labelSetTable->setText(QCoreApplication::translate("SQLSettingDialog", "\350\256\276\347\275\256\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("SQLSettingDialog", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SQLSettingDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SQLSettingDialog: public Ui_SQLSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLSETTINGDIALOG_H
