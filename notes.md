# *CSC 231 GAME*
## Class Notes

TO DO: 
* delete potion on use 
* balance hp and damage
* ladder item 
  * interact causes dungeon and actors to reload
* TNT pressure plate 
  * stepping on pressure plate tile creates explosion animation that damages all neighbors

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

Frames:
* these frames represent how much logic is computed a second... this game is at 10 frames per second
* once execute has been called (# of frames) times, event is done
* when done cleans up/resets , optional 

Events: 
* make stuff as simple as possible

Ladders/Floors:
* Make ladder/pit item 
* interact function inside 
* recreates dungeon
* find open tile 
* reloads actors 

Healing Potion: 
* need to make it usable by button 
* delete when done 
* drinking animation
