#include "game/entity/dev/controllable.h"

void DevControllable::doInput(int actionId){
    switch (actionId)
    {
    case 0:
        owner->move(0, amplitude);
        break;
    case 1:
        owner->move(-amplitude, 0);
        break;
    case 2:
        owner->move(0,-amplitude);
        break;
    case 3:
        owner->move(amplitude,0);
        break;
    case 6:
        // if(!owner->getPhysic()->is_falling){
        //     owner->move(0, 10*amplitude);
        //     owner->getPhysic()->is_falling = true;
        // }
        owner->move(0, 4*amplitude);
        break;
    default:
        break;
    }
}
