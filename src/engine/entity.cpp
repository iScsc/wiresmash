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
void Entity::addSprite(sf::Drawable* sprite){
    this->sprite = sprite;
}

sf::Drawable* Entity::getSprite(){
    return this->sprite;
}

//Dangerous adder : only private
void Entity::addPhxBox(PhxBox* pb){
    this->phxbox = pb;
    pb->linkPos(&(this->pos));
    pb->linkVel(&(this->vel));
    pb->linkOwner(this);
}

void Entity::addPhxBox(Box<PhxBox>* pb, PhxBox::CollisionBehaviour ct){
    PhxBox* phxbox = new PhxBox();
    this->addPhxBox(phxbox);
    phxbox->linkBox(pb);
    phxbox->setCollisionType(ct);
}

PhxBox* Entity::getPhxBox(){
    return this->phxbox;
}

void Entity::move(double dx, double dy){
    this->pos.first += dx;
    this->pos.second += dy;
}