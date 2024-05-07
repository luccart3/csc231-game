#include "ladder.h"
#include "engine.h"
#include "entity.h"
//#include "monsters.h"


Ladder::Ladder()
    :Item{"hammer"} {} //sprite will change to ladder once I add it

void Ladder::interact(Engine& engine, Entity& climber) {
    // for (number of monsters) {
    // monster.remove_entity();
    // }
    //
    // for (int i = 0; i < 5; ++i) {
    //            std::shared_ptr<Entity> monster_1 = engine.create_monster();
    //            std::shared_ptr<Entity> monster_2 = engine.create_monster();
    //            std::shared_ptr<Entity> monster_3 = engine.create_monster();
    //
    //            Monsters::make_orc_masked(monster_1);
    //            Monsters::make_muddy(monster_2);
    //            Monsters::make_demon_big(monster_3);
    //        }
    //
    //        engine.run();
}