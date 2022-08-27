#include "game/entity/dev/blue_terrain.h"

BlueTerrain::BlueTerrain() : Entity("dev_02_BTR"){
    this->addHitbox(new Rectangle(100,10));
    this->setPos(point(50, -150));

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100, 10));
    rectangle->setFillColor(sf::Color(0,0,255,127));
    this->addSprite(rectangle);

}