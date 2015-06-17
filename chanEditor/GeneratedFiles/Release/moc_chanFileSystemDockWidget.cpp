/****************************************************************************
** Meta object code from reading C++ file 'chanFileSystemDockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chanFileSystemDockWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chanFileSystemDockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chanFileSystemDockWidget_t {
    QByteArrayData data[16];
    char stringdata[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chanFileSystemDockWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chanFileSystemDockWidget_t qt_meta_stringdata_chanFileSystemDockWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "chanFileSystemDockWidget"
QT_MOC_LITERAL(1, 25, 11), // "createdFile"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "removedFile"
QT_MOC_LITERAL(4, 50, 12), // "importedFile"
QT_MOC_LITERAL(5, 63, 11), // "renamedFile"
QT_MOC_LITERAL(6, 75, 12), // "selectedFile"
QT_MOC_LITERAL(7, 88, 10), // "createFile"
QT_MOC_LITERAL(8, 99, 10), // "removeFile"
QT_MOC_LITERAL(9, 110, 10), // "importFile"
QT_MOC_LITERAL(10, 121, 10), // "renameFile"
QT_MOC_LITERAL(11, 132, 12), // "createFolder"
QT_MOC_LITERAL(12, 145, 12), // "removeFolder"
QT_MOC_LITERAL(13, 158, 13), // "updateActions"
QT_MOC_LITERAL(14, 172, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(15, 189, 12) // "renameFolder"

    },
    "chanFileSystemDockWidget\0createdFile\0"
    "\0removedFile\0importedFile\0renamedFile\0"
    "selectedFile\0createFile\0removeFile\0"
    "importFile\0renameFile\0createFolder\0"
    "removeFolder\0updateActions\0QTreeWidgetItem*\0"
    "renameFolder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chanFileSystemDockWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       5,    2,   88,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    1,  102,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,

       0        // eod
};

void chanFileSystemDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chanFileSystemDockWidget *_t = static_cast<chanFileSystemDockWidget *>(_o);
        switch (_id) {
        case 0: _t->createdFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->removedFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->importedFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->renamedFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->selectedFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->createFile(); break;
        case 6: _t->removeFile(); break;
        case 7: _t->importFile(); break;
        case 8: _t->renameFile(); break;
        case 9: _t->createFolder(); break;
        case 10: _t->removeFolder(); break;
        case 11: _t->updateActions((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->renameFolder(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chanFileSystemDockWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanFileSystemDockWidget::createdFile)) {
                *result = 0;
            }
        }
        {
            typedef void (chanFileSystemDockWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanFileSystemDockWidget::removedFile)) {
                *result = 1;
            }
        }
        {
            typedef void (chanFileSystemDockWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanFileSystemDockWidget::importedFile)) {
                *result = 2;
            }
        }
        {
            typedef void (chanFileSystemDockWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanFileSystemDockWidget::renamedFile)) {
                *result = 3;
            }
        }
        {
            typedef void (chanFileSystemDockWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanFileSystemDockWidget::selectedFile)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject chanFileSystemDockWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_chanFileSystemDockWidget.data,
      qt_meta_data_chanFileSystemDockWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chanFileSystemDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chanFileSystemDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chanFileSystemDockWidget.stringdata))
        return static_cast<void*>(const_cast< chanFileSystemDockWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int chanFileSystemDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
void chanFileSystemDockWidget::createdFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chanFileSystemDockWidget::removedFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void chanFileSystemDockWidget::importedFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void chanFileSystemDockWidget::renamedFile(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void chanFileSystemDockWidget::selectedFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
