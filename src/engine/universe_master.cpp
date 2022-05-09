#include "engine/universe_master.h"

void UniverseMaster::addEntity(Entity *entity)
{
    this->allEntity.push_back(entity);
    Physic *physic = entity->getPhysic();
    sf::Drawable *sprite = entity->getSprite();
    if (physic)
    {
        this->allPhysic.push_back(physic);
    }
    if (sprite)
    {
        this->allSprite.push_back(sprite);
    }
}

void UniverseMaster::updateEntity()
{
    for (Entity *p_entity : allEntity)
    {
        std::cout << p_entity->getName() << " ";
        std::cout << (p_entity->getPos()).second << " ";

        //TEMPORARY
        if(p_entity->getSprite())
        {
            ((sf::CircleShape*) p_entity->getSprite())->setPosition(p_entity->getPos().first, p_entity->getPos().second);
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


void UniverseMaster::update()
{
    this->window->clear();
    updatePhysic();
    updateEntity();
    updateSprite();
    std::cout << "\n";
    this->window->display();
}
