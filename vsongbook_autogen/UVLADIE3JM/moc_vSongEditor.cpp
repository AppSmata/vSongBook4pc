/****************************************************************************
** Meta object code from reading C++ file 'vSongEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/vSongEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vSongEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vSongEditor_t {
    QByteArrayData data[15];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vSongEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vSongEditor_t qt_meta_stringdata_vSongEditor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "vSongEditor"
QT_MOC_LITERAL(1, 12, 12), // "ShowFeedback"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "show"
QT_MOC_LITERAL(4, 31, 10), // "DeleteSong"
QT_MOC_LITERAL(5, 42, 14), // "ReloadSettings"
QT_MOC_LITERAL(6, 57, 17), // "PopulateSongbooks"
QT_MOC_LITERAL(7, 75, 8), // "LoadSong"
QT_MOC_LITERAL(8, 84, 11), // "SaveChanges"
QT_MOC_LITERAL(9, 96, 15), // "ShowExtraFields"
QT_MOC_LITERAL(10, 112, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(11, 136, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(12, 162, 24), // "on_actionClear_triggered"
QT_MOC_LITERAL(13, 187, 24), // "on_actionExtra_triggered"
QT_MOC_LITERAL(14, 212, 22) // "on_BtnFeedback_clicked"

    },
    "vSongEditor\0ShowFeedback\0\0show\0"
    "DeleteSong\0ReloadSettings\0PopulateSongbooks\0"
    "LoadSong\0SaveChanges\0ShowExtraFields\0"
    "on_actionSave_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionClear_triggered\0"
    "on_actionExtra_triggered\0"
    "on_BtnFeedback_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vSongEditor[] = {

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
       1,    1,   74,    2, 0x08 /* Private */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vSongEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vSongEditor *_t = static_cast<vSongEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowFeedback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->DeleteSong(); break;
        case 2: _t->ReloadSettings(); break;
        case 3: { bool _r = _t->PopulateSongbooks();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->LoadSong(); break;
        case 5: _t->SaveChanges(); break;
        case 6: _t->ShowExtraFields(); break;
        case 7: _t->on_actionSave_triggered(); break;
        case 8: _t->on_actionDelete_triggered(); break;
        case 9: _t->on_actionClear_triggered(); break;
        case 10: _t->on_actionExtra_triggered(); break;
        case 11: _t->on_BtnFeedback_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject vSongEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vSongEditor.data,
      qt_meta_data_vSongEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *vSongEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vSongEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vSongEditor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int vSongEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
