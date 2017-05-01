/****************************************************************************
** Meta object code from reading C++ file 'UpdateFeeds.h'
**
** Created: Thu Oct 3 12:23:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UpdateFeeds.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpdateFeeds.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UpdateFeeds[] = {

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
      13,   12,   12,   12, 0x0a,
      43,   39,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UpdateFeeds[] = {
    "UpdateFeeds\0\0Slot_InitiateConnection()\0"
    "ind\0TableClicked(QStandardItem*)\0"
};

void UpdateFeeds::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UpdateFeeds *_t = static_cast<UpdateFeeds *>(_o);
        switch (_id) {
        case 0: _t->Slot_InitiateConnection(); break;
        case 1: _t->TableClicked((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UpdateFeeds::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UpdateFeeds::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UpdateFeeds,
      qt_meta_data_UpdateFeeds, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UpdateFeeds::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UpdateFeeds::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UpdateFeeds::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateFeeds))
        return static_cast<void*>(const_cast< UpdateFeeds*>(this));
    return QWidget::qt_metacast(_clname);
}

int UpdateFeeds::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
