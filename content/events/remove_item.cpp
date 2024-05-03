#include "remove_item.h"
#include "item.h"
#include "entity.h"

RemoveItem::RemoveItem(Entity& entity, Item& item)
    :entity{entity}, item{item} {}

void RemoveItem::execute(Engine&) {
    entity.remove_item(&item);
}

void RemoveItem::when_done(Engine&) {

}