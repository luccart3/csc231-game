#pragma once

#include "item.h"
#include "entity.h"

class HealButton : public Item {
public:
    explicit HealButton(int recovery);
    void interact(Engine& engine, Entity& entity) override;

private:
    int recovery;
};