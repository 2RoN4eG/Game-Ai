#include "t_rotating_vehicle_to_course_system.hpp"

#include "../t_component_defines.hpp"
#include "../tools/t_2d_vector.hpp"

#include <cmath>


namespace
{
    inline t_radians_value t_get_radians(const t_2d_vector& vector)
    {
        return atan2(vector.y(), vector.x());
    }

    inline t_degrees_value t_get_degrees(const t_2d_vector& vector)
    {
        const t_radians_value radians = t_get_radians(vector);

        return t_convert_radians_to_degrees(radians);
    }
}


void update_rotating_to_course_data(const t_frame_delta_time_value delta_time,
                                    t_heading_radians_value& heading,
                                    t_course_radians_value& course,
                                    t_heading_speed_radians_per_second_value& heading_speed)
{
    // TODO: Replace operator == to compare function.

    if (course == heading)
    {
        return;
    }

    const t_angle_radians_value difference { course - heading };

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
                                                                         const t_course_degrees_value course,
                                                                         const t_heading_speed_degrees_per_second_value heading_speed)
    : _heading { t_convert_degrees_to_radians(heading) }
    , _course { t_convert_degrees_to_radians(course) }
    , _heading_speed { t_convert_degrees_to_radians(heading_speed) }
{
}

/**
 * @brief t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system
 * @param heading
 * @param course is 2D vector
 * @param heading_speed
 */
t_rotating_vehicle_to_course_system::t_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                                                         const t_course_2d_vector& course,
                                                                         const t_heading_speed_degrees_per_second_value heading_speed)
    : _heading { t_convert_degrees_to_radians(heading) }
    , _course { t_get_radians(course) }
    , _heading_speed { t_convert_degrees_to_radians(heading_speed) }
{
}

/**
 * @brief t_rotating_vehicle_to_course_system::update
 * @param delta_time
 */
void t_rotating_vehicle_to_course_system::update(const t_frame_delta_time_value delta_time)
{
    update_rotating_to_course_data(delta_time, _heading, _course, _heading_speed);
}


/**
 * @brief t_extended_rotating_vehicle_to_course_system::t_extended_rotating_vehicle_to_course_system constructs object.
 * @param heading
 * @param course
 * @param heading_speed
 */
t_extended_rotating_vehicle_to_course_system::t_extended_rotating_vehicle_to_course_system(const t_heading_degrees_value heading,
                                                                                           const t_course_degrees_value course,
                                                                                           const t_heading_speed_degrees_per_second_value heading_speed)
    : t_rotating_vehicle_to_course_system { heading, course, heading_speed }
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
