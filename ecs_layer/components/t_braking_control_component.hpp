#pragma once

#include "../t_component_defines.hpp"


class t_braking_control_component
{
public:
    t_braking_control_component(const t_speed_value speed, const t_time_floating_value time);
    t_braking_control_component(const t_identifier_value identifier, const t_speed_value speed, const t_time_floating_value time);

    const t_identifier_value get_identifier() const;

private:
    const t_identifier_value _identifier {};

    t_speed_value _speed {};

    [[maybe_unused]] const t_time_floating_value _time {};

    const t_acceleration_value _acceleration {};

private:
    friend class t_braking_control_system;

    friend class t_braking_distance_system;
};
