#pragma once

#include "item.h"

class Sword_Rusty : public Item {
public:
    explicit Sword_Rusty(int damage);
    // cause damage to defender
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};