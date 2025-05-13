#include "t_vehicle_entity.hpp"

#include <iostream>
#include <iomanip>


t_identifier_value make_identifier(const t_vehicle_part vehicle_part, const t_unique_part unique_part)
{
    // if (!std::is_same_v<t_vehicle_part, t_unsigned_short>)
    // {
    //     throw std::runtime_error { "t_vehicle_part is not the same as t_unsigned_short" };
    // }

    constexpr size_t t_unique_part_size { sizeof(t_unique_part) };

    constexpr size_t t_vehicle_part_size { sizeof(t_vehicle_part) };

    constexpr size_t shift_to_bits { (t_unique_part_size - t_vehicle_part_size) * 8 };

    constexpr t_identifier_value restrictor { std::numeric_limits<t_identifier_value>::max() >> size_t { t_vehicle_part_size * 8 } };

    return (static_cast<t_identifier_value>(vehicle_part) << shift_to_bits) | (unique_part & restrictor);
}
