#include <map>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fichier("texte.txt");
    string mot;
    map<string, int> occurrences;
    while(fichier >> mot)   //On lit le fichier mot par mot
    {
         ++occurrences[mot]; //On incrémente le compteur pour le mot lu
    }
    cout << "Le mot 'banane' existe " << occurrences["banane"] << " fois dans le fichier" << endl;
    cout << "Le mot 'bananes' existe " << occurrences["bananes"] << " fois dans le fichier" << endl;
    cout << "Le mot 'bananier' existe " << occurrences["bananier"] << " fois dans le fichier" << endl;
    cout << "Le mot 'Afrique' existe " << occurrences["Afrique"] << " fois dans le fichier" << endl;
    cout << "Le mot 'Inde' existe " << occurrences["Inde"] << " fois dans le fichier" << endl;
    cout << "Le mot 'vitamines' existe " << occurrences["vitamines"] << " fois dans le fichier" << endl;
    return 0;
}