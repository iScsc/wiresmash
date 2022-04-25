#ifndef ENGINE_PHYSIC_PHYSIC_H
#define ENGINE_PHYSIC_PHYSIC_H

#include <vector>

#include "engine/physic/cinematic.h"


typedef struct PhxParam PhxParam;
struct PhxParam
{
    int mass = 0;

    PhxParam() = default;
};


class Physic
{
private:
    PhxParam phxParam;
    std::pair<int, int>* pos;
    std::pair<int, int> vel;

public:

    bool is_falling = true;

    PhxParam getParam();
    Physic(/* args */) = default;
    Physic(PhxParam phxParam){this->phxParam = phxParam;};

    void setMass(int mass){this->phxParam.mass = mass;};
    
    void linkPos(std::pair<int, int>* pos);
    
    void update();
};

#endif
