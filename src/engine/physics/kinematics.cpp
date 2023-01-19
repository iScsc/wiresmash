#include "engine/physics/kinematics.h"

void gravity(std::pair<double, double>* vel, double* mass){
    vel->second += *mass * PHX_CST_G;
}
