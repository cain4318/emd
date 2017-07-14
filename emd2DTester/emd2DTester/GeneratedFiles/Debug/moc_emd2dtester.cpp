/****************************************************************************
** Meta object code from reading C++ file 'emd2dtester.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../emd2dtester.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emd2dtester.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_emd2DTester_t {
    QByteArrayData data[20];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_emd2DTester_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_emd2DTester_t qt_meta_stringdata_emd2DTester = {
    {
QT_MOC_LITERAL(0, 0, 11), // "emd2DTester"
QT_MOC_LITERAL(1, 12, 17), // "setRootPathSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "setResPathSignal"
QT_MOC_LITERAL(4, 48, 13), // "calPairSignal"
QT_MOC_LITERAL(5, 62, 14), // "savePairSignal"
QT_MOC_LITERAL(6, 77, 14), // "saveGradSignal"
QT_MOC_LITERAL(7, 92, 16), // "calsaveAllSignal"
QT_MOC_LITERAL(8, 109, 9), // "doClicked"
QT_MOC_LITERAL(9, 119, 7), // "btnname"
QT_MOC_LITERAL(10, 127, 15), // "setRootPathSlot"
QT_MOC_LITERAL(11, 143, 14), // "setResPathSlot"
QT_MOC_LITERAL(12, 158, 16), // "setPairIndexSlot"
QT_MOC_LITERAL(13, 175, 5), // "index"
QT_MOC_LITERAL(14, 181, 13), // "setRadiusSlot"
QT_MOC_LITERAL(15, 195, 1), // "r"
QT_MOC_LITERAL(16, 197, 11), // "calPairSlot"
QT_MOC_LITERAL(17, 209, 12), // "savePairSlot"
QT_MOC_LITERAL(18, 222, 12), // "saveGradSlot"
QT_MOC_LITERAL(19, 235, 14) // "calsaveAllSlot"

    },
    "emd2DTester\0setRootPathSignal\0\0"
    "setResPathSignal\0calPairSignal\0"
    "savePairSignal\0saveGradSignal\0"
    "calsaveAllSignal\0doClicked\0btnname\0"
    "setRootPathSlot\0setResPathSlot\0"
    "setPairIndexSlot\0index\0setRadiusSlot\0"
    "r\0calPairSlot\0savePairSlot\0saveGradSlot\0"
    "calsaveAllSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_emd2DTester[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   95,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void emd2DTester::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        emd2DTester *_t = static_cast<emd2DTester *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRootPathSignal(); break;
        case 1: _t->setResPathSignal(); break;
        case 2: _t->calPairSignal(); break;
        case 3: _t->savePairSignal(); break;
        case 4: _t->saveGradSignal(); break;
        case 5: _t->calsaveAllSignal(); break;
        case 6: _t->doClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setRootPathSlot(); break;
        case 8: _t->setResPathSlot(); break;
        case 9: _t->setPairIndexSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setRadiusSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->calPairSlot(); break;
        case 12: _t->savePairSlot(); break;
        case 13: _t->saveGradSlot(); break;
        case 14: _t->calsaveAllSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::setRootPathSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::setResPathSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::calPairSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::savePairSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::saveGradSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (emd2DTester::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&emd2DTester::calsaveAllSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject emd2DTester::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_emd2DTester.data,
      qt_meta_data_emd2DTester,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *emd2DTester::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *emd2DTester::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_emd2DTester.stringdata0))
        return static_cast<void*>(const_cast< emd2DTester*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int emd2DTester::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void emd2DTester::setRootPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void emd2DTester::setResPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void emd2DTester::calPairSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void emd2DTester::savePairSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void emd2DTester::saveGradSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void emd2DTester::calsaveAllSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
