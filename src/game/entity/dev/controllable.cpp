#include "game/entity/dev/controllable.h"

using namespace Wiresmash;

void Wiresmash::DevControllable::doInput(int actionId) {
    switch (actionId) {
    case 0:
        owner->move(0, amplitude);
        break;
    case 1:
        owner->move(-amplitude, 0);
        break;
    case 2:
        owner->move(0, -amplitude);
        break;
    case 3:
        owner->move(amplitude, 0);
        break;
    case 6:
        // if(!owner->getPoint()->is_falling){
        //     owner->move(0, 10*amplitude);
        //     owner->getPoint()->is_falling = true;
        // }
        owner->move(0, 4 * amplitude);
        break;
    default:

        break;
    }
}
