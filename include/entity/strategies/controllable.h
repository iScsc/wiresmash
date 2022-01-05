#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include "strategy.h"
#include <SFML/Window.hpp>

class Controllable : public virtual Strategy
{
private:
    
public:
    Controllable(/* args */);
    ~Controllable();

    void flush(std::vector<unsigned short> &inputs); //flush ? events ?, receive an array of boolean (flags) representing if some keys are pressed, 
    // WARNING needs a convention (between conductor.ControllableHandler and this class) on that boolean array
};

Controllable::Controllable(/* args */) : Strategy(/* args */)
{
    // Done
}

Controllable::~Controllable()
{
}







#endif
