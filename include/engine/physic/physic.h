#ifndef ENGINE_PHYSIC_PHYSIC_H
#define ENGINE_PHYSIC_PHYSIC_H

#include <vector>

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
public:
    PhxParam getParam();
    Physic(/* args */) = default;
    Physic(PhxParam phxParam){this->phxParam = phxParam;};

    void setMass(int mass){this->phxParam.mass = mass;};
};

#endif
