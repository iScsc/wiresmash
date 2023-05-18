/**
 * @file input_handler.h
 * @author Grégory Brivady
 * @brief Handle key input
 * @version 0.1
 * @date 2022-12-04
 *
 *
 */
#ifndef ENGINE_INPUT_INPUT_HANDLER_H
#define ENGINE_INPUT_INPUT_HANDLER_H

#include <SFML/Window/Keyboard.hpp>

#include "engine/entity.h"

namespace Engine {

struct UniversalInput {
    int handlerId;
    int inputId;
};

struct Keybind {
    sf::Keyboard::Key key;
    UniversalInput action;
};

/**
 * @brief Translates sfml keys to game actions
 *
 */
class InputHandler {
  public:
    InputHandler(/* args */) = default;
    ~InputHandler() = default;
    void setOwner(Entity* entity) { this->owner = entity; };
    virtual void doInput(int actionId){};

  protected:
    Entity* owner;

  private:
    int start_action_id;
};

} // namespace Engine

#endif