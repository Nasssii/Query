#include "finddata.h"
#include "ui_finddata.h"
#include "QMetaType"
#include "sqlconifg.h"
#include <QStandardPaths>
#include <QDir>
Finddata *m_finddata;
mMysqlThread *m_MysqlThread;

S_6 MysqlSettings;


//日期代码
Finddata::Finddata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Finddata)
{
    ui->setupUi(this);
    //ui->dateEdit_End->setTime(QDateTime::currentDateTime().toLocalTime());
    ui->dateEdit_End->setDateTime(QDateTime::currentDateTime());
    //ui->dateEdit_Begin->setdate(QDateTime::currentDateTime().date().addDays(-2));
    ui->dateEdit_Begin->setDate(QDateTime::currentDateTime().date().addDays(-7));

//    MysqlSettings.hostName = "127.0.0.1";
//    MysqlSettings.databaseName = "sql_jianghuai";
//    MysqlSettings.userName = "admin1";
//    MysqlSettings.password = "123456";
//    connect(ui->pushButton, &QPushButton::clicked, this, &Finddata::on_Btn_ExportAll_clicked);
}

Finddata::~Finddata()
{
    delete ui;
}

void Finddata::on_Btn_Find_clicked()
{
    if( ui->comboBox->currentText() == NULL ){
        QMessageBox::warning(this, "错误", QString("请选择数据表格"), QMessageBox::Yes);
        return;
    }
    ui->CurPage->setValue(1);
    QString tablename;
    tablename = ui->comboBox->currentText();
    QString str="";
    //str = QString("time>'%1' and time<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());
    str = QString("生产日期>'%1' and 生产日期<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());
    if( !ui->ChB_date->isChecked()){
        str = "1=1";
    }
    emit signals_load_data(tablename," where "+str,ui->allPage->value(),ui->allPage->value()*(ui->CurPage->value()-1));
}

void Finddata::slots_setmodel(QSqlTableModel *mModel)
{
    ui->tableView->setModel(mModel);
}

void Finddata::on_Btn_PageDown_clicked()
{
    QString tablename;
    QString str="";
    tablename = ui->comboBox->currentText();
    //str = QString("time>'%1' and time<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());
    str = QString("生产日期>'%1' and 生产日期<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());

    int cur_number = ui->CurPage->value();
    ui->CurPage->setValue(cur_number + 1);
    if( !ui->ChB_date->isChecked()){
        str = "1=1";
    }
    emit signals_load_data(tablename," where "+str,ui->allPage->value(),ui->allPage->value()*(ui->CurPage->value()-1));
}

void Finddata::on_Btn_PageUp_clicked()
{
    QString tablename;
    QString str="";
    tablename = ui->comboBox->currentText();
    //str = QString("time>'%1' and time<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());
    str = QString("生产日期>'%1' and 生产日期<'%2'").arg(ui->dateEdit_Begin->text()).arg(ui->dateEdit_End->text());

    int cur_number = ui->CurPage->value();
    cur_number = cur_number>1 ? cur_number-1:1;//if(cur_number>1) true:cur_number=cur_number-1 false:cur_number=1
    ui->CurPage->setValue(cur_number);
    if( !ui->ChB_date->isChecked()){
        str = "1=1";
    }
    emit signals_load_data(tablename," where "+str,ui->allPage->value(),ui->allPage->value()*(ui->CurPage->value()-1));
}


void Finddata::btw_to_picture()
{
    QProcess process;
    //D:\Program Files (x86)\Seagull\BarTender Suite
    //"D:\Program Files (x86)\Seagull\BarTender Suite\bartend.exe" /F=F:\label\channel1.btw /X /ImageExportFile=F:\output.png /ImageExportFormat=PNG /Q
    //bartend.exe /F=模板.btw /X /Q /DatabaseName=SystemDatabase /SetNamedSubString=DataBlockName.FieldName,Value
       QString command = "\"D:\\Program Files (x86)\\Seagull\\BarTender Suite\\bartend.exe\"";
       QStringList args;
       args << "/F=F:\\label\\channel1.btw"
            << "/X"  // 执行导出操作
            << "/ImageExportFile=F:\\output.png"
            //<< "/ImageExportFormat=PNG"
            << "/Q"; // 静默模式
       qDebug()<<args;
       process.start(command, args);
           if (!process.waitForFinished(30000)) { // 等待30秒
               qDebug() << "导出超时或失败：" << process.errorString();
           } else {
               qDebug() << "导出完成，退出码：" << process.exitCode();
           }
}

//******************************************** Mysql线程*************************************
mMysqlThread::mMysqlThread(QObject *parent)
{
   myModel = nullptr;
   pThread = new QThread;
   this->moveToThread(pThread);
   connect(pThread, &QThread::started, this, &mMysqlThread::connectSQL);
   qRegisterMetaType<QMap<QString, QStringList>>("QMap<QString, QStringList>");

//   Map_TableName.insert("组装工位", "datas_linecode_a1");

//   Map_TableName.insert("视觉检测1", "datas_linecode_s");
//   Map_TableName.insert("视觉检测2", "datas_linecode_s1");
//   Map_TableName.insert("视觉检测3", "datas_linecode_s2");
//   Map_TableName.insert("视觉检测4", "datas_linecode_s3");

//   Map_TableName.insert("泄露测试", "datas_linecode_jl");

//   Map_TableName.insert("风速检测1", "datas_linecode_f");
//   Map_TableName.insert("风速检测2", "datas_linecode_f1");
//   Map_TableName.insert("风速检测3", "datas_linecode_f2");
//   Map_TableName.insert("风速检测4", "datas_linecode_f3");
//   Map_TableName.insert("风速检测5", "datas_linecode_f4");

//   Map_TableName.insert("性能检测1", "datas_linecode_d");
//   Map_TableName.insert("性能检测2", "datas_linecode_d1");
//   Map_TableName.insert("性能检测3", "datas_linecode_d2");
//   Map_TableName.insert("性能检测4", "datas_linecode_d3");


//   Model_ba buff_Model_ba;
//   buff_Model_ba.Tab_Name = "组装工位";
//   buff_Model_ba.mModel = new QSqlTableModel(this, db);
//   //设置表名
//   for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
//       QString key = it.key();
//       buff_Model_ba.Tab_Name = it.value();
//       SqlModel.insert(key, buff_Model_ba);
//   }

//   qDebug()<<"1111gogo";


//   /*
//   SqlModel.insert("视觉检测1", new QSqlTableModel(this, db));
//   SqlModel.insert("视觉检测2", new QSqlTableModel(this, db));
//   SqlModel.insert("视觉检测3", new QSqlTableModel(this, db));
//   SqlModel.insert("视觉检测4", new QSqlTableModel(this, db));

//   SqlModel.insert("泄露测试", new QSqlTableModel(this, db));

//   SqlModel.insert("风速检测1", new QSqlTableModel(this, db));
//   SqlModel.insert("风速检测2", new QSqlTableModel(this, db));
//   SqlModel.insert("风速检测3", new QSqlTableModel(this, db));
//   SqlModel.insert("风速检测4", new QSqlTableModel(this, db));
//   SqlModel.insert("风速检测5", new QSqlTableModel(this, db));

//   SqlModel.insert("性能检测1", new QSqlTableModel(this, db));
//   SqlModel.insert("性能检测2", new QSqlTableModel(this, db));
//   SqlModel.insert("性能检测3", new QSqlTableModel(this, db));
//   SqlModel.insert("性能检测4", new QSqlTableModel(this, db));


//   //设置表名
//   for (auto it = SqlModel.begin(); it != SqlModel.end(); ++it) {
//       QString key = it.key();
//       it.value()->setTable(Map_TableName[key]);
//   }
//   */

//   emit signals_sql_model_conn();


}

mMysqlThread::~mMysqlThread()
{

}
void mMysqlThread::slot_reloadSqlConfig()
{
    if (myModel != nullptr) {
        delete myModel;
        myModel = nullptr;
    }

    const QString connectionName = db.connectionName();
    if (db.isValid()) {
        if (db.isOpen()) {
            db.close();
        }
        db = QSqlDatabase();
        if (!connectionName.isEmpty()) {
            QSqlDatabase::removeDatabase(connectionName);
        }
    }

    connectSQL();
}

//建立检测名称与数据表的映射关系
void mMysqlThread::InitSQL()
{

    // 清空原有映射（若有）
        Map_TableName.clear();

        const SqlConnectionConfig config = SQLConifg::loadConfig();
        for (const SqlTableConfig &tableConfig : config.tables) {
            if (!tableConfig.enabled) {
                continue;
            }
            const QString tabName = tableConfig.tabName.trimmed();
            const QString tableName = tableConfig.tableName.trimmed();
            if (!tabName.isEmpty() && !tableName.isEmpty()) {
                Map_TableName.insert(tabName, tableName);
            }
        }

        // 自动探测每张表的结果字段和日期字段
        m_resultFieldMap.clear();
        m_dateFieldMap.clear();
        for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
            const QStringList cols = getTableColumns(it.value());
            for (const QString &col : cols) {
                if (col.contains("结果"))
                    m_resultFieldMap[it.key()] = col;
                if (col.contains("日期"))
                    m_dateFieldMap[it.key()] = col;
            }
        }

        // 创建 QSqlTableModel
        Model_ba buff_Model_ba;
        for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
            buff_Model_ba.mModel = new QSqlTableModel();
            buff_Model_ba.Tab_Name = it.value();
            SqlModel.insert(it.key(), buff_Model_ba);
            SqlModel[it.key()].mModel->setTable(it.value());
        }

}

