#include "sqlconifg.h"

#include <QApplication>
#include <QDir>
#include <QSettings>

SQLConifg::SQLConifg()
{
}

QString SQLConifg::settingsPath()
{
    const QString dataDir = QApplication::applicationDirPath() + "/Data";
    QDir dir(dataDir);
    if (!dir.exists()) {
        dir.mkpath(dataDir);
    }
    return dataDir + "/Settings.ini";
}

SqlConnectionConfig SQLConifg::loadConfig()
{
    SqlConnectionConfig config;
    QSettings settings(settingsPath(), QSettings::IniFormat);

    // 连接信息兼容原有 [Settings] 分组，避免影响 MainWindow::Read_Settings()。
    config.connectionName = settings.value("SqlSetting/connectionName").toString();
    config.hostName = settings.value("Settings/hostname").toString();
    config.databaseName = settings.value("Settings/databaseName").toString();
    config.userName = settings.value("Settings/userName").toString();
    config.password = settings.value("Settings/password").toString();
    config.port = settings.value("Settings/port", 3306).toInt();

    // 新表映射格式：SqlTables/size + 每行 tabName/tableName/enabled。
    const int size = settings.beginReadArray("SqlTables");
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        SqlTableConfig table;
        table.tabName = settings.value("tabName").toString();
        table.tableName = settings.value("tableName").toString();
        table.enabled = settings.value("enabled", true).toBool();
        if (!table.tabName.trimmed().isEmpty() || !table.tableName.trimmed().isEmpty()) {
            config.tables.append(table);
        }
    }
    settings.endArray();

    // 兼容旧配置 FrontendTables/names：只作为前端名和数据库表名相同的默认值读取。
    if (config.tables.isEmpty()) {
        const QStringList oldTables = settings.value("FrontendTables/names").toStringList();
        for (const QString &name : oldTables) {
            if (!name.trimmed().isEmpty()) {
                SqlTableConfig table;
                table.tabName = name.trimmed();
                table.tableName = name.trimmed();
                table.enabled = true;
                config.tables.append(table);
            }
        }
    }

    return config;
}

bool SQLConifg::saveConfig(const SqlConnectionConfig &config)
{
    QSettings settings(settingsPath(), QSettings::IniFormat);

    // 连接信息仍写入原 [Settings]，保证现有数据库连接读取逻辑可继续工作。
    settings.setValue("SqlSetting/connectionName", config.connectionName);
    settings.setValue("Settings/hostname", config.hostName);
    settings.setValue("Settings/databaseName", config.databaseName);
    settings.setValue("Settings/userName", config.userName);
    settings.setValue("Settings/password", config.password);
    settings.setValue("Settings/port", config.port);

    settings.remove("SqlTables");
    settings.beginWriteArray("SqlTables");
    for (int i = 0; i < config.tables.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("tabName", config.tables.at(i).tabName);
        settings.setValue("tableName", config.tables.at(i).tableName);
        settings.setValue("enabled", config.tables.at(i).enabled);
    }
    settings.endArray();
    settings.sync();

    return settings.status() == QSettings::NoError;
}
