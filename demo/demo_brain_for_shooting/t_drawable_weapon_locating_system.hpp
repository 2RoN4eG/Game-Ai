#pragma once

#include "t_defines.hpp"


class t_shooting_game_scene;

struct t_drawable_weapon_context;


class t_drawable_weapon_locating_system
{
public:
    t_drawable_weapon_locating_system(t_shooting_game_scene& game_scene);

    void on_game_scene_size_changed(const t_random_area_size w, const t_random_area_size h);

private:
    t_shooting_game_scene& _game_scene;

    t_drawable_weapon_context& _drawable_weapon;
};
