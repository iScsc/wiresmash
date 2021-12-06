#ifndef WALL_H
#define WALL_H
#include "entity.h"

class Wall: Entity
{
private:
    //properties as visible, physical (can we pass through, or only some charcac ?) will be store in strategies
    
public:
    Wall(std::vector<Strategy*> strategies);// same question as character
    ~Wall();
};

// in .cpp :

Wall::Wall(/* args */)
{

}

Wall::~Wall()
{
}




#endif