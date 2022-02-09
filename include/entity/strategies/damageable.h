#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "strategy.h"
#include <vector>

using namespace std;

class Damageable : public Strategy
{
private:
    float maxLife;
    float currentLife;
public:
    static void damage(vector<Damageable> damageableArray, vector<vector<double, double>> damageMatrix);

    void setMaxLife(float maxLife);

    float getMaxLife();

    void setCurrentLife(float currentLife);

    float getCurrentLife();


    Damageable(float maxLife);
    Damageable(/* Default parameters */);
    ~Damageable();
};

#endif
