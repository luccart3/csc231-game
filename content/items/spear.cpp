#include "spear.h"
#include "hit.h"
#include "engine.h"
#include "thrust.h"
#include "entity.h"
#include "sound.h"

// content/items/spear.cpp
Spear::Spear(int damage)
    :Item{"spear"}, damage{damage} {}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Sound>("hit");
    engine.events.create_event<Hit>(defender, damage);
}

