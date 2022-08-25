#include "engine/hitbox/hitbox.h"

void Hitbox::linkPos(std::pair<int, int>* pos){
    this->pos = pos;
}

void Hitbox::linkEntity(Entity* ett){
    this->owner = ett;
}