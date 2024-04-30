#pragma once

#include "item.h"

class Healing_Potion : public Item {
public:
    explicit Healing_Potion(int recovery);
    // cause damage to defender
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int recovery;
};