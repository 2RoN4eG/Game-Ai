#pragma once

#include "../tools/t_2d_vector.hpp"
#include "../tools/t_2d_vector.hpp"


class t_dynamic_component_interface
{
};


class t_shell_component
{
public:
    t_shell_component(const t_identifier_value identifier);

    const t_identifier_value get_identifier() const;

    const t_weight_value get_weight() const;

protected:
    const t_identifier_value    _identifier {};

    const t_weight_value        _weight {};

    t_2d_position_value         _position {};
};
