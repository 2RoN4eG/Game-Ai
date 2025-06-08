#include "t_projectile_collision_system.hpp"

#include "t_shooting_game_scene.hpp"


t_projectile_collision_system::t_projectile_collision_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_projectile_collision_system::update(const t_update_delta_time delta_time)
{
    const t_enemy_context& enemy = t_shooting_game_scene_get_context<t_enemy_context>(_game_scene);

    const t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_entry_holder<t_projectile_context>();

    if (projectile_holder.amount())
    {
        std::cout << "holder contains " << projectile_holder.amount() << " projectiles" << std::endl;
    }

    const t_position_context& enemy_position = enemy.position;

    for (const t_projectile_context& projectile : projectile_holder)
    {
        const t_position_context& projectile_position = projectile._position;

        const t_distance_value distance = t_get_distance(enemy_position, projectile_position);

        const t_radius_value radius = projectile._radius;

        if (distance > radius)
        {
            continue;
        }

        std::cout << "projectile { identifier } hits enemy { identifier }, distance is " << distance << ", radius is " << radius << std::endl;
    }
}
