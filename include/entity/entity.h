#ifndef ENTITY_H
#define ENTITY_H

#include "strategies/strategy.h"
// TODO cannot include recursivly #include "lib/lib.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

enum StrategiesID {
  DRAWABLE = 0, PHYSICAL = 1, DAMAGEABLE = 2
};

class Entity //maybe virtual class ? let's see if this is useful or not later
{
private:
    std::vector<Strategy*> strategies; //basic attribute of an Entity
    sf::Vector2u position;
    sf::Vector2i velocity;
public:
    Entity(std::vector<Strategy*> strategies); //basic constructor
    ~Entity();

    bool hasStrategy(StrategiesID);
    Strategy* getStrategy(StrategiesID);

    sf::Vector2u getPosition();
    void addVelocity();
    void incVelocity(sf::Vector2i a);
};



#endif
