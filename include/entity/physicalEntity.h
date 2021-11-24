#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include <SFML/System/Vector2.hpp>


typedef struct 
{
    /* collider stuff ( e.g. linked list of vertex) */
} Collider;



class PhysicalEntity
{
private:
    sf::Vector2f pos;
    float rot;

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