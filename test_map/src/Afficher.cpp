#include "Afficher.h"

Afficher::Afficher()
{
    //ctor
}

Afficher::~Afficher()
{
    //dtor
}

void Afficher::operator()(int a) const
{
    cout << a << endl;
}
