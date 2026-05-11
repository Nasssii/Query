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

        if (Map_TableName.isEmpty()) {
            // 标签页0 - 主线
            Map_TableName.insert("主线", "datas_linecode_a1");
            // 标签页1 - 辅线（一个分表）
            Map_TableName.insert("辅线", "datas_linecode_b1");
            // 标签页2 - 检漏检测（
            Map_TableName.insert("检漏检测", "datas_linecode_jl");
            // 标签页3 - 风速检测（两个表）
            Map_TableName.insert("风速检测1", "datas_linecode_f");
            Map_TableName.insert("风速检测2", "datas_linecode_f1");
            // 标签页4 - 性能检测
            Map_TableName.insert("性能检测", "datas_linecode_d");
        }
        // 结果字段名列表（
        Name_result.clear();
        Name_date.clear();
        Name_result << "结果"               // 主线 (索引0)
                    << "视觉影像总结果"     // 辅线 (索引1)
                    << "视觉影像总结果"     // 检漏检测 (索引2)
                    << "风速总结果"         // 风速检测 (索引3，两个表共用)
                    << "电检总结果";        // 性能检测 (索引4)
        Name_date << "数据更新日期"
                  << "日期"
                  << "日期"
                  << "日期"
                  << "日期";

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

void mMysqlThread::slot_Load_Data_show(Model_ba mModelBa, QString str, int rowsPerPage, int offset)
{
        if (mModelBa.Tab_Name.trimmed().isEmpty() || mModelBa.mModel == nullptr) {
        qDebug() << "跳过查询：表名为空或模型为空，where:" << str;
        return;
    }
// 1. 获取总记录数
    int total = getTotalRecordCount(mModelBa.Tab_Name, str);
    int totalPages = (total + rowsPerPage - 1) / rowsPerPage; // 向上取整

    // 2. 修正 offset 不要越界
    if (offset >= total && total > 0) {
        offset = (totalPages - 1) * rowsPerPage;
    }

    // 3. 发送总页数信号（更新页码控件）
    int currentPage = offset / rowsPerPage + 1;
    emit signal_totalPages(totalPages, currentPage);

    // 4. 执行带分页的查询
    QString selectStr = QString("SELECT * FROM %1 %2 LIMIT %3 OFFSET %4")
                            .arg(mModelBa.Tab_Name, str, QString::number(rowsPerPage), QString::number(offset));
    mModelBa.mModel->QSqlQueryModel::setQuery(selectStr);
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

// 分批导出全部数据到Excel
void mMysqlThread::slot_exportAllBatched(QString whereClause)
{
       qDebug() << "[Export] 开始导出，where:" << whereClause;
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktopPath + "/ExportData");
    if (!dir.exists()) dir.mkpath(".");

    QString dateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString filePath = QString("%1/ExportData/Export_%2.xlsm").arg(desktopPath).arg(dateTime);
    qDebug() << "[Export] 文件路径:" << filePath;

    // 2. 创建 Excel 对象（可能卡死 1）
    qDebug() << "[Export] 正在创建 Excel.Application...";
    QAxObject* excel = new QAxObject("Excel.Application", this);
    if (excel->isNull()) {
        qDebug() << "[Export] 创建 Excel 对象失败！可能未安装 Excel 或 COM 未注册";
        QMessageBox::warning(nullptr, "错误", "无法创建 Excel 对象。");
        delete excel;
        emit signals_exportProgress(-1, 0, 0, 0, "");
        return;
    }
    qDebug() << "[Export] Excel 对象创建成功";
    excel->setProperty("DisplayAlerts", false);
    qDebug() << "[Export] 设置 DisplayAlerts 完成";

    QAxObject* workbooks = excel->querySubObject("Workbooks");

    if (!workbooks || workbooks->isNull()) {
         qDebug() << "[Export] 获取 Workbooks 失败";
         excel->dynamicCall("Quit()");
         delete excel;
         emit signals_exportProgress(-1, 0, 0, 0, "获取 Workbooks 失败");
         return;
     }
     qDebug() << "[Export] 获取 Workbooks 成功";


    QAxObject* workbook = workbooks->querySubObject("Add");
      //debug代码
      if (!workbook || workbook->isNull()) {
          qDebug() << "[Export] 新建工作簿失败";
          workbooks->dynamicCall("Close()");
          excel->dynamicCall("Quit()");
          delete workbooks;
          delete excel;
          emit signals_exportProgress(-1, 0, 0, 0, "新建工作簿");
          return;
      }
      qDebug() << "[Export] 新建工作簿成功";

    QAxObject* worksheets = workbook->querySubObject("Worksheets");
    //正确检查 worksheets 是否有效
    if (!worksheets || worksheets->isNull()) {
        qDebug() << "[Export] 获取 Worksheets 失败";
        workbooks->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete workbook;
        delete workbooks;
        delete excel;
        emit signals_exportProgress(-1, 0, 0, 0, "Worksheets失败");
        return;
    }
    qDebug() << "[Export] 新建工作簿成功";

    int tableIndex = 0;
    int totalTables = Map_TableName.size();

    for (auto it = Map_TableName.begin(); it != Map_TableName.end(); ++it) {
        QString sheetName = it.key();
        QString tableName = it.value();
        tableIndex++;

        QStringList columns = getTableColumns(tableName);
        if (columns.isEmpty()) continue;

        QString countSql = QString("SELECT COUNT(*) FROM %1 %2").arg(tableName).arg(whereClause);
        QSqlQuery countQuery(db);
        int totalCount = 0;
        if (countQuery.exec(countSql) && countQuery.next()) {
            totalCount = countQuery.value(0).toInt();
        }
        if (totalCount == 0) continue;
        if (totalCount > MAX_EXPORT_ROWS) totalCount = MAX_EXPORT_ROWS;

        int totalBatches = (totalCount + BATCH_QUERY_ROWS - 1) / BATCH_QUERY_ROWS;

        QAxObject* sheet = nullptr;
        if (tableIndex == 1) {
            sheet = worksheets->querySubObject("Item(int)", 1);
        } else {
            sheet = worksheets->querySubObject("Add()");
        }
        sheet->setProperty("Name", sheetName.left(31));

        for (int col = 0; col < columns.size(); ++col) {
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
            cell->setProperty("Value", columns.at(col));
            delete cell;
        }

        int currentRow = 2;

        for (int batchIndex = 0; batchIndex < totalBatches; ++batchIndex) {
            int offset = batchIndex * BATCH_QUERY_ROWS;
            int limit = BATCH_QUERY_ROWS;
            if (offset + limit > totalCount) limit = totalCount - offset;

            QString sql = QString("SELECT %1 FROM %2 %3 LIMIT %4 OFFSET %5")
                .arg(columns.join(",")).arg(tableName).arg(whereClause).arg(limit).arg(offset);

            QSqlQuery query(db);
            if (!query.exec(sql)) continue;

            int rowsWrittenInBatch = 0;
            while (query.next()) {
                for (int col = 0; col < columns.size(); ++col) {
                    QAxObject* cell = sheet->querySubObject("Cells(int,int)", currentRow, col + 1);
                    cell->setProperty("Value", query.value(col));
                    delete cell;
                }
                currentRow++;
                rowsWrittenInBatch++;
                if (rowsWrittenInBatch % BATCH_WRITE_ROWS == 0) {
                    emit signals_exportProgress(tableIndex, totalTables, batchIndex + 1, totalBatches, sheetName);
                    QApplication::processEvents();
                }
            }

            emit signals_exportProgress(tableIndex, totalTables, batchIndex + 1, totalBatches, sheetName);
            QApplication::processEvents();
        }

        qDebug() << "表" << sheetName << "导出完成";
    }

    int totalSheets = worksheets->property("Count").toInt();
    for (int i = totalSheets; i > tableIndex; --i) {
        QAxObject* lastSheet = worksheets->querySubObject("Item(int)", i);
        if (lastSheet) lastSheet->dynamicCall("Delete");
    }

    workbook->dynamicCall("SaveAs(const QString&, int)", QDir::toNativeSeparators(filePath), 52);
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");

    QMessageBox::information(nullptr, "完成", QString("导出成功！\n文件位置：%1").arg(filePath));
    emit signals_exportProgress(totalTables, totalTables, 0, 0, "完成");
}
