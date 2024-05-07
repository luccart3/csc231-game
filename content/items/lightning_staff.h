#pragma once

#include "item.h"

class Lightning_Staff : public Item {
public:
    explicit Lightning_Staff(int damage);
    // cause damage to defender
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;


private:
    int damage;
};