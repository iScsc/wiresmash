
#include "entity/strategies/controllable.h"

using namespace std;

Controllable::Controllable(/* args */) {
}

Controllable::~Controllable() {
}


void Controllable::addCallBack(unsigned short input, void (*callBackFunc)()) {

    callBacks.push_back(make_pair(input, callBackFunc));
}

void Controllable::deleteCallBack(key input){
    // TODO : remplacer par une liste
    for(int i = 0; i < callBacks.size(); i++){
        if(callBacks.at(i).first == input){
            callBacks.erase(callBacks.begin()+i);
            return;
        }
    }
    printf("[X] Key n°%d not found in CallBacks",input);
    return;
}
/*
void Controllable::modifyCallBack_by_Key(key old_input, key new_input);
void Controllable::modifyCallBack_by_Func(void (*callBackFunc_toModify)(), key new_input);
*/
void Controllable::flush(std::array<key, NB_KEYS> inputs){

    for(int j = 0; j < inputs.size(); j++){
        for (int i = 0; i < callBacks.size(); i++){
            if(callBacks.at(i).first == inputs.at(j)){
                (*callBacks.at(i).second)();
                return;
            }
        }
    }
    
    

}
