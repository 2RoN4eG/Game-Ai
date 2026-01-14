#pragma once

// #include "../tools/t_2d_vector.hpp"

#include "../tools/t_2d_vector.hpp"


class t_radio_component
{
public:
    static const t_enumerated_component_value t_part { t_enumerated_component_value::t_radio };

public:
    t_radio_component() = default;
    t_radio_component(const t_go_identifier_value identifier, const t_radio_distance_value distance);

    ~t_radio_component() = default;

    const t_identifier_value get_identifier() const;

    const t_radio_distance_value get_distance() const;

private:
    const t_identifier_value    _identifier {};

    t_radio_distance_value      _distance {};

private:
    friend void t_set_radio_distance(t_radio_component& radio, const t_radio_distance_value distance);
};


using t_vehicle_radio_component = t_radio_component;
