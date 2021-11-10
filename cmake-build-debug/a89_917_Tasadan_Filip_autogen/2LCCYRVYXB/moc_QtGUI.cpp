/****************************************************************************
** Meta object code from reading C++ file 'QtGUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/QtGUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUI_t {
    const uint offsetsAndSize[94];
    char stringdata0[773];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 3), // "GUI"
QT_MOC_LITERAL(4, 15), // "adminModeSignal"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 14), // "userModeSignal"
QT_MOC_LITERAL(36, 15), // "dataChartSignal"
QT_MOC_LITERAL(52, 16), // "listUpdateSignal"
QT_MOC_LITERAL(69, 16), // "backToMenuSignal"
QT_MOC_LITERAL(86, 15), // "addNewDogSignal"
QT_MOC_LITERAL(102, 11), // "std::string"
QT_MOC_LITERAL(114, 5), // "breed"
QT_MOC_LITERAL(120, 4), // "name"
QT_MOC_LITERAL(125, 3), // "age"
QT_MOC_LITERAL(129, 5), // "photo"
QT_MOC_LITERAL(135, 15), // "deleteDogSignal"
QT_MOC_LITERAL(151, 15), // "updateDogSignal"
QT_MOC_LITERAL(167, 13), // "::std::string"
QT_MOC_LITERAL(181, 21), // "operationStatusSignal"
QT_MOC_LITERAL(203, 13), // "status_string"
QT_MOC_LITERAL(217, 15), // "adminUndoSignal"
QT_MOC_LITERAL(233, 15), // "adminRedoSignal"
QT_MOC_LITERAL(249, 20), // "userBackToMenuSignal"
QT_MOC_LITERAL(270, 20), // "backToUserMenuSignal"
QT_MOC_LITERAL(291, 16), // "filterMenuSignal"
QT_MOC_LITERAL(308, 21), // "seeAdoptionListSignal"
QT_MOC_LITERAL(330, 26), // "seeTableAdoptionListSignal"
QT_MOC_LITERAL(357, 23), // "iterateDogsWindowSignal"
QT_MOC_LITERAL(381, 22), // "currentDogUpdateSignal"
QT_MOC_LITERAL(404, 25), // "displayAdoptionListSignal"
QT_MOC_LITERAL(430, 28), // "seeAdoptionDisplayListSignal"
QT_MOC_LITERAL(459, 7), // "initGUI"
QT_MOC_LITERAL(467, 13), // "initAdminMode"
QT_MOC_LITERAL(481, 12), // "initUserMode"
QT_MOC_LITERAL(494, 13), // "dataChartSlot"
QT_MOC_LITERAL(508, 14), // "displayDogList"
QT_MOC_LITERAL(523, 25), // "updateOperationStatusSlot"
QT_MOC_LITERAL(549, 13), // "addNewDogSlot"
QT_MOC_LITERAL(563, 13), // "deleteDogSlot"
QT_MOC_LITERAL(577, 13), // "updateDogSlot"
QT_MOC_LITERAL(591, 13), // "adminUndoSlot"
QT_MOC_LITERAL(605, 13), // "adminRedoSlot"
QT_MOC_LITERAL(619, 21), // "iterateDogsWindowSlot"
QT_MOC_LITERAL(641, 14), // "filterMenuSlot"
QT_MOC_LITERAL(656, 19), // "seeAdoptionListSlot"
QT_MOC_LITERAL(676, 24), // "seeTableAdoptionListSlot"
QT_MOC_LITERAL(701, 20), // "currentDogUpdateSlot"
QT_MOC_LITERAL(722, 23), // "displayAdoptionListSlot"
QT_MOC_LITERAL(746, 26) // "seeAdoptionDisplayListSlot"

    },
    "GUI\0adminModeSignal\0\0userModeSignal\0"
    "dataChartSignal\0listUpdateSignal\0"
    "backToMenuSignal\0addNewDogSignal\0"
    "std::string\0breed\0name\0age\0photo\0"
    "deleteDogSignal\0updateDogSignal\0"
    "::std::string\0operationStatusSignal\0"
    "status_string\0adminUndoSignal\0"
    "adminRedoSignal\0userBackToMenuSignal\0"
    "backToUserMenuSignal\0filterMenuSignal\0"
    "seeAdoptionListSignal\0seeTableAdoptionListSignal\0"
    "iterateDogsWindowSignal\0currentDogUpdateSignal\0"
    "displayAdoptionListSignal\0"
    "seeAdoptionDisplayListSignal\0initGUI\0"
    "initAdminMode\0initUserMode\0dataChartSlot\0"
    "displayDogList\0updateOperationStatusSlot\0"
    "addNewDogSlot\0deleteDogSlot\0updateDogSlot\0"
    "adminUndoSlot\0adminRedoSlot\0"
    "iterateDogsWindowSlot\0filterMenuSlot\0"
    "seeAdoptionListSlot\0seeTableAdoptionListSlot\0"
    "currentDogUpdateSlot\0displayAdoptionListSlot\0"
    "seeAdoptionDisplayListSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  242,    2, 0x06,    0 /* Public */,
       3,    0,  243,    2, 0x06,    1 /* Public */,
       4,    0,  244,    2, 0x06,    2 /* Public */,
       5,    0,  245,    2, 0x06,    3 /* Public */,
       6,    0,  246,    2, 0x06,    4 /* Public */,
       7,    4,  247,    2, 0x06,    5 /* Public */,
      13,    1,  256,    2, 0x06,   10 /* Public */,
      14,    3,  259,    2, 0x06,   12 /* Public */,
      16,    1,  266,    2, 0x06,   16 /* Public */,
      18,    0,  269,    2, 0x06,   18 /* Public */,
      19,    0,  270,    2, 0x06,   19 /* Public */,
      20,    0,  271,    2, 0x06,   20 /* Public */,
      21,    0,  272,    2, 0x06,   21 /* Public */,
      22,    0,  273,    2, 0x06,   22 /* Public */,
      23,    0,  274,    2, 0x06,   23 /* Public */,
      24,    0,  275,    2, 0x06,   24 /* Public */,
      25,    0,  276,    2, 0x06,   25 /* Public */,
      26,    0,  277,    2, 0x06,   26 /* Public */,
      27,    0,  278,    2, 0x06,   27 /* Public */,
      28,    0,  279,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      29,    0,  280,    2, 0x0a,   29 /* Public */,
      30,    0,  281,    2, 0x0a,   30 /* Public */,
      31,    0,  282,    2, 0x0a,   31 /* Public */,
      32,    0,  283,    2, 0x0a,   32 /* Public */,
      33,    0,  284,    2, 0x0a,   33 /* Public */,
      34,    1,  285,    2, 0x0a,   34 /* Public */,
      35,    4,  288,    2, 0x0a,   36 /* Public */,
      36,    1,  297,    2, 0x0a,   41 /* Public */,
      37,    3,  300,    2, 0x0a,   43 /* Public */,
      38,    0,  307,    2, 0x0a,   47 /* Public */,
      39,    0,  308,    2, 0x0a,   48 /* Public */,
      40,    0,  309,    2, 0x0a,   49 /* Public */,
      41,    0,  310,    2, 0x0a,   50 /* Public */,
      42,    0,  311,    2, 0x0a,   51 /* Public */,
      43,    0,  312,    2, 0x0a,   52 /* Public */,
      44,    0,  313,    2, 0x0a,   53 /* Public */,
      45,    0,  314,    2, 0x0a,   54 /* Public */,
      46,    0,  315,    2, 0x0a,   55 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, QMetaType::Int, 0x80000000 | 8,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 8,   10,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, 0x80000000 | 15,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 8,   17,
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

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   17,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, QMetaType::Int, 0x80000000 | 8,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 8,   10,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, 0x80000000 | 15,   10,   11,   12,
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

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->adminModeSignal(); break;
        case 1: _t->userModeSignal(); break;
        case 2: _t->dataChartSignal(); break;
        case 3: _t->listUpdateSignal(); break;
        case 4: _t->backToMenuSignal(); break;
        case 5: _t->addNewDogSignal((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4]))); break;
        case 6: _t->deleteDogSignal((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 7: _t->updateDogSignal((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const ::std::string(*)>(_a[3]))); break;
        case 8: _t->operationStatusSignal((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 9: _t->adminUndoSignal(); break;
        case 10: _t->adminRedoSignal(); break;
        case 11: _t->userBackToMenuSignal(); break;
        case 12: _t->backToUserMenuSignal(); break;
        case 13: _t->filterMenuSignal(); break;
        case 14: _t->seeAdoptionListSignal(); break;
        case 15: _t->seeTableAdoptionListSignal(); break;
        case 16: _t->iterateDogsWindowSignal(); break;
        case 17: _t->currentDogUpdateSignal(); break;
        case 18: _t->displayAdoptionListSignal(); break;
        case 19: _t->seeAdoptionDisplayListSignal(); break;
        case 20: _t->initGUI(); break;
        case 21: _t->initAdminMode(); break;
        case 22: _t->initUserMode(); break;
        case 23: _t->dataChartSlot(); break;
        case 24: _t->displayDogList(); break;
        case 25: _t->updateOperationStatusSlot((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 26: _t->addNewDogSlot((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4]))); break;
        case 27: _t->deleteDogSlot((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 28: _t->updateDogSlot((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const ::std::string(*)>(_a[3]))); break;
        case 29: _t->adminUndoSlot(); break;
        case 30: _t->adminRedoSlot(); break;
        case 31: _t->iterateDogsWindowSlot(); break;
        case 32: _t->filterMenuSlot(); break;
        case 33: _t->seeAdoptionListSlot(); break;
        case 34: _t->seeTableAdoptionListSlot(); break;
        case 35: _t->currentDogUpdateSlot(); break;
        case 36: _t->displayAdoptionListSlot(); break;
        case 37: _t->seeAdoptionDisplayListSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::adminModeSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::userModeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::dataChartSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::listUpdateSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::backToMenuSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GUI::*)(const std::string & , const std::string & , int , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::addNewDogSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GUI::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::deleteDogSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GUI::*)(const std::string & , int , const ::std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::updateDogSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GUI::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::operationStatusSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::adminUndoSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::adminRedoSignal)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::userBackToMenuSignal)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::backToUserMenuSignal)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::filterMenuSignal)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::seeAdoptionListSignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::seeTableAdoptionListSignal)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::iterateDogsWindowSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::currentDogUpdateSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::displayAdoptionListSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (GUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::seeAdoptionDisplayListSignal)) {
                *result = 19;
                return;
            }
        }
    }
}

const QMetaObject GUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUI.offsetsAndSize,
    qt_meta_data_GUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GUI_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const ::std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const ::std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void GUI::adminModeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GUI::userModeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GUI::dataChartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GUI::listUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GUI::backToMenuSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GUI::addNewDogSignal(const std::string & _t1, const std::string & _t2, int _t3, const std::string & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GUI::deleteDogSignal(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GUI::updateDogSignal(const std::string & _t1, int _t2, const ::std::string & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GUI::operationStatusSignal(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GUI::adminUndoSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void GUI::adminRedoSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GUI::userBackToMenuSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void GUI::backToUserMenuSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void GUI::filterMenuSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void GUI::seeAdoptionListSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void GUI::seeTableAdoptionListSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void GUI::iterateDogsWindowSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void GUI::currentDogUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void GUI::displayAdoptionListSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void GUI::seeAdoptionDisplayListSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
