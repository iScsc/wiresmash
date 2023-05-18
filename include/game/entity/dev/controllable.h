#ifndef GAME_ENTITY_DEV_CONTROLLABLE_H
#define GAME_ENTITY_DEV_CONTROLLABLE_H

#include "engine/input/input_handler.h"

class DevControllable : public Engine::InputHandler
{
private:
    int amplitude;

public:
    void setAmplitude(int amp) { this->amplitude = amp; };
    void doInput(int actionId) override;
};

#endif