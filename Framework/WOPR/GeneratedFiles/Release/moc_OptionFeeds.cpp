/****************************************************************************
** Meta object code from reading C++ file 'OptionFeeds.h'
**
** Created: Thu Oct 3 12:23:02 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OptionFeeds.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionFeeds.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OptionFeeds[] = {

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
      19,   13,   12,   12, 0x0a,
      84,   80,   12,   12, 0x0a,
     112,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OptionFeeds[] = {
    "OptionFeeds\0\0otick\0"
    "OptionFeeds_ManageTableUpdates(Serializable::OptionTick_ser)\0"
    "msg\0ConsoleMessage(std::string)\0"
    "SearchSymbol()\0"
};

void OptionFeeds::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OptionFeeds *_t = static_cast<OptionFeeds *>(_o);
        switch (_id) {
        case 0: _t->OptionFeeds_ManageTableUpdates((*reinterpret_cast< Serializable::OptionTick_ser(*)>(_a[1]))); break;
        case 1: _t->ConsoleMessage((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->SearchSymbol(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OptionFeeds::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OptionFeeds::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionFeeds,
      qt_meta_data_OptionFeeds, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OptionFeeds::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OptionFeeds::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OptionFeeds::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionFeeds))
        return static_cast<void*>(const_cast< OptionFeeds*>(this));
    return QWidget::qt_metacast(_clname);
}

int OptionFeeds::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
