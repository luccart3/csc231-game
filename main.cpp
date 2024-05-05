#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "tnt_button.h"
#include "heal_button.h"

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
        // make the buttons and look up their sprites
        auto tnt_button = std::make_shared<TNTButton>(25);
        tnt_button->sprite = engine.graphics.get_sprite(tnt_button->name);
        auto heal_button = std::make_shared<HealButton>(25);
        heal_button->sprite = engine.graphics.get_sprite(heal_button->name);

        // place them on random tiles
        for (int i = 0; i < 3; ++i) {
            Vec pos_1 = engine.dungeon.random_open_room_tile();
            Tile& tile = engine.dungeon.get_tile(pos_1);
            tile.item = tnt_button;
            Vec pos_2 = engine.dungeon.random_open_room_tile();
            Tile& tile_2 = engine.dungeon.get_tile(pos_2);
            tile_2.item = heal_button;
        }
        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
