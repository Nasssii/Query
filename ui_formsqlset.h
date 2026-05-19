/********************************************************************************
** Form generated from reading UI file 'formsqlset.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSQLSET_H
#define UI_FORMSQLSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSqlset
{
public:

    void setupUi(QWidget *FormSqlset)
    {
        if (FormSqlset->objectName().isEmpty())
            FormSqlset->setObjectName(QString::fromUtf8("FormSqlset"));
        FormSqlset->resize(400, 300);

        retranslateUi(FormSqlset);

        QMetaObject::connectSlotsByName(FormSqlset);
    } // setupUi

    void retranslateUi(QWidget *FormSqlset)
    {
        FormSqlset->setWindowTitle(QCoreApplication::translate("FormSqlset", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSqlset: public Ui_FormSqlset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSQLSET_H
