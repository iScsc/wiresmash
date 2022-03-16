#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>

#define NB_STRATEGY 3

enum StrategiesID {
    DRAWABLE = 0, PHYSICAL = 1, DAMAGEABLE = 2
};

class Strategy 
//For now Strategy seems only a polymorphic-class, usefull only to store every strategies.
//we'll have to think how we want to use strategies, because if they're all stored as Strategy
//we can't write strategies.get(0).aMethodFromPhysicalEntity() because strategies.get(0) is of type Strategy,
//maybe a method in Strategy that return the type of the object(Physical, Drawable,..) or directly return the object ?
//there is to be discussed here
{
private:
    /* data */
public:
    Strategy(/* args */);
    ~Strategy();
};

std::vector<Strategy*> emptyStrHdl();

#endif