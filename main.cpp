#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_ogre(hero);

        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> monster_1 = engine.create_monster();
            std::shared_ptr<Entity> monster_2 = engine.create_monster();
            std::shared_ptr<Entity> monster_3 = engine.create_monster();

            Monsters::make_orc_masked(monster_1);
            Monsters::make_muddy(monster_2);
            Monsters::make_demon_big(monster_3);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
