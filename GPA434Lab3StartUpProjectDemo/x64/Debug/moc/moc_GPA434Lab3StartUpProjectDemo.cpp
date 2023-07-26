/****************************************************************************
** Meta object code from reading C++ file 'GPA434Lab3StartUpProjectDemo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GPA434Lab3StartUpProjectDemo.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GPA434Lab3StartUpProjectDemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS = QtMocHelpers::stringData(
    "GPA434Lab3StartUpProjectDemo",
    "startSimulation",
    "",
    "stepSimulation",
    "pauseSimulation",
    "resumeSimulation",
    "stopSimulation",
    "advance",
    "about"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[29];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[16];
    char stringdata5[17];
    char stringdata6[15];
    char stringdata7[8];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS_t qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 28),  // "GPA434Lab3StartUpProjectDemo"
        QT_MOC_LITERAL(29, 15),  // "startSimulation"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 14),  // "stepSimulation"
        QT_MOC_LITERAL(61, 15),  // "pauseSimulation"
        QT_MOC_LITERAL(77, 16),  // "resumeSimulation"
        QT_MOC_LITERAL(94, 14),  // "stopSimulation"
        QT_MOC_LITERAL(109, 7),  // "advance"
        QT_MOC_LITERAL(117, 5)   // "about"
    },
    "GPA434Lab3StartUpProjectDemo",
    "startSimulation",
    "",
    "stepSimulation",
    "pauseSimulation",
    "resumeSimulation",
    "stopSimulation",
    "advance",
    "about"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGPA434Lab3StartUpProjectDemoENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GPA434Lab3StartUpProjectDemo::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGPA434Lab3StartUpProjectDemoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GPA434Lab3StartUpProjectDemo, std::true_type>,
        // method 'startSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stepSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'advance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'about'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GPA434Lab3StartUpProjectDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GPA434Lab3StartUpProjectDemo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startSimulation(); break;
        case 1: _t->stepSimulation(); break;
        case 2: _t->pauseSimulation(); break;
        case 3: _t->resumeSimulation(); break;
        case 4: _t->stopSimulation(); break;
        case 5: _t->advance(); break;
        case 6: _t->about(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *GPA434Lab3StartUpProjectDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GPA434Lab3StartUpProjectDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGPA434Lab3StartUpProjectDemoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GPA434Lab3StartUpProjectDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
