/**
 * @file phxbox.h
 * @author Grégory Brivady
 * @brief Defines the behaviour of boxes that are supposed to work under the
 * laws of physics
 * @version 0.1
 * @date 2022-12-03
 *
 *
 */
#ifndef ENGINE_PHYSICS_PHXBOX_H
#define ENGINE_PHYSICS_PHXBOX_H

#include <utility>

#include "engine/box/box.h"

namespace Engine {

class Entity;

/**
 * @brief Boxes that should push each other to solve intersection.
 *
 */
class PhxBox {
    friend Entity;

  public:
    /**
     * @brief Sub-behaviour to solve collisions
     *
     */
    enum class CollisionBehaviour {
        PUSHABLE, ///< Can be pushed by another box
        STATIC    ///< Cannot be pushed
    };
    PhxBox() = default;

    Box<PhxBox>* getBox() { return this->box; };

    void setCollisionType(CollisionBehaviour ct);
    void linkOwner(Entity* owner);
    void linkBox(Box<PhxBox>* box);

    /**
     * @brief [TEMPORARY] Solve the collision between two objects
     *
     * @details Should be called twice to solve everything.
     * If both object are @see CollisionBehaviour::PUSHABLE then they each
     * get pushed by half of the intersection vector, in a direction that solves
     * the collision. If one of them is STATIC, then it does not move and the
     * other one does by the full intersection vector. If both are STATIC,
     * nothing happens.
     *
     * @param coll_pb
     */
    void solveCollision(Intersection<PhxBox>& coll_pb);

    Entity* getOwner();

  private:
    Box<PhxBox>* box;
    Entity* owner;
    std::pair<double, double>* owner_pos;
    std::pair<double, double>* owner_vel;
    CollisionBehaviour type;

    void linkPos(std::pair<double, double>* owner_pos);
    void linkVel(std::pair<double, double>* owner_vel);
};

} // namespace Engine

#endif