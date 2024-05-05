#pragma once

#include "item.h"
#include "entity.h"

class PressedButton : public Item {
public:
    explicit PressedButton();
    void interact(Engine& engine, Entity& entity) override;
};