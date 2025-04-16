#include "t_rotating_vehicle_system.hpp"


namespace
{
    constexpr t_speed_value heading_speed_degrees { 20 };
}


t_rotating_vehicle_system::t_rotating_vehicle_system(const t_input_device& input_device)
    : _input_device { input_device }
    , _turn_left_subsystem { {}, heading_speed_degrees }
    , _turn_right_subsystem { {}, heading_speed_degrees }
{
}

void t_rotating_vehicle_system::update(const t_frame_delta_time_value delta_time)
{
    const t_turn_left_event turn_left_event { _input_device, 'W' | 'w' };

    if (turn_left_event())
    {
        const t_range_value joystick_deviation = turn_left_event.get_deviation_value();

        _turn_left_subsystem.update(joystick_deviation, delta_time);

        return;
    }

    const t_turn_right_event turn_right_event { _input_device, 'S' | 's' };

    if (turn_right_event())
    {
        const t_range_value joystick_deviation = turn_left_event.get_deviation_value();

        _turn_right_subsystem.update(joystick_deviation, delta_time);

        return;
    }
}
