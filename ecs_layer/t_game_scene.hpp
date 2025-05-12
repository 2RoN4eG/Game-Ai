#pragma once

#include "t_component_holder.hpp"
#include "t_get_component_holder.hpp"

#include "components/t_vehicle_component.hpp"
#include "components/t_shell_component.hpp"


class t_game_database;


class t_game_scene
    : public t_get_component_holder
    , public t_component_holder<t_vehicle_component>
    , public t_component_holder<t_shell_component>
{
public:
    template <typename t_component>
    t_component_holder<t_component>& get_component_holder()
    {
        return *this;
    }
};


void create_game_scene(const t_game_database& database);
