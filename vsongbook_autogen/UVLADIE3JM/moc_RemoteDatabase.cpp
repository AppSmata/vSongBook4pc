/****************************************************************************
** Meta object code from reading C++ file 'RemoteDatabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/RemoteDatabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemoteDatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteDatabase_t {
    QByteArrayData data[20];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteDatabase_t qt_meta_stringdata_RemoteDatabase = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RemoteDatabase"
QT_MOC_LITERAL(1, 15, 12), // "networkReady"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "openFile"
QT_MOC_LITERAL(4, 38, 4), // "path"
QT_MOC_LITERAL(5, 43, 10), // "gotDirList"
QT_MOC_LITERAL(6, 54, 4), // "json"
QT_MOC_LITERAL(7, 59, 8), // "userdata"
QT_MOC_LITERAL(8, 68, 17), // "gotCurrentVersion"
QT_MOC_LITERAL(9, 86, 7), // "version"
QT_MOC_LITERAL(10, 94, 3), // "url"
QT_MOC_LITERAL(11, 98, 14), // "gotLicenceList"
QT_MOC_LITERAL(12, 113, 48), // "std::vector<std::pair<std::st..."
QT_MOC_LITERAL(13, 162, 8), // "licences"
QT_MOC_LITERAL(14, 171, 13), // "gotBranchList"
QT_MOC_LITERAL(15, 185, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(16, 210, 8), // "branches"
QT_MOC_LITERAL(17, 219, 11), // "std::string"
QT_MOC_LITERAL(18, 231, 14), // "default_branch"
QT_MOC_LITERAL(19, 246, 14) // "uploadFinished"

    },
    "RemoteDatabase\0networkReady\0\0openFile\0"
    "path\0gotDirList\0json\0userdata\0"
    "gotCurrentVersion\0version\0url\0"
    "gotLicenceList\0"
    "std::vector<std::pair<std::string,std::string> >\0"
    "licences\0gotBranchList\0std::vector<std::string>\0"
    "branches\0std::string\0default_branch\0"
    "uploadFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteDatabase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    2,   53,    2, 0x06 /* Public */,
       8,    2,   58,    2, 0x06 /* Public */,
      11,    1,   63,    2, 0x06 /* Public */,
      14,    2,   66,    2, 0x06 /* Public */,
      19,    1,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void, 0x80000000 | 17,   10,

       0        // eod
};

void RemoteDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteDatabase *_t = static_cast<RemoteDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->networkReady(); break;
        case 1: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->gotDirList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->gotCurrentVersion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->gotLicenceList((*reinterpret_cast< std::vector<std::pair<std::string,std::string> >(*)>(_a[1]))); break;
        case 5: _t->gotBranchList((*reinterpret_cast< std::vector<std::string>(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 6: _t->uploadFinished((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RemoteDatabase::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::networkReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::openFile)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::gotDirList)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::gotCurrentVersion)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(std::vector<std::pair<std::string,std::string>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::gotLicenceList)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(std::vector<std::string> , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::gotBranchList)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (RemoteDatabase::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteDatabase::uploadFinished)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject RemoteDatabase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RemoteDatabase.data,
      qt_meta_data_RemoteDatabase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RemoteDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteDatabase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RemoteDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RemoteDatabase::networkReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RemoteDatabase::openFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RemoteDatabase::gotDirList(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RemoteDatabase::gotCurrentVersion(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RemoteDatabase::gotLicenceList(std::vector<std::pair<std::string,std::string>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RemoteDatabase::gotBranchList(std::vector<std::string> _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RemoteDatabase::uploadFinished(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
