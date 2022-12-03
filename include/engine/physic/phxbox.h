#ifndef ENGINE_PHYSIC_PHXBOX_H
#define ENGINE_PHYSIC_PHXBOX_H

#include <utility>
#include "engine/box/box.h"

class Entity;

class PhxBox{
    friend Entity;
public:
    enum class CollisionBehaviour {PUSHABLE, STATIC};
    PhxBox() = default;

    Box<PhxBox>* getBox() {return this->box;};

    void setCollisionType(CollisionBehaviour ct);
    void linkOwner(Entity* owner);
    void linkBox(Box<PhxBox>* box);

    void solveCollision(Intersection<PhxBox>& coll_pb);

    Entity* getOwner();
    
private:
    Box<PhxBox>* box;
    Entity* owner;
    std::pair<double, double>* owner_pos;
    std::pair<double, double>* owner_vel;
    CollisionBehaviour type;

    void linkPos(std::pair<double, double>* owner_pos);
    void linkVel(std::pair<double, double>* owner_vel);
};


#endif