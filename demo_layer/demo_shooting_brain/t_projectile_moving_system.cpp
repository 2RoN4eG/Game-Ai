#include "t_projectile_moving_system.hpp"

#include "t_shooting_game_scene.hpp"


t_projectile_moving_system::t_projectile_moving_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_projectile_moving_system::update(const t_update_delta_time_value delta_time)
{
    t_entry_holder<t_projectile_context>& projectile_holder = _game_scene.get_mutable_entry_holder<t_projectile_context>();

    for (t_projectile_context& projectile : projectile_holder)
    {
        t_position_context& projectile_position = projectile._position;

        const t_velocity_context& projectile_velocity = projectile._velocity;

        const t_position_context& step = projectile_velocity * delta_time;

        // std::cout << "projectile position " << projectile_position.x() << ", " << projectile_position.y()
        //           << ", velocity " << projectile_velocity.x() << ", " << projectile_velocity.y()
        //           << ", step " << step.x() << ", " << step.y()
        //           << std::endl;

        projectile_position = projectile_position + step;
    }
}
