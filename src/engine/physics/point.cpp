#include "engine/physics/point.h"

using namespace Engine;

void Engine::Point::linkPos(std::pair<double, double>* pos){
   this->pos = pos;
}

void Engine::Point::update(){
    if(is_falling){
	gravity(pos, &(phxParam.mass));
    }

    
}

