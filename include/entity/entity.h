#ifndef ENTITY_H
#define ENTITY_H

// TODO cannot include recursivly #include "lib/lib.h"
#include <vector>

#include <SFML/System/Vector2.hpp>

#include "strategies/strategy.h"


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
    void move(sf::Vector2i);
    void addVelocity();
    void incVelocity(sf::Vector2i a);
    void revertVelocity();
};

#endif

