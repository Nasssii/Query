#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QStandardPaths>
#include <QSignalBlocker>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTabBar>
#include <QHeaderView>
#include <QTableView>
#include <QSqlRecord>
#include <QToolButton>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include "accountdialog.h"
#include "sqlsettingdialog.h"

QStringList chineseList;
QStringList Assembly_cloumns;
QStringList Table_name;//数据库名字


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("查询系统V1.0 广州品晟汽车空调设备股份有限公司");
    {   // 读取数据库连接配置
        const SqlConnectionConfig cfg = SQLConifg::loadConfig();
        MysqlSettings.hostName     = cfg.hostName;
        MysqlSettings.databaseName = cfg.databaseName;
        MysqlSettings.userName     = cfg.userName;
        MysqlSettings.password     = cfg.password;
        MysqlSettings.port         = QString::number(cfg.port);
        MysqlSettings.B_MYSQL_EN   = true;
    }
    m_finddata = new Finddata;
    QHBoxLayout *layout1 = new QHBoxLayout;


    layout1->addWidget(m_finddata);
    //ui->tabWidget->setLayout(layout1);

    m_MysqlThread = new mMysqlThread(this);
    m_MysqlThread->pThread->start();

    // 记录当前标签页 key 和索引（PageInfo 由 slots_sql_model_conn 初始化）
    m_currentTabIndex = ui->tabWidget->currentIndex();
    m_currentTabKey = currentSqlModelName();

    // 启用页码控件（UI文件中默认为禁用）
    ui->CurPage->setEnabled(true);
    ui->CurPage_2->setEnabled(true);
    ui->CurPage->setReadOnly(true);
//菜单绑定对应页面

    // 连接标签页切换信号
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);


    //    ui->tabWidget->addTab(m_finddata, "标签页");
    //连接槽函数
    connect(m_finddata,&Finddata::signals_load_data,m_MysqlThread,&mMysqlThread::slot_Load_Data);
    connect(m_MysqlThread,&mMysqlThread::signals_setmodel,m_finddata,&Finddata::slots_setmodel);
    //    connect(m_finddata,&Finddata::signals_export_data,m_MysqlThread,&mMysqlThread::slot_export_data);//单表导出已删除
    //connect(m_finddata,&Finddata::signals_export_all,m_MysqlThread,&mMysqlThread::slot_exportAllBatched);  // 已废弃：旧导出路径，COM 在非主线程有风险
    connect(m_MysqlThread,&mMysqlThread::signals_exportProgress,this,&MainWindow::slot_updateExportProgress);  // 进度显示



    connect(m_MysqlThread,&mMysqlThread::signals_sql_model_conn,this,&MainWindow::slots_sql_model_conn);
    connect(m_MysqlThread,&mMysqlThread::sign_setWordList,this,&MainWindow::setWordList);

    connect(this,&MainWindow::signals_Load_Data_show,m_MysqlThread,&mMysqlThread::slot_Load_Data_show);

    connect(this,&MainWindow::signals_get_flowernumber,m_MysqlThread,&mMysqlThread::slot_get_flowernumber,Qt::BlockingQueuedConnection);
    connect(m_MysqlThread, &mMysqlThread::signal_totalPages, this, &MainWindow::updatePageControls);//发送signal_totalPages信号去mainwindows的updatePageControls
    //翻页按钮
    connect(this, &MainWindow::signals_requestExportData,m_MysqlThread, &mMysqlThread::slot_fetchDataForExport);  // 主线程请求子线程查询导出数据
    connect(m_MysqlThread, &mMysqlThread::signals_exportDataReady, this, &MainWindow::slot_writeExcel);           // 子线程数据就绪，由主线程写 Excel
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_ExportAll_clicked);           //导出按钮响应，ExportAll_clicked
    // 登录验证（BlockingQueuedConnection 同步等待结果）
    connect(this, &MainWindow::signals_checkLogin,
            m_MysqlThread, &mMysqlThread::slot_checkLogin,
            Qt::BlockingQueuedConnection);
    // 列数改变 → 只刷新列显示，不查库
    connect(ui->allPage, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int newColumns){
    m_pageInfoMap[m_currentTabKey].columnsPerPage = qMax(1, newColumns);
    m_pageInfoMap[m_currentTabKey].columnPage = 1;
    QSignalBlocker blocker(ui->CurPage);
    ui->CurPage->setValue(1);
    applyColumnPageToCurrentView();});

    // 查询条件变更 → 200ms 防抖，失效所有 tab 缓存，只查当前 tab
    QTimer *debounceTimer = new QTimer(this);
    debounceTimer->setSingleShot(true);
    connect(debounceTimer, &QTimer::timeout, this, [this]() {
        for (auto it = m_pageInfoMap.begin(); it != m_pageInfoMap.end(); ++it)
            it->dataLoaded = false;
        loadDataForCurrentPage();
        // 3s 空闲后静默刷新其他 tab
        QTimer::singleShot(3000, this, [this]() {
            for (auto it = m_pageInfoMap.begin(); it != m_pageInfoMap.end(); ++it) {
                if (!it->dataLoaded)
                    loadDataForTab(it.key(), true);
            }
        });
    });
    auto reloadOnChange = [debounceTimer]() {
        debounceTimer->start(200);
    };
    connect(ui->lineEdit_SerialN, &QLineEdit::textChanged, this, reloadOnChange);
    connect(ui->lineEdit_OnlineCode, &QLineEdit::textChanged, this, reloadOnChange);
    connect(ui->lineEdit_ComCode, &QLineEdit::textChanged, this, reloadOnChange);
    connect(ui->lineEdit_Condition, &QLineEdit::textChanged, this, reloadOnChange);
    connect(ui->comboBox_Result, &QComboBox::currentTextChanged, this, reloadOnChange);
    connect(ui->comboBox_Status, &QComboBox::currentTextChanged, this, reloadOnChange);
    connect(ui->dateEdit_Begin, &QDateEdit::dateChanged, this, reloadOnChange);
    connect(ui->dateEdit_End, &QDateEdit::dateChanged, this, reloadOnChange);
    connect(ui->ChB_date, &QCheckBox::stateChanged, this, reloadOnChange);


    m_MysqlThread->InitSQL();
    slots_sql_model_conn();

    list_model = new QStringListModel(this);
    completer = new QCompleter;
    completer->setModel(list_model);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit_Name->setCompleter(completer);
    connect(ui->lineEdit_Name, &QLineEdit::textChanged, this, &MainWindow::handleTextChange);

    ui->dateEdit_End->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_Begin->setDate(QDateTime::currentDateTime().date().addDays(-7));

    // 加载查询字段配置
    m_queryFields = SQLConifg::loadQueryFields();

    //隐藏按钮控件
//    ui->pushButton_2->setVisible(false);
//    ui->pushButton_3->setVisible(false);
//    ui->pushButton_4->setVisible(false);
//    ui->pushButton_5->setVisible(false);
//    ui->pushButton_6->setVisible(false);
  setupUserButton();

  ui->Btn_PageDown->setVisible(true);
  ui->Btn_PageUp->setVisible(true);
  ui->CurPage->setVisible(true);
  ui->CurPage_2->setVisible(true);
  ui->label_4->setVisible(true);

    // 在翻页控件 label_4 ("/") 后面添加"字段组"标签
    QLabel *colGroupLabel = new QLabel("字段组", this);
    int idx = ui->horizontalLayout_8->indexOf(ui->label_4);
    if (idx >= 0) {
        ui->horizontalLayout_8->insertWidget(idx + 1, colGroupLabel);
    }
}


