#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>

#include "systems/concepts/t_double_buffering_team_player_lookup_subsystem.hpp"


TEST_CASE( "t_double_buffering_team_player_lookup_subsystem", "[concepts]" )
{
    t_double_buffering_team_player_lookup_subsystem subsystem {};

    SECTION( "making teams for players" )
    {
        const t_team_value team_a { 1 };
        const t_team_value team_b { 2 };

        subsystem.create_team_player(team_a, 1002);
        subsystem.create_team_player(team_b, 2004);
        subsystem.create_team_player(team_a, 1001);
        subsystem.create_team_player(team_a, 1003);
        subsystem.create_team_player(team_b, 2002);
        subsystem.create_team_player(team_b, 2001);
        subsystem.create_team_player(team_b, 2003);

        {
            t_exit_sorter { subsystem };
        }

        REQUIRE(subsystem.get_team_player_holder(team_a).size() == 3);
        REQUIRE(subsystem.get_team_player_holder(team_b).size() == 4);
    }

    SECTION( "expecting throwing exception" )
    {
        const t_team_value team_c { 3 };

        REQUIRE_THROWS(subsystem.get_team_player_holder(team_c));
    }
}
