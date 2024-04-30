#include "sword_rusty.h"
#include "hit.h"
#include "engine.h"
#include "swing.h"
#include "entity.h"

// content/items/spear.cpp
Sword_Rusty::Sword_Rusty(int damage)
    :Item{"sword_rusty"}, damage{damage} {}

void Sword_Rusty::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}

