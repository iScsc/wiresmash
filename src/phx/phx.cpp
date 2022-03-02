#include "phx/phx.h"

void addGravity(vel* tempAcc){
    tempAcc->x += PHX_CST_Gx;
    tempAcc->y += PHX_CST_Gy;
}

vel updateCinematics(PhysicalEntity* const ett) {

    vel correction (0,0); 
    PhyParam phxParam = ett->getParam();

    //Newton's Second Law
    addGravity(&correction);

    return correction; 
}