void MainWindow::on_actions_SQL_triggered()
{
    // 操作员（level 1）和未登录（level 0）不可打开设置
    if (m_currentLevel == 0 || m_currentLevel == 1) {
        QMessageBox::information(this, "无权限", "当前用户无权限修改配置。");
        return;
    }
    SQLSettingDialog dlg(this, m_currentLevel);
    connect(&dlg, &SQLSettingDialog::configChanged, this, &MainWindow::slot_sqlConfigChanged);
    dlg.exec();
}

void MainWindow::slot_sqlConfigChanged(const SqlConnectionConfig &config)
{
    Q_UNUSED(config)
    {   // 重新读取数据库连接配置
        const SqlConnectionConfig cfg = SQLConifg::loadConfig();
        MysqlSettings.hostName     = cfg.hostName;
        MysqlSettings.databaseName = cfg.databaseName;
        MysqlSettings.userName     = cfg.userName;
        MysqlSettings.password     = cfg.password;
        MysqlSettings.port         = QString::number(cfg.port);
        MysqlSettings.B_MYSQL_EN   = true;
    }
    m_queryFields = SQLConifg::loadQueryFields();
    reloadSqlRuntime();
}

void MainWindow::clearSqlTabsAndModels()
{
    ui->tabWidget->blockSignals(true);
    while (ui->tabWidget->count() > 0) {
        QWidget *tab = ui->tabWidget->widget(0);
        ui->tabWidget->removeTab(0);
        delete tab;
    }
    ui->tabWidget->blockSignals(false);

    m_dynamicSqlTabs.clear();
    m_dynamicSqlTabNames.clear();
    m_pageInfoMap.clear();

    for (auto it = m_MysqlThread->SqlModel.begin(); it != m_MysqlThread->SqlModel.end(); ++it) {
        delete it.value().mModel;
    }
    m_MysqlThread->SqlModel.clear();
    m_MysqlThread->Map_TableName.clear();
}

void MainWindow::reloadSqlRuntime()
{
    if (m_MysqlThread == nullptr) {
        return;
    }

    clearSqlTabsAndModels();

    const bool invoked = QMetaObject::invokeMethod(m_MysqlThread, "slot_reloadSqlConfig", Qt::BlockingQueuedConnection);
    if (!invoked || !m_MysqlThread->B_Connect) {
        QMessageBox::warning(this, "错误", "数据库重新连接失败，请检查 SQL 设置。");
        return;
    }

    m_MysqlThread->InitSQL();
    slots_sql_model_conn();

    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        QWidget *tabW = ui->tabWidget->widget(i);
        QString tabKey = m_dynamicSqlTabNames.value(tabW);
        if (tabKey.isEmpty()) continue;
        PageInfo info;
        info.columnPage = 1;
        info.columnsPerPage = ui->allPage->value();
        m_pageInfoMap[tabKey] = info;
    }
    m_currentTabIndex = ui->tabWidget->currentIndex();
    m_currentTabKey = currentSqlModelName();
    resetCurrentPage();
    ui->CurPage->setMaximum(1);
    ui->CurPage_2->setValue(1);
    ui->Btn_PageUp->setEnabled(false);
    ui->Btn_PageDown->setEnabled(false);
    updateQueryFieldLabels();
    QMessageBox::information(this, "提示", "SQL 设置已保存并刷新。");
}
void MainWindow::setWordList(const QStringList &words) {
    fullWordList = words;
}

