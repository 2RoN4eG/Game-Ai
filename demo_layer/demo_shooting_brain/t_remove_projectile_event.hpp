#ifndef T_REMOVE_PROJECTILE_EVENT_H
#define T_REMOVE_PROJECTILE_EVENT_H

#include "t_defines.hpp"

#include "t_component_contexts_and_systems.hpp"


class t_remove_projectile_event
{
public:
    t_remove_projectile_event(t_projectile_identifier_value projectile_identifier);

    t_projectile_identifier_value projectile_identifier() const;

private:
    t_projectile_identifier_value _projectile_identifier {};
};

#endif // T_REMOVE_PROJECTILE_EVENT_H
