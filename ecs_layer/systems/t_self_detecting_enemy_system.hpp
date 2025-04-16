#pragma once

#include "../tools/t_2d_vector.hpp"


class t_game_scene;


class t_self_detecting_enemy_system
{
public:
    t_self_detecting_enemy_system(t_game_scene& game_scene);

    ~t_self_detecting_enemy_system();

    void update(const t_frame_delta_time_value delta_time);

private:
    t_game_scene& _game_scene;
};
