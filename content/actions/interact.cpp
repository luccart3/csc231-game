#include "interact.h"
#include "item.h"

Result Interact::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec pos = entity->get_position();
    Tile& tile = engine.dungeon.get_tile(pos);
    tile.item->interact(engine, *entity);
    return success();
}