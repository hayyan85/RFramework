/****************************************************************************
** Meta object code from reading C++ file 'Network.h'
**
** Created: Wed Oct 23 11:14:23 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Network.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Framework__NEclipse__QpidSubscriber[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      40,   37,   36,   36, 0x05,
      94,   90,   36,   36, 0x05,
     122,  115,   36,   36, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Framework__NEclipse__QpidSubscriber[] = {
    "Framework::NEclipse::QpidSubscriber\0"
    "\0ot\0QTUpdateOptionTable(Serializable::OptionTick_ser)\0"
    "err\0QTErrorDump(QString)\0symbol\0"
    "QTRemoveSymbol(std::string)\0"
};

void Framework::NEclipse::QpidSubscriber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QpidSubscriber *_t = static_cast<QpidSubscriber *>(_o);
        switch (_id) {
        case 0: _t->QTUpdateOptionTable((*reinterpret_cast< Serializable::OptionTick_ser(*)>(_a[1]))); break;
        case 1: _t->QTErrorDump((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->QTRemoveSymbol((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Framework::NEclipse::QpidSubscriber::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Framework::NEclipse::QpidSubscriber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Framework__NEclipse__QpidSubscriber,
      qt_meta_data_Framework__NEclipse__QpidSubscriber, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Framework::NEclipse::QpidSubscriber::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Framework::NEclipse::QpidSubscriber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Framework::NEclipse::QpidSubscriber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Framework__NEclipse__QpidSubscriber))
        return static_cast<void*>(const_cast< QpidSubscriber*>(this));
    return QObject::qt_metacast(_clname);
}

int Framework::NEclipse::QpidSubscriber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Framework::NEclipse::QpidSubscriber::QTUpdateOptionTable(Serializable::OptionTick_ser _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Framework::NEclipse::QpidSubscriber::QTErrorDump(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Framework::NEclipse::QpidSubscriber::QTRemoveSymbol(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
