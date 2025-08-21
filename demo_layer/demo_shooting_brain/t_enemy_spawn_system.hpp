#ifndef T_ENEMY_SPAWN_SYSTEM_HPP
#define T_ENEMY_SPAWN_SYSTEM_HPP

#include "t_defines.hpp"


class t_shooting_game_scene;


class t_set_course_system
{
public:
    t_set_course_system(t_shooting_game_scene& game_scene)
        : _game_scene { game_scene }
    {
    }

private:
    t_shooting_game_scene& _game_scene;
};


class t_enemy_spawn_system
{
public:
    t_enemy_spawn_system(t_shooting_game_scene& game_scene);

    void set_ramdom_area_width(const t_random_area_size size);

    void set_ramdom_area_height(const t_random_area_size size);

    void on_game_scene_size_changed(const t_random_area_size width, const t_random_area_size height);

    const t_random_area_size width() const;

    const t_random_area_size height() const;

    void update(const t_update_delta_time delta_time);

private:
    t_shooting_game_scene& _game_scene;

    t_random_area_size _width {};

    t_random_area_size _height {};
};

#endif // T_ENEMY_SPAWN_SYSTEM_HPP
