#ifndef AFFICHER_H
#define AFFICHER_H

#include <iostream>

using namespace std;

class Afficher
{
    public:
        Afficher();
        virtual ~Afficher();

        void operator()(int a) const;

    protected:

    private:
};

#endif // AFFICHER_H
