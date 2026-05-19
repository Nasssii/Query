/****************************************************************************
** Meta object code from reading C++ file 'finddata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../finddata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finddata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Finddata_t {
    QByteArrayData data[15];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Finddata_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Finddata_t qt_meta_stringdata_Finddata = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Finddata"
QT_MOC_LITERAL(1, 9, 17), // "signals_load_data"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "Tab_Name"
QT_MOC_LITERAL(4, 37, 3), // "str"
QT_MOC_LITERAL(5, 41, 8), // "now_rows"
QT_MOC_LITERAL(6, 50, 11), // "now_CurPage"
QT_MOC_LITERAL(7, 62, 18), // "signals_export_all"
QT_MOC_LITERAL(8, 81, 3), // "sql"
QT_MOC_LITERAL(9, 85, 19), // "on_Btn_Find_clicked"
QT_MOC_LITERAL(10, 105, 23), // "on_Btn_PageDown_clicked"
QT_MOC_LITERAL(11, 129, 21), // "on_Btn_PageUp_clicked"
QT_MOC_LITERAL(12, 151, 14), // "slots_setmodel"
QT_MOC_LITERAL(13, 166, 15), // "QSqlTableModel*"
QT_MOC_LITERAL(14, 182, 6) // "mModel"

    },
    "Finddata\0signals_load_data\0\0Tab_Name\0"
    "str\0now_rows\0now_CurPage\0signals_export_all\0"
    "sql\0on_Btn_Find_clicked\0on_Btn_PageDown_clicked\0"
    "on_Btn_PageUp_clicked\0slots_setmodel\0"
    "QSqlTableModel*\0mModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Finddata[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x06 /* Public */,
       7,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,
      11,    0,   58,    2, 0x08 /* Private */,
      12,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void Finddata::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Finddata *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_load_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->signals_export_all((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_Btn_Find_clicked(); break;
        case 3: _t->on_Btn_PageDown_clicked(); break;
        case 4: _t->on_Btn_PageUp_clicked(); break;
        case 5: _t->slots_setmodel((*reinterpret_cast< QSqlTableModel*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSqlTableModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Finddata::*)(QString , QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Finddata::signals_load_data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Finddata::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Finddata::signals_export_all)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Finddata::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Finddata.data,
    qt_meta_data_Finddata,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Finddata::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Finddata::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Finddata.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Finddata::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Finddata::signals_load_data(QString _t1, QString _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Finddata::signals_export_all(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_mMysqlThread_t {
    QByteArrayData data[41];
    char stringdata0[556];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mMysqlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mMysqlThread_t qt_meta_stringdata_mMysqlThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "mMysqlThread"
QT_MOC_LITERAL(1, 13, 16), // "signals_setmodel"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "QSqlTableModel*"
QT_MOC_LITERAL(4, 47, 6), // "mModel"
QT_MOC_LITERAL(5, 54, 22), // "signals_sql_model_conn"
QT_MOC_LITERAL(6, 77, 16), // "sign_setWordList"
QT_MOC_LITERAL(7, 94, 5), // "words"
QT_MOC_LITERAL(8, 100, 17), // "signal_totalPages"
QT_MOC_LITERAL(9, 118, 9), // "totalRows"
QT_MOC_LITERAL(10, 128, 5), // "limit"
QT_MOC_LITERAL(11, 134, 23), // "signals_exportDataReady"
QT_MOC_LITERAL(12, 158, 16), // "QList<TableData>"
QT_MOC_LITERAL(13, 175, 7), // "allData"
QT_MOC_LITERAL(14, 183, 22), // "signals_exportProgress"
QT_MOC_LITERAL(15, 206, 12), // "currentTable"
QT_MOC_LITERAL(16, 219, 11), // "totalTables"
QT_MOC_LITERAL(17, 231, 12), // "currentBatch"
QT_MOC_LITERAL(18, 244, 12), // "totalBatches"
QT_MOC_LITERAL(19, 257, 9), // "sheetName"
QT_MOC_LITERAL(20, 267, 14), // "slot_Load_Data"
QT_MOC_LITERAL(21, 282, 8), // "Tab_Name"
QT_MOC_LITERAL(22, 291, 3), // "str"
QT_MOC_LITERAL(23, 295, 8), // "now_rows"
QT_MOC_LITERAL(24, 304, 11), // "now_CurPage"
QT_MOC_LITERAL(25, 316, 23), // "slot_fetchDataForExport"
QT_MOC_LITERAL(26, 340, 11), // "whereClause"
QT_MOC_LITERAL(27, 352, 15), // "slot_export_all"
QT_MOC_LITERAL(28, 368, 3), // "sql"
QT_MOC_LITERAL(29, 372, 21), // "slot_exportAllBatched"
QT_MOC_LITERAL(30, 394, 17), // "slot_load_columns"
QT_MOC_LITERAL(31, 412, 9), // "tablename"
QT_MOC_LITERAL(32, 422, 20), // "slot_reloadSqlConfig"
QT_MOC_LITERAL(33, 443, 19), // "slot_Load_Data_show"
QT_MOC_LITERAL(34, 463, 8), // "Model_ba"
QT_MOC_LITERAL(35, 472, 8), // "mModelBa"
QT_MOC_LITERAL(36, 481, 6), // "offset"
QT_MOC_LITERAL(37, 488, 21), // "slot_get_flowernumber"
QT_MOC_LITERAL(38, 510, 19), // "getTotalRecordCount"
QT_MOC_LITERAL(39, 530, 9), // "tableName"
QT_MOC_LITERAL(40, 540, 15) // "getTableColumns"

    },
    "mMysqlThread\0signals_setmodel\0\0"
    "QSqlTableModel*\0mModel\0signals_sql_model_conn\0"
    "sign_setWordList\0words\0signal_totalPages\0"
    "totalRows\0limit\0signals_exportDataReady\0"
    "QList<TableData>\0allData\0"
    "signals_exportProgress\0currentTable\0"
    "totalTables\0currentBatch\0totalBatches\0"
    "sheetName\0slot_Load_Data\0Tab_Name\0str\0"
    "now_rows\0now_CurPage\0slot_fetchDataForExport\0"
    "whereClause\0slot_export_all\0sql\0"
    "slot_exportAllBatched\0slot_load_columns\0"
    "tablename\0slot_reloadSqlConfig\0"
    "slot_Load_Data_show\0Model_ba\0mModelBa\0"
    "offset\0slot_get_flowernumber\0"
    "getTotalRecordCount\0tableName\0"
    "getTableColumns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mMysqlThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       8,    2,  101,    2, 0x06 /* Public */,
      11,    1,  106,    2, 0x06 /* Public */,
      14,    5,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    4,  120,    2, 0x0a /* Public */,
      25,    1,  129,    2, 0x0a /* Public */,
      27,    1,  132,    2, 0x0a /* Public */,
      29,    1,  135,    2, 0x0a /* Public */,
      30,    1,  138,    2, 0x0a /* Public */,
      32,    0,  141,    2, 0x0a /* Public */,
      33,    4,  142,    2, 0x0a /* Public */,
      37,    2,  151,    2, 0x0a /* Public */,
      38,    2,  156,    2, 0x0a /* Public */,
      40,    1,  161,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,   15,   16,   17,   18,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34, QMetaType::QString, QMetaType::Int, QMetaType::Int,   35,   22,   10,   36,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString,   31,   22,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   39,   26,
    QMetaType::QStringList, QMetaType::QString,   39,

       0        // eod
};

void mMysqlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mMysqlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_setmodel((*reinterpret_cast< QSqlTableModel*(*)>(_a[1]))); break;
        case 1: _t->signals_sql_model_conn(); break;
        case 2: _t->sign_setWordList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 3: _t->signal_totalPages((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->signals_exportDataReady((*reinterpret_cast< QList<TableData>(*)>(_a[1]))); break;
        case 5: _t->signals_exportProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 6: _t->slot_Load_Data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->slot_fetchDataForExport((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_export_all((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slot_exportAllBatched((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slot_load_columns((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slot_reloadSqlConfig(); break;
        case 12: _t->slot_Load_Data_show((*reinterpret_cast< Model_ba(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 13: { QStringList _r = _t->slot_get_flowernumber((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->getTotalRecordCount((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { QStringList _r = _t->getTableColumns((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSqlTableModel* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<TableData> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Model_ba >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mMysqlThread::*)(QSqlTableModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::signals_setmodel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mMysqlThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::signals_sql_model_conn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mMysqlThread::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::sign_setWordList)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mMysqlThread::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::signal_totalPages)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (mMysqlThread::*)(QList<TableData> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::signals_exportDataReady)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (mMysqlThread::*)(int , int , int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mMysqlThread::signals_exportProgress)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mMysqlThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_mMysqlThread.data,
    qt_meta_data_mMysqlThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mMysqlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mMysqlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mMysqlThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mMysqlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void mMysqlThread::signals_setmodel(QSqlTableModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mMysqlThread::signals_sql_model_conn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void mMysqlThread::sign_setWordList(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mMysqlThread::signal_totalPages(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void mMysqlThread::signals_exportDataReady(QList<TableData> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void mMysqlThread::signals_exportProgress(int _t1, int _t2, int _t3, int _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
