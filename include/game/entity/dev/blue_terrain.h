#ifndef GAME_ENTITY_DEV_BLUE_TERRAIN_H
#define GAME_ENTITY_DEV_BLUE_TERRAIN_H

#include <SFML/Graphics/RectangleShape.hpp>

#include "engine/box/rectangle.h"
#include "engine/entity.h"
#include "engine/physics/phxbox.h"

namespace Wiresmash {

class BlueTerrain : public Engine::Entity {
  public:
    BlueTerrain();
    void collPhxNotify(Engine::Entity* ett) override {
        ett->getPoint()->is_falling = false;
    }
};

} // namespace Wiresmash

#endif
