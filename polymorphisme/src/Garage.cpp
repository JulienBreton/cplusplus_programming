#include "Garage.h"

Garage::Garage()
{
    //ctor
}

Garage::~Garage()
{
    for(unsigned int i(0); i<m_stock.size(); ++i)
    {
        delete m_stock[i];  //On libère la i-ème case mémoire allouée
        m_stock[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    m_stock.clear();
}

void Garage::ajouterVehicule(Vehicule * vehiculeAAjouter)
{
    m_stock.push_back(vehiculeAAjouter);
}

void Garage::supprimerVehicule(unsigned int positionVehicule)
{
    cout << "On va supprimer le véhicule en position : " << positionVehicule << endl;

    --positionVehicule;

    m_stock[positionVehicule]->affiche();

    if(!m_stock.empty() && positionVehicule < m_stock.size())
    {
        delete m_stock[positionVehicule];
        m_stock[positionVehicule] = 0;
        m_stock.erase(m_stock.begin()+positionVehicule);

        cout << "Véhicule supprimé" << endl;
    }
    else
    {
        cout << "Suppression impossible" << endl;
    }
}

void Garage::afficherNbrVehicules() const
{
    cout << "Il y a " << m_stock.size() << " véhicules dans le garage." << endl;
}

void Garage::afficherContenuGarage() const
 {
    cout << "---Contenu du garage---" << endl;

    for(unsigned int i=0; i<m_stock.size(); i++)
    {
        m_stock[i]->affiche();
    }

    cout << "---Fin contenu du garage---" << endl;
 }

void Garage::afficherCaracteristiquesVehicule(unsigned int positionVehicule) const
{
    cout << "Détail du véhicule " << positionVehicule << " : ";

    if(!m_stock.empty() && positionVehicule < m_stock.size())
    {
        m_stock[positionVehicule-1]->affiche();
    }
}

Vehicule* Garage::getVehicule(unsigned int positionVehicule) const
{
    return m_stock[positionVehicule-1];
}

unsigned int Garage::getNbrVehicules() const
{
    return m_stock.size();
}
