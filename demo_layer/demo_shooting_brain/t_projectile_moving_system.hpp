#pragma once

#include "t_defines.hpp"


class t_shooting_game_scene;


class t_projectile_moving_system
{
public:
    t_projectile_moving_system(t_shooting_game_scene& game_scene);

    void update(const t_update_delta_time_value delta_time);

private:
    t_shooting_game_scene& _game_scene;
};
