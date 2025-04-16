#pragma once

#include "t_defines.hpp"

class t_shooting_game_scene;


class t_colliding_projectile_system
{
public:
    t_colliding_projectile_system(t_shooting_game_scene& game_scene);

    void update(const t_update_delta_time delta_time);

    void operator()(const t_update_delta_time delta_time)
    {
        update(delta_time);
    }

private:
    t_shooting_game_scene& _game_scene;
};
