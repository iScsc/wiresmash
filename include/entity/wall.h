#ifndef WALL_H
#define WALL_H
#include "entity.h"
#include "strategies/multi_drawable.h"
#include "strategies/physical_entity.h"

class Wall: Entity
{
private:
    std::vector<Strategy*> generateDefaultStrategies();
    //properties as visible, physical (can we pass through, or only some charcac ?) will be store in strategies
    
public:
    Wall();
    Wall(std::vector<Strategy*> strategies);// same question as character
    ~Wall();
};

// in .cpp :

std::vector<Strategy*> generateDefaultStrategies() {
    std::vector<Strategy*> vec;
    vec.push_back(new MultiDrawable());
    vec.push_back(new PhysicalEntity());
    return vec;
}

Wall::Wall() : Wall(Wall::generateDefaultStrategies()) {}
Wall::Wall(std::vector<Strategy*> strategies) : Entity(strategies) {}

Wall::~Wall()
{
}




#endif