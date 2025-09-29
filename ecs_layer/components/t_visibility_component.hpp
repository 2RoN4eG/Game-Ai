#pragma once

#include "../tools/t_2d_vector.hpp"


class t_visibility_component
{
public:
    t_visibility_component(const t_go_identifier_value identifier,
                           const t_distance_value distance);

    ~t_visibility_component() = default;

    const t_identifier_value get_identifier() const;

    const t_distance_value get_distance() const;

private:
    const t_identifier_value _identifier {};

    t_distance_value _distance {};

private:
    friend void t_set_visibility_distance(t_visibility_component& visibility, t_distance_value distance);

public:
    static const t_component_enumenated_value t_part { t_component_enumenated_value::t_visibility };
};


using t_vehicle_visibility_component = t_visibility_component;
