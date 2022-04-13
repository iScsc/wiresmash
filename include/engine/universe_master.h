#ifndef ENGINE_UNIVERSE_MASTER_H
#define ENGINE_UNIVERSE_MASTER_H

#include <iostream>
#include <list>
#include "engine/entity.h"

typedef std::list<Entity*> EntityStack;

class UniverseMaster
{
private:
    EntityStack allEntities;

public:
    UniverseMaster(/* args */) = default;

    void addEntity(Entity* entity);

    void updateEntity();
};




#endif