QString MainWindow::getLastChineseChar(const QString &input) {
    if(input.isEmpty()) return "";
    QString prefix;
    for(const QChar &ch : input) {
        if(ch.unicode() >= 0x4E00 && ch.unicode() <= 0x9FA5) {
            prefix.append(ch);
        } else {
            break;
        }
    }
    return prefix;
}
void MainWindow::handleTextChange(const QString &text) {

    if(!text.isEmpty()) {
            QStringList filtered;
            for(const QString &word : fullWordList) {
                if(word.contains(text, Qt::CaseInsensitive)) {
                    filtered << word;
                }
            }
            list_model->setStringList(filtered);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
* @description 数据库模型绑定
* @param {QTableView*}
* @param {QSqlTableModel*}
* @returns {-}
* @date 2025-08-16 08:33:00
*/
void MainWindow::Database_Model_Binding(QTableView* TableView,QSqlTableModel* Model)
{
    TableView->setModel(Model);
    TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    TableView->horizontalHeader()->setStretchLastSection(false);
    TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    TableView->horizontalHeader()->setMinimumSectionSize(60);
}

/**
* @description 数据库模型绑定槽函数
* @param {}
* @param {}
* @returns {-}
* @date 2025-08-16 08:33:00
*/


void MainWindow::slots_sql_model_conn()
{
    ui->tabWidget->blockSignals(true);
    ui->tabWidget->tabBar()->setStyleSheet("QTabBar::tab { min-width: 120px; padding: 8px 28px 8px 16px; }");

    while (ui->tabWidget->count() > 0) {
        QWidget *tab = ui->tabWidget->widget(0);
        ui->tabWidget->removeTab(0);
        delete tab;
    }
    m_dynamicSqlTabs.clear();
    m_dynamicSqlTabNames.clear();
    for (auto it = m_MysqlThread->SqlModel.begin(); it != m_MysqlThread->SqlModel.end(); ++it) {
        if (it.value().mModel == nullptr) {
            continue;
        }

        QWidget *tabPage = new QWidget(ui->tabWidget);
        QVBoxLayout *layout = new QVBoxLayout(tabPage);
        layout->setContentsMargins(0, 0, 0, 0);
        QTableView *tableView = new QTableView(tabPage);
        tableView->setAlternatingRowColors(true);
        tableView->setSortingEnabled(false);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableView->horizontalHeader()->setMinimumSectionSize(60);
        layout->addWidget(tableView);
        Database_Model_Binding(tableView, it.value().mModel);

        // 模型重置（新查询数据到达）后标记加载完成 + 测量列宽 + 恢复列隐藏状态
        const QString tableName = it.key();
        connect(it.value().mModel, &QSqlQueryModel::modelReset, this, [this, tableView, tableName]() {
            if (m_pageInfoMap.contains(tableName)) {
                PageInfo &info = m_pageInfoMap[tableName];
                info.dataLoaded = true;
                info.dataLoading = false;
                if (tableName == m_currentTabKey) {
                    cacheColumnWidths(tableView);
                    applyColumnPageToView(tableView, info.columnPage, true);
                }
            }
        });

        const int tabIndex = ui->tabWidget->addTab(tabPage, tableName);
        if (canDeleteSqlTableMapping()) {
            QToolButton *closeButton = new QToolButton(ui->tabWidget);
            closeButton->setText("×");
            closeButton->setAutoRaise(true);
            closeButton->setCursor(Qt::PointingHandCursor);
            closeButton->setFixedSize(16, 16);
            closeButton->setStyleSheet(
                        "QToolButton { border: none; border-radius: 8px; color: #666666; font-size: 12px; padding: 0px; }"
                        "QToolButton:hover { background-color: #dcdcdc; color: #222222; }"
                        "QToolButton:pressed { background-color: #c8c8c8; }");
            connect(closeButton, &QToolButton::clicked, this, [this, tableName]() {
                deleteSqlTableMapping(tableName);
            });
            ui->tabWidget->tabBar()->setTabButton(tabIndex, QTabBar::RightSide, closeButton);
        }

        m_dynamicSqlTabs.append(tabPage);
        m_dynamicSqlTabNames.insert(tabPage, tableName);
    }

    // 缓存每张表的列名（用于"无相关字段"判断）
    m_cachedTableColumns.clear();
    for (auto it = m_MysqlThread->SqlModel.begin(); it != m_MysqlThread->SqlModel.end(); ++it) {
        QStringList cols;
        QSqlRecord rec = it.value().mModel->record();
        for (int i = 0; i < rec.count(); ++i) {
            cols << rec.fieldName(i);
        }
        m_cachedTableColumns[it.value().Tab_Name] = cols;
    }

    // 初始化所有标签页的分页信息（用 tableName 做 key）
    m_pageInfoMap.clear();
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        QWidget *tabW = ui->tabWidget->widget(i);
        QString tabKey = m_dynamicSqlTabNames.value(tabW);
        if (tabKey.isEmpty()) continue;
        PageInfo info;
        info.columnPage = 1;
        info.columnsPerPage = ui->allPage->value();
        m_pageInfoMap[tabKey] = info;
    }

    ui->tabWidget->blockSignals(false);
    m_currentTabIndex = ui->tabWidget->currentIndex();
    m_currentTabKey = currentSqlModelName();
    updateQueryFieldLabels();
}

//void MainWindow::slot_Load_Data(QString Tab_Name,QString str,int now_rows,int now_CurPage)
//{
////    myModel->setTable(Tab_Name);
////    myModel->select();
////    emit signals_setmodel(myModel);
////    QString selectStr = "SELECT * FROM "+Tab_Name+str+tr( " LIMIT %1 OFFSET %2").arg(now_rows).arg(now_CurPage);
////    qDebug()<<selectStr;
////    myModel->QSqlQueryModel::setQuery(selectStr);
//}

void MainWindow::on_Btn_Find_clicked()
{
    if (m_pageInfoMap.contains(m_currentTabKey)) {
        m_pageInfoMap[m_currentTabKey].dataLoaded = false;
    }
    m_cachedColumnWidths.remove(m_currentTabKey);
    resetCurrentPage();
    loadDataForCurrentPage();
}

void MainWindow::resetCurrentPage()
{
    PageInfo &info = m_pageInfoMap[m_currentTabKey];
    info.columnPage = 1;
    info.columnsPerPage = ui->allPage->value();

    QSignalBlocker blocker(ui->CurPage);
    ui->CurPage->setValue(1);
}

void MainWindow::loadDataForCurrentPage()
{
    loadDataForTab(m_currentTabKey, false);
}

void MainWindow::loadDataForTab(const QString &tableName, bool silent)
{
    if (!m_pageInfoMap.contains(tableName)) return;
    if (m_currentLevel == 0) return;

    if (!silent) {
        QMutexLocker locker(&m_exportMutex);
        if (m_bExporting) {
            QMessageBox::information(this, "提示", "正在导出数据，请稍后再试。");
            return;
        }
    }

    if (!m_MysqlThread->SqlModel.contains(tableName)) return;

    PageInfo &pageInfo = m_pageInfoMap[tableName];
    pageInfo.dataLoaded = false;
    pageInfo.dataLoading = true;
    m_cachedColumnWidths.remove(tableName);
    pageInfo.columnsPerPage = ui->allPage->value();

    auto emitModelQuery = [this, &tableName](const QString &whereClause) {
        if (m_MysqlThread->SqlModel.contains(tableName)) {
            int limit = ui->allPage->value();
            int offset = 0;
            emit signals_Load_Data_show(m_MysqlThread->SqlModel[tableName], whereClause, limit, offset);
        }
    };
    // 构建 WHERE 子句
    QString finalWhere = " where 1=1";

    // 从配置读取字段名（兜底用硬编码名）
    QString colFlowNumber = m_queryFields.value(2).columnName;
    if (colFlowNumber.isEmpty()) colFlowNumber = "流水号";

    // 精确查询（流水号/上线码/条码）优先级最高
    if (!ui->lineEdit_SerialN->text().isEmpty()) {
        qDebug() << "精确查询-流水号";
        finalWhere = QString(" where %1='%2'").arg(colFlowNumber, ui->lineEdit_SerialN->text());
    } else if (!ui->lineEdit_OnlineCode->text().isEmpty()) {
        qDebug() << "精确查询-上线码";
        QStringList flowernumber_list = emit signals_get_flowernumber("rfid_to_uplinecode",
            QString(" where 上线码='%1' or 返修码='%1'").arg(ui->lineEdit_OnlineCode->text()));
        qDebug() << flowernumber_list;
        if (flowernumber_list.isEmpty()) {
            if (!silent)
                QMessageBox::question(this, "询问", "查询不到此上线码，请重新输入。");
            return;
        }
        QStringList parts;
        for (const QString &fn : flowernumber_list)
            parts << QString("%1='%2'").arg(colFlowNumber, fn);
        finalWhere = " where " + parts.join(" or ");
    } else if (!ui->lineEdit_ComCode->text().isEmpty()) {
        qDebug() << "精确查询-条码";
        QStringList selParts;
        for (int i = 0; i < Assembly_cloumns.count(); ++i)
            selParts << QString("%1='%2'").arg(Assembly_cloumns.at(i), ui->lineEdit_ComCode->text());
        QStringList flowernumber_list = emit signals_get_flowernumber("datas_linecode_a1",
            QString(" where %1").arg(selParts.join(" or ")));
        if (flowernumber_list.isEmpty()) {
            if (!silent)
                QMessageBox::question(this, "询问", "查询不到此条码，请重新输入。");
            return;
        }
        QStringList parts;
        for (const QString &fn : flowernumber_list)
            parts << QString("%1='%2'").arg(colFlowNumber, fn);
        finalWhere = " where " + parts.join(" or ");
    } else {
        // 模糊查询
        qDebug() << "模糊查询";
        QStringList conditions;
        if (!ui->lineEdit_Name->text().isEmpty())
            conditions << QString("%1 like '%2'").arg(ui->lineEdit_Name->text(), ui->lineEdit_Condition->text());
        if (ui->comboBox_Result->currentText() != "") {
            QString resultField = m_MysqlThread->m_resultFieldMap.value(tableName);
            if (!resultField.isEmpty())
                conditions << QString("%1='%2'").arg(resultField, ui->comboBox_Result->currentText());
        }
        if (ui->comboBox_Status->currentText() != "")
            conditions << QString("模式='%1'").arg(ui->comboBox_Status->currentText());
        if (ui->ChB_date->isChecked()) {
            QString dateField = m_MysqlThread->m_dateFieldMap.value(tableName);
            if (dateField.isEmpty()) dateField = "日期";
            conditions << QString("%1>'%2' and %1<'%3'").arg(dateField, ui->dateEdit_Begin->text(), ui->dateEdit_End->text());
        }
        if (!conditions.isEmpty())
            finalWhere = " where " + conditions.join(" and ");
    }

    qDebug() << "finalWhere:" << finalWhere;
    emitModelQuery(finalWhere);
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug()<<"table:"<<index<<ui->tabWidget->currentIndex();
}


//上一页下一页按钮事件
//void MainWindow::updatePageControls(int totalPages, int currentPage)
//{
//    // 设置当前页控件的最大值（总页数）
//    ui->CurPage->setMaximum(totalPages);
//    // 设置当前页码（注意：如果当前页码已经正确，此行可防止重复触发查询�?
//    if (ui->CurPage->value() != currentPage) {
//        ui->CurPage->setValue(currentPage);
//    }
//    // 更新总页数显示
//    ui->CurPage_2->setValue(totalPages);

//    // 翻页按钮
//    // 假设按钮名为 Btn_PageUp �?Btn_PageDown
//     ui->Btn_PageUp->setEnabled(currentPage > 1);
//     ui->Btn_PageDown->setEnabled(currentPage < totalPages);
//}



void MainWindow::setupUserButton()
{
    ui->USER->setVisible(true);
    ui->USER->setIconSize(QSize(40, 40));
    ui->USER->setText("未登录");
    ui->USER->setFixedHeight(66);
    m_currentLevel = 0;
    updateUiForPermissionLevel();
    updateUserButtonStyle();
    connect(ui->USER, &QToolButton::clicked, this, &MainWindow::showLoginDialog);
}

bool MainWindow::canDeleteSqlTableMapping() const
{
    return m_currentLevel == 2 || m_currentLevel == 3;
}

void MainWindow::showLoginDialog()
{
    if (m_currentLevel > 0) {
        QMenu menu(this);
        QAction *switchUser = menu.addAction("切换用户");
        QAction *logout = menu.addAction("退出登录");
        QAction *chosen = menu.exec(QCursor::pos());
        if (chosen == logout) {
            logoutUser();
            return;
        }
        if (chosen != switchUser) return;
    }

    AccountDialog dlg(this);
    connect(&dlg, &AccountDialog::loginRequested, this, [&](const QString &user, const QString &pwd) {
        auto result = emit signals_checkLogin(user, pwd);
        if (result.first > 0) {
            QSettings settings(SQLConifg::settingsPath(), QSettings::IniFormat);
            settings.setValue("User/name", user);
            settings.setValue("User/level", result.first);
            settings.sync();
            m_currentLevel = result.first;
            ui->USER->setText(user);
            updateUiForPermissionLevel();
            updateUserButtonStyle();
            dlg.accept();
        } else {
            QMessageBox::warning(this, "登录失败", "用户名或密码错误，请重新输入。");
        }
    });
    dlg.exec();
}

void MainWindow::logoutUser()
{
    m_currentLevel = 0;
    ui->USER->setText("未登录");
    {
        QSettings settings(SQLConifg::settingsPath(), QSettings::IniFormat);
        settings.remove("User/name");
        settings.remove("User/level");
        settings.sync();
    }
    updateUserButtonStyle();
    updateUiForPermissionLevel();
}

void MainWindow::updateUserButtonStyle()
{
    QString iconPath;
    QString btnStyle;
    QString tooltip;

    switch (m_currentLevel) {
    case 0:
        iconPath = ":/new/prefix1/image/user.svg";
        btnStyle = "border:none; background:transparent; color:rgb(0, 0, 0); font-size:11px; margin-right:15px;";
        tooltip = "点击登录";
        break;
    case 1:
        iconPath = ":/new/prefix1/image/user_operator.png";
        btnStyle = "border:none; background:transparent; color:#2d8cf0; font-weight:bold; font-size:11px; margin-right:15px;";
        tooltip = "点击切换用户";
        break;
    case 2:
        iconPath = ":/new/prefix1/image/user.svg";
        btnStyle = "border:none; background:transparent; color:#f0ad4e; font-weight:bold; font-size:11px; margin-right:15px;";
        tooltip = "点击切换用户";
        break;
    case 3:
        iconPath = ":/new/prefix1/image/user.svg";
        btnStyle = "border:none; background:transparent; color:#d9534f; font-weight:bold; font-size:11px; margin-right:15px;";
        tooltip = "点击切换用户";
        break;
    default:
        iconPath = ":/new/prefix1/image/user.svg";
        btnStyle = "border:none; background:transparent; color:rgb(0, 0, 0); font-size:11px; margin-right:15px;";
        tooltip = "点击登录";
        break;
    }

    QIcon icon(iconPath);
    if (icon.isNull()) {
        icon = QIcon(":/new/prefix1/image/user.svg");
    }
    ui->USER->setIcon(icon);
    ui->USER->setStyleSheet(btnStyle);
    ui->USER->setToolTip(tooltip);
}

void MainWindow::updateUiForPermissionLevel()
{
    // 轻量更新：只增删 tab 关闭按钮，不断数据库、不重建 tab
    bool canClose = canDeleteSqlTableMapping();
    QTabBar *bar = ui->tabWidget->tabBar();
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        QWidget *tab = ui->tabWidget->widget(i);
        if (!m_dynamicSqlTabNames.contains(tab)) continue;
        const QString &tableName = m_dynamicSqlTabNames[tab];
        QWidget *btn = bar->tabButton(i, QTabBar::RightSide);
        if (canClose && !btn) {
            QToolButton *closeButton = new QToolButton(ui->tabWidget);
            closeButton->setText(QStringLiteral("\u00D7"));
            closeButton->setAutoRaise(true);
            closeButton->setCursor(Qt::PointingHandCursor);
            closeButton->setFixedSize(16, 16);
            closeButton->setStyleSheet(
                "QToolButton { border: none; border-radius: 8px; color: #666666; font-size: 12px; padding: 0px; }"
                "QToolButton:hover { background-color: #dcdcdc; color: #222222; }"
                "QToolButton:pressed { background-color: #c8c8c8; }");
            connect(closeButton, &QToolButton::clicked, this, [this, tableName]() {
                deleteSqlTableMapping(tableName);
            });
            bar->setTabButton(i, QTabBar::RightSide, closeButton);
        } else if (!canClose && btn) {
            bar->setTabButton(i, QTabBar::RightSide, nullptr);
            delete btn;
        }
    }
    // 更新按钮样式
    updateUserButtonStyle();
    qDebug() << "[Login] 权限已更新，当前等级:" << m_currentLevel;
}

