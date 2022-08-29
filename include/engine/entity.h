#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "engine/physic/physic.h"
#include "engine/physic/phxbox.h"
#include "engine/box/box.h"

class Entity
{
private:
    //Coordinates
    std::pair<int, int> pos;
    std::pair<int, int> vel;
    //Name
    std::string name;
    //Physic
    Physic* physic;
    //Displaying
    sf::Drawable* sprite;
    // --- Boxes --- //
    //Pushboxes
    PhxBox* phxbox;



public:
    Entity();
    Entity(std::string name);
    ~Entity() = default;

    void addPhysic();
    Physic* getPhysic();

    void addSprite();
    void addSprite(sf::Drawable*);
    sf::Drawable* getSprite();

    void addPhxBox(PhxBox* h);
    PhxBox* getPhxBox();

    std::string getName(){ return name; };

    void setPos(int x, int y){ pos = std::make_pair(x, y);};
    void setPos(std::pair<int, int> pos){this->pos = pos;};
    std::pair<int, int> getPos(){return pos;};

    void setVel(int vx, int vy){ vel = std::make_pair(vx, vy);};
    void setVel(std::pair<int, int> vel){this->vel = vel;};
    std::pair<int, int> getVel(){return vel;};

    virtual void collPhxNotify(Entity* ett) {};
};


#endif
