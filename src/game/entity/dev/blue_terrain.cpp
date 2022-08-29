#include "game/entity/dev/blue_terrain.h"

BlueTerrain::BlueTerrain() : Entity("dev_02_BTR"){

    Rectangle<PhxBox>* myBox = new Rectangle<PhxBox>(100,10);
    PhxBox* myPushBox = new PhxBox();

    this->addPhxBox(myPushBox);
    myPushBox->linkBox(myBox);
    myPushBox->setCollisionType(PhxBox::CollisionBehaviour::STATIC);


    
    this->setPos(point(50, -150));

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100, -10));
    rectangle->setFillColor(sf::Color(0,0,255,127));
    this->addSprite(rectangle);

}