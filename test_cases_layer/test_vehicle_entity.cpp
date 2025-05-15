#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>

#include "components/t_vehicle_entity.hpp"

#include <iostream>


struct t_making_identifier_input
{
    const t_vehicle_part vehicle_part {};

    const t_unique_part unique_part {};
};


std::ostream& operator<<(std::ostream& stream, const t_making_identifier_input& input)
{
    stream << " { " << std::to_string(static_cast<uint64_t>(input.vehicle_part)) << ", " << std::to_string(input.unique_part) << " }";

    return stream;
}


TEST_CASE( "testing vehicle entity" )
{
    SECTION( "generated record from table" )
    {
        using t_record = std::tuple<t_making_identifier_input, t_identifier_value>;

        const t_record record = GENERATE(table<t_making_identifier_input, t_identifier_value>({
            t_record { t_making_identifier_input { static_cast<t_vehicle_part>(0),      0 },                                         0x0 },
            t_record { t_making_identifier_input { static_cast<t_vehicle_part>(0xFFFF), 0xFFFFFFFFFFFF },                            std::numeric_limits<t_identifier_value>::max() },
            t_record { t_making_identifier_input { static_cast<t_vehicle_part>(0xFFFF), 0 },                                         0xFFFF000000000000 },
            t_record { t_making_identifier_input { static_cast<t_vehicle_part>(0),      0xFFFFFFFFFFFF },                            0x0000FFFFFFFFFFFF },
            t_record { t_making_identifier_input { static_cast<t_vehicle_part>(0),      std::numeric_limits<t_unique_part>::max() }, 0x0000FFFFFFFFFFFF },
            t_record { t_making_identifier_input { t_vehicle_part::t_engine,            0xFF1F },                                    0x000100000000FF1F }
        }));

        const t_making_identifier_input input = std::get<0>(record);

        const t_identifier_value identifier = make_identifier_value(input.vehicle_part, input.unique_part);

        REQUIRE(identifier == std::get<1>(record));
    }
}