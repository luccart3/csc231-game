#pragma once
#include "action.h"
#include "vec.h"
#include "entity.h"
#include "engine.h"


namespace Monsters {
    void make_orc_masked(std::shared_ptr<Entity>& monster);
    void make_muddy(std::shared_ptr<Entity>& monster);
    void make_demon_big(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> behavior_aggressive(Engine& engine, Entity&);
    std::unique_ptr<Action> behavior_wander(Engine& engine, Entity&);
    std::unique_ptr<Action> behavior_boring(Engine& engine, Entity&);

}
