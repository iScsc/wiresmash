#ifndef GAME_ENTITY_DEV_RED_SQUARE_H
#define GAME_ENTITY_DEV_RED_SQUARE_H

#include <SFML/Graphics/RectangleShape.hpp>

#include "engine/entity.h"
#include "engine/box/rectangle.h"
#include "engine/physics/phxbox.h"
#include "game/entity/dev/controllable.h"

class RedSquare: public Engine::Entity
{
private:
    /* data */
public:
    RedSquare(int size);
    void collPhxNotify(Engine::Entity* ett) {}
};


#endif