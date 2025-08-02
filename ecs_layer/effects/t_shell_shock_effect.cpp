#include "t_shell_shock_effect.hpp"

#include "../components/t_vehicle_component.hpp"

#include "../interfaces/t_sound_player_interface.hpp"


constexpr t_identifier_value t_shell_shock_effect_applied_sound_identifier {};

constexpr t_identifier_value t_shell_shock_effect_disapplied_sound_identifier {};


t_shell_shock_effect::t_shell_shock_effect(t_vehicle_component& vehicle, t_sound_player_interface& sound_player)
    : t_effect_interface { t_timestamp { 40 } }
    , _vehicle { vehicle }
    , _sound_player { sound_player }
{
}

t_shell_shock_effect::~t_shell_shock_effect()
{
}

void t_shell_shock_effect::apply()
{
    /** */

    _speed_limit = _vehicle.get_speed_limit();

    const t_speed_limit_value speed_limit = _speed_limit * (100 - 20) / 100;

    t_set_vehicle_speed_limit(_vehicle, speed_limit);

    /** */

    _radio_distance = {};

    const t_radio_distance_value distance = {};

    t_set_vehicle_radio_distance(_vehicle, distance);

    /** play sound for applied effect */

    _sound_player.play(t_shell_shock_effect_applied_sound_identifier);
}

void t_shell_shock_effect::disapply()
{
    t_set_vehicle_speed_limit(_vehicle, _speed_limit);

    t_set_vehicle_radio_distance(_vehicle, _radio_distance);

    /** play sound for disapplied effect */

    _sound_player.play(t_shell_shock_effect_disapplied_sound_identifier);
}
