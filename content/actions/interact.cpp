#include "interact.h"
#include "item.h"

Interact::Interact(Tile& tile)
    : tile{tile}{}

Result Interact::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    tile.item->interact(engine, *entity);
    return success();
}