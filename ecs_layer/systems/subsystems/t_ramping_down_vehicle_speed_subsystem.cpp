#include "t_ramping_down_vehicle_speed_subsystem.hpp"

#include "../../components/t_engine_component.hpp"
#include "../../components/t_chassis_component.hpp"
#include "../../components/t_vehicle_component.hpp"


namespace
{
    // Данное время расчитывается строго от массы машины (пока константа).

    constexpr t_frame_delta_time_value g_ramping_down_time { 2000. };    // milliseconds

    inline t_engine_component& t_get_vehicle_engine(t_vehicle_component& vehicle)
    {
        t_chassis_component& chassis { vehicle.get_mutable_chassis() };

        return chassis.get_mutable_engine();
    }
}


t_ramping_down_vehicle_speed_subsystem::t_ramping_down_vehicle_speed_subsystem(t_vehicle_component& vehicle,
                                                                               const t_range<t_speed_scale_value>& speed_scale_range)
    : _engine { t_get_vehicle_engine(vehicle) }
    , _speed_limit { vehicle.get_speed_limit() }
    , _speed_scale_range { speed_scale_range }
{
}

void t_ramping_down_vehicle_speed_subsystem::update(const t_frame_delta_time_value delta_time)
{
    // speed scale is range [0 ... 1]

    const t_speed_value speed = _engine.get_speed();

    if (speed == _speed_limit)
    {
        return;
    }

    const t_speed_scale_value speed_scale { speed / _speed_limit };

    if (_speed_scale_range.is_minimum(speed_scale))
    {
        return;
    }

    const t_speed_value delta_speed { delta_time / g_ramping_down_time * 100 };

    t_set_engine_speed(_engine, speed - delta_speed);
}


const t_frame_delta_time_value t_get_rumping_down_time()
{
    return g_ramping_down_time;
}
