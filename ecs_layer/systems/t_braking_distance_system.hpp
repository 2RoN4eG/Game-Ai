#pragma once

#include "../t_entry_holder.hpp"


class t_game_scene;
class t_braking_distance_component;
class t_braking_control_component;


class t_braking_distance_system
{
public:
    t_braking_distance_system(t_game_scene& game_scene, const t_identifier_value identifier);
    ~t_braking_distance_system() = default;

    void update(const t_delta_time_floating_value delta_time);

private:
    const t_entry_holder<t_braking_control_component>& _braking_control_entry_holder;

    const t_braking_control_component& _braking_control_component;


    t_entry_holder<t_braking_distance_component>& _braking_distance_entry_holder;

    t_braking_distance_component& _braking_distance_component;
};
