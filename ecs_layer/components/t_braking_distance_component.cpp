#include "t_braking_distance_component.hpp"


t_braking_distance_component::t_braking_distance_component(const t_identifier_value identifier)
    : _identifier { identifier }
{
}

const t_identifier_value t_braking_distance_component::get_identifier() const
{
    return _identifier;
}

const t_distance_value t_braking_distance_component::get_distance() const
{
    return _distance;
}
