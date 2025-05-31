#include "t_ai_shooting_brain_system.hpp"

#include <vector>

#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"
#include "t_shooting_game_scene.hpp"


namespace
{
    using t_ai_controllable_identifier_holder = std::vector<int>;

    t_ai_controllable_identifier_holder get_ai_controllable_identifiers()
    {

    }

    t_rotation_context& t_shooting_game_scene_get_rotation_context(t_shooting_game_scene& game_scene)
    {
        static t_rotation_context rotation {};

        return rotation;
    }
}


t_ai_shooting_brain_system::t_ai_shooting_brain_system(t_shooting_game_scene& game_scene)
    : _game_scene { game_scene }
{
}

void t_ai_shooting_brain_system::update(const t_update_delta_time delta_time)
{
    //
}
