#include "wander.h"
#include "entity.h"
#include <memory>
#include "engine.h"
#include "rest.h"
#include "move.h"
#include "randomness.h"
#include "attack.h"


Result Wander::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    // randomize order of neighbors: shuffle in engine/utils/randomness.h
    shuffle(std::begin(neighbors), std::end(neighbors));
    // find first open floor tile
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (!tile.is_wall() && !tile.has_entity() &&!tile.has_item()) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
        if (tile.has_entity()) {
            if (entity->get_team() != tile.entity->get_team()) {
                return alternative(Attack(*tile.entity));
            }
        }
    }
    return alternative(Rest{});
}