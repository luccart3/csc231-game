#include "action.h"
#include "vec.h"
#include "engine.h"
#include "tile.h"
#include "entity.h"


class Move : public Action {
public:
    explicit Move(Vec direction);

    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
};
