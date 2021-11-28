#ifndef CHARACTER_H
#define CHARACTER_H
#include "controlable.h"
#include "drawable_handler.h"
#include "physical_entity.h"
#include "schedulable.h"
#include <vector>

// dependencies
class Hitbox{ /* Stuff with hitboxes */ };


class Character : Controllable, DrawableHandler, PhysicalEntity, Schedulable
{
private:

    std::vector<Hitbox> attackHitbox;
    Hitbox damageHitbox;


public:

    Character(/* args */);
    ~Character();

    virtual void sendEvent( sf::Event e );


    float maxLife;
    float currentLife;
    float strength;
    float speed;
    float jumpHeight;


};

Character::Character(/* args */)
{
}

Character::~Character()
{
}





#endif