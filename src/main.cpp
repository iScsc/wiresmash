// #include <iostream>
// #include <SFML/Graphics.hpp>

// #include "entity/entity.h"
// #include "entity/strategies/strategy.h"
// #include "entity/strategies/physical_entity.h"
// #include "phx/phx.h"
// #include "phx/collision.h"

// using namespace std;

// int main() {
//   sf::RenderWindow window(sf::VideoMode(800, 450), "Wiresmash");
//   window.setVerticalSyncEnabled(true);
//   window.setFramerateLimit(60);
  
//   PhxParam light = PhxParam(1);
//   PhxParam heavy = PhxParam(10);

//   Entity *ett1 = new Entity();
//   Entity *ett2 = new Entity();
//   ett1->setStrategy(PHYSICAL, new PhysicalEntity(light));
//   ett2->setStrategy(PHYSICAL, new PhysicalEntity(heavy));

//   std::vector<Entity*> ettVect;

//   ettVect.push_back(ett1);
//   ettVect.push_back(ett2);


//   vector<Collider> collVect;
//   std::cout << "position of ett1: " << ettVect.at(0)->getPosition().x << ";" << ettVect.at(0)->getPosition().y << std::endl;
//   std::cout << "position of ett2: " << ett2->getPosition().x << ";" << ett2->getPosition().y << std::endl;
//   while (window.isOpen()) {
//     sf::Event event;
//     while (window.pollEvent(event)) {
//       switch (event.type) {
//       case sf::Event::Closed:
//         window.close();
//         break;
//       case sf::Event::KeyReleased:
//         // TODO
//         break;
//       default:
//         break;
//       }
//     }

//     // objects update.
//     window.clear(sf::Color::Black);

//     vel acc1 = updateCinematics((PhysicalEntity*) ett1->getStrategy(PHYSICAL));
//     ett1->incVelocity(acc1);
//     ett1->addVelocity();
//     vel acc2 = updateCinematics((PhysicalEntity*) ett2->getStrategy(PHYSICAL));
//     ett2->incVelocity(acc2);
//     ett2->addVelocity();
//     do
//     {
//       collVect = checkCollision(ettVect);
//       for (Collider coll : collVect)
//       {
//         cout << "Entity: " << coll.ettCollided << "is colliding with entity " << coll.ettColliding << endl;
//       }
      
      
//     } while (/*True condition : collVect.size() != 0 */ 0);
    

//     std::cout << "position of ett1: " << ettVect.at(0)->getPosition().x << ";" << ettVect.at(0)->getPosition().y << std::endl;
//     std::cout << "position of ett2: " << ett2->getPosition().x << ";" << ett2->getPosition().y << std::endl;

//     window.display();
//   }

//   printf("Mass of both entities : %d, %d \n", ((PhysicalEntity*)ettVect.at(0)->getStrategy(PHYSICAL))->getParam().mass,
//                                               ((PhysicalEntity*)ettVect.at(1)->getStrategy(PHYSICAL))->getParam().mass);

//   return 0;
// }

#include "engine/universe_master.h"

int main(int argc, char const *argv[])
{
  UniverseMaster universe = UniverseMaster();
  Entity* entity1 = new Entity("Oui");
  Entity entity2("Non");
  universe.addEntity(entity1);
  universe.addEntity(&entity2);
  universe.updateEntity();
  return 0;
}
