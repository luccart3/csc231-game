#pragma once

#include "item.h"

class Healing_Potion : public Item {
public:
    explicit Healing_Potion(int recovery);
    // recovery is amount of health regained
    // heal owner
    void use(Engine& engine, Entity& owner) override;
    void interact(Engine& engine, Entity& entity) override;


private:
    int recovery;
};