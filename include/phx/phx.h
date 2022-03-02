#ifndef PHX_PFD_H
#define PHX_PFD_H

#include "lib/lib.h"
#include "entity/strategies/physical_entity.h"

// Constrain
// vitessePersoMax < longeurPersoMin

#define PHX_MAX_VEL = 1000000

// Constants
#define PHX_CST_Gx   0
#define PHX_CST_Gy -10

void smoothVel(vel*);

void addGravity(vel*);

vel updateCinematics(PhysicalEntity* const);

#endif
