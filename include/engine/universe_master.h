#ifndef ENGINE_UNIVERSE_MASTER_H
#define ENGINE_UNIVERSE_MASTER_H

#include <iostream>
#include <list>
#include "engine/entity.h"
#include "engine/physic/physic.h"

typedef std::list<Entity*> EntityStack;

typedef	std::list<Physic*> PhysicStack;

class UniverseMaster
{
private:
    EntityStack allEntity;
    PhysicStack allPhysic;

    void updatePhysic();
    void updateEntity();

public:
    UniverseMaster(/* args */) = default;

    void addEntity(Entity* entity);

    void update();
};




#endif
