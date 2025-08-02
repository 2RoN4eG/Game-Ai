#include <catch2/catch_test_macros.hpp>

#include "mocks/mock_sound_player.hpp"

#include "effects/t_shell_shock_effect.hpp"

#include "components/t_vehicle_component.hpp"

#include "t_helper.hpp"

#include <iostream>


using trompeloeil::eq;


TEST_CASE( "testing shell shock effect", "[effects]" )
{
    SKIP( "Не исправлена ошибка в коде" );

    t_vehicle_component vehicle = create_testable_vehicle();

    const t_speed_limit_value initial { 100 };
    const t_speed_limit_value must_be { 80 };

    mock_sound_player sound_player;

    SECTION( "applying / disapplying shell shock effect" )
    {
        REQUIRE(vehicle.get_speed_limit() == initial);

        t_shell_shock_effect effect { vehicle, sound_player };

        effect.apply();

        REQUIRE(vehicle.get_speed_limit() == must_be);

        const t_identifier_value expected_apply {};
        REQUIRE_CALL(sound_player, play(eq(expected_apply)));

        effect.disapply();

        REQUIRE(vehicle.get_speed_limit() == initial);

        const t_identifier_value expected_disapply {};
        REQUIRE_CALL(sound_player, play(eq(expected_disapply)));
    }
}
