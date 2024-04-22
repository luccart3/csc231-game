#pragma once

#include "item.h"

class Spear : public Item {
public:
    explicit Spear(int damage);
    // cause damage to defender
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};