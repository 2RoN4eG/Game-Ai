#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>

#include "systems/concepts/t_double_buffering_team_player_lookup_system.hpp"


TEST_CASE( "t_double_buffering_team_player_lookup_system", "[concepts]" )
{
    t_double_buffering_team_player_lookup_system system {};

    SECTION( "making teams for players" )
    {
        const t_team_value team_a { 1 };
        const t_team_value team_b { 2 };

        system.create_team_player(team_a, 1002);
        system.create_team_player(team_b, 2004);
        system.create_team_player(team_a, 1001);
        system.create_team_player(team_a, 1003);
        system.create_team_player(team_b, 2002);
        system.create_team_player(team_b, 2001);
        system.create_team_player(team_b, 2003);

        {
            t_exit_sorter { system };
        }

        REQUIRE(system.get_team_player_holder(team_a).size() == 3);
        REQUIRE(system.get_team_player_holder(team_b).size() == 4);
    }

    SECTION( "expecting throwing exception" )
    {
        const t_team_value team_c { 3 };

        REQUIRE_THROWS(system.get_team_player_holder(team_c));
    }
}
