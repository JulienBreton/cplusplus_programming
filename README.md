## C++

#### Le mot clé const

```c++
int getVitesse() const;

int getVitesse() const
{
  return m_vitesse;
}

```
Ici le mot clé const dit au compilateur que la donnée membre ne peut pas être modifiée.

```c++
bool estPlusRapideQue(Voiture const& maVoiture);
```
Ici le mot clé const dit au compilateur que l'objet passé en paramètre ne peut pas être modifié.

#### Retour par référence

```c++
Voiture& demarrer();

Voiture& demarrer()
{
  m_demarree = true;
  return *this;
}
```
#### Le mot clé virtual

* Une méthode virtuelle peut être redéfinie dans une classe fille. Cela permet d'appeler la méthode de la classe fille et non pas celle de la classe mére.
* Une méthode virtuelle pure doit être redéfinie dans une classe fille. Dans le cas où ça n'a pas de sens d'implémenter la méthode dans la classe mère on la déclare comme virtuelle pure (=0).

#### Le mot clé static

* Une métode statique peut être appelée directement sans créer d'objet.
* Une variable statique est partagée par toutes les instances d'une même classe.

### Le mot clé friend

Une fonction amie d'une classe peut accéder à tous ses éléments, même les éléments privés.

```c++
class MaClasse
{
    public:
        MaClasse();
        virtual ~MaClasse();

    protected:

    private:
        void afficher();

        friend void fonctionAmie(MaClasse & test);
};

Dans le MaClasse.cpp :
void MaClasse::afficher()
{
    cout << "Appellé par la fonction amie." << endl;
}

void fonctionAmie(MaClasse & test)
{
    test.afficher();
}

Dans le main.cpp :
MaClasse * test1 = new MaClasse();
fonctionAmie(*test1);
```
## Qt

#### Pour faire fonctionner Qt :

```console
sudo apt-get install build-essential libgl1-mesa-dev
```
#### Pour avoir la transparence sur les fenêtres de LXDE :

Voir http://debian-facile.org/doc:environnements:lxde:transparence pour l'installation de Compton.

```console
compton &
```
#### Activation du mécanisme slots/signals personnalisé :

Ajout de la macro Q_OBJECT dans la classe => The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system.

#### Pour avoir les outils pour la traduction (lupdate):

```
sudo apt-get install qttools5-dev-tools
sudo apt-get install qt5-qmake
```
