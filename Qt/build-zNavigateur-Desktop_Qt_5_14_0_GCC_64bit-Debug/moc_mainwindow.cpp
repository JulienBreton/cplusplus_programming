/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../zNavigateur/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "ouvrirTab"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "fermerTab"
QT_MOC_LITERAL(4, 32, 19), // "allerPagePrecedente"
QT_MOC_LITERAL(5, 52, 17), // "allerPageSuivante"
QT_MOC_LITERAL(6, 70, 13), // "rechargerPage"
QT_MOC_LITERAL(7, 84, 14), // "stopChargement"
QT_MOC_LITERAL(8, 99, 12), // "allerAccueil"
QT_MOC_LITERAL(9, 112, 8), // "allerURL"
QT_MOC_LITERAL(10, 121, 21), // "actualiserTitreOnglet"
QT_MOC_LITERAL(11, 143, 9), // "titrePage"
QT_MOC_LITERAL(12, 153, 22), // "afficherAProposzNavigo"
QT_MOC_LITERAL(13, 176, 17), // "afficherAProposQt"
QT_MOC_LITERAL(14, 194, 18), // "actualiserBarreURL"
QT_MOC_LITERAL(15, 213, 3), // "url"
QT_MOC_LITERAL(16, 217, 31) // "actualiserApresChangementOnglet"

    },
    "MainWindow\0ouvrirTab\0\0fermerTab\0"
    "allerPagePrecedente\0allerPageSuivante\0"
    "rechargerPage\0stopChargement\0allerAccueil\0"
    "allerURL\0actualiserTitreOnglet\0titrePage\0"
    "afficherAProposzNavigo\0afficherAProposQt\0"
    "actualiserBarreURL\0url\0"
    "actualiserApresChangementOnglet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      16,    1,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   15,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ouvrirTab(); break;
        case 1: _t->fermerTab(); break;
        case 2: _t->allerPagePrecedente(); break;
        case 3: _t->allerPageSuivante(); break;
        case 4: _t->rechargerPage(); break;
        case 5: _t->stopChargement(); break;
        case 6: _t->allerAccueil(); break;
        case 7: _t->allerURL(); break;
        case 8: _t->actualiserTitreOnglet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->afficherAProposzNavigo(); break;
        case 10: _t->afficherAProposQt(); break;
        case 11: _t->actualiserBarreURL((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 12: _t->actualiserApresChangementOnglet((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
