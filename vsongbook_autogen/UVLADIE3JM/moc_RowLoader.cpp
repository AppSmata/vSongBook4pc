/****************************************************************************
** Meta object code from reading C++ file 'RowLoader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/RowLoader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RowLoader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RowLoader_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RowLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RowLoader_t qt_meta_stringdata_RowLoader = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RowLoader"
QT_MOC_LITERAL(1, 10, 7), // "fetched"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "token"
QT_MOC_LITERAL(4, 25, 6), // "size_t"
QT_MOC_LITERAL(5, 32, 9), // "row_begin"
QT_MOC_LITERAL(6, 42, 7), // "row_end"
QT_MOC_LITERAL(7, 50, 16), // "rowCountComplete"
QT_MOC_LITERAL(8, 67, 8) // "num_rows"

    },
    "RowLoader\0fetched\0\0token\0size_t\0"
    "row_begin\0row_end\0rowCountComplete\0"
    "num_rows"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RowLoader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       7,    2,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,

       0        // eod
};

void RowLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RowLoader *_t = static_cast<RowLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fetched((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< size_t(*)>(_a[3]))); break;
        case 1: _t->rowCountComplete((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RowLoader::*_t)(int , size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RowLoader::fetched)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RowLoader::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RowLoader::rowCountComplete)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RowLoader::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RowLoader.data,
      qt_meta_data_RowLoader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RowLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RowLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RowLoader.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RowLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RowLoader::fetched(int _t1, size_t _t2, size_t _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RowLoader::rowCountComplete(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
