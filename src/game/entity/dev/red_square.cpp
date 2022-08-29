#include "game/entity/dev/red_square.h"

RedSquare::RedSquare(int size) : Entity("dev_01_RSQ"){
    this->addPhysic();
    this->getPhysic()->setMass(1);

    Rectangle<PhxBox>* myBox = new Rectangle<PhxBox>(size,size);
    PhxBox* myPushBox = new PhxBox();

    this->addPhxBox(myPushBox);
    myPushBox->linkBox(myBox);
    myPushBox->setCollisionType(PhxBox::CollisionBehaviour::PUSHABLE);

    sf::RectangleShape* square = new sf::RectangleShape(sf::Vector2f(size,-size));
    square->setFillColor(sf::Color(255,0,0));
    this->addSprite(square);
}