#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fichier("data.txt");
    istream_iterator<double> it(fichier); //Un itérateur sur le fichier
    istream_iterator<double> end;         //Le signal de fin
    ostream_iterator<double> itSortie(cout, ", ");

    while(it != end)   //Tant qu'on a pas atteint la fin
    {
        //cout << *it << endl;
        *itSortie = *it;  //On lit
        ++it;                 //Et on avance
    }

    ifstream fichier2("data.txt");
    cout << *min_element(istream_iterator<double>(fichier2), istream_iterator<double>())<< endl;

    return 0;
}
