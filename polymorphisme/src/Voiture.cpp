#include "Voiture.h"

Voiture::Voiture(int prix, int anneeFabrication, int portes) : Vehicule(prix, anneeFabrication), m_portes(portes)
{
    //ctor
}

Voiture::~Voiture()
{
    //dtor
}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes, datant de " << m_anneeFabrication << " et coutant " << m_prix << " euros." << endl;
}

unsigned int Voiture::nombreRoues() const
{
    return 4;
}
