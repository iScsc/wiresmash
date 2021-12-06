#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include "strategy.h"
#include <queue>
#include <functional>
#include <map>

class Schedulable : public virtual Strategy //schedulable is useless right now we'll think it later
{
private:

    std::multimap<int, std::function<void ()> > actions; // actions to do at a given frame (contains a frame and a function to call)
    
public:


    
    void update(int frame);

    void addAction(int frame, std::function<void()> action);


    Schedulable(/* args */);
    ~Schedulable();
};

Schedulable::Schedulable(/* args */)
{
}

Schedulable::~Schedulable()
{
}






#endif