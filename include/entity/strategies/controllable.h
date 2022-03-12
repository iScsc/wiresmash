#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include <SFML/Window.hpp>
#include "lib/lib.h"
#include "entity/strategies/strategy.h"

typedef unsigned short key;

using namespace std;

class Controllable : public virtual Strategy {
private:
    vector<pair<key, void (*)() > > callBacks;
public:
    Controllable(/* args */);

    ~Controllable();

    void flush(std::array<key, NB_KEYS>); 
    //receives an array of boolean (flags) representing if some keys are pressed
    // WARNIGN needs a convention (between conductor.ControllableHandler and this class) on that boolean array

    void Controllable::addCallBack(key input, void (*callBackFunc)()); 
    void Controllable::deleteCallBack(key input);
    void Controllable::modifyCallBack_by_Key(key old_input, key new_input);
    void Controllable::modifyCallBack_by_Func(void (*callBackFunc_toModify)(), key new_input);

};

#endif
