#include "move.h"
#include "entity.h"
#include <iostream>
#include <memory>
#include "engine.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec tile_go = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(tile_go);

    if (tile.is_wall() || tile.has_entity()) {
        return failure();
    }

    else if (tile.has_door()) {
        return failure();
    }

    else {
        entity->move_to(tile_go);
        return success();
    }
}

Move::Move(Vec direction)
     : direction{direction}{}


//if (tile = door) { go through door }

//else if (tile = entity ) { return failure () }

//else if (tile = wall ) { return failure () }

//else { new_position = old_position + direction}

// If new position is wall
// return failure()
// If new position is door
// return alternative(OpenDoor{})