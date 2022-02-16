#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "phx/phx.h"
#include "lib/forces.h"
class PhysicalEntity
{
public :
    vector<Force> forces;
    pos position;
    vector<Force> getForces();
    PhysicalEntity(vector<Force>);
}


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

        // objects update.
        window.clear(sf::Color::Black);
        // TODO
        vel velocity = updateCinematics(&ett1);
        window.display();
    }
    
    return 0;
}

