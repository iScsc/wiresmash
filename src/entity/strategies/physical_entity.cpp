#include "entity/strategies/physical_entity.h"
#include "phx/hitbox.h"

PhxParam::PhxParam(int mass){
  this->mass = mass;
}

PhysicalEntity::PhysicalEntity(/* args */)
{
    //think to instantiate the parent Transformable attributes
}

PhysicalEntity::PhysicalEntity(PhxParam phxParam)
{
  this->phxParam = phxParam;
}

Hitbox PhysicalEntity::getHitbox() {
  return physicalHitbox;
}

PhxParam PhysicalEntity::getParam(){
  return phxParam;
}

