#pragma once
#include "entity.h"
#include "engine.h"
#include "action.h"
#include "tile.h"

class Interact : public Action {
public:
    explicit Interact(Tile& tile);

    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Tile& tile;
};