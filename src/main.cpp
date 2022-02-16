#include "entity/entity.h"
#include "entity/strategies/strategy.h"
#include <iostream>
using namespace std;

#include "entity/strategies/physical_entity.h"
#include "phx/phx.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 450), "fil rouge!");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  vector<Force> forces{Force::weight};
  std::vector<Strategy*> weightEtt = { new PhysicalEntity(forces), nullptr, nullptr};
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

    vel vel1 = updateCinematics((PhysicalEntity*) ett1->getStrategy(StrategiesID::PHYSICAL));
    ett1->addVelocity(vel1);
    vel vel2 = updateCinematics((PhysicalEntity*) ett1->getStrategy(StrategiesID::PHYSICAL));
    ett2->addVelocity(vel2);

    window.display();
  }

  return 0;
}
