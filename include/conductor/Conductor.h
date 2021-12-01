#ifndef DEF_CONDUCTOR
#define DEF_CONDUCTOR

#include <SFML/Graphics.hpp>
#include "ControllerHandler.h"
#include "ScheduleHandler.h"
#include "PhysicsHandler.h"
#include "DrawHandler.h"
#include "AudioHandler.h"

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
