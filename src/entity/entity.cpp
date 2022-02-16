#include "entity/entity.h"
#include <SFML/System/Vector2.hpp>


bool Entity::hasStrategy(StrategiesID strategy){
    return (strategies.at(strategy) != nullptr);
}

Strategy* Entity::getStrategy(StrategiesID strategy){
    return strategies.at(strategy);
}

Entity::Entity(std::vector<Strategy*> strategies){
    //this->strategies = strategies;
}
    
void Entity::addVelocity(sf::Vector2i vel) {
  // TODO dirty casting
  position = (sf::Vector2u) ((sf::Vector2i) position + vel);
}

Entity::~Entity()
{
}
