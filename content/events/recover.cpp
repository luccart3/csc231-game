#include "recover.h"
#include "entity.h"
#include "die.h"

Recover::Recover(Entity& entity, int recovery)
    :entity{entity}, recovery{recovery} {}

void Recover::execute(Engine&) {
    entity.take_damage(recovery*-1); // reduce health
}

void Recover::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity}); // remove from game
    }
}