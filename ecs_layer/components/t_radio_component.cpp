#include "t_radio_component.hpp"


t_radio_component::t_radio_component(const t_go_identifier_value identifier, const t_radio_distance_value distance)
    : _identifier { identifier }
    , _distance { distance }
{
}

const t_identifier_value t_radio_component::get_identifier() const
{
    return _identifier;
}

const t_radio_distance_value t_radio_component::get_distance() const
{
    return _distance;
}


void t_set_radio_distance(t_radio_component& radio, const t_radio_distance_value distance)
{
    radio._distance = distance;
}
