#pragma once
#include <memory>
#include "entity.h"
#include "action.h"


namespace Heroes {
    void make_ogre(std::shared_ptr<Entity>& hero);
    std::unique_ptr<Action> behavior();
}
