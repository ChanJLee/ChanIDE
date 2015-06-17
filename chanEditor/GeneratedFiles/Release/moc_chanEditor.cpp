/****************************************************************************
** Meta object code from reading C++ file 'chanEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chanEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chanEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chanEditor_t {
    QByteArrayData data[23];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chanEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chanEditor_t qt_meta_stringdata_chanEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "chanEditor"
QT_MOC_LITERAL(1, 11, 8), // "openFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "closeFile"
QT_MOC_LITERAL(4, 31, 10), // "renameFile"
QT_MOC_LITERAL(5, 42, 10), // "selectFile"
QT_MOC_LITERAL(6, 53, 26), // "createFileSystemDockWidget"
QT_MOC_LITERAL(7, 80, 13), // "updateActions"
QT_MOC_LITERAL(8, 94, 7), // "newFile"
QT_MOC_LITERAL(9, 102, 4), // "open"
QT_MOC_LITERAL(10, 107, 4), // "save"
QT_MOC_LITERAL(11, 112, 6), // "saveAs"
QT_MOC_LITERAL(12, 119, 4), // "redo"
QT_MOC_LITERAL(13, 124, 4), // "undo"
QT_MOC_LITERAL(14, 129, 3), // "cut"
QT_MOC_LITERAL(15, 133, 4), // "copy"
QT_MOC_LITERAL(16, 138, 5), // "paste"
QT_MOC_LITERAL(17, 144, 7), // "aboutMe"
QT_MOC_LITERAL(18, 152, 23), // "setWhitespaceVisibility"
QT_MOC_LITERAL(19, 176, 5), // "build"
QT_MOC_LITERAL(20, 182, 3), // "run"
QT_MOC_LITERAL(21, 186, 8), // "shutDown"
QT_MOC_LITERAL(22, 195, 21) // "addToOutputDockWidget"

    },
    "chanEditor\0openFile\0\0closeFile\0"
    "renameFile\0selectFile\0createFileSystemDockWidget\0"
    "updateActions\0newFile\0open\0save\0saveAs\0"
    "redo\0undo\0cut\0copy\0paste\0aboutMe\0"
    "setWhitespaceVisibility\0build\0run\0"
    "shutDown\0addToOutputDockWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chanEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x08 /* Private */,
       3,    1,  122,    2, 0x08 /* Private */,
       4,    2,  125,    2, 0x08 /* Private */,
       5,    1,  130,    2, 0x08 /* Private */,
       6,    0,  133,    2, 0x08 /* Private */,
       7,    0,  134,    2, 0x08 /* Private */,
       8,    0,  135,    2, 0x08 /* Private */,
       9,    0,  136,    2, 0x08 /* Private */,
      10,    0,  137,    2, 0x08 /* Private */,
      11,    0,  138,    2, 0x08 /* Private */,
      12,    0,  139,    2, 0x08 /* Private */,
      13,    0,  140,    2, 0x08 /* Private */,
      14,    0,  141,    2, 0x08 /* Private */,
      15,    0,  142,    2, 0x08 /* Private */,
      16,    0,  143,    2, 0x08 /* Private */,
      17,    0,  144,    2, 0x08 /* Private */,
      18,    1,  145,    2, 0x08 /* Private */,
      19,    0,  148,    2, 0x08 /* Private */,
      20,    0,  149,    2, 0x08 /* Private */,
      21,    0,  150,    2, 0x08 /* Private */,
      22,    1,  151,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void chanEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chanEditor *_t = static_cast<chanEditor *>(_o);
        switch (_id) {
        case 0: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->closeFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->renameFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->selectFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->createFileSystemDockWidget(); break;
        case 5: _t->updateActions(); break;
        case 6: _t->newFile(); break;
        case 7: _t->open(); break;
        case 8: _t->save(); break;
        case 9: _t->saveAs(); break;
        case 10: _t->redo(); break;
        case 11: _t->undo(); break;
        case 12: _t->cut(); break;
        case 13: _t->copy(); break;
        case 14: _t->paste(); break;
        case 15: _t->aboutMe(); break;
        case 16: _t->setWhitespaceVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->build(); break;
        case 18: _t->run(); break;
        case 19: _t->shutDown(); break;
        case 20: _t->addToOutputDockWidget((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject chanEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_chanEditor.data,
      qt_meta_data_chanEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chanEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chanEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chanEditor.stringdata))
        return static_cast<void*>(const_cast< chanEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int chanEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
