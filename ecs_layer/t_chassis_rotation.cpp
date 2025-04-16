#include "t_chassis_rotation.hpp"


t_chassis_rotation::t_chassis_rotation(const t_angle_degrees_value heading_angle_in_degrees,
                                       const t_floating direction_sign,
                                       const t_angle_degrees_value course_angle_in_degrees)
    : _heading_degrees { heading_angle_in_degrees }
    , _direction { direction_sign }
    , _course_degrees { course_angle_in_degrees }
{
}

void t_chassis_rotation::set_direction_sign(const t_floating direction_sign)
{
    _direction = direction_sign;
}

void t_chassis_rotation::set_heading_angle_in_degrees(const t_angle_degrees_value heading_angle_in_degrees)
{
    _heading_degrees = heading_angle_in_degrees;
}

void t_chassis_rotation::set_course_angle_in_degrees(const t_angle_degrees_value course_angle_in_degrees)
{
    _course_degrees = course_angle_in_degrees;
}
