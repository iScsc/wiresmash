#include "entity/entity.h"

Entity::Entity(){
    strategies = emptyStrHdl();
}
Entity::Entity(std::vector<Strategy*> s) : strategies(s) {}
Entity::~Entity() {}

void Entity::setStrategy(StrategiesID id, Strategy* str){
  strategies.at(id) = str;
}

bool Entity::hasStrategy(StrategiesID strategy){
    return (strategies.at(strategy) != nullptr);
}

Strategy* Entity::getStrategy(StrategiesID strategy){
    return strategies.at(strategy);
}

sf::Vector2u  Entity::getPosition() {
  return position;
}

void Entity::move(sf::Vector2i vel){
  // TODO Casting
  position = (sf::Vector2u) ((sf::Vector2i) position + vel);

}

void Entity::addVelocity() {
  // TODO dirty casting
  position = (sf::Vector2u) ((sf::Vector2i) position + velocity);
}

void Entity::incVelocity(sf::Vector2i acc) {
  velocity += acc;
}

void Entity::revertVelocity(){
  velocity *= -1;
}