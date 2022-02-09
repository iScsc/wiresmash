#ifndef STRATEGY_H
#define STRATEGY_H

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

Strategy::Strategy(/* args */)
{
    // Nothing to do
}

#endif
