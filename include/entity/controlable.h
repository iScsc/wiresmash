#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include <SFML/Window.hpp>


class Controllable
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