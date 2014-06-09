/****************************************************************************
** Meta object code from reading C++ file 'mondossier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mondossier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mondossier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mondossier_t {
    QByteArrayData data[16];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_mondossier_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_mondossier_t qt_meta_stringdata_mondossier = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 17),
QT_MOC_LITERAL(4, 38, 15),
QT_MOC_LITERAL(5, 54, 10),
QT_MOC_LITERAL(6, 65, 13),
QT_MOC_LITERAL(7, 79, 15),
QT_MOC_LITERAL(8, 95, 10),
QT_MOC_LITERAL(9, 106, 13),
QT_MOC_LITERAL(10, 120, 11),
QT_MOC_LITERAL(11, 132, 17),
QT_MOC_LITERAL(12, 150, 14),
QT_MOC_LITERAL(13, 165, 14),
QT_MOC_LITERAL(14, 180, 14),
QT_MOC_LITERAL(15, 195, 14)
    },
    "mondossier\0ajoutUV\0\0sauvegarder_choix\0"
    "ajoutPreference\0ajoutRejet\0ajoutExigence\0"
    "supprPreference\0supprRejet\0supprExigence\0"
    "maj_dossier\0sauvegarder_modif\0"
    "modifier_infos\0enable_branche\0"
    "enable_filiere\0enable_credits\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mondossier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a,
       3,    0,   85,    2, 0x0a,
       4,    0,   86,    2, 0x0a,
       5,    0,   87,    2, 0x0a,
       6,    0,   88,    2, 0x0a,
       7,    0,   89,    2, 0x0a,
       8,    0,   90,    2, 0x0a,
       9,    0,   91,    2, 0x0a,
      10,    0,   92,    2, 0x0a,
      11,    0,   93,    2, 0x0a,
      12,    0,   94,    2, 0x0a,
      13,    0,   95,    2, 0x0a,
      14,    0,   96,    2, 0x0a,
      15,    0,   97,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mondossier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mondossier *_t = static_cast<mondossier *>(_o);
        switch (_id) {
        case 0: _t->ajoutUV(); break;
        case 1: _t->sauvegarder_choix(); break;
        case 2: _t->ajoutPreference(); break;
        case 3: _t->ajoutRejet(); break;
        case 4: _t->ajoutExigence(); break;
        case 5: _t->supprPreference(); break;
        case 6: _t->supprRejet(); break;
        case 7: _t->supprExigence(); break;
        case 8: _t->maj_dossier(); break;
        case 9: _t->sauvegarder_modif(); break;
        case 10: _t->modifier_infos(); break;
        case 11: _t->enable_branche(); break;
        case 12: _t->enable_filiere(); break;
        case 13: _t->enable_credits(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject mondossier::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mondossier.data,
      qt_meta_data_mondossier,  qt_static_metacall, 0, 0}
};


const QMetaObject *mondossier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mondossier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mondossier.stringdata))
        return static_cast<void*>(const_cast< mondossier*>(this));
    return QDialog::qt_metacast(_clname);
}

int mondossier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
