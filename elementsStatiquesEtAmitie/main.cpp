#include <iostream>
#include "MaClasse.h"

using namespace std;

int main()
{
    MaClasse * test1 = new MaClasse();
    MaClasse * test2 = new MaClasse();

    fonctionAmie(*test1);

    cout << "Il y a " << MaClasse::nombreInstances() << " instances en cours." << endl;

    delete test1;

    cout << "Il y a " << MaClasse::nombreInstances() << " instances en cours." << endl;

    delete test2;

    cout << "Il y a " << MaClasse::nombreInstances() << " instances en cours." << endl;

    return 0;
}
