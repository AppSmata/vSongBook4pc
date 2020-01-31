/****************************************************************************
** Meta object code from reading C++ file 'vSongOnline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/vSongOnline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vSongOnline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vSongOnline_t {
    QByteArrayData data[18];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vSongOnline_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vSongOnline_t qt_meta_stringdata_vSongOnline = {
    {
QT_MOC_LITERAL(0, 0, 11), // "vSongOnline"
QT_MOC_LITERAL(1, 12, 13), // "onBooksResult"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 42, 5), // "reply"
QT_MOC_LITERAL(5, 48, 13), // "onSongsResult"
QT_MOC_LITERAL(6, 62, 14), // "createListView"
QT_MOC_LITERAL(7, 77, 9), // "LoadBooks"
QT_MOC_LITERAL(8, 87, 9), // "LoadSongs"
QT_MOC_LITERAL(9, 97, 15), // "progressManager"
QT_MOC_LITERAL(10, 113, 3), // "ist"
QT_MOC_LITERAL(11, 117, 3), // "max"
QT_MOC_LITERAL(12, 121, 12), // "showProgress"
QT_MOC_LITERAL(13, 134, 4), // "show"
QT_MOC_LITERAL(14, 139, 19), // "on_LstBooks_clicked"
QT_MOC_LITERAL(15, 159, 5), // "index"
QT_MOC_LITERAL(16, 165, 21), // "on_BtnProceed_clicked"
QT_MOC_LITERAL(17, 187, 20) // "on_BtnCancel_clicked"

    },
    "vSongOnline\0onBooksResult\0\0QNetworkReply*\0"
    "reply\0onSongsResult\0createListView\0"
    "LoadBooks\0LoadSongs\0progressManager\0"
    "ist\0max\0showProgress\0show\0on_LstBooks_clicked\0"
    "index\0on_BtnProceed_clicked\0"
    "on_BtnCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vSongOnline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    2,   73,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      16,    0,   84,    2, 0x08 /* Private */,
      17,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vSongOnline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vSongOnline *_t = static_cast<vSongOnline *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onBooksResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->onSongsResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->createListView(); break;
        case 3: _t->LoadBooks(); break;
        case 4: _t->LoadSongs(); break;
        case 5: _t->progressManager((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 6: _t->showProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_LstBooks_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_BtnProceed_clicked(); break;
        case 9: _t->on_BtnCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject vSongOnline::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vSongOnline.data,
      qt_meta_data_vSongOnline,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *vSongOnline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vSongOnline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vSongOnline.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int vSongOnline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
