#include"ZFraction.h"
#include <iostream>

using namespace std;

int main()
{
    ZFraction a(4,3);
    ZFraction b(1,5);
    ZFraction c,d,e,f;

    c = a+b;

    d = a*b;

    e = a-b;

    f = a/b;

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << a << " - " << b << " = " << e << endl;

    cout << a << " / " << b << " = " << f << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    cout << "On transforme a en nombre réel : " << a.transformerEnNombreReel() << endl;

    cout << "Inverse de a : " << -a << endl;

    cout << "Inverse de b : " << -b << endl;

    cout << "Calcul la racine carrée de a : " << a.calculerRacineCarree(a) << endl;

    cout << "Valeur absolue de a : " << a.calculerValeurAbsolue() << endl;

    cout << "Calcul de a puissance 3 : " << a.calculerPuissance(3) << endl;

    return 0;
}
