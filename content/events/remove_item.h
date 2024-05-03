#pragma once
#include "event.h"

class Entity;
class Item;

class RemoveItem : public Event {
public:
    RemoveItem(Entity& entity, Item& item);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Entity& entity;
    Item& item;
};