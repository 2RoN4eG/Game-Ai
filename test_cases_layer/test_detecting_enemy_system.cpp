#include <catch2/catch_test_macros.hpp>

#include "systems/t_detecting_enemy_system.hpp"
#include "systems/t_radio_transmitting_system.hpp"

#include "t_game_database.hpp"
#include "t_game_scene.hpp"

#include <iostream>
#include <algorithm>


using t_vehicle_position_value = t_2d_vector_value;


const t_vehicle_position_value t_get_game_scene_vehicle_position(t_game_scene& game_scene, const t_identifier_value identifier)
{
    const t_entry_holder<t_vehicle_component>& vehicle_holder = game_scene.get_entry_holder<t_vehicle_component>();

    const t_vehicle_component& vehicle = vehicle_holder.get_component(identifier);

    return t_get_vehicle_position(vehicle);
}

void t_set_game_scene_vehicle_position(t_game_scene& game_scene, const t_identifier_value identifier, const t_vehicle_position_value position)
{
    t_entry_holder<t_vehicle_component>& vehicle_holder = game_scene.get_mutable_entry_holder<t_vehicle_component>();

    t_vehicle_component& vehicle = vehicle_holder.get_mutable_component(identifier);

    t_set_vehicle_position(vehicle, position);
}

void t_create_game_scene_vehicle_on_position(t_game_scene& game_scene, const t_identifier_value identifier, const t_vehicle_position_value position)
{
    t_entry_holder<t_vehicle_component>& vehicle_holder = game_scene.get_mutable_entry_holder<t_vehicle_component>();

    t_vehicle_component& vehicle = vehicle_holder.create_component(identifier);

    t_set_vehicle_position(vehicle, position);
}

template <typename t_component, typename... t_arguments>
t_component& t_create_game_scene_component(t_game_scene& game_scene, const t_identifier_value identifier, t_arguments&&... arguments)
{
    t_entry_holder<t_component>& mutable_holder = game_scene.get_mutable_entry_holder<t_component>();

    return mutable_holder.create_component(identifier, std::forward<t_arguments>(arguments)...);
}

void t_create_game_scene_vehicle(t_game_scene& game_scene,
                                 const t_identifier_value identifier,
                                 const t_team_value team,
                                 const t_vehicle_position_value position,
                                 const t_visibility_distance_value visibility_distance,
                                 const t_radio_distance_value radio_distance)
{
    // t_create_game_scene_component<t_vehicle_position_value>      (game_scene, identifier, position);

    t_create_game_scene_component<t_vehicle_radio_component>     (game_scene, identifier, radio_distance);
    t_create_game_scene_component<t_vehicle_visibility_component>(game_scene, identifier, visibility_distance);
    t_vehicle_component& vehicle = t_create_game_scene_component<t_vehicle_component>           (game_scene, identifier);

    t_set_vehicle_team               (vehicle, team);
    t_set_vehicle_position           (vehicle, position);
    t_set_vehicle_visibility_distance(vehicle, visibility_distance);
    t_set_vehicle_radio_distance     (vehicle, radio_distance);
}

void prepare_testable_game_scene(t_game_scene& game_scene)
{
    t_entry_holder<t_vehicle_component>& vehicle_holder = game_scene.get_mutable_entry_holder<t_vehicle_component>();
 
    t_vehicle_identifier_maker identifier_maker {};

    vehicle_holder.create_component(identifier_maker());

    vehicle_holder.create_component(identifier_maker());
    vehicle_holder.create_component(identifier_maker());
}


inline int count_game_scene_self_detected(t_game_scene& game_scene, const t_identifier_value identifier)
{
    const t_entry_holder<t_detected_enemy_component>& holder = game_scene.get_entry_holder<t_detected_enemy_component>();

    struct t_count_predicate
    {
        t_detecting_source _source {};

        t_identifier_value _identifier {};

        const bool operator()(const t_detected_enemy_component& detected) const
        {
            return detected._source == _source && detected._detected_by == _identifier;
        }
    };

    return std::count_if(begin(holder), end(holder), t_count_predicate { t_detecting_source::by_self, identifier });
}


// create 3 vehicles with different options ...

TEST_CASE( "testing detecting enemy system", "[systems]" )
{
    t_game_scene game_scene {};

    t_detecting_enemy_system system { game_scene };

    SECTION( "vehicles are not existing" )
    {
        system.update(t_frame_delta_time_value {});

        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 0 }) == 0);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 1 }) == 0);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 2 }) == 0);
    }

    SECTION( "vehicle { identifier 1 } detects one vehicle { identifier 0 }, vehicle { identifier 2 } does not detect anybody" )
    {
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 0 }, t_team_value { 0 }, t_vehicle_position_value {   0,   0 }, t_visibility_distance_value { 100 }, t_radio_distance_value { 450 }); // 
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 1 }, t_team_value { 1 }, t_vehicle_position_value { 300,   0 }, t_visibility_distance_value { 350 }, t_radio_distance_value { 450 }); // distance between 0 and 1 is 300.0
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 2 }, t_team_value { 1 }, t_vehicle_position_value { 300, 300 }, t_visibility_distance_value { 350 }, t_radio_distance_value { 450 }); // distance between 0 and 2 is 424.264{...}

        system.update(t_frame_delta_time_value {});

        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 0 }) == 0);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 1 }) == 1);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 2 }) == 0);

        SECTION( "vehicle { identifier 1 } transmits information about vehicle { identifier 0 } to vehicle { identifier 2 }" )
        {
            t_radio_transmitting_system system { game_scene };
        }
    }

    SECTION( "vehicle { identifier 1 } detects one vehicle { identifier 0 }, vehicle { identifier 2 } does not detect anybody" )
    {
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 0 }, t_team_value { 0 }, t_vehicle_position_value {   0,   0 }, t_visibility_distance_value { 100 }, t_radio_distance_value { 450 }); // 
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 1 }, t_team_value { 1 }, t_vehicle_position_value { 300,   0 }, t_visibility_distance_value { 350 }, t_radio_distance_value { 450 }); // distance between 0 and 1 is 300.0
        t_create_game_scene_vehicle(game_scene, t_identifier_value { 2 }, t_team_value { 1 }, t_vehicle_position_value { 300, 300 }, t_visibility_distance_value { 350 }, t_radio_distance_value { 450 }); // distance between 0 and 2 is 424.264{...}

        system.update(t_frame_delta_time_value {});

        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 0 }) == 0);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 1 }) == 1);
        REQUIRE(count_game_scene_self_detected(game_scene, t_identifier_value { 2 }) == 0);
    }
}
