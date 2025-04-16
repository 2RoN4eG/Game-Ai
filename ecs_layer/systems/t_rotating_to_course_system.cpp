#include "t_rotating_to_course_system.hpp"

#include "t_rotating_vehicle_to_course_system.hpp"

#include <iostream>


/**
 * @brief t_rotating_to_course_system::t_rotating_to_course_system
 * @param component_manager
 */
t_rotating_to_course_system::t_rotating_to_course_system()
    : _rotating_to_course_caches {}
{
}

/**
 * @brief t_rotating_to_course_system::update
 * @param delta_time
 */
void t_rotating_to_course_system::update(const t_frame_delta_time_value delta_time)
{
    for (t_rotating_heading_to_course_component& cache : _rotating_to_course_caches)
    {
        t_heading_radians_value& heading = cache._heading;

        const t_course_radians_value course = cache._course;

        const t_heading_speed_radians_per_second_value heading_speed = cache._heading_speed;

        update_rotating_to_course(heading, course, heading_speed, delta_time);
    }
}
