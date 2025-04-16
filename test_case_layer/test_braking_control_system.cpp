#include <catch2/catch_test_macros.hpp>

#include "systems/t_braking_distance_system.hpp"
#include "systems/t_braking_control_system.hpp"

#include "components/t_braking_control_component.hpp"
#include "components/t_braking_distance_component.hpp"

#include <utility>


namespace
{
    // Дистанция торможения для данных скорости с которой останавливамся и времени остановки

    const t_braking_distance_value braking_distance(const t_speed_value speed, t_time_floating_value time)
    {
        const t_acceleration_value acceleration { speed / time };

        const t_floating_value half { 1. / 2 };

        return time * (speed - half * acceleration * time);
    }

    template <typename t_component, typename... t_arguments>
    void create_game_scene_component(t_game_scene& game_scene, t_arguments&&... arguments)
    {
        t_entry_holder<t_component>& entry_holder = game_scene.get_mutable_entry_holder<t_component>();

        entry_holder.create_component(std::forward<t_arguments>(arguments) ...);
    }

    template <typename t_component>
    const t_component& get_game_scene_component(t_game_scene& game_scene, const t_identifier_value identifier)
    {
        const t_entry_holder<t_component>& entry_holder = game_scene.get_entry_holder<t_component>();

        return entry_holder.get_component(identifier);
    }

    using t_percent_value = t_floating_value;

    template <typename t_range_value>
    t_range<t_range_value> create_range(const t_range_value value, const t_percent_value percent)
    {
        const t_range_value percented { value * percent / t_percent_value { 100 } };

        std::cout << "value is " << value << ", percent is " << percent << ", percented is " << percented << std::endl;

        const t_range_value minimum { value - percented };

        const t_range_value maximum { value + percented };

        return t_range<t_range_value>(minimum, maximum);
    }
}


TEST_CASE( "braking control system" )
{
    t_game_scene game_scene {};

    const t_identifier_value identifier {};

    const t_speed_value speed { 100 };

    const t_time_second_value seconds { 10 };

    const t_distance_value expected { 500. };

    REQUIRE(braking_distance(speed, seconds) == expected);

    create_game_scene_component<t_braking_control_component>(game_scene, identifier, speed, t_time_floating_value { seconds });

    create_game_scene_component<t_braking_distance_component>(game_scene, identifier);

    const t_frame_per_second_value frame_per_second { 30 };

    const int steps { frame_per_second * seconds };

    t_braking_distance_system braking_distance_system { game_scene, identifier };

    t_braking_control_system braking_control_system { game_scene };

    const t_frame_delta_time_value frame_delta_time { 1. / frame_per_second };

    for (int step {}; step < steps; ++ step)
    {
        braking_distance_system.update(frame_delta_time);

        braking_control_system.update(frame_delta_time);
    }

    {
        const t_braking_distance_component component = get_game_scene_component<t_braking_distance_component>(game_scene, identifier);

        const t_distance_value distance = component.get_distance();

        std::cout << "real braking distance is " << distance << " / estimated (calculated) braking distance is " << braking_distance(speed, seconds) << std::endl;

        const t_range<t_distance_value> expected_distance_range = create_range<t_distance_value>(expected, 0.4);

        REQUIRE(expected_distance_range.is_in_range(distance));
    }
}
