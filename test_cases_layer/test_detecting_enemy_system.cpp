#include <catch2/catch_test_macros.hpp>

#include "systems/t_detecting_enemy_system.hpp"

#include "t_game_database.hpp"
#include "t_game_scene.hpp"

#include <iostream>

// create 3 vehicles with different options ...

TEST_CASE( "testing detecting enemy system", "[systems]" )
{
    t_game_database {};

    t_game_scene game_scene {};

    create_2_vehicles_game_scene();

    t_detecting_enemy_system system { game_scene };
}
