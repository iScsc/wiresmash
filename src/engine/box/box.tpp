#include "engine/box/box.h"

template <typename T> 
void Box<T>::linkPos(std::pair<int, int>* pos){
    this->pos = pos;
}

template <typename T> 
void Box<T>::linkOwner(T* t){
    this->owner = t;
}