#include "use_item.h"
#include "entity.h"
#include "item.h"
#include "rest.h"


Result UseItem::perform(Engine& engine, std::shared_ptr<Entity> user) {
    std::shared_ptr<Item> item = user->get_current_item();
    item->use(engine, *user);
    return success();
}

