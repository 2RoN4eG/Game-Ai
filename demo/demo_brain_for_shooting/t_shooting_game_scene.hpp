#pragma once

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"


class t_shooting_game_scene : public t_entry_holder_aggregator<t_enemy_context,
                                                               t_weapon_context,
                                                               t_moving_context,
                                                               t_rotation_context,
                                                               t_projectile_context,
                                                               t_player_context,
                                                               t_drawable_weapon_context>
{
};

template <typename t_context>
inline t_context& t_shooting_game_scene_get_mutable_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_context>& enemy_holder = game_scene.get_mutable_entry_holder<t_context>();

    return enemy_holder.get_mutable_component();
}


inline t_rotation_context& t_shooting_game_scene_get_rotation_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_rotation_context>& rotation_holder = game_scene.get_mutable_entry_holder<t_rotation_context>();

    return rotation_holder.get_mutable_component();
}

inline t_enemy_context& t_shooting_game_scene_get_mutable_enemy_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_enemy_context>& enemy_holder = game_scene.get_mutable_entry_holder<t_enemy_context>();

    return enemy_holder.get_mutable_component();
}

inline t_weapon_context& t_shooting_game_scene_get_mutable_weapon_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_weapon_context>& weapon_holder = game_scene.get_mutable_entry_holder<t_weapon_context>();

    return weapon_holder.get_mutable_component();
}

inline const t_weapon_context& t_shooting_game_scene_get_weapon_context(t_shooting_game_scene& game_scene)
{
    const t_entry_holder<t_weapon_context>& weapon_holder = game_scene.get_entry_holder<t_weapon_context>();

    return weapon_holder.get_component();
}

inline t_rotation_context& t_shooting_game_scene_get_mutable_rotation_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_rotation_context>& rotation_holder = game_scene.get_mutable_entry_holder<t_rotation_context>();

    return rotation_holder.get_mutable_component();
}
