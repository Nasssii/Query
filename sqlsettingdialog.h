#ifndef SQLSETTINGDIALOG_H
#define SQLSETTINGDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "sqlconifg.h"

namespace Ui {
class SQLSettingDialog;
}

class SQLSettingDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SQLSettingDialog(QWidget *parent = nullptr, int permissionLevel = 1);
    ~SQLSettingDialog();

signals:
    // 保存成功后发出，后续 MainWindow 可用它触发重新加载配置。
    void configChanged(const SqlConnectionConfig &config);

private slots:
    void on_SQLTableSetitng_itemChanged(QTableWidgetItem *item);
    void onSelSetItemChanged(QTableWidgetItem *item);
    void deleteSelectedRow();
    void onConfirmClicked();
    void onCancelClicked();

private:
    void ensureOneEmptyRow();
    void ensureSelSetEmptyRow();
    static void ensureTableBottomEmptyRow(QTableWidget *table);
    void loadConfigToUi();
    bool collectConfigFromUi(SqlConnectionConfig *config);
    bool isValidName(const QString &name) const;

    Ui::SQLSettingDialog *ui;
    int m_permissionLevel = 1;
};

#endif // SQLSETTINGDIALOG_H
