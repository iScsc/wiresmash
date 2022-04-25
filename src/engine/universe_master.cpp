#include "engine/universe_master.h"

void UniverseMaster::addEntity(Entity* entity){
    this->allEntity.push_back(entity);
    Physic* physic = entity->getPhysic();
    if(physic){
        this->allPhysic.push_back(physic);
   }
}

void UniverseMaster::updateEntity(){
    for (Entity* p_entity : allEntity)
    {
        std::cout << p_entity->getName() << " ";
	std::cout << (p_entity->getPos()).second << " ";
    }
}

void UniverseMaster::updatePhysic(){
    for (Physic* p_physic : allPhysic)
    {
        std::cout << p_physic << " ";
	p_physic->update();
    }

}

void UniverseMaster::update(){
    updatePhysic();
    updateEntity();
    std::cout << "\n";
}
