#include "t_ramping_vehicle_speed_system.hpp"

#include <iostream>


t_ramping_vehicle_speed_system::t_ramping_vehicle_speed_system(const t_moving_forward_event& forward_moving_event,
                                               t_vehicle_component& vehicle)
    : _forward_moving_event { forward_moving_event }
    , _vehicle { vehicle }
    , _ramping_up_speed { _vehicle, _speed_scale_range }
    , _ramping_down_speed { _vehicle, _speed_scale_range }
{
    std::cout << "speed scale: "
              << "minimum is " << _speed_scale_range.get_minimum()
              << ", maximum is " << _speed_scale_range.get_maximum()
              << std::endl;
}

void t_ramping_vehicle_speed_system::update(const t_frame_delta_time_value delta_time)
{
    if (_forward_moving_event())
    {
        _ramping_up_speed.update(delta_time);

        return;
    }

    _ramping_down_speed.update(delta_time);
}
