#include <iostream>

#ifndef DUREE_H
#define DUREE_H
using namespace std;


class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    Duree& operator+=(Duree const& a);
    Duree& operator+=(int secondes);
    Duree& operator-=(Duree const& a);
    Duree& operator-=(int secondes);
    Duree operator/(Duree const& a);
    void afficherHeure() const;
    void afficher(std::ostream &flux) const;

    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
};

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const &a, Duree const& b);
bool operator>(Duree const &a, Duree const& b);
bool operator<=(Duree const &a, Duree const& b);
bool operator>=(Duree const &a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, Duree const& b);
ostream& operator<<(ostream &flux, Duree const& duree);

#endif // DUREE_H
