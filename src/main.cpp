#include <chrono>
#include <thread>

#include "engine/universe_master.h"
#include "graphics/display.h"

#include "game/entity/dev/red_square.h"
#include "engine/hitbox/rectangle.h"

int main(int argc, char const *argv[]){

    sf::RenderWindow window(sf::VideoMode(200, 200), "WIRESMASH");
    sf::Event event;

    UniverseMaster universe = UniverseMaster();

    universe.linkWindow(&window);

    RedSquare* dev_ett1 = new RedSquare();
    dev_ett1->addHitbox(new Rectangle(10,10));

    universe.addEntity(dev_ett1);
    // universe.addEntity(entity2);

    Entity* rect1 = new Entity("Square1");
    rect1->setPos(std::pair<int, int>(13, -39));
    rect1->addHitbox(new Rectangle(5,5));
    sf::RectangleShape r1 = sf::RectangleShape(sf::Vector2f(5,5));
    rect1->addSprite(&r1);

    Entity* rect2 = new Entity("Square2");
    rect2->setPos(std::pair<int, int>(9, -40));
    rect2->addHitbox(new Rectangle(5,5));
    sf::RectangleShape r2 = sf::RectangleShape(sf::Vector2f(5,5));
    r2.setFillColor(sf::Color(0,255,0));
    rect2->addSprite(&r2);


    universe.addEntity(rect1);
    universe.addEntity(rect2);

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
