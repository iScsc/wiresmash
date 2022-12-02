#ifndef ENGINE_INPUT_INPUT_HANDLER_H
#define ENGINE_INPUT_INPUT_HANDLER_H

#include "engine/entity.h"

struct UniversalInput
{
    int handlerId;
    int inputId;
};

class InputHandler
{
private:
    int start_action_id;

protected:
    Entity* owner;
public:
    InputHandler(/* args */) = default;
    ~InputHandler() = default;
    void setOwner(Entity* entity){ this->owner = entity;};
    virtual void doInput(int actionId) {};
};

#endif