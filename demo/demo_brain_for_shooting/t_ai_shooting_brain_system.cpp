#include "t_ai_shooting_brain_system.hpp"

#include <vector>

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"
#include "t_shooting_game_scene.hpp"


namespace
{

}


t_ai_shooting_brain_system::t_ai_shooting_brain_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
    , _rotation_context { t_shooting_game_scene_get_rotation_context(game_scene) }
    , _enemy_context { t_shooting_game_scene_get_mutable_enemy_context(game_scene) }
    , _weapon_context { t_shooting_game_scene_get_mutable_weapon_context(game_scene) }
{
}

void t_ai_shooting_brain_system::update(const t_update_delta_time delta_time)
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

    const /*t_collision_radius*/ int collision_radius { 5 };

    t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_mutable_entry_holder<t_projectile_context>();

    projectile_holder.create_component(t_projectile_identifier_value {}, _weapon_context.heat_damage, collision_radius, t_position_context {}, t_velocity_context {});

    std::cout << "[brain] projectiles amount is " << projectile_holder.amount() << std::endl;

    t_weapon_cooldown_runner(_weapon_context);
}
