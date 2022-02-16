#ifndef ENTITY_H
#define ENTITY_H

#include "strategies/strategy.h"
#include <vector>

class Entity //maybe virtual class ? let's see if this is useful or not later
{
private:
    std::vector<Strategy*> strategies; //basic attribute of an Entity
    
public:
    enum StrategiesID{
        DRAWABLE = 0, PHYSICAL = 1, DAMAGEABLE = 2
    };

    bool hasStrategy(StrategiesID);
    Strategy*getStrategy(StrategiesID);

    Entity(std::vector<Strategy*> strategies); //basic constructor
    ~Entity();
};



#endif
