#include <catch2/catch_test_macros.hpp>

#include "t_game_database.hpp"


TEST_CASE( "game object database" )
{
    t_game_database database {};

    SECTION( "component creating / getting" )
    {
        const t_identifier_value engine_identifier {};

        const t_engine_power_value engine_power { 1000 };

        t_entry_holder<t_engine_component>& engine_database = database.get_mutable_entry_holder<t_engine_component>();

        REQUIRE(engine_database.amount() == 0);

        engine_database.create_component(engine_identifier, engine_power);

        REQUIRE(engine_database.amount() == 1);

        t_engine_component& engine = engine_database.get_mutable_component(engine_identifier);

        const t_engine_power_value  expected_engine_power  { expected_engine_power };
        const t_engine_speed_value  expected_engine_speed  {};
        const t_engine_weight_value expected_engine_weight {};

        REQUIRE(engine.get_power()  == engine_power);
        REQUIRE(engine.get_speed()  == expected_engine_speed);
        REQUIRE(engine.get_weight() == expected_engine_weight);
    }

    SECTION( "getting incorrect component" )
    {
        const t_identifier_value engine_identifier { std::numeric_limits<t_identifier_value>::max() };

        const t_entry_holder<t_engine_component>& engine_database = database.get_entry_holder<t_engine_component>();

        REQUIRE_THROWS(engine_database.get_component(engine_identifier));
    }

    SECTION( "vehicle creating from database" )
    {
        t_engine_identifier_maker engine_identifier_maker {};

        create_engine_database(database, engine_identifier_maker);


        t_chassis_identifier_maker chassis_identifier_maker {};

        create_chassis_database(database, chassis_identifier_maker);


        t_gun_identifier_maker gun_identifier_maker {};

        create_gun_database(database, gun_identifier_maker);


        t_turret_identifier_maker turret_identifier_maker {};

        create_turret_database(database, turret_identifier_maker);


        t_radio_identifier_maker radio_identifier_maker {};

        create_radio_database(database, radio_identifier_maker);
    }
}
