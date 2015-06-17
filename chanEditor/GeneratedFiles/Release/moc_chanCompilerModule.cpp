/****************************************************************************
** Meta object code from reading C++ file 'chanCompilerModule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chanCompilerModule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chanCompilerModule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chanCompilerModule_t {
    QByteArrayData data[7];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chanCompilerModule_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chanCompilerModule_t qt_meta_stringdata_chanCompilerModule = {
    {
QT_MOC_LITERAL(0, 0, 18), // "chanCompilerModule"
QT_MOC_LITERAL(1, 19, 8), // "finished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "result"
QT_MOC_LITERAL(4, 36, 10), // "getResults"
QT_MOC_LITERAL(5, 47, 6), // "finish"
QT_MOC_LITERAL(6, 54, 5) // "build"

    },
    "chanCompilerModule\0finished\0\0result\0"
    "getResults\0finish\0build"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chanCompilerModule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    2,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,    2,    2,

       0        // eod
};

void chanCompilerModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chanCompilerModule *_t = static_cast<chanCompilerModule *>(_o);
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->result((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->getResults(); break;
        case 3: _t->finish(); break;
        case 4: _t->build((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chanCompilerModule::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanCompilerModule::finished)) {
                *result = 0;
            }
        }
        {
            typedef void (chanCompilerModule::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chanCompilerModule::result)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject chanCompilerModule::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_chanCompilerModule.data,
      qt_meta_data_chanCompilerModule,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chanCompilerModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chanCompilerModule::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chanCompilerModule.stringdata))
        return static_cast<void*>(const_cast< chanCompilerModule*>(this));
    return QObject::qt_metacast(_clname);
}

int chanCompilerModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void chanCompilerModule::finished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chanCompilerModule::result(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
