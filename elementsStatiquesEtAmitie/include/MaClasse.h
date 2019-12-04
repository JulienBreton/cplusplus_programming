#include <iostream>

using namespace std;

#ifndef MACLASSE_H
#define MACLASSE_H

class MaClasse
{
    public:
        MaClasse();
        virtual ~MaClasse();
        static int nombreInstances();

    protected:

    private:
        static int compteur;
        void afficher();

        friend void fonctionAmie(MaClasse & test);
};



#endif // MACLASSE_H
