#include <string>
#include <iostream>

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

using namespace std;

class Personnage
{
    public:
        Personnage(string nom);
        void recevoirDegats(int degats);
        void coupDePoing(Personnage &cible) const;
        void sePresenter() const;

    protected:
        int m_vie;
        std::string m_nom;

    private:

};

#endif // PERSONNAGE_H
