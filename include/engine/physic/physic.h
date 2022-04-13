#ifndef ENGINE_PHYSIC_PHYSIC_H
#define ENGINE_PHYSIC_PHYSIC_H

#include <vector>
#include "engine/entity.h"

typedef struct PhxParam PhxParam; 
struct PhxParam
{
    int mass = 0;

    PhxParam() = default;
};


class Physic 
{
private:
    Entity* owner;
    PhxParam phxParam;
public:
    PhxParam getParam();
    Physic(/* args */) = default;
    Physic(PhxParam phxParam){this->phxParam = phxParam;};

    void setMass(int mass){this->phxParam.mass = mass;};
};

#endif
