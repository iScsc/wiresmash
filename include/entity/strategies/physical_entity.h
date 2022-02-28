#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include "strategy.h"
#include "lib/forces.h"
#include "lib/lib.h"
#include "phx/hitbox.h"
#include <vector>

class PhysicalEntity : public Strategy 
{
/*Maybe the most important strategy
PhysicalEntity (or later simply "Physical" ? "Physicable" ?) has to describe physical caracteristics of his entity:
mass, touchable, (not invisible --> in Drawable), elasticity (wait ?), forceSensible (if he is or isn't sensible to some)..

Maybe we would like to store damage hitboxes in here instead of Character, 
or damageHitbox != physicalHitbox (like i can touch with my legs) but they can't take damage
*/
private:
    Hitbox physicalHitbox; // boolean solid (or touchable ?) in here
    PhxParam phxParam;
    static void correction(std::vector<PhysicalEntity> phxEtts, std::vector<std::vector<double,double>> correctionMatrix);

    /*
    the Physic toolbox will access position and then update position of every Entity
    with this strategy, these functions aren't implemented here

    only get and set positions are needed
    */

    PhysicalEntity(/* Default values */);
    ~PhysicalEntity();
};

#endif
