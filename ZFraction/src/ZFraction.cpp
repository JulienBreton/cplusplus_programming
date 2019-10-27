#include "ZFraction.h"
#include <iostream>

using namespace std;

ZFraction::ZFraction(int numerateur, int denominateur)
{
    if(denominateur == 0)
    {
        cout << "Division par 0 impossible! On considére que le dénominateur vaut 1." << endl;
        denominateur=1;
    }

    m_numerateur = numerateur;
    m_denominateur = denominateur;

    simplifierFraction();

}

ZFraction::ZFraction(int numerateur)
{
    m_numerateur = numerateur;
    m_denominateur = 1;
}

ZFraction::ZFraction()
{
    m_numerateur = 0;
    m_denominateur = 0;
    m_diviseurCommun = 0;
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
    a.afficherFraction(flux) ;
    return flux;
}

ZFraction& ZFraction::operator+=(ZFraction a)
{
    //On passe les fractions sous un même denominateur.

    //On sauvegarde les dénominateurs qui vont servir à effectuer le calcul.
    int denominateur1 = m_denominateur;
    int denominateur2 = a.m_denominateur;

    //On multiplie le numérateur et le dénominateur de la fraction par le dénominateur de l'autre fraction.
    m_numerateur *= denominateur2;
    m_denominateur *= denominateur2;

    a.m_numerateur *= denominateur1;
    a.m_denominateur *= denominateur1;

    if(m_denominateur == a.m_denominateur)
    {
        m_numerateur += a.m_numerateur;
    }
    else
    {
        cout << "Erreur lors de l'addition.";
    }

    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction a)
{
    m_numerateur *= a.m_numerateur;
    m_denominateur *= a.m_denominateur;

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
    if(float(m_numerateur)/m_denominateur < float(a.m_numerateur)/a.m_denominateur)
    {
        return true;
    }

    return false;
}

ZFraction& ZFraction::simplifierFraction()
{
    m_diviseurCommun = pgcd(m_numerateur, m_denominateur);

    m_numerateur /= m_diviseurCommun;
    m_denominateur /= m_diviseurCommun;

    return *this;
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie += b;

    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie *= b;

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
