#include "t_visibility_component.hpp"


t_visibility_component::t_visibility_component(const t_go_identifier_value identifier,
                                                 const t_visibility_distance_value distance)
    : _identifier { identifier }
    , _distance { distance }
{
}

const t_identifier_value t_visibility_component::get_identifier() const
{
    return _identifier;
}

const t_visibility_distance_value t_visibility_component::get_distance() const
{
    return _distance;
}


void t_set_visibility_distance(t_visibility_component& visibility, t_distance_value distance)
{
    visibility._distance = distance;
}
