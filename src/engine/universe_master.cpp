#include "engine/universe_master.h"

void UniverseMaster::addEntity(Entity* entity){
    this->allEntities.push_back(entity);
}

void UniverseMaster::updateEntity(){
    for (Entity* p_entity : allEntities)
    {
        std::cout << p_entity->getName() << " ";
    }
    std::cout << "\n";
    
}