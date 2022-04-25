#include "engine/physic/physic.h"

void Physic::linkPos(std::pair<int, int>* pos){
   this->pos = pos;
}

void Physic::update(){
    if(is_falling){
	gravity(pos, &(phxParam.mass));
    }

    
}

