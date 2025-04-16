#include "t_ai_demo_movable_component.hpp"

t_ai_demo_movable_component::t_ai_demo_movable_component(const t_1d_position_value position,
                                                         const t_speed_value speed)
    : _position { position }
    , _speed { speed }
{
}

t_1d_position_value t_ai_demo_movable_component::get_position() const
{
    return _position;
}

void t_ai_demo_movable_component::set_position(const t_1d_position_value position)
{
    _position = position;
}

t_speed_value t_ai_demo_movable_component::get_speed() const
{
    return _speed;
}
