#ifndef HITBOX_HITBOX_H
#define HITBOX_HITBOX_H

#include <cmath>
#include <vector>
// #include "engine/entity.h"
typedef std::pair<int, int> point;

class Entity;

struct Collision
{
    Entity* ettColliding;
    Entity* ettCollided ;
    std::pair<int, int> collisionVector = std::make_pair(0, 0); //Vector start from colliding, towards collided
    Collision() = default;
} typedef Collision;


class Hitbox
{
    friend class Entity;

private:
    void linkPos(std::pair<int, int>* pos);
    void linkEntity(Entity* ett);

protected:
    std::pair<int, int>* pos;
    Entity* owner;
    /* Position of vertices, relative to the hitbox' position .
     * Vertices MUST be given in trigonometric order.
    */
    std::vector<point> relVertices;

public:

    Hitbox() = default;
    ~Hitbox() = default;

    point* getPos() {return pos;};
    std::vector<point> getVertices() {return relVertices;};
    Entity* getOwner() {return owner;};
    virtual Collision checkCollision(Hitbox* ) = 0;
};

#endif