#include "Arme.h"

Arme::Arme()
{

}

Arme::Arme(string nomArme, int degats): m_nomArme(nomArme), m_degats(degats)
{

}

Arme::~Arme()
{

}

string Arme::getNomArme() const
{
    return m_nomArme;
}

int Arme::getDegats() const
{
    return m_degats;
}
