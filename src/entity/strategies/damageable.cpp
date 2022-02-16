#include "entity/strategies/damageable.h"

Damageable::Damageable() : Strategy()
{
    this->maxLife = 100;
    this->currentLife = 100;
}

Damageable::Damageable(float maxLife) : Strategy(/* args */) {
    this->maxLife = maxLife;
    this->currentLife = maxLife;
}

Damageable::~Damageable() {
}

void Damageable::setMaxLife(float maxLife) {
    maxLife = maxLife;
}

float Damageable::getMaxLife() {
    return maxLife;
}

void Damageable::setCurrentLife(float currentLife) {
    currentLife = currentLife;
}

float Damageable::getCurrentLife() {
    return currentLife;
}

