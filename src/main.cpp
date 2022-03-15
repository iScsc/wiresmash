#include <iostream>
#include <SFML/Graphics.hpp>

#include "entity/entity.h"
#include "entity/strategies/strategy.h"
#include "entity/strategies/physical_entity.h"
#include "phx/phx.h"

using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 450), "Wiresmash");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  PhxParam param = PhxParam(1);
  std::vector<Strategy*> weightEtt = { nullptr, new PhysicalEntity(param), nullptr}; // TODO so ugly
  Entity *ett1 = new Entity(weightEtt);
  Entity *ett2 = new Entity(weightEtt);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
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
    window.clear(sf::Color::Black);

    vel acc1 = updateCinematics((PhysicalEntity*) ett1->getStrategy(PHYSICAL));
    ett1->incVelocity(acc1);
    ett1->addVelocity();
    vel acc2 = updateCinematics((PhysicalEntity*) ett2->getStrategy(PHYSICAL));
    ett2->incVelocity(acc2);
    ett2->addVelocity();
    
    std::cout << "position of ett1: " << ett1->getPosition().x << ";" << ett1->getPosition().y << std::endl;
    std::cout << "position of ett2: " << ett2->getPosition().x << ";" << ett2->getPosition().y << std::endl;

    window.display();
  }

  return 0;
}
