#include "move.h"
#include "entity.h"
#include <memory>
#include "engine.h"
#include "opendoor.h"
#include "rest.h"
#include "attack.h"
#include "interact.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec tile_go = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(tile_go);

    if (tile.is_wall()) {
        return failure();
    }

    else if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()) {
            return alternative(Attack(*tile.entity));
        }
        else {
            return alternative(Rest{});
        }
    }

    else if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});
    }

    else if (tile.has_item()) {
        //need to make it so only hero can interact
        entity->move_to(tile_go);
        return alternative(Interact{tile});
    }

    entity->move_to(tile_go);
    return success();
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