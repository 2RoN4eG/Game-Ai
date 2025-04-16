#include <catch2/catch_test_macros.hpp>

#include "components/t_vehicle_component.hpp"

#include "t_helper.hpp"


TEST_CASE( "setting vehicle speed" )
{
    t_vehicle_component vehicle = create_testable_vehicle();

    t_chassis_component& chassis = vehicle.get_mutable_chassis();

    t_engine_component& vehicle_engine = chassis.get_mutable_engine();

    REQUIRE(vehicle_engine == vehicle.get_mutable_engine());

    REQUIRE(vehicle_engine.get_speed() == 0);


    SECTION( "setting speed that is in speed range 0 ... speed limit" )
    {
        const t_speed_value expected_speed { 50 };

        t_set_vehicle_speed(vehicle, expected_speed);

        REQUIRE(vehicle_engine.get_speed() == expected_speed);
    }
}
