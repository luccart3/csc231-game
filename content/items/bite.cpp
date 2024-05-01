#include "bite.h"
#include "engine.h"
#include "sound.h"
#include "hit.h"

Bite::Bite(int damage)
    :Item{"none"}, damage{damage} {}

void Bite::use(Engine& engine, Entity&, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
    engine.events.create_event<Sound>("bite");

}
