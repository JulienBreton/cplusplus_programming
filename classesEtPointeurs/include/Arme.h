#include <string>
#include <iostream>

#ifndef ARME_H
#define ARME_H

using namespace std;

class Arme
{
    public:
        Arme();
        Arme(string nomArme, int degats);
        virtual ~Arme();
        string getNomArme() const;
        int getDegats() const;
        void setDegats(int degats);

    protected:

    private:
        string m_nomArme;
        int m_degats;
};

#endif // ARME_H
