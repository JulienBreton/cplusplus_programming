#include <iostream>
#include "Guerrier.h"
#include "Magicien.h"

using namespace std;

int main()
{
    cout << "Création du personnage" << endl;
    Personnage *monPersonnage = new Personnage("Paul le personnage");
    cout << "Création du guerrier" << endl;
    Guerrier *monGuerrier = new Guerrier("Roger le guerrier");
    cout << "Création du magicien" << endl;
    Magicien *monMagicien = new Magicien("Robert le magicien");
    cout << endl << endl << endl;
    monPersonnage->sePresenter();
    cout << endl;
    monGuerrier->sePresenter(); //Utilisation du masquage sur la fonction sePresenter.
    cout << endl;
    monMagicien->sePresenter();

    delete monPersonnage, monGuerrier, monMagicien;

    return 0;
}
