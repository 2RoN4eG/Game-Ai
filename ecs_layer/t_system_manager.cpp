#include "t_system_manager.hpp"


t_game_systems::t_game_systems(const t_input_device& input_device, const t_moving_forward_event& forward_moving_event)
    : _engine { {}, t_engine_power_value { 1000. } }
    , _chassis { {}, t_chassis_weight_value { 40. }, _engine }
    , _vehicle { {}, t_turret_component { {}, {} }, _chassis }
    , _chassis_speed_system { forward_moving_event, _vehicle }
    , _chassis_turn_system { input_device }
{
}

void t_game_systems::update(const t_frame_delta_time_value frame_delta_time)
{
    _chassis_speed_system.update(frame_delta_time);

    _chassis_turn_system.update(frame_delta_time);
}
