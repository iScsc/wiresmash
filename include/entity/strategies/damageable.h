#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "strategy.h"
#include <vector>

class Damageable : public Strategy
{
private:
    float maxLife;
    float currentLife;
public:
    static void damage(std::vector<Damageable> damageableArray, std::vector<std::vector<double, double>> damageMatrix);

    void setMaxLife(float &_maxLife);

    float getMaxLife();

    void setCurrentLife(float &_currentLife);

    float getCurrentLife();


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
