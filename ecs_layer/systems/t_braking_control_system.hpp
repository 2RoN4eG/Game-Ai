#pragma once


#include "../t_game_scene.hpp"


class t_game_scene;
class t_braking_control_component;


class t_braking_control_system
{
public:
    t_braking_control_system(t_game_scene& game_scene);
    ~t_braking_control_system() = default;

    void update(const t_delta_time_floating_value delta_time);

private:
    t_game_scene& _game_scene;

    t_entry_holder<t_braking_control_component>& _entry_holder;
};
