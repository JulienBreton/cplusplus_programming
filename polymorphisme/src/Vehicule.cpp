#include "Vehicule.h"

Vehicule::Vehicule(int prix, int anneeFabrication) : m_prix(prix), m_anneeFabrication(anneeFabrication)
{
    //ctor
}

Vehicule::~Vehicule()
{
    //dtor
}

void Vehicule::affiche() const
{
    cout << "Ceci est un vehicule datant de " << m_anneeFabrication << "et coutant " << m_prix << " euros." << endl;
}
