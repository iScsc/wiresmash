/**
 * @file box.h
 * @author Grégory Brivady (gregory.brivady@gmail.com)
 * @brief Box tempalte class definition
 * @version 0.1.0
 * @date 2022-08-25
 * 
 */
#ifndef ENGINE_BOX_BOX_H
#define ENGINE_BOX_BOX_H

#include <cmath>
#include <vector>
// #include "engine/entity.h"
typedef std::pair<double, double> point;

// class Entity;

template <typename T>
struct Intersection
{
    T* intersecting;
    T* intersected ;
    std::pair<double, double> intersectionVector = std::make_pair(0, 0); //Vector start from intersecting, towards intersected
    Intersection() = default;
};

/**
 * @brief Boxes are defined solely as geometrical objects. Their only purposes
 * is to check if they intersect with other box-objects of the same type. By
 * using the template parameter, one can specify the behaviour of such a box when it
 * intersects with another box-object.
 * 
 * @tparam T behaviour of the box
 */
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
    virtual Intersection<T> checkIntersection(Box<T>* ) = 0;
};
#include "../src/engine/box/box.tpp"

#endif