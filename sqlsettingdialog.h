#ifndef SQLSETTINGDIALOG_H
#define SQLSETTINGDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

#include "sqlconifg.h"

namespace Ui {
class SQLSettingDialog;
}

class SQLSettingDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SQLSettingDialog(QWidget *parent = nullptr);
    ~SQLSettingDialog();

signals:
    // 保存成功后发出，后续 MainWindow 可用它触发重新加载配置。
    void configChanged(const SqlConnectionConfig &config);

private slots:
    void onItemChanged(QTableWidgetItem *item);
    void deleteSelectedRow();
    void onConfirmClicked();
    void onCancelClicked();

private:
    void ensureOneEmptyRow();
    void loadConfigToUi();
    bool collectConfigFromUi(SqlConnectionConfig *config);
    bool isValidName(const QString &name) const;

    Ui::SQLSettingDialog *ui;
};

#endif // SQLSETTINGDIALOG_H
