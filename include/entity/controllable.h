#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include "entity.h"
#include <SFML/Window.hpp>



class Controllable : public virtual Entity
{
private:
    
public:
    Controllable(/* args */);
    ~Controllable();

    virtual void sendEvent(sf::Event e);

};

Controllable::Controllable(/* args */)
{
}

Controllable::~Controllable()
{
}







#endif