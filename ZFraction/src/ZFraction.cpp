#include "ZFraction.h"
#include <iostream>

using namespace std;

ZFraction::ZFraction(int numerateur, int denominateur):m_numerateur(numerateur), m_denominateur(denominateur)
{
    simplifierFraction();

    signer();
}

ZFraction::~ZFraction()
{

}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

void ZFraction::afficherFraction(ostream &flux) const
{
    if(m_denominateur == 1)
    {
        flux << m_numerateur;
    }
    else
    {
        flux << m_numerateur << "/" << m_denominateur;
    }
}

ostream& operator<<(ostream &flux, ZFraction const& a)
{
    a.afficherFraction(flux);
    return flux;
}

ZFraction& ZFraction::operator+=(ZFraction const& a)
{
    m_numerateur = m_numerateur * a.m_denominateur + a.m_numerateur * m_denominateur;
    m_denominateur = m_denominateur * a.m_denominateur;

    simplifierFraction();

    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& a)
{
    m_numerateur = m_numerateur * a.m_denominateur - a.m_numerateur * m_denominateur;
    m_denominateur = m_denominateur * a.m_denominateur;

    simplifierFraction();

    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& a)
{
    m_numerateur *= a.m_numerateur;
    m_denominateur *= a.m_denominateur;

    simplifierFraction();

    return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& a)
{
    m_numerateur *= a.m_denominateur;
    m_denominateur *= a.m_numerateur;

    simplifierFraction();

    return *this;
}

bool ZFraction::estEgal(ZFraction const& a) const
{
    if(m_numerateur == a.m_numerateur && m_denominateur == a.m_denominateur)
    {
        return true;
    }

    return false;
}

bool ZFraction::estPlusPetit(ZFraction const& a) const
{
    if(m_numerateur * a.m_denominateur < m_denominateur * a.m_numerateur)
    {
        return true;
    }

    return false;
}

ZFraction& ZFraction::simplifierFraction()
{
    int diviseurCommun = pgcd(m_numerateur, m_denominateur);

    m_numerateur /= diviseurCommun;
    m_denominateur /= diviseurCommun;

    return *this;
}

int ZFraction::getNumerateur() const
{
    return m_numerateur;
}

int ZFraction::getDenominateur() const
{
    return m_denominateur;
}

double ZFraction::transformerEnNombreReel() const
{
    return double(m_numerateur) / m_denominateur;
}

void ZFraction::signer()
{
    if(m_numerateur >= 0 && m_denominateur < 0)
    {
        m_numerateur = -m_numerateur;
        m_denominateur = -m_denominateur;
    }

    else if(m_numerateur < 0 && m_denominateur < 0)
    {
        m_numerateur = -m_numerateur;
        m_denominateur = -m_denominateur;
    }
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie += b;

    copie.signer();

    return copie;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie -= b;

    copie.signer();

    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie *= b;

    copie.signer();

    return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie /= b;

    copie.signer();

    return copie;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    if(a.estEgal(b))
    {
        return true;
    }

    return false;
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
    if(a.estEgal(b))
    {
        return false;
    }

    return true;
}

bool operator<(ZFraction const& a, ZFraction const& b)
{

    if(a.estPlusPetit(b))
    {
        return true;
    }

    return false;
}

bool operator>(ZFraction const& a, ZFraction const& b)
{

    if(!a.estPlusPetit(b) && !a.estEgal(b))
    {
        return true;
    }

    return false;
}

bool operator<=(ZFraction const& a, ZFraction const& b) //Vrai si a<=b donc si b n'est pas plus petit que a
{
    if(b.estPlusPetit(a))
        return false;
    else
        return true;
}

bool operator>=(ZFraction const& a, ZFraction const& b) //Vrai si a>=b donc si a n'est pas plus petit que b
{
    if(a.estPlusPetit(b))
        return false;
    else
        return true;
}

ZFraction operator-(ZFraction const& a)
{
    ZFraction copie(a);
    copie *= -1;
    copie.signer();
    return copie;
}

double ZFraction::calculerRacineCarree(ZFraction const& a)
{
    double racineCarree = sqrt(a.m_numerateur) / sqrt(a.m_denominateur);

    return racineCarree;
}

ZFraction ZFraction::calculerValeurAbsolue()
{
    ZFraction copie(*this);

    copie.m_numerateur = abs(m_numerateur);
    copie.m_denominateur = abs(m_denominateur);

    copie.simplifierFraction();

    return copie;
}

ZFraction ZFraction::calculerPuissance(int puissance)
{
    ZFraction copie(*this);

    copie.m_numerateur = pow(m_numerateur, puissance);
    copie.m_denominateur = pow(m_denominateur, puissance);

    copie.simplifierFraction();

    return copie;
}
