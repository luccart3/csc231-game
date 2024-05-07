#pragma once

#include "item.h"
#include "entity.h"

class Ladder : public Item {
public:
    explicit Ladder();

    void interact(Engine& engine, Entity& climber) override;

};