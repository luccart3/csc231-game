#include "monsters.h"
#include "rest.h"
#include "randomness.h"
#include "engine.h"
#include "action.h"
#include "wander.h"
#include "move.h"

namespace Monsters {
void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(12);
    monster->behavior = behavior_aggressive;
}

void make_muddy(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("muddy");
    monster->set_max_health(5);
    monster->behavior = behavior_wander;
}

void make_demon_big(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("demon_big");
    monster->set_max_health(12);
    monster->behavior = behavior_boring;
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

std::unique_ptr<Action> behavior_wander(Engine& engine, Entity& entity) {
    if (probability(66)) { // engine/util/randomness.h
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

std::unique_ptr<Action> behavior_boring(Engine& engine, Entity& entity) {
    return std::make_unique<Rest>();
}

}