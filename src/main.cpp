#include <chrono>
#include <thread>

#include "engine/universe_master.h"
#include "graphics/display.h"

int main(int argc, char const *argv[]){

    sf::RenderWindow window(sf::VideoMode(200, 200), "WIRESMASH");
    sf::Event event;

    UniverseMaster universe = UniverseMaster();

    universe.linkWindow(&window);

    Entity *entity1 = new Entity("Oui");
    entity1->addPhysic();
    entity1->getPhysic()->setMass(1);

    Entity *entity2 = new Entity("Non");
    entity2->addSprite();
    entity2->addPhysic();
    entity2->getPhysic()->setMass(1);

    universe.addEntity(entity1);
    universe.addEntity(entity2);


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
