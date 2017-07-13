/****************************************************************************
** Meta object code from reading C++ file 'dataprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dataprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataProcess_t {
    QByteArrayData data[20];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataProcess_t qt_meta_stringdata_DataProcess = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataProcess"
QT_MOC_LITERAL(1, 12, 17), // "setRootPathSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "setResPathSignal"
QT_MOC_LITERAL(4, 48, 14), // "doRenameSignal"
QT_MOC_LITERAL(5, 63, 11), // "doCutSignal"
QT_MOC_LITERAL(6, 75, 12), // "doPlusSignal"
QT_MOC_LITERAL(7, 88, 14), // "doResizeSignal"
QT_MOC_LITERAL(8, 103, 17), // "doRenameAllSignal"
QT_MOC_LITERAL(9, 121, 13), // "doSclarSignal"
QT_MOC_LITERAL(10, 135, 9), // "doClicked"
QT_MOC_LITERAL(11, 145, 7), // "btnname"
QT_MOC_LITERAL(12, 153, 15), // "setRootPathSlot"
QT_MOC_LITERAL(13, 169, 14), // "setResPathSlot"
QT_MOC_LITERAL(14, 184, 12), // "doRenameSlot"
QT_MOC_LITERAL(15, 197, 9), // "doCutSlot"
QT_MOC_LITERAL(16, 207, 10), // "doPlusSlot"
QT_MOC_LITERAL(17, 218, 12), // "doResizeSlot"
QT_MOC_LITERAL(18, 231, 15), // "doRenameAllSlot"
QT_MOC_LITERAL(19, 247, 11) // "doSclarSlot"

    },
    "DataProcess\0setRootPathSignal\0\0"
    "setResPathSignal\0doRenameSignal\0"
    "doCutSignal\0doPlusSignal\0doResizeSignal\0"
    "doRenameAllSignal\0doSclarSignal\0"
    "doClicked\0btnname\0setRootPathSlot\0"
    "setResPathSlot\0doRenameSlot\0doCutSlot\0"
    "doPlusSlot\0doResizeSlot\0doRenameAllSlot\0"
    "doSclarSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,
       7,    0,  104,    2, 0x06 /* Public */,
       8,    0,  105,    2, 0x06 /* Public */,
       9,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  107,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
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

void DataProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataProcess *_t = static_cast<DataProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRootPathSignal(); break;
        case 1: _t->setResPathSignal(); break;
        case 2: _t->doRenameSignal(); break;
        case 3: _t->doCutSignal(); break;
        case 4: _t->doPlusSignal(); break;
        case 5: _t->doResizeSignal(); break;
        case 6: _t->doRenameAllSignal(); break;
        case 7: _t->doSclarSignal(); break;
        case 8: _t->doClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setRootPathSlot(); break;
        case 10: _t->setResPathSlot(); break;
        case 11: _t->doRenameSlot(); break;
        case 12: _t->doCutSlot(); break;
        case 13: _t->doPlusSlot(); break;
        case 14: _t->doResizeSlot(); break;
        case 15: _t->doRenameAllSlot(); break;
        case 16: _t->doSclarSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::setRootPathSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::setResPathSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doRenameSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doCutSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doPlusSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doResizeSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doRenameAllSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doSclarSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject DataProcess::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DataProcess.data,
      qt_meta_data_DataProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataProcess.stringdata0))
        return static_cast<void*>(const_cast< DataProcess*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DataProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DataProcess::setRootPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DataProcess::setResPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DataProcess::doRenameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DataProcess::doCutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DataProcess::doPlusSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DataProcess::doResizeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void DataProcess::doRenameAllSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void DataProcess::doSclarSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
