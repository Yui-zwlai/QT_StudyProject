/****************************************************************************
** Meta object code from reading C++ file 'widgetnetwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgetnetwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetnetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetNetwork_t {
    QByteArrayData data[21];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetNetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetNetwork_t qt_meta_stringdata_WidgetNetwork = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WidgetNetwork"
QT_MOC_LITERAL(1, 14, 29), // "on_pushButton_Connect_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 26), // "on_pushButton_Send_clicked"
QT_MOC_LITERAL(4, 72, 40), // "on_comboBox_Protocol_currentI..."
QT_MOC_LITERAL(5, 113, 4), // "arg1"
QT_MOC_LITERAL(6, 118, 32), // "on_pushButton_SeendClean_clicked"
QT_MOC_LITERAL(7, 151, 33), // "on_pushButton_ReciveClean_cli..."
QT_MOC_LITERAL(8, 185, 25), // "on_checkBox_Timer_clicked"
QT_MOC_LITERAL(9, 211, 7), // "checked"
QT_MOC_LITERAL(10, 219, 27), // "on_checkBox_SendHex_clicked"
QT_MOC_LITERAL(11, 247, 32), // "on_pushButton_ReciveSave_clicked"
QT_MOC_LITERAL(12, 280, 8), // "ReadData"
QT_MOC_LITERAL(13, 289, 12), // "ConnectError"
QT_MOC_LITERAL(14, 302, 12), // "errorQString"
QT_MOC_LITERAL(15, 315, 13), // "ConnectionAdd"
QT_MOC_LITERAL(16, 329, 10), // "connection"
QT_MOC_LITERAL(17, 340, 16), // "ConnectionRemove"
QT_MOC_LITERAL(18, 357, 12), // "TimerTimeOut"
QT_MOC_LITERAL(19, 370, 14), // "ShortCutButton"
QT_MOC_LITERAL(20, 385, 21) // "on_toolButton_clicked"

    },
    "WidgetNetwork\0on_pushButton_Connect_clicked\0"
    "\0on_pushButton_Send_clicked\0"
    "on_comboBox_Protocol_currentIndexChanged\0"
    "arg1\0on_pushButton_SeendClean_clicked\0"
    "on_pushButton_ReciveClean_clicked\0"
    "on_checkBox_Timer_clicked\0checked\0"
    "on_checkBox_SendHex_clicked\0"
    "on_pushButton_ReciveSave_clicked\0"
    "ReadData\0ConnectError\0errorQString\0"
    "ConnectionAdd\0connection\0ConnectionRemove\0"
    "TimerTimeOut\0ShortCutButton\0"
    "on_toolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetNetwork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      11,    0,  102,    2, 0x08 /* Private */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetNetwork *_t = static_cast<WidgetNetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Connect_clicked(); break;
        case 1: _t->on_pushButton_Send_clicked(); break;
        case 2: _t->on_comboBox_Protocol_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_SeendClean_clicked(); break;
        case 4: _t->on_pushButton_ReciveClean_clicked(); break;
        case 5: _t->on_checkBox_Timer_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_SendHex_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_ReciveSave_clicked(); break;
        case 8: _t->ReadData(); break;
        case 9: _t->ConnectError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ConnectionAdd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->ConnectionRemove((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->TimerTimeOut(); break;
        case 13: _t->ShortCutButton(); break;
        case 14: _t->on_toolButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject WidgetNetwork::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetNetwork.data,
      qt_meta_data_WidgetNetwork,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetNetwork.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
