/****************************************************************************
** Meta object code from reading C++ file 'RemotePushDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/RemotePushDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemotePushDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemotePushDialog_t {
    QByteArrayData data[13];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemotePushDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemotePushDialog_t qt_meta_stringdata_RemotePushDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RemotePushDialog"
QT_MOC_LITERAL(1, 17, 10), // "checkInput"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "accept"
QT_MOC_LITERAL(4, 36, 16), // "reloadBranchList"
QT_MOC_LITERAL(5, 53, 14), // "fillInLicences"
QT_MOC_LITERAL(6, 68, 48), // "std::vector<std::pair<std::st..."
QT_MOC_LITERAL(7, 117, 8), // "licences"
QT_MOC_LITERAL(8, 126, 14), // "fillInBranches"
QT_MOC_LITERAL(9, 141, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(10, 166, 8), // "branches"
QT_MOC_LITERAL(11, 175, 11), // "std::string"
QT_MOC_LITERAL(12, 187, 14) // "default_branch"

    },
    "RemotePushDialog\0checkInput\0\0accept\0"
    "reloadBranchList\0fillInLicences\0"
    "std::vector<std::pair<std::string,std::string> >\0"
    "licences\0fillInBranches\0"
    "std::vector<std::string>\0branches\0"
    "std::string\0default_branch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemotePushDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    0,   41,    2, 0x09 /* Protected */,
       5,    1,   42,    2, 0x09 /* Protected */,
       8,    2,   45,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,

       0        // eod
};

void RemotePushDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemotePushDialog *_t = static_cast<RemotePushDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkInput(); break;
        case 1: _t->accept(); break;
        case 2: _t->reloadBranchList(); break;
        case 3: _t->fillInLicences((*reinterpret_cast< const std::vector<std::pair<std::string,std::string> >(*)>(_a[1]))); break;
        case 4: _t->fillInBranches((*reinterpret_cast< const std::vector<std::string>(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject RemotePushDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RemotePushDialog.data,
      qt_meta_data_RemotePushDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RemotePushDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemotePushDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemotePushDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RemotePushDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
