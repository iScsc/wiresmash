#include "../../../include/entity/strategies/damageable.h"

Damageable::Damageable(/* args */) {
}

Damageable::~Damageable() {
}

void Damageable::setMaxLife(float &_maxLife) {
    maxLife = _maxLife;
}

float Damageable::getMaxLife() {
    return maxLife;
}

void Damageable::setCurrentLife(float &_currentLife) {
    currentLife = _currentLife;
}

float Damageable::getCurrentLife() {
    return currentLife;
}

