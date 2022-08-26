#ifndef LIB_H
#define LIB_H

using namespace std;

#include <SFML/System/Vector2.hpp>
#include "entity/entity.h"

#define NB_KEYS 256

typedef sf::Vector2u pos;
typedef sf::Vector2i vel;

struct Collision
{
    Entity* ettColliding;
    Entity* ettCollided ;
    vel collisionVector;
};

#endif
