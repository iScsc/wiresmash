#include "../../../include/entity/strategies/physical_entity.h"

PhysicalEntity::PhysicalEntity(/* args */) {
    //think to instantiate the parent Transformable attributes
}

PhysicalEntity::~PhysicalEntity() {

}

void PhysicalEntity::setMass(double _mass) {
    mass = _mass;
}

double PhysicalEntity::getMass() {
    return mass;
}

void PhysicalEntity::setHitbox(Hitbox &_Hitbox) {
    physicalHitbox = _Hitbox;
}

Hitbox PhysicalEntity::getHitbox() {
    return physicalHitbox;
}

void PhysicalEntity::setGravityReaction(signed short _gravityReaction) {
    gravityReaction = _gravityReaction;
}

signed short PhysicalEntity::getGravityReaction() {
    return gravityReaction;
}

void PhysicalEntity::setBouncyness(double _bouncyness) {
    bouncyness = _bouncyness;
}

double PhysicalEntity::getBouncyness() {
    return bouncyness;
}

void PhysicalEntity::setInternalEnergy(double _internalEnergy) {
    internalEnergy = _internalEnergy;
}

double PhysicalEntity::getInternalEnergy() {
    return internalEnergy;
}

void PhysicalEntity::setElectricCharge(double eC) {
    electricCharge = eC;
}

double PhysicalEntity::getElectricCharge() {
    return electricCharge;
}