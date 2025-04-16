#include "t_shooting_game_scene_creator.hpp"

#include "t_shooting_game_scene.hpp"
#include "t_component_contexts_and_systems.hpp"

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"


namespace
{
    template <typename t_context, typename... t_arguments>
    inline t_context& t_shooting_game_scene_create_context(t_shooting_game_scene& game_scene, t_arguments&&... arguments)
    {
        t_entry_holder<t_context>& entry_holder = game_scene.get_mutable_entry_holder<t_context>();

        return entry_holder.create_component(std::forward<t_arguments>(arguments)...);
    }
}


t_shooting_game_scene_creator::t_shooting_game_scene_creator(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
    t_shooting_game_scene_create_context<t_player_context>(game_scene);

    t_shooting_game_scene_create_context<t_rotation_context>(game_scene, t_floating_value { -90. }, t_floating_value { 20. });

    t_shooting_game_scene_create_context<t_weapon_context>(game_scene);

    // ui contexts

    t_shooting_game_scene_create_context<t_drawable_weapon_context>(game_scene);

    t_shooting_game_scene_create_context<t_enemy_context>(game_scene, t_health_points_value {});
}
