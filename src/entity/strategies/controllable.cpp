
#include "../../../include/entity/strategies/controllable.h"


Controllable::Controllable(/* args */) {
}

Controllable::~Controllable() {
}


void Controllable::addCallBack(std::vector<unsigned short> inputs, std::function<void()> callback) {

    for (int i = 0; i < callBacks.size(); i++) {
        if (callBacks[i].first == inputs) { /// adds the callback to the callBacks Vector
            callBacks[i].second.emplace_back(callback);
            return;
        }
    }


    std::pair<std::vector<unsigned short>, std::function<void()> > a = std::pair<std::vector<unsigned short>, std::function<void()>>(
            inputs, callback);

    callBacks.emplace_back(a);
    
}

void Controllable::flush(std::vector<unsigned short> &inputs){

    // Calls all callback functions ( without MAE)
    for (int i = 0; i < callBacks.size(); i++)
    {
        if(callBacks[i].first == inputs){
            for (int j = 0; j < callBacks[i].second.size(); i++)
            {
                callBacks[i].second[j](); // flushes Every Callbacks
            }
            break;
        }
    }
    
    

}