void MainWindow::deleteSqlTableMapping(const QString &modelName)
{
    if (modelName.isEmpty() || !canDeleteSqlTableMapping()) {
        return;
    }

    SqlConnectionConfig config = SQLConifg::loadConfig();
    for (int i = config.tables.count() - 1; i >= 0; --i) {
        if (config.tables.at(i).tabName == modelName) {
            config.tables.removeAt(i);
        }
    }

    if (!SQLConifg::saveConfig(config)) {
        QMessageBox::warning(this, "删除失败", "写入 Data/Settings.ini 失败。");
        return;
    }

    QWidget *tabPage = m_dynamicSqlTabNames.key(modelName, nullptr);
    if (tabPage != nullptr) {
        const int index = ui->tabWidget->indexOf(tabPage);
        if (index >= 0) {
            ui->tabWidget->removeTab(index);
        }
        m_dynamicSqlTabs.removeAll(tabPage);
        m_dynamicSqlTabNames.remove(tabPage);
        delete tabPage;
    }

    QMessageBox::information(this, "提示", "表映射已删除，重启程序后完全生效。");
}
QString MainWindow::currentSqlModelName() const
{
    return m_dynamicSqlTabNames.value(ui->tabWidget->currentWidget());
}

//横滚辅助函数
QTableView* MainWindow::getCurrentTableView()
{
    return ui->tabWidget->currentWidget() ? ui->tabWidget->currentWidget()->findChild<QTableView*>() : nullptr;
}

QStringList MainWindow::currentModelColumns(const QSqlQueryModel *model) const
{
    QStringList columns;
    if (model == nullptr) {
        return columns;
    }

    const int columnCount = model->columnCount();
    columns.reserve(columnCount);
    for (int i = 0; i < columnCount; ++i) {
        columns << model->headerData(i, Qt::Horizontal).toString();
    }
    return columns;
}

