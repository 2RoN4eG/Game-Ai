#include "t_gun_component.hpp"

#include "../tools/t_2d_vector.hpp"


t_gun_component::t_gun_component(const t_go_identifier_value identifier, const t_elevation_degrees_value elevation_degrees)
    : _go_identifier { identifier }
    , _elevation_radians { t_convert_degrees_to_radians(elevation_degrees) }
{
}

t_gun_component::t_gun_component(const t_elevation_degrees_value elevation_degrees)
    : t_gun_component { {}, t_convert_degrees_to_radians(elevation_degrees) }
{
}

const t_elevation_radians_value t_gun_component::get_elevation() const
{
    return _elevation_radians;
}

const t_weight_value t_gun_component::get_weight() const
{
    return t_weight_value {};
}
