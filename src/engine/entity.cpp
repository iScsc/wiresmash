#include "engine/entity.h"

Entity::Entity(){
    this->physic = NULL;
}

Entity::Entity(std::string name){
    this->name = name;
}

void Entity::addPhysic(){
    this->physic = new Physic();
}

Physic* Entity::getPhysic(){
    return this->physic;
}
