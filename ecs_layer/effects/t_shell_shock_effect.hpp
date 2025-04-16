#include "../interfaces/t_effect_interface.hpp"

#include "../t_component_defines.hpp"


class t_vehicle_component;
class t_sound_player_interface;


class t_shell_shock_effect : public t_effect_interface
{
public:
    t_shell_shock_effect(t_vehicle_component& vehicle, t_sound_player_interface& sound_player);
    ~t_shell_shock_effect() override;

    void apply() override;

    void disapply() override;

    const t_timestamp expire_after() const override;

private:
    t_vehicle_component& _vehicle;

    t_sound_player_interface& _sound_player;

    t_timestamp _expire_after {};

    t_speed_limit_value _speed_limit {};

    t_radio_distance_value _radio_distance {};
};
