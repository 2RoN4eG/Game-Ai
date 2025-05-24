#include "ai/gob/t_brain.hpp"

#include "ai/gob/behaviors/t_linear_moving_behavior.hpp"
#include "ai/gob/behaviors/t_idle_behavior.hpp"

#include "ai/gob/goals/t_goal_is_arrived.hpp"

#include "t_system_manager.hpp"
#include "systems/t_rotating_vehicle_to_course_system.hpp"

#include <iostream>
#include <iomanip>


int main()
{
    ai::gob::t_brain ai_runner {};

    t_movable_component movable {};
    const t_position_value destination { 100. };

    const ai::t_node_identifier moving_node_identifier = ai_runner.hold_behavior(std::move(std::make_unique<ai::gob::t_linear_moving_behavior>(movable)));
    const ai::t_node_identifier   idle_node_identifier = ai_runner.hold_behavior(std::move(std::make_unique<ai::gob::t_idle_behavior>()));

    ai_runner.hold_transition(moving_node_identifier, idle_node_identifier, std::move(std::make_unique<ai::gob::t_goal_is_arrived>(movable, destination)));

    ai_runner.finish_preparing();

    t_input_device input_device {};
    t_moving_forward_event forward_moving_event { input_device, true };
    t_game_systems game_systems { input_device, forward_moving_event };

    const ai::t_delta_time frame_delta_time { 1. / 30. };

    ai::t_delta_time time {};

    long frames { 30 * 15 };
    while (frames --)
    {
        time += frame_delta_time;

        game_systems.update(frame_delta_time);

        if (time > 10.)
        {
            new (&forward_moving_event) t_moving_forward_event (input_device, false);
        }

        ai_runner.update(frame_delta_time);
    }


    t_rotating_vehicle_to_course_system rotating_to_course { 0, 90, 20 };

    for (size_t number {}; number <= 360; number ++)
    {
        rotating_to_course.update(frame_delta_time);
    }

    std::cout << t_make_vector_from_degrees_along_y_axis(0) << std::endl;

    return 0;
}
