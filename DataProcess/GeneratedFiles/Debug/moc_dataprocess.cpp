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
    char stringdata0[271];
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
QT_MOC_LITERAL(4, 48, 13), // "calGardSignal"
QT_MOC_LITERAL(5, 62, 12), // "calDisSignal"
QT_MOC_LITERAL(6, 75, 15), // "readData1Signal"
QT_MOC_LITERAL(7, 91, 15), // "readData2Signal"
QT_MOC_LITERAL(8, 107, 15), // "cal2DGardSignal"
QT_MOC_LITERAL(9, 123, 17), // "calBatchDisSignal"
QT_MOC_LITERAL(10, 141, 9), // "doClicked"
QT_MOC_LITERAL(11, 151, 7), // "btnname"
QT_MOC_LITERAL(12, 159, 15), // "setRootPathSlot"
QT_MOC_LITERAL(13, 175, 14), // "setResPathSlot"
QT_MOC_LITERAL(14, 190, 11), // "calGradSlot"
QT_MOC_LITERAL(15, 202, 10), // "calDisSlot"
QT_MOC_LITERAL(16, 213, 13), // "readData1Slot"
QT_MOC_LITERAL(17, 227, 13), // "readData2Slot"
QT_MOC_LITERAL(18, 241, 13), // "cal2DGradSlot"
QT_MOC_LITERAL(19, 255, 15) // "calBatchDisSlot"

    },
    "DataProcess\0setRootPathSignal\0\0"
    "setResPathSignal\0calGardSignal\0"
    "calDisSignal\0readData1Signal\0"
    "readData2Signal\0cal2DGardSignal\0"
    "calBatchDisSignal\0doClicked\0btnname\0"
    "setRootPathSlot\0setResPathSlot\0"
    "calGradSlot\0calDisSlot\0readData1Slot\0"
    "readData2Slot\0cal2DGradSlot\0calBatchDisSlot"
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
        case 2: _t->calGardSignal(); break;
        case 3: _t->calDisSignal(); break;
        case 4: _t->readData1Signal(); break;
        case 5: _t->readData2Signal(); break;
        case 6: _t->cal2DGardSignal(); break;
        case 7: _t->calBatchDisSignal(); break;
        case 8: _t->doClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setRootPathSlot(); break;
        case 10: _t->setResPathSlot(); break;
        case 11: _t->calGradSlot(); break;
        case 12: _t->calDisSlot(); break;
        case 13: _t->readData1Slot(); break;
        case 14: _t->readData2Slot(); break;
        case 15: _t->cal2DGradSlot(); break;
        case 16: _t->calBatchDisSlot(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::calGardSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::calDisSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::readData1Signal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::readData2Signal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::cal2DGardSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (DataProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataProcess::calBatchDisSignal)) {
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
void DataProcess::calGardSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DataProcess::calDisSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DataProcess::readData1Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DataProcess::readData2Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void DataProcess::cal2DGardSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void DataProcess::calBatchDisSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
