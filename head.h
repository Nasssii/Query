#ifndef HEAD_H
#define HEAD_H

#include "ui_mainwindow.h"

#include "finddata.h"
#include "ui_finddata.h"
// 【删除】#include "mainwindow.h"  // 避免循环依赖
#include <QDebug>
#include <QTimer>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QThread>
#include <QDir>
#include <QStringListModel>
#include <QCompleter>
#include <QLineEdit>

#include <QProcess>

extern QStringList chineseList;
extern QStringList Assembly_cloumns;//组装数据列名
extern QStringList Table_name;//数据库名字
extern QStringList Name_result;//结果列名
extern QStringList Name_date;//日期名称

#endif // HEAD_H
