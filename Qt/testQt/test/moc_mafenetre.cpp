/****************************************************************************
** Meta object code from reading C++ file 'mafenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mafenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mafenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaFenetre_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaFenetre_t qt_meta_stringdata_MaFenetre = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MaFenetre"
QT_MOC_LITERAL(1, 10, 17), // "agrandissementMax"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "changerLargeur"
QT_MOC_LITERAL(4, 44, 7), // "largeur"
QT_MOC_LITERAL(5, 52, 14), // "changerHauteur"
QT_MOC_LITERAL(6, 67, 16), // "augmenterOpacite"
QT_MOC_LITERAL(7, 84, 14), // "reduireOpacite"
QT_MOC_LITERAL(8, 99, 14), // "ouvrirDialogue"
QT_MOC_LITERAL(9, 114, 13), // "poserQuestion"
QT_MOC_LITERAL(10, 128, 14), // "demanderPseudo"
QT_MOC_LITERAL(11, 143, 14), // "changerCouleur"
QT_MOC_LITERAL(12, 158, 13), // "changerPolice"
QT_MOC_LITERAL(13, 172, 12), // "chargerImage"
QT_MOC_LITERAL(14, 185, 23) // "afficherComoEstaReponse"

    },
    "MaFenetre\0agrandissementMax\0\0"
    "changerLargeur\0largeur\0changerHauteur\0"
    "augmenterOpacite\0reduireOpacite\0"
    "ouvrirDialogue\0poserQuestion\0"
    "demanderPseudo\0changerCouleur\0"
    "changerPolice\0chargerImage\0"
    "afficherComoEstaReponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaFenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
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

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MaFenetre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->agrandissementMax(); break;
        case 1: _t->changerLargeur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changerHauteur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->augmenterOpacite(); break;
        case 4: _t->reduireOpacite(); break;
        case 5: _t->ouvrirDialogue(); break;
        case 6: _t->poserQuestion(); break;
        case 7: _t->demanderPseudo(); break;
        case 8: _t->changerCouleur(); break;
        case 9: _t->changerPolice(); break;
        case 10: _t->chargerImage(); break;
        case 11: _t->afficherComoEstaReponse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaFenetre::agrandissementMax)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MaFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MaFenetre.data,
    qt_meta_data_MaFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MaFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MaFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MaFenetre::agrandissementMax()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
