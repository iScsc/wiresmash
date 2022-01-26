#ifndef HITBOX_H
#define HITBOX_H
#include "lib/lib.h"

class Hitbox
{

private:
    unsigned int s;                           // number of point composing the Hitbox 
    pos tl; // Top Left         (TL)
    pos br; // Bottom Right     (BR)

public:
    /*
    ----------------------------Hitbox Creation---------------------------- (ETT conventions)

    at the creation : for a point (x,y) : y --> MaxInt-y  (ETT conventions --> phx conventions)
    build a Hitbox full of the point (0, 0) */

    Hitbox();

    // build a Hitbox with an array of points {x,y} (for a size = 2 Hitbox : first point is Top Left, second is Bottom Right)
    Hitbox(unsigned int H[][2], unsigned int size = 2);

    // set a value for the point with the index of i (for a size = 2 Hitbox : Top Left : H[0], Bottom Right : H[1])
    void setPoint(unsigned int i, unsigned int x, unsigned int y);

    //----------------------------Obtention de Hitbox----------------------------// (phx conventions)

    // get the number of points composing Hitbox
    unsigned int size();

    // return the Hitbox as a vector of points {x, y} (given points are Bottom Left and Top Right)
    std::vector<pos> getHitbox();
};

#endif
