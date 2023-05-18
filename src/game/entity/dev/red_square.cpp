#include "game/entity/dev/red_square.h"

RedSquare::RedSquare(int size) : Engine::Entity("dev_01_RSQ") {
    this->addPoint();
    this->getPoint()->setMass(1);

    Engine::Rectangle<Engine::PhxBox>* myBox =
        new Engine::Rectangle<Engine::PhxBox>(size, size);
    this->addPhxBox(myBox, Engine::PhxBox::CollisionBehaviour::PUSHABLE);

    sf::RectangleShape* square =
        new sf::RectangleShape(sf::Vector2f(size, -size));
    square->setFillColor(sf::Color(255, 0, 0));
    this->addSprite(square);

    DevControllable* controls = new DevControllable();
    controls->setAmplitude(1);
    controls->setOwner(this);
    this->addInputHandler(controls);
}
