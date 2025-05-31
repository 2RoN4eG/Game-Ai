#pragma once


using t_update_delta_time = float;

class t_shooting_game_scene;

struct t_rotation_context;


class t_ai_shooting_brain_system
{
public:
    t_ai_shooting_brain_system(t_shooting_game_scene& game_scene);

    void update(const t_update_delta_time delta_time);

private:
    t_shooting_game_scene&  _game_scene;
};
