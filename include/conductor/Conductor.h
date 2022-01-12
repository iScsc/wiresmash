#ifndef DEF_CONDUCTOR
#define DEF_CONDUCTOR

#include <SFML/Graphics.hpp>
#include "Controllable.h"

class Conductor {
  public:
    Conductor();
    void flush();
    Controllable* getEntities();
    ~Conductor();

  private:
};

#endif
