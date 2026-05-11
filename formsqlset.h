#ifndef FORMSQLSET_H
#define FORMSQLSET_H

#include <QWidget>

namespace Ui {
class FormSqlset;
}

class FormSqlset : public QWidget
{
    Q_OBJECT

public:
    explicit FormSqlset(QWidget *parent = nullptr);
    ~FormSqlset();

private:
    Ui::FormSqlset *ui;
};

#endif // FORMSQLSET_H
