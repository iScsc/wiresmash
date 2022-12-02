#ifndef ENGINE_PHYSIC_PHYSIC_H
#define ENGINE_PHYSIC_PHYSIC_H

#include <vector>

#include "engine/physic/cinematic.h"


typedef struct PhxParam PhxParam;
struct PhxParam
{
    double mass = 0;

    PhxParam() = default;
};


class Physic
{
    friend class Entity;

private:

    PhxParam phxParam;
    std::pair<double, double>* pos;
    std::pair<double, double> vel;
    
    void linkPos(std::pair<double, double>* pos);

public:

    bool is_falling = true;

    PhxParam getParam();
    Physic(/* args */) = default;
    Physic(PhxParam phxParam){this->phxParam = phxParam;};

    void setMass(double mass){this->phxParam.mass = mass;};
        
    void update();
};

#endif
