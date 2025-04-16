#pragma once

#include "t_entry_holder_aggregator.hpp"

#include "components/t_engine_component.hpp"
#include "components/t_chassis_component.hpp"
#include "components/t_gun_component.hpp"
#include "components/t_turret_component.hpp"
#include "components/t_radio_component.hpp"


class t_game_database : public t_entry_holder_aggregator<
        t_engine_component,
        t_chassis_component,
        t_gun_component,
        t_turret_component,
        t_radio_component,
        t_visibility_component
    >
{
};


size_t create_game_database(t_game_database& database);
