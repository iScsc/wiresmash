/**
 * @file universe_master.h
 * @author Grégory Brivady
 * @brief
 * @version 0.1
 * @date 2022-12-03
 *
 *
 */
#ifndef ENGINE_UNIVERSE_MASTER_H
#define ENGINE_UNIVERSE_MASTER_H

#include <iostream>
#include <list>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "engine/entity.h"
#include "engine/input/input_handler.h"
#include "engine/physics/phxbox.h"
#include "engine/physics/point.h"

#include "settings/input_reader.h"

namespace Engine {

typedef std::list<Entity*> EntityStack;

typedef std::list<Point*> PointStack;

typedef std::list<sf::Drawable*> SpriteStack;

typedef std::list<Box<PhxBox>*> PhxBoxStack;

typedef std::vector<InputHandler*> InpHdlTable;

/**
 * @brief Conductor of the engine
 *
 * @details Stores all the entity and every property as a stack.
 * Then handles the iteration over every stack, at each frame,
 * of every "property system".
 *
 */
class UniverseMaster {
  public:
    UniverseMaster(/* args */) = default;

    void linkWindow(sf::RenderWindow* p_window) { this->window = p_window; };

    void addEntity(Entity* entity);

    void update();

    void
    initInput(std::list<Keybind> keybindings); // TODO : Temporary for dev,
                                               // should be initialised properly

  private:
    std::list<Keybind> keybindings;

    EntityStack allEntity;
    PointStack allPoint;
    SpriteStack allSprite;
    PhxBoxStack allPhxBox;
    InpHdlTable allInpHdl;

    void updatePoint();
    void updateEntity();
    void updateSprite();

    void readInputs();

    std::list<Intersection<PhxBox>> checkPhxCollision();

    sf::RenderWindow* window;
};

} // namespace Engine

#endif
