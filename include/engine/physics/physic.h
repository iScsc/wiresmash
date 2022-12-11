/**
 * @file physic.h
 * @author Grégory Brivady
 * @brief Physics of the game engine
 * @version 0.1
 * @date 2022-12-03
 * 
 * 
 */
#ifndef ENGINE_PHYSICS_PHYSIC_H
#define ENGINE_PHYSICS_PHYSIC_H

#include <vector>

#include "engine/physics/kinematics.h"

/**
 * @brief Parameters of a physic object, used to compute forces
 * 
 */
struct PhxParam
{
    double mass = 0;

    PhxParam() = default;
} typedef PhxParam;

/**
 * @brief A Physic object, handles all the computation of the
 * kinematics to update the position of the Entity that owns it.
 * 
 */
class Physic
{
    friend class Entity;

public:

    bool is_falling = true;

    PhxParam getParam();
    Physic(/* args */) = default;
    Physic(PhxParam phxParam){this->phxParam = phxParam;};

    void setMass(double mass){this->phxParam.mass = mass;};
    
    /**
     * @brief Update the position of the physic object by
     * computing all the forces that apply on it, and then
     * applying Newton's second law.
     * 
     */
    void update();

private:

    PhxParam phxParam;
    std::pair<double, double>* pos;
    std::pair<double, double> vel;
    
    void linkPos(std::pair<double, double>* pos);
};

#endif
