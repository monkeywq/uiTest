/****************************************************************************
** Meta object code from reading C++ file 'uiTest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uiTest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiTest_t {
    QByteArrayData data[16];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiTest_t qt_meta_stringdata_uiTest = {
    {
QT_MOC_LITERAL(0, 0, 6), // "uiTest"
QT_MOC_LITERAL(1, 7, 12), // "slotOpenFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "slotTest2"
QT_MOC_LITERAL(4, 31, 16), // "slotControlInput"
QT_MOC_LITERAL(5, 48, 13), // "slotViewCurve"
QT_MOC_LITERAL(6, 62, 18), // "slotSerialPortInit"
QT_MOC_LITERAL(7, 81, 22), // "slotSerialPortSendData"
QT_MOC_LITERAL(8, 104, 24), // "slotSerialPortReciveData"
QT_MOC_LITERAL(9, 129, 19), // "slotSerialPortClose"
QT_MOC_LITERAL(10, 149, 22), // "slotSerialPortTestInit"
QT_MOC_LITERAL(11, 172, 12), // "slotSaveFile"
QT_MOC_LITERAL(12, 185, 16), // "slotChangeGKPram"
QT_MOC_LITERAL(13, 202, 16), // "slotSelectGKFile"
QT_MOC_LITERAL(14, 219, 18), // "slotSelectGKNumber"
QT_MOC_LITERAL(15, 238, 11) // "slotStopSys"

    },
    "uiTest\0slotOpenFile\0\0slotTest2\0"
    "slotControlInput\0slotViewCurve\0"
    "slotSerialPortInit\0slotSerialPortSendData\0"
    "slotSerialPortReciveData\0slotSerialPortClose\0"
    "slotSerialPortTestInit\0slotSaveFile\0"
    "slotChangeGKPram\0slotSelectGKFile\0"
    "slotSelectGKNumber\0slotStopSys"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiTest *_t = static_cast<uiTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotOpenFile(); break;
        case 1: _t->slotTest2(); break;
        case 2: _t->slotControlInput(); break;
        case 3: _t->slotViewCurve(); break;
        case 4: _t->slotSerialPortInit(); break;
        case 5: _t->slotSerialPortSendData(); break;
        case 6: _t->slotSerialPortReciveData(); break;
        case 7: _t->slotSerialPortClose(); break;
        case 8: _t->slotSerialPortTestInit(); break;
        case 9: _t->slotSaveFile(); break;
        case 10: _t->slotChangeGKPram(); break;
        case 11: _t->slotSelectGKFile(); break;
        case 12: _t->slotSelectGKNumber(); break;
        case 13: _t->slotStopSys(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject uiTest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_uiTest.data,
      qt_meta_data_uiTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *uiTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_uiTest.stringdata0))
        return static_cast<void*>(const_cast< uiTest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int uiTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
