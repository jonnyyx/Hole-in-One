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
    QByteArrayData data[16];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Level_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Level_1_t qt_meta_stringdata_Level_1 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Level_1"
QT_MOC_LITERAL(1, 8, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QItemSelection"
QT_MOC_LITERAL(4, 41, 8), // "selected"
QT_MOC_LITERAL(5, 50, 10), // "deselected"
QT_MOC_LITERAL(6, 61, 6), // "update"
QT_MOC_LITERAL(7, 68, 10), // "startLevel"
QT_MOC_LITERAL(8, 79, 10), // "pauseLevel"
QT_MOC_LITERAL(9, 90, 11), // "resumeLevel"
QT_MOC_LITERAL(10, 102, 12), // "addRectangle"
QT_MOC_LITERAL(11, 115, 9), // "addCircle"
QT_MOC_LITERAL(12, 125, 16), // "highscoreCounter"
QT_MOC_LITERAL(13, 142, 5), // "reset"
QT_MOC_LITERAL(14, 148, 10), // "rotateLeft"
QT_MOC_LITERAL(15, 159, 11) // "rotateRight"

    },
    "Level_1\0selectionChanged\0\0QItemSelection\0"
    "selected\0deselected\0update\0startLevel\0"
    "pauseLevel\0resumeLevel\0addRectangle\0"
    "addCircle\0highscoreCounter\0reset\0"
    "rotateLeft\0rotateRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Level_1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,
      14,    0,   82,    2, 0x0a /* Public */,
      15,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

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

       0        // eod
};

void Level_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Level_1 *_t = static_cast<Level_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->update(); break;
        case 2: _t->startLevel(); break;
        case 3: _t->pauseLevel(); break;
        case 4: _t->resumeLevel(); break;
        case 5: _t->addRectangle(); break;
        case 6: _t->addCircle(); break;
        case 7: _t->highscoreCounter(); break;
        case 8: _t->reset(); break;
        case 9: _t->rotateLeft(); break;
        case 10: _t->rotateRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Level_1::*_t)(const QItemSelection & , const QItemSelection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Level_1::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Level_1::selectionChanged(const QItemSelection & _t1, const QItemSelection & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