//连接数据库
bool mMysqlThread::connectSQL()
{


//    db = QSqlDatabase::addDatabase("ODBC");
//    db.setHostName(MysqlSettings.hostName);//
//    db.setPort(3306);
//    db.setDatabaseName(MysqlSettings.databaseName);//
//    db.setUserName(MysqlSettings.userName);
//    db.setPassword(MysqlSettings.password);

    db = QSqlDatabase::addDatabase("QODBC");
    QString connStr = QString("DRIVER={MySQL ODBC 8.0 Unicode Driver};"
                              "SERVER=%1;PORT=%2;DATABASE=%3;UID=%4;PWD=%5")
                      .arg(MysqlSettings.hostName)
                      .arg(MysqlSettings.port.isEmpty() ? "3306" : MysqlSettings.port)
                      .arg(MysqlSettings.databaseName)
                      .arg(MysqlSettings.userName)
                      .arg(MysqlSettings.password);
    db.setDatabaseName(connStr);
    if(!db.open()){
        B_Connect = false;
        qDebug() << "连接数据库失败" << db.lastError();
    }else{
        B_Connect = true;
        myModel = new QSqlTableModel();
        qDebug() << "连接数据库成功";
        Get_tablse_name();
    }
    return B_Connect;
}
//获取表单信息
void mMysqlThread::Get_tablse_name()
{
    QSqlQuery query(db);
    query.exec("show tables;");
    qDebug() << "读取列表信息";
    m_finddata->ui->comboBox->clear();
    while (query.next()) {
//        qDebug() << "table:"<<query.value(0).toString();
        m_finddata->ui->comboBox->addItem(query.value(0).toString());
        slot_load_columns(query.value(0).toString());
    }
}
/*--------------查询-------------------------------------*/

