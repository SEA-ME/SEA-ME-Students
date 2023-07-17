/****************************************************************************
** Meta object code from reading C++ file 'car_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "car_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'car_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarInterfaceAdaptor_t {
    QByteArrayData data[11];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarInterfaceAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarInterfaceAdaptor_t qt_meta_stringdata_CarInterfaceAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CarInterfaceAdaptor"
QT_MOC_LITERAL(1, 20, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 36, 33), // "org.example.Examples.CarInter..."
QT_MOC_LITERAL(3, 70, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 90, 243), // "  <interface name=\"org.examp..."
QT_MOC_LITERAL(5, 315, 7), // "crashed"
QT_MOC_LITERAL(6, 323, 0), // ""
QT_MOC_LITERAL(7, 324, 10), // "accelerate"
QT_MOC_LITERAL(8, 335, 10), // "decelerate"
QT_MOC_LITERAL(9, 346, 8), // "turnLeft"
QT_MOC_LITERAL(10, 355, 9) // "turnRight"

    },
    "CarInterfaceAdaptor\0D-Bus Interface\0"
    "org.example.Examples.CarInterface\0"
    "D-Bus Introspection\0"
    "  <interface name=\"org.example.Examples.CarInterface\">\n    <method "
    "name=\"accelerate\"/>\n    <method name=\"decelerate\"/>\n    <method "
    "name=\"turnLeft\"/>\n    <method name=\"turnRight\"/>\n    <signal nam"
    "e=\"crashed\"/>\n  </interface>\n\0"
    "crashed\0\0accelerate\0decelerate\0turnLeft\0"
    "turnRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarInterfaceAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       5,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    0,   43,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    6, 0x0a /* Public */,
       8,    0,   45,    6, 0x0a /* Public */,
       9,    0,   46,    6, 0x0a /* Public */,
      10,    0,   47,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CarInterfaceAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarInterfaceAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->crashed(); break;
        case 1: _t->accelerate(); break;
        case 2: _t->decelerate(); break;
        case 3: _t->turnLeft(); break;
        case 4: _t->turnRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarInterfaceAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarInterfaceAdaptor::crashed)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CarInterfaceAdaptor::staticMetaObject = { {
    &QDBusAbstractAdaptor::staticMetaObject,
    qt_meta_stringdata_CarInterfaceAdaptor.data,
    qt_meta_data_CarInterfaceAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarInterfaceAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarInterfaceAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarInterfaceAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int CarInterfaceAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
void CarInterfaceAdaptor::crashed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
