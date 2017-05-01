/****************************************************************************
** Meta object code from reading C++ file 'OptionQuoter.h'
**
** Created: Fri Nov 1 10:46:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OptionQuoter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionQuoter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OptionQuoter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      37,   31,   13,   13, 0x0a,
      92,   85,   13,   13, 0x0a,
     147,  127,   13,   13, 0x0a,
     196,  192,   13,   13, 0x0a,
     233,  229,   13,   13, 0x0a,
     278,  192,   13,   13, 0x0a,
     311,   13,   13,   13, 0x0a,
     348,  339,   13,   13, 0x0a,
     381,   13,   13,   13, 0x0a,
     399,   13,   13,   13, 0x0a,
     412,   13,   13,   13, 0x0a,
     426,   13,   13,   13, 0x0a,
     440,   13,   13,   13, 0x0a,
     462,   13,   13,   13, 0x0a,
     486,   13,   13,   13, 0x0a,
     507,  503,   13,   13, 0x0a,
     533,   13,   13,   13, 0x0a,
     550,   13,   13,   13, 0x0a,
     567,   13,   13,   13, 0x0a,
     586,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OptionQuoter[] = {
    "OptionQuoter\0\0ShowSymbolList()\0otick\0"
    "UpdateOptionModel(Serializable::OptionTick_ser)\0"
    "symbol\0RemoveSymbolFromModel(std::string)\0"
    "topLeft,bottomRight\0"
    "ExchangeDataChanged(QModelIndex,QModelIndex)\0"
    "itm\0ExchangeSelected(QStandardItem*)\0"
    "pkt\0UpdateOpenOrder(Serializable::RUpdatePacket)\0"
    "CancelOrderCheck(QStandardItem*)\0"
    "TimerSlotEnableGUITimeOut()\0ErrorMsg\0"
    "DisplayErrorMessage(std::string)\0"
    "PauseAutomation()\0HideFilter()\0"
    "HideConsole()\0HideUpdates()\0"
    "AddExpressionFilter()\0AddColumnToExpression()\0"
    "TestExpression()\0pos\0FilterContextMenu(QPoint)\0"
    "SaveExpression()\0LoadExpression()\0"
    "ManageAutomation()\0Run_SPX_Algo1_NeutralAction()\0"
};

void OptionQuoter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OptionQuoter *_t = static_cast<OptionQuoter *>(_o);
        switch (_id) {
        case 0: _t->ShowSymbolList(); break;
        case 1: _t->UpdateOptionModel((*reinterpret_cast< Serializable::OptionTick_ser(*)>(_a[1]))); break;
        case 2: _t->RemoveSymbolFromModel((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->ExchangeDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->ExchangeSelected((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 5: _t->UpdateOpenOrder((*reinterpret_cast< Serializable::RUpdatePacket(*)>(_a[1]))); break;
        case 6: _t->CancelOrderCheck((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 7: _t->TimerSlotEnableGUITimeOut(); break;
        case 8: _t->DisplayErrorMessage((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->PauseAutomation(); break;
        case 10: _t->HideFilter(); break;
        case 11: _t->HideConsole(); break;
        case 12: _t->HideUpdates(); break;
        case 13: _t->AddExpressionFilter(); break;
        case 14: _t->AddColumnToExpression(); break;
        case 15: _t->TestExpression(); break;
        case 16: _t->FilterContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 17: _t->SaveExpression(); break;
        case 18: _t->LoadExpression(); break;
        case 19: _t->ManageAutomation(); break;
        case 20: _t->Run_SPX_Algo1_NeutralAction(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OptionQuoter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OptionQuoter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OptionQuoter,
      qt_meta_data_OptionQuoter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OptionQuoter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OptionQuoter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OptionQuoter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionQuoter))
        return static_cast<void*>(const_cast< OptionQuoter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OptionQuoter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
