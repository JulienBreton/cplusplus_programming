#include "Duree.h"
#include <iostream>
using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
    while(secondes >= 60)
    {
        int restantSecondes = secondes - 60;

        minutes = minutes + 1;
        secondes = restantSecondes;
    }

    while(minutes >= 60)
    {
        int restantMinutes = minutes - 60;

        heures = heures + 1;
        minutes = restantMinutes;
    }

    //cout << "Nombre d'heures : " << heures << endl;
    //cout << "Nombre de minutes : " << minutes << endl;
    //cout << "Nombre de secondes : " << secondes << endl;

}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}

bool operator<(Duree const &a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}

bool operator>(Duree const &a, Duree const& b)
{
    if(a.estEgal(b))
    {
        return false;
    }

    return !(a.estPlusPetitQue(b));
}

bool operator<=(Duree const &a, Duree const& b)
{
    if(a.estEgal(b))
    {
        return true;
    }

    if(a.estPlusPetitQue(b))
    {
        return true;
    }

    return false;

}

bool operator>=(Duree const &a, Duree const& b)
{
    if(a.estEgal(b))
    {
        return true;
    }

    if(!a.estPlusPetitQue(b))
    {
        return true;
    }

    return false;

}

/*Duree& Duree::operator+=(Duree const& a)
{
    m_heures += a.m_heures;
    m_minutes += a.m_minutes;
    m_secondes += a.m_secondes;

    while(m_secondes >= 60)
    {
        int restantSecondes = m_secondes - 60;

        m_minutes = m_minutes + 1;
        m_secondes = restantSecondes;
    }

    while(m_minutes >= 60)
    {
        int restantMinutes = m_minutes - 60;

        m_heures = m_heures + 1;
        m_minutes = restantMinutes;
    }

    return *this;
}*/

Duree& Duree::operator+=(const Duree& a)
{
    //1 : ajout des secondes
    m_secondes += a.m_secondes;
    //cout << "Nombre de secondes : " << m_secondes << endl;
    //Si le nombre de secondes dépasse 60, on rajoute des minutes
    //Et on met un nombre de secondes inférieur à 60
    m_minutes += m_secondes / 60;
    //cout << "Nombre de minutes : " << m_minutes << endl;
    m_secondes %= 60;
    //cout << "Nombre de secondes : " << m_secondes << endl;

    //2 : ajout des minutes
    m_minutes += a.m_minutes;
    //cout << "Nombre de minutes : " << m_minutes << endl;
    //Si le nombre de minutes dépasse 60, on rajoute des heures
    //Et on met un nombre de minutes inférieur à 60
    m_heures += m_minutes / 60;
    //cout << "Nombre d'heures : " << m_heures << endl;
    m_minutes %= 60;
    //cout << "Nombre de minutes : " << m_minutes << endl;

    //3 : ajout des heures
    m_heures += a.m_heures;
    //cout << "Nombre d'heures : " << m_heures << endl;

    return *this;
}

void Duree::afficherHeure() const
{
    cout << "Nombre d'heures : " << m_heures << endl;
    cout << "Nombre de minutes : " << m_minutes << endl;
    cout << "Nombre de secondes : " << m_secondes << endl;
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);   //On utilise le constructeur de copie de la classe Duree !
    copie += b;       //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;     //Et on renvoie le résultat. Ni a ni b n'ont changé.
}

Duree& Duree::operator+=(int secondes)
{
    m_secondes += secondes;
    m_minutes += m_secondes/60;
    m_secondes %= 60;

    m_heures += m_minutes/60;
    m_minutes %= 60;

    return *this;
}

Duree operator+(Duree const& a, int const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}

Duree& Duree::operator-=(const Duree& a)
{
    m_secondes -= a.m_secondes;
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    if(m_secondes < 0)
    {
        m_minutes -= 1;
        m_secondes += 60;
    }

    m_minutes -= a.m_minutes;
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    if(m_minutes < 0)
    {
        m_heures -= 1;
        m_minutes += 60;
    }

    m_heures -= a.m_heures;

    return *this;
}

Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie -= b;
    return copie;
}

Duree& Duree::operator-=(int secondes)
{
    m_secondes -= secondes;
    m_minutes += m_secondes/60;
    m_secondes %= 60;

    if(m_secondes < 0)
    {
        m_minutes -= 1;
        m_secondes += 60;
    }

    m_heures -= m_minutes/60;

    if(m_minutes < 0)
    {
        m_heures -= 1;
        m_minutes += 60;
    }

    m_minutes %= 60;

    return *this;
}

ostream& operator<<( ostream &flux, Duree const& duree )
{
    duree.afficher(flux) ;
    return flux;
}

void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}
