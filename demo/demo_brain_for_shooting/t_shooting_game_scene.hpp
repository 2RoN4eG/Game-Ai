#pragma once


#include "../../ecs_layer/t_entry_holder_aggregator.hpp"

#include "t_component_contexts_and_systems.hpp"


class t_shooting_game_scene : public t_entry_holder_aggregator<t_moving_context,
                                                               t_projectile_context>
{
};
