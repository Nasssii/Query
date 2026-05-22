#include "sqlsettingdialog.h"
#include "ui_SQLSettingDialog.h"

#include <QKeySequence>
#include <QMessageBox>
#include <QPushButton>
#include <QRegExp>
#include <QShortcut>
#include <QTableWidget>
#include "sqlconifg.h"

SQLSettingDialog::SQLSettingDialog(QWidget *parent, int permissionLevel) :
    QDialog(parent),
    ui(new Ui::SQLSettingDialog),
    m_permissionLevel(permissionLevel)
{
    ui->setupUi(this);

    QTableWidget *table = ui->SQLTableSetitng;
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList() << tr("前端表名") << tr("数据库表名"));
    table->horizontalHeader()->setVisible(false);
    table->horizontalHeader()->setDisabled(true);

    QShortcut *delShortcut = new QShortcut(QKeySequence::Delete, this);
    connect(delShortcut, &QShortcut::activated, this, &SQLSettingDialog::deleteSelectedRow);

    // UI 文件中的按钮名保持不变：pushButton=确认，pushButton_2=取消。
    connect(ui->pushButton, &QPushButton::clicked, this, &SQLSettingDialog::onConfirmClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &SQLSettingDialog::onCancelClicked);


    // 设置查询条件配置表
    QTableWidget *selSetTable = ui->tableWidgetSelSet;
    selSetTable->setColumnCount(3);
    selSetTable->setHorizontalHeaderLabels(
        QStringList() << tr("显示名称") << tr("数据库列名") << tr("关联查询表"));
    connect(selSetTable, &QTableWidget::itemChanged, this, &SQLSettingDialog::onSelSetItemChanged);

    loadConfigToUi();
    ensureOneEmptyRow();

    // 根据权限禁用控件
    if (m_permissionLevel == 2) {
        // 管理员：不能修改连接配置
        ui->host->setEnabled(false);
        ui->port->setEnabled(false);
        ui->linkSQL->setEnabled(false);
        ui->SQLUser->setEnabled(false);
        ui->SQLPASSWORD->setEnabled(false);
    }
    // level 1(操作员) 无法进入此对话框；level 3(系统管理员) 拥有完整权限
}

SQLSettingDialog::~SQLSettingDialog()
{
    delete ui;
}

void SQLSettingDialog::ensureOneEmptyRow()
{
    QTableWidget *table = ui->SQLTableSetitng;
    ensureTableBottomEmptyRow(table);
}

void SQLSettingDialog::ensureSelSetEmptyRow()
{
    QTableWidget *table = ui->tableWidgetSelSet;
    // 管理员最多 3 行
    if (m_permissionLevel == 2 && table->rowCount() >= 3)
        return;
    ensureTableBottomEmptyRow(table);
}

void SQLSettingDialog::ensureTableBottomEmptyRow(QTableWidget *table)
{
    const int last = table->rowCount() - 1;
    if (last < 0) {
        table->insertRow(0);
        return;
    }
    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem *item = table->item(last, col);
        if (item && !item->text().trimmed().isEmpty()) {
            table->insertRow(table->rowCount());
            return;
        }
    }
}

bool SQLSettingDialog::isValidName(const QString &name) const
{
    // 允许中文、字母、数字、下划线，覆盖当前表名和前端显示名的使用场景。
    QRegExp re("^[A-Za-z0-9_\u4e00-\u9fa5]{1,64}$");
    return re.exactMatch(name);
}

void SQLSettingDialog::on_SQLTableSetitng_itemChanged(QTableWidgetItem *item)
{
    if (item == nullptr || item->column() > 1) {
        return;
    }

    QTableWidget *table = ui->SQLTableSetitng;
    table->blockSignals(true);

    const QString text = item->text().trimmed();
    if (!text.isEmpty()) {
        if (!isValidName(text)) {
            QMessageBox::warning(this, tr("格式错误"), tr("名称只能包含中文、字母、数字和下划线，长度 1~64。"));
            item->setText("");
            table->blockSignals(false);
            return;
        }
        item->setText(text);
    }

    // 删除中间的全空行，仅保留末尾空行用于继续新增。
    for (int i = 0; i < table->rowCount(); ++i) {
        QTableWidgetItem *frontItem = table->item(i, 0);
        QTableWidgetItem *dbItem = table->item(i, 1);
        const bool empty = (!frontItem || frontItem->text().trimmed().isEmpty()) &&
                           (!dbItem || dbItem->text().trimmed().isEmpty());
        if (empty && i != table->rowCount() - 1) {
            table->removeRow(i);
            --i;
        }
    }

    ensureOneEmptyRow();
    table->blockSignals(false);
}

void SQLSettingDialog::onSelSetItemChanged(QTableWidgetItem *item)
{
    if (item == nullptr) return;
    ensureSelSetEmptyRow();
}

void SQLSettingDialog::deleteSelectedRow()
{
    QTableWidget *table = ui->SQLTableSetitng;
    const int row = table->currentRow();
    if (row < 0) {
        return;
    }

    table->blockSignals(true);
    table->removeRow(row);
    ensureOneEmptyRow();
    table->blockSignals(false);
}

