#include "t_rotating_vehicle_subsystem.hpp"

#include <iomanip>


namespace
{
    const t_floating_value make_velocity(const t_floating_value direction, const t_floating_value speed)
    {
        return direction * speed;
    }
}


t_rotating_chassis_subsystem::t_rotating_chassis_subsystem(const t_heading_degrees_value heading_degrees,
                                                           const t_heading_speed_degrees_per_second_value heading_speed_degrees)
    : _heading { t_convert_degrees_to_radians(heading_degrees) }
    , _heading_speed { t_convert_degrees_to_radians(heading_speed_degrees) }
{
}

void t_rotating_chassis_subsystem::update(const t_range_value joystick_value, const t_frame_delta_time_value frame_delta_time)
{
    const t_angular_speed_degrees_per_second_value angular_speed_step = joystick_value * _heading_speed * frame_delta_time;

    _heading += angular_speed_step;
}