void MainWindow::cacheColumnWidths(QTableView *view)
{
    if (!view) return;
    auto *model = qobject_cast<QSqlQueryModel*>(view->model());
    if (!model) return;
    const int colCount = model->columnCount();
    if (colCount <= 0) return;

    QString tabKey = m_currentTabKey;
    QVector<int> widths(colCount, 80);

    // 临时显示所有列，用 ResizeToContents 测量内容宽度
    QHeaderView *header = view->horizontalHeader();
    QVector<bool> hiddenBackup(colCount);
    for (int i = 0; i < colCount; ++i) {
        hiddenBackup[i] = view->isColumnHidden(i);
        view->setColumnHidden(i, false);
    }

    header->setSectionResizeMode(QHeaderView::ResizeToContents);
    QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);

    for (int i = 0; i < colCount; ++i) {
        widths[i] = qMax(60, header->sectionSize(i));
    }

    // 恢复隐藏状态和 Interactive 模式
    header->setSectionResizeMode(QHeaderView::Interactive);
    for (int i = 0; i < colCount; ++i) {
        view->setColumnHidden(i, hiddenBackup[i]);
    }

    m_cachedColumnWidths[tabKey] = widths;
}

int MainWindow::columnPageSizeForView(const QTableView *view) const
{
    if (!view) return 10;
    const int viewportWidth = view->viewport()->width();
    if (viewportWidth <= 0) return 10;

    QString tabKey = m_currentTabKey;
    if (!m_cachedColumnWidths.contains(tabKey)) return 10;

    const QVector<int> &widths = m_cachedColumnWidths[tabKey];
    const int colCount = widths.size();
    if (colCount <= 0) return 10;

    int totalWidth = 0;
    int colsThatFit = 0;
    for (int i = 0; i < colCount; ++i) {
        if (colsThatFit == 0 || totalWidth + widths[i] <= viewportWidth) {
            totalWidth += widths[i];
            ++colsThatFit;
        } else {
            break;
        }
    }

    return qMax(1, colsThatFit);
}

void MainWindow::applyColumnPageToView(QTableView *view, int pageIndex, bool updateControls)
{
    if (view == nullptr) {
        return;
    }

    auto *model = qobject_cast<QSqlQueryModel*>(view->model());
    if (model == nullptr) {
        return;
    }

    const int columnCount = model->columnCount();
    if (columnCount <= 0) {
        return;
    }

    PageInfo &info = m_pageInfoMap[m_currentTabKey];

    // 如果还没有缓存宽度，先测量
    if (!m_cachedColumnWidths.contains(m_currentTabKey)) {
        cacheColumnWidths(view);
    }

    // 从缓存计算每页列数
    const int pageSize = columnPageSizeForView(view);
    info.columnPageSize = pageSize;

    // 简单分页：不重叠，页面边界清晰
    const int totalPages = qMax(1, (columnCount + pageSize - 1) / pageSize);
    const int currentPage = qBound(1, pageIndex, totalPages);
    const int startColumn = (currentPage - 1) * pageSize;
    const int endColumn = qMin(startColumn + pageSize, columnCount);

    view->setUpdatesEnabled(false);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 先隐藏所有列，再显示当前页的列
    for (int i = 0; i < columnCount; ++i) {
        view->setColumnHidden(i, true);
    }
    for (int i = startColumn; i < endColumn; ++i) {
        view->setColumnHidden(i, false);
    }

    // 获取缓存宽度
    const QVector<int> &cachedWidths = m_cachedColumnWidths[m_currentTabKey];
    int totalContentWidth = 0;
    QVector<int> visibleIndices;
    for (int i = startColumn; i < endColumn; ++i) {
        if (i < cachedWidths.size()) {
            totalContentWidth += cachedWidths[i];
            visibleIndices.append(i);
        }
    }

    const int viewportWidth = view->viewport()->width();

    // 分配宽度：只拉伸不压缩（留白可接受）
    if (totalContentWidth > 0 && viewportWidth > 0 && !visibleIndices.isEmpty()) {
        if (totalContentWidth < viewportWidth) {
            // 内容窄于视口 → 按比例拉伸填满
            double ratio = (double)viewportWidth / totalContentWidth;
            int allocated = 0;
            for (int vi = 0; vi < visibleIndices.size(); ++vi) {
                int col = visibleIndices[vi];
                int w;
                if (vi == visibleIndices.size() - 1) {
                    w = viewportWidth - allocated;
                } else {
                    w = (int)(cachedWidths[col] * ratio);
                    allocated += w;
                }
                view->horizontalHeader()->resizeSection(col, w);
            }
        } else {
            // 内容≥视口 → 直接使用内容宽度，不压缩列宽，允许留白
            for (int vi = 0; vi < visibleIndices.size(); ++vi) {
                int col = visibleIndices[vi];
                view->horizontalHeader()->resizeSection(col, cachedWidths[col]);
            }
        }
    }

    view->setUpdatesEnabled(true);
    view->viewport()->update();

    info.columnPage = currentPage;
    info.totalColumnPages = totalPages;

    if (updateControls) {
        QSignalBlocker curBlocker(ui->CurPage);
        ui->CurPage->setMaximum(totalPages);
        ui->CurPage->setValue(currentPage);
        ui->CurPage_2->setValue(totalPages);
        ui->Btn_PageUp->setEnabled(currentPage > 1);
        ui->Btn_PageDown->setEnabled(currentPage < totalPages);
    }
}

void MainWindow::applyColumnPageToCurrentView()
{
    applyColumnPageToView(getCurrentTableView(), m_pageInfoMap.value(m_currentTabKey).columnPage, true);
}

void MainWindow::updateQueryFieldLabels()
{
    QString dbTableName;
    if (m_MysqlThread && m_MysqlThread->SqlModel.contains(m_currentTabKey)) {
        dbTableName = m_MysqlThread->SqlModel[m_currentTabKey].Tab_Name;
    }

    QStringList currentCols;
    if (!dbTableName.isEmpty() && m_cachedTableColumns.contains(dbTableName)) {
        currentCols = m_cachedTableColumns.value(dbTableName);
    }

    // 三个搜索字段对应的 label 和 lineEdit
    QPair<QLabel*, QLineEdit*> fields[] = {
        {ui->label_2, ui->lineEdit_ComCode},
        {ui->label_3, ui->lineEdit_OnlineCode},
        {ui->label_5, ui->lineEdit_SerialN}
    };

    for (int i = 0; i < m_queryFields.size() && i < 3; ++i) {
        QLabel *label = fields[i].first;
        QLineEdit *edit = fields[i].second;
        const QueryFieldConfig &cfg = m_queryFields[i];

        if (cfg.lookupTable.isEmpty()) {
            // 直接查当前表 → 检查列是否存在
            if (currentCols.contains(cfg.columnName)) {
                label->setText(cfg.displayName + "：");
                edit->setEnabled(true);
                edit->setPlaceholderText("");
            } else {
                label->setText(cfg.displayName + "：(无相关字段)");
                edit->setEnabled(false);
                edit->setPlaceholderText("当前表无此字段");
                edit->clear();
            }
        } else {
            // 跨表查询 → 始终可用
            label->setText(cfg.displayName + "：");
            edit->setEnabled(true);
            edit->setPlaceholderText("");
        }
    }
}

void MainWindow::on_Btn_PageDown_clicked()
{
    if (!m_pageInfoMap.contains(m_currentTabKey)) return;
    PageInfo &info = m_pageInfoMap[m_currentTabKey];
    if (info.columnPage >= info.totalColumnPages) return;

    QTableView *view = getCurrentTableView();
    if (!view) return;
    applyColumnPageToView(view, info.columnPage + 1, true);
}

