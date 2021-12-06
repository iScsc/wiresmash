#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
#include <vector>



class Character : public Entity
{
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;

    float maxLife; //to be update later if a charac is considered as a system of body parts
    float currentLife;
    float strength;
    float maxSpeed;
    float jumpHeight;


public:

    Character(std::vector<Strategy*> strategies); //or every player has the same strategies ? to be discussed...
    ~Character();

};

//in .cpp:

Character::Character(/* args */)
{
    //initialize startegies of parent class !
}

Character::~Character()
{
}





#endif