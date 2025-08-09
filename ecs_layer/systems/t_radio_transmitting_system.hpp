#pragma once

#include "../tools/t_2d_vector.hpp"

#include "../components/t_detected_enemy_component.hpp"

#include <vector>


using t_detected_enemy_record = t_detected_enemy_component;

using t_game_scene_vehicle = t_identifier_value;

using t_game_scene_teams = std::vector<t_identifier_value>;

using t_game_scene_identifiers = std::vector<t_identifier_value>;

using t_vehicle_team_value = int;

using t_vehicle_radio_distance = int;


class t_game_scene;


class t_radio_transmitting_system
{
public:
    t_radio_transmitting_system(t_game_scene& game_scene);

    ~t_radio_transmitting_system();

    void update(const t_frame_delta_time_value delta_time);

private:
    t_game_scene& _game_scene;
};
