#include "heroes.h"
#include "entity.h"
#include "action.h"
#include "closedoor.h"
#include "engine.h"
#include "move.h"
#include "rest.h"
#include "spiked_club.h"
#include "spear.h"
#include "healing_potion.h"
#include "item.h"

namespace Heroes {
void make_ogre(std::shared_ptr<Entity>& hero) {
    hero->set_sprite("ogre");
    hero->set_max_health((50));
    hero->behavior = behavior;
    hero->add_to_inventory(std::make_shared<Spiked_Club>(5));
    hero->add_to_inventory(std::make_shared<Spear>(3));
    hero->add_to_inventory(std::make_shared<Healing_Potion>(15));

}
std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
    std::string key = engine.input.get_last_keypress();
    if (key == "R") {
        return std::make_unique<Rest>();
    }
    if (key == "C") {
        return std::make_unique<CloseDoor>();
    }
    if (key == "E") { //for items used on self
        std::shared_ptr<Item> item = entity.get_current_item();
        item->use(engine, entity);
        return std::make_unique<Rest>(); //uses turn
    }
    if (key == "D") {
        return std::make_unique<Move>(Vec{1, 0});
    }
    if (key == "A") {
        return std::make_unique<Move>(Vec{-1, 0});
    }
    if (key == "W") {
        return std::make_unique<Move>(Vec{0, 1});
    }
    if (key == "S") {
        return std::make_unique<Move>(Vec{0, -1});
    }

    else if (!key.empty() && std::isdigit(key.at(0))){
        int item_num = std::stoi(key) - 1; // "1" -> index 0
        entity.select_item(item_num);
    }
    return nullptr;
}

}