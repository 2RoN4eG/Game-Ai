#include "t_braking_distance_system.hpp"

#include "../t_game_scene.hpp"


namespace
{
    template <typename t_component>
    inline t_component& get_game_scene_mutable_component(t_game_scene& game_scene, const t_identifier_value identifier)
    {
        t_entry_holder<t_component>& entry_holder = game_scene.get_mutable_entry_holder<t_component>();

        return entry_holder.get_mutable_component(identifier);
    }

    template <typename t_component>
    inline const t_component& get_game_scene_component(const t_game_scene& game_scene, const t_identifier_value identifier)
    {
        const t_entry_holder<t_component>& entry_holder = game_scene.get_entry_holder<t_component>();

        return entry_holder.get_component(identifier); 
    }
}


t_braking_distance_system::t_braking_distance_system(t_game_scene& game_scene, const t_identifier_value identifier)
    : _braking_control_entry_holder { game_scene.get_entry_holder<t_braking_control_component>() }
    , _braking_control_component { _braking_control_entry_holder.get_component(identifier) }
    , _braking_distance_entry_holder { game_scene.get_mutable_entry_holder<t_braking_distance_component>() }
    , _braking_distance_component { _braking_distance_entry_holder.get_mutable_component(identifier) }
{
}

void t_braking_distance_system::update(const t_delta_time_floating_value delta_time)
{
    t_distance_value& distance { _braking_distance_component._distance };

    const t_speed_value speed { _braking_control_component._speed };

    distance = distance + speed * delta_time;
}
