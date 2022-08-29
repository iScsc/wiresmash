#ifndef ENGINE_BOX_RECTANGLE_H
#define ENGINE_BOX_RECTANGLE_H

#include <iostream>
#include <algorithm>

#include "engine/box/box.h"

template <typename T>
class Rectangle: public Box<T>
{
public:

    Rectangle(int x, int y);
    Rectangle(int x1, int y1, int x2, int y2);

    Collision<T> checkCollision(Rectangle<T>* ); //implemented by this class
    //TODO : HORRIBLE
    Collision<T> checkCollision(Box<T>* h) {return dynamic_cast<Rectangle<T>*>(h)->checkCollision(this); }; //let the other class handle the collision
};
#include "../src/engine/box/rectangle.tpp"
#endif