#include "engine/universe_master.h"

void UniverseMaster::addEntity(Entity *entity)
{
    this->allEntity.push_back(entity);
    Physic *physic = entity->getPhysic();
    sf::Drawable *sprite = entity->getSprite();
    Box* hitbox = entity->getHitbox();
    if (physic)
    {
        this->allPhysic.push_back(physic);
    }
    if (sprite)
    {
        this->allSprite.push_back(sprite);
    }
    if (hitbox)
    {
        this->allHitbox.push_back(hitbox);
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

std::list<Collision> UniverseMaster::checkCollision()
{
    std::list<Collision> allCollision;
    Collision cur_coll;
    for (HitboxStack::iterator it = allHitbox.begin(); it != allHitbox.end()--; ++it)
    {
        for (HitboxStack::iterator it2 = std::next(it); it2 != allHitbox.end(); ++it2)
        {
            cur_coll = (*it)->checkCollision(*it2);
            if (cur_coll.ettColliding == NULL)
            {
                std::cout << "No collision between " << (*it)->getOwner()->getName() << " and " << (*it2)->getOwner()->getName() << "\n";
            }
            else{
                std::cout << "Collision between " << (*it)->getOwner()->getName() << " and " << (*it2)->getOwner()->getName() << " ";
                std::cout << "EttColliding" << cur_coll.ettColliding->getName() << ";ColVect" << cur_coll.collisionVector.first << "," << cur_coll.collisionVector.second << "\n";
                allCollision.push_back(cur_coll);
            }
        }
        
    }
    return allCollision;
}

void UniverseMaster::update()
{
    this->window->clear();

    updatePhysic();
    checkCollision();

    updateEntity();
    updateSprite();
    std::cout << "\n";
    this->window->display();
}
