#ifndef SOMMER_H
#define SOMMER_H

class Sommer
{
public:
    Sommer()
        :m_somme(0)
    {}

    void operator()(int n)
    {
        m_somme += n;
    }

    int resultat() const
    {
        return m_somme;
    }

private:
    int m_somme;

};

#endif // SOMMER_H
