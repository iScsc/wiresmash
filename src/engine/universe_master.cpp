#include "engine/universe_master.h"

#include <chrono>
#include <thread>

using namespace Engine;

Engine::UniverseMaster::~UniverseMaster() {
    for (Entity* entity : this->allEntity) {
        delete entity;
    }
    for (InputHandler* handle : this->allInpHdl) {
        delete handle;
    }
}

void Engine::UniverseMaster::addEntity(Entity* entity) {
    this->allEntity.push_back(entity);
    Point* point = entity->getPoint();
    sf::Drawable* sprite = entity->getSprite();
    PhxBox* phxbox = entity->getPhxBox();
    InputHandler* inphdl = entity->getInputHandler();
    if (point) {
        this->allPoint.push_back(point);
    }
    if (sprite) {
        this->allSprite.push_back(sprite);
    }
    if (phxbox) {
        this->allPhxBox.push_back(phxbox->getBox());
    }
    if (inphdl) {
        this->allInpHdl.push_back(inphdl);
    }
}

void Engine::UniverseMaster::updateEntity() {
    for (Entity* p_entity : allEntity) {
        // TODO: TEMPORARY
        if (p_entity->getSprite()) {
            ((sf::CircleShape*)p_entity->getSprite())
                ->setPosition(p_entity->getPos().first,
                              -p_entity->getPos().second);
        }
    }
}

void Engine::UniverseMaster::updatePoint() {
    for (Point* p_physic : allPoint) {
        p_physic->update();
    }
}

void Engine::UniverseMaster::updateSprite() {
    for (sf::Drawable* p_sprite : allSprite) {
        this->window->draw(*p_sprite);
    }
}

void Engine::UniverseMaster::readInputs() {
    for (Keybind bind : keybindings) {
        if (sf::Keyboard::isKeyPressed(bind.key) &&
            bind.action.handlerId < allInpHdl.size()) {
            allInpHdl.at(bind.action.handlerId)->doInput(bind.action.inputId);
        }
    }
}

std::list<Intersection<PhxBox>> Engine::UniverseMaster::checkPhxCollision() {
    std::list<Intersection<PhxBox>> allPhxCollision;
    Intersection<PhxBox> cur_coll;
    for (PhxBoxStack::iterator it = allPhxBox.begin(); it != allPhxBox.end()--;
         ++it) {
        for (PhxBoxStack::iterator it2 = std::next(it); it2 != allPhxBox.end();
             ++it2) {
            cur_coll = (*it)->checkIntersection(*it2);
            if (cur_coll.intersecting != NULL) {
                allPhxCollision.push_back(cur_coll);
            }
        }
    }
    return allPhxCollision;
}

void Engine::UniverseMaster::update() {
    this->window->clear();
    readInputs();
    updatePoint();
    std::list<Intersection<PhxBox>> allPhxCollision;
    do {
        allPhxCollision = checkPhxCollision();
        for (Intersection<PhxBox> coll_pb : allPhxCollision) {
            coll_pb.intersecting->solveCollision(coll_pb);
            coll_pb.intersecting->solveCollision(coll_pb);
        }
    } while (!allPhxCollision.empty());
    updateEntity();
    updateSprite();
    this->window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

void Engine::UniverseMaster::initInput(std::list<Keybind> keybindings) {
    this->keybindings = keybindings;
}