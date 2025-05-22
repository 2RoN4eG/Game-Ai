#include "t_turret_component.hpp"

#include "../tools/t_2d_vector.hpp"


t_turret_component::t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                                       const t_elevation_degrees_value gun_elevation_degrees)
    : _azimuth_radians { t_convert_degrees_to_radians(azimuth_degrees) }
    , _gun { gun_elevation_degrees }
    , _visibility { {}, {} }
{
}

t_turret_component::t_turret_component(const t_azimuth_degrees_value azimuth_degrees,
                                       const t_gun_component& gun)
    : _azimuth_radians { t_convert_degrees_to_radians(azimuth_degrees) }
    , _gun { gun }
    , _visibility { {}, {} }
{
}

const t_identifier_value t_turret_component::get_identifier() const
{
    return _identifier;
}

const t_azimuth_degrees_value t_turret_component::get_azimuth() const
{
    return _azimuth_radians;
}

const t_elevation_degrees_value t_turret_component::get_elevation() const
{
    return _gun.get_elevation();
}

t_visibility_component& t_turret_component::get_mutable_visibility()
{
    return _visibility;
}

t_gun_component& t_turret_component::get_mutable_gun()
{
    return _gun;
}

const t_weight_value t_turret_component::get_weight() const
{
    return _weight + _gun.get_weight();
}
