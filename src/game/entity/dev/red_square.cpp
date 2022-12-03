#include "game/entity/dev/red_square.h"

RedSquare::RedSquare(int size) : Entity("dev_01_RSQ"){
    this->addPhysic();
    this->getPhysic()->setMass(1);

    Rectangle<PhxBox>* myBox = new Rectangle<PhxBox>(size,size);
    this->addPhxBox(myBox, PhxBox::CollisionBehaviour::PUSHABLE);

    sf::RectangleShape* square = new sf::RectangleShape(sf::Vector2f(size,-size));
    square->setFillColor(sf::Color(255,0,0));
    this->addSprite(square);

    DevControllable* controls = new DevControllable();
    controls->setAmplitude(1);
    controls->setOwner(this);
    this->addInputHandler(controls);

}