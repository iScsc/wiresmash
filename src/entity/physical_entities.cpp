#include "entity/strategies/physical_entity.h"
#include "phx/hitbox.h"

PhysicalEntity::PhysicalEntity(/* args */)
{
    //think to instantiate the parent Transformable attributes
}

PhysicalEntity::PhysicalEntity(std::vector<Force> f)
{
  forces = f;
}

Hitbox PhysicalEntity::getHitbox() {
  return physicalHitbox;
}

std::vector<Force> PhysicalEntity::getForces() {
  return forces;
}
