#ifndef ENGINE_HITBOX_RECTANGLE_H
#define ENGINE_HITBOX_RECTANGLE_H

#include <iostream>
#include <algorithm>

#include "engine/hitbox/hitbox.h"

class Rectangle: public Hitbox
{
public:

    Rectangle(int x, int y);
    Rectangle(int x1, int y1, int x2, int y2);

    Collision checkCollision(Rectangle* ); //implemented by this class
    //TODO : HORRIBLE
    Collision checkCollision(Hitbox* h) {return dynamic_cast<Rectangle*>(h)->checkCollision(this); }; //let the other class handle the collision
};

#endif