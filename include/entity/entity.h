#ifndef ENTITY_H
#define ENTITY_H

#include "strategies/strategy.h"
#include <vector>

class Entity //maybe virtual class ? let's see if this is useful or not later
{
private:
    std::vector<Strategy*> strategies; //basic attribute of an Entity
    
public:
    const static int PHYSICAL = 0;
    const static int DRAWABLE = 1;

    const bool hasStrategy(int strategy);

    Entity(std::vector<Strategy*> strategies); //basic constructor
    ~Entity();
};

//in .cpp :

const bool Entity::hasStrategy(int strategy)
{
    //if 'strategy' in strategies return true
}

Entity::Entity(std::vector<Strategy*> strategies){
    this->strategies = strategies;
    // Done for now
}

Entity::~Entity()
{
}




#endif