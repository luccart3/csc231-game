#include "spiked_club.h"
#include "hit.h"
#include "engine.h"

Spiked_Club::Spiked_Club(int damage)
    :Item{"spiked_club"}, damage{damage} {}

void Spiked_Club::use(Engine& engine, Entity&, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
}

