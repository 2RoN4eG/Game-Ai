#include "t_goal_is_arrived.hpp"

#include "../ecs_layer/components/t_ai_demo_movable_component.hpp"


namespace ai::gob
{
    t_goal_is_arrived::t_goal_is_arrived(const t_ai_demo_movable_component& movable_component,
                                     const t_1d_position_value goal_position)
        : _movable_component { movable_component }
        , _goal_position { goal_position }
        , _description { "" }
    {
    }

    t_description_view t_goal_is_arrived::description() const
    {
        return "аггрегатор выбора достигнутой цели как логическое ИЛИ";
    }

    t_priority t_goal_is_arrived::priority() const
    {
        return {};
    }

    bool t_goal_is_arrived::is_reached() const
    {
        return _movable_component.get_position() >= _goal_position;
    }
}
