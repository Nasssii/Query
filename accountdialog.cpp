#include "accountdialog.h"
#include "ui_Account_Dialog.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QToolButton>
#include "sqlconifg.h"

AccountDialog::AccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::btnLogin)
{
    ui->setupUi(this);
    setWindowTitle("用户登录");

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    // 密码显隐按钮
    ui->btnTogglePassword->setIcon(QIcon(":/new/prefix1/image/eye_show.png"));
    connect(ui->btnTogglePassword, &QToolButton::clicked, this, [this]() {
        bool hidden = (ui->lineEditPassword->echoMode() == QLineEdit::Password);
        ui->lineEditPassword->setEchoMode(hidden ? QLineEdit::Normal : QLineEdit::Password);
        ui->btnTogglePassword->setIcon(QIcon(hidden ? ":/new/prefix1/image/eye_close.png" : ":/new/prefix1/image/eye_show.png"));
    });

    connect(ui->pushButton, &QPushButton::clicked, this, &AccountDialog::onLoginClicked);
    connect(ui->btnExit, &QPushButton::clicked, this, &AccountDialog::onExitClicked);

    // 记住用户名
    QSettings settings(SQLConifg::settingsPath(), QSettings::IniFormat);
    QString rememberedName = settings.value("User/rememberedName").toString();
    if (!rememberedName.isEmpty()) {
        ui->lineEditUser->setText(rememberedName);
        ui->checkRememberUser->setChecked(true);
    }
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

void AccountDialog::onLoginClicked()
{
    const QString user = ui->lineEditUser->text().trimmed();
    const QString pwd = ui->lineEditPassword->text();
    if (user.isEmpty() || pwd.isEmpty()) {
        return;
    }

    // 记住用户名
    QSettings settings(SQLConifg::settingsPath(), QSettings::IniFormat);
    if (ui->checkRememberUser->isChecked()) {
        settings.setValue("User/rememberedName", user);
    } else {
        settings.remove("User/rememberedName");
    }
    settings.sync();

    emit loginRequested(user, pwd);
}

void AccountDialog::onExitClicked()
{
    reject();
}
