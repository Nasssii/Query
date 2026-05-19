#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 【调整】先包含finddata.h，确保TableData在head.h之前已定�?
#include "finddata.h"
#include "head.h"
#include "sqlconifg.h"
#include <QMap>
#include <QMutex>
#include <QProgressDialog>
// 【删除】重复的 #include "finddata.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Read_Settings();
    void setWordList(const QStringList &words);
    void exportToCsvFallback(const QList<TableData>& allData, const QString& excelPath);
private slots:
    void on_actions_SQL_triggered();
    void slot_sqlConfigChanged(const SqlConnectionConfig &config);
    void on_Btn_Find_clicked();

    void on_tabWidget_currentChanged(int index);
    void updatePageControls(int totalRows, int limit);
    //下一页按钮事�?
    void on_Btn_PageUp_clicked();
    void on_Btn_PageDown_clicked();

    void onTabChanged(int index);
    void on_pushButton_ExportAll_clicked();  // 导出按钮点击�?
    void slot_startExport();                   // 发起导出流程
    void slot_writeExcel(QList<TableData> allData); // 在主线程�?Excel
    void slot_updateExportProgress(int currentTable, int totalTables, int currentBatch, int totalBatches, QString sheetName); // 导出进度更新




public slots:
    void slots_sql_model_conn();


private:
    Ui::MainWindow *ui;
    void Database_Model_Binding(QTableView *TableView,QSqlTableModel* Model);
    void handleTextChange(const QString &text);
    void applyColumnPageToCurrentView();
    void applyColumnPageToView(QTableView *view, int pageIndex, bool updateControls);
    int columnPageSizeForView(const QTableView *view) const;
    QStringList currentModelColumns(const QSqlQueryModel *model) const;
    void cacheColumnWidths(QTableView *view);

    QStringListModel *list_model;
    QStringList fullWordList;
    QCompleter *completer;

    QString getLastChineseChar(const QString &input);
    //
    struct PageInfo {
        int columnPage = 1;          // 当前第几组字段
        int columnPageSize = 10;     // 字段组大小（来自 allPage 控件）
        int totalColumnPages = 1;    // 总共几组字段
        int columnsPerPage = 50;     // 用户设定的每页字段数
        bool dataLoaded = false;     // 是否已从数据库加载过数据
    };
    QMap<QString, PageInfo> m_pageInfoMap;   // 表名 -> 分页信息
    QList<QueryFieldConfig> m_queryFields;   // 查询字段配置
    QMap<QString, QStringList> m_cachedTableColumns; // 表名 -> 列名缓存
    QString m_currentTabKey;                 // 当前 Tab 的表名 key
    int m_currentTabIndex = 0;               // 当前 Tab 的索引（用于 Name_result/Name_date 等）
    QMap<QString, QVector<int>> m_cachedColumnWidths;  // 表名 -> 每列内容宽度缓存
    QTableView* getCurrentTableView();
    QString currentSqlModelName() const;
    bool canDeleteSqlTableMapping() const;
    void deleteSqlTableMapping(const QString &modelName);
    void clearSqlTabsAndModels();
    void reloadSqlRuntime();
    void loadDataForCurrentPage();
    void resetCurrentPage();
    void updateQueryFieldLabels();
    QList<QWidget*> m_dynamicSqlTabs;
    QMap<QWidget*, QString> m_dynamicSqlTabNames;

    QString buildWhereClause();  // 根据界面控件构建 WHERE 子句
    // 导出状态锁与标�?
    QMutex m_exportMutex;
    bool m_bExporting = false;
    // 进度对话框指�?
    QProgressDialog *m_progressDlg = nullptr;
    //辅助函数
    void enableAllControls();
    void finalizeExport(bool success, const QString &message);

signals:
    void signals_Load_Data_show(Model_ba mModelBa,QString str,int limit,int offset);
    QStringList signals_get_flowernumber(QString tablename,QString str);
  // void signals_export_all_data(QString sql);   //导出信号
    void signals_requestExportData(QString whereClause); // 请求子线程查询数�?
    void exportCompleted(bool success, QString message);    // 导出完成信号，可连接其他界面进行状态更�?
};
#endif // MAINWINDOW_H

