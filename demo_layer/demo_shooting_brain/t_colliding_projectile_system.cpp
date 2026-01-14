#include "t_colliding_projectile_system.hpp"

#include "t_shooting_game_scene.hpp"


t_colliding_projectile_system::t_colliding_projectile_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_colliding_projectile_system::update(const t_update_delta_time_value  sdelta_time)
{
    const t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_entry_holder<t_projectile_context>();

    // if (projectile_holder.amount())
    // {
    //     std::cout << "holder contains " << projectile_holder.amount() << " projectiles" << std::endl;
    // }

    t_enemy_context& enemy = get_shooting_brain_game_scene_mutable_context<t_enemy_context>(_game_scene);

    const t_position_context& enemy_position = enemy.position;

    for (const t_projectile_context& projectile : projectile_holder)
    {
        // TODO: Подумать не стоит ли оперировать сразу итераторами внутри данного цикла?

        const t_position_context& projectile_position = projectile._position;

        const t_distance_value distance = t_get_distance(enemy_position, projectile_position);

        const t_radius_value projectile_heat_radius = projectile._collision_radius;

        if (projectile_heat_radius < distance)
        {
            // Если дистанция между снарядом и врагом больше радиуса для столкновения, то
            // пропускаем данный снаряд.

            continue;
        }

        t_health_points_value& enemy_health_points = enemy.health_points;

        // TODO: alias projectile._heat_damage

        enemy_health_points -= projectile._heat_damage;

        // std::cout << "projectile { identifier } hits enemy { identifier }, distance is " << distance << ", radius is " << radius << std::endl;

        t_entry_holder<t_remove_projectile_event>& remove_projectile_event_holder = _game_scene.get_mutable_entry_holder<t_remove_projectile_event>();

        remove_projectile_event_holder.create_component(projectile._identifier);

        std::cerr << "remove_projectile_event_holder amount is " << remove_projectile_event_holder.amount() << std::endl;
    }
}
