#ifndef ENTITY_H
#define ENTITY_H

#include "strategy.h"
#include <vector>

class Entity //maybe virtual class ? let's see if this is usefull or not later
{
private:
    std::vector<Strategy*> strategies; //basic attribute of an Entity
    
public:
    Entity(std::vector<Strategy*> strategies); //basic constructor
    ~Entity();
};

//in .cpp :

Entity::Entity(std::vector<Strategy*> strategies){
    //this->strategies = strategies;
}

Entity::~Entity()
{
}




#endif