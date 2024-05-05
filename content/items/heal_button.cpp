#include "heal_button.h"
#include "tile.h"
#include "engine.h"
#include "hit.h"
#include "sound.h"
#include "animation.h"
#include "pressed_button.h"

HealButton::HealButton(int recovery)
    :Item{"tnt_button"}, recovery{recovery} {}
//looks identical to tnt intentionally

void HealButton::interact(Engine& engine, Entity& entity) {

    Vec position = entity.get_position();

    //sequence of events
    auto button_press = engine.events.create_event<Sound>("button-press");
    std::shared_ptr<Event> magic =
        std::make_shared<Animation>("magic", position);
    button_press->add_next(magic);
    button_press->add_next(Sound("magic"));
    magic->add_next(Hit{entity, -1 * recovery});

    //heals entities in adjacent tiles
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_entity()) {
            engine.events.create_event<Hit>(*tile.entity, -1 * recovery);
        }
    }

    //removes the heal_button item and replaces it with the pressed_button item
    engine.dungeon.remove_item(position);
    auto pressed_button = std::make_shared<PressedButton>();
    pressed_button->sprite = engine.graphics.get_sprite(pressed_button->name);
    Tile& tile = engine.dungeon.get_tile(position);
    tile.item = pressed_button;

}