//获取表名
QStringList mMysqlThread::getTableColumns(const QString& tableName)
{
    QStringList columns;
    QSqlQuery query(db);   // 确保使用成员变量 db
    QString sql = QString("DESCRIBE %1").arg(tableName);
    if (query.exec(sql)) {
        while (query.next()) {
            columns.append(query.value(0).toString());
        }
    } else {
        qDebug() << "获取列名失败：" << query.lastError().text();
    }
    return columns;
}
void mMysqlThread::slot_export_all(QString sql)
{
    // 确保导出目录存在（桌面路径，兼容所有电脑）
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktopPath + "/ExportData");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString dateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString filePath = QString("%1/ExportData/Export_%2.xlsm").arg(desktopPath).arg(dateTime);

    // 创建 Excel 应用程序对象
    QAxObject* excel = new QAxObject("Excel.Application", this);
    if (excel->isNull()) {

        QMessageBox::warning(nullptr, "错误", "无法创建 Excel 对象，请确保已安装 Microsoft Excel。");
        delete excel;
        return;
    }

    excel->setProperty("DisplayAlerts", false);          // 关闭警告弹窗
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    QAxObject* workbook = workbooks->querySubObject("Add");   // 新建工作簿
    QAxObject* worksheets = workbook->querySubObject("Worksheets");

    int sheetIndex = 1;   // 用于控制 Sheet 的索引

    // 遍历所有需要导出的表
    for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
        QString tableName = it.value();   // 数据库表名，如 "datas_linecode_a1"
        QString sheetName = it.key();     // 显示名称，如 "主线"

        // 获取或创建 Sheet
        QAxObject* sheet = nullptr;
        if (sheetIndex == 1) {
            // 第一个 Sheet 已经存在（新建工作簿自带一个 Sheet），直接获取
            sheet = worksheets->querySubObject("Item(int)", 1);
        } else {
            // 添加新的 Sheet
            QAxObject* newSheet = worksheets->querySubObject("Add()");
            sheet = newSheet;
        }
        // 设置 Sheet 名称（限制31字符）
        sheet->setProperty("Name", sheetName.left(31));

        // 获取该表的所有列名
        QStringList columns = getTableColumns(tableName);
        if (columns.isEmpty()) {
            qDebug() << "表" << tableName << "无列信息，跳过";
            continue;
        }

        // 构建 SELECT 语句（只查询需要的列，避免 * 顺序问题）
        QString colsStr = columns.join(",");
        QString select = QString("SELECT %1 FROM %2 %3")
                             .arg(colsStr)
                             .arg(tableName)
                             .arg(sql);   // sql 已经是 "where ..." 形式

        QSqlQuery query(db);
        if (!query.exec(select)) {
            qDebug() << "查询失败：" << query.lastError() << select;
            continue;
        }

        // 写入列标题（第一行）
        for (int col = 0; col < columns.size(); ++col) {
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
            cell->setProperty("Value", columns.at(col));
            delete cell;
        }

        // 写入数据（从第二行开始）
        int row = 2;
        while (query.next()) {
            for (int col = 0; col < columns.size(); ++col) {
                QAxObject* cell = sheet->querySubObject("Cells(int,int)", row, col + 1);
                QVariant value = query.value(col);
                cell->setProperty("Value", value);
                delete cell;
            }
            ++row;
            // 每500行处理一次事件
            if (row % 500 == 0) {
                QApplication::processEvents();
            }
        }

        // 自动调整列宽（可选，提升可读性）
        QAxObject* usedRange = sheet->querySubObject("UsedRange");
        if (usedRange) {
            QAxObject* columnsRange = usedRange->querySubObject("Columns");
            if (columnsRange) {
                columnsRange->dynamicCall("AutoFit");
            }
        }

        ++sheetIndex;
    }

    // 删除默认多余的 Sheet（如果只有导出的表数量少于 Sheet 总数）
    int totalSheets = worksheets->property("Count").toInt();
    for (int i = totalSheets; i > sheetIndex - 1; --i) {
        QAxObject* lastSheet = worksheets->querySubObject("Item(int)", i);
        if (lastSheet) {
            lastSheet->dynamicCall("Delete");
        }
    }

    // 保存文件为 .xlsm 格式（FileFormat: 52 = xlOpenXMLWorkbookMacroEnabled）
    workbook->dynamicCall("SaveAs(const QString&, int)", QDir::toNativeSeparators(filePath), 52);
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");

    delete excel;

    QMessageBox::information(nullptr, "完成", QString("导出成功！\n文件位置：%1").arg(filePath));
}



