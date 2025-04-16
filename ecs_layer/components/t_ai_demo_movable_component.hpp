#ifndef T_AI_DEMO_MOVABLE_COMPONENT_H
#define T_AI_DEMO_MOVABLE_COMPONENT_H

#include "../t_component_defines.hpp"


class t_ai_demo_movable_component
{
public:
    t_ai_demo_movable_component(const t_1d_position_value position = {},
                                const t_speed_value speed = 100.);

    t_1d_position_value get_position() const;

    void set_position(const t_1d_position_value position);

    t_speed_value get_speed() const;

private:
    t_1d_position_value _position {};

    t_speed_value _speed {};
};

#endif // T_AI_DEMO_MOVABLE_COMPONENT_H