void MainWindow::on_Btn_PageUp_clicked()
{
    if (!m_pageInfoMap.contains(m_currentTabKey)) return;
    PageInfo &info = m_pageInfoMap[m_currentTabKey];
    if (info.columnPage <= 1) return;

    QTableView *view = getCurrentTableView();
    if (!view) return;
    applyColumnPageToView(view, info.columnPage - 1, true);
}
void MainWindow::onTabChanged(int index)
{
    if (index < 0) return;

    // 保存旧 tab 状态（columnsPerPage）
    if (m_pageInfoMap.contains(m_currentTabKey)) {
        PageInfo &oldInfo = m_pageInfoMap[m_currentTabKey];
        oldInfo.columnsPerPage = ui->allPage->value();
    }

    m_currentTabIndex = index;
    m_currentTabKey = currentSqlModelName();
    if (!m_pageInfoMap.contains(m_currentTabKey)) {
        PageInfo info;
        info.columnPage = 1;
        info.columnsPerPage = ui->allPage->value();
        m_pageInfoMap[m_currentTabKey] = info;
    }

    const PageInfo &newInfo = m_pageInfoMap[m_currentTabKey];
    QSignalBlocker curPageBlocker(ui->CurPage);
    QSignalBlocker allPageBlocker(ui->allPage);
    ui->CurPage->setValue(1);
    ui->allPage->setValue(newInfo.columnsPerPage);
    ui->Btn_PageUp->setEnabled(false);
    ui->Btn_PageDown->setEnabled(false);

    // 懒加载逻辑
    if (newInfo.dataLoaded) {
        // 数据已缓存 → 直接恢复列显示，不查库
        applyColumnPageToCurrentView();
        updateQueryFieldLabels();
        return;
    }

    if (newInfo.dataLoading) {
        // 数据正在加载中 → 等待 modelReset 自动更新 UI
        return;
    }

    // 数据从未加载过 → 触发查询
    loadDataForCurrentPage();
}
//映射标签页信息到�?
void MainWindow::updatePageControls(int totalRows, int limit)
{
    applyColumnPageToCurrentView();
}
QString MainWindow::buildWhereClause()
{
    // 精确查询（流水号/条码）优先级最高
    if (!ui->lineEdit_SerialN->text().isEmpty()) {
        return QString(" where 流水号='%1'").arg(ui->lineEdit_SerialN->text());
    }

    if (!ui->lineEdit_OnlineCode->text().isEmpty()) {
        // 注意：这里需要异步获取流水号列表，导出时建议保持与查询一致的逻辑�?
        // 但为了简化，你可以暂时只支持单一流水号精确查询，或者把获取流水号的逻辑复制过来�?
        // 下面给出一个同步获取的示例（需要确认signals_get_flowernumber 是阻塞的�?
        QStringList flowernumber_list = emit signals_get_flowernumber("rfid_to_uplinecode",
            QString(" where 上线码='%1' or 返修码='%1'").arg(ui->lineEdit_OnlineCode->text()));
        if (flowernumber_list.size() == 1) {
            return QString(" where 流水号='%1'").arg(flowernumber_list.at(0));
        } else if (flowernumber_list.size() > 1) {
            QStringList conditions;
            for (const QString& fn : flowernumber_list) {
                conditions << QString("流水号='%1'").arg(fn);
            }
            return " where (" + conditions.join(" or ") + ")";
        }
    }

    if (!ui->lineEdit_ComCode->text().isEmpty()) {
        QString sel;
        for (int i = 0; i < Assembly_cloumns.size(); ++i) {
            if (i == 0)
                sel = QString("%1='%2'").arg(Assembly_cloumns.at(i), ui->lineEdit_ComCode->text());
            else
                sel += " or " + QString("%1='%2'").arg(Assembly_cloumns.at(i), ui->lineEdit_ComCode->text());
        }
        QStringList flowernumber_list = emit signals_get_flowernumber("datas_linecode_a1", QString(" where %1").arg(sel));
        if (flowernumber_list.isEmpty()) {
            QMessageBox::question(this, "询问", "查询不到此条码，导出取消。");
            return QString(); // 返回空表示无法导出
        } else if (flowernumber_list.size() == 1) {
            return QString(" where 流水号='%1'").arg(flowernumber_list.at(0));
        } else {
            QStringList conditions;
            for (const QString& fn : flowernumber_list) {
                conditions << QString("流水号='%1'").arg(fn);
            }
            return " where (" + conditions.join(" or ") + ")";
        }
    }
    // 模糊查询条件
    QStringList whereParts;
    if (!ui->lineEdit_Name->text().isEmpty() && !ui->lineEdit_Condition->text().isEmpty()) {
        whereParts << QString("%1 like '%2'").arg(ui->lineEdit_Name->text(), ui->lineEdit_Condition->text());
    }
    if (ui->comboBox_Result->currentText() != "") {
        QString resultField = m_MysqlThread->m_resultFieldMap.value(m_currentTabKey);
        if (!resultField.isEmpty())
            whereParts << QString("%1='%2'").arg(resultField, ui->comboBox_Result->currentText());
    }
    if (ui->comboBox_Status->currentText() != "") {
        whereParts << QString("模式='%1'").arg(ui->comboBox_Status->currentText());
    }
    if (ui->ChB_date->isChecked()) {
        QString dateField = m_MysqlThread->m_dateFieldMap.value(m_currentTabKey);
        if (dateField.isEmpty()) dateField = "日期";
        whereParts << QString("%1>'%2' and %1<'%3'").arg(dateField,
                                                        ui->dateEdit_Begin->text(),
                                                        ui->dateEdit_End->text());
    }

    if (whereParts.isEmpty()) {
        return " where 1=1";  // 无额外条件，但保证语法正确
    } else {
        return " where " + whereParts.join(" and ");
    }
}
//导出辅助函数
void MainWindow::enableAllControls()
{
    ui->Btn_Find->setEnabled(true);
    ui->Btn_PageUp->setEnabled(true);
    ui->Btn_PageDown->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->CurPage->setEnabled(true);
    ui->allPage->setEnabled(true);
    ui->lineEdit_SerialN->setEnabled(true);
    ui->lineEdit_OnlineCode->setEnabled(true);
    ui->lineEdit_ComCode->setEnabled(true);
    ui->lineEdit_Name->setEnabled(true);
    ui->lineEdit_Condition->setEnabled(true);
    ui->comboBox_Result->setEnabled(true);
    ui->comboBox_Status->setEnabled(true);
    ui->ChB_date->setEnabled(true);
    ui->dateEdit_Begin->setEnabled(true);
    ui->dateEdit_End->setEnabled(true);
}
//导出辅助函数
void MainWindow::finalizeExport(bool success, const QString &message)
{
    // 解锁导出标志
    QMutexLocker locker(&m_exportMutex);
    m_bExporting = false;

    // 恢复按钮
    enableAllControls();

    // 弹出结果
    if (success) {
        QMessageBox::information(this, "完成", message);
    } else {
        QMessageBox::warning(this, "错误", message);
    }

    // 发射导出完成信号（供其他模块监听�?
    emit exportCompleted(success, message);
}
//发起导出
void MainWindow::slot_startExport()
{
    // 互斥锁保护，防止重复导出
    QMutexLocker locker(&m_exportMutex);
    if (m_bExporting) {
        QMessageBox::information(this, "提示", "导出正在进行中，请稍候...");
        return;
    }
    m_bExporting = true;

    // 禁用所有查询控件
    ui->Btn_Find->setEnabled(false);
    ui->Btn_PageUp->setEnabled(false);
    ui->Btn_PageDown->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->CurPage->setEnabled(false);
    ui->allPage->setEnabled(false);
    ui->lineEdit_SerialN->setEnabled(false);
    ui->lineEdit_OnlineCode->setEnabled(false);
    ui->lineEdit_ComCode->setEnabled(false);
    ui->lineEdit_Name->setEnabled(false);
    ui->lineEdit_Condition->setEnabled(false);
    ui->comboBox_Result->setEnabled(false);
    ui->comboBox_Status->setEnabled(false);
    ui->ChB_date->setEnabled(false);
    ui->dateEdit_Begin->setEnabled(false);
    ui->dateEdit_End->setEnabled(false);

    // 构建 WHERE 子句（该函数可能触发阻塞信号获取流水号，可以接受�?
    QString whereClause = buildWhereClause();
    if (whereClause.isEmpty()) {
        // 出错恢复
        m_bExporting = false;
        enableAllControls();   // 自定义函数恢复控�?
        return;
    }

    // 弹出确认对话框
    QMessageBox::StandardButton btn = QMessageBox::question(this, "确认导出",
        QString("导出位置：桌面/ExportData/"),
        QMessageBox::Yes | QMessageBox::No);
    if (btn != QMessageBox::Yes) {
        m_bExporting = false;
        enableAllControls();
        return;
    }

    // 显示进度对话框（模式对话框，有自己的事件循环�?
    m_progressDlg = new QProgressDialog("正在查询数据，请稍候...", "取消", 0, 0, this);
    m_progressDlg->setWindowModality(Qt::WindowModal);
    m_progressDlg->setMinimumDuration(0);          // 立即显示
    m_progressDlg->setValue(0);
    m_progressDlg->setCancelButton(nullptr);      // 不允许取消（或自行处理）
    m_progressDlg->show();

    // 请求子线程开始查询数据（异步�?
    emit signals_requestExportData(whereClause);
}

