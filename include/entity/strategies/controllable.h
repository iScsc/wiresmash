#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include "strategy.h"
#include <SFML/Window.hpp>

class Controllable : public virtual Strategy {
private:
    std::vector<std::pair<std::vector<unsigned short>, std::vector<std::function<void()>>>> callBacks;
public:
    Controllable(/* args */);

    ~Controllable();

    MBK
    void flush(std::array<unsigned short, MBKEY> &inputs); //flush ? events ?, receive an array of boolean (flags) representing if some keys are pressed,
    // WARNIGN needs a convention (between conductor.ControllableHandler and this class) on that boolean array

    void addCallBack(std::vector<unsigned short> inputs,
                     std::function<void()> callback); // These take effects immediatly ( independant of the MAE )


};

Controllable::Controllable(/* args */) : Strategy(/* args */)
{
    // Done
}

Controllable::~Controllable()
{
}

#endif
