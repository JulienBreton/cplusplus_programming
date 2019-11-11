#include <iostream>
#include <vector>
#include "Vehicule.h"
#include "Moto.h"
#include "Voiture.h"
#include "Camion.h"
#include "Garage.h"

using namespace std;

int main()
{
    Garage * monGarage = new Garage();

    //Collection hétérogène
    monGarage->ajouterVehicule(new Voiture(15000, 2005, 5));
    monGarage->ajouterVehicule(new Voiture(12000, 2003, 3));
    monGarage->ajouterVehicule(new Moto(2000, 2007, 212.5));
    monGarage->ajouterVehicule(new Camion(20000, 2001, 10));

    monGarage->afficherNbrVehicules();

    monGarage->supprimerVehicule(1);

    monGarage->afficherNbrVehicules();

    monGarage->supprimerVehicule(3);

    monGarage->afficherNbrVehicules();

    monGarage->afficherContenuGarage();

    monGarage->afficherCaracteristiquesVehicule(1);

    monGarage->ajouterVehicule(new Moto(1200, 2019, 375));
    monGarage->ajouterVehicule(new Camion(20000, 2001, 10));

    for(unsigned int i=1; i<=monGarage->getNbrVehicules(); i++)
    {
        cout << "Ce véhicule a " << monGarage->getVehicule(i)->nombreRoues() << " roues" << endl;
    }

    return 0;
}