void mMysqlThread::slot_Load_Data(QString Tab_Name, QString str, int now_rows, int now_CurPage)
{
    // 根据表名查找对应的 Model_ba
    QString modelKey;
    for (auto it = SqlModel.begin(); it != SqlModel.end(); ++it) {
        if (it.value().Tab_Name == Tab_Name) {
            modelKey = it.key();
            break;
        }
    }
    if (modelKey.isEmpty()) {
        qDebug() << "未找到表对应的 Model:" << Tab_Name;
        return;
    }
    // 调用已有的分页查询函数
    slot_Load_Data_show(SqlModel[modelKey], str, now_rows, now_CurPage);
}

void mMysqlThread::slot_Load_Data_show(Model_ba mModelBa, QString str, int limit, int offset)
{
    if (mModelBa.Tab_Name.trimmed().isEmpty() || mModelBa.mModel == nullptr) {
        return;
    }

    // 使用 SQL_CALC_FOUND_ROWS 一次查询同时获取数据+总行数，避免两次全表扫描
    QString selectStr = QString("SELECT SQL_CALC_FOUND_ROWS * FROM %1 %2 LIMIT %3 OFFSET %4")
                            .arg(mModelBa.Tab_Name, str)
                            .arg(limit).arg(offset);
    mModelBa.mModel->QSqlQueryModel::setQuery(selectStr);

    // 立即获取 FOUND_ROWS() 得到总行数（必须在同一连接上执行）
    int totalRows = 0;
    QSqlQuery foundQuery;
    if (foundQuery.exec("SELECT FOUND_ROWS()") && foundQuery.next()) {
        totalRows = foundQuery.value(0).toInt();
    }

    // 回传总行数和 limit，主线程计算页数并更新 UI
    emit signal_totalPages(totalRows, limit);
}

