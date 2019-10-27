#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

string demanderMotAMelanger()
{
    string motSaisi = "";

    cout << "Saisissez un mot" << endl;
    cin >> motSaisi;

    for(int i = 0; i <= 500 ; i++)
    {
        cout << endl;
    }

    return motSaisi;
}

string creerMotMystere(string motAMelanger)
{
    string motMystere = "";
    int position = 0;

    while(motAMelanger.size() != 0)
    {
        position = rand() % motAMelanger.size(); //Génére un nombre entre 0 et la longueur du mot à mélanger - 1.
        motMystere += motAMelanger[position];
        motAMelanger.erase(position, 1);
    }

    //cout << "Le mot mystère : " << motMystere << endl;

    return motMystere;
}

int demanderMotMystere(string motAMelanger, string motMystere, int essais)
{
    int score = 50;
    string motAComparer = "";

    cout << "Vous avez " << essais << " essais." << endl;

    do
    {
        cout << "Quel est ce mot ? " << motMystere << endl;
        cin >>  motAComparer;

        //transform(motAMelanger.begin(), motAMelanger.end(), motAMelanger.begin(), ::tolower);
        //transform(motAComparer.begin(), motAComparer.end(), motAComparer.begin(), ::toupper);

        if(motAMelanger == motAComparer)
        {
            cout << "Bravo !" << endl;
        }
        else
        {
            essais -= 1;
            score -= 10;
            cout << "Ce n'est pas le mot !" << endl;

            if(essais > 0)
            {
                cout << "Il vous reste " << essais << " essai(s)."<< endl;
            }
            else
            {
                cout << "La solution est : " << motAMelanger << endl;
            }
        }

    }
    while(motAMelanger != motAComparer && essais >= 1);

    return score;
}

double calculerScore(vector<int> const& score)
{
    double moyenneScore = 0.0;
    int sommeScores = 0;

    for(unsigned int i=0; i<=score.size()-1; i++)
    {
        //cout << "Somme scores : " << score[i] << endl;

        sommeScores += score[i];
    }

    //cout << "Somme scores : " << sommeScores;

    moyenneScore = sommeScores/score.size();

    return moyenneScore;
}

int obtenirNombreLignes(string const fichierTxt)
{
    ifstream dictionnaire(fichierTxt.c_str());

    string ligne = "";
    int nbrLignes = 0;

    if(dictionnaire)
    {
        while(getline(dictionnaire, ligne) && !dictionnaire.eof())
        {
            nbrLignes++;
        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    return nbrLignes;
}

string selectionnerMotDico()
{
    string const fichierDico("dico.txt");
    string motAuHasard = "";
    int nbrLignes = 0;

    nbrLignes = obtenirNombreLignes(fichierDico);

    ifstream dico(fichierDico.c_str());

    if(dico)
    {
        string ligne = "";
        int positionTiree = 0;
        int positionMot = 1;

        //cout << "Nombre de lignes du fichier : " << nbrLignes << endl;

        positionTiree = rand() % nbrLignes; // On tire un nombre entre 0 et le nombre de lignes - 1
        positionTiree += 1;

        //cout << "Position tirée au hasard : " << positionTiree <<endl;

        while(positionMot <= nbrLignes)
        {
            //cout << "On parcours le fichier => ligne : " << positionMot << endl;

            if(positionMot == positionTiree)
            {
                getline(dico, motAuHasard);
                //cout << "On a notre mot : " << motAuHasard << endl;
                positionMot = nbrLignes+1;
            }
            else
            {
                getline(dico, motAuHasard);
            }

            positionMot++;
        }

        dico.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    if(motAuHasard[motAuHasard.size()-1] == '\r')
    {
        //cout << "On retire le retour chariot" << endl;
        motAuHasard.erase(motAuHasard.size()-1, 1);
    }

    return motAuHasard;
}

int main()
{
    srand(time(0));

    string motAMelanger = "";
    string motMystere = "";
    string continuer = "";
    int nombreEssais = 5;
    vector<int> scoresPartiesJouees;
    double moyenneScoreParties = 0;
    int scorePartieEnCours = 0;
    int nombreDeParties = 0;
    string choixMode = "";

    do
    {

        nombreDeParties++;

        //1 : On demande de saisir un mot ou de sélectionner un mot au hasard dans un dico
        while(choixMode != "1" && choixMode != "2")
        {
            cout << "1 - Saisir un mot" << endl;
            cout << "2 - Prendre un mot au hasard dans un dico" << endl;
            cout << "Entrez 1 ou 2 pour sélectionner le mode : ";
            cin >> choixMode;
            cout << "mode : " << choixMode << endl;
        }

        if(choixMode == "1")
        {
            motAMelanger = demanderMotAMelanger();
        }
        else if (choixMode == "2")
        {
            motAMelanger = selectionnerMotDico();
        }

        //2 : On mélange les lettres du mot
        motMystere = creerMotMystere(motAMelanger);

        //3 : On demande à l'utilisateur quel est le mot mystère
        scorePartieEnCours = demanderMotMystere(motAMelanger, motMystere, nombreEssais);
        cout << "Score de la partie : " << scorePartieEnCours << endl;
        scoresPartiesJouees.push_back(scorePartieEnCours);

        do
        {
            choixMode = "";
            cout << "Voulez-vous faire une autre partie? (o/N) : " << endl;
            cin >> continuer;
        }
        while(continuer != "o" && continuer != "N");

    }while(continuer == "o");

    moyenneScoreParties = calculerScore(scoresPartiesJouees);
    cout << "Votre score moyen après " << nombreDeParties << " partie(s) : " << moyenneScoreParties << endl;

    return 0;
}
