# *CSC 231 GAME*
## Class Notes

For Actions: 
* always use failure, success, and alternative
* for move, we need something that looks like:
  * ent->move_to (get_pos() + direction)

Tiles:
* Common error: 
  * Tile& tile = engine.dungeon.get_tile(position);
  * make sure you use & 
  * means you can change things, like accidentally removing things from game


