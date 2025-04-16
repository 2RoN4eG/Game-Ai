#ifndef T_TURRET_COMPONENT_HPP
#define T_TURRET_COMPONENT_HPP

#include "../t_component_defines.hpp"

#include "t_gun_component.hpp"


class t_turret_component
{
public:
    t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                       const t_elevation_degrees_value elevation_degrees);

    const t_azimuth_degrees_value get_azimuth() const;

    const t_elevation_degrees_value get_elevation() const;

    t_gun_component& get_mutable_gun();

protected:
    t_azimuth_radians_value _azimuth_radians;

    t_gun_component _gun;
};

#endif // T_TURRET_COMPONENT_HPP
