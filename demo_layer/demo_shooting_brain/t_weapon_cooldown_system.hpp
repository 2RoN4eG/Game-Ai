#pragma once

#include "t_defines.hpp"


class t_shooting_game_scene;


class t_weapon_cooldown_system
{
public:
    t_weapon_cooldown_system(t_shooting_game_scene& game_scene);

    void update(const t_update_delta_time delta_time);

private:
    t_shooting_game_scene& _game_scene;
};
