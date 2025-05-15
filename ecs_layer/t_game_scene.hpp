#pragma once

#include "t_entry_holder.hpp"

#include "components/t_vehicle_component.hpp"
#include "components/t_shell_component.hpp"

#include "effects/t_shell_shock_effect.hpp"


class t_game_database;


class t_game_scene
    : public t_entry_holder<t_engine_component>
    , public t_entry_holder<t_chassis_component>
    , public t_entry_holder<t_gun_component>
    , public t_entry_holder<t_turret_component>
    , public t_entry_holder<t_radio_component>
    , public t_entry_holder<t_shell_component>
    , public t_entry_holder<t_shell_shock_effect>
{
public:
    template <typename t_entry>
    t_entry_holder<t_entry>& get_component_holder()
    {
        return *this;
    }
};


void create_game_scene_entity(const t_vehicle_entity& entity, const t_game_database& database, t_game_scene& game_scene);


using t_player_identifier_value = t_identifier_value;
