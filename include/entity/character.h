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



class Character : public Entity
{
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;  //-->> in the future stored in strategies ???

    std::vector<Strategy*> generateDefaultStrategies();


    float strength;
    float maxSpeed;
    float jumpHeight;


public:

    Character(std::vector<Strategy*> strategies); //or every player has the same strategies ? to be discussed...
    Character();
    Character(float strength, float maxSpeed, float jumpHeigth);
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

Character::Character(std::vector<Strategy*> strategies) : Entity(strategies)
{
    //init drawable, physical, controllable, damageable,...
    // Initiate parameters
    this->strength = 100;
    this->maxSpeed = 100;
    this->jumpHeight = 50;
    // Done for now
}

Character::~Character()
{
}





#endif