#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "engine/physic/physic.h"
#include "engine/physic/phxbox.h"
#include "engine/box/box.h"

class InputHandler;
class Entity
{
private:
    //Coordinates
    std::pair<double, double> pos;
    std::pair<double, double> vel;
    //Name
    std::string name;
    //Physic
    Physic* physic;
    //Displaying
    sf::Drawable* sprite;
    // --- Boxes --- //
    //Pushboxes
    PhxBox* phxbox;
    //Dangerous adder, so stocked here for now
    void addPhxBox(PhxBox* pb);

    // --- Controls --- //
    InputHandler* inputHandler;

public:
    Entity();
    Entity(std::string name);
    ~Entity() = default;

    void addPhysic();
    Physic* getPhysic();

    void addSprite();
    void addSprite(sf::Drawable*);
    sf::Drawable* getSprite();

    void addPhxBox(Box<PhxBox>* box, PhxBox::CollisionBehaviour ct);
    PhxBox* getPhxBox();

    std::string getName(){ return name; };

    void setPos(double x, double y){ pos = std::make_pair(x, y);};
    void setPos(std::pair<double, double> pos){this->pos = pos;};
    std::pair<double, double> getPos(){return pos;};

    void setVel(double vx, double vy){ vel = std::make_pair(vx, vy);};
    void setVel(std::pair<double, double> vel){this->vel = vel;};
    std::pair<double, double> getVel(){return vel;};

    virtual void collPhxNotify(Entity* ett) {};

    InputHandler* getInputHandler() {return inputHandler;};
    void move(double dx, double dy);
    void addInputHandler(InputHandler* i){ this->inputHandler = i;};
};


#endif
