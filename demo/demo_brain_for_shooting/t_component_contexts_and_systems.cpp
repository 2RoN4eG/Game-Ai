#include "t_component_contexts_and_systems.hpp"

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

//
t_enemy_context t_get_random_enemy(int x_range_minimum, int x_ramge_maximum, int y_range_minimum, int y_ramge_maximum)
{
    const int x_range = (x_ramge_maximum - x_range_minimum);

    const float x = random() % x_range + x_range_minimum;


    const int y_range = (y_ramge_maximum - y_range_minimum);

    const float y = random() % y_range + y_range_minimum;


    qDebug() << "enemy locates on position x: " << x << " y: " << y;

    return t_enemy_context { 100, x, y };
}

//
bool t_is_weapon_reloading(const t_weapon_context& context)
{
    return context.cooldown_time > 0.;
}

//
bool t_is_course_reached(const t_rotation_context& context)
{
    return context.heading == context.course;
}

// функция, изменяющая heading в сторону course с учетом времени
void t_rotation_system_updater(t_rotation_context& context, const float deltaTime)
{
    // функция, изменяющая heading в сторону course с учетом времени

    float difference { context.course - context.heading };

    // нормализация разницы углов (-180. до 180. градусов)
    if (difference >  180) difference -= 360.;
    if (difference < -180) difference += 360.;

    // ограничение скорости поворота
    const float step = context.angular_speed * deltaTime;

    if (std::fabs(difference) < step)
    {
        // Если угол уже близко, просто устанавливаем целевой

        context.heading = context.course;
    }
    else
    {
        // Двигаемся к цели

        context.heading += (difference > 0) ? step : -step;
    }
}

bool t_is_shoot_possible(const t_weapon_context& weapon)
{
    return weapon.cooldown_time <= 0.;
}

bool t_projectile_spawner(t_shooting_game_scene& game_scene, t_weapon_context& weapon)
{
    // getting projectile holder ...

    // creating projectile { x, y, damage } into ...
}

void t_shooting_system_updater(t_shooting_game_scene& game_scene, t_weapon_context& weapon, const float delta)
{
    if (t_is_shoot_possible(weapon) == false)
    {
        qDebug () << "shooting is not possible, cooldown time is " << weapon.cooldown_time;

        return;
    }

    t_projectile_spawner(game_scene, weapon);
}

void t_moving_system_updater(t_moving_context_holder& holder, const float delta)
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

void t_ai_system_updater(const float delta)
{
}

bool t_ai_is_shoot_possible()
{
    // is weapon reached necesesary cource?

    // is weapon ready to shoot (cooldown time is zero or less, projectiles are not an empty)?

    return {};
}

bool does_projectile_collide_with_anything(t_shooting_game_scene& game_scene, const t_projectile_context& projectile)
{
    // for ()
    // {
    // }

    return {};
}

void t_projectile_collision_system_updater(t_shooting_game_scene& game_scene)
{
    for (const t_projectile_context& projectile : g_projectile_context_holder)
    {
    }
}
