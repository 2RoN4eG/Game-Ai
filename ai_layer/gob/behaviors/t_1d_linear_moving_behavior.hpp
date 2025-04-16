#ifndef T_1D_LINEAR_MOVING_BEHAVIOR_H
#define T_1D_LINEAR_MOVING_BEHAVIOR_H

#include "../interfaces/t_behavior_interface.hpp"

#include "../ecs_layer/components/t_ai_demo_movable_component.hpp"


class t_ai_demo_movable_component;


namespace ai::gob
{
    class t_1d_linear_moving_behavior : public interfaces::t_behavior_interface
    {
    public:
        t_1d_linear_moving_behavior(t_ai_demo_movable_component& movable_component);

        ~t_1d_linear_moving_behavior() override = default;

        std::string_view description() const override;

        void behave(const t_delta_time delta) override;

    private:
        t_ai_demo_movable_component& _movable_component;
    };
}

#endif // T_1D_LINEAR_MOVING_BEHAVIOR_H
