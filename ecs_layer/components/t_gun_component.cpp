#include "t_gun_component.hpp"

#include "../tools/t_2d_vector.hpp"


t_gun_component::t_gun_component(const t_elevation_degrees_value elevation_degrees)
    : _elevation_radians { t_convert_degrees_to_radians(elevation_degrees) }
{
}

const t_elevation_radians_value t_gun_component::get_elevation() const
{
    return _elevation_radians;
}
