/********************************************************************************
** Form generated from reading UI file 'Account_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_DIALOG_H
#define UI_ACCOUNT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btnLogin
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *labelLoginTitle_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPassword;
    QLabel *labelUser;
    QCheckBox *checkRememberUser;
    QLabel *labelPassword;
    QLineEdit *lineEditUser;
    QToolButton *btnTogglePassword;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QPushButton *btnExit;

    void setupUi(QDialog *btnLogin)
    {
        if (btnLogin->objectName().isEmpty())
            btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->resize(630, 382);
        verticalLayoutWidget_2 = new QWidget(btnLogin);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 601, 311));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(verticalLayoutWidget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelLoginTitle_2 = new QLabel(frame);
        labelLoginTitle_2->setObjectName(QString::fromUtf8("labelLoginTitle_2"));
        labelLoginTitle_2->setGeometry(QRect(240, 20, 151, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(20);
        labelLoginTitle_2->setFont(font);

        horizontalLayout->addWidget(frame);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditPassword = new QLineEdit(verticalLayoutWidget_2);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setMinimumSize(QSize(200, 25));

        gridLayout->addWidget(lineEditPassword, 1, 2, 1, 1);

        labelUser = new QLabel(verticalLayoutWidget_2);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));
        labelUser->setMinimumSize(QSize(85, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AcadEref"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        labelUser->setFont(font1);

        gridLayout->addWidget(labelUser, 0, 1, 1, 1);

        checkRememberUser = new QCheckBox(verticalLayoutWidget_2);
        checkRememberUser->setObjectName(QString::fromUtf8("checkRememberUser"));

        gridLayout->addWidget(checkRememberUser, 5, 2, 1, 1);

        labelPassword = new QLabel(verticalLayoutWidget_2);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setMinimumSize(QSize(85, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AcadEref"));
        font2.setPointSize(16);
        labelPassword->setFont(font2);

        gridLayout->addWidget(labelPassword, 1, 1, 1, 1);

        lineEditUser = new QLineEdit(verticalLayoutWidget_2);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));
        lineEditUser->setMinimumSize(QSize(200, 25));

        gridLayout->addWidget(lineEditUser, 0, 2, 1, 1);

        btnTogglePassword = new QToolButton(verticalLayoutWidget_2);
        btnTogglePassword->setObjectName(QString::fromUtf8("btnTogglePassword"));
        btnTogglePassword->setStyleSheet(QString::fromUtf8("QToolButton#btnTogglePassword {\n"
"    border: none;\n"
"    background: transparent;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QToolButton#btnTogglePassword:hover {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QToolButton#btnTogglePassword:pressed {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QToolButton#btnTogglePassword:checked {\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/eye_show.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTogglePassword->setIcon(icon);
        btnTogglePassword->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(btnTogglePassword, 1, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(btnLogin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 340, 93, 28));
        btnExit = new QPushButton(btnLogin);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(220, 340, 93, 28));

        retranslateUi(btnLogin);

        QMetaObject::connectSlotsByName(btnLogin);
    } // setupUi

    void retranslateUi(QDialog *btnLogin)
    {
        btnLogin->setWindowTitle(QCoreApplication::translate("btnLogin", "Dialog", nullptr));
        labelLoginTitle_2->setText(QCoreApplication::translate("btnLogin", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        labelUser->setText(QCoreApplication::translate("btnLogin", "\347\224\250\346\210\267\345\220\215", nullptr));
        checkRememberUser->setText(QCoreApplication::translate("btnLogin", "\350\256\260\344\275\217\347\224\250\346\210\267\345\220\215", nullptr));
        labelPassword->setText(QCoreApplication::translate("btnLogin", "\345\257\206  \347\240\201", nullptr));
        btnTogglePassword->setText(QCoreApplication::translate("btnLogin", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("btnLogin", "\347\231\273\345\275\225", nullptr));
        btnExit->setText(QCoreApplication::translate("btnLogin", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class btnLogin: public Ui_btnLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_DIALOG_H
