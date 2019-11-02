#include "Personnage.h"

Personnage::Personnage() : m_arme(0), m_vivant(true), m_pseudo(""), m_vie(100), m_mana(100)
{
    cout << "Passage par le constructeur par defaut" << endl;

    //cout << "Création d'un personnage sans identité et sans arme." << endl;

    m_arme = new Arme();
}

Personnage::Personnage(string pseudo, string nomArme): m_arme(0), m_vivant(true), m_pseudo(pseudo), m_vie(100), m_mana(100)
{
    cout << "Passage par le constructeur avec arguments" << endl;

    m_arme = new Arme(nomArme, 30);

   /* cout << "Création du personnage " << m_pseudo
    << " avec " << m_vie << " de vie,"
    << " avec l'arme " << m_arme->getNomArme()
    << " de dégats " << m_arme->getDegats() << "." << endl;*/
}

Personnage::Personnage(Personnage const& PersonnageAcopier): m_arme(0), m_vivant(PersonnageAcopier.m_vivant), m_pseudo(PersonnageAcopier.m_pseudo), m_vie(PersonnageAcopier.m_vie), m_mana(PersonnageAcopier.m_mana)
{
    cout << "Passage par le constructeur de copie" << endl;

    m_arme = new Arme(*(PersonnageAcopier.m_arme));

    /*cout << "Création du personnage " << m_pseudo
    << " avec " << m_vie << " de vie,"
    << " avec l'arme " << m_arme->getNomArme()
    << " de dégats " << m_arme->getDegats() << "." << endl;

    cout << "Fin constructeur de copie" << endl;*/
}

Personnage::~Personnage()
{
    delete m_arme;
}

int Personnage::getVie() const
{
    return m_vie;
}

void Personnage::setVie(int vie)
{
    m_vie = vie;
}

void  Personnage::setVivant(bool vivant)
{
    m_vivant = vivant;
}

void Personnage::recevoirDegats(int degats)
{
    if(getVivant())
    {
        if(m_vie - degats <= 0)
        {
            m_vie = 0;
            setVivant(false);
        }
        else if(m_vie - degats > 0)
        {
            m_vie -= degats;
        }
    }
}

void Personnage::attaquer(Personnage& cible)
{
    cible.recevoirDegats(m_arme->getDegats());
}

Arme* Personnage::getArmeUtilisee() const
{
    return m_arme;
}

string  Personnage::getPseudo() const
{
    return m_pseudo;
}

void  Personnage::setPseudo(string pseudo)
{
    m_pseudo = pseudo;
}

bool Personnage::getVivant() const
{
    return m_vivant;
}

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
    cout << "On passe par operator=" << endl;

    if(this != &personnageACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_pseudo = personnageACopier.m_pseudo;
        m_vie = personnageACopier.m_vie; //On copie tous les champs
        m_mana = personnageACopier.m_mana;
        delete m_arme;
        m_arme = new Arme(*(personnageACopier.m_arme));
    }
    return *this; //On renvoie l'objet lui-même
}
