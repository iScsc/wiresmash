#include "entity/strategies/physical_entity.h"

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

void correctionUpdate(std::vector<Collider> colliderList)
    {
        Entity* ett1;
        Entity* ett2;
        vel intr;
        int mass1;
        int mass2;
        vel displacement;
        for (Collider col : colliderList) {
            ett1 = col.ettColliding;
            ett2 = col.ettCollided;
            intr = col.collisionVector;
            //TODO implement bouncyness later
            // unsigned double b1,b2; //bouncyness
            // b1 = ett1.bouncyness;
            // b2 = ett2.bouncyness;
            mass1 = ((PhysicalEntity*) ett1->getStrategy(PHYSICAL))->getParam().mass;
            mass2 = ((PhysicalEntity*) ett2->getStrategy(PHYSICAL))->getParam().mass;
            //massRatio = mass2/(mass1 + mass2);
            // Inherited from SFML transformable
            displacement = intr;
            displacement /= 2;
            ett1->move(displacement);            
            ett2->move(displacement-intr);
            //Reversing speed
            ett1->revertVelocity();
            ett2->revertVelocity();
        }
    }