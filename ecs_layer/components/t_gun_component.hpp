#pragma once

#include "../t_component_defines.hpp"


using t_amount          = int;

using t_cooldown_time   = int;


class t_gun_component
{
public:
    t_gun_component(const t_go_identifier_value identifier, const t_elevation_degrees_value elevation_degrees);
    t_gun_component(const t_elevation_degrees_value elevation_degrees);

    const t_elevation_radians_value get_elevation() const;

    bool single() const
    {
        return _amount == 1;
    }

    bool dual() const
    {
        return _amount == 2;
    }

    const t_weight_value get_weight() const;

protected:
    const t_go_identifier_value _identifier {};

    t_elevation_radians_value   _elevation_radians;

    t_amount                    _amount { 1 };

    t_cooldown_time             _cooldown_time {};
};
