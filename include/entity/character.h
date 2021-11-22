#ifndef CHARACTER_H
#define CHARACTER_H
#include "controlable.h"
#include "drawable_handler.h"
#include "physical_entity.h"
#include "schedulable.h"

class Character : Controllable, DrawableHandler, Physical_entity, Schedulable
{
private:
    /* data */
public:

    virtual void sendEvent( sf::Event e );
    

    Character(/* args */);
    ~Character();
};

Character::Character(/* args */)
{
}

Character::~Character()
{
}





#endif