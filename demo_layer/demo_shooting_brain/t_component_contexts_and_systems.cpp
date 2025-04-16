#include "t_component_contexts_and_systems.hpp"

#include "t_shooting_game_scene.hpp"

#include <vector>

#include <QDebug>


namespace
{
    using t_ui_event = std::string_view;
}


std::vector<t_ui_event>              g_ui_event_holder {};

t_moving_context_holder              g_moving_context_holder {};

t_projectile_context_holder          g_projectile_context_holder {};


bool t_is_alive(const t_enemy_context& context)
{
    return context.health_points > 0;
}

bool t_is_dead(const t_enemy_context& context)
{
    return context.health_points == 0;
}

bool t_is_weapon_reloading(const t_weapon_context& context)
{
    return context.cooldown_time > 0.;
}

inline t_position_context get_rotated_gun_position(const t_drawable_weapon_context& gun, const t_rotation_context& rotation)
{
    const t_position_context gun_position = gun.position;

    const t_axis_value       gun_length   = gun.length;
    const t_axis_value       gun_heading  = rotation._heading;

    // TODO: Replace gun_position.x/y() + gun_length * std::cos/std::sin(gun_heading * M_PI / 180.f)

    const t_axis_value       end_of_gun_x = gun_position.x() + gun_length * std::cos(gun_heading * M_PI / 180.f);
    const t_axis_value       end_of_gun_y = gun_position.y() + gun_length * std::sin(gun_heading * M_PI / 180.f);

    return t_position_context { end_of_gun_x, end_of_gun_y };
}

bool t_heading_has_reached_its_course(const t_rotation_context& rotation)
{
    return rotation._heading == rotation._course;
}

// функция, изменяющая heading в сторону course с учетом времени
void t_rotation_system_updater(t_rotation_context& rotation, const float delta_time)
{
    // функция, изменяющая heading в сторону course с учетом времени между кадрами

    float difference { rotation._course - rotation._heading };

    // нормализация разницы углов (-180. до 180. градусов)
    if (difference >  180.) difference -= 360.;
    if (difference < -180.) difference += 360.;

    // ограничение скорости поворота
    const float step = rotation._angular_speed * delta_time;

    if (std::fabs(difference) < step)
    {
        // Если угол уже близко, просто устанавливаем целевой

        rotation._heading = rotation._course;
    }
    else
    {
        // Двигаемся к цели

        rotation._heading += (difference > 0) ? step : -step;
    }
}

bool t_is_weapon_ready_for_shoot(const t_weapon_context& weapon)
{
    return weapon.cooldown_time <= 0.;
}

bool t_projectile_spawner(t_shooting_game_scene& game_scene, t_weapon_context& weapon)
{
    // getting projectile holder ...

    // creating projectile { x, y, damage } into ...

    return {};
}

void t_shooting_system_updater(t_shooting_game_scene& game_scene, t_weapon_context& weapon, const float delta)
{
    if (t_is_weapon_ready_for_shoot(weapon) == false)
    {
        qDebug () << "shooting is not possible, cooldown time is " << weapon.cooldown_time;

        return;
    }
}

void t_moving_system_updater(t_moving_context_holder& holder, const float delta)
{
    for (t_moving_context& context : holder)
    {
        const t_velocity_context step = context.velocity * delta;

        context.position = context.position + step;
    }
}

void t_projectile_moving_system_updater(t_moving_context_holder& holder, const float delta)
{
    for (t_moving_context& context : holder)
    {
        const t_velocity_context step = context.velocity * delta;

        context.position = context.position + step;
    }
}

void t_weapon_cooldown_runner(t_weapon_context& weapon)
{
    weapon.cooldown_time = weapon.reloading_time;
}

void t_weapon_cooldown_updater(t_weapon_context& weapon, const float delta)
{
    weapon.cooldown_time -= delta;
}

void t_colliding_projectile_system_updater(t_shooting_game_scene& game_scene, const float delta)
{
    const t_entry_holder<t_projectile_context>& projectile_holder = game_scene.get_entry_holder<t_projectile_context>();

    const t_entry_holder<t_enemy_context>& enemy_holder = game_scene.get_entry_holder<t_enemy_context>();

    const t_enemy_context& enemy = enemy_holder.get_component();

    const t_position_context& enemy_position = enemy.position;

    // const t_size_context& enemy_size = enemy.size;

    // const t_2d_vector_axis_value x_lhs { enemy_position.x() - enemy_size.width()  / 2 };
    // const t_2d_vector_axis_value x_rhs { enemy_position.x() + enemy_size.width()  / 2 };
    // const t_2d_vector_axis_value y_lhs { enemy_position.y() - enemy_size.height() / 2 };
    // const t_2d_vector_axis_value y_rhs { enemy_position.y() + enemy_size.height() / 2 };

    for (const t_projectile_context& projectile : g_projectile_context_holder)
    {
        const t_position_context& projectile_position = projectile._position;

        t_distance_value distance = t_get_distance(projectile_position, enemy_position);

        // const bool has_collided {
        //     projectile_position.x() >= x_lhs && projectile_position.x() <= x_rhs &&
        //     projectile_position.y() >= y_lhs && projectile_position.y() <= y_rhs
        // };
    }
}

void t_moving_projectile_system_updater(t_shooting_game_scene& game_scene, const float delta_time)
{
    t_entry_holder<t_projectile_context>& projectile_holder = game_scene.get_mutable_entry_holder<t_projectile_context>();

    for (t_projectile_context& projectile : projectile_holder)
    {
        const t_velocity_context step = projectile._velocity * delta_time;

        projectile._position = projectile._position + step;
    }
}

void t_weapon_cooldown_system_updater(t_shooting_game_scene& game_scene, const float delta_time)
{
    t_entry_holder<t_weapon_context>& weapon_holder = game_scene.get_mutable_entry_holder<t_weapon_context>();

    for (t_weapon_context& weapon : weapon_holder)
    {
        weapon.cooldown_time -= delta_time;
    }
}
