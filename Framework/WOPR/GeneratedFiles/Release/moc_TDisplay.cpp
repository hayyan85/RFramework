/****************************************************************************
** Meta object code from reading C++ file 'TDisplay.h'
**
** Created: Thu Oct 3 12:23:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TDisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   10,    9,    9, 0x0a,
      74,   60,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TDisplay[] = {
    "TDisplay\0\0quantity,symb\0"
    "UpdateSiloQuantity(int,std::string)\0"
    "delay_ms,symb\0UpdateFeedDelay(float,std::string)\0"
};

void TDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TDisplay *_t = static_cast<TDisplay *>(_o);
        switch (_id) {
        case 0: _t->UpdateSiloQuantity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->UpdateFeedDelay((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TDisplay,
      qt_meta_data_TDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TDisplay))
        return static_cast<void*>(const_cast< TDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int TDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
