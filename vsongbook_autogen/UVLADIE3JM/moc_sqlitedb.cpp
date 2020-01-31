/****************************************************************************
** Meta object code from reading C++ file 'sqlitedb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/sqlitedb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlitedb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBBrowserDB_t {
    QByteArrayData data[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBBrowserDB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBBrowserDB_t qt_meta_stringdata_DBBrowserDB = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DBBrowserDB"
QT_MOC_LITERAL(1, 12, 11), // "sqlExecuted"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "sql"
QT_MOC_LITERAL(4, 29, 7), // "msgtype"
QT_MOC_LITERAL(5, 37, 9), // "dbChanged"
QT_MOC_LITERAL(6, 47, 5), // "dirty"
QT_MOC_LITERAL(7, 53, 16), // "structureUpdated"
QT_MOC_LITERAL(8, 70, 16), // "requestCollation"
QT_MOC_LITERAL(9, 87, 4), // "name"
QT_MOC_LITERAL(10, 92, 8), // "eTextRep"
QT_MOC_LITERAL(11, 101, 20), // "databaseInUseChanged"
QT_MOC_LITERAL(12, 122, 4), // "busy"
QT_MOC_LITERAL(13, 127, 4) // "user"

    },
    "DBBrowserDB\0sqlExecuted\0\0sql\0msgtype\0"
    "dbChanged\0dirty\0structureUpdated\0"
    "requestCollation\0name\0eTextRep\0"
    "databaseInUseChanged\0busy\0user"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBBrowserDB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,
       7,    0,   47,    2, 0x06 /* Public */,
       8,    2,   48,    2, 0x06 /* Public */,
      11,    2,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   12,   13,

       0        // eod
};

void DBBrowserDB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBBrowserDB *_t = static_cast<DBBrowserDB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sqlExecuted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->dbChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->structureUpdated(); break;
        case 3: _t->requestCollation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->databaseInUseChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DBBrowserDB::*_t)(QString , int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBBrowserDB::sqlExecuted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DBBrowserDB::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBBrowserDB::dbChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DBBrowserDB::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBBrowserDB::structureUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DBBrowserDB::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBBrowserDB::requestCollation)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DBBrowserDB::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBBrowserDB::databaseInUseChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject DBBrowserDB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBBrowserDB.data,
      qt_meta_data_DBBrowserDB,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBBrowserDB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBBrowserDB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBBrowserDB.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBBrowserDB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DBBrowserDB::sqlExecuted(QString _t1, int _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< DBBrowserDB *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBBrowserDB::dbChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DBBrowserDB::structureUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DBBrowserDB::requestCollation(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DBBrowserDB::databaseInUseChanged(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
