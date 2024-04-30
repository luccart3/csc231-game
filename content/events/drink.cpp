#include "drink.h"

constexpr int duration = 3; //number of frames

constexpr int delta = 1; //pixels

Drink::Drink(Sprite& sprite, Vec)
    :Event{duration}, sprite{sprite}, copy{sprite} {
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;
    sprite.angle = -5;
}

void Drink::execute(Engine&) {
    //shift in pixels (16 per tile)
    direction = {0,1};
    sprite.shift += direction * delta;
}

void Drink::when_done(Engine&) {
    sprite = copy;
}