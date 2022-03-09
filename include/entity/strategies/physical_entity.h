#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include <string>
#include <vector>

#include "lib/forces.h"
#include "lib/lib.h"

#include "entity/strategies/strategy.h"
#include "phx/hitbox.h"

typedef struct PhxParam PhxParam; 
struct PhxParam
{
    int mass = 0;

    PhxParam() = default;
    /* Full constructor as of version XX.YY */
    PhxParam(int mass);

    /*     
    Procedure adding new params is the following : 
        - add them as attributes in PhyParam WITH A DEFAULT VALUE
        - add a new constructor
        - implements force calculation in phx
        - add the force to N2L 

    Pros : 
        - easy to add things : almost nothing to change in old codebase,
        - future proof
        - does not require a lot of prior planning while still allowing for
          a lot of possibilities in the future
        - future proof
        - future proof
        - future proof

    Cons : 
        - might get expensive in memory since we use a struct
        - entities that requires only the latest parameters and the defaults for
          everything else might have unecesseraly long constructors
        - lot of arguments in constructor
    
    Did I mention that it is ✨ future proof ✨ ?

    EXAMPLE :
    At version 1.23, we had a plane-like entity, so we had the following parameters : Cx, Cy. 

    We had :
        int cx = 0;
        int cy = 0;
    
    as struct attributes, and we create a new constructor :
    PhyParam(int mass, ..., int Cx, int Cz);
    And then we implement force calculation and add it to N2L
    */

};

class PhysicalEntity : public Strategy 
{
/*Maybe the most important strategy
PhysicalEntity (or later simply "Physical" ? "Physicable" ?) has to describe physical caracteristics of his entity:
mass, touchable, (not invisible --> in Drawable), elasticity (wait ?), forceSensible (if he is or isn't sensible to some)..

Maybe we would like to store damage hitboxes in here instead of Character, 
or damageHitbox != physicalHitbox (like i can touch with my legs) but they can't take damage
*/
private:
    //position, rotation etc in the parent class Transformable TODO WTF
    Hitbox physicalHitbox; // boolean solid (or touchable ?) in here
    PhxParam phxParam;
    static void correction(std::vector<PhysicalEntity> phxEtts, std::vector<std::vector<double,double>> correctionMatrix);
    Hitbox getHitbox();
    void setHitbox(Hitbox newHitbox);
    PhxParam getParam();

    //setPosition already handle in parent class Transformable: Google "sfml Transformable"
    /*
    the Physic toolbox will access position and then update position of every Entity
    with this strategy, these functions aren't implemented here

    only get and set positions are needed
    */

    PhysicalEntity(/* args */);
    PhysicalEntity(PhxParam phxParam);
    ~PhysicalEntity();
};

#endif
