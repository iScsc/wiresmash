#include "engine/physics/kinematics.h"

using namespace Engine;

void Engine::gravity(std::pair<double, double>* vel, double* mass){
    vel->second += *mass * PHX_CST_G;
}
