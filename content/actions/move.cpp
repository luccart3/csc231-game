#include "move.h"
#include "tile.h"
#include "engine.h"

Result Move::perform(Engine&, std::shared_ptr<Entity>) {
    Vec new_position = position + direction;
    position = new_position;
    //Tile& tile = engine.dungeon.get_tile(position);
//if (tile = door) { go through door }

//else if (tile = enemy ) { return failure () }

//else if (tile = wall ) { return failure () }

//else { new_position = old_position + direction}
}

// If new position is wall
// return failure()
// If new position is door
// return alternative(OpenDoor{})