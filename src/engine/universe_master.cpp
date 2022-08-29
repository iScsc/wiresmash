#include "engine/universe_master.h"
#include <chrono>
#include <thread>
void UniverseMaster::addEntity(Entity *entity)
{
    this->allEntity.push_back(entity);
    Physic *physic = entity->getPhysic();
    sf::Drawable *sprite = entity->getSprite();
    PhxBox* phxbox = entity->getPhxBox();
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
    
}

void UniverseMaster::updateEntity()
{
    for (Entity *p_entity : allEntity)
    {
        std::cout << p_entity->getName() << " ";
        std::cout << (p_entity->getPos()).second << " ";

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

std::list<Collision<PhxBox>> UniverseMaster::checkPhxCollision()
{
    std::list<Collision<PhxBox>> allPhxCollision;
    Collision<PhxBox> cur_coll;
    for (PhxBoxStack::iterator it = allPhxBox.begin(); it != allPhxBox.end()--; ++it)
    {
        for (PhxBoxStack::iterator it2 = std::next(it); it2 != allPhxBox.end(); ++it2)
        {
            cur_coll = (*it)->checkCollision(*it2);
            if (cur_coll.colliding == NULL)
            {
                // std::cout << "No collision between " << (*it)->getOwner()->getName() << " and " << (*it2)->getOwner()->getName() << "\n";
            }
            else{
                std::cout << "Collision " << std::endl;
                // std::cout << "EttColliding" << cur_coll.colliding->getName() << ";ColVect" << cur_coll.collisionVector.first << "," << cur_coll.collisionVector.second << "\n";
                allPhxCollision.push_back(cur_coll);
            }
        }
        
    }
    return allPhxCollision;
}

void UniverseMaster::update()
{
    this->window->clear();

    updatePhysic();
    std::list<Collision<PhxBox>> allPhxCollision;
    do
    {
        allPhxCollision = checkPhxCollision();
        for (Collision<PhxBox> coll_pb : allPhxCollision)
        {
            // std::cout << coll_pb.colliding->getOwner()->getName() << " with " << coll_pb.collided->getOwner()->getName() <<std::endl;
            // std::cout << coll_pb.colliding->getOwner()->getPos().first << " " << coll_pb.colliding->getOwner()->getPos().second << std::endl;
            coll_pb.colliding->solveCollision(coll_pb);
            // coll_pb.colliding->getOwner()->collPhxNotify(coll_pb.collided->getOwner());
            coll_pb.colliding->solveCollision(coll_pb);
            // coll_pb.colliding->getOwner()->collPhxNotify(coll_pb.collided->getOwner());
        }
    } while (!allPhxCollision.empty());
    updateEntity();
    updateSprite();
    std::cout << "\n";
    this->window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
