#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Conductor.h"


int main(){
  sf::RenderWindow window(sf::VideoMode(800, 450), "fil rouge!");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

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

    // objects update.
    conductor.flush()
    window.clear(sf::Color::Black);
    // TODO
    window.display();
  }
  
  return 0;
}

