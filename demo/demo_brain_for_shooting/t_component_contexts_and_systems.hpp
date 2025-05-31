#ifndef T_COMPONENT_CONTEXTS_AND_SYSTEMS_H
#define T_COMPONENT_CONTEXTS_AND_SYSTEMS_H

#include <vector>

#include "../../ecs_layer/tools/t_2d_vector.hpp"

class t_shooting_game_scene;


using t_identifier              = int;

using t_projectile_identifier   = int;

using t_weapon_identifier       = int;

using t_integral_value          = int;

using t_floating_value          = float;

using t_axis_value              = t_floating_value;

using t_position_context        = t_2d_vector_value;

using t_velocity_context        = t_2d_vector_value;


struct t_moving_context
{
    t_identifier            identifier {};

    t_position_context      position {};

    t_velocity_context      velocity {};
};

struct t_enemy_context
{
    t_integral_value health_points;

    t_position_context position {};

    t_enemy_context(const t_integral_value health_points, const t_axis_value x, const t_axis_value y)
        : health_points { health_points }
        , position { x, y }
    {
    }

    t_enemy_context()
        : t_enemy_context { {}, {}, {} }
    {
    }
};

struct t_rotation_context
{
    // Структура для управления углом вращения

    t_floating_value heading;          // Текущий угол (градусы)
    t_floating_value course;           // Целевой угол (градусы)

    t_floating_value angular_speed;    // Скорость поворота (градусы/секунда)
};

struct t_projectile_context
{
    t_projectile_identifier identifier {};

    int                     heat_damage {};

    // collision radius
    int                     radius {};

    t_position_context      position {};
};

struct t_cooldown_cache_context
{
    t_weapon_identifier identifier {};

    t_floating_value    cooldown_time {};   // Остаток времени до готовности
};

struct t_weapon_context
{
    t_floating_value           heat_damage {};          // _per_shot

    const t_floating_value     reloading_time { 10. };  // Время перезарядки оружия (миллисекунды (ms))

    t_floating_value           cooldown_time {};        // Остаток времени до готовности
};

using t_moving_context_holder       = std::vector<t_moving_context>;

using t_projectile_context_holder   = std::vector<t_projectile_context>;


extern t_moving_context_holder      g_moving_context_holder;

extern t_projectile_context_holder  g_projectile_context_holder;


bool t_is_alive(const t_enemy_context& context);

t_enemy_context t_get_random_enemy(int x_range_minimum, int x_ramge_maximum, int y_range_minimum, int y_ramge_maximum);

bool t_is_weapon_reloading(const t_weapon_context& context);

bool t_is_course_reached(const t_rotation_context& context);

void t_rotation_system_updater(t_rotation_context& context, const float deltaTime);

bool t_is_shoot_possible(const t_weapon_context& weapon);

bool t_projectile_spawner(t_shooting_game_scene& game_scene, t_weapon_context& weapon);

void t_shooting_system_updater(t_shooting_game_scene& game_scene, t_weapon_context& weapon, const float delta);

void t_moving_system_updater(t_moving_context_holder& moving, const float delta);

void t_weapon_cooldown_runner(t_weapon_context& weapon);

void t_weapon_cooldown_updater(t_weapon_context& weapon, const float delta);

void t_ai_system_updater(const float delta);

bool t_ai_is_shoot_possible();

bool does_projectile_collide_with_anything(t_shooting_game_scene& game_scene, const t_projectile_context& projectile);

void t_projectile_collision_system_updater(t_shooting_game_scene& game_scene);

#endif // T_COMPONENT_CONTEXTS_AND_SYSTEMS_H
