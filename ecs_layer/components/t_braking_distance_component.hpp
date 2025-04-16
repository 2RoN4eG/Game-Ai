#pragma once

#include "../tools/t_2d_vector.hpp"


class t_braking_distance_component
{
public:
    t_braking_distance_component(const t_identifier_value identifier);

    ~t_braking_distance_component() = default;

    const t_identifier_value get_identifier() const;

    const t_distance_value get_distance() const;

private:
    const t_identifier_value _identifier {};

    t_distance_value _distance {};

private:
    friend class t_braking_distance_system;
};
