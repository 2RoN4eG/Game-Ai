#include "t_drawable_weapon_locating_system.hpp"

#include "t_shooting_game_scene.hpp"

#include "t_component_contexts_and_systems.hpp"


t_drawable_weapon_locating_system::t_drawable_weapon_locating_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
    , _drawable_weapon { get_shooting_brain_game_scene_mutable_context<t_drawable_weapon_context>(_game_scene) }
{
}

void t_drawable_weapon_locating_system::on_game_scene_size_changed(const t_random_area_size x, const t_random_area_size y)
{
    t_position_context& position = _drawable_weapon.position;

    position = t_position_context { static_cast<t_2d_vector_axis_value>(x), static_cast<t_2d_vector_axis_value>(y) };
}
