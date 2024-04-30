#pragma once
#include "event.h"

//forward declaration (declare the type of the variable)
class Entity;

class Recover : public Event {
public:
    Recover(Entity& entity, int recovery);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Entity& entity;
    int recovery;
};