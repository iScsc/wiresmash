#include <chrono>
#include <thread>

#include "engine/universe_master.h"
#include "graphics/display.h"

#include "game/entity/dev/dev_entities.h"


int main(int argc, char const *argv[]){

    sf::RenderWindow window(sf::VideoMode(200, 200), "WIRESMASH");
    sf::Event event;

    UniverseMaster universe = UniverseMaster();

    universe.linkWindow(&window);

    RedSquare* dev_ett1 = new RedSquare();
    dev_ett1->setPos(100,0);
    
    universe.addEntity(dev_ett1);

    BlueTerrain* dev_ett2 = new BlueTerrain();
    universe.addEntity(dev_ett2);

    while(window.isOpen()){

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        universe.update();
    }
    return 0;
}
