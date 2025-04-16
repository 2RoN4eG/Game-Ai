#pragma once

using t_update_delta_time = float;

class t_shooting_game_scene;

struct t_rotation_context;
struct t_enemy_context;
struct t_weapon_context;


class t_shooting_ai_brain_system
{
public:
    t_shooting_ai_brain_system(t_shooting_game_scene& game_scene);

    void update(const t_update_delta_time delta_time);

private:
    t_shooting_game_scene&      _game_scene;

    const t_rotation_context&   _rotation_context;

    const t_enemy_context&      _enemy_context;

    t_weapon_context&           _weapon_context;
};
