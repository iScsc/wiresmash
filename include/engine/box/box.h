/**
 * @file box.h
 * @author Grégory Brivady
 * @brief Box template class definition
 * @version 0.1.0
 * @date 2022-08-25
 * 
 */
#ifndef ENGINE_BOX_BOX_H
#define ENGINE_BOX_BOX_H

#include <cmath>
#include <vector>

/**
 * @brief Container for all the information about an intersection of two boxes.
 * 
 * @tparam T behaviour of the boxes
 */
template <typename T>
struct Intersection
{
    T* intersecting;
    T* intersected ;
    std::pair<double, double> intersectionVector = std::make_pair(0, 0); //Vector start from intersecting, towards intersected
    Intersection() = default;
};

/**
 * @brief Boxes are defined solely as geometrical objects. Their only purpose
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

public:

    Box() = default;
    ~Box() = default;

    std::pair<double, double>* getPos() {return pos;};
    std::vector<std::pair<double, double>> getVertices() {return relVertices;};
    T* getOwner() {return owner;};

    /**
     * @brief Check if this box and another one intersects.
     * 
     * @param b 
     * @return an @see Intersection<T>  object
     */
    virtual Intersection<T> checkIntersection(Box<T>* b) = 0;

protected:
    /**
     * @brief direct link to owner's position
     * 
     */
    std::pair<double, double>* pos;

    /**
     * @brief the behaviour who owns the box
     * 
     */
    T* owner;

   /**
    * @brief Position of the vertices, relative to the box frame of reference.
    * Vertices must be given in trigonometric order.
   */
    std::vector<std::pair<double, double>> relVertices;

private:

    /**
     * @brief link the position of this box to the one of its owner.
     * 
     * @param pos 
     */
    void linkPos(std::pair<double, double>* pos);

    /**
     * @brief link the box to its owner.
     * 
     * @param t 
     */
    void linkOwner(T* t);
};

#include "../src/engine/box/box.tpp" //TODO : find a better way to include this

#endif