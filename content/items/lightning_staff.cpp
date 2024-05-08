#include "lightning_staff.h"
#include "hit.h"
#include "engine.h"
#include "raise.h"
#include "entity.h"
#include "animation.h"
#include "sound.h"

Lightning_Staff::Lightning_Staff(int damage)
    :Item{"staff_green"}, damage{damage} {}

void Lightning_Staff::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    auto raise = engine.events.create_event<Raise>(sprite, direction);
    std::shared_ptr<Event> lightning =
        std::make_shared<Animation>("lightning", defender.get_position());
    lightning->add_next(Hit{defender, damage});
    raise->add_next(lightning);
    engine.events.create_event<Sound>("thunder");
}

void Lightning_Staff::interact(Engine& engine, Entity& entity) {
    Vec position = entity.get_position();
    Tile& tile = engine.dungeon.get_tile(position);
    entity.add_to_inventory(tile.item);
    engine.dungeon.remove_item(position);
    engine.events.create_event<Sound>("pop");
}



