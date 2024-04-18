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

Doors: 
* Finish open door anc close door by friday 

Wander: 
* typo in perform on slides, needs entity

Ideas: 
* save function
* ladders and floors 
* levels
* tnt on floor and pressure plate
* shape-shifter
  * kill enemy, turn into them, don't get attacked by enemies of that type? 
