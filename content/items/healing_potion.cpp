#include "healing_potion.h"
#include "engine.h"
#include "entity.h"
#include "recover.h"

// content/items/spear.cpp
Healing_Potion::Healing_Potion(int recovery)
    :Item{"potion_red"}, recovery{recovery} {}

void Healing_Potion::use(Engine& engine, Entity& attacker, Entity& defender) {
//    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Recover>(attacker, recovery);
}