QStringList mMysqlThread::slot_get_flowernumber(QString tablename,QString str)
{
    QStringList list_flowernumber;
    QString selectStr = "SELECT 流水号 FROM "+tablename+str;
    qDebug()<<"sql:"<<selectStr;
    QSqlQuery query1;
    query1.prepare(selectStr);
    if( !query1.exec() ){
        qDebug()<<"搜索流水号失败："<<query1.lastError();
    }else{
        while (query1.next()){
             list_flowernumber<<query1.value(0).toString();
        }
    }
    qDebug()<<"获取流水号"<<list_flowernumber;
    return list_flowernumber;
}

void mMysqlThread::slot_load_columns(QString tablename)
{
    QString list_name;
    QStringList list_sql;
    QString str = "describe " + tablename;
    QSqlQuery query1;
    query1.prepare(str);
    if( !query1.exec() ){
        qDebug()<<"搜索列名失败："<<query1.lastError();
    }else{
        while (query1.next()) {
            QString columns_name = query1.value(0).toString();
//            list_sql.append(query1.value(0).toString());
            if( tablename == "datas_linecode_a1" ){
                if( columns_name != "数据更新日期" ){
                    Assembly_cloumns<<columns_name;
                }
            }
            if( !chineseList.contains(columns_name)){
                chineseList<<columns_name;
            }
        }
    }
    emit sign_setWordList(chineseList);
//    if( list_sql.length() == 0 ){
//        qDebug()<<"未找到列名:"<<str;
//        return;
//    }else{
//        for(int i=0;i<list_sql.length()-1;i++){
//            list_name = list_name + QString("'%1',").arg(list_sql.at(i));
//        }
//        list_name = list_name+"'"+list_sql.at(list_sql.length()-1)+"'";//获取列名
//    }
}

