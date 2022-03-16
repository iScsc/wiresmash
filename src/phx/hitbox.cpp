#include "phx/hitbox.h"
#include <climits>

//----------------------------Creation de Hitbox----------------------------// (ETT conventions)

// size default value is 2
Hitbox::Hitbox(){
    s = 2;
    tl = br = {0, 0};
}

// size default value is 2
Hitbox::Hitbox(unsigned int H[][2], unsigned int size){
    s = size;
    tl = { H[0][0], UINT_MAX-H[0][1] };
    br = { H[1][0], UINT_MAX-H[1][1] };
}

void Hitbox::setPoint(unsigned int i, unsigned int x, unsigned int y){
    if (i == 0){
        tl = {x, UINT_MAX-y};
    } else {
        br = {x, UINT_MAX-y};
    }
}

//----------------------------Obtention de Hitbox----------------------------// (phx conventions)

unsigned int Hitbox::size(){
    return s;
}

std::vector<pos> Hitbox::getHitbox(){
    std::vector<pos> H;
    H.push_back(pos(tl.x, br.y) );
    H.push_back(pos(br.x, tl.y) );
    return H;
}
