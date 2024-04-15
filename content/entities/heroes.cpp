#include "heroes.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "move.h"

namespace Heroes {
void make_ogre(std::shared_ptr<Entity>& hero) {
    hero->set_sprite("ogre");
    hero->set_max_health((50));
    hero->behavior = behavior;
}
std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
    std::string key = engine.input.get_last_keypress();
    if (key == "R") {
        return std::make_unique<Rest>();
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
    return nullptr;
}

}