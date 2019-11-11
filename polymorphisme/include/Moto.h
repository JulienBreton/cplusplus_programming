#include "Vehicule.h"

#ifndef MOTO_H
#define MOTO_H

class Moto : public Vehicule  //Une Moto EST UN Vehicule
{
    public:
    Moto(int prix, int anneeFabrication, double vitesseMax);
    virtual ~Moto();
    virtual void affiche() const;
    virtual unsigned int nombreRoues() const;

    private:
    double m_vitesse;  //La vitesse maximale de la moto
};

#endif // MOTO_H
