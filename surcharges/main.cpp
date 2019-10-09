#include <iostream>
#include "Duree.h"

using namespace std;

int main()
{
    /*Duree duree1(1, 35, 30), duree2(1, 30, 45);

    if (duree1 == duree2)
    {
        cout << "Les durees sont identiques" << endl;
    }
    else if (duree1 != duree2)
    {
        cout << "Les durees sont differentes" << endl;
        if (duree1 < duree2)
        cout << "La premiere duree est plus petite" << endl;
        else if (duree1 > duree2)
        cout << "La premiere duree est plus grande" << endl;
    }

    if (duree1 <= duree2)
    {
        cout << "La durée 1 est inférieure ou égale à la durée 2." << endl;
    }

    if (duree1 >= duree2)
    {
        cout << "La durée 1 est supérieure ou égale à la durée 2." << endl;
    }

    duree1 += duree2;

    duree1.afficherHeure();*/

    /*Duree duree1(1, 1, 10), duree2(0, 40, 50), duree3(0, 0, 10), duree4(0, 0, 60);
    Duree resultat;
    int secondes = 3601;

    cout << "Addition de durées :" << endl;
    duree1.afficherHeure();
    cout << "+" << endl;
    duree2.afficherHeure();
    cout << "+" << endl;
    duree3.afficherHeure();

    resultat = duree1 + duree2 + duree3;

    cout << "=" << endl;
    resultat.afficherHeure();

    cout << "Heures + secondes(int) :" << endl;
    resultat = duree1 + secondes;
    duree1.afficherHeure();
    cout << "+" << endl;
    cout << secondes << endl;
    cout << "=" << endl;
    resultat.afficherHeure();

    cout << "Soustraction de durées :" << endl;
    resultat = duree1 - duree2;
    resultat.afficherHeure();
    duree1 -= 70;
    duree1.afficherHeure();*/

    Duree duree1(2, 25, 28), duree2(0, 16, 33);
    cout << duree1 << " et " << duree2 << endl;

    return 0;
}
