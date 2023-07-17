/****************************************************************************
** Meta object code from reading C++ file 'car_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "car_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'car_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface_t qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface = {
    {
QT_MOC_LITERAL(0, 0, 39), // "OrgExampleExamplesCarInterfac..."
QT_MOC_LITERAL(1, 40, 7), // "crashed"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 10), // "accelerate"
QT_MOC_LITERAL(4, 60, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(5, 80, 10), // "decelerate"
QT_MOC_LITERAL(6, 91, 8), // "turnLeft"
QT_MOC_LITERAL(7, 100, 9) // "turnRight"

    },
    "OrgExampleExamplesCarInterfaceInterface\0"
    "crashed\0\0accelerate\0QDBusPendingReply<>\0"
    "decelerate\0turnLeft\0turnRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrgExampleExamplesCarInterfaceInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,
       6,    0,   42,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,

       0        // eod
};

void OrgExampleExamplesCarInterfaceInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrgExampleExamplesCarInterfaceInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->crashed(); break;
        case 1: { QDBusPendingReply<> _r = _t->accelerate();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->decelerate();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<> _r = _t->turnLeft();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<> _r = _t->turnRight();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrgExampleExamplesCarInterfaceInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrgExampleExamplesCarInterfaceInterface::crashed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrgExampleExamplesCarInterfaceInterface::staticMetaObject = { {
    &QDBusAbstractInterface::staticMetaObject,
    qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface.data,
    qt_meta_data_OrgExampleExamplesCarInterfaceInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrgExampleExamplesCarInterfaceInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrgExampleExamplesCarInterfaceInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrgExampleExamplesCarInterfaceInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgExampleExamplesCarInterfaceInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
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
void OrgExampleExamplesCarInterfaceInterface::crashed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
