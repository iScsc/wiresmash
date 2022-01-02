#ifndef PHX_PHX_H
#define PHX_PHX_H

#include "lib/lib.h"
#include <vector>
#include <iostream>
#include "entity/strategies/physical_entity.h"

// Constrain
// vitessePersoMax < longeurPersoMin

Vel updateCinematics(PhysicalEntity const);

class Hitbox {
private:
    std::vector<Vec> m_vertices;
};

#endif
