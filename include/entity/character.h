#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
#include "strategies/strategy.h"
#include <vector>



class Character : public Entity
{
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;  //-->> in the future stored in strategies ???


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