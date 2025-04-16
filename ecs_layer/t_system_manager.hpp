#pragma once

#include "components/t_vehicle_component.hpp"
#include "systems/t_ramping_vehicle_speed_system.hpp"
#include "systems/t_rotating_vehicle_system.hpp"


/**
 * @brief The t_game_systems class
 */
class t_game_systems
{
public:
    t_game_systems(const t_input_device& input_device,
                   const t_moving_forward_event& forward_moving_event);

    void update(const t_frame_delta_time_value delta_time);

private:
    t_engine_component _engine;

    t_chassis_component _chassis;

    t_vehicle_component _vehicle;

    t_ramping_vehicle_speed_system _chassis_speed_system;

    t_chassis_turn_system _chassis_turn_system;
};
