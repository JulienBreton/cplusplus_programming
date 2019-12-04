#include "MaClasse.h"

int MaClasse::compteur = 0;

MaClasse::MaClasse()
{
    ++compteur;
}

MaClasse::~MaClasse()
{
    --compteur;
}

int MaClasse::nombreInstances() //Ne pas remettre 'static' dans l'implémentation
{
    return compteur;
}

void MaClasse::afficher()
{
    cout << "Appellé par la fonction amie." << endl;
}

void fonctionAmie(MaClasse & test)
{
    test.afficher();
}
