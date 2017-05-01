/****************************************************************************
** Meta object code from reading C++ file 'Eclipse.h'
**
** Created: Tue Oct 22 10:26:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Eclipse.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Eclipse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Eclipse[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   21,    9,    8, 0x0a,
      55,    8,    8,    8, 0x0a,
      76,    8,    8,    8, 0x0a,
      99,    8,    8,    8, 0x0a,
     124,    8,    8,    8, 0x0a,
     147,    8,    8,    8, 0x0a,
     181,  172,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Eclipse[] = {
    "Eclipse\0\0std::string\0item_\0"
    "GetConfigValue(std::string)\0"
    "DisplayUpdateFeeds()\0DisplayEquityScanner()\0"
    "DisplayVolatilityGraph()\0"
    "DisplayOptionScanner()\0DisplayExpirationGraph()\0"
    "ErrorMsg\0ErrorDisplay(QString)\0"
};

void Eclipse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Eclipse *_t = static_cast<Eclipse *>(_o);
        switch (_id) {
        case 0: { std::string _r = _t->GetConfigValue((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 1: _t->DisplayUpdateFeeds(); break;
        case 2: _t->DisplayEquityScanner(); break;
        case 3: _t->DisplayVolatilityGraph(); break;
        case 4: _t->DisplayOptionScanner(); break;
        case 5: _t->DisplayExpirationGraph(); break;
        case 6: _t->ErrorDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Eclipse::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Eclipse::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Eclipse,
      qt_meta_data_Eclipse, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Eclipse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Eclipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Eclipse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Eclipse))
        return static_cast<void*>(const_cast< Eclipse*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Eclipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
