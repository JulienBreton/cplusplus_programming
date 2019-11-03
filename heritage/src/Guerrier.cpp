#include "Guerrier.h"

Guerrier::Guerrier(string nom) : Personnage(nom)
{
    cout << "Constructeur de la classe Guerrier" << endl;
}

Guerrier::~Guerrier()
{
    //dtor
}

void Guerrier::frapperCommeUnSourdAvecUnMarteau(Personnage &cible) const
{
    cible.recevoirDegats(30);
}

void Guerrier::sePresenter() const
{
    Personnage::sePresenter();
    cout << "Je suis un Guerrier redoutable." << endl;
}
