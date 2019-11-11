#include "Vehicule.h"

#ifndef VOITURE_H
#define VOITURE_H

class Voiture : public Vehicule //Une Voiture EST UN Vehicule
{
    public:
    Voiture(int prix, int anneeFabrication, int portes);
    virtual ~Voiture();
    virtual void affiche() const;
    virtual unsigned int nombreRoues() const;

    private:
    int m_portes;  //Le nombre de portes de la voiture
};

#endif // VOITURE_H
