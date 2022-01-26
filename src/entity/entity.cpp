#include "entity/entity.h"


bool Entity::hasStrategy(StrategiesID strategy){
    return (strategies.at(strategy) != NULL);
}

Strategy* Entity::getStrategy(StrategiesID strategy){
    return strategies.at(strategy);
}

Entity::Entity(std::vector<Strategy*> strategies){
    //this->strategies = strategies;
}

Entity::~Entity()
{
}
