#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "conductor/Conductor.h"
#include "entity/Character.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 450), "fil rouge!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    vector<Force> forces {Force::weight};
    PhysicalEntity ett1 = PhysicalEntity(forces);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    // TODO
                    break;
                default:
                    break;
            }
        }

  Conductor conductor;

  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      switch (event.type){
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyReleased:
          // TODO
          break;
        default:
          break;
      }
    }
    
    return 0;
}

