#ifndef LIB_H
#define LIB_H

using namespace std;

#include <tuple>
#include <vector>
#include <climits>
#include "entity/entity.h"
#include "entity/strategies/physical_entity.h"
#include "phx/hitbox.h"

#define NB_KEYS 256

typedef std::pair<unsigned int, unsigned int> pos;
typedef std::pair<int, int> vel;

struct Collider
{
    Entity* ettColliding;
    Entity* ettCollided ;
    vel collisionVector;
};

typedef struct PhxParam
{   
    pos position;
    vel velocity;

    unsigned int mass;
    short gravityReaction; //-1 if the PhysicalEntity is likely to fly
    double bouncyness; // [0,1] absorb every momentum (0) or none (1), maybe it will increase it's internal energy ( to satisfy conservation of energy)
    double internalEnergy; //for characters that can absorb energy and then liberate it ?
} PhxParam;

#endif
