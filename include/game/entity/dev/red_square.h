#ifndef GAME_ENTITY_DEV_RED_SQUARE_H
#define GAME_ENTITY_DEV_RED_SQUARE_H

#include <SFML/Graphics/RectangleShape.hpp>

#include "engine/entity.h"
#include "engine/box/rectangle.h"
#include "engine/physic/phxbox.h"

class RedSquare: public Entity
{
private:
    /* data */
public:
    RedSquare(int size);
    void collPhxNotify(Entity* ett) {}
};


#endif