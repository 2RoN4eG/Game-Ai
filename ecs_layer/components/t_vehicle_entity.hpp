#pragma once

#include "t_defines.hpp"

#include <vector>


enum t_vehicle_part : unsigned short
{
    t_engine,
    t_chassis,
    t_gun,
    t_turret,
    t_radio
};


t_game_object_identifier_value make_unique_identifier(const t_vehicle_part part_identifier, const t_identifier_value identifier);


using t_vehicle_part_pair = std::pair<t_vehicle_part, t_identifier_value>;

using t_vehicle_entity = std::vector<t_vehicle_part_pair>;
