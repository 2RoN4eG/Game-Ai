#include "t_1d_linear_moving_behavior.hpp"

#include <iostream>


namespace ai::gob
{
    t_1d_linear_moving_behavior::t_1d_linear_moving_behavior(t_ai_demo_movable_component& movable_component)
        : _movable_component { movable_component }
    {
    }
    
    std::string_view t_1d_linear_moving_behavior::description() const
    {
        return "Поведение простого линейного движения (без поворотов, движение по прямой).";
    }
    
    void t_1d_linear_moving_behavior::behave(const t_delta_time delta_time)
    {
        t_1d_position_value position = _movable_component.get_position();

        const t_speed_value delta_speed = _movable_component.get_speed() / delta_time;

        _movable_component.set_position(position + delta_speed);
    }
}
