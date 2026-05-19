#ifndef FINDDATA_H
#define FINDDATA_H

#include <head.h>
#include <QWidget>
#include <QSqlTableModel>
#include <QAxObject>

// 分批导出常量
const int BATCH_QUERY_ROWS = 1500;    // 每批查询1500条
const int BATCH_WRITE_ROWS = 200;    // 每批写入Excel 200行
const int MAX_EXPORT_ROWS = 50000;    // 单表最大导出

struct Model_ba{
    QString Tab_Name;
    QSqlTableModel *mModel;

};

Q_DECLARE_METATYPE(Model_ba)


// sql数据载体结构体 - 使用二维数组优化
struct TableData {
    QString sheetName;
    QStringList columns;
    QVector<QVector<QVariant>> rows;  // 二维数组，连续内存，效率更高
    int totalCount = 0;                // 实际总行数（用于判断是否截断）
    bool isTruncated = false;         // 是否被截断
};
//Q_DECLARE_METATYPE 是 Qt 元对象系统宏，注册自定义类型，让 Qt 能识别、存储、传递该类型。
//注册类型

//使这两个类型可用于 信号槽传参、QVariant 存储、属性系统、跨线程传递 等 Qt 核心场景。
Q_DECLARE_METATYPE(TableData)
Q_DECLARE_METATYPE(QList<TableData>)
Q_DECLARE_METATYPE(QVector<QVector<QVariant>>)  // 新增二维数组类型注册

namespace Ui {
class Finddata;
}

class Finddata : public QWidget
{
    Q_OBJECT

public:
    explicit Finddata(QWidget *parent = nullptr);
    ~Finddata();
    QString sql_data;
    Ui::Finddata *ui;

    void btw_to_picture();


private slots:
    void on_Btn_Find_clicked();
    void on_Btn_PageDown_clicked();

    void on_Btn_PageUp_clicked();

//    void on_pushButton_clicked();

public slots:
    void slots_setmodel(QSqlTableModel *mModel);
signals:
    void signals_load_data(QString Tab_Name,QString str,int now_rows,int now_CurPage);
//    void signals_export_data(QString tablename,QString sql);//导出数据
    void signals_export_all(QString sql);//导出全部到Excel

private:

};
extern Finddata *m_finddata;



//sql类

class mMysqlThread : public QObject
{
    Q_OBJECT

public:
    explicit mMysqlThread(QObject *parent = nullptr);
    ~mMysqlThread();

    QThread *pThread;

    bool B_Connect = false;
    bool B_Table = true;

    QSqlDatabase db;
    QSqlTableModel *myModel;

    bool connectSQL();
    void creatTable();
    void insert_Datas_Staion(QStringList list_arg1);
    void insertDatas_Channel_Pars(QStringList list_arg1);
    QMap<QString, QString> Map_TableName;
    void Get_tablse_name();



    QMap<QString,Model_ba> SqlModel;

    void InitSQL();

public slots:
    void slot_Load_Data(QString Tab_Name,QString str,int now_rows,int now_CurPage);//查询数据
    void slot_fetchDataForExport(QString whereClause);//响应主线程请求，查询所有表的数据并返回
    void slot_export_all(QString sql);//导出全部到Excel
    void slot_exportAllBatched(QString sql);//分批导出全部到Excel
    void slot_load_columns(QString tablename);//加载列名
    void slot_reloadSqlConfig();//重新加载数据库连接和模型

    void slot_Load_Data_show(Model_ba mModelBa,QString str,int limit,int offset);
    QStringList slot_get_flowernumber(QString tablename,QString str);
    int getTotalRecordCount(const QString &tableName, const QString &whereClause);//获取表单数据总数
    QStringList getTableColumns(const QString& tableName);//获取表列名


signals:
    void signals_setmodel(QSqlTableModel *mModel);
    void signals_sql_model_conn();
    void sign_setWordList(const QStringList &words);//设置信号
    void signal_totalPages(int totalRows, int limit);//总行数与每页行数
    void signals_exportDataReady(QList<TableData> allData);//携带所有表的数据准备完毕
    void signals_exportProgress(int currentTable, int totalTables, int currentBatch, int totalBatches, QString sheetName);//导出进度
};
extern mMysqlThread *m_MysqlThread;

struct S_6{

    QString hostName;
    QString port;
    QString databaseName;
    QString userName;
    QString password;
    bool B_MYSQL_EN = false;
};
extern S_6 MysqlSettings;

#endif // FINDDATA_H
