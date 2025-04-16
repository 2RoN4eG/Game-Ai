#pragma once

#include "../t_component_defines.hpp"


class t_radio_component
{
public:
    t_radio_component() = default;
    t_radio_component(const t_go_identifier_value go_identifier, const t_radio_distance_value distance);

    ~t_radio_component() = default;

    const t_identifier_value get_go_identifier() const;

    const t_radio_distance_value get_distance() const;

private:
    const t_identifier_value    _go_identifier {};

    t_radio_distance_value      _distance {};
};
