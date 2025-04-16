#include "t_ai_demo_linear_moving_system.hpp"

#include "../components/t_ai_demo_movable_component.hpp"
#include "../t_component_defines.hpp"


t_ai_demo_linear_moving_system::t_ai_demo_linear_moving_system(t_ai_demo_movable_component& movable_component)
    : _movable_entity { movable_component }
{
}

void t_ai_demo_linear_moving_system::update(const t_frame_delta_time_value delta_time)
{
    t_1d_position_value position = _movable_entity.get_position();
    
    const t_speed_value delta_speed = _movable_entity.get_speed() / delta_time;

    _movable_entity.set_position(position + delta_speed);
}
