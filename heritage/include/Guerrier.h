#ifndef GUERRIER_H
#define GUERRIER_H

#include <iostream>
#include <string>
#include "Personnage.h"

class Guerrier : public Personnage
{
    public:
        Guerrier(string nom);
        virtual ~Guerrier();
        void frapperCommeUnSourdAvecUnMarteau(Personnage &cible) const;
        void sePresenter() const;

    protected:

    private:
};

#endif // GUERRIER_H