//void MainWindow::slot_writeExcel(QList<TableData> allData)
//{
//    // 关闭查询中的进度对话框
//    if (m_progressDlg) {
//        m_progressDlg->close();
//        delete m_progressDlg;
//        m_progressDlg = nullptr;
//    }

//    // 确保导出目录存在（桌面路径，兼容所有电脑）
//    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
//    QDir dir(desktopPath + "/ExportData");
//    if (!dir.exists()) {
//        dir.mkpath(".");
//    }

//    QString dateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
//    QString filePath = QString("%1/ExportData/Export_%2.xlsm").arg(desktopPath).arg(dateTime);

//    // 创建 Excel 进度对话框
//    QProgressDialog excelProgress("正在生成Excel文件，请稍候...", "取消", 0, 100, this);
//    excelProgress.setWindowModality(Qt::WindowModal);
//    excelProgress.setMinimumDuration(0);
//    excelProgress.setValue(0);
//    excelProgress.show();
//    QApplication::processEvents();

//    // 使用 QAxObject 操作 Excel（主线程 STA 兼容�?
//    QAxObject* excel = new QAxObject("Excel.Application", this);
//    if (excel->isNull()) {
//        QMessageBox::warning(this, "错误", "无法创建 Excel 对象，请确保已安�?Microsoft Excel�?);
//        delete excel;
//        finalizeExport(false, "创建Excel失败");
//        return;
//    }

//    excel->setProperty("DisplayAlerts", false);
//    QAxObject* workbooks = excel->querySubObject("Workbooks");
//    QAxObject* workbook = workbooks->querySubObject("Add");
//    QAxObject* worksheets = workbook->querySubObject("Worksheets");

//    int sheetIndex = 1;
//    int totalSheets = allData.size();
//    for (int i = 0; i < totalSheets; ++i) {
//        const TableData &data = allData.at(i);
//        if (data.columns.isEmpty()) continue;

//        // 获取或创建工作表
//        QAxObject* sheet = nullptr;
//        if (sheetIndex == 1) {
//            sheet = worksheets->querySubObject("Item(int)", 1);
//        } else {
//            sheet = worksheets->querySubObject("Add()");
//        }
//        sheet->setProperty("Name", data.sheetName.left(31));

//        // 批量写入标题行和数据（使用一维Variant数组逐列写入�?
//        int colCount = data.columns.size();
//        int totalRows = data.rows.size();

//        if (colCount > 0 && totalRows > 0) {
//            // 写入标题行
//            for (int col = 0; col < colCount; ++col) {
//                QAxObject* cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
//                cell->setProperty("Value", data.columns.at(col));
//                delete cell;
//            }

//            // 批量写入数据 - 每行作为一个Variant数组
//            for (int r = 0; r < totalRows; ++r) {
//                const auto &rowData = data.rows[r];
//                for (int c = 0; c < rowData.size(); ++c) {
//                    QAxObject* cell = sheet->querySubObject("Cells(int,int)", r + 2, c + 1);
//                    cell->setProperty("Value", rowData.at(c));
//                    delete cell;
//                }
//                // �?00行处理一次事件
//                if (r > 0 && r % 500 == 0) {
//                    QApplication::processEvents();
//                }
//            }
//        } else if (colCount > 0) {
//            // 只有标题行
//            for (int col = 0; col < colCount; ++col) {
//                QAxObject* cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
//                cell->setProperty("Value", data.columns.at(col));
//                delete cell;
//            }
//        }

//        // 自动调整列宽
//        QAxObject* usedRange = sheet->querySubObject("UsedRange");
//        if (usedRange) {
//            QAxObject* columnsRange = usedRange->querySubObject("Columns");
//            if (columnsRange) {
//                columnsRange->dynamicCall("AutoFit");
//            }
//        }

//        ++sheetIndex;

//        // 更新进度�?
//        int progress = (i + 1) * 100 / totalSheets;
//        excelProgress.setValue(progress);
//        QApplication::processEvents();
//    }

//    // 删除多余工作表
//    int totalSht = worksheets->property("Count").toInt();
//    for (int i = totalSht; i > sheetIndex - 1; --i) {
//        QAxObject* lastSheet = worksheets->querySubObject("Item(int)", i);
//        if (lastSheet) lastSheet->dynamicCall("Delete");
//    }

//    // 保存并退出
//    workbook->dynamicCall("SaveAs(const QString&, int)", QDir::toNativeSeparators(filePath), 52);
//    workbook->dynamicCall("Close()");
//    excel->dynamicCall("Quit()");
//    delete excel;

//    excelProgress.close();
//    finalizeExport(true, QString("导出成功！\n文件位置：%1").arg(filePath));
//}