void SQLSettingDialog::loadConfigToUi()
{
    const SqlConnectionConfig config = SQLConifg::loadConfig();

    ui->host->setText(config.hostName);
    ui->linkSQL->setText(config.databaseName);
    ui->SQLUser->setText(config.userName);
    ui->SQLPASSWORD->setText(config.password);
    ui->port->setText(QString::number(config.port));

    QTableWidget *table = ui->SQLTableSetitng;
    table->blockSignals(true);
    table->setRowCount(0);
    for (const SqlTableConfig &tableConfig : config.tables) {
        const int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(tableConfig.tabName));
        table->setItem(row, 1, new QTableWidgetItem(tableConfig.tableName));
    }
    table->blockSignals(false);
    ensureOneEmptyRow();

    // 加载查询字段配置
    QList<QueryFieldConfig> queryFields = SQLConifg::loadQueryFields();
    QTableWidget *selSet = ui->tableWidgetSelSet;
    selSet->blockSignals(true);
    selSet->setRowCount(0);
    for (const QueryFieldConfig &qf : queryFields) {
        const int row = selSet->rowCount();
        selSet->insertRow(row);
        selSet->setItem(row, 0, new QTableWidgetItem(qf.displayName));
        selSet->setItem(row, 1, new QTableWidgetItem(qf.columnName));
        selSet->setItem(row, 2, new QTableWidgetItem(qf.lookupTable));
    }
    selSet->blockSignals(false);
    ensureSelSetEmptyRow();
}

bool SQLSettingDialog::collectConfigFromUi(SqlConnectionConfig *config)
{
    if (config == nullptr) {
        return false;
    }

    config->hostName = ui->host->text().trimmed();
    config->databaseName = ui->linkSQL->text().trimmed();
    config->userName = ui->SQLUser->text().trimmed();
    config->password = ui->SQLPASSWORD->text();
    bool portOk = false;
    const int portValue = ui->port->text().trimmed().toInt(&portOk);
    if (!portOk || portValue < 1 || portValue > 65535) {
        QMessageBox::warning(this, tr("格式错误"), tr("PORT 必须是 1~65535 的数字。"));
        return false;
    }
    config->port = portValue;
    config->tables.clear();

    if (config->hostName.isEmpty()) {
        QMessageBox::warning(this, tr("格式错误"), tr("host 不能为空。"));
        return false;
    }
    QRegExp hostRegExp("^[A-Za-z0-9_.-]{1,255}$");
    if (!hostRegExp.exactMatch(config->hostName)) {
        QMessageBox::warning(this, tr("格式错误"), tr("host 只能包含字母、数字、点、下划线和短横线。"));
        return false;
    }
    if (config->databaseName.isEmpty() || !isValidName(config->databaseName)) {
        QMessageBox::warning(this, tr("格式错误"), tr("数据库名不能为空，且只能包含中文、字母、数字和下划线。"));
        return false;
    }
    if (config->userName.isEmpty()) {
        QMessageBox::warning(this, tr("格式错误"), tr("用户名不能为空。"));
        return false;
    }

    QTableWidget *table = ui->SQLTableSetitng;
    for (int i = 0; i < table->rowCount(); ++i) {
        QTableWidgetItem *frontItem = table->item(i, 0);
        QTableWidgetItem *dbItem = table->item(i, 1);
        const QString tabName = frontItem ? frontItem->text().trimmed() : QString();
        const QString tableName = dbItem ? dbItem->text().trimmed() : QString();

        if (tabName.isEmpty() && tableName.isEmpty()) {
            continue;
        }
        if (tabName.isEmpty() || tableName.isEmpty()) {
            QMessageBox::warning(this, tr("格式错误"), tr("表映射必须同时填写前端表名和数据库表名。"));
            return false;
        }
        if (!isValidName(tabName) || !isValidName(tableName)) {
            QMessageBox::warning(this, tr("格式错误"), tr("表名只能包含中文、字母、数字和下划线，长度 1~64。"));
            return false;
        }

        SqlTableConfig tableConfig;
        tableConfig.tabName = tabName;
        tableConfig.tableName = tableName;
        tableConfig.enabled = true;
        config->tables.append(tableConfig);
    }

    if (config->tables.isEmpty()) {
        QMessageBox::warning(this, tr("格式错误"), tr("至少需要配置一个数据库表名。"));
        return false;
    }

    return true;
}

void SQLSettingDialog::onConfirmClicked()
{
    SqlConnectionConfig config;
    if (!collectConfigFromUi(&config)) {
        return;
    }

    if (!SQLConifg::saveConfig(config)) {
        QMessageBox::warning(this, tr("保存失败"), tr("写入 Data/Settings.ini 失败。"));
        return;
    }

    // 收集并保存查询字段配置
    QList<QueryFieldConfig> queryFields;
    QTableWidget *selSet = ui->tableWidgetSelSet;
    for (int i = 0; i < selSet->rowCount(); ++i) {
        QTableWidgetItem *nameItem  = selSet->item(i, 0);
        QTableWidgetItem *colItem   = selSet->item(i, 1);
        QTableWidgetItem *lookItem  = selSet->item(i, 2);
        QString displayName = nameItem  ? nameItem->text().trimmed() : QString();
        QString columnName  = colItem   ? colItem->text().trimmed()  : QString();
        QString lookupTable = lookItem  ? lookItem->text().trimmed() : QString();
        if (!displayName.isEmpty()) {
            QueryFieldConfig qf;
            qf.displayName = displayName;
            qf.columnName  = columnName;
            qf.lookupTable = lookupTable;
            queryFields.append(qf);
        }
    }
    if (!queryFields.isEmpty()) {
        SQLConifg::saveQueryFields(queryFields);
    }

    emit configChanged(config);
    accept();
}

void SQLSettingDialog::onCancelClicked()
{
    reject();
}
