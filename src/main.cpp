#include <chrono>
#include <thread>

#include "engine/universe_master.h"
#include "graphics/display.h"

#include "game/entity/dev/dev_entities.h"

#include "settings/input_reader.h"

int main(int argc, char const *argv[]){

    sf::RenderWindow window(sf::VideoMode(200, 200), "WIRESMASH");
    sf::Event event;

    Engine::UniverseMaster universe = Engine::UniverseMaster();
    universe.linkWindow(&window);
    universe.initInput(make_keybinds("../settings/keybinds"));

    RedSquare* dev_ett1 = new RedSquare(10);
    dev_ett1->setPos(100,0);
    
    universe.addEntity(dev_ett1);

    RedSquare* dev_ett3 = new RedSquare(10);
    dev_ett3->setPos(100,0);
    universe.addEntity(dev_ett3);

    BlueTerrain* dev_ett2 = new BlueTerrain();
    universe.addEntity(dev_ett2);
    // std::this_thread::sleep_for(std::chrono::seconds(4));
    int i = 0;
    while(window.isOpen()){

        while (window.pollEvent(event)){
            switch (event.type)
            {
            case sf::Event::Closed :
                window.close();
                break;

            case sf::Event::LostFocus:
                //TODO : implement proper pause
                while (window.pollEvent(event) || event.type != sf::Event::GainedFocus)
                {
                }
            default:
                break;
            }
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
        universe.update();
    }
    return 0;
}
