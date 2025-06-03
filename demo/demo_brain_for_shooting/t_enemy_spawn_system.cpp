#include "t_enemy_spawn_system.hpp"

#include "t_shooting_game_scene.hpp"


namespace
{
    const t_axis_value get_restricted_random_value(const t_integral_value maximum)
    {
        const int minimum {};

        const int range = (maximum - minimum);

        return random() % range + minimum;
    }
}


t_enemy_spawn_system::t_enemy_spawn_system(t_shooting_game_scene& game_scene, const t_random_area_size w, const t_random_area_size h)
    : _game_scene { game_scene }
    , _width { w }
    , _height { h }
{
    update({});
}

void t_enemy_spawn_system::set_ramdom_area_width(const t_random_area_size size)
{
    _width = size;
}

void t_enemy_spawn_system::set_ramdom_area_height(const t_random_area_size size)
{
    _height = size;
}

void t_enemy_spawn_system::set_ramdom_area_size(const t_random_area_size width, const t_random_area_size height)
{
    _width = width;

    _height = height;
}

void t_enemy_spawn_system::update(const t_update_delta_time delta_time)
{
    t_entry_holder<t_enemy_context>& enemy_holder = _game_scene.get_mutable_entry_holder<t_enemy_context>();

    if (enemy_holder.amount() != 0)
    {
        return;
    }

    const t_axis_value x = get_restricted_random_value(_width);

    const t_axis_value y = get_restricted_random_value(_height);

    const t_health_points_value health_points { 100 };

    enemy_holder.create_component(health_points, x, y);
}
