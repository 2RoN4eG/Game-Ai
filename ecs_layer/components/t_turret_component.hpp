#ifndef T_TURRET_COMPONENT_HPP
#define T_TURRET_COMPONENT_HPP

#include "../tools/t_2d_vector.hpp"

#include "t_gun_component.hpp"
#include "t_visibility_component.hpp"


class t_turret_component
{
public:
    t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                       const t_elevation_degrees_value gun_elevation_degrees);

    t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                       const t_gun_component& gun);

    const t_identifier_value get_identifier() const;

    const t_azimuth_degrees_value get_azimuth() const;

    const t_elevation_degrees_value get_elevation() const;

    const t_weight_value get_weight() const;

    t_visibility_component& get_mutable_visibility();

    t_gun_component& get_mutable_gun();

protected:
    const t_identifier_value    _identifier {};

    t_gun_component             _gun;

    t_visibility_component      _visibility;

    t_weight_value              _weight {};

    t_azimuth_radians_value     _azimuth_radians {};

public:
    static const t_component_enumenated_value t_part { t_component_enumenated_value::t_turret };
};

#endif // T_TURRET_COMPONENT_HPP
