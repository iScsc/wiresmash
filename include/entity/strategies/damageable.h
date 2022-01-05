#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "strategy.h"


class Damageable : public virtual Strategy
{
private:
    float maxLife;
    float currentLife;
public:
    static void damage(Vector<Damageable> damageableArray, Vector<Vector<double,double>> damageMatrix);

    Damageable(float maxLife);
    Damageable(/* Default parameters */);
    ~Damageable();
};

Damageable::Damageable() : Strategy()
{
    this->maxLife = 100;
    this->currentLife = 100;
}

Damageable::Damageable(float maxLife) : Strategy(/* args */) {
    this->maxLife = maxLife;
    this->currentLife = maxLife;
}



Damageable::~Damageable()
{
}



#endif