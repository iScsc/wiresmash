#ifndef ENGINE_BOX_BOX_H
#define ENGINE_BOX_BOX_H

#include <cmath>
#include <vector>
// #include "engine/entity.h"
typedef std::pair<double, double> point;

// class Entity;
template <typename T>
struct Collision
{
    T* colliding;
    T* collided ;
    std::pair<double, double> collisionVector = std::make_pair(0, 0); //Vector start from colliding, towards collided
    Collision() = default;
};

template <typename T>
class Box
{
    friend T;

private:
    void linkPos(std::pair<double, double>* pos);
    void linkOwner(T* t);

protected:
    std::pair<double, double>* pos;
    T* owner;
    /* Position of vertices, relative to the hitbox' position .
     * Vertices MUST be given in trigonometric order.
    */
    std::vector<point> relVertices;

public:

    Box() = default;
    ~Box() = default;

    point* getPos() {return pos;};
    std::vector<point> getVertices() {return relVertices;};
    T* getOwner() {return owner;};
    virtual Collision<T> checkCollision(Box<T>* ) = 0;
};
#include "../src/engine/box/box.tpp"

#endif