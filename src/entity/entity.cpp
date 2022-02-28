#include "entity/entity.h"
#include <SFML/System/Vector2.hpp>

Entity::Entity(std::vector<Strategy*> s) : strategies(s) {}
Entity::~Entity() {}

bool Entity::hasStrategy(StrategiesID strategy){
    return (strategies.at(strategy) != nullptr);
}

Strategy* Entity::getStrategy(StrategiesID strategy){
    return strategies.at(strategy);
}

sf::Vector2u  Entity::getPosition() {
  return position;
}
    
void Entity::addVelocity(sf::Vector2i vel) {
  // TODO dirty casting
  position = (sf::Vector2u) ((sf::Vector2i) position + vel);
}

