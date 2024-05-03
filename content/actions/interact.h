#pragma once
#include "entity.h"
#include "engine.h"
#include "action.h"

class Interact : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};