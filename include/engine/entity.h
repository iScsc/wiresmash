/**
 * @file entity.h
 * @author Grégory Brivady
 * @brief Master object of the game
 * @version 0.1
 * @date 2022-12-03
 *
 *
 */
#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <vector>





#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "engine/box/box.h"
#include "engine/physics/phxbox.h"
#include "engine/physics/point.h"

namespace Engine {

class InputHandler;

/**
 * @brief An entity is an object that exists in the game universe.
 *
 * @details This class both links to all the properties of an object,
 * but also handles interfacing between the properties. Each property is stored
 * as a pointer. To add a property to an entity, one should use the add
 * functions, and once everything is initialised, the entity can be added to the
 * universe.
 *
 */
class Entity {
  public:
    Entity();
    Entity(std::string name);
    ~Entity() = default;

    void addPoint();
    Point* getPoint();

    void addSprite();
    void addSprite(sf::Drawable*);
    sf::Drawable* getSprite();

    /**
     * @brief Add physical collision to the entity
     *
     * @param box the box containing the entity
     * @param ct behaviour of the entity, as a an object that can collide
     */
    void addPhxBox(Box<PhxBox>* box, PhxBox::CollisionBehaviour ct);
    PhxBox* getPhxBox();

    std::string getName() { return name; };

    void setPos(double x, double y) { pos = std::make_pair(x, y); };
    void setPos(std::pair<double, double> pos) { this->pos = pos; };
    std::pair<double, double> getPos() { return pos; };

    void setVel(double vx, double vy) { vel = std::make_pair(vx, vy); };
    void setVel(std::pair<double, double> vel) { this->vel = vel; };
    std::pair<double, double> getVel() { return vel; };

    virtual void collPhxNotify(Entity* ett){};

    InputHandler* getInputHandler() { return inputHandler; };
    void move(double dx, double dy);
    void addInputHandler(InputHandler* i) { this->inputHandler = i; };

  private:
    // Coordinates
    std::pair<double, double> pos;
    std::pair<double, double> vel;
    // Name
    std::string name;
    // Point
    Point* point;
    // Displaying
    sf::Drawable* sprite;

    // --- Boxes --- //
    // Pushboxes
    PhxBox* phxbox;
    // Dangerous adder, so stocked here for now
    void addPhxBox(PhxBox* pb);

    // --- Controls --- //
    InputHandler* inputHandler;
};

} // namespace Engine

#endif
