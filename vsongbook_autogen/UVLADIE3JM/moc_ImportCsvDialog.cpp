/****************************************************************************
** Meta object code from reading C++ file 'ImportCsvDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ImportCsvDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImportCsvDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImportCsvDialog_t {
    QByteArrayData data[11];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImportCsvDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImportCsvDialog_t qt_meta_stringdata_ImportCsvDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ImportCsvDialog"
QT_MOC_LITERAL(1, 16, 6), // "accept"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "updatePreview"
QT_MOC_LITERAL(4, 38, 10), // "checkInput"
QT_MOC_LITERAL(5, 49, 11), // "selectFiles"
QT_MOC_LITERAL(6, 61, 25), // "updateSelectedFilePreview"
QT_MOC_LITERAL(7, 87, 15), // "updateSelection"
QT_MOC_LITERAL(8, 103, 12), // "matchSimilar"
QT_MOC_LITERAL(9, 116, 21), // "toggleAdvancedSection"
QT_MOC_LITERAL(10, 138, 4) // "show"

    },
    "ImportCsvDialog\0accept\0\0updatePreview\0"
    "checkInput\0selectFiles\0updateSelectedFilePreview\0"
    "updateSelection\0matchSimilar\0"
    "toggleAdvancedSection\0show"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImportCsvDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void ImportCsvDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImportCsvDialog *_t = static_cast<ImportCsvDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->updatePreview(); break;
        case 2: _t->checkInput(); break;
        case 3: _t->selectFiles(); break;
        case 4: _t->updateSelectedFilePreview(); break;
        case 5: _t->updateSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->matchSimilar(); break;
        case 7: _t->toggleAdvancedSection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ImportCsvDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ImportCsvDialog.data,
      qt_meta_data_ImportCsvDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImportCsvDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImportCsvDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImportCsvDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ImportCsvDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
