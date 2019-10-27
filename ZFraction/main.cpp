#include"ZFraction.h"
#include <iostream>

using namespace std;

int main()
{
    ZFraction a(1,2);
    ZFraction b(1,5);
    ZFraction c,d;

    c = a+b;

    d = a*b;

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    return 0;
}
