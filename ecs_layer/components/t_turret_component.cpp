#include "t_turret_component.hpp"

#include "../tools/t_2d_vector.hpp"


t_turret_component::t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                                       const t_elevation_degrees_value elevation_degrees)
    : _azimuth_radians { t_convert_degrees_to_radians(azimuth_degrees) }
    , _gun { elevation_degrees }
{
}

const t_azimuth_degrees_value t_turret_component::get_azimuth() const
{
    return _azimuth_radians;
}

const t_elevation_degrees_value t_turret_component::get_elevation() const
{
    return _gun.get_elevation();
}

t_gun_component& t_turret_component::get_mutable_gun()
{
    return _gun;
}
