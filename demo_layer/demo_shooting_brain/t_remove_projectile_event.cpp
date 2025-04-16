#include "t_remove_projectile_event.hpp"

t_remove_projectile_event::t_remove_projectile_event(t_projectile_identifier_value projectile_identifier)
    : _projectile_identifier { projectile_identifier }
{
}

t_projectile_identifier_value t_remove_projectile_event::projectile_identifier() const
{
    return _projectile_identifier;
}
