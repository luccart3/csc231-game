#include "action.h"
#include "vec.h"


class Move : public Action {
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    Vec position;
    Vec direction;

};