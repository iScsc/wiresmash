#ifndef DEF_CONDUCTOR
#define DEF_CONDUCTOR

#include <SFML/Graphics.hpp>
#include "conductor/ControllerHandler.h"
#include "conductor/ScheduleHandler.h"
#include "conductor/PhysicsHandler.h"
#include "conductor/DrawHandler.h"
#include "conductor/AudioHandler.h"

class Conductor {
  public:
    Conductor();
    void flush();
    Controlable[] getEntities();
    ~Conductor();

  private:
    ControllerHandler controllerHandler;
    ScheduleHandler scheduleHandler;
    PhysicsHandler physicsHandler;
    DrawHandler drawHandler;
    AudioHandler audioHandler;
};

#endif
