#include "../../include/entity/character.h"


Character::~Character() {
}

const std::vector<Hitbox> &Character::getAttackHitbox() const {
    return attackHitbox;
}

void Character::setAttackHitbox(const std::vector<Hitbox> &attackHitbox) {
    Character::attackHitbox = attackHitbox;
}

const Hitbox &Character::getDamageHitbox() const {
    return damageHitbox;
}

void Character::setDamageHitbox(const Hitbox &damageHitbox) {
    Character::damageHitbox = damageHitbox;
}

float Character::getStrength() const {
    return strength;
}

void Character::setStrength(float strength) {
    Character::strength = strength;
}

float Character::getMaxSpeed() const {
    return maxSpeed;
}

void Character::setMaxSpeed(float maxSpeed) {
    Character::maxSpeed = maxSpeed;
}

float Character::getJumpHeight() const {
    return jumpHeight;
}

void Character::setJumpHeight(float jumpHeight) {
    Character::jumpHeight = jumpHeight;
}

void Character::addAttackHitbox(Hitbox htbx) {
    attackHitbox.push_back(htbx);
}

void Character::eraseAttackHitbox(int index) {
    attackHitbox.erase(attackHitbox.begin() + index);
}

void Character::eraseAttackHitbox(int indexFirst, int indexLast) {
    attackHitbox.erase(attackHitbox.begin() + indexFirst, attackHitbox.begin() + indexLast);
}
