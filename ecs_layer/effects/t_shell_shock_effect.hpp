#include "../interfaces/t_effect_interface.hpp"

#include "../tools/t_2d_vector.hpp"


class t_vehicle_component;
class t_sound_player_interface;


// Эфект оглушения, все параметры используемые для применения эффекта можно посмотреть 

class t_shell_shock_effect : public t_effect_interface
{
public:
    t_shell_shock_effect(t_vehicle_component& vehicle, t_sound_player_interface& sound_player);
    ~t_shell_shock_effect() override;

    void apply() override;

    void disapply() override;

private:
    t_vehicle_component& _vehicle;

    t_sound_player_interface& _sound_player;

    t_speed_limit_value _speed_limit {};

    t_radio_distance_value _radio_distance {};
};
