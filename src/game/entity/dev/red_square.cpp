#include "game/entity/dev/red_square.h"

RedSquare::RedSquare(){
    Entity("dev_01_RSQ");
    this->addPhysic();
    this->getPhysic()->setMass(2);

    sf::RectangleShape* square = new sf::RectangleShape(sf::Vector2f(10,10));
    square->setFillColor(sf::Color(255,0,0));
    this->addSprite(square);
}