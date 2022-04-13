#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <vector>
#include "engine/physic/physic.h"


class Entity
{
private:
    std::pair<int, int> pos;
    std::pair<int, int> vel;

    std::string name;

    Physic* physic;    

public:
    Entity();
    Entity(std::string name);
    ~Entity() = default;

    void addPhysic();

    std::string getName(){ return name; };

    void setPos(int x, int y){ pos = std::make_pair(x, y);};
    void setPos(std::pair<int, int> pos){this->pos = pos;};
    std::pair<int, int> getPos(){return pos;};

    void setVel(int vx, int vy){ vel = std::make_pair(vx, vy);};
    void setVel(std::pair<int, int> vel){this->vel = vel;};
    std::pair<int, int> getVel(){return vel;};

};


#endif