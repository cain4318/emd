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
    QByteArrayData data[16];
    char stringdata0[197];
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
QT_MOC_LITERAL(4, 48, 12), // "doDemoSignal"
QT_MOC_LITERAL(5, 61, 13), // "doAlignSignal"
QT_MOC_LITERAL(6, 75, 14), // "doBottomSignal"
QT_MOC_LITERAL(7, 90, 11), // "doICPSignal"
QT_MOC_LITERAL(8, 102, 9), // "doClicked"
QT_MOC_LITERAL(9, 112, 7), // "btnname"
QT_MOC_LITERAL(10, 120, 15), // "setRootPathSlot"
QT_MOC_LITERAL(11, 136, 14), // "setResPathSlot"
QT_MOC_LITERAL(12, 151, 10), // "doDemoSlot"
QT_MOC_LITERAL(13, 162, 11), // "doAlignSlot"
QT_MOC_LITERAL(14, 174, 12), // "doBottomSlot"
QT_MOC_LITERAL(15, 187, 9) // "doICPSlot"

    },
    "DataProcess\0setRootPathSignal\0\0"
    "setResPathSignal\0doDemoSignal\0"
    "doAlignSignal\0doBottomSignal\0doICPSignal\0"
    "doClicked\0btnname\0setRootPathSlot\0"
    "setResPathSlot\0doDemoSlot\0doAlignSlot\0"
    "doBottomSlot\0doICPSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataProcess[] = {

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
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   85,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
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
        case 2: _t->doDemoSignal(); break;
        case 3: _t->doAlignSignal(); break;
        case 4: _t->doBottomSignal(); break;
        case 5: _t->doICPSignal(); break;
        case 6: _t->doClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setRootPathSlot(); break;
        case 8: _t->setResPathSlot(); break;
        case 9: _t->doDemoSlot(); break;
        case 10: _t->doAlignSlot(); break;
        case 11: _t->doBottomSlot(); break;
        case 12: _t->doICPSlot(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doDemoSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doAlignSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doBottomSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::doICPSignal)) {
                *result = 5;
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
void DataProcess::doDemoSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DataProcess::doAlignSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DataProcess::doBottomSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DataProcess::doICPSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