void MainWindow::slot_writeExcel(QList<TableData> allData)
{
     qDebug() << "[Export] slot_writeExcel 被调用，表数据" << allData.size();
    // 关闭查询中的进度对话框
    if (m_progressDlg) {
        m_progressDlg->close();
        delete m_progressDlg;
        m_progressDlg = nullptr;
    }

    // 1. 准备路径
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktopPath + "/ExportData");
    if (!dir.exists()) dir.mkpath(".");
    QString dateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString filePath = QString("%1/ExportData/Export_%2.xlsm").arg(desktopPath).arg(dateTime);

    // 2. 尝试创建 Excel 对象
    QAxObject* excel = new QAxObject("Excel.Application", this);
    if (excel->isNull()) {
        qDebug() << "[Export] 创建 Excel 对象失败，降级 CSV";
        QMessageBox::warning(this, "导出失败", "无法创建 Excel 对象，将导出为 CSV 文件。");
        delete excel;
        exportToCsvFallback(allData, filePath);
        return;
    }
    qDebug() << "[Export] Excel 对象创建成功";
    excel->setProperty("DisplayAlerts", false);
    excel->setProperty("ScreenUpdating", false);

    // 3. 获取 Workbooks
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    if (!workbooks || workbooks->isNull()) {
           qDebug() << "[Export] 获取 Workbooks 失败，降级 CSV";
        QMessageBox::warning(this, "导出失败", "无法获取 Excel Workbooks，将导出为 CSV 文件。");
        excel->dynamicCall("Quit()");
        delete excel;
        exportToCsvFallback(allData, filePath);
        return;
    }
    qDebug() << "[Export] 获取 Workbooks 成功";
    // 4. 新建工作表
    QAxObject* workbook = workbooks->querySubObject("Add");
    if (!workbook || workbook->isNull()) {
        QMessageBox::warning(this, "导出失败", "无法创建 Excel 工作簿，将导出为 CSV 文件。");
        workbooks->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete workbooks;
        delete excel;
        exportToCsvFallback(allData, filePath);
        return;
    }

    // 5. 获取 Worksheets
    QAxObject* worksheets = workbook->querySubObject("Worksheets");
    if (!worksheets || worksheets->isNull()) {
        QMessageBox::warning(this, "导出失败", "无法获取 Excel 工作表，将导出为 CSV 文件。");
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete workbook;
        delete workbooks;
        delete excel;
        exportToCsvFallback(allData, filePath);
        return;
    }

    // 6. 显示 Excel 进度�?
    QProgressDialog excelProgress("正在生成Excel文件，请稍候...", "取消", 0, 100, this);
    excelProgress.setWindowModality(Qt::WindowModal);
    excelProgress.setMinimumDuration(0);
    excelProgress.setValue(0);
    excelProgress.show();
    QApplication::processEvents();

    int sheetIndex = 1;
    int totalSheets = allData.size();
    bool writeSuccess = true;

    for (int i = 0; i < totalSheets && writeSuccess; ++i) {
        const TableData& data = allData.at(i);
        if (data.columns.isEmpty()) continue;

        // 获取或创建工作表
        QAxObject* sheet = nullptr;
        if (sheetIndex == 1) {
            sheet = worksheets->querySubObject("Item(int)", 1);
        } else {
            sheet = worksheets->querySubObject("Add()");
        }

        if (!sheet || sheet->isNull()) {
            qDebug() << "跳过工作表：" << data.sheetName;
            continue;
        }

        sheet->setProperty("Name", data.sheetName.left(31));

        int colCount = data.columns.size();
        int rowCount = data.rows.size();

        // 构建二维 QVariant 数组，一次性写入整个 Range
        // 第一行是标题，之后是数据行
        QVariantList allRows;
        allRows.reserve(1 + rowCount);

        // 标题行
        QVariantList headerRow;
        headerRow.reserve(colCount);
        for (int col = 0; col < colCount; ++col)
            headerRow << data.columns.at(col);
        allRows << QVariant(headerRow);

        // 数据行
        for (int r = 0; r < rowCount; ++r) {
            const auto& srcRow = data.rows[r];
            QVariantList rowData;
            rowData.reserve(srcRow.size());
            for (int c = 0; c < srcRow.size(); ++c)
                rowData << srcRow.at(c);
            allRows << QVariant(rowData);

            if (r % 5000 == 0) {
                QApplication::processEvents();
                if (excelProgress.wasCanceled()) {
                    writeSuccess = false;
                    break;
                }
            }
        }

        if (writeSuccess) {
            // 计算 Range 范围："A1:XX最后行"
            auto columnLetter = [](int col) -> QString {
                QString result;
                while (col > 0) {
                    col--;
                    result.prepend(QChar('A' + (col % 26)));
                    col /= 26;
                }
                return result;
            };
            QString endCol = columnLetter(colCount);
            QString endRow = QString::number(1 + rowCount);
            QString rangeStr = QString("A1:%1%2").arg(endCol).arg(endRow);
            QAxObject* range = sheet->querySubObject("Range(const QString&)", rangeStr);
            if (range) {
                range->setProperty("Value", QVariant(allRows));
                delete range;
            }
        }

        // 自动调整列宽
        {
            QAxObject* usedRange = sheet->querySubObject("UsedRange");
            if (usedRange) {
                QAxObject* columnsRange = usedRange->querySubObject("Columns");
                if (columnsRange) {
                    columnsRange->dynamicCall("AutoFit");
                }
            }
        }

        ++sheetIndex;
        int progress = (i + 1) * 100 / totalSheets;
        excelProgress.setValue(progress);
    }

    excelProgress.close();

    // 删除多余工作表
    if (writeSuccess) {
        int totalSht = worksheets->property("Count").toInt();
        for (int i = totalSht; i > sheetIndex - 1; --i) {
            QAxObject* lastSheet = worksheets->querySubObject("Item(int)", i);
            if (lastSheet) lastSheet->dynamicCall("Delete");
        }

        // 保存并退出
        excel->setProperty("ScreenUpdating", true);
        workbook->dynamicCall("SaveAs(const QString&, int)", QDir::toNativeSeparators(filePath), 52);
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete excel;
        finalizeExport(true, QString("导出成功！\n文件位置：%1").arg(filePath));
    } else {
        // 用户取消或写入失败
        excel->setProperty("ScreenUpdating", true);
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete excel;
        finalizeExport(false, "导出已取消或写入出错。");
    }
}

// 降级为 CSV 导出（在头文件中声明）
void MainWindow::exportToCsvFallback(const QList<TableData>& allData, const QString& excelPath)
{
    qDebug() << "[Export] 降级为 CSV 导出";
    QString csvPath = excelPath;
    csvPath.replace(".xlsm", ".csv");
    QFile file(csvPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        finalizeExport(false, "无法创建 CSV 文件。");
        return;
    }
    QTextStream out(&file);
    // 写入 BOM，让 Excel 正确识别中文

    out << QChar(0xFEFF);

    for (const auto& data : allData) {
        out << "[" << data.sheetName << "]\n";
        out << data.columns.join(",") << "\n";
        for (const auto& row : data.rows) {
            QStringList rowStr;
            for (const QVariant& val : row) {
                QString s = val.toString();
                s.replace("\"", "\"\"");  // 转义双引号
                rowStr << "\"" + s + "\"";
            }
            out << rowStr.join(",") << "\n";
        }
        out << "\n";
    }
    file.close();
    qDebug() << "[Export] CSV 导出完成";
    finalizeExport(true, QString("Excel 不可用，已导出为 CSV 文件：%1").arg(csvPath));
}


//覆盖
void MainWindow::on_pushButton_ExportAll_clicked()
{
    slot_startExport();
}
//void MainWindow::on_pushButton_ExportAll_clicked()
//{
//    QString whereClause = buildWhereClause();
//    if (whereClause.isEmpty()) {
//        return;
//    }

//    QMessageBox::StandardButton btn = QMessageBox::question(this, "确认导出",
//        QString("导出位置：D:/MysqlData/"),
//        QMessageBox::Yes | QMessageBox::No);
//    if (btn != QMessageBox::Yes)
//        return;

//    // 发射信号，让导出在子线程中执�?
//    //emit signals_export_all_data(whereClause);
//}

// 更新导出进度显示
void MainWindow::slot_updateExportProgress(int currentTable, int totalTables, int currentBatch, int totalBatches, QString sheetName)
{
    if (currentTable == -1) {
        // 错误情况
        QMessageBox::warning(this, "错误", "创建Excel失败，请确保已安装Microsoft Excel。");
        m_bExporting = false;
        enableAllControls();
        return;
    }

    if (sheetName == "完成") {
        // 导出完成
        m_bExporting = false;
        enableAllControls();
        if (m_progressDlg) {
            m_progressDlg->close();
            delete m_progressDlg;
            m_progressDlg = nullptr;
        }
        return;
    }

    // 更新进度对话框
    if (m_progressDlg) {
        QString text = QString("正在导出: %1\n%2/%3, 批次%4/%5")
            .arg(sheetName)
            .arg(currentTable).arg(totalTables)
            .arg(currentBatch).arg(totalBatches);
        m_progressDlg->setLabelText(text);

        // 计算百分比
        int totalProgress = (currentTable - 1) * 100 / totalTables;
        int tableProgress = currentBatch * 100 / totalBatches / totalTables;
        int progress = totalProgress + tableProgress;
        m_progressDlg->setValue(progress);
    }
}




