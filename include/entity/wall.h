#ifndef WALL_H
#define WALL_H
#include "drawable_handler.h"
#include "physical_entity.h"



class Wall: DrawableHandler, Physical_entity
{
private:
    /* data */
public:
    Wall(/* args */);
    ~Wall();
};

Wall::Wall(/* args */)
{
}

Wall::~Wall()
{
}




#endif