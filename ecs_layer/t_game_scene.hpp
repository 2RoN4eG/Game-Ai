#pragma once

#include "t_entry_holder_aggregator.hpp"

#include "components/t_vehicle_component.hpp"
#include "components/t_shell_component.hpp"
#include "components/t_vehicle_entity.hpp"
#include "components/t_detected_enemy_component.hpp"
#include "components/t_braking_distance_component.hpp"
#include "components/t_braking_control_component.hpp"

#include "effects/t_shell_shock_effect.hpp"


class t_game_database;


class t_game_scene : public t_entry_holder_aggregator<
        t_engine_component,
        t_chassis_component,
        t_gun_component,
        t_turret_component,
        t_radio_component,
        t_visibility_component,
        t_detected_enemy_component,
        //
        t_vehicle_component,
        //
        t_braking_control_component,
        t_braking_distance_component,
        //
        t_shell_component,
        // effects
        t_shell_shock_effect
    >
{
};


using t_game_scene_vehicle_components = std::vector<t_vehicle_component>;


t_game_scene create_2_vehicles_game_scene(const t_game_database& database);


void create_game_scene_vehicle(t_game_scene& game_scene);


using t_player_identifier_value = t_identifier_value;


template <typename t_component, typename... t_arguments>
inline void set_game_scene_component(const t_game_scene& game_scene, t_arguments&&... arguments)
{
    t_entry_holder<t_component>& entry_holder = game_scene.get_mutable_entry_holder<t_component>();

    entry_holder.create_component(std::forward<t_arguments>(arguments)...);
}
