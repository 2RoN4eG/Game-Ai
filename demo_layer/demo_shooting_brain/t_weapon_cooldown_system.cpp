#include "t_weapon_cooldown_system.hpp"


#include "t_shooting_game_scene.hpp"


t_weapon_cooldown_system::t_weapon_cooldown_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_weapon_cooldown_system::update(const t_update_delta_time delta_time)
{
    t_entry_holder<t_weapon_context>& weapons = _game_scene.get_mutable_entry_holder<t_weapon_context>();

    for (t_weapon_context& weapon : weapons)
    {
        weapon.cooldown_time -= delta_time;
    }
}
