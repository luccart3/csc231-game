#pragma once
#include "action.h"
#include "vec.h"
#include "entity.h"
#include "engine.h"


namespace Heroes {
    void make_ogre(std::shared_ptr<Entity>& hero);
    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}
