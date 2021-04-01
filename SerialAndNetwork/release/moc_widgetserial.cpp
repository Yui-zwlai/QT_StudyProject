/****************************************************************************
** Meta object code from reading C++ file 'widgetserial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgetserial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetserial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetSerial_t {
    QByteArrayData data[13];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetSerial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetSerial_t qt_meta_stringdata_WidgetSerial = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WidgetSerial"
QT_MOC_LITERAL(1, 13, 23), // "on_SwitchButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_SendButton_clicked"
QT_MOC_LITERAL(4, 60, 28), // "on_CleanReciveButton_clicked"
QT_MOC_LITERAL(5, 89, 26), // "on_CleanSendButton_clicked"
QT_MOC_LITERAL(6, 116, 29), // "on_checkBox_ReciveHex_clicked"
QT_MOC_LITERAL(7, 146, 7), // "checked"
QT_MOC_LITERAL(8, 154, 27), // "on_checkBox_SendHex_clicked"
QT_MOC_LITERAL(9, 182, 32), // "on_pushButton_emptyCount_clicked"
QT_MOC_LITERAL(10, 215, 14), // "ReadSerialData"
QT_MOC_LITERAL(11, 230, 12), // "TimerTimeOut"
QT_MOC_LITERAL(12, 243, 30) // "on_pushButton_openFile_clicked"

    },
    "WidgetSerial\0on_SwitchButton_clicked\0"
    "\0on_SendButton_clicked\0"
    "on_CleanReciveButton_clicked\0"
    "on_CleanSendButton_clicked\0"
    "on_checkBox_ReciveHex_clicked\0checked\0"
    "on_checkBox_SendHex_clicked\0"
    "on_pushButton_emptyCount_clicked\0"
    "ReadSerialData\0TimerTimeOut\0"
    "on_pushButton_openFile_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetSerial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetSerial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetSerial *_t = static_cast<WidgetSerial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SwitchButton_clicked(); break;
        case 1: _t->on_SendButton_clicked(); break;
        case 2: _t->on_CleanReciveButton_clicked(); break;
        case 3: _t->on_CleanSendButton_clicked(); break;
        case 4: _t->on_checkBox_ReciveHex_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_SendHex_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_emptyCount_clicked(); break;
        case 7: _t->ReadSerialData(); break;
        case 8: _t->TimerTimeOut(); break;
        case 9: _t->on_pushButton_openFile_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject WidgetSerial::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetSerial.data,
      qt_meta_data_WidgetSerial,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetSerial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetSerial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetSerial.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetSerial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
