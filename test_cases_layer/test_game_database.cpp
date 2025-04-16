#include <catch2/catch_test_macros.hpp>

#include "t_game_database.hpp"


TEST_CASE( "game object database" )
{
    t_component_database database {};

    SECTION( "component creating / getting" )
    {
        const t_identifier_value engine_identifier {};

        const t_engine_power_value engine_power { 1000 };

        t_component_holder<t_engine_component> engine_database = database.get_component_holder<t_engine_component>();

        REQUIRE(engine_database.amount() == 0);

        engine_database.create_component(engine_identifier, engine_power);

        REQUIRE(engine_database.amount() == 1);

        t_engine_component& engine = engine_database.get_component(engine_identifier);

        const t_engine_power_value  expected_engine_power  { expected_engine_power };
        const t_engine_speed_value  expected_engine_speed  {};
        const t_engine_weight_value expected_engine_weight {};

        REQUIRE(engine.get_power()  == engine_power);
        REQUIRE(engine.get_speed()  == expected_engine_speed);
        REQUIRE(engine.get_weight() == expected_engine_weight);
    }
}
