#include "Moto.h"

Moto::Moto(int prix, int anneeFabrication, double vitesseMax) : Vehicule(prix, anneeFabrication), m_vitesse(vitesseMax)
{
    //ctor
}

Moto::~Moto()
{
    //dtor
}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h, datant de " << m_anneeFabrication << " et coutant " << m_prix << " euros." << endl;
}

unsigned int Moto::nombreRoues() const
{
    return 2;
}
