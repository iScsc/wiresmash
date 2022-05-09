#include "engine/entity.h"

Entity::Entity(){
    this->physic = NULL;
    this->sprite = NULL;
}

Entity::Entity(std::string name): Entity() {
    this->name = name;
}

void Entity::addPhysic(){
    this->physic = new Physic();
    this->physic->linkPos(&(this->pos));
}

Physic* Entity::getPhysic(){
    return this->physic;
}

void Entity::addSprite(){
    sf::CircleShape* circle = new sf::CircleShape(10);
    circle->setPosition(1, 1);
    this->sprite = circle;
}

sf::Drawable* Entity::getSprite(){
    return this->sprite;
}