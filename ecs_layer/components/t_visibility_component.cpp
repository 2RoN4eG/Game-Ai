#include "t_visibility_component.hpp"


t_visibility_component::t_visibility_component(const t_go_identifier_value go_identifier,
                                                 const t_visibility_distance_value distance)
    : _go_identifier { go_identifier }
    , _distance { distance }
{
}

const t_identifier_value t_visibility_component::get_go_identifier() const
{
    return _go_identifier;
}

const t_visibility_distance_value t_visibility_component::get_distance() const
{
    return _distance;
}
