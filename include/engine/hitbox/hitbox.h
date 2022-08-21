#ifndef HITBOX_HITBOX_H
#define HITBOX_HITBOX_H

#include <vector>

typedef std::pair<int, int> point;

struct Collision
{
    Entity* ettColliding;
    Entity* ettCollided ;
    std::pair<int, int> collisionVector; //Vector start from colliding, towards collided
} typedef Collision;

class Entity;

class Hitbox
{
    friend class Entity;

private:

    Entity* owner;
    std::pair<int, int>* pos;
    /* Position of vertices, relative to the hitbox' position */
    std::vector<point> relVertices;

    void linkPos();
    void linkEntity();

public:

    Hitbox();
    ~Hitbox();

    virtual Collision checkCollision(Hitbox* );

};

#endif