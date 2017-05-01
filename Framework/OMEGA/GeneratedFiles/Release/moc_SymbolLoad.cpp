/****************************************************************************
** Meta object code from reading C++ file 'SymbolLoad.h'
**
** Created: Fri Nov 1 10:46:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SymbolLoad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SymbolLoad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SymbolLoad[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      39,   35,   11,   11, 0x0a,
      62,   35,   11,   11, 0x0a,
      88,   35,   11,   11, 0x0a,
     111,   35,   11,   11, 0x0a,
     137,   35,   11,   11, 0x0a,
     160,   35,   11,   11, 0x0a,
     186,   35,   11,   11, 0x0a,
     209,   35,   11,   11, 0x0a,
     235,   35,   11,   11, 0x0a,
     258,   35,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,
     314,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SymbolLoad[] = {
    "SymbolLoad\0\0ProcessSymbolDetails()\0"
    "itm\0Q_DateChanged(QString)\0"
    "Q_CallPutChanged(QString)\0"
    "A_DateChanged(QString)\0A_CallPutChanged(QString)\0"
    "B_DateChanged(QString)\0B_CallPutChanged(QString)\0"
    "C_DateChanged(QString)\0C_CallPutChanged(QString)\0"
    "D_DateChanged(QString)\0D_CallPutChanged(QString)\0"
    "RetrieveCorrespondingSymbol()\0"
    "CancelForm()\0"
};

void SymbolLoad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SymbolLoad *_t = static_cast<SymbolLoad *>(_o);
        switch (_id) {
        case 0: _t->ProcessSymbolDetails(); break;
        case 1: _t->Q_DateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Q_CallPutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->A_DateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->A_CallPutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->B_DateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->B_CallPutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->C_DateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->C_CallPutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->D_DateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->D_CallPutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->RetrieveCorrespondingSymbol(); break;
        case 12: _t->CancelForm(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SymbolLoad::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SymbolLoad::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SymbolLoad,
      qt_meta_data_SymbolLoad, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SymbolLoad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SymbolLoad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SymbolLoad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SymbolLoad))
        return static_cast<void*>(const_cast< SymbolLoad*>(this));
    return QDialog::qt_metacast(_clname);
}

int SymbolLoad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
