#pragma once

#include "../t_component_defines.hpp"


class t_shell_component
{
public:
    t_shell_component(const t_identifier_value identifier);

    const t_identifier_value get_identifier() const;

    const t_weight_value get_weight() const;

protected:
    const t_identifier_value    _identifier {};

    const t_weight_value        _weight {};
};
