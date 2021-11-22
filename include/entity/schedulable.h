#ifndef SCHEDULABLE.H
#define SCHEDULABLE.H
#include <queue>
#include <functional>
#include <map>

class Schedulable
{
private:

    std::multimap<int, std::function<void ()> > actions; // actions to do at a given frame (contains a frame and a function to call)
    // Maybe a Circular buffer would be better ?
public:


    
    void update(int frame)
    /*
    {

        if(actions.count(frame) > 0){

            for(std::function<void()> currentAction : (actions.find(frame)) ){

            }
        }
        
    } */; // call this one each frame

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