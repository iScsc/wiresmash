#include "phx/phx.h"
#include <vector>

Vel updateCinematics(PhysicalEntity const ett) {
  Vel correction (0,0); 
  Vel ett.getVelocity();
  std::vector<Force> forces = ett.getForce(); 

  for (auto force: forces) {
    switch(force) {
      case weight:
        correction.second += -10;
        break;

      default:
        break;
    }
  } 

  return correction; 
}

