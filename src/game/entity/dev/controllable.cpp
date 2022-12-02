#include "game\entity\dev\controllable.h"

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
    default:
        break;
    }
}
