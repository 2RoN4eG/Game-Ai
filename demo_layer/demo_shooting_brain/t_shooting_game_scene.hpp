#pragma once

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"
#include "t_remove_projectile_event.hpp"


class t_shooting_game_scene : public t_entry_holder_aggregator<t_enemy_context,
                                                               t_weapon_context,
                                                               t_rotation_context,
                                                               t_projectile_context,
                                                               t_player_context,
                                                               t_drawable_weapon_context,
                                                               t_remove_projectile_event>
{
};

template <typename t_context>
inline t_context& get_shooting_brain_game_scene_mutable_context(t_shooting_game_scene& game_scene)
{
    t_entry_holder<t_context>& entry_holder = game_scene.get_mutable_entry_holder<t_context>();

    return entry_holder.get_mutable_component();
}

template <typename t_context>
inline const t_context& get_shooting_brain_game_scene_context(const t_shooting_game_scene& game_scene)
{
    const t_entry_holder<t_context>& entry_holder = game_scene.get_entry_holder<t_context>();

    return entry_holder.get_component();
}
