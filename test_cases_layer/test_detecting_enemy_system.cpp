#include <catch2/catch_test_macros.hpp>

#include "systems/t_detecting_enemy_system.hpp"

#include "t_game_database.hpp"
#include "t_game_scene.hpp"

#include <iostream>

const t_vehicle_component& t_get_game_scene_vehicle(t_game_scene& game_scene, const t_identifier_value identifier)
{
    
}

void set_game_scene_vehicle(t_game_scene& game_scene,
                            const t_identifier_value identifier,
                            const t_2d_position_value& position,
                            const t_visibility_distance_value visibility)
{
}

void veryfy_visibility_distance(t_game_scene& game_scene,
                                const t_identifier_value lhs,
                                const t_visibility_distance_value visibility,
                                const t_identifier_value rhs)
{
    const t_vehicle_component& lhs = t_get_game_scene_vehicle(game_scene, lhs);

    t_get_distances();
}

// create 3 vehicles with different options ...

TEST_CASE( "testing detecting enemy system", "[systems]" )
{
    t_game_scene game_scene {};

    t_detecting_enemy_system system { game_scene };

    system.update(t_frame_delta_time_value {});
}
