#include "Camion.h"

Camion::Camion(int prix, int anneeFabricaton, int poids) : Vehicule(prix, anneeFabricaton), m_poids(poids)
{
    //ctor
}

Camion::~Camion()
{
    //dtor
}

void Camion::affiche() const
{
    cout << "Ceci est un camion pesant " << m_poids << " tonnes, datant de " << m_anneeFabrication << " et coutant " << m_prix << " euros." << endl;
}

unsigned int Camion::nombreRoues() const
{
    return 8;
}
