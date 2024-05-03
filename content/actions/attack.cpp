#include "attack.h"
#include "item.h"


Attack::Attack(Entity& defender)
    : defender{defender}{}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    std::shared_ptr<Item> weapon = attacker->get_current_item();
    weapon->use(engine, *attacker, defender);
    return success();
}