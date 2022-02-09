#include <SFML/Graphics.hpp>
#include "phx/collision.h"
#include <vector>
#include <iostream>

int main(){

    //sf::Window window(sf::VideoMode(600, 600), "Debug Window");
    //Creates a hitbox in 0, 0 upto 5, 5; square
    Hitbox hbx1 = Hitbox(0, 0, 5, 5);
    //Another one in 4,4 upto 10, 10;
    Hitbox hbx2 = Hitbox(4, 4, 6, 6);

    Entity ett1 = Entity(hbx1);
    Entity ett2 = Entity(hbx2);
    std::vector<Entity> vectEnt;
    vectEnt.push_back(ett1);
    vectEnt.push_back(ett2);
    std::vector<Collider> collVect = checkCollision(vectEnt);
    printf("On axis x : %d \n", collVect.at(0).colVector.first);
    printf("On axis y : %d \n", collVect.at(0).colVector.second);
    return 0;
}