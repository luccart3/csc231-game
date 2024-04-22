#pragma once

#include "item.h"

class Spiked_Club : public Item {
public:
    explicit Spiked_Club(int damage);
    // cause damage to defender
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};