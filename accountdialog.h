#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>
#include <QPair>

namespace Ui {
class btnLogin;
}

class AccountDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AccountDialog(QWidget *parent = nullptr);
    ~AccountDialog();

signals:
    void loginRequested(const QString &user, const QString &pwd);

private slots:
    void onLoginClicked();
    void onExitClicked();

private:
    Ui::btnLogin *ui;
};

#endif // ACCOUNTDIALOG_H
