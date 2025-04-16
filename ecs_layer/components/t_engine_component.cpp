#include "t_engine_component.hpp"

#include <iostream>

constexpr t_speed_value t_speed_epsilon = 1e-10;


t_engine_component::t_engine_component(const t_engine_power_value power)
    : _power { power }
    , _speed {}
{
}


const t_engine_power_value t_engine_component::get_power() const
{
    return _power;
}

const t_speed_value t_engine_component::get_speed() const
{
    return _speed;
}


void t_set_engine_speed(t_engine_component& engine, const t_speed_value speed)
{
    engine._speed = speed < t_speed_epsilon ? 0 : speed;
}
