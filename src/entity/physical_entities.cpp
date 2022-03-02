#include "entity/strategies/physical_entity.h"
#include "phx/hitbox.h"

PhyParam::PhyParam(int mass){
  this->mass = mass;
}

PhysicalEntity::PhysicalEntity(/* args */)
{
    //think to instantiate the parent Transformable attributes
}

PhysicalEntity::PhysicalEntity(PhyParam phxParam)
{
  this->phxParam = phxParam;
}

Hitbox PhysicalEntity::getHitbox() {
  return physicalHitbox;
}

PhyParam PhysicalEntity::getParam(){
  return phxParam;
}