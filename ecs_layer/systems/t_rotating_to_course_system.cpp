#include "t_rotating_to_course_system.hpp"

#include "../t_component_manager.hpp"
#include "t_rotating_vehicle_to_course_system.hpp"

#include <iostream>


/**
 * @brief t_rotating_to_course_system::t_rotating_to_course_system
 * @param component_manager
 */
t_rotating_to_course_system::t_rotating_to_course_system(t_hidden_component_manager& component_manager)
    : _rotating_to_course_caches { component_manager.rotating_to_course_caches() }
{
    std::cout << "t_rotating_to_course_system ... created" << std::endl;
}

/**
 * @brief t_rotating_to_course_system::update
 * @param delta_time
 */
void t_rotating_to_course_system::update(const t_frame_delta_time_value delta_time)
{
    for (t_rotating_to_course_cache& cache : _rotating_to_course_caches)
    {
        t_heading_radians_value& heading = cache._heading;

        t_course_radians_value& course = cache._course;

        t_heading_speed_radians_per_second_value& heading_speed = cache._heading_speed;

        update_rotating_to_course_data(delta_time, heading, course, heading_speed);
    }
}
