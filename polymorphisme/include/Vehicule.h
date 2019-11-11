#include <iostream>

using namespace std;

#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule
{
    public:
    Vehicule(int prix, int anneeFabrication);
    virtual ~Vehicule();
    virtual void affiche() const;  //Affiche une description du Vehicule
    virtual unsigned int nombreRoues() const = 0;

    protected:
    int m_prix;  //Chaque véhicule a un prix
    int m_anneeFabrication;
};

#endif // VEHICULE_H
