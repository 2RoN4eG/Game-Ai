#include "t_rotating_vehicle_to_course_system.hpp"

#include "../tools/t_2d_vector.hpp"
#include "../tools/t_2d_vector.hpp"

#include <cmath>
#include <iostream>


namespace
{
    inline t_radians_value t_get_radians(const t_2d_vector_value vector)
    {
        return atan2(vector.y(), vector.x());
    }

    inline t_degrees_value t_get_degrees(const t_2d_vector_value vector)
    {
        const t_radians_value radians = t_get_radians(vector);

        return t_convert_radians_to_degrees(radians);
    }
}


void update_rotating_to_course(t_heading_radians_value& heading,
                               const t_heading_speed_radians_per_second_value heading_speed,
                               const t_course_radians_value course,
                               const t_frame_delta_time_value delta_time)
{
    // TODO: Check heading is in range [0 ... 360) degrees

    // TODO: Check course is in range [0 ... 360) degrees

    // TODO: Replace operator == to compare function.

    if (course == heading)
    {
        return;
    }

    const t_angle_radians_value difference { course - heading };

    std::cout << "difference between course and heading, radians " << difference << std::endl;

    const t_angle_radians_value heading_step_radians { heading_speed * delta_time };

    if (difference <= heading_step_radians)
    {
        heading = course;

        return;
    }

    heading += heading_step_radians;
}


/**
 * @brief t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system
 * @param heading
 * @param course
 * @param heading_speed
 */
t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                                                         const t_heading_speed_degrees_per_second_value heading_speed,
                                                                         const t_course_degrees_value course)
    : _heading { t_convert_degrees_to_radians(heading) }
    , _heading_speed { t_convert_degrees_to_radians(heading_speed) }
    , _course { t_convert_degrees_to_radians(course) }
{
}

/**
 * @brief t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system
 * @param heading
 * @param course is 2D vector
 * @param heading_speed
 */
t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                                                         const t_heading_speed_degrees_per_second_value heading_speed,
                                                                         const t_2d_course& course)
    : _heading { t_convert_degrees_to_radians(heading) }
    , _heading_speed { t_convert_degrees_to_radians(heading_speed) }
    , _course { t_get_radians(course) }
{
}

/**
 * @brief t_rotating_vehicle_to_course_system::update
 * @param delta_time
 */
void t_rotating_vehicle_to_course_system::update(const t_frame_delta_time_value delta_time)
{
    update_rotating_to_course(_heading, _heading_speed, _course, delta_time);
}


/**
 * @brief t_extended_rotating_vehicle_to_course_system::t_extended_rotating_vehicle_to_course_system constructs object.
 * @param heading
 * @param course
 * @param heading_speed
 */
t_extended_rotating_vehicle_to_course_system::t_extended_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                                                                           const t_heading_speed_degrees_per_second_value heading_speed,
                                                                                           const t_course_degrees_value course)
    : t_rotating_vehicle_to_course_system { heading, heading_speed, course }
{
}

/**
 * @brief t_extended_rotating_vehicle_to_course_system::get_heading_radians returns heading in radians.
 * @return
 */
const t_heading_radians_value t_extended_rotating_vehicle_to_course_system::get_heading_radians() const
{
    return _heading;
}

/**
 * @brief t_extended_rotating_vehicle_to_course_system::get_heading_degrees
 * @return
 */
const t_heading_degrees_value t_extended_rotating_vehicle_to_course_system::get_heading_degrees() const
{
    return t_convert_radians_to_degrees(_heading);
}

/**
 * @brief t_extended_rotating_vehicle_to_course_system::get_course_radians returns course in radians.
 * @return
 */
const t_course_radians_value t_extended_rotating_vehicle_to_course_system::get_course_radians() const
{
    return _course;
}

/**
 * @brief t_extended_rotating_vehicle_to_course_system::get_heading_speed returns heading speed in radians per second.
 * @return
 */
const t_heading_speed_radians_per_second_value t_extended_rotating_vehicle_to_course_system::get_heading_speed() const
{
    return _heading_speed;
}
