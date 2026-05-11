#include "mainwindow.h"
#include <QMutex>
#include <QApplication>
#include <QVector>
#include "finddata.h"
void MessWriteLog(QtMsgType, const QMessageLogContext &, const QString &);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    struct Model_ba{
//        QString Tab_Name;
//        QSqlTableModel *mModel;

//    };

//    Q_DECLARE_METATYPE(Model_ba)


//    // sql数据载体结构体
//    struct TableData {
//        QString sheetName;
//        QStringList columns;
//        QList<QList<QVariant>> rows;
//    };




    // 注册自定义类型
    qRegisterMetaType<Model_ba>("Model_ba");
    // 导出表数据自定义类型
    qRegisterMetaType<TableData>("TableData");
    qRegisterMetaType<QList<TableData>>("QList<TableData>");
    // 新增二维数组类型注册
    qRegisterMetaType<QVector<QVector<QVariant>>>("QVector<QVector<QVariant>>");

    qInstallMessageHandler(MessWriteLog);
    MainWindow w;
    //w.show();
    w.showMaximized();
    return a.exec();
}

//写日志功能
void MessWriteLog(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //定义日志文件存放路径
    QString logDir = QApplication::applicationDirPath() + "\\调试日志\\" + QDate::currentDate().toString("yyyy_MM") + "\\";
    QDir curDir(logDir);
    if(!curDir.exists(logDir)){//如果路径不存在则创建
        curDir.mkpath(logDir);
    }
    static QMutex mutex;//互斥量
    mutex.lock();
    QString contextType;//日志类型
    switch(type){

    case QtDebugMsg:
        contextType = QString("Debug");
        break;
    case QtWarningMsg:
        contextType = QString("Warning");
        break;
    case QtCriticalMsg:
        contextType = QString("Critical");
        break;
    case QtFatalMsg:
        contextType = QString("Fatal");
    }
    QString contextInfo = QString("[%1: %2]").arg(QString(context.file)).arg(context.line);//代码所在文件及行数
    QString contextTime = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");//当前时间

    QString mess = QString("%1: [%2] %3：%4").arg(contextTime).arg(contextType).arg(contextInfo).arg(msg);//一行日志信息
    QFile contextFile(logDir + QDate::currentDate().toString("yyyy_MM_dd") +".log");
    contextFile.open(QIODevice::WriteOnly | QIODevice::Append);//以只写或追加方式打开文件
    QTextStream contextStream(&contextFile);//定义文件流
    contextStream << mess << "\r\n";//将文件流写入文件
    contextFile.flush();
    contextFile.close();
    mutex.unlock();//释放互斥量
}
