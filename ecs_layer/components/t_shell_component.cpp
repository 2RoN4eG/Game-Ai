#include "t_shell_component.hpp"


t_shell_component::t_shell_component(const t_identifier_value identifier)
    : _identifier { identifier }
{
}

const t_identifier_value t_shell_component::get_identifier() const
{
    return _identifier;
}

const t_weight_value t_shell_component::get_weight() const
{
    return _weight;
}
