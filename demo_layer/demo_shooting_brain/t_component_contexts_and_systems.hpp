#ifndef T_COMPONENT_CONTEXTS_AND_SYSTEMS_H
#define T_COMPONENT_CONTEXTS_AND_SYSTEMS_H

#include <vector>

#include "../../ecs_layer/tools/t_2d_vector.hpp"

#include <cmath>


class t_shooting_game_scene;


using t_long_value                  = long;

using t_long_long_value             = long long;

using t_floating_value              = float;

using t_axis_value                  = t_2d_vector_axis_value;

using t_length_value                = t_axis_value;

using t_position_context            = t_2d_vector_value;

using t_velocity_context            = t_2d_vector_value;

using t_heat_damage_value           = t_floating_value;

using t_radius_value                = t_floating_value;

using t_collision_radius_value      = t_radius_value;

using t_projectile_identifier_value = t_go_identifier_value;

using t_weapon_identifier_value     = t_go_identifier_value;

using t_integral_value              = t_long_value;

using t_context_descriptor          = std::string_view;


struct t_moving_context
{
    t_identifier_value      identifier {};

    t_position_context      position {};

    t_velocity_context      velocity {};

    static t_context_descriptor get_description()
    {
        return "t_moving_context";
    }
};

struct t_player_context
{
    t_position_context      position {};

    t_player_context(const t_axis_value x, const t_axis_value y)
        : position { x, y }
    {
        std::cout << "player was spawned on position x: " << x << ", y: " << y << std::endl;
    }

    t_player_context()
        : t_player_context({}, {})
    {
    }

    static t_context_descriptor get_description()
    {
        return "t_player_context";
    }
};

struct t_size_context
{
    t_2d_vector_axis_value _width {};

    t_2d_vector_axis_value _height {};


    t_size_context(const t_2d_vector_axis_value width, const t_2d_vector_axis_value height)
        : _width { width }
        , _height { height }
    {
    }

    t_size_context()
        : t_size_context { t_2d_vector_axis_value {}, t_2d_vector_axis_value {} }
    {
    }

    const t_2d_vector_axis_value width() const
    {
        return _width;
    }

    const t_2d_vector_axis_value height() const
    {
        return _height;
    }

    static t_context_descriptor get_description()
    {
        return "t_size_context";
    }
};

using t_game_scene_size_context = t_size_context;

struct t_enemy_context
{
    t_position_context      position {};

    t_health_points_value   health_points;

    t_enemy_context(const t_health_points_value health_points, const t_axis_value x, const t_axis_value y)
        : health_points { health_points }
        , position { x, y }
    {
        std::cout << "enemy was spawned on position x: " << x << ", y: " << y << ", health points: " << health_points << std::endl;
    }

    t_enemy_context()
        : t_enemy_context { {}, {}, {} }
    {
        std::cout << "enemy was spawned on position x: " << position.x() << ", y: " << position.y() << ", health points: " << health_points << std::endl;
    }

    t_enemy_context(const t_health_points_value health_points)
        : t_enemy_context { health_points, t_axis_value {}, t_axis_value {} }
    {
        std::cout << "enemy was spawned on position x: " << position.x() << ", y: " << position.y() << ", health points: " << health_points << std::endl;
    }

    static t_context_descriptor get_description()
    {
        return "t_enemy_context";
    }
};

struct t_rotation_context
{
    // Структура для управления углом вращения

    t_heading_radians_value                     _heading;          // Текущий угол (градусы)

    t_course_radians_value                      _course;           // Целевой угол (градусы)

    t_angular_speed_radians_per_second_value    _angular_speed;    // Скорость поворота (градусы/секунда)

    t_rotation_context(const t_floating_value heading,
                       const t_floating_value course,
                       const t_angular_speed_radians_per_second_value angular_speed)
        : _heading { heading }
        , _course { course }
        , _angular_speed { angular_speed }
    {
    }

    t_rotation_context(const t_degrees_value degrees,
                       const t_angular_speed_degrees_per_second_value angular_speed)
        : _heading { degrees }
        , _course { degrees }
        , _angular_speed { angular_speed }
    {
    }

    static t_context_descriptor get_description()
    {
        return "t_rotation_context";
    }
};

/// @brief Данный контест содержит начальную позицию (position) и длинну оружия для
/// вычисления конечной позиции используя heading для этого.
struct t_drawable_weapon_context
{
    t_drawable_weapon_context(const t_position_context& position)
        : position { position }
        , length { 50.0 }
    {
    }

    t_drawable_weapon_context()
        : t_drawable_weapon_context { {} }
    {
    }

public:
    t_identifier_value identifier;

    t_position_context position {};

