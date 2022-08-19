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

    universe.addEntity(entity1);
    universe.addEntity(entity2);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while(window.isOpen()){

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        universe.update();
    }
    return 0;
}
