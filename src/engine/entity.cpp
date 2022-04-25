#include "engine/entity.h"

Entity::Entity(){
    this->physic = NULL;
}

Entity::Entity(std::string name){
    this->name = name;
}

void Entity::addPhysic(){
    this->physic = new Physic();
    this->physic->linkPos(&(this->pos));
}

Physic* Entity::getPhysic(){
    return this->physic;
}
