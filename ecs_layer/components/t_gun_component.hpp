#pragma once

#include "../tools/t_2d_vector.hpp"


using t_gun_amount_value            = int;

using t_cooldown_time_millis_value  = int;

using t_shot_damage_value           = int;

// Предпологается что дальше это будет контейнер [minimum ... maximum] с рандомной выборкой значния из него.
using t_shot_damage_range           = int;


class t_gun_component
{
public:
    t_gun_component(const t_go_identifier_value identifier, const t_elevation_degrees_value elevation_degrees);
    t_gun_component(const t_elevation_degrees_value elevation_degrees);

    const t_identifier_value get_identifier() const;

    const t_elevation_radians_value get_elevation() const;

    const bool single() const
    {
        return _amount == 1;
    }

    const bool dual() const
    {
        return _amount == 2;
    }

    const t_weight_value get_weight() const;

    const t_shot_damage_value get_shot_damage() const;

    const t_cooldown_time_millis_value get_cooldown_time() const;

protected:
    const t_go_identifier_value     _identifier {};

    t_elevation_radians_value       _elevation_radians {};

    t_gun_amount_value              _amount { 1 };

    t_shot_damage_value             _shot_damage { 100 };

    t_cooldown_time_millis_value    _cooldown_time { 250 };

public:
    static const t_component_identifier_value t_part { t_component_identifier_value::t_gun };
};