    t_axis_value length { 50.0 }; // Длина линии
};

inline void set_drawable_weapon_position(t_drawable_weapon_context& drawable_weapon, const t_position_context& position)
{
    drawable_weapon.position = position;
}

/// @brief As weapon is line and t_drawable_weapon_context contains position and line length, this method calculates end of line position using t_rotation_context 
/// @param drawable_weapon 
/// @param rotation 
/// @return 
inline t_position_context get_rotated_length_point(const t_drawable_weapon_context& drawable_weapon, const t_rotation_context& rotation)
{
    const t_position_context& position              = drawable_weapon.position;
    const t_axis_value& length                      = drawable_weapon.length;
    const t_heading_radians_value& rotation_heading = rotation._heading;

    const t_axis_value x = position.x() + length * std::cos(rotation_heading * M_PI / 180.);
    const t_axis_value y = position.y() + length * std::sin(rotation_heading * M_PI / 180.);

    return t_position_context { x, y };
}


struct t_projectile_context
{
    // Снаряд, который имеет радиус поражения
    // Если дистанция между снарядом и enemy меньше радиуса поражения

    //
    t_projectile_identifier_value   _identifier {};

    //
    t_position_context              _position {};

    //
    t_velocity_context              _velocity {};

    //
    t_collision_radius_value        _collision_radius {};

    //
    t_heat_damage_value             _heat_damage {};


    t_projectile_context(const t_projectile_identifier_value identifier,
                         const t_position_context position,
                         const t_velocity_context velocity,
                         const t_collision_radius_value collision_radius,
                         const t_heat_damage_value heat_damage)
        : _identifier { identifier }
        , _position { position }
        , _velocity { velocity }
        , _collision_radius { collision_radius }
        , _heat_damage { heat_damage }
    {
        std::cout << "construct progectile with heat damage " << heat_damage << std::endl;
    }

    t_projectile_context(const t_projectile_identifier_value identifier,
                         const t_heat_damage_value heat_damage,
                         const t_collision_radius_value collision_radius,
                         const t_position_context position,
                         const t_velocity_context velocity)
        : t_projectile_context { identifier, position, velocity, collision_radius, heat_damage }
    {
    }

    static t_context_descriptor get_description()
    {
        return "t_projectile_context";
    }
};

struct t_weapon_context
{
    const t_weapon_identifier_value identifier {};

    const t_heat_damage_value       heat_damage { 60 };         // _per_shot

    const t_speed_value             projectile_speed { 50 };    //

    const t_floating_value          reloading_time { 10. };     // Время перезарядки оружия (миллисекунды (ms))

    t_floating_value                cooldown_time {};           // Остаток времени до готовности


    t_weapon_context()
        : heat_damage { 60 }
        , projectile_speed { 50 }
        , reloading_time { 10. }
        , cooldown_time {}
    {
    }

    static t_context_descriptor get_description()
    {
        return "t_weapon_context";
    }
};


using t_moving_context_holder       = std::vector<t_moving_context>;

using t_projectile_context_holder   = std::vector<t_projectile_context>;


extern t_moving_context_holder      g_moving_context_holder;

extern t_projectile_context_holder  g_projectile_context_holder;


t_position_context get_gun_context(t_drawable_weapon_context& gun);

bool t_is_alive(const t_enemy_context& context);

bool t_is_dead(const t_enemy_context& context);

t_enemy_context t_get_random_enemy(int x_range_minimum, int x_ramge_maximum, int y_range_minimum, int y_ramge_maximum);

bool t_is_weapon_reloading(const t_weapon_context& context);

bool t_heading_has_reached_its_course(const t_rotation_context& context);

void t_rotation_system_updater(t_rotation_context& context, const float deltaTime);

bool t_is_weapon_ready_for_shoot(const t_weapon_context& weapon);

bool t_projectile_spawner(t_shooting_game_scene& game_scene, t_weapon_context& weapon);

void t_shooting_system_updater(t_shooting_game_scene& game_scene, t_weapon_context& weapon, const float delta);

void t_moving_system_updater(t_moving_context_holder& moving, const float delta);

void t_weapon_cooldown_runner(t_weapon_context& weapon);

void t_weapon_cooldown_updater(t_weapon_context& weapon, const float delta);

bool does_projectile_collide_with_anything(t_shooting_game_scene& game_scene, const t_projectile_context& projectile);

void t_colliding_projectile_system_updater(t_shooting_game_scene& game_scene, const float delta);

void t_moving_projectile_system_updater(t_shooting_game_scene& game_scene, const float delta);

#endif // T_COMPONENT_CONTEXTS_AND_SYSTEMS_H
