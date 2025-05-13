#pragma once

#include "../t_component_defines.hpp"

#include <vector>


using t_unsigned_short = unsigned short;

enum t_vehicle_part : t_unsigned_short
{
    t_engine    = 1,
    t_chassis,
    t_gun,
    t_turret,
    t_radio
};

using t_unique_part = t_identifier_value;

t_identifier_value make_identifier(const t_vehicle_part vehicle_part, const t_unique_part unique_part);


using t_vehicle_part_pair = std::pair<t_vehicle_part, t_identifier_value>;

using t_vehicle_entity = std::vector<t_vehicle_part_pair>;

using t_vehicle_entities = std::vector<t_vehicle_entity>;
