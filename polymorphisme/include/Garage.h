#include <vector>
#include <iostream>
#include "Vehicule.h"

#ifndef GARAGE_H
#define GARAGE_H

class Garage
{
    public:
        Garage();
        virtual ~Garage();
        void ajouterVehicule(Vehicule * vehiculeAAjouter);
        void supprimerVehicule(unsigned int positionVehicule);
        void afficherNbrVehicules() const;
        void afficherContenuGarage() const;
        void afficherCaracteristiquesVehicule(unsigned int positionVehicule) const;
        Vehicule* getVehicule(unsigned int positionVehicule) const;
        unsigned int getNbrVehicules() const;

    protected:

    private:
        vector<Vehicule*> m_stock;
};

#endif // GARAGE_H
