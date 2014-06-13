/****************************************************************************
** Meta object code from reading C++ file 'mondossier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mondossier.h"
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
    QByteArrayData data[25];
    char stringdata[403];
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
QT_MOC_LITERAL(10, 120, 17),
QT_MOC_LITERAL(11, 138, 14),
QT_MOC_LITERAL(12, 153, 14),
QT_MOC_LITERAL(13, 168, 14),
QT_MOC_LITERAL(14, 183, 19),
QT_MOC_LITERAL(15, 203, 19),
QT_MOC_LITERAL(16, 223, 18),
QT_MOC_LITERAL(17, 242, 19),
QT_MOC_LITERAL(18, 262, 16),
QT_MOC_LITERAL(19, 279, 18),
QT_MOC_LITERAL(20, 298, 14),
QT_MOC_LITERAL(21, 313, 25),
QT_MOC_LITERAL(22, 339, 25),
QT_MOC_LITERAL(23, 365, 24),
QT_MOC_LITERAL(24, 390, 11)
    },
    "mondossier\0ajoutUV\0\0sauvegarder_choix\0"
    "ajoutPreference\0ajoutRejet\0ajoutExigence\0"
    "supprPreference\0supprRejet\0supprExigence\0"
    "sauvegarder_modif\0modifier_infos\0"
    "enable_branche\0enable_credits\0"
    "add_critere_branche\0add_critere_filiere\0"
    "add_critere_cursus\0sauvegarder_dossier\0"
    "suppr_UV_suivies\0generer_suggestion\0"
    "voirsuggestion\0add_choix_critere_branche\0"
    "add_choix_critere_filiere\0"
    "add_choix_critere_cursus\0maj_dossier\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mondossier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x08,
       3,    0,  130,    2, 0x08,
       4,    0,  131,    2, 0x08,
       5,    0,  132,    2, 0x08,
       6,    0,  133,    2, 0x08,
       7,    0,  134,    2, 0x08,
       8,    0,  135,    2, 0x08,
       9,    0,  136,    2, 0x08,
      10,    0,  137,    2, 0x08,
      11,    0,  138,    2, 0x08,
      12,    0,  139,    2, 0x08,
      13,    0,  140,    2, 0x08,
      14,    0,  141,    2, 0x08,
      15,    0,  142,    2, 0x08,
      16,    0,  143,    2, 0x08,
      17,    0,  144,    2, 0x08,
      18,    0,  145,    2, 0x08,
      19,    0,  146,    2, 0x08,
      20,    0,  147,    2, 0x08,
      21,    0,  148,    2, 0x08,
      22,    0,  149,    2, 0x08,
      23,    0,  150,    2, 0x08,
      24,    0,  151,    2, 0x0a,

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
        case 8: _t->sauvegarder_modif(); break;
        case 9: _t->modifier_infos(); break;
        case 10: _t->enable_branche(); break;
        case 11: _t->enable_credits(); break;
        case 12: _t->add_critere_branche(); break;
        case 13: _t->add_critere_filiere(); break;
        case 14: _t->add_critere_cursus(); break;
        case 15: _t->sauvegarder_dossier(); break;
        case 16: _t->suppr_UV_suivies(); break;
        case 17: _t->generer_suggestion(); break;
        case 18: _t->voirsuggestion(); break;
        case 19: _t->add_choix_critere_branche(); break;
        case 20: _t->add_choix_critere_filiere(); break;
        case 21: _t->add_choix_critere_cursus(); break;
        case 22: _t->maj_dossier(); break;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
