/****************************************************************************
** Meta object code from reading C++ file 'vSongBooklist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/vSongBooklist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vSongBooklist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vSongBooklist_t {
    QByteArrayData data[17];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vSongBooklist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vSongBooklist_t qt_meta_stringdata_vSongBooklist = {
    {
QT_MOC_LITERAL(0, 0, 13), // "vSongBooklist"
QT_MOC_LITERAL(1, 14, 8), // "LoadBook"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "GetUpdates"
QT_MOC_LITERAL(4, 35, 12), // "LoadBooklist"
QT_MOC_LITERAL(5, 48, 9), // "searchstr"
QT_MOC_LITERAL(6, 58, 11), // "SaveChanges"
QT_MOC_LITERAL(7, 70, 10), // "DeleteBook"
QT_MOC_LITERAL(8, 81, 19), // "on_LstBooks_clicked"
QT_MOC_LITERAL(9, 101, 5), // "index"
QT_MOC_LITERAL(10, 107, 24), // "on_TxtSearch_textChanged"
QT_MOC_LITERAL(11, 132, 4), // "arg1"
QT_MOC_LITERAL(12, 137, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(13, 160, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(14, 184, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(15, 210, 26), // "on_actionRefresh_triggered"
QT_MOC_LITERAL(16, 237, 25) // "on_actionUpdate_triggered"

    },
    "vSongBooklist\0LoadBook\0\0GetUpdates\0"
    "LoadBooklist\0searchstr\0SaveChanges\0"
    "DeleteBook\0on_LstBooks_clicked\0index\0"
    "on_TxtSearch_textChanged\0arg1\0"
    "on_actionNew_triggered\0on_actionSave_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionRefresh_triggered\0"
    "on_actionUpdate_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vSongBooklist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vSongBooklist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vSongBooklist *_t = static_cast<vSongBooklist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadBook(); break;
        case 1: _t->GetUpdates(); break;
        case 2: _t->LoadBooklist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SaveChanges(); break;
        case 4: _t->DeleteBook(); break;
        case 5: _t->on_LstBooks_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_TxtSearch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_actionNew_triggered(); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionDelete_triggered(); break;
        case 10: _t->on_actionRefresh_triggered(); break;
        case 11: _t->on_actionUpdate_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject vSongBooklist::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vSongBooklist.data,
      qt_meta_data_vSongBooklist,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *vSongBooklist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vSongBooklist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vSongBooklist.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int vSongBooklist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
