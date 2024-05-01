#include "raise.h"

constexpr int duration = 3; //number of frames

constexpr int delta = 7; //pixels

Raise::Raise(Sprite& sprite, Vec direction)
    :Event{duration}, sprite{sprite}, copy{sprite}, direction{direction} {
    //orient the weapon towards direction
    sprite.center = sprite.size / 4;
    sprite.shift.y -= sprite.size.y / 2;
    sprite.angle = 0;
}

void Raise::execute(Engine&) {
    //shift in pixels (16 per tile)
    direction = {0,1};
    sprite.shift += direction * delta;
}

void Raise::when_done(Engine& ) {
    sprite = copy;

}