// slot_fetchDataForExport遍历 Map_TableName，查询每个表，打包到 QList<TableData>
// 使用二维数组存储，优化大数据量导出
void mMysqlThread::slot_fetchDataForExport(QString whereClause)
{
    QList<TableData> allData;

    // 遍历 Map_TableName（已定义的表名映射）
    for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
        QString sheetName = it.key();      // 如 "主线"
        QString tableName = it.value();    // 如 "datas_linecode_a1"

        // 获取列名（复用已有函数）
        QStringList columns = getTableColumns(tableName);
        if (columns.isEmpty()) {
            qDebug() << "表" << tableName << "无列信息，跳过";
            continue;
        }

        // 【优化1】先查询总行数，判断是否需要截断
        QString countSql = QString("SELECT COUNT(*) FROM %1 %2")
            .arg(tableName).arg(whereClause);
        QSqlQuery countQuery(db);
        int totalCount = 0;
        bool isTruncated = false;
        
        if (countQuery.exec(countSql) && countQuery.next()) {
            totalCount = countQuery.value(0).toInt();
        }

        // 【优化2】计算实际导出行数，添加LIMIT限制
        int limitRows = (totalCount > MAX_EXPORT_ROWS) ? MAX_EXPORT_ROWS : totalCount;
        isTruncated = (totalCount > MAX_EXPORT_ROWS);

        // 【优化3】使用预分配内存的二维数组 QVector
        QVector<QVector<QVariant>> rows;
        rows.reserve(limitRows);  // 预分配内存，避免多次重新分配

        // 【优化4】LIMIT 查询，控制数据量
        QString sql = QString("SELECT %1 FROM %2 %3 LIMIT %4")
                          .arg(columns.join(","))
                          .arg(tableName)
                          .arg(whereClause)
                          .arg(limitRows);

        QSqlQuery query(db);
        if (!query.exec(sql)) {
            qDebug() << "导出数据查询失败：" << query.lastError() << sql;
            continue;
        }

        // 【优化5】使用 QVector 存储，二维数组结构更高效
        while (query.next()) {
            QVector<QVariant> row;
            row.reserve(columns.size());  // 预分配列内存
            for (int i = 0; i < columns.size(); ++i) {
                row.append(query.value(i));
            }
            rows.append(row);
        }

        // 打包一个表的数据
        TableData data;
        data.sheetName = sheetName;
        data.columns = columns;
        data.rows = rows;
        data.totalCount = totalCount;
        data.isTruncated = isTruncated;
        allData.append(data);
        
        qDebug() << "表" << sheetName << "导出" << rows.size() 
                 << (isTruncated ? QString("条(共%1条，已截断)").arg(totalCount) : "条");
    }

    // 将数据包发回主线程
    emit signals_exportDataReady(allData);
}




//获取表单数据总数
int mMysqlThread::getTotalRecordCount(const QString &tableName, const QString &whereClause)
{
    QSqlQuery query(db);
    QString trimmed = whereClause.trimmed();
    QString countSql;
    if (trimmed.isEmpty() || trimmed == "where") {
        countSql = QString("SELECT COUNT(*) FROM %1").arg(tableName);
    } else {
        countSql = QString("SELECT COUNT(*) FROM %1 %2").arg(tableName).arg(whereClause);
    }
    qDebug() << "Count SQL:" << countSql;  // 调试输出
    if (!query.exec(countSql)) {
        qDebug() << "获取总记录数失败：" << query.lastError();
        return 0;
    }
    if (query.next()) {
        return query.value(0).toInt();
    }
return 0;
}

// 分批导出全部数据到Excel（已废弃，改为新路径：slot_fetchDataForExport + slot_writeExcel）
void mMysqlThread::slot_exportAllBatched(QString whereClause)
{
    Q_UNUSED(whereClause)
    qDebug() << "[Export] slot_exportAllBatched 已废弃，请使用新导出路径。";
}

// 验证登录
QPair<int, QString> mMysqlThread::slot_checkLogin(const QString &user, const QString &pwd)
{
    QSqlQuery query(db);
    query.prepare("SELECT 权限, 权限等级 FROM admin WHERE 用户名=? AND 员工密码=?");
    query.addBindValue(user);
    query.addBindValue(pwd);
    if (query.exec() && query.next()) {
        return {query.value(1).toInt(), query.value(0).toString()};
    }
    return {0, ""};
}
