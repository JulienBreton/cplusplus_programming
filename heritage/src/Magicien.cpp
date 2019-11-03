#include "Magicien.h"

Magicien::Magicien(string nom) : Personnage(nom), m_mana(100)
{
    cout << "Constructeur de la classe Magicien" << endl;
}

Magicien::~Magicien()
{
    //dtor
}

void Magicien::bouleDeFeu() const
{
}
