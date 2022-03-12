#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include "entity/strategies/strategy.h"

class Schedulable : public virtual Strategy //schedulable is useless right now we'll think it later
{
private:
    std::multimap<int, std::function<void ()>> actions; // actions to do at a given frame (contains a frame and a function to call)
    
public:


    
    void update(int frame);

    void addAction(int frame, std::function<void()> action);


    Schedulable(/* args */);
    ~Schedulable();
};

Schedulable::Schedulable(/* args */) : Strategy(/* args */)
{
    // Done for now
}

Schedulable::~Schedulable()
{
}






#endif