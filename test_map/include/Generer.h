#ifndef GENERER_H
#define GENERER_H

#include <random>

class Generer
{
    public:
        Generer();
        virtual ~Generer();
        int operator()() const;

    protected:

    private:
};

#endif // GENERER_H
