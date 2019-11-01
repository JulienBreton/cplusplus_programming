#include <iostream>
#include <cmath>

#ifndef ZFRACTION_H
#define ZFRACTION_H

using namespace std;

class ZFraction
{
    public:
        ZFraction(int numerateur=0, int denominateur=1);
        virtual ~ZFraction();

        ZFraction& operator+=(ZFraction const& a);
        ZFraction& operator-=(ZFraction const& a);
        ZFraction& operator*=(ZFraction const& a);
        ZFraction& operator/=(ZFraction const& a);
        bool estEgal(ZFraction const& a) const;
        bool estPlusPetit(ZFraction const& a) const;
        void afficherFraction(ostream &flux) const;
        ZFraction& simplifierFraction();
        int getNumerateur() const;
        int getDenominateur() const;
        double transformerEnNombreReel() const;
        void signer();
        double calculerRacineCarree(ZFraction const& a);
        ZFraction calculerValeurAbsolue();
        ZFraction calculerPuissance(int puissance);

    protected:

    private:

        int m_numerateur;
        int m_denominateur;
};

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a);
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
ostream& operator<<(ostream &flux, ZFraction const& a);
int pgcd(int a, int b);

#endif // ZFRACTION_H
