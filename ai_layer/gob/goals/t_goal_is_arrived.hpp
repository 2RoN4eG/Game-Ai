#ifndef T_GOAL_IS_ARRIVED_H
#define T_GOAL_IS_ARRIVED_H

#include "../../t_defines.hpp"

#include "../interfaces/t_goal_interface.hpp"


class t_ai_demo_movable_component;


namespace ai::gob
{
    class t_goal_is_arrived : public interfaces::t_goal_interface
    {
    public:
        t_goal_is_arrived(const t_ai_demo_movable_component& movable_component,
                          const t_1d_position_value destination);

        ~t_goal_is_arrived() override = default;

        t_description_view description() const override;

        t_priority priority() const override;

        bool is_reached() const override;

    protected:
        const t_ai_demo_movable_component& _movable_component;
        
        const t_1d_position_value _goal_position {};

        std::string _description {};
    };
}

#endif // T_GOAL_IS_ARRIVED_H
