#pragma once
#include "action.h"
#include "engine.h"
#include "entity.h"

class UseItem : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> user) override;
private:
};
