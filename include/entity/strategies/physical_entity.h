#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include "strategy.h"
#include <vector>
#include <SFML/Graphics/Transformable.hpp>
#include "lib.h"

class Hitbox{};

class PhysicalEntity : public sf::Transformable, public Strategy 
{
/*Maybe the most important strategy
PhysicalEntity (or later simply "Physical" ? "Physicable" ?) has to describe physical caracteristics of his entity:
mass, touchable, (not invisible --> in Drawable), elasticity (wait ?), forceSensible (if he is or isn't sensible to some)..

Maybe we would like to store damage hitboxes in here instead of Character, 
or damageHitbox != physicalHitbox (like i can touch with my legs) but they can't take damage
*/
private:
    //!!! IMPORTANT position, rotation etc in the parent class Transformable

    Hitbox physicalHitbox; // boolean solid (or touchable ?) in here

    PhxParam phxParam;

public:
    static void
    correction(std::vector<PhysicalEntity> phxEtts, std::vector<std::vector<double, double>> correctionMatrix);



    //setPosition already handle in parent class Transformable: Google "sfml Transformable"

    /*
    the Physic toolbox will access position and then update position of every Entity
    with this strategy, these functions aren't implemented here

    only get and set positions are needed
    */

    PhysicalEntity(/* Default values */);
    PhysicalEntity(unsigned double mass, unsigned double bouncyness, signed short gravityReaction, double internalEnergy, double electricCharge);
    ~PhysicalEntity();

    //getters and setters ...
    void setMass(double _mass);

    double getMass();

    void setHitbox(Hitbox &_Hitbox); //with stored reference...

    Hitbox getHitbox();

    void setGravityReaction(signed short _gravityReaction);

    signed short getGravityReaction();

    void setBouncyness(double _bouncyness);

    double getBouncyness();

    void setInternalEnergy(double _internalEnergy);

    double getInternalEnergy();

    void setElectricCharge(double eC);

    double getElectricCharge();

};

// in cpp :
PhysicalEntity::PhysicalEntity(/* Default values */) : Strategy(/* no args */), sf::Transformable()
{
    // Initialize default parameters
    this->mass = 100;
    this->gravityReaction = 1;
    this->bouncyness = .5;
    this->internalEnergy = 0;
    this->electricCharge = 0;
    // Done for now, depending on args
}

PhysicalEntity::PhysicalEntity(unsigned double mass, unsigned double bouncyness, signed short gravityReaction, double internalEnergy, double electricCharge) : Strategy(/* no args */), sf::Transformable() {
    this->mass = mass;
    this->gravityReaction = gravityReaction;
    this->bouncyness = bouncyness;
    this->internalEnergy = internalEnergy;
    this->electricCharge = electricCharge;
}

PhysicalEntity::~PhysicalEntity()
{
}

#endif
