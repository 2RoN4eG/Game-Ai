#include "t_shooting_ai_brain_system.hpp"

#include <vector>

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"
#include "t_shooting_game_scene.hpp"


namespace
{

}


t_shooting_ai_brain_system::t_shooting_ai_brain_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
    , _rotation_context { get_shooting_brain_game_scene_mutable_context<t_rotation_context>(game_scene) }
    , _enemy_context { get_shooting_brain_game_scene_mutable_context<t_enemy_context>(game_scene) }
    , _weapon_context { get_shooting_brain_game_scene_mutable_context<t_weapon_context>(game_scene) }
{
}

void t_shooting_ai_brain_system::update(const t_update_delta_time delta_time)
{
    // is weapon reached necesesary cource?

    if (t_heading_has_reached_its_course(_rotation_context) == false)
    {
        return;
    }

    // std::cout << "[brain] heading has reached its course ..." << std::endl;

    if (t_is_alive(_enemy_context) == false)
    {
        return;
    }

    // std::cout << "[brain] enemy is alive (health points are " << _enemy_context.health_points << ") ..." << std::endl;

    // is weapon ready to shoot (cooldown time is zero or less, projectiles are not an empty)?

    if (t_is_weapon_ready_for_shoot(_weapon_context) == false)
    {
        return;
    }

    // std::cout << "[brain] weapon is ready to shoot (cooldown remaining: " << _weapon_context.cooldown_time << " milliseconds)" << std::endl;

    // spawn projectile

    const t_drawable_weapon_context& drawable_weapon = get_shooting_brain_game_scene_context<t_drawable_weapon_context>(_game_scene);

    const t_rotation_context& rotation = get_shooting_brain_game_scene_context<t_rotation_context>(_game_scene);

    const t_position_context& projectile_position = get_rotated_length_point(drawable_weapon, rotation);

    const t_enemy_context& enemy = get_shooting_brain_game_scene_context<t_enemy_context>(_game_scene);

    const t_position_context& enemy_position = enemy.position;

    const t_position_context& distance = enemy_position - projectile_position;

    const t_position_context& normilized = t_normilize_vector(distance);

    const t_speed_value projectile_speed = _weapon_context.projectile_speed;

    const t_position_context& projectile_velocity = normilized * projectile_speed;

    const t_collision_radius_value collision_radius { 5 };

    t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_mutable_entry_holder<t_projectile_context>();

    projectile_holder.create_component(t_projectile_identifier_value {}, _weapon_context.heat_damage, collision_radius, projectile_position, projectile_velocity);

    t_weapon_cooldown_runner(_weapon_context);
}
