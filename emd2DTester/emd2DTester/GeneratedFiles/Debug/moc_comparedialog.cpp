/****************************************************************************
** Meta object code from reading C++ file 'comparedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../comparedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comparedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_compareDialog_t {
    QByteArrayData data[16];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_compareDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_compareDialog_t qt_meta_stringdata_compareDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "compareDialog"
QT_MOC_LITERAL(1, 14, 17), // "setimg1PathSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "setimg2PathSignal"
QT_MOC_LITERAL(4, 51, 16), // "setResPathSignal"
QT_MOC_LITERAL(5, 68, 13), // "calDiffSignal"
QT_MOC_LITERAL(6, 82, 14), // "saveDiffSignal"
QT_MOC_LITERAL(7, 97, 13), // "saveAllSignal"
QT_MOC_LITERAL(8, 111, 9), // "doClicked"
QT_MOC_LITERAL(9, 121, 7), // "btnname"
QT_MOC_LITERAL(10, 129, 15), // "setimg1PathSlot"
QT_MOC_LITERAL(11, 145, 15), // "setimg2PathSlot"
QT_MOC_LITERAL(12, 161, 14), // "setResPathSlot"
QT_MOC_LITERAL(13, 176, 11), // "calDiffSlot"
QT_MOC_LITERAL(14, 188, 12), // "saveDiffSlot"
QT_MOC_LITERAL(15, 201, 11) // "saveAllSlot"

    },
    "compareDialog\0setimg1PathSignal\0\0"
    "setimg2PathSignal\0setResPathSignal\0"
    "calDiffSignal\0saveDiffSignal\0saveAllSignal\0"
    "doClicked\0btnname\0setimg1PathSlot\0"
    "setimg2PathSlot\0setResPathSlot\0"
    "calDiffSlot\0saveDiffSlot\0saveAllSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_compareDialog[] = {

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

void compareDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        compareDialog *_t = static_cast<compareDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setimg1PathSignal(); break;
        case 1: _t->setimg2PathSignal(); break;
        case 2: _t->setResPathSignal(); break;
        case 3: _t->calDiffSignal(); break;
        case 4: _t->saveDiffSignal(); break;
        case 5: _t->saveAllSignal(); break;
        case 6: _t->doClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setimg1PathSlot(); break;
        case 8: _t->setimg2PathSlot(); break;
        case 9: _t->setResPathSlot(); break;
        case 10: _t->calDiffSlot(); break;
        case 11: _t->saveDiffSlot(); break;
        case 12: _t->saveAllSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::setimg1PathSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::setimg2PathSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::setResPathSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::calDiffSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::saveDiffSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (compareDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&compareDialog::saveAllSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject compareDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_compareDialog.data,
      qt_meta_data_compareDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *compareDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *compareDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_compareDialog.stringdata0))
        return static_cast<void*>(const_cast< compareDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int compareDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void compareDialog::setimg1PathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void compareDialog::setimg2PathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void compareDialog::setResPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void compareDialog::calDiffSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void compareDialog::saveDiffSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void compareDialog::saveAllSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
