#include "formsqlset.h"
#include "ui_formsqlset.h"

FormSqlset::FormSqlset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSqlset)
{
    ui->setupUi(this);
}

FormSqlset::~FormSqlset()
{
    delete ui;
}
