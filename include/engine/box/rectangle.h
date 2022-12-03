#ifndef ENGINE_BOX_RECTANGLE_H
#define ENGINE_BOX_RECTANGLE_H

#include <iostream>
#include <algorithm>

#include "engine/box/box.h"

template <typename T>
class Rectangle: public Box<T>
{
public:

    Rectangle(double x, double y);
    Rectangle(double x1, double y1, double x2, double y2);

    Intersection<T> checkIntersection(Rectangle<T>* ); //implemented by this class
    //TODO : HORRIBLE
    Intersection<T> checkIntersection(Box<T>* h) {return dynamic_cast<Rectangle<T>*>(h)->checkIntersection(this); }; //let the other class handle the collision
};
#include "../src/engine/box/rectangle.tpp"
#endif