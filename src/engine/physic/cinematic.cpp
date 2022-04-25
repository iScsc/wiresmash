#include "engine/physic/cinematic.h"

void gravity(std::pair<int, int>* vel, int* mass){
    vel->second += *mass * PHX_CST_G;
}
