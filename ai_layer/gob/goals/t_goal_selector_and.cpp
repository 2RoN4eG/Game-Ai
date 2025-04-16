#include "t_goal_selector_and.hpp"

namespace ai::gob
{
    t_goal_and_selector::t_goal_and_selector()
        : _description { "" }
    {
    }

    t_description_view t_goal_and_selector::description() const
    {
        return _description;
    }

    t_priority t_goal_and_selector::priority() const
    {
        return {};
    }

    bool t_goal_and_selector::is_reached() const
    {
        return {};
    }
}
