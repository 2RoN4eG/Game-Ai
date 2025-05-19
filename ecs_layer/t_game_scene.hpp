#pragma once

#include "t_entry_holder.hpp"

#include "components/t_vehicle_component.hpp"
#include "components/t_shell_component.hpp"
#include "components/t_vehicle_entity.hpp"
#include "components/t_detected_target_component.hpp"

#include "effects/t_shell_shock_effect.hpp"


class t_game_database;


class t_game_scene
    : public t_entry_holder<t_engine_component>
    , public t_entry_holder<t_chassis_component>
    , public t_entry_holder<t_gun_component>
    , public t_entry_holder<t_turret_component>
    , public t_entry_holder<t_radio_component>
    , public t_entry_holder<t_vehicle_component>
    , public t_entry_holder<t_detected_target_component>
    , public t_entry_holder<t_shell_component>
    , public t_entry_holder<t_shell_shock_effect>
{
public:
    template <typename t_entry>
    t_entry_holder<t_entry>& get_mutable_entry_holder()
    {
        return *this;
    }

    template <typename t_entry>
    const t_entry_holder<t_entry>& get_entry_holder() const
    {
        return *this;
    }
};


using t_game_scene_vehicle_components = std::vector<t_vehicle_component>;


inline const t_game_scene_vehicle_components& get_game_scene_vehicles(const t_game_scene& game_scene)
{
    const t_entry_holder<t_vehicle_component>& entry_holder = game_scene.get_entry_holder<t_vehicle_component>();

    // TODO: Think how to get vehicles from entry_holder ...

    return t_game_scene_vehicle_components {};
}


t_game_scene create_2_vehicles_game_scene(const t_game_database& database);


using t_player_identifier_value = t_identifier_value;
