#ifndef MAGICIEN_H
#define MAGICIEN_H

#include <iostream>
#include <string>
#include "Personnage.h"

class Magicien : public Personnage
{
    public:
        Magicien(string nom);
        virtual ~Magicien();
        void bouleDeFeu() const;
        void bouleDeGlace() const;

    protected:

    private:
        int m_mana;
};

#endif // MAGICIEN_H
