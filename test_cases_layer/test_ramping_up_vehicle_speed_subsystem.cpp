#include <catch2/catch_test_macros.hpp>

#include "components/t_vehicle_component.hpp"
#include "components/t_engine_component.hpp"

#include "systems/subsystems/t_ramping_up_vehicle_speed_subsystem.hpp"


using t_step_value = int;


TEST_CASE( "ramping up vehicle speed subsystem" )
{
    const t_step_value steps { 20 };

    const t_frame_delta_time_value frame_delta_time { 500 };

    REQUIRE(frame_delta_time == t_get_rumping_up_time() / steps);

    const t_range<t_speed_scale_value> speed_scale_range { 0., 1. };

    t_vehicle_component vehicle { t_identifier {}, t_weight_value { 40 }, t_engine_component {} };

    t_ramping_up_vehicle_speed_subsystem subsystem { vehicle, speed_scale_range };

    const t_speed_limit_value speed_limit = vehicle.get_speed_limit();

    const t_engine_component& engine { vehicle.get_mutable_engine() };

    for (t_step_value step = 1; step <= steps; ++ step)
    {
        subsystem.update(frame_delta_time);

        const t_speed_value must_be_value = speed_limit * step / steps;

        REQUIRE(engine.get_speed() == must_be_value);
    }

    // verifying speed limit reached ...

    REQUIRE(engine.get_speed() == speed_limit);
}
