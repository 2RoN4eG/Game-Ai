#include "t_braking_control_system.hpp"

t_braking_control_system::t_braking_control_system(t_game_scene& game_scene)
    : _game_scene { game_scene }
    , _entry_holder { _game_scene.get_mutable_entry_holder<t_braking_control_component>() }
{
}

void t_braking_control_system::update(const t_delta_time_floating_value delta_time)
{
    if (_entry_holder.amount() == 0)
    {
        return;
    }

    for (t_braking_control_component& component : _entry_holder)
    {
        t_speed_value& speed { component._speed };

        // check if speed is equal speed limit

        const t_acceleration_value acceleration { component._acceleration };

        speed = std::max(t_speed_value {}, speed - acceleration * delta_time);
    }
}
