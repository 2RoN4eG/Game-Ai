#include <catch2/catch_test_macros.hpp>

#include "components/t_vehicle_component.hpp"
#include "components/t_engine_component.hpp"

#include "systems/subsystems/t_ramping_down_vehicle_speed_subsystem.hpp"

#include <iostream>


using t_step_amount_value = int;


TEST_CASE( "ramping down vehicle speed subsystem" )
{
    /// эмитация торможения с максимальной скорости.

    const t_step_amount_value steps { 20 };

    const t_frame_delta_time_value frame_delta_time { 100 };

    REQUIRE(frame_delta_time == t_get_rumping_down_time() / steps);

    const t_range<t_speed_scale_value> speed_scale_range { 0., 1. };

    t_vehicle_component vehicle { t_identifier {}, t_weight_value { 40 }, t_engine_component {} };

    const t_speed_limit_value speed_limit = vehicle.get_speed_limit();

    t_engine_component& engine { vehicle.get_mutable_engine() };

    t_set_engine_speed(engine, speed_limit);

    REQUIRE(engine.get_speed() == speed_limit);

    std::cout << "engine speed is " << engine.get_speed() << ", must be value is " << speed_limit << std::endl;

    t_ramping_down_vehicle_speed_subsystem subsystem { vehicle, speed_scale_range };

    for (t_step_amount_value step = 1; step <= steps; ++ step)
    {
        subsystem.update(frame_delta_time);

        const t_speed_value must_be_value = speed_limit - speed_limit * step / steps;

        REQUIRE(engine.get_speed() == must_be_value);
    }

    // verifying speed limit reached ...

    REQUIRE(engine.get_speed() == 0);
}
