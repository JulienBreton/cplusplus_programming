#include <iostream>

#ifndef ZFRACTION_H
#define ZFRACTION_H

using namespace std;

class ZFraction
{
    public:
        ZFraction();
        ZFraction(int numerateur);
        ZFraction(int numerateur, int denominateur);
        virtual ~ZFraction();

        ZFraction& operator+=(ZFraction a);
        ZFraction& operator*=(ZFraction a);
        bool estEgal(ZFraction const& a) const;
        bool estPlusPetit(ZFraction const& a) const;
        void afficherFraction(ostream &flux) const;
        ZFraction& simplifierFraction();

    protected:

    private:

        int m_numerateur;
        int m_denominateur;
        int m_diviseurCommun;
};

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
ostream& operator<<(ostream &flux, ZFraction const& a);
int pgcd(int a, int b);

#endif // ZFRACTION_H
