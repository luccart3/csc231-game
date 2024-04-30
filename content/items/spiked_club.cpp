#include "spiked_club.h"
#include "hit.h"
#include "engine.h"
#include "swing.h"
#include "entity.h"
#include "animation.h"
#include "sound.h"

Spiked_Club::Spiked_Club(int damage)
    :Item{"spiked_club"}, damage{damage} {}

void Spiked_Club::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    auto swing = engine.events.create_event<Swing>(sprite, direction);
    std::shared_ptr<Event> explosion =
        std::make_shared<Animation>("explosion", defender.get_position());
    explosion->add_next(Hit{defender, damage});
    swing->add_next(explosion);
    engine.events.create_event<Sound>("thunder");

}



