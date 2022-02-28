#include "phx/phx.h"


vel updateCinematics(PhysicalEntity* const ett) {
  vel correction (0,0); 
  std::vector<Force> forces = ett->getForces();

  for (auto force: forces) {
    switch(force) {
      case weight:
        correction.y += WEIGHT;
        break;

      default:
        break;
    }
  } 

  return correction; 
}

