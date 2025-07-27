#include "t_removing_projectile_system.hpp"

#include "t_shooting_game_scene.hpp"

#include "t_remove_projectile_event.hpp"


namespace
{
    class t_remove_projectile_subsystem
    {
    };
}


t_removing_projectile_system::t_removing_projectile_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_removing_projectile_system::update(const t_update_delta_time delta_time)
{
    t_entry_holder<t_remove_projectile_event>& remove_projectile_event_holder = _game_scene.get_mutable_entry_holder<t_remove_projectile_event>();

    for (t_remove_projectile_event event : remove_projectile_event_holder)
    {

    }
}
