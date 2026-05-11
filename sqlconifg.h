#ifndef SQLCONIFG_H
#define SQLCONIFG_H

#include <QList>
#include <QString>

struct SqlTableConfig
{
    QString tabName;      // 前端显示名
    QString tableName;    // 数据库真实表名
    bool enabled = true;
};

struct SqlConnectionConfig
{
    QString connectionName;   // Qt 数据库连接名
    // QString driverName;    // 数据库驱动，例如 QMYSQL / QSQLITE
    QString hostName;         // 主机地址
    QString databaseName;     // 数据库名
    QString userName;         // 用户名
    QString password;         // 密码
    int port = 3306;

    QList<SqlTableConfig> tables;
};

class SQLConifg
{
public:
    SQLConifg();

    // 当前阶段统一使用程序运行目录下的 Data/Settings.ini，兼容原有配置文件。
    static QString settingsPath();

    // 从 ini 读取 SQL 设置，返回结构体，供 SQLSettingDialog 回显。
    static SqlConnectionConfig loadConfig();

    // 将 SQLSettingDialog 收集到的设置写回 ini。
    static bool saveConfig(const SqlConnectionConfig &config);
};

#endif // SQLCONIFG_H
