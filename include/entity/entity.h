#ifndef ENTITY_H
#define ENTITY_H

#include "strategies/strategy.h"
#include <vector>

class Entity //maybe virtual class ? let's see if this is useful or not later
{
private:
    std::vector<Strategy *> strategies; //basic attribute of an Entity

public:
    const static int PHYSICAL = 0;
    const static int DRAWABLE = 1;

    const bool hasStrategy(int strategy);

    void addStrategies(Strategy *strat);

    void eraseStrategies(int index);

    void eraseStrategies(int indexFirst, int indexLast);

    Entity(std::vector<Strategy *> strategies); //basic constructor
    ~Entity();
};

#endif
