/****************************************************************************
** Meta object code from reading C++ file 'sqlitetablemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/sqlitetablemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlitetablemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SqliteTableModel_t {
    QByteArrayData data[13];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SqliteTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SqliteTableModel_t qt_meta_stringdata_SqliteTableModel = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SqliteTableModel"
QT_MOC_LITERAL(1, 17, 13), // "finishedFetch"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "fetched_row_begin"
QT_MOC_LITERAL(4, 50, 15), // "fetched_row_end"
QT_MOC_LITERAL(5, 66, 16), // "finishedRowCount"
QT_MOC_LITERAL(6, 83, 12), // "updateFilter"
QT_MOC_LITERAL(7, 96, 6), // "size_t"
QT_MOC_LITERAL(8, 103, 6), // "column"
QT_MOC_LITERAL(9, 110, 5), // "value"
QT_MOC_LITERAL(10, 116, 18), // "updateGlobalFilter"
QT_MOC_LITERAL(11, 135, 20), // "std::vector<QString>"
QT_MOC_LITERAL(12, 156, 6) // "values"

    },
    "SqliteTableModel\0finishedFetch\0\0"
    "fetched_row_begin\0fetched_row_end\0"
    "finishedRowCount\0updateFilter\0size_t\0"
    "column\0value\0updateGlobalFilter\0"
    "std::vector<QString>\0values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqliteTableModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   40,    2, 0x0a /* Public */,
      10,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void SqliteTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqliteTableModel *_t = static_cast<SqliteTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishedFetch((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->finishedRowCount(); break;
        case 2: _t->updateFilter((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->updateGlobalFilter((*reinterpret_cast< const std::vector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SqliteTableModel::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SqliteTableModel::finishedFetch)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SqliteTableModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SqliteTableModel::finishedRowCount)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SqliteTableModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_SqliteTableModel.data,
      qt_meta_data_SqliteTableModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SqliteTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqliteTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SqliteTableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int SqliteTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SqliteTableModel::finishedFetch(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SqliteTableModel::finishedRowCount()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
