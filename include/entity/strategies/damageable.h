#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "strategy.h"


class Damageable
{
private:
    float maxLife;
    float currentLife;
public:
    static void damage(Vector<Damageable> damageableArray, Vector<Vector<double,double>> damageMatrix);

    Damageable(/* args */);
    ~Damageable();
};



Damageable::Damageable(/* args */)
{
}

Damageable::~Damageable()
{
}



#endif