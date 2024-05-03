#include "healing_potion.h"
#include "engine.h"
#include "entity.h"
#include "recover.h"
#include "drink.h"
#include "sound.h"
#include "remove_item.h"

Healing_Potion::Healing_Potion(int recovery)
    :Item{"potion_red"}, recovery{recovery} {}

void Healing_Potion::use(Engine& engine, Entity& owner) {

    Vec direction = owner.get_direction();

    auto drink = engine.events.create_event<Drink>(sprite, direction);
    std::shared_ptr<Event> remove_item =
        std::make_shared<RemoveItem>(owner, *this);
    drink->add_next(Recover{owner, recovery});
    drink->add_next(remove_item);
    engine.events.create_event<Sound>("slurp");
}

