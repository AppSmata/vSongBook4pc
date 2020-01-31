/****************************************************************************
** Meta object code from reading C++ file 'ExtendedTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ExtendedTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExtendedTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UniqueFilterModel_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UniqueFilterModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UniqueFilterModel_t qt_meta_stringdata_UniqueFilterModel = {
    {
QT_MOC_LITERAL(0, 0, 17) // "UniqueFilterModel"

    },
    "UniqueFilterModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UniqueFilterModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void UniqueFilterModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject UniqueFilterModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_UniqueFilterModel.data,
      qt_meta_data_UniqueFilterModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UniqueFilterModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UniqueFilterModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UniqueFilterModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int UniqueFilterModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ExtendedTableWidgetEditorDelegate_t {
    QByteArrayData data[1];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExtendedTableWidgetEditorDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExtendedTableWidgetEditorDelegate_t qt_meta_stringdata_ExtendedTableWidgetEditorDelegate = {
    {
QT_MOC_LITERAL(0, 0, 33) // "ExtendedTableWidgetEditorDele..."

    },
    "ExtendedTableWidgetEditorDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtendedTableWidgetEditorDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ExtendedTableWidgetEditorDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ExtendedTableWidgetEditorDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_ExtendedTableWidgetEditorDelegate.data,
      qt_meta_data_ExtendedTableWidgetEditorDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExtendedTableWidgetEditorDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtendedTableWidgetEditorDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtendedTableWidgetEditorDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int ExtendedTableWidgetEditorDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ExtendedTableWidget_t {
    QByteArrayData data[27];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExtendedTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExtendedTableWidget_t qt_meta_stringdata_ExtendedTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ExtendedTableWidget"
QT_MOC_LITERAL(1, 20, 17), // "foreignKeyClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 22), // "sqlb::ObjectIdentifier"
QT_MOC_LITERAL(4, 62, 5), // "table"
QT_MOC_LITERAL(5, 68, 11), // "std::string"
QT_MOC_LITERAL(6, 80, 6), // "column"
QT_MOC_LITERAL(7, 87, 5), // "value"
QT_MOC_LITERAL(8, 93, 11), // "switchTable"
QT_MOC_LITERAL(9, 105, 4), // "next"
QT_MOC_LITERAL(10, 110, 21), // "openFileFromDropEvent"
QT_MOC_LITERAL(11, 132, 23), // "selectedRowsToBeDeleted"
QT_MOC_LITERAL(12, 156, 15), // "editCondFormats"
QT_MOC_LITERAL(13, 172, 19), // "currentIndexChanged"
QT_MOC_LITERAL(14, 192, 7), // "current"
QT_MOC_LITERAL(15, 200, 8), // "previous"
QT_MOC_LITERAL(16, 209, 14), // "reloadSettings"
QT_MOC_LITERAL(17, 224, 15), // "selectTableLine"
QT_MOC_LITERAL(18, 240, 12), // "lineToSelect"
QT_MOC_LITERAL(19, 253, 16), // "selectTableLines"
QT_MOC_LITERAL(20, 270, 9), // "firstLine"
QT_MOC_LITERAL(21, 280, 5), // "count"
QT_MOC_LITERAL(22, 286, 9), // "selectAll"
QT_MOC_LITERAL(23, 296, 15), // "openPrintDialog"
QT_MOC_LITERAL(24, 312, 17), // "vscrollbarChanged"
QT_MOC_LITERAL(25, 330, 11), // "cellClicked"
QT_MOC_LITERAL(26, 342, 5) // "index"

    },
    "ExtendedTableWidget\0foreignKeyClicked\0"
    "\0sqlb::ObjectIdentifier\0table\0std::string\0"
    "column\0value\0switchTable\0next\0"
    "openFileFromDropEvent\0selectedRowsToBeDeleted\0"
    "editCondFormats\0currentIndexChanged\0"
    "current\0previous\0reloadSettings\0"
    "selectTableLine\0lineToSelect\0"
    "selectTableLines\0firstLine\0count\0"
    "selectAll\0openPrintDialog\0vscrollbarChanged\0"
    "cellClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtendedTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
      10,    1,   89,    2, 0x06 /* Public */,
      11,    0,   92,    2, 0x06 /* Public */,
      12,    1,   93,    2, 0x06 /* Public */,
      13,    2,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  101,    2, 0x0a /* Public */,
      17,    1,  102,    2, 0x0a /* Public */,
      19,    2,  105,    2, 0x0a /* Public */,
      22,    0,  110,    2, 0x0a /* Public */,
      23,    0,  111,    2, 0x0a /* Public */,
      24,    1,  112,    2, 0x08 /* Private */,
      25,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QByteArray,    4,    6,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QModelIndex,   26,

       0        // eod
};

void ExtendedTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExtendedTableWidget *_t = static_cast<ExtendedTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->foreignKeyClicked((*reinterpret_cast< const sqlb::ObjectIdentifier(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 1: _t->switchTable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->openFileFromDropEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->selectedRowsToBeDeleted(); break;
        case 4: _t->editCondFormats((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->currentIndexChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 6: _t->reloadSettings(); break;
        case 7: _t->selectTableLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->selectTableLines((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->selectAll(); break;
        case 10: _t->openPrintDialog(); break;
        case 11: _t->vscrollbarChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->cellClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ExtendedTableWidget::*_t)(const sqlb::ObjectIdentifier & , const std::string & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::foreignKeyClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ExtendedTableWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::switchTable)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ExtendedTableWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::openFileFromDropEvent)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ExtendedTableWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::selectedRowsToBeDeleted)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ExtendedTableWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::editCondFormats)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ExtendedTableWidget::*_t)(const QModelIndex & , const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtendedTableWidget::currentIndexChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ExtendedTableWidget::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_ExtendedTableWidget.data,
      qt_meta_data_ExtendedTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExtendedTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtendedTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtendedTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int ExtendedTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
void ExtendedTableWidget::foreignKeyClicked(const sqlb::ObjectIdentifier & _t1, const std::string & _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExtendedTableWidget::switchTable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExtendedTableWidget::openFileFromDropEvent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ExtendedTableWidget::selectedRowsToBeDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ExtendedTableWidget::editCondFormats(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ExtendedTableWidget::currentIndexChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
