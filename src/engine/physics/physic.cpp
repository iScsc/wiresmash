#include "engine/physics/physic.h"

void Physic::linkPos(std::pair<double, double>* pos){
   this->pos = pos;
}

void Physic::update(){
    if(is_falling){
	gravity(pos, &(phxParam.mass));
    }

    
}

