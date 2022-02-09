#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
#include "strategies/strategy.h"
#include <vector>
#include "strategies/multi_drawable.h"
#include "strategies/controllable.h"
#include "strategies/physical_entity.h"
#include "strategies/schedulable.h"
#include "strategies/damageable.h"

class Hitbox {
};


class Character : public Entity {
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;  //-->> in the future stored in strategies ???

    std::vector<Strategy*> generateDefaultStrategies();

    float strength;
    float maxSpeed;
    float jumpHeight;

public:

    void addAttackHitbox(Hitbox htbx);

    void eraseAttackHitbox(int index);

    void eraseAttackHitbox(int indexFirst, int indexLast);

    std::vector<Hitbox> &getAttackHitbox();

    Hitbox &getDamageHitbox();

    void setDamageHitbox(Hitbox &damageHitbox);

    float getStrength();

    void setStrength(float strength);

    float getMaxSpeed();

    void setMaxSpeed(float maxSpeed);

    float getJumpHeight();

    void setJumpHeight(float jumpHeight);


public:

    Character();
    Character(std::vector<Strategy*> strategies); //or every player has the same strategies ? to be discussed...
    Character(float strength, float maxSpeed, float jumpHeight);
    Character(std::vector<Strategy*>, float strength, float maxSpeed, float jumpHeight);
    ~Character();

};

//in .cpp:
std::vector<Strategy*> generateDefaultStrategies() {
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

#endif
