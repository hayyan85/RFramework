/****************************************************************************
** Meta object code from reading C++ file 'Network.h'
**
** Created: Thu Oct 3 12:23:02 2013
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
static const uint qt_meta_data_Framework__WOPR__QpidConnector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   32,   31,   31, 0x05,
      91,   87,   31,   31, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Framework__WOPR__QpidConnector[] = {
    "Framework::WOPR::QpidConnector\0\0ot\0"
    "QTDisplayOnOptionForm(Serializable::OptionTick_ser)\0"
    "msg\0QTConsoleMessage(std::string)\0"
};

void Framework::WOPR::QpidConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QpidConnector *_t = static_cast<QpidConnector *>(_o);
        switch (_id) {
        case 0: _t->QTDisplayOnOptionForm((*reinterpret_cast< Serializable::OptionTick_ser(*)>(_a[1]))); break;
        case 1: _t->QTConsoleMessage((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Framework::WOPR::QpidConnector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Framework::WOPR::QpidConnector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Framework__WOPR__QpidConnector,
      qt_meta_data_Framework__WOPR__QpidConnector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Framework::WOPR::QpidConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Framework::WOPR::QpidConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Framework::WOPR::QpidConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Framework__WOPR__QpidConnector))
        return static_cast<void*>(const_cast< QpidConnector*>(this));
    return QObject::qt_metacast(_clname);
}

int Framework::WOPR::QpidConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Framework::WOPR::QpidConnector::QTDisplayOnOptionForm(Serializable::OptionTick_ser _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Framework::WOPR::QpidConnector::QTConsoleMessage(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
