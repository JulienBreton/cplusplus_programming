#include <string>
#include <iostream>
#include "Arme.h"

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

using namespace std;

class Personnage
{
    public:
        Personnage();
        Personnage(string pseudo, string nomArme);
        Personnage(Personnage const& PersonnageAcopier);
        virtual ~Personnage();
        void attaquer(Personnage &cible);
        void recevoirDegats(int degats);
        void setVivant(bool vivant);
        bool getVivant() const;
        int getVie() const;
        void setVie(int vie);
        string getPseudo() const;
        void setPseudo(string pseudo);
        Arme* getArmeUtilisee() const;
        Personnage& operator=(Personnage const& personnageACopier);

    protected:

    private:
        Arme * m_arme;
        bool m_vivant;
        string m_pseudo;
        int m_vie;
        int m_mana;


};

#endif // PERSONNAGE_H
