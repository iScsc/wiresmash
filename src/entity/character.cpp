#include "entity/character.h"

std::vector<Strategy*> Character::generateDefaultStrategies() {
    std::vector<Strategy*> vec;
    vec.push_back(new Damageable());
    vec.push_back(new Controllable());
    vec.push_back(new MultiDrawable());
    vec.push_back(new PhysicalEntity());
    vec.push_back(new Schedulable());
    return vec;
}

Character::Character() : Character(Character::generateDefaultStrategies()) {}
Character::Character(std::vector<Strategy*> strategies) : Character(Character::generateDefaultStrategies(), 100, 100, 10) {};
Character::Character(float strength, float maxSpeed, float jumpHeight) : Character(Character::generateDefaultStrategies(), strength, maxSpeed, jumpHeight) {}

Character::Character(std::vector<Strategy *> strategies, float strength, float maxSpeed, float jumpHeight) : Entity(strategies) {
    this->strength = strength;
    this->maxSpeed = maxSpeed;
    this->jumpHeight = jumpHeight;
}


Character::~Character()
{
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
