#include "t_goal_selector_or.hpp"

namespace ai::gob
{
    t_goal_or_selector::t_goal_or_selector()
    {
    }

    t_description_view t_goal_or_selector::description() const
    {
        return "аггрегатор выбора достигнутой цели как логическое И";
    }

    t_priority t_goal_or_selector::priority() const
    {
        return 0.5f;
    }

    bool t_goal_or_selector::is_reached() const
    {
        for (const std::unique_ptr<interfaces::t_goal_interface>& goal : _goals)
        {
            if (goal->is_reached())
            {
                return true;
            }
        }

        return {};
    }
}
