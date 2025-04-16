#include "t_enemy_spawn_system.hpp"

#include "t_shooting_game_scene.hpp"

#include <random>


namespace
{
    const t_axis_value restrict_random_value(const t_random_area_size_value maximum)
    {
        if (maximum == 0)
        {
            throw std::runtime_error { "maximum value can not be zero" };
        }

        const t_random_area_size_value minimum {};

        const t_random_area_size_value range { maximum - minimum };

        long random_value = random();

        std::cout << "random_value is " << random_value << " [ " << minimum << ", " << maximum << " ]" << std::endl;

        t_axis_value restricted_value = random_value % range + minimum;

        std::cout << "restricted value is " << restricted_value << " [ " << minimum << ", " << maximum << " ]" << std::endl;

        return restricted_value;
    }

    class t_setting_course_to_enemy_subsystem
    {
    public:
        t_setting_course_to_enemy_subsystem(t_shooting_game_scene& game_scene)
            : _game_scene { game_scene }
        {
        }

        void update(const t_update_delta_time delta_time)
        {
            (void) delta_time;

            const t_drawable_weapon_context& drawable_weapon = get_shooting_brain_game_scene_context<t_drawable_weapon_context>(_game_scene);

            const t_enemy_context& enemy = get_shooting_brain_game_scene_context<t_enemy_context>(_game_scene);

            const t_position_context& drawable_weapon_position = drawable_weapon.position;

            const t_position_context& enemy_position = enemy.position;

            const t_position_context target = enemy_position - drawable_weapon_position;

            t_rotation_context& rotation = get_shooting_brain_game_scene_mutable_context<t_rotation_context>(_game_scene);

            t_floating_value& rotation_course = rotation._course;

            rotation_course = std::atan2(target.y(), target.x()) * 180.0 / M_PI;
        }

    private:
        t_shooting_game_scene& _game_scene;
    };
}


t_enemy_spawn_system::t_enemy_spawn_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
    , _width {}
    , _height {}
{
}

void t_enemy_spawn_system::on_game_scene_size_changed(const t_random_area_size width, const t_random_area_size height)
{
    std::cout << "on_game_scene_size_changed "
              << "width: from " << _width << " to " << width << ", "
              << "height: from " << _height << " to " << height
              << std::endl;

    _width = width;

    _height = height;

}

const t_random_area_size t_enemy_spawn_system::width() const
{
    return _width;
}

const t_random_area_size t_enemy_spawn_system::height() const
{
    return _height;
}

void t_enemy_spawn_system::update(const t_update_delta_time delta_time)
{
    t_entry_holder<t_enemy_context>& enemy_holder = _game_scene.get_mutable_entry_holder<t_enemy_context>();

    if (enemy_holder.amount() > 1)
    {
        return;
    }

    if (enemy_holder.amount() == 1)
    {
        t_enemy_context& enemy = enemy_holder.get_mutable_component();

        if (t_is_alive(enemy))
        {
            return;
        }

        t_position_context& enemy_position = enemy.position;

        const t_axis_value enemy_position_x = enemy_position.x();

        const t_axis_value enemy_position_y = enemy_position.y();

        std::cout << (t_is_alive(enemy) ? "alive" : "dead") <<  " enemy exists on position x: " << enemy_position_x << " (" << _width << "), "
                                                                                          "y: " << enemy_position_y << " (" << _height << ")" << std::endl;

        new (&enemy) t_enemy_context(t_health_points_value { 100 }, restrict_random_value(_width), restrict_random_value(_height));

        t_setting_course_to_enemy_subsystem subsystem { _game_scene };

        subsystem.update(delta_time);

        return;
    }

    const t_axis_value x = restrict_random_value(_width);

    const t_axis_value y = restrict_random_value(_height);

    std::cout << "enemy is on possition x: " << x << " (" << _width << "), "
                                       "y: " << y << " (" << _height << ")" << std::endl;

    const t_health_points_value health_points { 100 };

    enemy_holder.create_component(health_points, x, y);
}
