#ifndef PHX_COLLISION_H
#define PHX_COLLISION_H

#include "lib/lib.h"

vel singleCheckCollision(Entity*, Entity*);

std::vector<Collider> checkCollision(std::vector<Entity*>);


#endif
