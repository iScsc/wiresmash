/**
 * @file rectangle.h
 * @author Grégory Brivady
 * @brief A rectangle
 * @version 0.1
 * @date 2022-12-03
 * 
 */
#ifndef ENGINE_BOX_RECTANGLE_H
#define ENGINE_BOX_RECTANGLE_H

#include <iostream>
#include <algorithm>

#include "engine/box/box.h"

/**
 * @brief A rectangle, defined by 4 vertices, starting from bottom-left, and then
 * progressing in trigonometric order.
 * @see Box<T>
 * 
 * @tparam T Behaviour of the rectangle-box
 */
template <typename T>
class Rectangle: public Box<T>
{
public:

    /**
     * @brief Construct a new Rectangle object by using only its length
     * and its height.
     * 
     * @param x Length of the rectangle on the x (horizontal) axis
     * @param y Height of the rectangle on the y (vertical) axis
     */
    Rectangle(double x, double y);

    /**
     * @brief Construct a new Rectangle object by specifying all 4 points of the rectangle.
     * 
     * @details If x1 < x2 and y1 < y2, its bottom-left corner and top-right corner will be:
     * (x1, y1) and (x2, y2).
     * 
     * 
     * @param x1 
     * @param y1 
     * @param x2 
     * @param y2 
     */
    Rectangle(double x1, double y1, double x2, double y2);

    Intersection<T> checkIntersection(Rectangle<T>* ); //implemented by this class
    //TODO : HORRIBLE
    Intersection<T> checkIntersection(Box<T>* h) {return dynamic_cast<Rectangle<T>*>(h)->checkIntersection(this); }; //let the other class handle the collision
};

#include "../src/engine/box/rectangle.tpp" //Todo : same as box.tpp todo

#endif