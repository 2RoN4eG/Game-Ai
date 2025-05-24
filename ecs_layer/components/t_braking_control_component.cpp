#include "t_braking_control_component.hpp"


t_braking_control_component::t_braking_control_component(const t_speed_value speed, const t_time_floating_value time)
    : t_braking_control_component { {}, speed, time }
{
}

t_braking_control_component::t_braking_control_component(const t_identifier_value identifier, const t_speed_value speed, const t_time_floating_value time)
    : _identifier { identifier }
    , _speed { speed }
    // , _time { time }
    , _acceleration { _speed / time }
{
}

const t_identifier_value t_braking_control_component::get_identifier() const
{
    return _identifier;
}
