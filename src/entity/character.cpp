#include "../../include/entity/character.h"


Character::~Character() {
}

std::vector<Hitbox> &Character::getAttackHitbox() {
    return attackHitbox;
}

Hitbox &Character::getDamageHitbox() {
    return damageHitbox;
}

void Character::setDamageHitbox(Hitbox &damageHitbox) {
    Character::damageHitbox = damageHitbox;
}

float Character::getStrength() {
    return strength;
}

void Character::setStrength(float strength) {
    Character::strength = strength;
}

float Character::getMaxSpeed() {
    return maxSpeed;
}

void Character::setMaxSpeed(float maxSpeed) {
    Character::maxSpeed = maxSpeed;
}

float Character::getJumpHeight() {
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
