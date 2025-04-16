#ifndef T_GOAL_SELECTOR_AND_H
#define T_GOAL_SELECTOR_AND_H

#include "../../t_defines.hpp"

#include "../interfaces/t_goal_interface.hpp"


namespace ai::gob
{
    class t_goal_and_selector : public interfaces::t_goal_interface
    {
    public:
        t_goal_and_selector();

        ~t_goal_and_selector() override = default;

        t_description_view description() const override;

        t_priority priority() const override;

        bool is_reached() const override;

    protected:
        std::string _description {};
    };
}

#endif // T_GOAL_SELECTOR_AND_H
