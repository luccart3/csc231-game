#include "monsters.h"
#include "rest.h"
#include "randomness.h"
#include "engine.h"
#include "action.h"
#include "wander.h"
#include "move.h"
#include "spiked_club.h"
#include "sword_rusty.h"
#include "bite.h"

namespace Monsters {
void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(10);
    monster->behavior = behavior_aggressive;
    monster->add_to_inventory(std::make_shared<Spiked_Club>(5));

}

void make_muddy(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("muddy");
    monster->set_max_health(5);
    monster->behavior = behavior_wander;
    monster->add_to_inventory(std::make_shared<Sword_Rusty>(2));

}

void make_demon_big(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("demon_big");
    monster->set_max_health(15);
    monster->behavior = behavior_aggressive;
    monster->add_to_inventory(std::make_shared<Bite>(10));

}

std::unique_ptr<Action> behavior_aggressive(Engine& engine, Entity& entity) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (entity.is_visible() && engine.hero) {
        auto path =
            engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
        else {
            return std::make_unique<Rest>();
        }
    }
    if (probability(66)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

std::unique_ptr<Action> behavior_wander(Engine&, Entity&) {
    if (probability(66)) { // engine/util/randomness.h
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

std::unique_ptr<Action> behavior_boring(Engine&, Entity&) {
    return std::make_unique<Rest>();
}

}