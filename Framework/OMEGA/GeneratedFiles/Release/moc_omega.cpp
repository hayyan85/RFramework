/****************************************************************************
** Meta object code from reading C++ file 'omega.h'
**
** Created: Fri Nov 1 10:46:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../omega.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'omega.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OMEGA[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      27,    6,    6,    6, 0x0a,
      44,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OMEGA[] = {
    "OMEGA\0\0StartOptionQuoter()\0StopAllQuoters()\0"
    "PauseAllQuoters()\0"
};

void OMEGA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OMEGA *_t = static_cast<OMEGA *>(_o);
        switch (_id) {
        case 0: _t->StartOptionQuoter(); break;
        case 1: _t->StopAllQuoters(); break;
        case 2: _t->PauseAllQuoters(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OMEGA::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OMEGA::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OMEGA,
      qt_meta_data_OMEGA, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OMEGA::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OMEGA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OMEGA::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OMEGA))
        return static_cast<void*>(const_cast< OMEGA*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OMEGA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
