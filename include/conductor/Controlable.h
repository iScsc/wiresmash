#ifndef DEF_CONTROLLABLE
#define DEF_CONTROLLABLE

#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>

class Controllable {
  public:
  Controllable();
  void keyHeldEvent(Key key, int timePressed)
  void keyNotHeldEvent(Key key, int timePressed)
  void keyPressedEvent(Key key, int timePressed)
  void keyReleasedEvent(Key key, int timePressed)
  ~Controllable();

  private:
};

#endif
