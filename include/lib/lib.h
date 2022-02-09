#ifndef LIB_H
#define LIB_H

#include <tuple>

#define NB_KEYS 256

typedef std::pair<unsigned int, unsigned int> Vec;
typedef std::pair<int, int> Vel;

typedef struct PhxParam
{   
    Vec position;
    Vel velocity;

    unsigned int mass;
    short gravityReaction; //-1 if the PhysicalEntity is likely to fly
    unsigned double bouncyness; // [0,1] absorb every momentum (0) or none (1), maybe it will increase it's internal energy ( to satisfy conservation of energy)
    double internalEnergy; //for characters that can absorb energy and then liberate it ?
} PhxParam;

enum Force {weight};

#endif
