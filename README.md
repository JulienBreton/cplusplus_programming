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
