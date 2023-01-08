#include "engine/physics/point.h"

void Point::linkPos(std::pair<double, double>* pos){
   this->pos = pos;
}

void Point::update(){
    if(is_falling){
	gravity(pos, &(phxParam.mass));
    }

    
}

