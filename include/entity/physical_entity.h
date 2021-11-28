#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include "entity.h"
#include <SFML/Graphics/Transformable.hpp>

class Hitbox{};

class PhysicalEntity : public sf::Transformable
{
private:

    Hitbox physicalHitbox;


public:

    virtual void updatePhysics(); //here some kind of phx::PhysicsHandler; 
    Hitbox getHitbox();
    void setHitbox(Hitbox newHitbox);

    PhysicalEntity(/* args */);
    ~PhysicalEntity();
};

PhysicalEntity::PhysicalEntity(/* args */)
{
}

PhysicalEntity::~PhysicalEntity()
{
}



#endif