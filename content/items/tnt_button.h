#pragma once

#include "item.h"
#include "entity.h"

class TNTButton : public Item {
public:
    explicit TNTButton(int damage);
    void interact(Engine& engine, Entity& entity) override;

private:
    int damage;
};