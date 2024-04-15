#include "move.h"
#include "entity.h"
#include <iostream>

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Move m = Move(direction);
    Vec position = entity->get_position();
    Tile& tile = engine.dungeon.get_tile(position);

    if (tile.is_wall() || tile.has_entity()) {
        return failure();
    }

    else if (tile.has_door()) {
        return failure();
    }

    else {
        entity->move_to(position);
        return success();
    }
}

Move::Move(Vec direction) {
    Vec position;
    Vec new_position = position + direction;
}


//if (tile = door) { go through door }

//else if (tile = entity ) { return failure () }

//else if (tile = wall ) { return failure () }

//else { new_position = old_position + direction}

// If new position is wall
// return failure()
// If new position is door
// return alternative(OpenDoor{})