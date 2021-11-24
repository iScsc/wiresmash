#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

typedef struct 
{
    /* collider stuff ( e.g. linked list of vertex) */
} Collider;


class PhysicalEntity 
{
private:

    Collider bndBox;
public:

    virtual void updatePhysics(); //here some kind of phx::PhysicsHandler; 
    void getCollider();
    void setCollider(Collider newCollider);
    
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