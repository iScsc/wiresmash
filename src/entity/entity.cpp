
#include "../../include/entity/entity.h"

 Entity::hasStrategy(int strategy) {
     //if 'strategy' in strategies return true
 }

Entity::Entity(std::vector<Strategy *> strategies) {
    //this->strategies = strategies;
}

Entity::~Entity() {
}

void Entity::addStrategies(Strategy *strat) {
    strategies.push_back(strat);
}

void Entity::eraseStrategies(int index) {
    strategies.erase(strategies.begin() + index);
}

void Entity::eraseStrategies(int indexFirst, int indexLast) {
    strategies.erase(strategies.begin() + indexFirst, strategies.begin() + indexLast);
}