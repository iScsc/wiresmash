#ifndef DEF_CONTROLLABLE
#define DEF_CONTROLLABLE

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class Controllable {
  public:
  Controllable();
  void keyHeldEvent(sf::Keyboard::Key key, int timePressed);
  void keyNotHeldEvent(sf::Keyboard::Key key, int timePressed);
  void keyPressedEvent(sf::Keyboard::Key key, int timePressed);
  void keyReleasedEvent(sf::Keyboard::Key key, int timePressed);
  ~Controllable();

  private:
};

#endif
