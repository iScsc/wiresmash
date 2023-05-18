/**
 * @file point.h
 * @author Grégory Brivady
 * @brief Physics of the game engine
 * @version 0.1
 * @date 2022-12-03
 *
 *
 */
#ifndef ENGINE_PHYSICS_POINT_H
#define ENGINE_PHYSICS_POINT_H

#include <vector>

#include "engine/physics/kinematics.h"

namespace Engine {

/**
 * @brief Parameters of a point object, used to compute forces
 *
 */
struct PhxParam {
    double mass = 0;

    PhxParam() = default;
} typedef PhxParam;

/**
 * @brief A Point object, handles all the computation of the
 * kinematics to update the position of the Entity that owns it.
 *
 */
class Point {
    friend class Entity;

  public:
    bool is_falling = true;

    PhxParam getParam();
    Point(/* args */) = default;
    Point(PhxParam phxParam) { this->phxParam = phxParam; };

    void setMass(double mass) { this->phxParam.mass = mass; };

    /**
     * @brief Update the position of the point object by
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

} // namespace Engine

#endif
