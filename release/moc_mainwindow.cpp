/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[43];
    char stringdata0[636];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "signals_Load_Data_show"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "Model_ba"
QT_MOC_LITERAL(4, 44, 8), // "mModelBa"
QT_MOC_LITERAL(5, 53, 3), // "str"
QT_MOC_LITERAL(6, 57, 5), // "limit"
QT_MOC_LITERAL(7, 63, 6), // "offset"
QT_MOC_LITERAL(8, 70, 24), // "signals_get_flowernumber"
QT_MOC_LITERAL(9, 95, 9), // "tablename"
QT_MOC_LITERAL(10, 105, 25), // "signals_requestExportData"
QT_MOC_LITERAL(11, 131, 11), // "whereClause"
QT_MOC_LITERAL(12, 143, 15), // "exportCompleted"
QT_MOC_LITERAL(13, 159, 7), // "success"
QT_MOC_LITERAL(14, 167, 7), // "message"
QT_MOC_LITERAL(15, 175, 18), // "signals_checkLogin"
QT_MOC_LITERAL(16, 194, 18), // "QPair<int,QString>"
QT_MOC_LITERAL(17, 213, 4), // "user"
QT_MOC_LITERAL(18, 218, 3), // "pwd"
QT_MOC_LITERAL(19, 222, 24), // "on_actions_SQL_triggered"
QT_MOC_LITERAL(20, 247, 21), // "slot_sqlConfigChanged"
QT_MOC_LITERAL(21, 269, 19), // "SqlConnectionConfig"
QT_MOC_LITERAL(22, 289, 6), // "config"
QT_MOC_LITERAL(23, 296, 19), // "on_Btn_Find_clicked"
QT_MOC_LITERAL(24, 316, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(25, 344, 5), // "index"
QT_MOC_LITERAL(26, 350, 18), // "updatePageControls"
QT_MOC_LITERAL(27, 369, 9), // "totalRows"
QT_MOC_LITERAL(28, 379, 21), // "on_Btn_PageUp_clicked"
QT_MOC_LITERAL(29, 401, 23), // "on_Btn_PageDown_clicked"
QT_MOC_LITERAL(30, 425, 12), // "onTabChanged"
QT_MOC_LITERAL(31, 438, 31), // "on_pushButton_ExportAll_clicked"
QT_MOC_LITERAL(32, 470, 16), // "slot_startExport"
QT_MOC_LITERAL(33, 487, 15), // "slot_writeExcel"
QT_MOC_LITERAL(34, 503, 16), // "QList<TableData>"
QT_MOC_LITERAL(35, 520, 7), // "allData"
QT_MOC_LITERAL(36, 528, 25), // "slot_updateExportProgress"
QT_MOC_LITERAL(37, 554, 12), // "currentTable"
QT_MOC_LITERAL(38, 567, 11), // "totalTables"
QT_MOC_LITERAL(39, 579, 12), // "currentBatch"
QT_MOC_LITERAL(40, 592, 12), // "totalBatches"
QT_MOC_LITERAL(41, 605, 9), // "sheetName"
QT_MOC_LITERAL(42, 615, 20) // "slots_sql_model_conn"

    },
    "MainWindow\0signals_Load_Data_show\0\0"
    "Model_ba\0mModelBa\0str\0limit\0offset\0"
    "signals_get_flowernumber\0tablename\0"
    "signals_requestExportData\0whereClause\0"
    "exportCompleted\0success\0message\0"
    "signals_checkLogin\0QPair<int,QString>\0"
    "user\0pwd\0on_actions_SQL_triggered\0"
    "slot_sqlConfigChanged\0SqlConnectionConfig\0"
    "config\0on_Btn_Find_clicked\0"
    "on_tabWidget_currentChanged\0index\0"
    "updatePageControls\0totalRows\0"
    "on_Btn_PageUp_clicked\0on_Btn_PageDown_clicked\0"
    "onTabChanged\0on_pushButton_ExportAll_clicked\0"
    "slot_startExport\0slot_writeExcel\0"
    "QList<TableData>\0allData\0"
    "slot_updateExportProgress\0currentTable\0"
    "totalTables\0currentBatch\0totalBatches\0"
    "sheetName\0slots_sql_model_conn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  104,    2, 0x06 /* Public */,
       8,    2,  113,    2, 0x06 /* Public */,
      10,    1,  118,    2, 0x06 /* Public */,
      12,    2,  121,    2, 0x06 /* Public */,
      15,    2,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  131,    2, 0x08 /* Private */,
      20,    1,  132,    2, 0x08 /* Private */,
      23,    0,  135,    2, 0x08 /* Private */,
      24,    1,  136,    2, 0x08 /* Private */,
      26,    2,  139,    2, 0x08 /* Private */,
      28,    0,  144,    2, 0x08 /* Private */,
      29,    0,  145,    2, 0x08 /* Private */,
      30,    1,  146,    2, 0x08 /* Private */,
      31,    0,  149,    2, 0x08 /* Private */,
      32,    0,  150,    2, 0x08 /* Private */,
      33,    1,  151,    2, 0x08 /* Private */,
      36,    5,  154,    2, 0x08 /* Private */,
      42,    0,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString,    9,    5,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   13,   14,
    0x80000000 | 16, QMetaType::QString, QMetaType::QString,   17,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   27,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   37,   38,   39,   40,   41,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_Load_Data_show((*reinterpret_cast< Model_ba(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: { QStringList _r = _t->signals_get_flowernumber((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->signals_requestExportData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->exportCompleted((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { QPair<int,QString> _r = _t->signals_checkLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPair<int,QString>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_actions_SQL_triggered(); break;
        case 6: _t->slot_sqlConfigChanged((*reinterpret_cast< const SqlConnectionConfig(*)>(_a[1]))); break;
        case 7: _t->on_Btn_Find_clicked(); break;
        case 8: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updatePageControls((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_Btn_PageUp_clicked(); break;
        case 11: _t->on_Btn_PageDown_clicked(); break;
        case 12: _t->onTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_pushButton_ExportAll_clicked(); break;
        case 14: _t->slot_startExport(); break;
        case 15: _t->slot_writeExcel((*reinterpret_cast< QList<TableData>(*)>(_a[1]))); break;
        case 16: _t->slot_updateExportProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 17: _t->slots_sql_model_conn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Model_ba >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<TableData> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Model_ba , QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signals_Load_Data_show)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = QStringList (MainWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signals_get_flowernumber)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signals_requestExportData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::exportCompleted)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = QPair<int,QString> (MainWindow::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signals_checkLogin)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signals_Load_Data_show(Model_ba _t1, QString _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
QStringList MainWindow::signals_get_flowernumber(QString _t1, QString _t2)
{
    QStringList _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void MainWindow::signals_requestExportData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::exportCompleted(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
QPair<int,QString> MainWindow::signals_checkLogin(const QString & _t1, const QString & _t2)
{
    QPair<int,QString> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
