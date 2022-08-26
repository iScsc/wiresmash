#ifndef ENGINE_HITBOX_LINE_H

#define ENGINE_HITBOX_LINE_H

#include "engine/hitbox/hitbox.h"
#include "engine/hitbox/rectangle.h"

class LineHitbox : public Hitbox
{
private:
    /* data */
public:
    LineHitbox() = default;
    LineHitbox(point a);
    LineHitbox(point a, point b);
    ~LineHitbox() = default;
    Collision checkCollision(Hitbox* h) override {return h->checkCollision(this);};
    Collision checkCollision(Rectangle* );
    Collision checkCollision(LineHitbox* );
};

class HLineHitbox : public LineHitbox
{
public:
    HLineHitbox(int length);
    HLineHitbox(int x1, int x2, int y);
    Collision checkCollision(Rectangle* );
};

class VLineHitbox : public LineHitbox
{
public:

    VLineHitbox(int height);
    VLineHitbox(int y1, int y2, int x);
    Collision checkCollision(Rectangle* );
};

#endif