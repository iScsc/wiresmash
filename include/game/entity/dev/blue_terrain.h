#ifndef GAME_ENTITY_DEV_BLUE_TERRAIN_H
#define GAME_ENTITY_DEV_BLUE_TERRAIN_H

#include <SFML/Graphics/RectangleShape.hpp>

#include "engine/entity.h"
#include "engine/box/rectangle.h"
#include "engine/physics/phxbox.h"
class BlueTerrain: public Entity{
public:
    BlueTerrain();
    void collPhxNotify(Entity* ett) override {ett->getPhysic()->is_falling=false;}
};

#endif