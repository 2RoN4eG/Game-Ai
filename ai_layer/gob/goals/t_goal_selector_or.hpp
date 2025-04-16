#ifndef T_GOAL_SELECTOR_OR_H
#define T_GOAL_SELECTOR_OR_H

#include "../../t_defines.hpp"
#include "../interfaces/t_goal_interface.hpp"

#include <vector>

namespace ai::gob
{
    class t_goal_or_selector : public interfaces::t_goal_interface
    {
    public:
        t_goal_or_selector();

        ~t_goal_or_selector() override = default;

        t_description_view description() const override;

        t_priority priority() const override;

        bool is_reached() const override;

    protected:
        std::vector<std::unique_ptr<interfaces::t_goal_interface>> _goals;
    };
}

#endif // T_GOAL_SELECTOR_OR_H
