#include "engine/hitbox/line.h"

LineHitbox::LineHitbox(point a){
    LineHitbox(point(0, 0), a);
}
LineHitbox::LineHitbox(point a, point b){
    this->relVertices.push_back(a);
    this->relVertices.push_back(b);
}

HLineHitbox::HLineHitbox(int length){
    HLineHitbox(0, length, 0);
}
HLineHitbox::HLineHitbox(int x1, int x2, int y){
    LineHitbox(point(x1, y), point(x1, y));
}

VLineHitbox::VLineHitbox(int height){
    VLineHitbox(0, height, 0);
}
VLineHitbox::VLineHitbox(int y1, int y2, int x){
    LineHitbox(point(x, y1), point(x, y2));
}

// TODO : Collisions btwn lines, line and rectangle
Collision VLineHitbox::checkCollision(Rectangle* r){
    Collision coll = Collision();
    return coll;
}

Collision HLineHitbox::checkCollision(Rectangle* r){
    Collision coll = Collision();
    return coll;
}

Collision LineHitbox::checkCollision(LineHitbox* l){
    Collision coll = Collision();
    return coll;
}