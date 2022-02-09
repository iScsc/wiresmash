#ifndef PHX_COLLISION_H
#define PHX_COLLISION_H

// dependencies
#include <tuple>
#include <vector>

/**
 * TEMPORARY STARTS HERE 
 * 
 */
class Hitbox
{
private:
    unsigned int x;
    unsigned int y;
    unsigned int length;
    unsigned int height;

public:
    Hitbox() = default;
    Hitbox(unsigned int x, unsigned int y, unsigned int length, unsigned int height);
    unsigned int getX();
    unsigned int getY();
    unsigned int getL();
    unsigned int getH();
};
class Entity{
public:
    Hitbox hbx;
    Entity(Hitbox hbx);
};
struct Collider
{
    Entity* ettColliding;
    Entity* ettInto ;
    std::pair<int, int> colVector;
};

std::pair<int, int> checkCollisionEntities(Entity, Entity);

std::vector<Collider> checkCollision(std::vector<Entity>);


#endif
