#ifndef DEF_CONTROLLERHANDLER
#define DEF_CONTROLLERHANDLER

#include <SFML/Graphics.hpp>
#include "Controllable.h"

class ControllerHandler {
  public:
    ControllerHandler();
    void flush();
    ~ControllerHandler();

  private:
    Controlable[] controlables;
    int timeHeldDown;
};

#endif
