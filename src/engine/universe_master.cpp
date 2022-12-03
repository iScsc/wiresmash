#include "engine/universe_master.h"
#include <chrono>
#include <thread>
void UniverseMaster::addEntity(Entity *entity)
{
    this->allEntity.push_back(entity);
    Physic *physic = entity->getPhysic();
    sf::Drawable *sprite = entity->getSprite();
    PhxBox* phxbox = entity->getPhxBox();
    InputHandler* inphdl = entity->getInputHandler();
    if (physic)
    {
        this->allPhysic.push_back(physic);
    }
    if (sprite)
    {
        this->allSprite.push_back(sprite);
    }
    if (phxbox)
    {
        this->allPhxBox.push_back(phxbox->getBox());
    }
    if (inphdl)
    {
        this->allInpHdl.push_back(inphdl);
    }
    
}

void UniverseMaster::updateEntity()
{
    for (Entity *p_entity : allEntity)
    {
        // std::cout << p_entity->getName() << " ";
        // std::cout << (p_entity->getPos()).second << " ";

        //TODO: TEMPORARY
        if(p_entity->getSprite())
        {
            ((sf::CircleShape*) p_entity->getSprite())->setPosition(p_entity->getPos().first, -p_entity->getPos().second);
        }
    }
}

void UniverseMaster::updatePhysic()
{
    for (Physic *p_physic : allPhysic)
    {
        p_physic->update();
    }
}

void UniverseMaster::updateSprite()
{
    for (sf::Drawable* p_sprite : allSprite)
    {
        this->window->draw(*p_sprite);
    }
}

void UniverseMaster::readInputs(){
    for (Keybind bind : keybindings)
    {
        if (sf::Keyboard::isKeyPressed(bind.key) && bind.action.handlerId < allInpHdl.size())
        {
            std::cout << "Input " << bind.action.inputId << " to Handler " << bind.action.handlerId << "\n";
            allInpHdl.at(bind.action.handlerId)->doInput(bind.action.inputId);            
        }
        
    }
    
}

std::list<Intersection<PhxBox>> UniverseMaster::checkPhxCollision()
{
    std::list<Intersection<PhxBox>> allPhxCollision;
    Intersection<PhxBox> cur_coll;
    for (PhxBoxStack::iterator it = allPhxBox.begin(); it != allPhxBox.end()--; ++it)
    {
        for (PhxBoxStack::iterator it2 = std::next(it); it2 != allPhxBox.end(); ++it2)
        {
            cur_coll = (*it)->checkIntersection(*it2);
            if (cur_coll.intersecting == NULL)
            {
                // std::cout << "No collision between " << (*it)->getOwner()->getName() << " and " << (*it2)->getOwner()->getName() << "\n";
            }
            else{
                std::cout << "Intersection " << std::endl;
                // std::cout << "EttColliding" << cur_coll.intersecting->getName() << ";ColVect" << cur_coll.intersectionVector.first << "," << cur_coll.intersectionVector.second << "\n";
                allPhxCollision.push_back(cur_coll);
            }
        }
        
    }
    return allPhxCollision;
}

void UniverseMaster::update()
{
    this->window->clear();
    readInputs();
    updatePhysic();
    std::list<Intersection<PhxBox>> allPhxCollision;
    do
    {
        allPhxCollision = checkPhxCollision();
        for (Intersection<PhxBox> coll_pb : allPhxCollision)
        {
            // std::cout << coll_pb.intersecting->getOwner()->getName() << " with " << coll_pb.intersected->getOwner()->getName() <<std::endl;
            // std::cout << coll_pb.intersecting->getOwner()->getPos().first << " " << coll_pb.intersecting->getOwner()->getPos().second << std::endl;
            coll_pb.intersecting->solveCollision(coll_pb);
            // coll_pb.intersecting->getOwner()->collPhxNotify(coll_pb.intersected->getOwner());
            coll_pb.intersecting->solveCollision(coll_pb);
            // coll_pb.intersecting->getOwner()->collPhxNotify(coll_pb.intersected->getOwner());
        }
    } while (!allPhxCollision.empty());
    updateEntity();
    updateSprite();
    std::cout << "\n";
    this->window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

void UniverseMaster::initInput(){
    std::list<Keybind> keybindings;
    keybindings.push_back(Keybind{sf::Keyboard::Key::W, UniversalInput{0, 0}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::A, UniversalInput{0, 1}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::S, UniversalInput{0, 2}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::D, UniversalInput{0, 3}});

    keybindings.push_back(Keybind{sf::Keyboard::Key::I, UniversalInput{1, 0}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::J, UniversalInput{1, 1}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::K, UniversalInput{1, 2}});
    keybindings.push_back(Keybind{sf::Keyboard::Key::L, UniversalInput{1, 3}});

    this->keybindings = keybindings;
}