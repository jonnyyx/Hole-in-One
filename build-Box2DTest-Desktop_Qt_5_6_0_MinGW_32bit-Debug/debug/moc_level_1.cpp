/****************************************************************************
** Meta object code from reading C++ file 'level_1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Box2D and GUI test/level_1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'level_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Level_1_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Level_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Level_1_t qt_meta_stringdata_Level_1 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Level_1"
QT_MOC_LITERAL(1, 8, 6), // "update"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "startLevel"
QT_MOC_LITERAL(4, 27, 10), // "pauseLevel"
QT_MOC_LITERAL(5, 38, 11), // "resumeLevel"
QT_MOC_LITERAL(6, 50, 12), // "addRectangle"
QT_MOC_LITERAL(7, 63, 9), // "addCircle"
QT_MOC_LITERAL(8, 73, 16), // "highscoreCounter"
QT_MOC_LITERAL(9, 90, 5) // "reset"

    },
    "Level_1\0update\0\0startLevel\0pauseLevel\0"
    "resumeLevel\0addRectangle\0addCircle\0"
    "highscoreCounter\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Level_1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
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

void Level_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Level_1 *_t = static_cast<Level_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->startLevel(); break;
        case 2: _t->pauseLevel(); break;
        case 3: _t->resumeLevel(); break;
        case 4: _t->addRectangle(); break;
        case 5: _t->addCircle(); break;
        case 6: _t->highscoreCounter(); break;
        case 7: _t->reset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Level_1::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Level_1.data,
      qt_meta_data_Level_1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Level_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Level_1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Level_1.stringdata0))
        return static_cast<void*>(const_cast< Level_1*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Level_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
