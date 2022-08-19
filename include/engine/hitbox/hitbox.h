#ifndef HITBOX_HITBOX_H
#define HITBOX_HITBOX_H

#include <vector>

typedef std::pair<int, int> point;

struct Collider
{
    Entity* ettColliding;
    Entity* ettCollided ;
    std::pair<int, int> collisionVector;
} typedef Collider;

class Entity;

class Hitbox
{
    friend class Entity;

private:

    Entity* owner;
    std::pair<int, int>* pos;
    /* Position of vertices, relative to the hitbox' position */
    std::vector<point> rel_vertices;

    void linkPos();
    void linkEntity();

public:

    Hitbox();
    ~Hitbox();

    Collider checkCollision(Hitbox* );

};

#endif