#include "graphics/display.h"

sf::RenderWindow initGraphicsWindow(std::string windowName){
    sf::RenderWindow window(sf::VideoMode(200, 200), windowName);
    return window;
}