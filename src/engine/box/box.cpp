#include "engine/box/box.h"

void Box::linkPos(std::pair<int, int>* pos){
    this->pos = pos;
}

void Box::linkEntity(Entity* ett){
    this->owner = ett;
}