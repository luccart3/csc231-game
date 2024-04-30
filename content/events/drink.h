#pragma once

#include "sprite.h"
#include "event.h"

class Drink : public Event {
public:
    Drink(Sprite& sprite, Vec direction);

    void execute(Engine& engine) override;

    void when_done(Engine& engine) override;

private:
    Sprite& sprite; //original weapon sprite
    Sprite copy;
    Vec direction;
};