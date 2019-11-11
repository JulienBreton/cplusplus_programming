#include "Vehicule.h"

#ifndef CAMION_H
#define CAMION_H

class Camion : public Vehicule
{
    public:
        Camion(int prix, int anneeFabricaton, int poids);
        virtual ~Camion();
        virtual void affiche() const;
        virtual unsigned int nombreRoues() const;

    protected:

    private:
        int m_poids;
};

#endif // CAMION_H
