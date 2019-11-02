#include <iostream>
#include "Personnage.h"

using namespace std;

int main()
{

    /*
    Lorsque l'on a un constructeur de copie il ne faut pas oublier des créer l'opérateur d'affectation.
    En effet il faut gérer les pointeurs aussi dans le cas de = car cet opérateur peut très bien être
    utilisé par quelqu'un qui utiliserait la classe.
    */

    Personnage *gimli = new Personnage("Gimli", "hache"); //constructeur avec arguments
    Personnage *orque1 = new Personnage; //consturcteur par défaut
    orque1->setPseudo("Orgue n°1");
    Personnage *orque2 = new Personnage("Orque n°2", "épée");  //constructeur avec arguments
    Personnage *orque3 = new Personnage(*orque2); //constructeur de copie
    orque3->setPseudo("Orgue n°3"); //Avant le pseudo de orque3 est le pseudo de orque2.
    Personnage *orque4 = new Personnage;
    *orque4 = *orque3; //Opérateur d'affectation qui s'utilise après la création.
    orque4->setPseudo("Orgue n°4"); //Avant le pseudo de orque4 est le pseudo de orque3.

    cout << "***" << endl;

    cout << gimli->getPseudo() << endl;
    cout << orque1->getPseudo() << endl;
    cout << orque2->getPseudo() << endl;
    cout << orque3->getPseudo() << endl;
    cout << orque4->getPseudo() << endl;

    delete orque1;
    delete orque2;
    delete orque3;
    delete orque4;
    delete gimli;

    cout << "***" << endl;

    Personnage perso1;
    Personnage perso2(perso1);
    Personnage perso3;
    perso3 = perso2;

    return 0;
}
