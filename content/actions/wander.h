#include "action.h"
#include "vec.h"
#include "engine.h"
#include "tile.h"
#include "entity.h"


class Wander : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

};
