#include "t_vehicle_entity.hpp"


t_identifier_value make_unique_identifier(const t_vehicle_part part_identifier, const t_identifier_value identifier)
{
    return static_cast<t_game_object_identifier_value>(part_identifier) << 48 | (identifier & 0x0000FFFFFFFFFFFF);
}
