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
