#include "engine/entity.h"

using namespace Engine;

Engine::Entity::Entity(){
    this->point = NULL;
    this->sprite = NULL;
}

Engine::Entity::Entity(std::string name): Entity() {
    this->name = name;
}

void Engine::Entity::addPoint(){
    this->point = new Point();
    this->point->linkPos(&(this->pos));
}

Point* Engine::Entity::getPoint(){
    return this->point;
}

void Engine::Entity::addSprite(){
    sf::CircleShape* circle = new sf::CircleShape(10);
    circle->setPosition(1, 1);
    this->sprite = circle;
}
void Engine::Entity::addSprite(sf::Drawable* sprite){
    this->sprite = sprite;
}

sf::Drawable* Engine::Entity::getSprite(){
    return this->sprite;
}

//Dangerous adder : only private
void Engine::Entity::addPhxBox(PhxBox* pb){
    this->phxbox = pb;
    pb->linkPos(&(this->pos));
    pb->linkVel(&(this->vel));
    pb->linkOwner(this);
}

void Engine::Entity::addPhxBox(Box<PhxBox>* pb, PhxBox::CollisionBehaviour ct){
    PhxBox* phxbox = new PhxBox();
    this->addPhxBox(phxbox);
    phxbox->linkBox(pb);
    phxbox->setCollisionType(ct);
}

PhxBox* Engine::Entity::getPhxBox(){
    return this->phxbox;
}

void Engine::Entity::move(double dx, double dy){
    this->pos.first += dx;
    this->pos.second += dy;
}