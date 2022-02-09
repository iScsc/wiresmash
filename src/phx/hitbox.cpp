#include "./../../include/phx/hitbox.h"

//----------------------------Creation de Hitbox----------------------------// (ETT conventions)

// size default value is 2
Hitbox::Hitbox(unsigned int size){
    s = size;
    tl = br = {0, -1};
}

// size default value is 2
Hitbox::Hitbox(unsigned int H[][2], unsigned int size){
    s = size;
    tl = { H[0][0], -1-H[0][1] };
    br = { H[1][0], -1-H[1][1] };
}

void Hitbox::setPoint(unsigned int i, unsigned int x, unsigned int y){
    if (i == 0){
        tl = {x, -1-y};
    } else {
        br = {x, -1-y};
    }
}

//----------------------------Obtention de Hitbox----------------------------// (phx conventions)

unsigned int Hitbox::size(){
    return s;
}

std::vector<std::pair<unsigned int, unsigned int>> Hitbox::getHitbox(){
    std::vector<std::pair<unsigned int, unsigned int>> H;
    H.push_back( std::make_pair(std::get<0>(tl), std::get<1>(br)) );
    H.push_back( std::make_pair(std::get<0>(br), std::get<1>(tl)) );
    return H;
}