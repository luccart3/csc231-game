#include "healing_potion.h"
#include "engine.h"
#include "entity.h"
#include "recover.h"
#include "drink.h"
#include "sound.h"

Healing_Potion::Healing_Potion(int recovery)
    :Item{"potion_red"}, recovery{recovery} {}

void Healing_Potion::use(Engine& engine, Entity& attacker, Entity&) {
    engine.events.create_event<Drink>(sprite, attacker.get_direction());
    engine.events.create_event<Recover>(attacker, recovery);
    engine.events.create_event<Sound>("slurp");
}

