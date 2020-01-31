/****************************************************************************
** Meta object code from reading C++ file 'FilterTableHeader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/FilterTableHeader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterTableHeader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterTableHeader_t {
    QByteArrayData data[21];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterTableHeader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterTableHeader_t qt_meta_stringdata_FilterTableHeader = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FilterTableHeader"
QT_MOC_LITERAL(1, 18, 13), // "filterChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "size_t"
QT_MOC_LITERAL(4, 40, 6), // "column"
QT_MOC_LITERAL(5, 47, 5), // "value"
QT_MOC_LITERAL(6, 53, 13), // "addCondFormat"
QT_MOC_LITERAL(7, 67, 6), // "filter"
QT_MOC_LITERAL(8, 74, 21), // "allCondFormatsCleared"
QT_MOC_LITERAL(9, 96, 17), // "condFormatsEdited"
QT_MOC_LITERAL(10, 114, 15), // "generateFilters"
QT_MOC_LITERAL(11, 130, 6), // "number"
QT_MOC_LITERAL(12, 137, 9), // "showFirst"
QT_MOC_LITERAL(13, 147, 15), // "adjustPositions"
QT_MOC_LITERAL(14, 163, 12), // "clearFilters"
QT_MOC_LITERAL(15, 176, 9), // "setFilter"
QT_MOC_LITERAL(16, 186, 12), // "inputChanged"
QT_MOC_LITERAL(17, 199, 9), // "new_value"
QT_MOC_LITERAL(18, 209, 21), // "addFilterAsCondFormat"
QT_MOC_LITERAL(19, 231, 19), // "clearAllCondFormats"
QT_MOC_LITERAL(20, 251, 15) // "editCondFormats"

    },
    "FilterTableHeader\0filterChanged\0\0"
    "size_t\0column\0value\0addCondFormat\0"
    "filter\0allCondFormatsCleared\0"
    "condFormatsEdited\0generateFilters\0"
    "number\0showFirst\0adjustPositions\0"
    "clearFilters\0setFilter\0inputChanged\0"
    "new_value\0addFilterAsCondFormat\0"
    "clearAllCondFormats\0editCondFormats"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterTableHeader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       6,    2,   84,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,
       9,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   95,    2, 0x0a /* Public */,
      10,    1,  100,    2, 0x2a /* Public | MethodCloned */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    2,  105,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,   11,   12,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterTableHeader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterTableHeader *_t = static_cast<FilterTableHeader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterChanged((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->addCondFormat((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->allCondFormatsCleared((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 3: _t->condFormatsEdited((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 4: _t->generateFilters((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->generateFilters((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 6: _t->adjustPositions(); break;
        case 7: _t->clearFilters(); break;
        case 8: _t->setFilter((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->inputChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->addFilterAsCondFormat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->clearAllCondFormats(); break;
        case 12: _t->editCondFormats(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FilterTableHeader::*_t)(size_t , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterTableHeader::filterChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FilterTableHeader::*_t)(size_t , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterTableHeader::addCondFormat)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FilterTableHeader::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterTableHeader::allCondFormatsCleared)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FilterTableHeader::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterTableHeader::condFormatsEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject FilterTableHeader::staticMetaObject = {
    { &QHeaderView::staticMetaObject, qt_meta_stringdata_FilterTableHeader.data,
      qt_meta_data_FilterTableHeader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FilterTableHeader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterTableHeader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterTableHeader.stringdata0))
        return static_cast<void*>(this);
    return QHeaderView::qt_metacast(_clname);
}

int FilterTableHeader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FilterTableHeader::filterChanged(size_t _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterTableHeader::addCondFormat(size_t _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FilterTableHeader::allCondFormatsCleared(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FilterTableHeader::condFormatsEdited(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
