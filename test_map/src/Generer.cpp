#include "Generer.h"

Generer::Generer()
{
    //ctor
}

Generer::~Generer()
{
    //dtor
}

int Generer::operator()() const
{
    return rand() % 10;  //On renvoie un nombre entre 0 et 9
}
