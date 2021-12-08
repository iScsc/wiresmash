#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
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
    ~Character();

};

//in .cpp:

Character::Character(/* args */)
{
    //init drawable, physical, controllable, damageable,...

}

Character::~Character()
{
}





#endif