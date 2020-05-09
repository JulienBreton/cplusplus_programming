#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << "C++: cat constructor";
}

void Cat::call()
{
    qInfo() << "C++: call function";
    emit meow(); //Le signal est utilisé dans la partie QML pour par exemple modifier l'interface (afficher qlq chose...)
 }

QString Cat::name()
{
    qInfo() << "C++: get name";
    return m_name;
}

void Cat::setName(QString value)
{
    qInfo() << "C++: setName fuction with param " + value;
    m_name = value;
    emit nameChanged(); //Le signal est utilisé dans la partie QML pour par exemple modifier l'interface (afficher qlq chose...)
}

